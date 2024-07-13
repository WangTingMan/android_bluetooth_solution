#include "binder_server.h"
#include <binder/ProcessState.h>
#include <binderwrapper/service.h>
#include <BT\a2dp\BluetoothA2DPSource.h>

#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

#pragma comment(lib,"libbinder.lib")
#pragma comment(lib,"libutils.lib")
#pragma comment(lib,"libcutils.lib")
#pragma comment(lib,"libbinderwrapper.lib")

class BluetoothService : public BnBluetoothService
{

public:

    BluetoothService();

    void        RegisterObserver( android::sp<IObserver> a_observer );

private:

    std::shared_mutex m_mutex;
    std::vector<android::sp<IObserver>> m_observers;
};

BluetoothService::BluetoothService()
{
    std::function<void( BluetoothAddress, ConnectionStatus )> fun;
    fun = [this]( BluetoothAddress a_addr, ConnectionStatus status)
        {
            std::vector<uint8_t> addr( a_addr.address, a_addr.address + BluetoothAddress::kLength );
            std::shared_lock<std::shared_mutex> lkcer( m_mutex );
            for( auto& ele : m_observers )
            {
                ele->A2dpConnectionStatusChanged( addr, status == ConnectionStatus::ServiceConnected );
            }
        };

    std::function<void( BluetoothAddress )> active_fun;
    active_fun = [ this ]( BluetoothAddress a_addr )
        {
            std::vector<uint8_t> addr( a_addr.address, a_addr.address + BluetoothAddress::kLength );
            std::shared_lock<std::shared_mutex> lkcer( m_mutex );
            for( auto& ele : m_observers )
            {
                ele->A2dpActiveDeviceChanged( addr );
            }
        };

    std::shared_ptr<Bluetooth::BluetoothA2DPSource> a2dp_src;
    a2dp_src = Bluetooth::BluetoothA2DPSource::GetMoudle();
    if( a2dp_src )
    {
        a2dp_src->ConnectToConnectionStatusChanged( fun );
        a2dp_src->ConnectToActiveDeviceChanged( active_fun );
    }
}

void BluetoothService::RegisterObserver( android::sp<IObserver> a_observer )
{
    std::lock_guard<std::shared_mutex> lkcer( m_mutex );
    m_observers.push_back( a_observer );
}

std::shared_mutex s_mutex;
android::sp<BluetoothService> s_service;
std::thread s_binder_thread;

void binder_server_init()
{
    android::sp<BluetoothService> service( new BluetoothService );
    std::unique_lock<std::shared_mutex> lcker( s_mutex );
    if( s_service )
    {
        return;
    }
    s_service = service;
    lcker.unlock();

    s_binder_thread = std::thread([ service ]()
        {
            auto desc = service->getInterfaceDescriptor();
            android::defaultServiceManager()->addService( desc, service );
            android::ProcessState::self()->startThreadPool();
            android::IPCThreadState::self()->joinThreadPool();
        });
}

