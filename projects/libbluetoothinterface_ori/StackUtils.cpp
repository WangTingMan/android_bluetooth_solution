#include "StackUtils.h"

DeviceControllerType convert(bt_device_type_t a_type)
{
    switch (a_type)
    {
    case BT_DEVICE_DEVTYPE_BREDR:
        return DeviceControllerType::BREDR;
        break;
    case BT_DEVICE_DEVTYPE_BLE:
        return DeviceControllerType::LEONLY;
        break;
    case BT_DEVICE_DEVTYPE_DUAL:
        return DeviceControllerType::DUAL;
        break;
    default:
        break;
    }
    return DeviceControllerType::BREDR;
}

DiscoveryState convert(bt_discovery_state_t a_state)
{
    switch (a_state)
    {
    case BT_DISCOVERY_STOPPED:
        return DiscoveryState::BT_DISCOVERY_STOPPED;
        break;
    case BT_DISCOVERY_STARTED:
        return DiscoveryState::BT_DISCOVERY_STARTED;
        break;
    default:
        break;
    }
    return DiscoveryState::BT_DISCOVERY_STOPPED;
}

BluetoothUuid convert(bluetooth::Uuid const& a_android_uui)
{
    BluetoothUuid uuid{};
    return uuid;
}

