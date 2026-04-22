
#include <hardware/bt_gatt_client.h>

#include "BluetoothGattServerImplementation.h"
#include "BluetoothGattClientImplementation.h"
#include "BluetoothGattImplementation.h"
#include "BluetoothBaseImplementation.h"
#include "BT/Adaptor.h"

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>
#include <Zhen/logging.h>

#include <hardware/bt_gatt_client.h>
#include <stack/include/gatt_api.h>
#include <hardware/bt_gatt.h>
#include <cutils/bitops.h>

static inline void PostCallbackMessageEventToPageManager( std::shared_ptr< GattClientBaseMessage> a_msg )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattClientImplementation::HandleClientCallbackMessage,
        std::ref( BluetoothGattClientImplementation::GetInstance() ),
        a_msg
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

static inline void PostTaskEventToPageManager(std::function<void()> a_tsk)
{
    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
    event->SetExecutableFunction(a_tsk);
    PageManager::GetInstance().PostEvent(event);
}

__BEGIN_DECLS

/** Callback invoked in response to register_client */
void _register_client_callback
    (
    int status,
    int client_if,
    const bluetooth::Uuid& app_uuid
    )
{
    std::vector<uint8_t> uuid;
    uuid.assign(app_uuid.uu.begin(), app_uuid.uu.begin() + bluetooth::Uuid::kNumBytes128);
    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleClientRegistered,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        status, client_if, uuid));
}

/** GATT open callback invoked in response to open */
void _connect_callback
    (
    int conn_id,
    int a_status,
    int client_if,
    const RawAddress& bda
    )
{
    BluetoothAddress addr(bda.address);
    
    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleGattConnectionStatusChanged,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        conn_id, a_status, client_if, addr));
}

/** Callback invoked in response to close */
void _disconnect_callback( int conn_id, int a_status, int client_if,
    const RawAddress& bda )
{
    auto msg = std::make_shared<ConnectStatusMessage>();
    msg->client_if = client_if;
    msg->conn_id = conn_id;
    msg->status = ConnectionStatus::ServiceDisconnected;;
    msg->address = BluetoothAddress( bda.address );

    PostCallbackMessageEventToPageManager( msg );
}

/**
 * Invoked in response to search_service when the GATT service search
 * has been completed.
 */
void _search_complete_callback( int conn_id, int status )
{
    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleGattServiceSearchingCompleted,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        conn_id, status));
}

/** Callback invoked in response to [de]register_for_notification */
void _register_for_notification_callback( int conn_id, int registered,
    int status, uint16_t handle )
{
    auto msg = std::make_shared<RegisterForNotificationMessage>();
    msg->conn_id = conn_id;
    msg->handle = handle;
    msg->registered = registered;
    msg->status = status;

    PostCallbackMessageEventToPageManager( msg );
}

/**
 * Remote device notification callback, invoked when a remote device sends
 * a notification or indication that a client has registered for.
 */
void _notify_callback( int conn_id,
    const btgatt_notify_params_t& p_data )
{
    auto msg = std::make_shared<NotifyMessage>();
    msg->conn_id = conn_id;
    msg->bda = BluetoothAddress( p_data.bda.address );
    msg->handle = p_data.handle;
    msg->is_notify = p_data.is_notify;
    msg->len = p_data.len;
    memcpy( msg->value, p_data.value, p_data.len );

    PostCallbackMessageEventToPageManager( msg );
}

/** Reports result of a GATT read operation */
void _read_characteristic_callback
    (
    int conn_id, int status, const btgatt_read_params_t& p_data
    )
{
    btgatt_read_params_type read_data;
    memcpy(&read_data, &p_data, sizeof(btgatt_read_params_type));
    auto msg = std::make_shared<ReadCharacteristicMessage>();
    msg->conn_id = conn_id;
    msg->status = status;
    msg->data = read_data;

    PostCallbackMessageEventToPageManager( msg );
}

/** GATT write characteristic operation callback */
void _write_characteristic_callback( int conn_id, int status,
    uint16_t handle, uint16_t len,
    const uint8_t* value )
{
    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleCharacteristicWriteCompleted,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        conn_id, status, handle));
}

/** Callback invoked in response to read_descriptor */
void _read_descriptor_callback( int conn_id, int status,
    const btgatt_read_params_t& p_data )
{
    btgatt_read_params_type read_data;
    memcpy(&read_data, &p_data, sizeof(btgatt_read_params_type));
    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleDescriptorReadCompleted,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        conn_id, status, read_data));
}

/** Callback invoked in response to write_descriptor */
void _write_descriptor_callback( int conn_id, int status,
    uint16_t handle, uint16_t len,
    const uint8_t* value )
{
    auto msg = std::make_shared<WriteDescriptorMessage>();
    msg->conn_id = conn_id;
    msg->status = status;
    msg->handle = handle;

    PostCallbackMessageEventToPageManager( msg );
}

/** GATT execute prepared write callback */
void _execute_write_callback( int conn_id, int status )
{
    auto msg = std::make_shared<WriteDescriptorMessage>();
    msg->conn_id = conn_id;
    msg->status = status;

    PostCallbackMessageEventToPageManager( msg );
}

/** Callback triggered in response to read_remote_rssi */
void _read_remote_rssi_callback( int client_if, const RawAddress& bda,
    int rssi, int status )
{
    auto msg = std::make_shared<ReadRemoteRssiMessage>();
    msg->client_if = client_if;
    msg->status = status;
    msg->rssi = rssi;
    //msg->bda = bda;

    PostCallbackMessageEventToPageManager( msg );
}

/** Callback invoked when the MTU for a given connection changes */
void _configure_mtu_callback( int conn_id, int status, int mtu )
{
    auto msg = std::make_shared<ConfigureMtuMessage>();
    msg->conn_id = conn_id;
    msg->status = status;
    msg->mtu = mtu;

    PostCallbackMessageEventToPageManager( msg );
}

/**
 * Callback notifying an application that a remote device connection is
 * currently congested and cannot receive any more data. An application should
 * avoid sending more data until a further callback is received indicating the
 * congestion status has been cleared.
 */
void _congestion_client_callback( int conn_id, bool congested )
{
    auto msg = std::make_shared<CongestionClientMessage>();
    msg->conn_id = conn_id;
    msg->congested = congested;

    PostCallbackMessageEventToPageManager( msg );
}

/** GATT get database callback */
void _get_gatt_db_callback( int conn_id, const btgatt_db_element_t* db,
    int count )
{
    std::vector<GATT_DB_ELEMENT> db_elements;
    for (int i = 0; i < count; ++i)
    {
        GATT_DB_ELEMENT db_element;
        db_element.attribute_handle = db[i].attribute_handle;
        db_element.end_handle = db[i].end_handle;
        db_element.id = db[i].id;
        db_element.permissions = db[i].permissions;
        db_element.properties = db[i].properties;
        db_element.start_handle = db[i].start_handle;
        db_element.type = (gatt_db_attribute_type)db[i].type;
        db_element.uuid.assign(db[i].uuid.uu.begin(), db[i].uuid.uu.end());

        db_elements.push_back(db_element);
    }

    PostTaskEventToPageManager(std::bind(
        &BluetoothGattClientImplementation::HandleGattServiceSearchingDetailCompleted,
        std::ref(BluetoothGattClientImplementation::GetInstance()),
        db_elements, conn_id));
}

/** GATT services between start_handle and end_handle were removed */
void _services_removed_callback( int conn_id, uint16_t start_handle,
    uint16_t end_handle )
{
    auto msg = std::make_shared<ServicesRemovedMessage>();
    msg->conn_id = conn_id;
    msg->start_handle = start_handle;
    msg->end_handle = end_handle;

    PostCallbackMessageEventToPageManager( msg );
}

/** GATT services were added */
void _services_added_callback( int conn_id,
    const btgatt_db_element_t& added,
    int added_count )
{
    auto msg = std::make_shared<ServicesAddedMessage>();
    msg->conn_id = conn_id;
    //msg->added = added;
    msg->added_count = added_count;

    PostCallbackMessageEventToPageManager( msg );
}

/** Callback invoked when the PHY for a given connection changes */
void _phy_client_updated_callback( int conn_id, uint8_t tx_phy,
    uint8_t rx_phy, uint8_t status )
{
    auto msg = std::make_shared<PhyClientUpdatedMessage>();
    msg->conn_id = conn_id;
    msg->tx_phy = tx_phy;
    msg->rx_phy = rx_phy;
    msg->status = status;

    PostCallbackMessageEventToPageManager( msg );
}

/** Callback invoked when the connection parameters for a given connection
 * changes */
void _conn_client_updated_callback( int conn_id, uint16_t interval,
    uint16_t latency, uint16_t timeout,
    uint8_t status )
{
    auto msg = std::make_shared<ConnClientUpdatedMessage>();
    msg->conn_id = conn_id;
    msg->interval = interval;
    msg->latency = latency;
    msg->timeout = timeout;
    msg->status = status;

    PostCallbackMessageEventToPageManager( msg );
}

void _service_changed_callback(int conn_id)
{
    LogError() << "service changed callback, not handled.";
}

void _subrate_change_callback(int conn_id, uint16_t subrate_factor,
    uint16_t latency, uint16_t cont_num,
    uint16_t timeout, uint8_t status)
{
    LogError() << "_subrate_change_callback, not handled.";
}

/** Callback invoked when the service discovery operation is done */
void _disc_done_callback( RawAddress bda )
{
    auto msg = std::make_shared<DiscoveryDoneMessage>();
    msg->address = BluetoothAddress( bda.address );

    PostCallbackMessageEventToPageManager( msg );
}

__END_DECLS

BluetoothGattClientImplementation::BluetoothGattClientImplementation()
{
    m_clientCallback.register_client_cb = _register_client_callback;
    m_clientCallback.open_cb = _connect_callback;
    m_clientCallback.close_cb = _disconnect_callback;
    m_clientCallback.search_complete_cb = _search_complete_callback;
    m_clientCallback.register_for_notification_cb = _register_for_notification_callback;
    m_clientCallback.notify_cb = _notify_callback;
    m_clientCallback.read_characteristic_cb = _read_characteristic_callback;
    m_clientCallback.write_characteristic_cb = _write_characteristic_callback;
    m_clientCallback.read_descriptor_cb = _read_descriptor_callback;
    m_clientCallback.write_descriptor_cb = _write_descriptor_callback;
    m_clientCallback.execute_write_cb = _execute_write_callback;
    m_clientCallback.read_remote_rssi_cb = _read_remote_rssi_callback;
    m_clientCallback.configure_mtu_cb = _configure_mtu_callback;
    m_clientCallback.congestion_cb = _congestion_client_callback;
    m_clientCallback.get_gatt_db_cb = _get_gatt_db_callback;
    m_clientCallback.services_removed_cb = _services_removed_callback;
    m_clientCallback.services_added_cb = _services_added_callback;
    m_clientCallback.phy_updated_cb = _phy_client_updated_callback;
    m_clientCallback.conn_updated_cb = _conn_client_updated_callback;
    m_clientCallback.service_changed_cb = _service_changed_callback;
}

void BluetoothGattClientImplementation::Init()
{
    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    btgatt_interface_t* gattInterface = reinterpret_cast< btgatt_interface_t* >( const_cast< void* >(
        interfaceBt->get_profile_interface( BT_PROFILE_GATT_ID ) ) );

    gatt_client_interface = const_cast< btgatt_client_interface_t* >( gattInterface->client );

    m_gattClientInitializedSignal();
}

bool BluetoothGattClientImplementation::Connect
    (
    BluetoothAddress a_address,
    int a_client_if
    )
{
    RawAddress addr;
    memcpy(addr.address, a_address.address, RawAddress::kLength);

    int client_if = a_client_if;
    const RawAddress& bd_addr = addr;
    bool is_direct = true;
    int transport = 0;
    bool opportunistic = false;
    int initiating_phys = 0;
    uint8_t addr_type = 1;

    gatt_client_interface->connect( client_if, bd_addr, addr_type, is_direct,
        transport, opportunistic, initiating_phys );

    return true;
}

bool BluetoothGattClientImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool BluetoothGattClientImplementation::IsInitlialized() const
{
    if( gatt_client_interface )
    {
        return true;
    }
    return false;
}

void* BluetoothGattClientImplementation::GetInterface()
{
    return gatt_client_interface;
}

BluetoothGattClientImplementation& BluetoothGattClientImplementation::GetInstance()
{
    static BluetoothGattClientImplementation instance;
    return instance;
}

BluetoothGattClientInterface& BluetoothGattClientInterface::GetInterface()
{
    return BluetoothGattClientImplementation::GetInstance();
}

void* BluetoothGattClientImplementation::GetGattClientCallback()
{
    void* p = nullptr;
    p = &m_clientCallback;
    return p;
}

void BluetoothGattClientImplementation::RegisterClientUuid
    (
    std::vector<uint8_t> a_uuid,
    bool a_support_eatt
    )
{
    bluetooth::Uuid uuid;
    memcpy(uuid.uu.data(), a_uuid.data(), bluetooth::Uuid::kNumBytes128);

    gatt_client_interface->register_client(uuid, a_support_eatt );
}

void BluetoothGattClientImplementation::SearchServiceByUuid
    (
    std::vector<uint8_t> a_uuid,
    int a_connection_id
    )
{
    bluetooth::Uuid uuid;
    memcpy(uuid.uu.data(), a_uuid.data(), bluetooth::Uuid::kNumBytes128);

    gatt_client_interface->search_service( a_connection_id, &uuid );
}

void BluetoothGattClientImplementation::RegisterNotification
    (
    int client_if,
    BluetoothAddress a_address,
    int16_t a_handle
    )
{
    RawAddress bd_addr;
    memcpy(bd_addr.address, a_address.address, BluetoothAddress::kLength);
    gatt_client_interface->register_for_notification(client_if, bd_addr, a_handle);
}

void BluetoothGattClientImplementation::WriteCharacteristic
    (
    int conn_id, uint16_t handle,
    int write_type, int auth_req,
    const uint8_t* value, size_t length
    )
{
    std::vector<uint8_t> value_vec;
    value_vec.insert( value_vec.begin(), value, value + length );
    gatt_client_interface->write_characteristic(conn_id, handle, write_type, auth_req, value, length );
}

void BluetoothGattClientImplementation::ReadDescriptor
    (
    int conn_id, uint16_t handle, int auth_req
    )
{
    gatt_client_interface->read_descriptor(conn_id, handle, auth_req);
}

void BluetoothGattClientImplementation::GetDbByConnectId( int conn_id )
{
    gatt_client_interface->get_gatt_db( conn_id );
}

int BluetoothGattClientImplementation::GetInterfaceNumber()
{
    return btifNumber;
}

void BluetoothGattClientImplementation::HandleClientCallbackMessage( std::shared_ptr< GattClientBaseMessage> a_msg )
{
    m_gattClientMessageSignal( a_msg );
}

void BluetoothGattClientImplementation::HandleClientRegistered
    (
    int status,
    int client_if,
    std::vector<uint8_t> uuid
    )
{
    m_gattClientRegisteredSignal(status, client_if, uuid);
}

void BluetoothGattClientImplementation::HandleGattConnectionStatusChanged
    (
    int conn_id,
    int a_status,
    int client_if,
    BluetoothAddress addr
    )
{
    ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
    switch (a_status)
    {
    case GATT_SUCCESS:
        status = ConnectionStatus::ServiceConnected;
        break;
    case GATT_NO_RESOURCES:
        LogError() << "Cannot create GATT due to no resources";
        break;
    case GATT_ERROR:
        LogError() << "Cannot create GATT due to some error";
        break;
    }
    m_gattConnectionStatusChangedSignal(conn_id, status, client_if, addr);
}

void BluetoothGattClientImplementation::HandleGattServiceSearchingCompleted
    (
    int conn_id,
    int a_status
    )
{
    if (a_status == GATT_SUCCESS)
    {
        gatt_client_interface->get_gatt_db(conn_id);
    }
    else
    {
        LogError() << "GATT service searching failed. status: " << a_status;
    }
}

void BluetoothGattClientImplementation::HandleGattServiceSearchingDetailCompleted
    (
    std::vector<GATT_DB_ELEMENT> a_db_elements,
    int a_connection_id
    )
{
    m_gattServiceSearchCompletedSignal(a_db_elements, a_connection_id);
}

void BluetoothGattClientImplementation::HandleDescriptorReadCompleted
    (
    int conn_id, int status,
    btgatt_read_params_type a_descriptor
    )
{
    m_descriptorReadCompletedSignal(conn_id, status, a_descriptor);
}

void BluetoothGattClientImplementation::HandleCharacteristicWriteCompleted
    (
    int conn_id, int status,
    uint16_t handle
    )
{
    //m_characteristicWriteCompletedSignal( conn_id, status, handle );
}
