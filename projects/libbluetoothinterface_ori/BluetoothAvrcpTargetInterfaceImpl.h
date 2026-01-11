#pragma once

#include <cstdint>
#include <include\hardware\bluetooth.h>

#include <types\raw_address.h>

#if __has_include(<hardware/bt_rc.h>)
#include <hardware/bt_rc.h>
#endif

#include <stack\include\avrc_defs.h>

#include "BT/StackLayer/BluetoothAvrcpTargetInterface.h"

namespace Bluetooth {

class BluetoothAvrcpTargetInterfaceImpl : public BluetoothAvrcpTargetInterface
{

public:

    BluetoothAvrcpTargetInterfaceImpl();

    static BluetoothAvrcpTargetInterfaceImpl& GetInterface();

    void Init() override;

    bool Connect
        (
        BluetoothAddress a_address
        ) override;

    bool disconnect
        (
        BluetoothAddress a_address
        ) override;

    bool setActiveDevice
        (
        BluetoothAddress a_address
        ) override;

    bool setSilenceDevice
        (
        BluetoothAddress a_address
        ) override;

private:

    btrc_interface_t* m_avrcpTargetInterface;
    btrc_callbacks_t m_avrcpTargetCallback;
};

}
