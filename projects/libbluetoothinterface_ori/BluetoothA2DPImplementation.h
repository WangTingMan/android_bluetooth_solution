#pragma once

#include <BT/StackLayer/BluetoothA2DPInterface.h>

#include <hardware/bluetooth.h>
#include <hardware/bt_av.h>

class BluetoothA2DPImplementation : public BluetoothA2DPInterface
{

public:

    static BluetoothA2DPImplementation& GetInterface();

    void Init() override;

    bool Connect
        (
        BluetoothAddress a_address
        )override;

    bool disconnect
        (
        BluetoothAddress a_address
        )override;

    bool setActiveDevice
        (
        BluetoothAddress a_address
        )override;

    bool setSilenceDevice
        (
        BluetoothAddress a_address
        )override;

private:

    btav_source_callbacks_t m_callBack;
    btav_source_interface_t* m_av_source_interface = nullptr;
};

