#include "BluetoothAdvScanningImplementation.h"

#include "BT/BluetoothAddress.h"

#include <Zhen/logging.h>
#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

#include <base/bind.h>
#include <base/callback.h>

void _FilterParamSetupCallback(uint8_t avbl_space, uint8_t action_type,
    uint8_t btm_status)
{
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>
        (
            std::bind(&BluetoothAdvScanningImplementation::HandleFilterParamSetupCallback,
                std::ref(BluetoothAdvScanningImplementation::GetInstance()), avbl_space, action_type, btm_status)
        ));
}

void ScanningCallbacksImpl::OnScannerRegistered(const bluetooth::Uuid app_uuid,
    uint8_t scannerId, uint8_t status)
{

}

void ScanningCallbacksImpl::OnSetScannerParameterComplete(uint8_t scannerId,
    uint8_t status)
{

}

void ScanningCallbacksImpl::OnScanResult(uint16_t event_type, uint8_t addr_type,
    RawAddress bda, uint8_t primary_phy,
    uint8_t secondary_phy, uint8_t advertising_sid,
    int8_t tx_power, int8_t rssi,
    uint16_t periodic_adv_int,
    std::vector<uint8_t> adv_data)
{
    BluetoothAddress address;
    memcpy(address.address, bda.address, BluetoothAddress::kLength);
    LogInfo() << "LE scanning result: " << address.ToString();
}

void ScanningCallbacksImpl::OnTrackAdvFoundLost(
    AdvertisingTrackInfo advertising_track_info)
{

}

void ScanningCallbacksImpl::OnBatchScanReports(int client_if, int status, int report_format,
    int num_records,
    std::vector<uint8_t> data)
{

}

void ScanningCallbacksImpl::OnBatchScanThresholdCrossed(int client_if)
{

}

void ScanningCallbacksImpl::OnPeriodicSyncStarted(int reg_id, uint8_t status,
    uint16_t sync_handle,
    uint8_t advertising_sid,
    uint8_t address_type, RawAddress address,
    uint8_t phy, uint16_t interval)
{

}

void ScanningCallbacksImpl::OnPeriodicSyncReport(uint16_t sync_handle, int8_t tx_power,
    int8_t rssi, uint8_t status,
    std::vector<uint8_t> data)
{

}

void ScanningCallbacksImpl::OnPeriodicSyncLost(uint16_t sync_handle)
{

}

void ScanningCallbacksImpl::OnPeriodicSyncTransferred(int pa_source, uint8_t status,
    RawAddress address)
{

}

void ScanningCallbacksImpl::OnBigInfoReport(uint16_t sync_handle, bool encrypted)
{

}

BluetoothAdvScanningInterface& BluetoothAdvScanningInterface::GetInterface()
{
    return BluetoothAdvScanningImplementation::GetInstance();
}

BluetoothAdvScanningImplementation& BluetoothAdvScanningImplementation::GetInstance()
{
    static BluetoothAdvScanningImplementation instance;
    return instance;
}

void BluetoothAdvScanningImplementation::Init()
{
}

void BluetoothAdvScanningImplementation::StartFullScan(bool a_start)
{
    m_scanner_interface->Scan(a_start);
}

void BluetoothAdvScanningImplementation::StartFilterScan()
{

    btgatt_filt_param_setup_t params;
    memset(&params, 0x00, sizeof(btgatt_filt_param_setup_t));

    // btgatt_filt_param_setup_t's information: https://source.android.com/docs/core/connect/bluetooth/hci_requirements
    params.feat_seln;       // APCF_Frature_Selection
    params.list_logic_type;
    params.filt_logic_type;
    params.rssi_high_thres;

    /*
    * DeliveryMode. IMMEDIATE = 0x0,ONFOUND = 0x1,BATCHED = 0x2. All other values are invalid.
    * Only when dely_mode equals ONFOUND, then found_timeout, found_timeout_cnt, rssi_low_thres,
    * lost_timeout and num_of_tracking_entries take effect.
    */
    params.dely_mode = 0x1;

    params.found_timeout;
    params.found_timeout_cnt;
    params.rssi_low_thres;
    params.lost_timeout;
    params.num_of_tracking_entries;

    uint8_t client_if = 0; // user app's id. Only invalid when dely_mode equal 0x1 and action equals 0x0

    /* Action:  0x0 for adding, 0x01 for delete, 0x3 for clear.
    * All other values are invalid.
    */
    uint8_t action = 0;     // APCF_Action

    uint8_t filt_index = 0; /* APCF_Filter_Index.Stack will hold a map(key is filt_index, and the value )
                             * The map's max size is total_num_of_advt_tracked's value */

                             /*
                             * ScanFilterParamSetup is to execute the android's bluetooth HCI extension operation: Apcf
                             */
    m_scanner_interface->ScanFilterParamSetup(client_if, action, filt_index,
        std::make_unique<btgatt_filt_param_setup_t>(params),
        base::Bind(&_FilterParamSetupCallback));
}

void BluetoothAdvScanningImplementation::HandleFilterParamSetupCallback(uint8_t avbl_space, uint8_t action_type,
    uint8_t btm_status)
{
    LogInfo() << "avbl_space: " << avbl_space << ", action_type: " << action_type
        << ", btm status: " << btm_status;
}

