#pragma once

#include "BT/StackLayer/BluetoothA2DPSinkInterface.h"

#include <hardware/bt_av.h>

class BluetoothA2DPSinkImplementation : public BluetoothA2DPSinkInterface
{

public:

    static BluetoothA2DPSinkImplementation& GetInstance();

    void Init() override;

    bool Connect
        (
        BluetoothAddress a_address
        )override;

    bool disconnect
        (
        BluetoothAddress a_address
        )override;

    void SetAudioFocus
        (
        bool a_grant
        )override;

private:

    btav_sink_interface_t* m_a2dpSinkInterface = nullptr;
    btav_sink_callbacks_t m_avCallback;
};

