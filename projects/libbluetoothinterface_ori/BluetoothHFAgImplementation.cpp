#include "BluetoothHFAgImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <BT/BluetoothHFAG.h>

#include <Zhen/ExecutbleEvent.h>
#include <Zhen/logging.h>
#include <Zhen/PageManager.h>

namespace bluetooth {
namespace headset {

/**
 * Headset related callbacks invoked from from the Bluetooth native stack
 * All callbacks are invoked on the JNI thread
 */
class HeadsetCallbacks : public Callbacks
{
 public:

  /**
   * Callback for connection state change.
   *
   * @param state one of the values from bthf_connection_state_t
   * @param bd_addr remote device address
   */
     virtual void ConnectionStateCallback( bthf_connection_state_t state,
                                           RawAddress* bd_addr )
     {
         BluetoothAddress address(bd_addr->address);
         ConnectionStatus status = ConnectionStatus::ServiceDisconnected;
         switch (state)
         {
         case BTHF_CONNECTION_STATE_DISCONNECTING:
             status = ConnectionStatus::ServiceDisconnecting;
             break;
         case BTHF_CONNECTION_STATE_CONNECTING:
             status = ConnectionStatus::ServiceConnecting;
             break;
         case BTHF_CONNECTION_STATE_CONNECTED:
             break;
         case BTHF_CONNECTION_STATE_SLC_CONNECTED:
             //Service level connection, then we treat it as connected.
             status = ConnectionStatus::ServiceConnected;
             break;
         case BTHF_CONNECTION_STATE_DISCONNECTED:
             status = ConnectionStatus::ServiceDisconnected;
             break;
         default:
             break;
         }

         auto fun = [address, status]()
             {
                 std::shared_ptr<Bluetooth::BluetoothHFAG> hfModule = Bluetooth::BluetoothHFAG::GetMoudle();
                 hfModule->HandleConnectionStatusChangedFromStack(address, status);
             };

         auto executableEvent = std::make_shared<ExecutbleEvent>(fun);
         PageManager::GetInstance().PostEvent(executableEvent);
     }

  /**
   * Callback for audio connection state change.
   *
   * @param state one of the values from bthf_audio_state_t
   * @param bd_addr remote device address
   */
  virtual void AudioStateCallback(bthf_audio_state_t state,
                                   RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for VR connection state change.
   *
   * @param state one of the values from bthf_vr_state_t
   * @param bd_addr
   */
  virtual void VoiceRecognitionCallback(bthf_vr_state_t state,
                                         RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for answer incoming call (ATA)
   *
   * @param bd_addr remote device address
   */
  virtual void AnswerCallCallback( RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for disconnect call (AT+CHUP)
   *
   * @param bd_addr remote device address
   */
  virtual void HangupCallCallback( RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for disconnect call (AT+CHUP)
   *
   * @param type denote Speaker/Mic gain bthf_volume_type_t
   * @param volume volume value 0 to 15, p69, HFP 1.7.1 spec
   * @param bd_addr remote device address
   */
  virtual void VolumeControlCallback(bthf_volume_type_t type, int volume,
                                      RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for dialing an outgoing call
   *
   * @param number intended phone number, if number is NULL, redial
   * @param bd_addr remote device address
   */
  virtual void DialCallCallback( char* number, RawAddress* bd_addr )
  {
      BluetoothAddress address( bd_addr->address );
      auto fun = std::bind
        (
        &Bluetooth::BluetoothHFAG::HandleDialCallback,
        Bluetooth::BluetoothHFAG::GetMoudle(),
        address,
        std::string(number)
        );
      PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>( fun ) );
  }

  /**
   * Callback for sending DTMF tones
   *
   * @param tone contains the dtmf character to be sent
   * @param bd_addr remote device address
   */
  virtual void DtmfCmdCallback( char tone, RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for enabling/disabling noise reduction/echo cancellation
   *
   * @param nrec 1 to enable, 0 to disable
   * @param bd_addr remote device address
   */
  virtual void NoiseReductionCallback(bthf_nrec_t nrec,
                                       RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for AT+BCS and event from BAC
   *
   * @param wbs WBS enable, WBS disable
   * @param bd_addr remote device address
   */
  virtual void WbsCallback( bthf_wbs_config_t wbs, RawAddress* bd_addr )
  {
      LogDebug();
  }

  void SwbCallback( bthf_swb_codec_t codec, bthf_swb_config_t swb,
      RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for call hold handling (AT+CHLD)
   *
   * @param chld the call hold command (0, 1, 2, 3)
   * @param bd_addr remote device address
   */
  virtual void AtChldCallback( bthf_chld_type_t chld, RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for CNUM (subscriber number)
   *
   * @param bd_addr remote device address
   */
  virtual void AtCnumCallback( RawAddress* bd_addr )
  {
      BluetoothAddress address( bd_addr->address );
      auto fun = std::bind
        (
        &Bluetooth::BluetoothHFAG::HandleCnumCallback,
        Bluetooth::BluetoothHFAG::GetMoudle(),
        address
        );
      PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>( fun ) );
  }

  /**
   * Callback for indicators (CIND)
   *
   * @param bd_addr remote device address
   */
  virtual void AtCindCallback( RawAddress* bd_addr )
  {
      BluetoothAddress address( bd_addr->address );
      auto fun = std::bind
            (
            &Bluetooth::BluetoothHFAG::HandleCindCallback,
            Bluetooth::BluetoothHFAG::GetMoudle(),
            address
            );
      PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>( fun ) );
  }

  /**
   * Callback for operator selection (COPS)
   *
   * @param bd_addr remote device address
   */
  virtual void AtCopsCallback( RawAddress* bd_addr )
  {
      BluetoothAddress address( bd_addr->address );
      auto fun = std::bind
            (
            &Bluetooth::BluetoothHFAG::HandleCopsCallback,
            Bluetooth::BluetoothHFAG::GetMoudle(),
            address
            );
      PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>( fun ) );
  }

  /**
   * Callback for call list (AT+CLCC)
   *
   * @param bd_addr remote device address
   */
  virtual void AtClccCallback( RawAddress* bd_addr )
  {
      BluetoothAddress address( bd_addr->address );
      auto fun = std::bind
        (
        &Bluetooth::BluetoothHFAG::HandleClccCallback,
        Bluetooth::BluetoothHFAG::GetMoudle(),
        address
        );
      PageManager::GetInstance().PostEvent( std::make_shared<ExecutbleEvent>( fun ) );
  }

  /**
   * Callback for unknown AT command recd from HF
   *
   * @param at_string he unparsed AT string
   * @param bd_addr remote device address
   */
  virtual void UnknownAtCallback( char* at_string, RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for keypressed (HSP) event.
   *
   * @param bd_addr remote device address
   */
  virtual void KeyPressedCallback( RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for BIND. Pass the remote HF Indicators supported.
   *
   * @param at_string unparsed AT command string
   * @param bd_addr remote device address
   */
  virtual void AtBindCallback( char* at_string, RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for BIEV. Pass the change in the Remote HF indicator values
   *
   * @param ind_id HF indicator id
   * @param ind_value HF indicator value
   * @param bd_addr remote device address
   */
  virtual void AtBievCallback(bthf_hf_ind_type_t ind_id, int ind_value,
                               RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for BIA. Pass the change in AG indicator activation.
   * NOTE: Call, Call Setup and Call Held indicators are mandatory and cannot
   *       be disabled. Thus, they are not included here.
   *
   * @param service whether HF should receive network service state update
   * @param roam whether HF should receive roaming state update
   * @param signal whether HF should receive signal strength update
   * @param battery whether HF should receive AG battery level update
   * @param bd_addr remote HF device address
   */
  virtual void AtBiaCallback(bool service, bool roam, bool signal, bool battery,
                              RawAddress* bd_addr )
  {
      LogDebug();
  }

  /**
   * Callback for DebugDump.
   *
   * @param active whether the SCO is active
   * @param codec_id the codec ID per spec: mSBC=2, LC3=3.
   * @param total_num_decoded_frames the number of frames decoded.
   * @param pkt_loss_ratio the ratio of lost frames
   * @param begin_ts time of the packet status window starts in microseconds.
   * @param end_ts time of the packet status window ends in microseconds.
   * @param pkt_status_in_hex recorded packets' status in hex string.
   * @param pkt_status_in_binary recorde packets' status in binary string.
   */
  virtual void DebugDumpCallback(bool active, uint16_t codec_id,
                                 int total_num_decoded_frames,
                                 double pkt_loss_ratio, uint64_t begin_ts,
                                 uint64_t end_ts, const char* pkt_status_in_hex,
                                  const char* pkt_status_in_binary )
  {
      LogDebug();
  }
};

}  // namespace headset
}  // namespace bluetooth

BluetoothHFAGInterface& BluetoothHFAGInterface::GetInterface()
{
    return BluetoothHFAgImplementation::GetInstance();
}

BluetoothHFAgImplementation& BluetoothHFAgImplementation::GetInstance()
{
    static BluetoothHFAgImplementation instance;
    return instance;
}

BluetoothHFAgImplementation::BluetoothHFAgImplementation()
{
    m_headset_callback = std::make_shared<bluetooth::headset::HeadsetCallbacks>();
}

void BluetoothHFAgImplementation::Init()
{
    auto interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    bluetooth::headset::Interface const* inter =
        reinterpret_cast<bluetooth::headset::Interface const*>(
            interfaceBt->get_profile_interface( BT_PROFILE_HANDSFREE_ID ) );
    m_hf_interface = const_cast<bluetooth::headset::Interface*>( inter );

    m_hf_interface->Init( m_headset_callback.get(), 5, true );
}

bool BluetoothHFAgImplementation::Connect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    bt_status_t status = m_hf_interface->Connect( &address );
    return true;
}

bool BluetoothHFAgImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool BluetoothHFAgImplementation::connectAudio(BluetoothAddress a_address)
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    bt_status_t status = m_hf_interface->ConnectAudio(&address, false);
    return true;
}

bool BluetoothHFAgImplementation::DialNewNumber( std::string a_number )
{
    return true;
}

void BluetoothHFAgImplementation::ResponseCind
    (
    BluetoothAddress a_address,
    bool a_cell_network_available,
    int a_active_call_count,
    int a_held_call_count,
    CallState a_call_state,
    int a_signal_level,
    bool a_is_roaming,
    int a_bettery_level
    )
{
    bluetooth::headset::bthf_call_state_t call_state = bluetooth::headset::BTHF_CALL_STATE_IDLE;
    switch( a_call_state )
    {
    case CallState::ACTIVE:
        call_state = bluetooth::headset::BTHF_CALL_STATE_ACTIVE;
        break;
    case CallState::HELD:
        call_state = bluetooth::headset::BTHF_CALL_STATE_HELD;
        break;
    case CallState::DIALING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_DIALING;
        break;
    case CallState::ALERTING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_ALERTING;
        break;
    case CallState::INCOMING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_INCOMING;
        break;
    case CallState::WAITING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_WAITING;
        break;
    case CallState::IDLE:
        call_state = bluetooth::headset::BTHF_CALL_STATE_IDLE;
        break;
    case CallState::DISCONNECTED:
        call_state = bluetooth::headset::BTHF_CALL_STATE_DISCONNECTED;
        break;
    default:
        break;
    }
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );
    m_hf_interface->CindResponse(
        ( a_cell_network_available ? 1 : 0 ),
        a_active_call_count,
        a_held_call_count,
        call_state,
        a_signal_level,
        (a_is_roaming ? 1 : 0),
        a_bettery_level,
        &address
        );
}

void BluetoothHFAgImplementation::ResponseCops
    (
    BluetoothAddress a_address,
    std::string a_cops
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );

    m_hf_interface->CopsResponse( a_cops.c_str(), &address );
}

void BluetoothHFAgImplementation::ResponseCnum
    (
    BluetoothAddress a_address,
    std::string a_cnum
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );

    if( !a_cnum.empty() )
    {
        std::string num_at_rsp = "+CNUM: ,\"";
        num_at_rsp.append( a_cnum );
        num_at_rsp.append( "\"," );
        if( a_cnum.size() > 0 && a_cnum.at( 0 ) == '+' )
        {
            num_at_rsp.push_back( 0x91 );
        }
        else
        {
            num_at_rsp.push_back( 0x81 );
        }
        num_at_rsp.append( ",,4" );
        m_hf_interface->FormattedAtResponse( num_at_rsp.c_str(), &address );
    }

    m_hf_interface->AtResponse( bluetooth::headset::BTHF_AT_RESPONSE_OK, 0, &address );
}

void BluetoothHFAgImplementation::ResponseClcc
    (
    BluetoothAddress a_address,
    int a_index,
    CallDirection a_direction,
    CallState a_call_state,
    CallMode a_call_mode,
    CallType a_call_type,
    std::string a_number,
    CallAddrType a_call_addr_type
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );

    bluetooth::headset::bthf_call_direction_t dir = bluetooth::headset::BTHF_CALL_DIRECTION_OUTGOING;
    switch( a_direction )
    {
    case CallDirection::CallOutgoing:
        dir = bluetooth::headset::BTHF_CALL_DIRECTION_OUTGOING;
        break;
    case CallDirection::CallIncoming:
        dir = bluetooth::headset::BTHF_CALL_DIRECTION_INCOMING;
        break;
    default:
        break;
    }

    bluetooth::headset::bthf_call_state_t call_state = bluetooth::headset::BTHF_CALL_STATE_ACTIVE;
    switch( a_call_state )
    {
    case CallState::ACTIVE:
        call_state = bluetooth::headset::BTHF_CALL_STATE_ACTIVE;
        break;
    case CallState::HELD:
        call_state = bluetooth::headset::BTHF_CALL_STATE_HELD;
        break;
    case CallState::DIALING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_DIALING;
        break;
    case CallState::ALERTING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_ALERTING;
        break;
    case CallState::INCOMING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_INCOMING;
        break;
    case CallState::WAITING:
        call_state = bluetooth::headset::BTHF_CALL_STATE_WAITING;
        break;
    case CallState::IDLE:
        call_state = bluetooth::headset::BTHF_CALL_STATE_IDLE;
        break;
    case CallState::DISCONNECTED:
        call_state = bluetooth::headset::BTHF_CALL_STATE_DISCONNECTED;
        break;
    default:
    break;
    }

    bluetooth::headset::bthf_call_mode_t call_mode = bluetooth::headset::BTHF_CALL_TYPE_VOICE;
    switch( a_call_mode )
    {
    case CallMode::Voice:
        call_mode = bluetooth::headset::BTHF_CALL_TYPE_VOICE;
        break;
    case CallMode::Data:
        call_mode = bluetooth::headset::BTHF_CALL_TYPE_DATA;
        break;
    case CallMode::Fax:
        call_mode = bluetooth::headset::BTHF_CALL_TYPE_FAX;
        break;
    default:
        break;
    }

    bluetooth::headset::bthf_call_mpty_type_t call_type = bluetooth::headset::BTHF_CALL_MPTY_TYPE_SINGLE;
    switch( a_call_type )
    {
    case CallType::SINGLE:
        call_type = bluetooth::headset::BTHF_CALL_MPTY_TYPE_SINGLE;
        break;
    case CallType::MULTI:
        call_type = bluetooth::headset::BTHF_CALL_MPTY_TYPE_MULTI;
        break;
    default:
        break;
    }

    bluetooth::headset::bthf_call_addrtype_t addr_type = bluetooth::headset::BTHF_CALL_ADDRTYPE_UNKNOWN;
    switch( a_call_addr_type )
    {
    case CallAddrType::UNKNOWN:
        addr_type = bluetooth::headset::BTHF_CALL_ADDRTYPE_UNKNOWN;
        break;
    case CallAddrType::INTERNATIONAL:
        addr_type = bluetooth::headset::BTHF_CALL_ADDRTYPE_INTERNATIONAL;
        break;
    default:
        break;
    }

    m_hf_interface->ClccResponse( a_index, dir, call_state, call_mode, call_type,
                                  a_number.c_str(), addr_type, &address );
}

void BluetoothHFAgImplementation::AtResponse
    (
    bool a_result,
    int a_code,
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy( address.address, a_address.address, BluetoothAddress::kLength );

    m_hf_interface->AtResponse(
        (
        a_result ? bluetooth::headset::BTHF_AT_RESPONSE_OK : bluetooth::headset::BTHF_AT_RESPONSE_ERROR ),
        a_code,
        &address
        );
}

void BluetoothHFAgImplementation::PhoneStateChange
    (
    BluetoothAddress a_address,
    int num_active,
    int num_held,
    CallState a_call_setup_state,
    std::string number,
    CallAddrType a_type,
    std::string name
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    bluetooth::headset::bthf_call_state_t call_setup_state = bluetooth::headset::BTHF_CALL_STATE_IDLE;
    switch (a_call_setup_state)
    {
    case CallState::ACTIVE:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_ACTIVE;
        break;
    case CallState::HELD:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_HELD;
        break;
    case CallState::DIALING:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_DIALING;
        break;
    case CallState::ALERTING:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_ALERTING;
        break;
    case CallState::INCOMING:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_INCOMING;
        break;
    case CallState::WAITING:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_WAITING;
        break;
    case CallState::IDLE:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_IDLE;
        break;
    case CallState::DISCONNECTED:
        call_setup_state = bluetooth::headset::BTHF_CALL_STATE_DISCONNECTED;
        break;
    default:
        break;
    }

    bluetooth::headset::bthf_call_addrtype_t type = bluetooth::headset::BTHF_CALL_ADDRTYPE_UNKNOWN;
    switch (a_type)
    {
    case CallAddrType::UNKNOWN:
        type = bluetooth::headset::BTHF_CALL_ADDRTYPE_UNKNOWN;
        break;
    case CallAddrType::INTERNATIONAL:
        type = bluetooth::headset::BTHF_CALL_ADDRTYPE_INTERNATIONAL;
        break;
    default:
        break;
    }

    m_hf_interface->PhoneStateChange(num_active, num_held, call_setup_state,
        number.c_str(), type, "name", &address);
}
