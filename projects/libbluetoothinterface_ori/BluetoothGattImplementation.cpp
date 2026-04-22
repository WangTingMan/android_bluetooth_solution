#include "BluetoothGattImplementation.h"
#include "BluetoothGattServerImplementation.h"
#include "BluetoothGattClientImplementation.h"
#include "BluetoothBaseImplementation.h"
#include "BT/Adaptor.h"
#include "BluetoothAdvScannerImplementation.h"
#include "BluetoothAdvImplementation.h"

#include <hardware/bt_gatt.h>

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

/** Callback invoked when batchscan reports are obtained */
void _batchscan_reports_callback( int client_if, int status,
    int report_format, int num_records,
    std::vector<uint8_t> data )
{

}

/** Callback invoked when batchscan storage threshold limit is crossed */
void _batchscan_threshold_callback( int client_if )
{

}

/** Track ADV VSE callback invoked when tracked device is found or lost */
void _track_adv_event_callback(
    btgatt_track_adv_info_t* p_track_adv_info )
{

}

/** Callback for scan results */
void _scan_result_callback( uint16_t event_type, uint8_t addr_type,
    RawAddress* bda, uint8_t primary_phy,
    uint8_t secondary_phy,
    uint8_t advertising_sid, int8_t tx_power,
    int8_t rssi, uint16_t periodic_adv_int,
    std::vector<uint8_t> adv_data, RawAddress* original_bda )
{

}

BluetoothGattImplementation& BluetoothGattImplementation::GetInstance()
{
    static BluetoothGattImplementation instance;
    return instance;
}

BluetoothGattImplementation::BluetoothGattImplementation()
{
    m_scannerCallback.scan_result_cb = _scan_result_callback;
    m_scannerCallback.batchscan_reports_cb = _batchscan_reports_callback;
    m_scannerCallback.batchscan_threshold_cb = _batchscan_threshold_callback;
    m_scannerCallback.track_adv_event_cb = _track_adv_event_callback;
}

void BluetoothGattImplementation::init()
{
    if( m_inited )
    {
        return;
    }

    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    m_btgatt_interface = reinterpret_cast<btgatt_interface_t*>(const_cast<void*>(
        interfaceBt->get_profile_interface(BT_PROFILE_GATT_ID)));

    BluetoothGattServerImplementation::GetInstance().Init();
    BluetoothGattClientImplementation::GetInstance().Init();

    m_callback.client = reinterpret_cast<btgatt_client_callbacks_t*>( BluetoothGattClientImplementation::GetInstance().GetGattClientCallback() );
    m_callback.server = reinterpret_cast<btgatt_server_callbacks_t*>( BluetoothGattServerImplementation::GetInstance().GetGattServerCallback() );
    m_callback.scanner = &( m_scannerCallback );
    m_callback.size = sizeof( btgatt_callbacks_t );
    m_btgatt_interface->init( &( m_callback ) );
    scannerInterface = m_btgatt_interface->scanner;
    advertiserInterface = m_btgatt_interface->advertiser;

    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>
            (
            std::bind(&BluetoothAdvScannerImplementation::init, std::ref(BluetoothAdvScannerImplementation::GetInstance()))
            ) );

    PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>
            (
            std::bind( &BluetoothAdvImplementation::init,
                std::ref( BluetoothAdvImplementation::GetInstance() ) )
            ) );
}

void* BluetoothGattImplementation::GetScannerInterface()
{
    return scannerInterface;
}

