#pragma once
#include "BT/StackLayer/BluetoothPANInterface.h"

#include <hardware/bluetooth.h>
#include <hardware/bt_pan.h>

class BluetoothPANImplementation : public BluetoothPANInterface
{

public:

	static BluetoothPANImplementation& GetInstance();

	void Init() override;

    virtual bool Connect(BluetoothAddress a_address) override;

    virtual bool disconnect(BluetoothAddress a_address) override;

private:

	btpan_interface_t* m_pan_interface = nullptr;
    btpan_callbacks_t m_callbacks;
};

