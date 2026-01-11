#pragma once

#include <memory>
#include <vector>

#include <BT/StackLayer/BluetoothRfcommInterface.h>

#include <hardware/bluetooth.h>
#include <hardware/bt_av.h>
#include <hardware/bt_sock.h>

class BluetoothRfcommImplementation : public BluetoothRfcommInterface
{

public:

    static BluetoothRfcommImplementation& GetInterface();

    virtual ~BluetoothRfcommImplementation() {}

    virtual void Init();

    virtual bool Connect
        (
        BluetoothAddress a_address,
        std::string a_service_name,
        int a_channel
        );

    virtual bool disconnect
        (
        BluetoothAddress a_address
        );

    bool listen
        (
        std::string const& a_service_name,
        std::vector<uint8_t> a_service_uuid,
        int a_user_id,
        int a_channel = 0
        );

    void send
        (
        int a_connect_id,
        std::shared_ptr<std::vector<uint8_t>> a_data
        );

    void disconnect( int a_connect_id );

public:

    void HandleConnectionSiangl
        (
        int a_user_id,
        sock_connect_signal_t a_signal
        );

    void HandleDisconnectionSiangl
        (
        int a_connect_id
        );

    void HandleReceivedDataFromRemote
        (
        int a_connect_id,
        std::shared_ptr<std::vector<uint8_t>> a_data
        );

private:

    btsock_interface_t* m_sock_interface = nullptr;
};

