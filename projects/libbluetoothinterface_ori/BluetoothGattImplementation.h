#pragma once
#include <memory>

#include <hardware/ble_scanner.h>
#include <hardware/bt_gatt.h>

class BluetoothGattImpl;

class BluetoothGattImplementation
{

public:

    static BluetoothGattImplementation& GetInstance();

    BluetoothGattImplementation();

    void init();

    void* GetScannerInterface();

private:

    bool m_inited = false;
    btgatt_scanner_callbacks_t m_scannerCallback;
    btgatt_callbacks_t m_callback;
    BleScannerInterface* scannerInterface = nullptr;
    BleAdvertiserInterface* advertiserInterface = nullptr;
    btgatt_interface_t* m_btgatt_interface = nullptr;
};

