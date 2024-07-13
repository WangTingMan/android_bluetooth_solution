#include "BluetoothA2DPSinkImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <BT/BluetoothAddress.h>
#include <BT/a2dp/BluetoothA2DPSource.h>
#include "BT/BluetoothA2DPSink.h"

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

/** Callback for connection state change.
* state will have one of the values from btav_connection_state_t
*/
void impl_btav_sink_connection_state_callback
    (
    const RawAddress& bd_addr,
    btav_connection_state_t state,
    const btav_error_t& error
    )
{
    BluetoothAddress address(bd_addr.address);
    ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
    switch (state)
    {
    case BTAV_CONNECTION_STATE_DISCONNECTED:
        status = ConnectionStatus::ServiceDisconnected;
        break;
    case BTAV_CONNECTION_STATE_CONNECTING:
        status = ConnectionStatus::ServiceConnecting;
        break;
    case BTAV_CONNECTION_STATE_CONNECTED:
        status = ConnectionStatus::ServiceConnected;
        break;
    case BTAV_CONNECTION_STATE_DISCONNECTING:
        status = ConnectionStatus::ServiceDisconnecting;
        break;
    default:
        break;
    }

    auto fun = std::bind
        (
        &Bluetooth::BluetoothA2DPSink::HandleConnectionStatusChangedCallback,
        Bluetooth::BluetoothA2DPSink::GetMoudle(),
        address,
        status
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

/** Callback for audiopath state change.
 *  state will have one of the values from btav_audio_state_t
 */
void impl_btav_sink_audio_state_callback
    (
    const RawAddress & bd_addr,
    btav_audio_state_t a_state
    )
{
    BluetoothAddress address(bd_addr.address);
    AudioPathState state = AudioPathState::STOPPED;
    switch (a_state)
    {
    case BTAV_AUDIO_STATE_REMOTE_SUSPEND:
        state = AudioPathState::SUSPEND;
        break;
    case BTAV_AUDIO_STATE_STARTED:
        state = AudioPathState::STARTED;
        break;
    case BTAV_AUDIO_STATE_STOPPED:
        state = AudioPathState::STOPPED;
        break;
    default:
        break;
    }
    auto fun = std::bind
        (
        &Bluetooth::BluetoothA2DPSink::HandleAudioStateChangedCallback,
        Bluetooth::BluetoothA2DPSink::GetMoudle(),
        address,
        state
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

/** Callback for audio configuration change.
 *  Used only for the A2DP Sink interface.
 *  sample_rate: sample rate in Hz
 *  channel_count: number of channels (1 for mono, 2 for stereo)
 */
void impl_tav_audio_sink_config_callback
    (
    const RawAddress & bd_addr,
    uint32_t sample_rate,
    uint8_t channel_count
    )
{
    BluetoothAddress address(bd_addr.address);
    auto fun = std::bind
        (
        &Bluetooth::BluetoothA2DPSink::HandleAudioConfigChangedCallback,
        Bluetooth::BluetoothA2DPSink::GetMoudle(),
        address,
        sample_rate,
        channel_count
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

BluetoothA2DPSinkInterface& BluetoothA2DPSinkInterface::GetInterface()
{
    return BluetoothA2DPSinkImplementation::GetInstance();
}

BluetoothA2DPSinkImplementation& BluetoothA2DPSinkImplementation::GetInstance()
{
    static BluetoothA2DPSinkImplementation instance;
    return instance;
}

void BluetoothA2DPSinkImplementation::Init()
{
    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();

    btav_sink_interface_t const* inter =
        reinterpret_cast<btav_sink_interface_t const*>(interfaceBt->get_profile_interface(BT_PROFILE_ADVANCED_AUDIO_SINK_ID));
    m_a2dpSinkInterface = const_cast<btav_sink_interface_t*>(inter);

    memset(&m_avCallback, 0x00, sizeof m_avCallback);
    m_avCallback.size = sizeof btav_sink_callbacks_t;
    m_avCallback.audio_config_cb = impl_tav_audio_sink_config_callback;
    m_avCallback.audio_state_cb = impl_btav_sink_audio_state_callback;
    m_avCallback.connection_state_cb = impl_btav_sink_connection_state_callback;

    m_a2dpSinkInterface->init(&m_avCallback, 1);
}

bool BluetoothA2DPSinkImplementation::Connect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_a2dpSinkInterface->connect(address);
    return true;
}

bool BluetoothA2DPSinkImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_a2dpSinkInterface->disconnect(address);
    return true;
}

void BluetoothA2DPSinkImplementation::SetAudioFocus
    (
    bool a_grant
    )
{
    int granted = a_grant ? 1 : 0;
    m_a2dpSinkInterface->set_audio_focus_state(granted);
}

