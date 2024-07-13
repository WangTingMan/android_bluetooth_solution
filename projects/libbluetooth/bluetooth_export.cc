#include <hardware/bluetooth.h>

#define EXPORT_SYMBOL _declspec(dllexport)

extern bt_interface_t bluetoothInterface;

void test_impl();

extern "C"
{
    EXPORT_SYMBOL void* GetAndroidBluetoothInterface()
    {
        return &bluetoothInterface;
    }

    EXPORT_SYMBOL void test()
    {
        test_impl();
    }
}
