#include "BluetoothAdvImplementation.h"
#include "BluetoothGattImplementation.h"

#include <Zhen/logging.h>
#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

#include <base/bind.h>
#include <base/callback.h>

#include <utils/misc.h>

int g_upper_reg_id = 1001;

std::string to_string(AdvertiseParameters const& db)
{
    std::stringstream ss;
    ss << "{ advertising_event_properties: " << db.advertising_event_properties
        << ", min_interval: " << db.min_interval
        << ", max_interval: " << (int)db.max_interval
        << ", channel_map: " << (int)db.channel_map
        << ", tx_power: " << (int)db.tx_power
        << ", primary_advertising_phy: " << (int)db.primary_advertising_phy
        << ", secondary_advertising_phy: " << (int)db.secondary_advertising_phy
        << ", scan_request_notification_enable: " << (int)db.scan_request_notification_enable
        << "}";
    return ss.str();
}

std::string to_string(PeriodicAdvertisingParameters const& parameter)
{
    std::stringstream ss;
    ss << "{enable:" << parameter.enable
        << ", min_interval: " << parameter.min_interval
        << ", max_interval: " << parameter.max_interval
        << ", periodic_advertising_properties: " << parameter.periodic_advertising_properties
        << "}";
    return ss.str();
}

void impl_StatusCallback( uint8_t a_status )
{

}

void impl_GetAddressCallback( uint8_t a_advertiser_id, uint8_t address_type, RawAddress address )
{

}

void impl_advertising_start_callback
    (
    int adv_id,
    uint8_t advertiser_id,
    int8_t tx_power,
    uint8_t status 
    )
{

}

void impl_IdTxPowerStatusCallback
    (
    uint8_t advertiser_id,
    int8_t tx_power,
    uint8_t status
    )
{

}

class AdvertisingCallbacksImpl : public AdvertisingCallbacks
{

public:

    virtual ~AdvertisingCallbacksImpl() = default;

    virtual void OnAdvertisingSetStarted( int reg_id, uint8_t advertiser_id,
        int8_t tx_power, uint8_t status )
    {

    }

    virtual void OnAdvertisingEnabled( uint8_t advertiser_id, bool enable,
        uint8_t status )
    {

    }

    virtual void OnAdvertisingDataSet( uint8_t advertiser_id, uint8_t status )
    {

    }

    virtual void OnScanResponseDataSet( uint8_t advertiser_id, uint8_t status )
    {

    }

    virtual void OnAdvertisingParametersUpdated( uint8_t advertiser_id,
        int8_t tx_power,
        uint8_t status )
    {

    }

    virtual void OnPeriodicAdvertisingParametersUpdated( uint8_t advertiser_id,
        uint8_t status )
    {

    }

    virtual void OnPeriodicAdvertisingDataSet( uint8_t advertiser_id,
        uint8_t status )
    {

    }

    virtual void OnPeriodicAdvertisingEnabled( uint8_t advertiser_id, bool enable,
        uint8_t status )
    {

    }

    virtual void OnOwnAddressRead( uint8_t advertiser_id, uint8_t address_type,
        RawAddress address )
    {

    }

};

BluetoothAdvImplementation& BluetoothAdvImplementation::GetInstance()
{
    static BluetoothAdvImplementation instance;
    return instance;
}

void BluetoothAdvImplementation::init()
{
    m_adv_callbacks = std::make_shared<AdvertisingCallbacksImpl>();

    auto api = BluetoothGattImplementation::GetInstance().GetAdvInterface();
    m_advertising_interface = reinterpret_cast<BleAdvertiserInterface*>(api);
    m_advertising_interface->RegisterCallbacks( m_adv_callbacks.get() );

    using namespace std::placeholders;
    auto fun = std::bind( &BluetoothAdvImplementation::adv_local_name,
        std::ref( BluetoothAdvImplementation::GetInstance() ) );
    auto event_ = std::make_shared<ExecutbleEvent>( fun );
    PageManager::GetInstance().PostEvent( event_ );
}

void BluetoothAdvImplementation::adv_local_name()
{
    std::string device_name{ "myledevice" };

    AdvertiseParameters adv_params = { 0 };
    adv_params.advertising_event_properties = 0x0013; // 可连接非定向广播
    adv_params.min_interval = 32;    // 最小广播间隔：32*0.625ms=20ms
    adv_params.max_interval = 100;   // 最大广播间隔：100*0.625ms=62.5ms
    adv_params.channel_map = 0x07;   // 启用37/38/39广播信道
    adv_params.tx_power = 4;         // 发射功率4dBm（可选：-127~20）
    adv_params.primary_advertising_phy = 1;  // 主PHY：1M
    adv_params.secondary_advertising_phy = 1; // 副PHY：1M
    adv_params.scan_request_notification_enable = 0; // 禁用扫描请求通知

    // 3. 构造广播数据（含设备名称，符合BLE AD格式）
    std::vector<uint8_t> adv_data;
    // AD字段：长度（1+名称长度） + 类型（0x09=完整名称） + 名称内容
    adv_data.push_back( static_cast<uint8_t>(1 + device_name.length()) );
    adv_data.push_back( 0x09 );
    adv_data.insert( adv_data.end(), device_name.begin(), device_name.end() );

    PeriodicAdvertisingParameters periodic_params = { 0 };
    periodic_params.enable = 0; // 禁用周期性广播

    uint8_t client_id = 0;
    int reg_id = 0;

    m_advertising_interface->StartAdvertisingSet
        (
        client_id,
        reg_id,
        base::Bind( impl_IdTxPowerStatusCallback ),
        adv_params, // 基础广播参数
        adv_data,   // 广播数据（设备名称）
        {},         // 无扫描响应数据
        periodic_params, // 周期性广播参数
        {},         // 无周期性广播数据
        0,          // duration=0：无限期广播
        0,          // maxExtAdvEvents=0：无扩展事件限制
        base::Bind( []( uint8_t advertiser_id, uint8_t status ) {
            LogInfo( "广播超时，advertiser_id=%d, status=%d", advertiser_id, status );
            } ) // 超时回调
        );
}

void BluetoothAdvImplementation::OnAdvertisingSetStarted
    (
    int reg_id,
    uint8_t advertiser_id,
    int8_t tx_power,
    uint8_t status
    )
{
    if (status == 0)
    {
        LogInfo( "adv registered. advertiser_id: %d", advertiser_id );
        m_advertiser_id = advertiser_id;
        m_advertising_interface->GetOwnAddress( m_advertiser_id,
            base::Bind( &impl_GetAddressCallback, m_advertiser_id ) );
    }
    else
    {
        LogInfo( "adv registered fail, status: %d", status );
    }
}

void BluetoothAdvImplementation::OnAdvertisingEnabled( uint8_t advertiser_id, bool enable,
    uint8_t status )
{

}


void BluetoothAdvImplementation::OnAdvertisingDataSet( uint8_t advertiser_id, uint8_t status )
{
    if (status == 0)
    {
        LogInfo( "广播名称数据设置成功" );
        m_advertising_interface->Enable
            (
            m_advertiser_id,
            true,
            base::Bind( &impl_StatusCallback  ),
            0, 0,
            base::Bind( &impl_StatusCallback )
            );
    }
    else
    {
        LogInfo( "广播数据设置失败，status: %d", status );
    }
}


void BluetoothAdvImplementation::OnScanResponseDataSet( uint8_t advertiser_id, uint8_t status )
{

}


void BluetoothAdvImplementation::OnAdvertisingParametersUpdated( uint8_t advertiser_id,
    int8_t tx_power,
    uint8_t status )
{

}


void BluetoothAdvImplementation::OnPeriodicAdvertisingParametersUpdated( uint8_t advertiser_id,
    uint8_t status )
{

}


void BluetoothAdvImplementation::OnPeriodicAdvertisingDataSet( uint8_t advertiser_id,
    uint8_t status )
{

}


void BluetoothAdvImplementation::OnPeriodicAdvertisingEnabled( uint8_t advertiser_id, bool enable,
    uint8_t status )
{

}


void BluetoothAdvImplementation::OnOwnAddressRead
    (
    uint8_t advertiser_id,
    uint8_t address_type,
    RawAddress address
    )
{
    if (address_type == 0)
    {
        memcpy( m_public_address.address, address.address, RawAddress::kLength );

        AdvertiseParameters adv_params;
        // 核心：可连接非定向广播（0x01），支持扫描响应（可选加0x10）
        adv_params.advertising_event_properties = 0x01;
        // 广播间隔：蓝牙规范要求可连接广播间隔≥20ms（32*0.625ms）
        adv_params.min_interval = 32;    // 最小间隔：32*0.625ms=20ms
        adv_params.max_interval = 100;   // 最大间隔：100*0.625ms=62.5ms
        adv_params.channel_map = 0x07;   // 使用37、38、39全信道广播
        adv_params.tx_power = 4;         // 发射功率：4dBm（按需调整）
        adv_params.primary_advertising_phy = 1;  // 主PHY：1M PHY
        adv_params.secondary_advertising_phy = 1; // 副PHY：1M PHY
        adv_params.scan_request_notification_enable = 0; // 禁用扫描请求通知

        // 设置广播参数
        m_advertising_interface->SetParameters( m_advertiser_id, adv_params,
            base::Bind( []( uint8_t status, int8_t tx_power ) {
                if (status == 0) {
                    LogInfo( "可连接广播参数设置成功，tx_power: %d", tx_power );
                }
                else {
                    LogInfo( "广播参数设置失败，status: %d", status );
                }
                } ) );

        std::vector<uint8_t> adv_data;
        // 蓝牙AD数据格式：长度（1字节） + AD类型（1字节） + 数据（N字节）
        std::string device_name = "MyBLEDevice"; // 自定义设备名称
        uint8_t data_len = 1 + device_name.length(); // 1=AD类型长度，总长度=类型+名称

        // 填充AD数据
        adv_data.push_back( data_len );          // 长度：1（类型） + 名称长度
        adv_data.push_back( 0x09 );              // AD类型：0x09=完整本地名称
        adv_data.insert( adv_data.end(), device_name.begin(), device_name.end() ); // 设备名称

        // 设置广播数据（set_scan_rsp=false：广播数据；true：扫描响应数据）
        m_advertising_interface->SetData( m_advertiser_id, false, adv_data,
            base::Bind( &impl_StatusCallback ) );
    }
    else
    {
        LogInfo( "获取到非公开地址，address_type: %d", address_type );
    }
}
