#include <hardware/bt_gatt_client.h>
#include "BluetoothGattServerImplementation.h"
#include "BluetoothBaseImplementation.h"
#include "BT/Adaptor.h"

#include <hardware/bt_gatt.h>
#include <gatt_api.h>

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>
#include <Zhen/logging.h>

#include <base/callback_forward.h>
#include <base/callback.h>

using namespace std::placeholders;
/** Callback invoked in response to register_server */
void _register_server_callback
    (
    int status,
    int server_if,
    const bluetooth::Uuid& app_uuid
    )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_register_server_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        status, server_if, app_uuid
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback indicating that a remote device has connected or been disconnected
 */
void _connection_callback( int conn_id, int server_if, int connected,
    const RawAddress& bda )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_connection_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, server_if, connected, bda
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked in response to create_service */
void _service_added_callback( int status, int server_if,
    const btgatt_db_element_t* a_service,
    size_t service_count )
{
    std::vector<btgatt_db_element_t> service_out;
    for (size_t i = 0; i < service_count; ++i)
    {
        service_out.push_back( a_service[i] );
    }
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_service_added_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        status, server_if, service_out
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked in response to stop_service */
void _service_stopped_callback( int status, int server_if,
    int srvc_handle )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_service_stopped_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        status, server_if, srvc_handle
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback triggered when a service has been deleted */
void _service_deleted_callback( int status, int server_if,
    int srvc_handle )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_service_deleted_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        status, server_if, srvc_handle
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback invoked when a remote device has requested to read a characteristic
 * or descriptor. The application must respond by calling send_response
 */
void _request_read_characteristic_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool is_long )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_request_read_characteristic_cb,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, trans_id, bda, attr_handle, offset, is_long
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback invoked when a remote device has requested to read a characteristic
 * or descriptor. The application must respond by calling send_response
 */
void _request_read_descriptor_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool is_long )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_request_read_descriptor_cb,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, trans_id, bda, attr_handle, offset, is_long
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback invoked when a remote device has requested to write to a
 * characteristic or descriptor.
 */
void _request_write_characteristic_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool need_rsp, bool is_prep,
    const uint8_t* value, size_t length )
{
    std::vector<uint8_t> value_out;
    value_out.insert( value_out.end(), value, value + length );
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_request_write_characteristic_cb,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, trans_id, bda, attr_handle, offset, need_rsp, is_prep, value_out
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

void _request_write_descriptor_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool need_rsp, bool is_prep,
    const uint8_t* value, size_t length )
{
    std::vector<uint8_t> value_out;
    value_out.insert( value_out.end(), value, value + length );
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_request_write_descriptor_cb,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, trans_id, bda, attr_handle, offset, need_rsp, is_prep, value_out
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked when a previously prepared write is to be executed */
void _request_exec_write_callback( int conn_id, int trans_id,
    const RawAddress& bda,
    int exec_write )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_request_exec_write_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, trans_id, bda, exec_write
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback triggered in response to send_response if the remote device
 * sends a confirmation.
 */
void _response_confirmation_callback( int status, int handle )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_response_confirmation_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        status, handle
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback confirming that a notification or indication has been sent
 * to a remote device.
 */
void _indication_sent_callback( int conn_id, int status )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_indication_sent_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, status
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/**
 * Callback notifying an application that a remote device connection is
 * currently congested and cannot receive any more data. An application should
 * avoid sending more data until a further callback is received indicating the
 * congestion status has been cleared.
 */
void _congestion_server_callback( int conn_id, bool congested )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_congestion_server_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, congested
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked when the MTU for a given connection changes */
void _mtu_changed_callback( int conn_id, int mtu )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_mtu_changed_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, mtu
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked when the PHY for a given connection changes */
void _phy_server_updated_callback( int conn_id, uint8_t tx_phy,
    uint8_t rx_phy, uint8_t status )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_phy_server_updated_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, tx_phy, rx_phy, status
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

/** Callback invoked when the connection parameters for a given connection
 * changes */
void _conn_server_updated_callback( int conn_id, uint16_t interval,
    uint16_t latency, uint16_t timeout,
    uint8_t status )
{
    std::shared_ptr< ExecutbleEvent > event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothGattServerImplementation::handle_conn_server_updated_callback,
        std::ref( BluetoothGattServerImplementation::GetInstance() ),
        conn_id, interval, latency, timeout, status
        );
    event->SetExecutableFunction( fun );
    PageManager::GetInstance().PostEvent( event );
}

BluetoothGattServerImplementation::BluetoothGattServerImplementation()
{
    m_clientCallback.register_server_cb = _register_server_callback;
    m_clientCallback.connection_cb = _connection_callback;
    m_clientCallback.service_added_cb = _service_added_callback;
    m_clientCallback.service_stopped_cb = _service_stopped_callback;
    m_clientCallback.service_deleted_cb = _service_deleted_callback;
    m_clientCallback.request_read_characteristic_cb = _request_read_characteristic_cb;
    m_clientCallback.request_read_descriptor_cb = _request_read_descriptor_cb;
    m_clientCallback.request_write_characteristic_cb = _request_write_characteristic_cb;
    m_clientCallback.request_write_descriptor_cb = _request_write_descriptor_cb;
    m_clientCallback.request_exec_write_cb = _request_exec_write_callback;
    m_clientCallback.response_confirmation_cb = _response_confirmation_callback;
    m_clientCallback.indication_sent_cb = _indication_sent_callback;
    m_clientCallback.congestion_cb = _congestion_server_callback;
    m_clientCallback.mtu_changed_cb = _mtu_changed_callback;
    m_clientCallback.phy_updated_cb = _phy_server_updated_callback;
    m_clientCallback.conn_updated_cb = _conn_server_updated_callback;
}

BluetoothGattServerImplementation& BluetoothGattServerImplementation::GetInstance()
{
    static BluetoothGattServerImplementation instance;
    return instance;
}

BluetoothGattServerInterface& BluetoothGattServerInterface::GetInterface()
{
    return BluetoothGattServerImplementation::GetInstance();
}

void BluetoothGattServerImplementation::Init()
{
    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    btgatt_interface_t* gattInterface = reinterpret_cast< btgatt_interface_t* >( const_cast< void* >(
        interfaceBt->get_profile_interface( BT_PROFILE_GATT_ID ) ) );

    m_serverInterface = const_cast< btgatt_server_interface_t* >( gattInterface->server );
}

void* BluetoothGattServerImplementation::GetGattServerCallback()
{
    void* p = nullptr;
    p = &m_clientCallback;
    return p;
}

void BluetoothGattServerImplementation::RegisterGattServer
    (
    std::vector<uint8_t> a_uuid,
    bool a_support_eatt
    )
{
    bluetooth::Uuid uuid;
    memcpy( uuid.uu.data(), a_uuid.data(), bluetooth::Uuid::kNumBytes128 );
    m_serverInterface->register_server( uuid, a_support_eatt );
}

void BluetoothGattServerImplementation::UnregisterGattServer
    (
    int a_server_id
    )
{
    m_serverInterface->unregister_server( a_server_id );
}

void BluetoothGattServerImplementation::StopGattService
    (
    int server_if,
    int service_handle
    )
{

}

void BluetoothGattServerImplementation::Connect
    (
    int server_if,
    const BluetoothAddress& bd_addr,
    bool is_direct,
    int transport
    )
{

}

void BluetoothGattServerImplementation::Disconnect
    (
    int server_if,
    const BluetoothAddress& bd_addr,
    int conn_id
    )
{

}

void BluetoothGattServerImplementation::AddServiceBody
    (
    int server_if,
    std::vector<GATT_DB_ELEMENT> service_elements
    )
{
    std::vector<btgatt_db_element_t> service;
    for (auto& ele : service_elements)
    {
        /*
        btgatt_db_element_t db_ele;
        db_ele.id = ele.id;
        memcpy( db_ele.uuid.uu.data(), ele.uuid.data(), bluetooth::Uuid::kNumBytes128 );
        switch (ele.type)
        {
        case GATT_DB_TYPE::BTGATT_DB_PRIMARY_SERVICE:
            db_ele.type = BTGATT_DB_PRIMARY_SERVICE;
            break;
        case GATT_DB_TYPE::BTGATT_DB_SECONDARY_SERVICE:
            db_ele.type = BTGATT_DB_SECONDARY_SERVICE;
            break;
        case GATT_DB_TYPE::BTGATT_DB_INCLUDED_SERVICE:
            db_ele.type = BTGATT_DB_INCLUDED_SERVICE;
            break;
        case GATT_DB_TYPE::BTGATT_DB_CHARACTERISTIC:
            db_ele.type = BTGATT_DB_CHARACTERISTIC;
            break;
        case GATT_DB_TYPE::BTGATT_DB_DESCRIPTOR:
            db_ele.type = BTGATT_DB_DESCRIPTOR;
            break;
        }
        db_ele.attribute_handle = ele.attribute_handle;
        db_ele.start_handle = ele.start_handle;
        db_ele.end_handle = ele.end_handle;
        db_ele.properties = ele.properties;
        db_ele.permissions = ele.permissions;
        db_ele.extended_properties = ele.extended_properties;
        service.push_back( db_ele );
        */
    }

    m_serverInterface->add_service( server_if, service.data(), service.size() );
}

void BluetoothGattServerImplementation::SendResponse
    (
    int conn_id,
    int trans_id,
    int status,
    GATTResponseContent response
    )
{

}

void BluetoothGattServerImplementation::StopService
    (
    int server_if,
    int service_handle
    )
{

}

void BluetoothGattServerImplementation::DeleteService
    (
    int server_if,
    int service_handle
    )
{

}

void BluetoothGattServerImplementation::SendIndication
    (
    int server_if,
    int attribute_handle,
    int conn_id,
    int confirm,
    std::vector<uint8_t> value
    )
{

}

void BluetoothGattServerImplementation::SendResponse
    (
    int conn_id,
    int trans_id,
    int status,
    const btgatt_response_t& response
    )
{

}

void BluetoothGattServerImplementation::SetPreferredPhy
    (
    const BluetoothAddress& bd_addr,
    uint8_t tx_phy,
    uint8_t rx_phy,
    uint16_t phy_options
    )
{

}

void BluetoothGattServerImplementation::ReadPhy
    (
    const BluetoothAddress& bd_addr
    )
{
    base::Callback<void( uint8_t tx_phy, uint8_t rx_phy, uint8_t status )> cb;

}

void BluetoothGattServerImplementation::handle_register_server_callback
    (
    int status,
    int server_if,
    const bluetooth::Uuid& app_uuid
    )
{
    std::vector<uint8_t> uuid;
    uuid.assign( app_uuid.uu.begin(), app_uuid.uu.begin() + bluetooth::Uuid::kNumBytes128 );

    //m_gattClientInitializedSignal( status == GATT_SUCCESS, server_if, uuid );
}

void BluetoothGattServerImplementation::handle_connection_callback
(
    int conn_id,
    int server_if,
    int connected,
    const RawAddress& bda
)
{

}

void BluetoothGattServerImplementation::handle_service_added_callback( int status, int server_if, std::vector<btgatt_db_element_t> service )
{

}

void BluetoothGattServerImplementation::handle_service_stopped_callback( int status, int server_if,
    int srvc_handle )
{

}

void BluetoothGattServerImplementation::handle_service_deleted_callback( int status, int server_if,
    int srvc_handle )
{

}

void BluetoothGattServerImplementation::handle_request_read_characteristic_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool is_long )
{

}

void BluetoothGattServerImplementation::handle_request_read_descriptor_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool is_long )
{

}

void BluetoothGattServerImplementation::handle_request_write_characteristic_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool need_rsp, bool is_prep,
    std::vector<uint8_t> value )
{

}

void BluetoothGattServerImplementation::handle_request_write_descriptor_cb( int conn_id, int trans_id,
    const RawAddress& bda, int attr_handle,
    int offset, bool need_rsp, bool is_prep,
    std::vector<uint8_t> value )
{

}

void BluetoothGattServerImplementation::handle_request_exec_write_callback( int conn_id, int trans_id,
    const RawAddress& bda,
    int exec_write )
{

}

void BluetoothGattServerImplementation::handle_response_confirmation_callback( int status, int handle )
{

}

void BluetoothGattServerImplementation::handle_indication_sent_callback( int conn_id, int status )
{

}

void BluetoothGattServerImplementation::handle_congestion_server_callback( int conn_id, bool congested )
{

}

void BluetoothGattServerImplementation::handle_mtu_changed_callback( int conn_id, int mtu )
{

}

void BluetoothGattServerImplementation::handle_phy_server_updated_callback( int conn_id, uint8_t tx_phy,
    uint8_t rx_phy, uint8_t status )
{

}

void BluetoothGattServerImplementation::handle_conn_server_updated_callback( int conn_id, uint16_t interval,
    uint16_t latency, uint16_t timeout,
    uint8_t status )
{

}