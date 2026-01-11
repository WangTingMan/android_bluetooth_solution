#include "BluetoothRfcommImplementation.h"
#include "BluetoothBaseImplementation.h"
#include "BluetoothGattImplementation.h"
#include <BT/rfcomm/BluetoothRfcomm.h>

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>
#include <Zhen/logging.h>

BluetoothRfcommImplementation& BluetoothRfcommImplementation::GetInterface()
{
    static BluetoothRfcommImplementation instance;
    return instance;
}

BluetoothRfcommInterface& BluetoothRfcommInterface::GetInterface()
{
    return BluetoothRfcommImplementation::GetInterface();
}

void BluetoothRfcommImplementation::Init()
{
    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    m_sock_interface = (btsock_interface_t*)interfaceBt->get_profile_interface
        ( BT_PROFILE_SOCKETS_ID );

    std::function<void()> fun;
    fun = std::bind(&BluetoothGattImplementation::init, std::ref(BluetoothGattImplementation::GetInstance()));
    auto executableEvent = std::make_shared<ExecutbleEvent>( fun );
    PageManager::GetInstance().PostEvent( executableEvent );

}

bool BluetoothRfcommImplementation::listen
    (
    std::string const& a_service_name,
    std::vector<uint8_t> a_service_uuid,
    int a_user_id,
    int a_channel
    )
{
    if( nullptr == m_sock_interface )
    {
        return false;
    }

    if( a_service_uuid.size() != bluetooth::Uuid::kNumBytes128 )
    {
        return false;
    }

    bluetooth::Uuid uuid;
    for( int i = 0; i < bluetooth::Uuid::kNumBytes128; ++i )
    {
        uuid.uu[i] = a_service_uuid[i];
    }

    int fake_fd = 0;
    m_sock_interface->listen( BTSOCK_RFCOMM, a_service_name.c_str(), &uuid, a_channel, &fake_fd, 0, a_user_id );
}

void BluetoothRfcommImplementation::send
    (
    int a_connect_id,
    std::shared_ptr<std::vector<uint8_t>> a_data
    )
{
}

void BluetoothRfcommImplementation::disconnect( int a_connect_id )
{
}

bool BluetoothRfcommImplementation::Connect
    (
    BluetoothAddress a_address,
    std::string a_service_name,
    int a_channel
    )
{
    return true;
}

bool BluetoothRfcommImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    return true;
}

void BluetoothRfcommImplementation::HandleConnectionSiangl
    (
    int a_user_id,
    sock_connect_signal_t a_signal
    )
{
    BluetoothAddress address;
    int local_channel = a_signal.channel;
    memcpy( address.address, a_signal.bd_addr.address, BluetoothAddress::kLength );
    LogError() << a_user_id << " connect! connect channel: " << a_signal.channel;
    return;
}

void BluetoothRfcommImplementation::HandleDisconnectionSiangl
    (
    int a_connect_id
    )
{
    LogError() << a_connect_id << " Disconnect!";
}

void BluetoothRfcommImplementation::HandleReceivedDataFromRemote
    (
    int a_connect_id,
    std::shared_ptr<std::vector<uint8_t>> a_data
    )
{
    std::shared_ptr<std::vector<uint8_t>> notify_data;
    notify_data = std::make_shared<std::vector<uint8_t>>();
    std::string notify{ "Received data:" };
    notify_data->insert( notify_data->begin(), notify.begin(), notify.end() );
    send( a_connect_id, notify_data );
    send( a_connect_id, a_data );
}

