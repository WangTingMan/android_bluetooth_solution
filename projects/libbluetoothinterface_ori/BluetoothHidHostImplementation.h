#pragma once
#include <BT/StackLayer/BluetoothHidHostInterface.h>

#include <hardware/bluetooth.h>
#include <hardware/bt_hh.h>
#include <ble_address_with_type.h>

class BluetoothHidHostImplementation : public BluetoothHidHostInterface
{

public:

    static BluetoothHidHostImplementation& GetInstance();

    void Init() override;

    bool Connect
        (
        BluetoothAddress a_address
        ) override;

    bool disconnect
        (
        BluetoothAddress a_address
        ) override;

    void GetReport
        (
        BluetoothAddress a_address
        ) override;

    void HandleConnectionStatusChanged
        (
        BluetoothAddress bd_addr,
        tBLE_ADDR_TYPE addr_type,
        tBT_TRANSPORT transport,
        bthh_connection_state_t state
        );

private:

    bool m_initialized = false;
    bthh_interface_t* m_interface = nullptr;
    bthh_callbacks_t m_callbacks;
};
