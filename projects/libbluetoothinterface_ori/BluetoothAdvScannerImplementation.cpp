#include "BluetoothAdvScannerImplementation.h"

#include "BT/BluetoothAddress.h"
#include "BT/StackLayer/BluetoothAdvScanningInterface.h"

#include <Zhen/logging.h>
#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

#include <base/bind.h>
#include <base/callback.h>

struct AdvScannerImpl
{
    AdvScannerImpl();

    static AdvScannerImpl& GetInstance();

    void HandleScannerCallback(uint8_t scanner_id, uint8_t btm_status );

    bool IsInitialized();

    bool initialized = false;
    std::vector<uint8_t> m_registered_uuid;
};

AdvScannerImpl::AdvScannerImpl()
{
    m_registered_uuid = std::vector<uint8_t>{ 0xA9, 0x44, 0x69, 0x73, 0x9b, 0xf0, 0x46,
        0x1f, 0xb5, 0x6a, 0x54, 0x4a, 0xbf, 0x69, 0xe1, 0x15 };
}

AdvScannerImpl& AdvScannerImpl::GetInstance()
{
    static AdvScannerImpl instance;
    return instance;
}

void AdvScannerImpl::HandleScannerCallback(uint8_t scanner_id, uint8_t btm_status)
{
    LogInfo() << "scanner ID: " << scanner_id << ", status: " << btm_status;
}

bool AdvScannerImpl::IsInitialized()
{
    return initialized;
}

BluetoothAdvScannerImplementation& BluetoothAdvScannerImplementation::GetInstance()
{
    static BluetoothAdvScannerImplementation instance;
    return instance;
}

BluetoothAdvScannerImplementation::BluetoothAdvScannerImplementation()
{

}

void BluetoothAdvScannerImplementation::init()
{
    if (AdvScannerImpl::GetInstance().initialized)
    {
        return;
    }

    BluetoothAdvScanningInterface::GetInterface().Init();
    AdvScannerImpl::GetInstance().initialized = true;
}

void BluetoothAdvScannerImplementation::StartFullScan(bool a_start)
{
    if (!AdvScannerImpl::GetInstance().IsInitialized())
    {
        return;
    }

    BluetoothAdvScanningInterface::GetInterface().StartFullScan(a_start);
}

void BluetoothAdvScannerImplementation::StartFilterScan()
{
    if (!AdvScannerImpl::GetInstance().IsInitialized())
    {
        return;
    }

    BluetoothAdvScanningInterface::GetInterface().StartFilterScan();

}

