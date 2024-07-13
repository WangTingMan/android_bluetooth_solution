#pragma once

#include <BT/StackLayer/BluetoothAdvScanningInterface.h>

#include <hardware/ble_scanner.h>

class ScanningCallbacksImpl : public ScanningCallbacks
{
public:

    virtual void OnScannerRegistered(const bluetooth::Uuid app_uuid,
        uint8_t scannerId, uint8_t status);
    virtual void OnSetScannerParameterComplete(uint8_t scannerId,
        uint8_t status);
    virtual void OnScanResult(uint16_t event_type, uint8_t addr_type,
        RawAddress bda, uint8_t primary_phy,
        uint8_t secondary_phy, uint8_t advertising_sid,
        int8_t tx_power, int8_t rssi,
        uint16_t periodic_adv_int,
        std::vector<uint8_t> adv_data);
    virtual void OnTrackAdvFoundLost(
        AdvertisingTrackInfo advertising_track_info);
    virtual void OnBatchScanReports(int client_if, int status, int report_format,
        int num_records,
        std::vector<uint8_t> data);
    virtual void OnBatchScanThresholdCrossed(int client_if);
    virtual void OnPeriodicSyncStarted(int reg_id, uint8_t status,
        uint16_t sync_handle,
        uint8_t advertising_sid,
        uint8_t address_type, RawAddress address,
        uint8_t phy, uint16_t interval);
    virtual void OnPeriodicSyncReport(uint16_t sync_handle, int8_t tx_power,
        int8_t rssi, uint8_t status,
        std::vector<uint8_t> data);
    virtual void OnPeriodicSyncLost(uint16_t sync_handle);
    virtual void OnPeriodicSyncTransferred(int pa_source, uint8_t status,
        RawAddress address);
    void OnBigInfoReport(uint16_t sync_handle, bool encrypted);
};

class BluetoothAdvScanningImplementation : public BluetoothAdvScanningInterface
{

public:

    static BluetoothAdvScanningImplementation& GetInstance();

    void Init()override;

    void StartFullScan(bool a_start)override;

    void StartFilterScan()override;

public:

    void HandleFilterParamSetupCallback(uint8_t avbl_space, uint8_t action_type,
        uint8_t btm_status);

private:

    ScanningCallbacksImpl m_scanning_callback;
    BleScannerInterface* m_scanner_interface = nullptr;
};

