#pragma once
#include <memory>

#include <hardware/bt_common_types.h>
#include <hardware/bt_gatt_server.h>

#include <BT/BluetoothAddress.h>
#include <BT/StackLayer/BluetoothGattServerInterface.h>

class BluetoothGatt;
class BluetoothGattServerImplementation : public BluetoothGattServerInterface
{

    friend class BluetoothGatt;

public:

    static BluetoothGattServerImplementation& GetInstance();

    BluetoothGattServerImplementation();

    void Init();

public:

    void* GetGattServerCallback();

    void RegisterGattServer
        (
        std::vector<uint8_t> a_uuid,
        bool a_support_eatt
        );

    void UnregisterGattServer
        (
        int a_server_id
        );

    void StopGattService
        (
        int server_if,
        int service_handle
        );

    void Connect
        (
        int server_if,
        const BluetoothAddress& bd_addr,
        bool is_direct,
        int transport
        );

    void Disconnect
        (
        int server_if,
        const BluetoothAddress& bd_addr,
        int conn_id
        );

    void AddServiceBody
        (
        int server_if,
        std::vector<GATT_DB_ELEMENT> service_elements
        );

    void SendResponse
        (
        int conn_id,
        int trans_id,
        int status,
        GATTResponseContent response
        );

    void StopService( int server_if, int service_handle );

    void DeleteService( int server_if, int service_handle );

    void SendIndication( int server_if, int attribute_handle,
        int conn_id, int confirm,
        std::vector<uint8_t> value );

    void SendResponse( int conn_id, int trans_id, int status,
        const btgatt_response_t& response );

    void SetPreferredPhy( const BluetoothAddress& bd_addr, uint8_t tx_phy,
        uint8_t rx_phy, uint16_t phy_options );

    void ReadPhy( const BluetoothAddress& bd_addr );

public:

    /**
     * GATT服务需要使用一个UUID来注册接口，协议栈会记录这个UUID值，并且告知所注册的ID。
     * 应用层调用RegisterGattServer来注册一个服务接口，随后通过本信号告知注册的结果。
     * status是注册状态；server_if是注册的ID；uuid是注册是所传递的UUID
     */
    boost_ns::signals2::connection ConnectToServiceRegistered
        (
        std::function<void( int /*status*/, int/*server_if*/, std::vector<uint8_t>/*uuid*/ )> a_fun
        )
    {
        return m_gattServiceRegisteredSignal.connect( (a_fun) );
    }

    boost_ns::signals2::connection connect_to_service_body_added
        (
        std::function<void( int status, int server_if, std::vector<GATT_DB_ELEMENT> )> a_fun
        )
    {
        return m_gatt_service_body_added_signal.connect( (a_fun) );
    }

    boost_ns::signals2::connection connect_to_client_connection_status_changed
        (
        std::function<void( int conn_id, int server_if, ConnectionStatus status, BluetoothAddress addr )> a_fun
        )
    {
        return m_client_connection_status_changed.connect( a_fun );
    }

    boost_ns::signals2::connection connect_to_client_read_desciptor_request
        (
        std::function<void(
            int conn_id,
            int trans_id,
            const BluetoothAddress& bda,
            int attr_handle,
            int offset,
            bool is_long )> a_fun
        )
    {
        return m_client_read_descriptor_request_siganl.connect( a_fun );
    }

    boost_ns::signals2::connection connect_to_client_read_characteristic_request
        (
        std::function<void(
            int conn_id,
            int trans_id,
            const BluetoothAddress& bda,
            int attr_handle,
            int offset,
            bool is_long )> a_fun
        )
    {
        return m_client_read_characteristic_request_siganl.connect( a_fun );
    }

    boost_ns::signals2::connection connect_to_client_write_characteristic_request
        (
        std::function<void(
            int conn_id,
            int trans_id,
            const BluetoothAddress& bda,
            int attr_handle,
            int offset,
            bool need_rsp,
            bool is_prep,
            std::vector<uint8_t> value )> a_fun
        )
    {
        return m_client_request_write_characteristic_siganl.connect( a_fun );
    }

public:

    void handle_register_server_callback
        (
        int status,
        int server_if,
        const bluetooth::Uuid& app_uuid
        );

    void handle_connection_callback
        (
        int conn_id,
        int server_if,
        int connected,
        const RawAddress& bda
        );

    void handle_service_added_callback( int status, int server_if, std::vector<btgatt_db_element_t> service );

    void handle_service_stopped_callback( int status, int server_if,
        int srvc_handle );

    void handle_service_deleted_callback( int status, int server_if,
        int srvc_handle );

    void handle_request_read_characteristic_cb( int conn_id, int trans_id,
        const RawAddress& bda, int attr_handle,
        int offset, bool is_long );

    void handle_request_read_descriptor_cb( int conn_id, int trans_id,
        const RawAddress& bda, int attr_handle,
        int offset, bool is_long );

    void handle_request_write_characteristic_cb( int conn_id, int trans_id,
        const RawAddress& bda, int attr_handle,
        int offset, bool need_rsp, bool is_prep,
        std::vector<uint8_t> value );

    void handle_request_write_descriptor_cb( int conn_id, int trans_id,
        const RawAddress& bda, int attr_handle,
        int offset, bool need_rsp, bool is_prep,
        std::vector<uint8_t> value );

    void handle_request_exec_write_callback( int conn_id, int trans_id,
        const RawAddress& bda,
        int exec_write );

    void handle_response_confirmation_callback( int status, int handle );

    void handle_indication_sent_callback( int conn_id, int status );

    void handle_congestion_server_callback( int conn_id, bool congested );

    void handle_mtu_changed_callback( int conn_id, int mtu );

    void handle_phy_server_updated_callback( int conn_id, uint8_t tx_phy,
        uint8_t rx_phy, uint8_t status );

    void handle_conn_server_updated_callback( int conn_id, uint16_t interval,
        uint16_t latency, uint16_t timeout,
        uint8_t status );

private:

    btgatt_server_interface_t* m_serverInterface = nullptr;
    btgatt_server_callbacks_t m_clientCallback;

    boost_ns::signals2::signal<void( int, int, std::vector<uint8_t> )> m_gattServiceRegisteredSignal;
    boost_ns::signals2::signal<void( int, int, std::vector<GATT_DB_ELEMENT> )> m_gatt_service_body_added_signal;
    boost_ns::signals2::signal<void( int conn_id, int servcer_id, ConnectionStatus status, BluetoothAddress addr )> m_client_connection_status_changed;
    boost_ns::signals2::signal<void(
        int conn_id,
        int trans_id,
        const BluetoothAddress& bda,
        int attr_handle,
        int offset,
        bool is_long )> m_client_read_descriptor_request_siganl;
    boost_ns::signals2::signal<void(
        int conn_id,
        int trans_id,
        const BluetoothAddress& bda,
        int attr_handle,
        int offset,
        bool is_long )> m_client_read_characteristic_request_siganl;
    boost_ns::signals2::signal<void(
        int conn_id,
        int trans_id,
        const BluetoothAddress& bda,
        int attr_handle,
        int offset,
        bool need_rsp,
        bool is_prep,
        std::vector<uint8_t> value )> m_client_request_write_characteristic_siganl;
};

