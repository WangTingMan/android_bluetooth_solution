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
};

