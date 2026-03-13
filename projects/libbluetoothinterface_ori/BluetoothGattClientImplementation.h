#pragma once
#include <memory>
#include <vector>
#include <cstdint>

#include <Zhen/global.h>

#include <BT/BluetoothCommonDefs.h>
#include <BT/BluetoothAddress.h>
#include <BT/StackLayer/BluetoothGattClientInterface.h>

#include <hardware/bt_common_types.h>
#include <hardware/bt_gatt_client.h>

class BluetoothGatt;
class BluetoothGattClientImplementation : public BluetoothGattClientInterface
{

    friend class BluetoothGatt;

public:

    static BluetoothGattClientImplementation& GetInstance();

    BluetoothGattClientImplementation();

    void Init();

    bool Connect
        (
        BluetoothAddress a_address,
        int a_client_if
        );

    bool disconnect
        (
        BluetoothAddress a_address
        );

    bool IsInitlialized()const;

    void* GetInterface();

    int GetInterfaceNumber();

    void RegisterClientUuid
        (
        std::vector<uint8_t> a_uuid,
        bool a_support_eatt
        );

    void SearchServiceByUuid
        (
        std::vector<uint8_t> a_uuid,
        int a_connection_id
        );

    void RegisterNotification
        (
        int client_if,
        BluetoothAddress a_address,
        int16_t a_handle
        );

    void WriteCharacteristic
        (
        int conn_id, uint16_t handle,
        int write_type, int auth_req,
        const uint8_t* value, size_t length
        );

    void ReadDescriptor
        (
        int conn_id, uint16_t handle, int auth_req
        );

    void GetDbByConnectId( int conn_id );

    boost_ns::signals2::connection ConnectToSignalGattClientInited
        (
        std::function<void()> a_fun
        )
    {
        return m_gattClientInitializedSignal.connect( a_fun );
    }

    boost_ns::signals2::connection ConnectToSignalGattClientMessageEmiited
        (
        std::function<void( std::shared_ptr< GattClientBaseMessage> ) > a_fun
        )
    {
        return m_gattClientMessageSignal.connect( a_fun );
    }

    boost_ns::signals2::connection ConnectToClientRegistered
        (
        std::function<void(int, int, std::vector<uint8_t>)> a_fun
        )
    {
        return m_gattClientRegisteredSignal.connect(a_fun);
    }

    boost_ns::signals2::connection ConnectToConnectionStatusChanged
        (
        std::function<void(int/*conn_id*/, ConnectionStatus/*a_status*/, int/*client_if*/, BluetoothAddress)> a_fun
        )
    {
        return m_gattConnectionStatusChangedSignal.connect(a_fun);
    }

    boost_ns::signals2::connection ConnectToServiceSearchCompleted
        (
        std::function<void(std::vector<btgatt_db_element_type>, int)> a_fun
        )
    {
        return m_gattServiceSearchCompletedSignal.connect(a_fun);
    }

    boost_ns::signals2::connection ConnectToDescriptorReadCompleted
        (
        std::function<void(int, int, btgatt_read_params_type)> a_fun
        )
    {
        return m_descriptorReadCompletedSignal.connect(a_fun);
    }

    boost_ns::signals2::connection ConnectToCharacteristicWriteCompleted
        (
        std::function<void(int conn_id, int status,
            uint16_t handle, uint16_t len, std::vector<uint8_t> value )> a_fun
        )
    {
        return m_characteristicWriteCompletedSignal.connect(a_fun);
    }

public:

    void HandleClientCallbackMessage( std::shared_ptr< GattClientBaseMessage> );

    void* GetGattClientCallback();

public:

    /**
     * Handle callback from stack
     */
    void HandleClientRegistered
        (
        int status,
        int client_if,
        std::vector<uint8_t> uuid
        );

    void HandleGattConnectionStatusChanged
        (
        int/*conn_id*/,
        int/*a_status*/,
        int/*client_if*/,
        BluetoothAddress
        );

    void HandleGattServiceSearchingCompleted
        (
        int/*conn_id*/,
        int/*a_status*/
        );

    void HandleGattServiceSearchingDetailCompleted
        (
        std::vector<btgatt_db_element_type> a_db_elements,
        int a_connection_id
        );

    void HandleDescriptorReadCompleted
        (
        int conn_id, int status,
        btgatt_read_params_type a_descriptor
        );

    void HandleCharacteristicWriteCompleted
        (
        int conn_id, int status,
        uint16_t handle
        );

private:

    boost_ns::signals2::signal<void()> m_gattClientInitializedSignal;
    boost_ns::signals2::signal<void(int, int, std::vector<uint8_t>)> m_gattClientRegisteredSignal;
    boost_ns::signals2::signal<void(int/*conn_id*/, ConnectionStatus/*a_status*/, int/*client_if*/, BluetoothAddress)> m_gattConnectionStatusChangedSignal;
    boost_ns::signals2::signal<void(std::shared_ptr<GattClientBaseMessage>)> m_gattClientMessageSignal;
    boost_ns::signals2::signal<void(std::vector<btgatt_db_element_type>, int)> m_gattServiceSearchCompletedSignal;
    boost_ns::signals2::signal<void(int, int, btgatt_read_params_type)> m_descriptorReadCompletedSignal;
    boost_ns::signals2::signal<void(int, int, uint16_t, uint16_t, std::vector<uint8_t>)> m_characteristicWriteCompletedSignal;

    btgatt_client_callbacks_t m_clientCallback;
    btgatt_client_interface_t* gatt_client_interface = nullptr;
    int btifNumber = 0;
};

