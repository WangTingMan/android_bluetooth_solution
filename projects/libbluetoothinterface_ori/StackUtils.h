#pragma once

#include <hardware/bluetooth.h>

#include <BT/BluetoothCommonDefs.h>
#include <BT/common/BluetoothUuid.h>

DeviceControllerType convert(bt_device_type_t a_type);

DiscoveryState convert(bt_discovery_state_t a_state);

BluetoothUuid convert(bluetooth::Uuid const& a_android_uui);

