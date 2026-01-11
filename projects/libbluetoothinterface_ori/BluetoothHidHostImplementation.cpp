#include <bt_types.h>

#include "BluetoothHidHostImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <Zhen/ExecutbleEvent.h>
#include <Zhen/PageManager.h>
#include <Zhen/logging.h>

#include <BT/HID/BluetoothHidHost.h>

#include <cutils/linux/uhid.h>

static void PostHidHostEvent(std::function<void(BluetoothHidHostImplementation*)> a_fun)
{
    std::function<void()> fun = [a_fun]()
        {
            a_fun(&BluetoothHidHostImplementation::GetInstance());
        };

    auto executableEvent = std::make_shared<ExecutbleEvent>(fun);
    PageManager::GetInstance().PostEvent(executableEvent);
}

/** Callback for connection state change.
 *  state will have one of the values from bthh_connection_state_t
 */
extern "C" void bthh_connection_state_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_connection_state_t state
    )
{
    BluetoothAddress address;
    memcpy(address.address, bd_addr->address, BluetoothAddress::kLength);
    auto fun = std::bind
        (
        &BluetoothHidHostImplementation::HandleConnectionStatusChanged,
        std::placeholders::_1,
        address,
        addr_type,
        transport,
        state
        );

    PostHidHostEvent(fun);
}

/** Callback for vitual unplug api.
 *  the status of the vitual unplug
 */
extern "C" void bthh_virtual_unplug_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_status_t hh_status
    )
{
    LogError();
}

/** Callback for get hid info
 *  hid_info will contain attr_mask, sub_class, app_id, vendor_id, product_id,
 * version, ctry_code, len
 */
extern "C" void bthh_hid_info_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_hid_info_t hid_info
    )
{
    LogError();
}

/** Callback for get protocol api.
 *  the protocol mode is one of the value from bthh_protocol_mode_t
 */
extern "C" void bthh_protocol_mode_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_status_t hh_status,
    bthh_protocol_mode_t mode
    )
{
    LogError();
}

/** Callback for get/set_idle_time api.
 */
extern "C" void bthh_idle_time_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_status_t hh_status,
    int idle_rate
    )
{
    LogError();
}

/** Callback for get report api.
 *  if staus is ok rpt_data contains the report data
 */
extern "C" void bthh_get_report_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_status_t hh_status,
    uint8_t* rpt_data,
    int rpt_size
    )
{
    LogError();
}

/** Callback for set_report/set_protocol api and if error
 *  occurs for get_report/get_protocol api.
 */
extern "C" void bthh_handshake_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_status_t hh_status
    )
{
    LogError();
}

extern "C" void bthh_data_callback_impl
    (
    RawAddress* bd_addr,
    tBLE_ADDR_TYPE addr_type,
    void* data,
    int32_t data_size
    )
{
    uhid_event* uid_ev = nullptr;
    uid_ev = reinterpret_cast<uhid_event*>(data);
    uhid_create_req* uid_create_req_ = nullptr;

    switch (uid_ev->type)
    {
    case UHID_CREATE:
        {
            uid_create_req_ = &(uid_ev->u.create);
            LogDebug() << "HID device created: " << uid_create_req_->name
                << ", rd data: " << Zhen::BinaryBuffer((const char*)uid_create_req_->rd_data, uid_create_req_->rd_size);
            return;
        }
        break;
    case UHID_OUTPUT_EV:
        break;
    case UHID_INPUT:
        {
            uint8_t* input_data = uid_ev->u.input.data;
            uint16_t input_data_size = uid_ev->u.input.size;
            LogDebug() << "Received HID input data: " << Zhen::BinaryBuffer((const char*)input_data, input_data_size);
            return;
        }
        break;
    case UHID_FEATURE:
        break;
    case UHID_FEATURE_ANSWER:
        break;
    default:
        break;
    }

    LogError() << "other data.";
}

BluetoothHidHostInterface& BluetoothHidHostInterface::GetInterface()
{
    return BluetoothHidHostImplementation::GetInstance();
}

BluetoothHidHostImplementation& BluetoothHidHostImplementation::GetInstance()
{
    static BluetoothHidHostImplementation instance;
    return instance;
}

void BluetoothHidHostImplementation::Init()
{
    if (m_initialized)
    {
        return;
    }

    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();

    bthh_interface_t const* inter =
        reinterpret_cast<bthh_interface_t const*>(
            interfaceBt->get_profile_interface(BT_PROFILE_HIDHOST_ID));
    m_interface = const_cast<bthh_interface_t*>(inter);

    memset(&m_callbacks, 0x00, sizeof(m_callbacks));
    m_callbacks.size = sizeof(m_callbacks);
    m_callbacks.connection_state_cb = bthh_connection_state_callback_impl;
    m_callbacks.hid_info_cb = bthh_hid_info_callback_impl;
    m_callbacks.protocol_mode_cb = bthh_protocol_mode_callback_impl;
    m_callbacks.idle_time_cb = bthh_idle_time_callback_impl;
    m_callbacks.get_report_cb = bthh_get_report_callback_impl;
    m_callbacks.virtual_unplug_cb = bthh_virtual_unplug_callback_impl;
    m_callbacks.handshake_cb = bthh_handshake_callback_impl;
    m_interface->init(&m_callbacks);

    m_initialized = true;
}

bool BluetoothHidHostImplementation::Connect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    tBLE_ADDR_TYPE addr_type = BLE_ADDR_PUBLIC;
    tBT_TRANSPORT transport = BT_TRANSPORT_BR_EDR;

    bt_status_t status = m_interface->connect(&address, addr_type, transport);
    return true;
}

bool BluetoothHidHostImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    tBLE_ADDR_TYPE addr_type = BLE_ADDR_PUBLIC;
    tBT_TRANSPORT transport = BT_TRANSPORT_BR_EDR;
    bt_status_t status = m_interface->disconnect(&address, addr_type, transport, true);
    return true;
}

void BluetoothHidHostImplementation::GetReport
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);

    tBLE_ADDR_TYPE addr_type = BLE_ADDR_PUBLIC;
    tBT_TRANSPORT transport = BT_TRANSPORT_BR_EDR;
    bthh_report_type_t report_type = BTHH_INPUT_REPORT;
    uint8_t id = 1;
    int buffer_size = 512;
    m_interface->get_report(&address, addr_type, transport, report_type, id, buffer_size);
}

void BluetoothHidHostImplementation::HandleConnectionStatusChanged
    (
    BluetoothAddress bd_addr,
    tBLE_ADDR_TYPE addr_type,
    tBT_TRANSPORT transport,
    bthh_connection_state_t state
    )
{
    ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
    switch (state)
    {
    case BTHH_CONN_STATE_CONNECTED:
        status = ConnectionStatus::ServiceConnected;
        break;
    case BTHH_CONN_STATE_CONNECTING:
        status = ConnectionStatus::ServiceConnecting;
        break;
    case BTHH_CONN_STATE_DISCONNECTED:
        status = ConnectionStatus::ServiceDisconnected;
        break;
    case BTHH_CONN_STATE_DISCONNECTING:
        status = ConnectionStatus::ServiceDisconnecting;
        break;
    case BTHH_CONN_STATE_UNKNOWN:
        status = ConnectionStatus::ServiceConnected;
        break;
    default:
        break;
    }

    std::shared_ptr<Bluetooth::BluetoothHidHost> hid_host = Bluetooth::BluetoothHidHost::GetMoudle();
    hid_host->HandleConnectionStatusChanged(bd_addr, status);
}
