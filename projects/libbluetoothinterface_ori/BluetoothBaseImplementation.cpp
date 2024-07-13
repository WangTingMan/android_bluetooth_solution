
#include "BluetoothBaseImplementation.h"

#include <Zhen/ExecutbleEvent.h>
#include <Zhen/PageManager.h>
#include <Zhen/logging.h>

#include <BT/Adaptor.h>
#include <Utils.h>

#include "StackUtils.h"
#include "binder_server.h"

#include <iomanip>

#include <windows.h>

#include <cutils/properties.h>

#include <filesystem>

#define FOLDER L"E:\\Projects\\google_bluetooth\\android_bluetooth_solution\\x64\\Debug\\"
#define MODULE_NAME L"libbluetooth.dll"

extern "C"
{
    typedef void* (*GetInterfaceType)();
    typedef void (*PrintLog)(const char* a_log, uint32_t a_line, const char* a_file, uint8_t a_level);
    typedef void (*test_lib_bluetooth)();
    typedef void* (*GetFakeAudioInterfaceType)();
    typedef void* (*GetStackApiExportInstanceType)();

    static test_lib_bluetooth s_test = nullptr;

}

void _adapter_state_changed_callback(bt_state_t state)
{
    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
    event->SetExecutableFunction(std::bind(&Adaptor::AdapterStateChanged, std::ref(Adaptor::GetInstance()), BT_STATE_ON == state));
    PageManager::GetInstance().PostEvent(event);
}

void _adapter_properties_callback
(
    bt_status_t status,
    int num_properties,
    bt_property_t* properties
)
{
    if (BT_STATUS_SUCCESS != status)
    {
        return;
    }

    for (int i = 0; i < num_properties; ++i)
    {
        switch (properties[i].type)
        {
        case BT_PROPERTY_BDNAME:
        {
            bt_bdname_t* name = reinterpret_cast<bt_bdname_t*>(properties[i].val);
            int size = properties[i].len;
            if (size == 0 || name == nullptr)
            {
                continue;
            }

            std::string localName(reinterpret_cast<char*>(name->name));
            std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
            event->SetExecutableFunction(std::bind(&Adaptor::OnLocalNameChanged, std::ref(Adaptor::GetInstance()), localName));
            PageManager::GetInstance().PostEvent(event);
        }
        break;
        case BT_PROPERTY_BDADDR:
        {
            RawAddress* addr = reinterpret_cast<RawAddress*>(properties[i].val);
            BluetoothAddress address;
            memcpy(address.address, addr->address, BluetoothAddress::kLength);
            std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
            event->SetExecutableFunction(std::bind(&Adaptor::OnLocalAddressChanged, std::ref(Adaptor::GetInstance()), address));
            PageManager::GetInstance().PostEvent(event);
        }
        break;
        case BT_PROPERTY_ADAPTER_SCAN_MODE:
        {
            bt_scan_mode_t* mode = reinterpret_cast<bt_scan_mode_t*>(properties[i].val);
            bool discoveriable = false;
            bool connectable = false;
            switch (*mode)
            {
            case BT_SCAN_MODE_NONE:
                discoveriable = false;
                connectable = false;
                break;
            case BT_SCAN_MODE_CONNECTABLE:
                discoveriable = false;
                connectable = true;
                break;
            case BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE:
                discoveriable = true;
                connectable = true;
                break;
            default:
                break;
            }
            auto fun = std::bind
            (
                &Adaptor::OnLocalSettingsChanged,
                std::ref(Adaptor::GetInstance()),
                discoveriable,
                connectable
            );
            std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
            event->SetExecutableFunction(fun);
            PageManager::GetInstance().PostEvent(event);
        }
        break;
        case BT_PROPERTY_ADAPTER_BONDED_DEVICES:
        {
            RawAddress* _address = reinterpret_cast<RawAddress*>(properties[i].val);
            BluetoothAddress address;
            int totalBondedDeviceCnt = properties[i].len / RawAddress::kLength;
            std::vector<BluetoothAddress> addresses;
            for (int i = 0; i < totalBondedDeviceCnt; ++i)
            {
                memcpy(address.address, _address[i].address, BluetoothAddress::kLength);
                addresses.push_back(address);
            }

            std::function<void()> fun = std::bind(
                &BluetoothBaseImplementation::OnPairedDeviceAddressReceived,
                std::ref(BluetoothBaseImplementation::GetInstance()),
                addresses
                );

            std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
            event->SetExecutableFunction(fun);
            PageManager::GetInstance().PostEvent(event);
        }
        break;
        case BT_PROPERTY_UUIDS:
        {
            bluetooth::Uuid* _uuid = reinterpret_cast<bluetooth::Uuid*>(properties[i].val);
            int totalUuidCnt = properties[i].len;
        }
        break;
        default:
            break;
        }
    }
}

void _remote_device_properties_callback
(
    bt_status_t status,
    RawAddress* bd_addr,
    int num_properties,
    bt_property_t* properties
)
{
    BluetoothAddress address(bd_addr->address);
    std::string name;
    std::string friendlyName;
    RemoteDevice device;
    device.address = address;
    std::vector<std::string> uuids;
    for (int i = 0; i < num_properties; ++i)
    {
        bt_property_t& property = properties[i];
        if (0u == property.len)
        {
            continue;
        }

        switch (property.type)
        {
        case BT_PROPERTY_REMOTE_FRIENDLY_NAME:
            friendlyName.assign(reinterpret_cast<char*>(property.val));
            break;
        case BT_PROPERTY_BDNAME:
            name.assign(reinterpret_cast<char*>(property.val), property.len);
            device.name = UTF8_To_string(name);
            break;
        case BT_PROPERTY_CLASS_OF_DEVICE:
            device.cod = *reinterpret_cast<uint32_t*>(property.val);
            break;
        case BT_PROPERTY_TYPE_OF_DEVICE:
            device.type = convert(*reinterpret_cast<bt_device_type_t*>(property.val));
            break;
        case BT_PROPERTY_UUIDS:
        {
            bluetooth::Uuid* p_uuid = nullptr;
            for (auto i = 0; i < property.len; i += 16)
            {
                p_uuid = reinterpret_cast<bluetooth::Uuid*>(
                    reinterpret_cast<char*>(property.val) + i);
                uuids.push_back(binary_to_hex_string(reinterpret_cast<char*>(property.val) + i, 16));
            }
        }
        break;
        default:
            break;
        }
    }
    auto fun = std::bind(&Adaptor::OnPairedDeviceReceived, std::ref(Adaptor::GetInstance()), device);
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>(fun);
    PageManager::GetInstance().PostEvent(event);
}

void _device_found_callback(int num_properties,
    bt_property_t* properties)
{
    RemoteDevice remoteDevice;
    bt_property_t* property_ = nullptr;
    bt_bdname_t* bdname = nullptr;
    RawAddress* address = nullptr;
    bluetooth::Uuid* uuids = nullptr;
    uint32_t* cod = nullptr;
    bt_device_type_t* type = nullptr;
    bt_service_record_t* record = nullptr;
    bt_scan_mode_t* mode_ = nullptr;
    RawAddress* bondedAddress = nullptr;
    uint32_t* time_ = nullptr;
    bt_bdname_t* remoteName = nullptr;
    int8_t* rssi = nullptr;
    bt_remote_version_t* version = nullptr;
    bt_local_le_features_t* localLeFeature = nullptr;
    bt_io_cap_t* ioCap = nullptr;
    for (int i = 0; i < num_properties; ++i)
    {
        property_ = properties + i;
        switch (property_->type)
        {
        case BT_PROPERTY_BDNAME:
        {
            std::string name((char*)property_->val, property_->len);
            remoteDevice.name = UTF8_To_string(name);
        }
        break;
        case BT_PROPERTY_BDADDR:
        {
            address = reinterpret_cast<RawAddress*> (property_->val);
            memcpy(remoteDevice.address.address, address->address, RawAddress::kLength);
        }
        break;
        case BT_PROPERTY_UUIDS:
        {
            uuids = reinterpret_cast<bluetooth::Uuid*>(property_->val);
            std::string uuidstr;
            for (int j = 0; j < property_->len / bluetooth::Uuid::kNumBytes128; ++j)
            {
                BluetoothUuid uuid = convert(uuids[j]);
                remoteDevice.uuids.push_back(uuid);
            }
        }
        break;
        case BT_PROPERTY_CLASS_OF_DEVICE:
        {
            cod = reinterpret_cast<uint32_t*>(property_->val);
            remoteDevice.cod = *cod;
        }
        break;
        case BT_PROPERTY_TYPE_OF_DEVICE:
        {
            type = reinterpret_cast<bt_device_type_t*> (property_->val);
            remoteDevice.type = convert( *type );
        }
        break;
        case BT_PROPERTY_SERVICE_RECORD:
        {
            record = reinterpret_cast<bt_service_record_t*>(property_->val);
            //memcpy(&remoteDevice.service_record, record, sizeof bt_service_record_t);
        }
        break;
        case BT_PROPERTY_ADAPTER_SCAN_MODE:
        {
            mode_ = reinterpret_cast<bt_scan_mode_t*>(property_->val);
        }
        break;
        case BT_PROPERTY_ADAPTER_BONDED_DEVICES:
        {
            bondedAddress = reinterpret_cast<RawAddress*>(property_->val);
        }
        break;
        case BT_PROPERTY_REMOTE_FRIENDLY_NAME:
        {
            remoteName = reinterpret_cast<bt_bdname_t*> (property_->val);

        }
        break;
        case BT_PROPERTY_REMOTE_RSSI:
        {
            rssi = reinterpret_cast<int8_t*>(property_->val);
            remoteDevice.rssi = *rssi;
        }
        break;
        case BT_PROPERTY_REMOTE_VERSION_INFO:
        {
            version = reinterpret_cast<bt_remote_version_t*>(property_->val);
        }
        break;
        case BT_PROPERTY_LOCAL_LE_FEATURES:
        {
            localLeFeature = reinterpret_cast<bt_local_le_features_t*>(property_->val);
        }
        break;
        case BT_PROPERTY_REMOTE_IS_COORDINATED_SET_MEMBER:
        {
            bool is = reinterpret_cast<bool*>(property_->val);
            LogDebug() << "is coordinated set member: " << std::boolalpha << is;
        }
        default:
            break;
        }
    }

    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>(
        [remoteDevice = std::move(remoteDevice)]()
        {
            if (DeviceControllerType::LEONLY != remoteDevice.type)
            {
                Adaptor::GetInstance().OnDeviceFound(remoteDevice);
            }
        }
    );

    PageManager::GetInstance().PostEvent(event);
}

void _discovery_state_changed_callback(bt_discovery_state_t state)
{
    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>
            (
            std::bind(&Adaptor::OnDiscoveryStateChanged, std::ref(Adaptor::GetInstance()), convert(state))
            );
    PageManager::GetInstance().PostEvent(event);
}

void _pin_request_callback(RawAddress* remote_bd_addr,
    bt_bdname_t* bd_name, uint32_t cod,
    bool min_16_digit)
{
    std::cout << __FUNCTION__ << std::endl;
}

void _ssp_request_callback
    (
    RawAddress* remote_bd_addr,
    bt_ssp_variant_t pairing_variant,
    uint32_t pass_key
    )
{
    std::string name;
    BluetoothAddress address(remote_bd_addr->address);
    SppPairingMethod method = SppPairingMethod::BT_SSP_VARIANT_CONSENT;
    switch (pairing_variant)
    {
    case BT_SSP_VARIANT_CONSENT:
        method = SppPairingMethod::BT_SSP_VARIANT_CONSENT;
        break;
    case BT_SSP_VARIANT_PASSKEY_CONFIRMATION:
        method = SppPairingMethod::BT_SSP_VARIANT_PASSKEY_CONFIRMATION;
        break;
    case BT_SSP_VARIANT_PASSKEY_ENTRY:
        method = SppPairingMethod::BT_SSP_VARIANT_PASSKEY_ENTRY;
        break;
    case BT_SSP_VARIANT_PASSKEY_NOTIFICATION:
        method = SppPairingMethod::BT_SSP_VARIANT_PASSKEY_NOTIFICATION;
        break;
    default:
        break;
    }
    auto fun = std::bind
        (
        &Adaptor::OnSppPairingConfRequest,
        std::ref(Adaptor::GetInstance()),
        address,
        name,
        pass_key,
        method
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

void _bond_state_changed_callback(bt_status_t status, RawAddress* remote_bd_addr, bt_bond_state_t state, int fail_reason)
{
    BluetoothAddress address(remote_bd_addr->address);
    BondState stateBond = BondState::NoneBond;
    switch (state)
    {
    case BT_BOND_STATE_NONE:
        stateBond = BondState::NoneBond;
        break;
    case  BT_BOND_STATE_BONDING:
        stateBond = BondState::Bonding;
        break;
    case BT_BOND_STATE_BONDED:
        stateBond = BondState::BondCompleted;
        break;
    default:
        break;
    }

    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>
        (
            std::bind(&Adaptor::OnBondStateChanged, std::ref(Adaptor::GetInstance()), stateBond, address)
        );
    PageManager::GetInstance().PostEvent(event);
}

void _address_consolidate_cb(RawAddress* main_bd_addr, RawAddress* secondary_bd_addr)
{

}

void _acl_state_changed_callback
    (
    bt_status_t status,
    RawAddress* remote_bd_addr,
    bt_acl_state_t state,
    int transport_link_type,
    bt_hci_error_code_t hci_reason,
    bt_conn_direction_t direction,
    uint16_t acl_handle
    )
{

}

void _callback_thread_event(bt_cb_thread_evt evt)
{
    //std::cout << __FUNCTION__ << std::endl;
}

void _energy_info_callback(bt_activity_energy_info* energy_info,
    bt_uid_traffic_t* uid_data)
{
    //std::cout << __FUNCTION__ << std::endl;
}

void _link_quality_report_callback(uint64_t timestamp, int report_id, int rssi, int snr,
    int retransmission_count, int packets_not_receive_count, int negative_acknowledgement_count)
{

}

void _generate_local_oob_data_callback(tBT_TRANSPORT transport, bt_oob_data_t oob_data)
{

}

void _switch_buffer_size_callback(bool is_low_latency_buffer_size)
{

}

void _le_address_associate_callback(RawAddress* main_bd_addr,
    RawAddress* secondary_bd_addr)
{

}

void _switch_codec_callback(bool is_low_latency_buffer_size)
{

}

void _le_rand_callback(uint64_t random)
{

}

void _dut_mode_recv_callback(uint16_t opcode, uint8_t* buf,
    uint8_t len)
{

}

void _le_test_mode_callback(bt_status_t status, uint16_t num_packets)
{

}

void _key_missing_callback(const RawAddress bd_addr)
{

}

int _acquire_wake_lock_callout(const char* lock_name)
{
    //packages/apps/Bluetooth/src/com/android/bluetooth/btservice/AdapterService.java
    //µÄprivate boolean acquireWakeLock(String lockName).
    // This function is called from JNI. It allows native code to acquire a single wake lock.
    // If the wake lock is already held, this function returns success. Although this function
    // only supports acquiring a single wake lock at a time right now, it will eventually be
    // extended to allow acquiring an arbitrary number of wake locks. The current interface
    // takes |lockName| as a parameter in anticipation of that implementation.

    //std::cout << __FUNCTION__ << std::endl;
    return 0;
}

int _release_wake_lock_callout(const char* lock_name)
{
    //std::cout << FunctionLog( __FUNCTION__ );
    //std::cout << __FUNCTION__ << std::endl;
    return 0;
}


BluetoothBaseInterface& BluetoothBaseInterface::GetInterface()
{
    return BluetoothBaseImplementation::GetInstance();
}

BluetoothBaseImplementation& BluetoothBaseImplementation::GetInstance()
{
    static BluetoothBaseImplementation instance;
    return instance;
}

BluetoothBaseImplementation::BluetoothBaseImplementation()
{
    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
    event->SetExecutableFunction( std::bind( &BluetoothBaseImplementation::InitPlatform, this ) );
    PageManager::GetInstance().PostEvent( event );
}

void BluetoothBaseImplementation::InitPlatform()
{
    parse_property_from_ini( "D:/bluetooth/setting/settings.ini" );
    binder_server_init();
}

void BluetoothBaseImplementation::Init()
{
    memset(&m_callback_, 0x00, sizeof m_callback_);
    m_callback_.size = sizeof m_callback_;
    m_callback_.adapter_state_changed_cb = &_adapter_state_changed_callback;
    m_callback_.adapter_properties_cb = &_adapter_properties_callback;
    m_callback_.remote_device_properties_cb = &_remote_device_properties_callback;
    m_callback_.device_found_cb = &_device_found_callback;
    m_callback_.discovery_state_changed_cb = &_discovery_state_changed_callback;
    m_callback_.pin_request_cb = &_pin_request_callback;
    m_callback_.ssp_request_cb = &_ssp_request_callback;
    m_callback_.bond_state_changed_cb = &_bond_state_changed_callback;
    m_callback_.address_consolidate_cb = &_address_consolidate_cb;
    m_callback_.acl_state_changed_cb = &_acl_state_changed_callback;
    m_callback_.thread_evt_cb = &_callback_thread_event;
    m_callback_.energy_info_cb = &_energy_info_callback;
    m_callback_.link_quality_report_cb = &_link_quality_report_callback;
    m_callback_.generate_local_oob_data_cb = &_generate_local_oob_data_callback;
    m_callback_.switch_buffer_size_cb = &_switch_buffer_size_callback;
    m_callback_.le_address_associate_cb = &_le_address_associate_callback;
    m_callback_.switch_codec_cb = &_switch_codec_callback;
    m_callback_.le_rand_cb = &_le_rand_callback;
    m_callback_.dut_mode_recv_cb = &_dut_mode_recv_callback;
    m_callback_.le_test_mode_cb = &_le_test_mode_callback;
    m_callback_.key_missing_cb = &_key_missing_callback;

    memset(&m_callout, 0x00, sizeof m_callout);
    m_callout.size = sizeof m_callout;
    m_callout.acquire_wake_lock = &_acquire_wake_lock_callout;
    m_callout.release_wake_lock = &_release_wake_lock_callout;

    bool ret = LoadBluetoothLibrary();
    if (!ret)
    {
        LogError() << "cannot load bluetooth library.";
        return;
    }

    m_fakeAudioInterface = nullptr;
    m_interface->init(&m_callback_, false, false, 0, nullptr, false, nullptr);
    m_interface->set_os_callouts(&m_callout);
}

void BluetoothBaseImplementation::Enable(bool a_enable)
{
    if (a_enable)
    {
        if( !m_interface )
        {
            Init();
        }

        if (m_interface)
        {
            m_interface->enable();
        }
    }
    else
    {
        m_interface->disable();
    }
}

void BluetoothBaseImplementation::StartSearch(bool a_search)
{
    if (a_search)
    {
        m_interface->get_adapter_property(BT_PROPERTY_ADAPTER_BONDED_DEVICES);
        m_interface->start_discovery();
    }
    else
    {
        m_interface->cancel_discovery();
    }
}

void BluetoothBaseImplementation::PairWithDevice(BluetoothAddress a_address)
{
    if (!m_interface)
    {
        return;
    }

    RawAddress addr;
    memcpy(addr.address, a_address.address, RawAddress::kLength);
    m_interface->create_bond(&addr, true);
}

void BluetoothBaseImplementation::DeletePairedDevice(BluetoothAddress a_address)
{
    if (!m_interface)
    {
        return;
    }

    RawAddress addr;
    memcpy(addr.address, a_address.address, RawAddress::kLength);
    m_interface->remove_bond(&addr);
}

void BluetoothBaseImplementation::SetLocalName(std::string const& a_name)
{
    bt_property_t property_;
    property_.type = BT_PROPERTY_BDNAME;
    property_.val = const_cast<char*>(a_name.c_str());
    property_.len = a_name.size() + 1;
    if (m_interface)
    {
        m_interface->set_adapter_property(&property_);
    }
}

bool BluetoothBaseImplementation::SetLocalDeviceSettings
    (
    bool a_pairable,
    bool a_discoverable,
    bool a_connectable
    )
{
    bool r = false;
    bt_property_t property_;
    property_.type = BT_PROPERTY_ADAPTER_SCAN_MODE;
    bt_scan_mode_t mode;
    if (a_connectable)
    {
        if (a_discoverable)
        {
            mode = BT_SCAN_MODE_CONNECTABLE_DISCOVERABLE;
        }
        else
        {
            mode = BT_SCAN_MODE_CONNECTABLE;
        }
    }
    else
    {
        mode = BT_SCAN_MODE_NONE;
    }
    property_.val = &mode;
    property_.len = sizeof bt_scan_mode_t;
    if (m_interface)
    {
        m_interface->set_adapter_property(&property_);
    }
    return r;
}

bool BluetoothBaseImplementation::SspPairingReply
    (
    BluetoothAddress a_address,
    bool             a_accept,
    SppPairingMethod a_pairingMethod,
    uint32_t         a_passkey
    )
{
    bool ret = false;
    RawAddress bd_addr;
    memcpy(bd_addr.address, a_address.address, RawAddress::kLength);
    bt_ssp_variant_t variant;
    switch (a_pairingMethod)
    {
    case SppPairingMethod::BT_SSP_VARIANT_CONSENT:
        variant = BT_SSP_VARIANT_CONSENT;
        break;
    case SppPairingMethod::BT_SSP_VARIANT_PASSKEY_CONFIRMATION:
        variant = BT_SSP_VARIANT_PASSKEY_CONFIRMATION;
        break;
    case SppPairingMethod::BT_SSP_VARIANT_PASSKEY_ENTRY:
        variant = BT_SSP_VARIANT_PASSKEY_ENTRY;
        break;
    case SppPairingMethod::BT_SSP_VARIANT_PASSKEY_NOTIFICATION:
        variant = BT_SSP_VARIANT_PASSKEY_NOTIFICATION;
        break;
    default:
        break;
    }

    uint8_t accept = a_accept ? TRUE : FALSE;
    m_interface->ssp_reply(&bd_addr, variant, accept, a_passkey);

    return ret;
}

void* BluetoothBaseImplementation::GetFakeAudioInterfaceFromModule()
{
    return m_fakeAudioInterface;
}

void BluetoothBaseImplementation::test()
{
    if (s_test == nullptr)
    {
        LoadBluetoothLibrary();
    }

    if (s_test)
    {
        s_test();
    }
}

void BluetoothBaseImplementation::OnPairedDeviceAddressReceived
    (
    std::vector<BluetoothAddress> a_addresses
    )
{
    for (auto beg = a_addresses.begin(); beg != a_addresses.end(); ++beg)
    {
        RawAddress address;
        memcpy(address.address, beg->address, BluetoothAddress::kLength);
        m_interface->get_remote_device_properties(&address);
    }
}

bool BluetoothBaseImplementation::LoadBluetoothLibrary()
{
    if (m_interface || s_test)
    {
        return true;
    }

    std::filesystem::path path(FOLDER MODULE_NAME);
    if( !std::filesystem::exists(path) )
    {
        char buffer[256] = { 0 };
        int ret = property_get("persist.bluetooth.local.libpath", buffer, nullptr);
        if (ret < 1)
        {
            LogError() << "Please set bluetooth library into property: "
                << "persist.bluetooth.local.libpath";
            return false;
        }

        std::filesystem::path path_property(buffer);
        if (!std::filesystem::exists(path_property))
        {
            LogError() << "No such file: " << buffer;
            return false;
        }
        path = std::move(path_property);
    }

    HMODULE hMod = LoadLibrary(path.wstring().c_str());
    if (hMod == NULL)
    {
        LogError() << "Cannot load library " << path.string();
        return false;
    }

    FARPROC pro = GetProcAddress(hMod, "GetAndroidBluetoothInterface");
    GetInterfaceType get = (GetInterfaceType)pro;
    if (get == nullptr)
    {
        LogError() << "Cannot find symbol GetAndroidBluetoothInterface from library: "
            << path.string();
        return false;
    }

    pro = GetProcAddress(hMod, "test");
    s_test = (test_lib_bluetooth)pro;

    m_interface = reinterpret_cast<bt_interface_t*>(get());
    return true;
}
