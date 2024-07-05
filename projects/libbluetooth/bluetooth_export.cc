#include <hardware/bluetooth.h>

#define EXPORT_SYMBOL _declspec(dllexport)

extern bt_interface_t bluetoothInterface;

extern "C"
{
    EXPORT_SYMBOL void* GetAndroidBluetoothInterface()
    {
        return &bluetoothInterface;
    }
}