#include "BluetoothHFImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <Zhen/ExecutbleEvent.h>
#include <Zhen/PageManager.h>
#include <Zhen/logging.h>

#include "BT/BluetoothHF.h"

#define PRINTDEBUG LogDebug() << "empty";

using namespace Bluetooth;

static void PostHFClientEvent( std::function<void(BluetoothHF*)> a_fun )
{
    std::shared_ptr<BluetoothHF> hfModule = BluetoothHF::GetMoudle();
    if( hfModule )
    {
        std::function<void()> fun = [ a_fun, hfModule ]() { a_fun( hfModule.get() ); };
        auto executableEvent = std::make_shared<ExecutbleEvent>( fun );
        PageManager::GetInstance().PostEvent( executableEvent );
    }
}

/** Callback for connection state change.
 *  state will have one of the values from BtHfConnectionState
 *  peer/chld_features are valid only for
 * BTHF_CLIENT_CONNECTION_STATE_SLC_CONNECTED state
 */
void impl_bthf_client_connection_state_callback
    (
    const RawAddress* bd_addr,
    bthf_client_connection_state_t state,
    unsigned int peer_feat,
    unsigned int chld_feat
    )
{
    BluetoothAddress address( bd_addr->address );
    ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
    switch( state )
    {
    case BTHF_CLIENT_CONNECTION_STATE_DISCONNECTED:
        status = ConnectionStatus::ServiceDisconnected;
    break;
    case BTHF_CLIENT_CONNECTION_STATE_CONNECTING:
        status = ConnectionStatus::ServiceConnecting;
    break;
    case BTHF_CLIENT_CONNECTION_STATE_CONNECTED:
    break;
    case BTHF_CLIENT_CONNECTION_STATE_SLC_CONNECTED:
        //Service level connection, then we treat it as connected.
        status = ConnectionStatus::ServiceConnected;
    break;
    case BTHF_CLIENT_CONNECTION_STATE_DISCONNECTING:
        status = ConnectionStatus::ServiceDisconnecting;
    break;
    default:
    break;
    }

    auto fun = [address, status]()
        {
            std::shared_ptr<BluetoothHF> hfModule = BluetoothHF::GetMoudle();
            hfModule->HandleConnectionStatusChangedFromStack( address, status );
            BluetoothHFImplementation::GetInstance().queryOperator( address );
        };

    auto executableEvent = std::make_shared<ExecutbleEvent>( fun );
    PageManager::GetInstance().PostEvent( executableEvent );
}

/** Callback for audio connection state change.
 *  state will have one of the values from BtHfAudioState
 */
void impl_bthf_client_audio_state_callback
    (
    const RawAddress* bd_addr,
    bthf_client_audio_state_t state
    )
{
    BluetoothAddress address( bd_addr->address );
    ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
    switch( state )
    {
    case BTHF_CLIENT_AUDIO_STATE_DISCONNECTED:
        status = ConnectionStatus::ServiceDisconnected;
    break;
    case BTHF_CLIENT_AUDIO_STATE_CONNECTING:
        status = ConnectionStatus::ServiceConnecting;
    break;
    case BTHF_CLIENT_AUDIO_STATE_CONNECTED:
        status = ConnectionStatus::ServiceConnected;
    break;
    case BTHF_CLIENT_AUDIO_STATE_CONNECTED_MSBC:
        status = ConnectionStatus::ServiceConnected;
    break;
    default:
    break;
    }

    auto fun = std::bind
        (
        &BluetoothHF::HandleSCOConnectionStatusChangedFromStack,
        std::placeholders::_1,
        address,
        status
        );
    PostHFClientEvent( fun );
}

/** Callback for VR connection state change.
 *  state will have one of the values from BtHfVRState
 */
void impl_bthf_client_vr_cmd_callback
    (
    const RawAddress* bd_addr,
    bthf_client_vr_state_t state
    )
{
    PRINTDEBUG
}

/** Callback for network state change
 */
void impl_bthf_client_network_state_callback
    (
    const RawAddress* bd_addr,
    bthf_client_network_state_t state
    )
{
    BluetoothAddress address( bd_addr->address );
    bool available = false;
    switch( state )
    {
    case BTHF_CLIENT_NETWORK_STATE_NOT_AVAILABLE:
    break;
    case BTHF_CLIENT_NETWORK_STATE_AVAILABLE:
    available = true;
    break;
    default:
    break;
    }
    auto fun = std::bind
    (
        &BluetoothHF::HandleNetworkAvailableFromStack,
        std::placeholders::_1,
        address,
        available
    );
    PostHFClientEvent( fun );
}

/** Callback for network roaming status change
 */
void impl_bthf_client_network_roaming_callback
    (
    const RawAddress* bd_addr,
    bthf_client_service_type_t type
    )
{
    BluetoothAddress address( bd_addr->address );
    switch( type )
    {
    case BTHF_CLIENT_SERVICE_TYPE_HOME:
    break;
    case BTHF_CLIENT_SERVICE_TYPE_ROAMING:
    break;
    default:
    break;
    }
}

/** Callback for signal strength indication
 */
void impl_bthf_client_network_signal_callback
    (
    const RawAddress* bd_addr,
    int signal_strength
    )
{
    BluetoothAddress address( bd_addr->address );
    auto fun = std::bind
        (
        &BluetoothHF::HandleSignalStrengthChangedFromStack,
        std::placeholders::_1,
        address,
        signal_strength
        );
    PostHFClientEvent( fun );
}

/** Callback for battery level indication
 */
void impl_bthf_client_battery_level_callback
    (
    const RawAddress* bd_addr,
    int battery_level
    )
{
    BluetoothAddress address( bd_addr->address );
    auto fun = std::bind
        (
        &BluetoothHF::HandleBatteryLevelChangedFromStack,
        std::placeholders::_1,
        address,
        battery_level
        );
    PostHFClientEvent( fun );
}

/** Callback for current operator name
 */
void impl_bthf_client_current_operator_callback
    (
    const RawAddress* bd_addr,
    const char* name
    )
{
    BluetoothAddress address( bd_addr->address );
    std::string operatorName( name );

    auto fun = [ address, operatorName ]()
        {
            std::shared_ptr<BluetoothHF> hfModule = BluetoothHF::GetMoudle();
            hfModule->HandleOperatorChangedFromStack( address, operatorName );
            BluetoothHFImplementation::GetInstance().querySubscriber( address );
        };

    auto executableEvent = std::make_shared<ExecutbleEvent>( fun );
    PageManager::GetInstance().PostEvent( executableEvent );
}

/** Callback for call indicator
 */
void impl_bthf_client_call_callback
    (
    const RawAddress* bd_addr,
    bthf_client_call_t call
    )
{
    BluetoothAddress address( bd_addr->address );
    bool inProgress = false;
    switch( call )
    {
    case BTHF_CLIENT_CALL_CALLS_IN_PROGRESS:
        LogDebug( "call in progress" );
        inProgress = true;
    break;
    case BTHF_CLIENT_CALL_NO_CALLS_IN_PROGRESS:
        LogDebug( "no call in progress" );
        inProgress = false;
    break;
    default:
    break;
    }

    auto fun = std::bind( &BluetoothHF::HandleCallProgressChangedFromStack,
                          std::placeholders::_1, address, inProgress );
    PostHFClientEvent( fun );
}

/** Callback for callsetup indicator
 */
void impl_bthf_client_callsetup_callback
    (
    const RawAddress* bd_addr,
    bthf_client_callsetup_t callsetup
    )
{
    BluetoothAddress address( bd_addr->address );
    bool hasCall = true;
    switch( callsetup )
    {
    case BTHF_CLIENT_CALLSETUP_NONE:
        hasCall = false;
        LogDebug( "none call setup" );
    break;
    case BTHF_CLIENT_CALLSETUP_INCOMING:
        LogDebug( "call set up incming" );
    break;
    case BTHF_CLIENT_CALLSETUP_OUTGOING:
        LogDebug( "call set up outgoing" );
    break;
    case BTHF_CLIENT_CALLSETUP_ALERTING:
        LogDebug( "call set up alerting" );
    break;
    default:
    break;
    }

    auto fun = std::bind( &BluetoothHF::HandleCallSetupChangedFromStack,
                          std::placeholders::_1, address, hasCall );
    PostHFClientEvent( fun );
}

/** Callback for callheld indicator
 */
void impl_bthf_client_callheld_callback
    (
    const RawAddress* bd_addr,
    bthf_client_callheld_t callheld
    )
{
    BluetoothAddress address( bd_addr->address );
    switch( callheld )
    {
    case BTHF_CLIENT_CALLHELD_HOLD_AND_ACTIVE:
        LogDebug() << "call held hold and active";
    break;
    case BTHF_CLIENT_CALLHELD_HOLD:
        LogDebug() << "call held hold";
    break;
    case BTHF_CLIENT_CALLHELD_NONE:
        LogDebug() << "call held hold none";
    break;
    default:
    break;
    }
    auto fun = std::bind( &BluetoothHF::StartQueryCallList, std::placeholders::_1, address );
    PostHFClientEvent( fun );
}

/** Callback for response and hold
 */
void impl_bthf_client_resp_and_hold_callback
    (
    const RawAddress* bd_addr,
    bthf_client_resp_and_hold_t resp_and_hold
    )
{
    switch( resp_and_hold )
    {
    case BTHF_CLIENT_RESP_AND_HOLD_HELD:
        LogDebug() << "BTHF_CLIENT_RESP_AND_HOLD_HELD";
    break;
    case BTRH_CLIENT_RESP_AND_HOLD_ACCEPT:
        LogDebug() << "BTRH_CLIENT_RESP_AND_HOLD_ACCEPT";
    break;
    case BTRH_CLIENT_RESP_AND_HOLD_REJECT:
        LogDebug() << "BTRH_CLIENT_RESP_AND_HOLD_REJECT";
    break;
    }
}

/** Callback for Calling Line Identification notification
 *  Will be called only when there is an incoming call and number is provided.
 */
void impl_bthf_client_clip_callback
    (
    const RawAddress* bd_addr,
    const char* number
    )
{
    LogDebug() << "receive a incoming call: " << number;
}

/**
 * Callback for Call Waiting notification
 */
void impl_bthf_client_call_waiting_callback
    (
    const RawAddress* bd_addr,
    const char* number
    )
{
    LogDebug() << "receive a incoming call(waiting): " << number;
}

/**
 *  Callback for listing current calls. Can be called multiple time.
 *  If number is unknown NULL is passed.
 */
void impl_bthf_client_current_calls
    (
    const RawAddress* bd_addr,
    int index,
    bthf_client_call_direction_t dir,
    bthf_client_call_state_t state,
    bthf_client_call_mpty_type_t mpty,
    const char* number
    )
{
    LogDebug() << "a session call number: " << number;

    CallSession session;
    session.index = index;
    BluetoothAddress address( bd_addr->address );

    switch( dir )
    {
    case BTHF_CLIENT_CALL_DIRECTION_OUTGOING:
        session.dir = CallDirection::CallOutgoing;
    break;
    case BTHF_CLIENT_CALL_DIRECTION_INCOMING:
        session.dir = CallDirection::CallIncoming;
    break;
    default:
    break;
    }

    switch( state )
    {
    case BTHF_CLIENT_CALL_STATE_ACTIVE:
        session.state = CallState::ACTIVE;
    break;
    case BTHF_CLIENT_CALL_STATE_HELD:
        session.state = CallState::HELD;
    break;
    case BTHF_CLIENT_CALL_STATE_DIALING:
        session.state = CallState::DIALING;
    break;
    case BTHF_CLIENT_CALL_STATE_ALERTING:
        session.state = CallState::ALERTING;
    break;
    case BTHF_CLIENT_CALL_STATE_INCOMING:
        session.state = CallState::INCOMING;
    break;
    case BTHF_CLIENT_CALL_STATE_WAITING:
        session.state = CallState::WAITING;
    break;
    default:
    break;
    }

    switch( mpty )
    {
    case BTHF_CLIENT_CALL_MPTY_TYPE_SINGLE:
        session.mpty = CallType::SINGLE;
    break;
    case BTHF_CLIENT_CALL_MPTY_TYPE_MULTI:
        session.mpty = CallType::MULTI;
    break;
    default:
    break;
    }
    session.number.assign( number );

    auto fun = std::bind
        (
        &BluetoothHF::HandleCallListChangedFromStack,
        std::placeholders::_1,
        address,
        session
        );
    PostHFClientEvent( fun );
}

/** Callback for audio volume change
 */
void impl_bthf_client_volume_change_callback
    (
    const RawAddress* bd_addr,
    bthf_client_volume_type_t type,
    int volume
    )
{
    BluetoothAddress address( bd_addr->address );

    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
    std::function<void( BluetoothHF* )> fun;
    if( type == BTHF_CLIENT_VOLUME_TYPE_SPK )
    {
        fun = std::bind
            (
            &BluetoothHF::HandleSpeakerVolumeChangedFromStack,
            std::placeholders::_1,
            address,
            volume
            );
    }
    else if( type == BTHF_CLIENT_VOLUME_TYPE_MIC )
    {
        fun = std::bind
            (
            &BluetoothHF::HandleMicVolumeChangedFromStack,
            std::placeholders::_1,
            address,
            volume
            );
    }

    if( fun )
    {
        PostHFClientEvent( fun );
    }
}

/** Callback for command complete event
 *  cme is valid only for BTHF_CLIENT_CMD_COMPLETE_ERROR_CME type
 */
void impl_bthf_client_cmd_complete_callback
    (
    const RawAddress* bd_addr,
    bthf_client_cmd_complete_t type,
    int cme
    )
{
    if( BTHF_CLIENT_CMD_COMPLETE_ERROR_CME == type )
    {
        LogDebug() << "Received a command error.";
    }
}

/** Callback for subscriber information
 */
void impl_bthf_client_subscriber_info_callback
    (
    const RawAddress* bd_addr,
    const char* name,
    bthf_client_subscriber_service_type_t type
    )
{
    BluetoothAddress address( bd_addr->address );

    auto fun = std::bind
    (
        &BluetoothHF::HandleLocalNumberChangedFromStack,
        std::placeholders::_1,
        address,
        std::string( name )
    );
    PostHFClientEvent( fun );
}

/** Callback for in-band ring tone settings
 */
void impl_bthf_client_in_band_ring_tone_callback
    (
    const RawAddress* bd_addr,
    bthf_client_in_band_ring_state_t state
    )
{
    BluetoothAddress address( bd_addr->address );
    bool supported = false;
    switch( state )
    {
    case BTHF_CLIENT_IN_BAND_RINGTONE_NOT_PROVIDED:
    supported = false;
    break;
    case BTHF_CLIENT_IN_BAND_RINGTONE_PROVIDED:
    supported = true;
    break;
    default:
    break;
    }
    std::shared_ptr<ExecutbleEvent> event = std::make_shared<ExecutbleEvent>();
    auto fun = std::bind
        (
        &BluetoothHF::HanldeInBandRingtongSupportChangedCallback,
        std::placeholders::_1,
        address,
        supported
        );
    PostHFClientEvent( fun );
}

/**
 * Callback for requested number from AG
 */
void impl_bthf_client_last_voice_tag_number_callback
    (
    const RawAddress* bd_addr,
    const char* number
    )
{
    LogDebug() << "last voice number is " << number;
}

/**
 * Callback for sending ring indication to app
 */
void impl_bthf_client_ring_indication_callback
    (
    const RawAddress* bd_addr
    )
{
    LogDebug() << "ring indication";
}

BluetoothHFInterface& BluetoothHFInterface::GetInterface()
{
    return BluetoothHFImplementation::GetInstance();
}

BluetoothHFImplementation& BluetoothHFImplementation::GetInstance()
{
    static BluetoothHFImplementation instance;
    return instance;
}

BluetoothHFImplementation::BluetoothHFImplementation()
{
    m_callbacks.size = sizeof( bthf_client_callbacks_t );
    m_callbacks.connection_state_cb = &impl_bthf_client_connection_state_callback;
    m_callbacks.audio_state_cb = &impl_bthf_client_audio_state_callback;
    m_callbacks.vr_cmd_cb = &impl_bthf_client_vr_cmd_callback;
    m_callbacks.network_state_cb = &impl_bthf_client_network_state_callback;
    m_callbacks.network_roaming_cb = &impl_bthf_client_network_roaming_callback;
    m_callbacks.network_signal_cb = &impl_bthf_client_network_signal_callback;
    m_callbacks.battery_level_cb = &impl_bthf_client_battery_level_callback;
    m_callbacks.current_operator_cb = &impl_bthf_client_current_operator_callback;
    m_callbacks.call_cb = &impl_bthf_client_call_callback;
    m_callbacks.callsetup_cb = &impl_bthf_client_callsetup_callback;
    m_callbacks.callheld_cb = &impl_bthf_client_callheld_callback;
    m_callbacks.resp_and_hold_cb = &impl_bthf_client_resp_and_hold_callback;
    m_callbacks.clip_cb = &impl_bthf_client_clip_callback;
    m_callbacks.call_waiting_cb = &impl_bthf_client_call_waiting_callback;
    m_callbacks.current_calls_cb = &impl_bthf_client_current_calls;
    m_callbacks.volume_change_cb = &impl_bthf_client_volume_change_callback;
    m_callbacks.cmd_complete_cb = &impl_bthf_client_cmd_complete_callback;
    m_callbacks.subscriber_info_cb = &impl_bthf_client_subscriber_info_callback;
    m_callbacks.in_band_ring_tone_cb = &impl_bthf_client_in_band_ring_tone_callback;
    m_callbacks.last_voice_tag_number_callback = &impl_bthf_client_last_voice_tag_number_callback;
    m_callbacks.ring_indication_cb = &impl_bthf_client_ring_indication_callback;
}

void BluetoothHFImplementation::Init()
{
    if( !m_initialized )
    {
        return;
    }

    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    bthf_client_interface_t const* inter =
        reinterpret_cast<bthf_client_interface_t const*>(
            interfaceBt->get_profile_interface( BT_PROFILE_HANDSFREE_CLIENT_ID ) );
    m_interface = const_cast<bthf_client_interface_t*>( inter );
    m_interface->init( &m_callbacks );
    m_initialized = true;
}

bool BluetoothHFImplementation::Connect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_interface->connect( &address );
    return true;
}

bool BluetoothHFImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_interface->disconnect( &address );
    return true;
}

bool BluetoothHFImplementation::setActiveDevice
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool BluetoothHFImplementation::setSilenceDevice
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool BluetoothHFImplementation::dialNumber
    (
    BluetoothAddress a_address,
    std::string a_number
    )
{
    bool ret = false;
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bt_status_t status = m_interface->dial( &address, a_number.c_str() );
    ret = BT_STATUS_SUCCESS == status;
    return ret;
}

void BluetoothHFImplementation::answerIncomingCall
    (
    BluetoothAddress& a_address,
    bool a_answered
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bthf_client_call_action_t action = ( a_answered ? BTHF_CLIENT_CALL_ACTION_ATA : BTHF_CLIENT_CALL_ACTION_CHUP );
    bt_status_t status = m_interface->handle_call_action( &address, action, 0 );
}

void BluetoothHFImplementation::swapCalls
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bt_status_t status = m_interface->handle_call_action( &address, BTHF_CLIENT_CALL_ACTION_CHLD_2, 0 );
}

void BluetoothHFImplementation::joinCalls
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bt_status_t status = m_interface->handle_call_action( &address, BTHF_CLIENT_CALL_ACTION_CHLD_3, 0 );
}

void BluetoothHFImplementation::splitCall
    (
    BluetoothAddress a_address,
    int a_index
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bt_status_t status = m_interface->handle_call_action( &address, BTHF_CLIENT_CALL_ACTION_CHLD_2x, a_index );
}

bool BluetoothHFImplementation::QueryCallList
    (
    BluetoothAddress a_address
    )
{
    bool ret = true;
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_interface->query_current_calls( &address );
    return ret;
}

void BluetoothHFImplementation::queryOperator( BluetoothAddress a_address )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_interface->query_current_operator_name( &address );
}

void BluetoothHFImplementation::querySubscriber( BluetoothAddress a_address )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_interface->retrieve_subscriber_info( &address );
}

