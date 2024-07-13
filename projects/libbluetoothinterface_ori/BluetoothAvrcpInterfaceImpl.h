#pragma once

#include "BT/avrcp/BluetoothAvrcpInterface.h"

#include <cstdint>
#include <include\hardware\bluetooth.h>

#include <types\raw_address.h>

#if __has_include(<hardware/bt_rc_ext.h>)
#include <hardware/bt_rc_ext.h>
#define USING_C_STYLE_CALLBACK
#endif

#if __has_include(<hardware/bt_rc.h>)
#include <hardware/bt_rc.h>
#endif

#include <stack\include\avrc_defs.h>

namespace Bluetooth
{

    class BluetoothAvrcpInterfaceImpl : public BluetoothAvrcpInterface
    {

    public:

        BluetoothAvrcpInterfaceImpl();

        bool SendGetPlayBackStateCmd(BluetoothAddress const&) override;

        virtual bool SendPassThroughCmd
            (
            BluetoothAddress const& a_address,
            AvrcpPassThroughKeyState a_state,
            AvrcpPassThroughKeyCode a_key
            )override;

        bool init() override;

    private:

        btrc_ctrl_interface_t* m_avrcpCtrolInterface = nullptr;
        btrc_ctrl_callbacks_t avrcpCallback;
    };

}

