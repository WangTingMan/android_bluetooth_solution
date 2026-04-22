#pragma once
#include "hardware/ble_advertiser.h"

#include <memory>

#include <BT/BluetoothAddress.h>

class AdvertisingCallbacksImpl;
class BluetoothAdvImplementation
{

public:

    static BluetoothAdvImplementation& GetInstance();

    void init();

    void adv_local_name();

public:

    void OnAdvertisingSetStarted( int reg_id, uint8_t advertiser_id,
        int8_t tx_power, uint8_t status );

    void OnAdvertisingEnabled( uint8_t advertiser_id, bool enable,
        uint8_t status );

    void OnAdvertisingDataSet( uint8_t advertiser_id, uint8_t status );

    void OnScanResponseDataSet( uint8_t advertiser_id, uint8_t status );

    void OnAdvertisingParametersUpdated( uint8_t advertiser_id,
        int8_t tx_power,
        uint8_t status );

    void OnPeriodicAdvertisingParametersUpdated( uint8_t advertiser_id,
        uint8_t status );

    void OnPeriodicAdvertisingDataSet( uint8_t advertiser_id,
        uint8_t status );

    void OnPeriodicAdvertisingEnabled( uint8_t advertiser_id, bool enable,
        uint8_t status );

    void OnOwnAddressRead( uint8_t advertiser_id, uint8_t address_type,
        RawAddress address );

private:

    BleAdvertiserInterface* m_advertising_interface = nullptr;
    uint8_t m_advertiser_id;
    std::shared_ptr<AdvertisingCallbacksImpl> m_adv_callbacks;
    BluetoothAddress m_public_address;
};

