#include "BluetoothAvrcpInterfaceImpl.h"
#include "BluetoothBaseImplementation.h"

#include "BT/BluetoothAddress.h"
#include "BT/avrcp/BluetoothAvrcpController.h"
#include "BT/Adaptor.h"

#include "Zhen/PageManager.h"
#include <Zhen/ExecutbleEvent.h>

#include <base\strings\sys_string_conversions.h>

#define CALLBACK_STYLE extern "C"
#define RAW_ADDRESS_TYPE RawAddress*
#define GET_ADDRESS_POINTER(addr) (addr)

#ifdef RAW_ADDRESS_TYPE
#undef RAW_ADDRESS_TYPE
#endif
#define RAW_ADDRESS_TYPE const RawAddress&
#undef GET_ADDRESS_POINTER
#define GET_ADDRESS_POINTER(addr) (&(addr))

#ifdef LOG_TO_FILE
#define LOGLLINE( log ) Adaptor::GetInstance().LogToFile( log, __LINE__, __FILE__, 3 );
#define LOGCALLBACK LOGLLINE( __FUNCTION__ )
#else
#define LOGLLINE( log ) std::cout << log << "; line: " << __LINE__ << std::endl;
#define LOGCALLBACK LOGLLINE( __FUNCTION__ )
#endif

using namespace Bluetooth;

CALLBACK_STYLE void impl_sinkbtrc_passthrough_rsp_callback(RAW_ADDRESS_TYPE bd_addr, int id,
    int key_state)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_groupnavigation_rsp_callback(int id, int key_state)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_connection_state_callback(bool rc_connect, bool bt_connect,
    RAW_ADDRESS_TYPE bd_addr)
{
    BluetoothAddress address(GET_ADDRESS_POINTER(bd_addr)->address);
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandleAvrcpConnectionStatusChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        address,
        (rc_connect ? ConnectionStatus::ServiceConnected : ConnectionStatus::ServiceDisconnected),
        (bt_connect ? ConnectionStatus::ServiceConnected : ConnectionStatus::ServiceDisconnected)
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}


CALLBACK_STYLE void impl_sinkbtrc_ctrl_getrcfeatures_callback(RAW_ADDRESS_TYPE bd_addr, int features)
{
    std::vector< AvrcpRemoteFeature > avfeatures;
    do
    {
        if (BTRC_FEAT_NONE == features)
        {
            avfeatures.push_back(AvrcpRemoteFeature::NONE);
            break;
        }

        if ((BTRC_FEAT_METADATA & features) > 0)
        {
            avfeatures.push_back(AvrcpRemoteFeature::METADATA);
        }

        if ((BTRC_FEAT_ABSOLUTE_VOLUME & features) > 0)
        {
            avfeatures.push_back(AvrcpRemoteFeature::ABSOLUTE_VOLUME);
        }

        if ((BTRC_FEAT_BROWSE & features) > 0)
        {
            avfeatures.push_back(AvrcpRemoteFeature::BROWSE);
        }
    } while (false);
    BluetoothAddress address(GET_ADDRESS_POINTER(bd_addr)->address);
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandleAvrcpFeaturesChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        address, avfeatures
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_setplayerapplicationsetting_rsp_callback(
    RAW_ADDRESS_TYPE bd_addr, uint8_t accepted)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_playerapplicationsetting_callback(
    RAW_ADDRESS_TYPE bd_addr, uint8_t num_attr,
    btrc_player_app_attr_t* app_attrs, uint8_t num_ext_attr,
    btrc_player_app_ext_attr_t* ext_attrs)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_playerapplicationsetting_changed_callback
    (
    RAW_ADDRESS_TYPE bd_addr,
    const btrc_player_settings_t& p_vals
    )
{
    const btrc_player_settings_t* vals_ptr = nullptr;
    vals_ptr = &p_vals;
    uint8_t value;
    for (int i = 0; i < vals_ptr->num_attr; ++i)
    {
        value = vals_ptr->attr_values[i];
        value = vals_ptr->attr_ids[i];
    }

    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_setabsvol_cmd_callback(RAW_ADDRESS_TYPE bd_addr,
    uint8_t abs_vol,
    uint8_t label)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_registernotification_abs_vol_callback(
    RAW_ADDRESS_TYPE bd_addr, uint8_t label)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_track_changed_callback(
    RAW_ADDRESS_TYPE bd_addr, uint8_t num_attr,
    btrc_element_attr_val_t* p_attrs)
{
    BluetoothAddress address(GET_ADDRESS_POINTER(bd_addr)->address);
    std::wstring names;
    std::string MultiBytes;
    AvrcpMediaAttributeType attributeType = AvrcpMediaAttributeType::TRACK_NUM;
    std::vector<std::pair< AvrcpMediaAttributeType, std::string> > attris;
    for (uint8_t i = 0; i < num_attr; ++i)
    {
        switch (p_attrs[i].attr_id)
        {
        case AVRC_MEDIA_ATTR_ID_TITLE:
            attributeType = AvrcpMediaAttributeType::TITLE;
            break;
        case AVRC_MEDIA_ATTR_ID_ARTIST:
            attributeType = AvrcpMediaAttributeType::ARTIST;
            break;
        case AVRC_MEDIA_ATTR_ID_ALBUM:
            attributeType = AvrcpMediaAttributeType::ALBUM;
            break;
        case AVRC_MEDIA_ATTR_ID_TRACK_NUM:
            attributeType = AvrcpMediaAttributeType::TRACK_NUM;
            break;
        case AVRC_MEDIA_ATTR_ID_NUM_TRACKS:
            attributeType = AvrcpMediaAttributeType::NUM_TRACKS;
            break;
        case AVRC_MEDIA_ATTR_ID_GENRE:
            attributeType = AvrcpMediaAttributeType::GENRE;
            break;
        case AVRC_MEDIA_ATTR_ID_PLAYING_TIME:
            attributeType = AvrcpMediaAttributeType::PLAYING_TIME;
            break;
        default:
            break;
        }
        names = base::SysUTF8ToWide(reinterpret_cast<char*>(p_attrs[i].text));
        MultiBytes = base::SysWideToNativeMB(names);
        attris.emplace_back(std::pair< AvrcpMediaAttributeType, std::string>(attributeType, std::move(MultiBytes)));
    }

    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandlePlayTrackChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        address,
        attris
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_play_position_changed_callback(
    RAW_ADDRESS_TYPE bd_addr, uint32_t song_len, uint32_t song_pos)
{
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandlePlayPosChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        BluetoothAddress(GET_ADDRESS_POINTER(bd_addr)->address),
        song_len,
        song_pos
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_play_status_changed_callback(
    RAW_ADDRESS_TYPE bd_addr, btrc_play_status_t play_status)
{
    AvrcpPlayStatus stauts;
    switch (play_status)
    {
    case BTRC_PLAYSTATE_STOPPED:
        stauts = AvrcpPlayStatus::STOPPED;
        break;
    case BTRC_PLAYSTATE_PLAYING:
        stauts = AvrcpPlayStatus::PLAYING;
        break;
    case BTRC_PLAYSTATE_PAUSED:
        stauts = AvrcpPlayStatus::PAUSED;
        break;
    case BTRC_PLAYSTATE_FWD_SEEK:
        stauts = AvrcpPlayStatus::FWD_SEEK;
        break;
    case BTRC_PLAYSTATE_REV_SEEK:
        stauts = AvrcpPlayStatus::REV_SEEK;
        break;
    case BTRC_PLAYSTATE_ERROR:
        stauts = AvrcpPlayStatus::ERROR_STATUS;
        break;
    default:
        break;
    }

    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandlePlayStatusChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        BluetoothAddress(GET_ADDRESS_POINTER(bd_addr)->address),
        stauts
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_get_folder_items_callback(
    RAW_ADDRESS_TYPE bd_addr, btrc_status_t status,
    const btrc_folder_items_t* folder_items, uint8_t count)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_change_path_callback
    (
    RAW_ADDRESS_TYPE bd_addr,
    uint32_t count
    )
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_set_browsed_player_callback(RAW_ADDRESS_TYPE bd_addr,
    uint8_t num_items,
    uint8_t depth)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_set_addressed_player_callback(
    RAW_ADDRESS_TYPE bd_addr, uint8_t status)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_btrc_ctrl_available_player_changed_callback(RAW_ADDRESS_TYPE bd_addr)
{
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandleAvailablePlayerChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        BluetoothAddress(GET_ADDRESS_POINTER(bd_addr)->address)
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_addressed_player_changed_callback(
    RAW_ADDRESS_TYPE bd_addr, uint16_t id)
{
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandleAddressedPlayerChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        BluetoothAddress(GET_ADDRESS_POINTER(bd_addr)->address),
        id
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_sinkbtrc_ctrl_now_playing_contents_changed_callback(
    RAW_ADDRESS_TYPE bd_addr)
{
    auto fun = std::bind
        (
        &BluetoothAvrcpController::HandleNowPlayingContentChangedCallback,
        BluetoothAvrcpController::GetMoudle(),
        BluetoothAddress(GET_ADDRESS_POINTER(bd_addr)->address)
        );
    PageManager::GetInstance().PostEvent(std::make_shared<ExecutbleEvent>(fun));
}

CALLBACK_STYLE void impl_btrc_ctrl_uids_changed_callback(RAW_ADDRESS_TYPE bd_addr,
    uint16_t uid_counter)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_btrc_ctrl_set_active_device_callback(
    RAW_ADDRESS_TYPE bd_addr, bool result)
{
    LOGCALLBACK
}

CALLBACK_STYLE void impl_btrc_ctrl_get_cover_art_psm_callback(RAW_ADDRESS_TYPE bd_addr,
    const uint16_t psm)
{
    LOGCALLBACK
}

namespace Bluetooth
{

    std::shared_ptr<BluetoothAvrcpInterface> BluetoothAvrcpInterface::CreateAvrcpInterface()
    {
        return std::make_shared<BluetoothAvrcpInterfaceImpl>();
    }

    BluetoothAvrcpInterfaceImpl::BluetoothAvrcpInterfaceImpl()
    {
        avrcpCallback.size = sizeof btrc_ctrl_callbacks_t;
        memset(&(avrcpCallback), 0, sizeof btrc_ctrl_callbacks_t);
        avrcpCallback.passthrough_rsp_cb = &impl_sinkbtrc_passthrough_rsp_callback;
        avrcpCallback.groupnavigation_rsp_cb = &impl_sinkbtrc_groupnavigation_rsp_callback;
        avrcpCallback.connection_state_cb = &impl_sinkbtrc_connection_state_callback;
        avrcpCallback.getrcfeatures_cb = &impl_sinkbtrc_ctrl_getrcfeatures_callback;
        avrcpCallback.setplayerappsetting_rsp_cb = &impl_sinkbtrc_ctrl_setplayerapplicationsetting_rsp_callback;
        avrcpCallback.playerapplicationsetting_cb = &impl_sinkbtrc_ctrl_playerapplicationsetting_callback;
        avrcpCallback.playerapplicationsetting_changed_cb = &impl_sinkbtrc_ctrl_playerapplicationsetting_changed_callback;
        avrcpCallback.setabsvol_cmd_cb = &impl_sinkbtrc_ctrl_setabsvol_cmd_callback;
        avrcpCallback.registernotification_absvol_cb = &impl_sinkbtrc_ctrl_registernotification_abs_vol_callback;
        avrcpCallback.track_changed_cb = &impl_sinkbtrc_ctrl_track_changed_callback;
        avrcpCallback.play_position_changed_cb = &impl_sinkbtrc_ctrl_play_position_changed_callback;
        avrcpCallback.play_status_changed_cb = &impl_sinkbtrc_ctrl_play_status_changed_callback;
        avrcpCallback.get_folder_items_cb = &impl_sinkbtrc_ctrl_get_folder_items_callback;
        avrcpCallback.change_folder_path_cb = &impl_sinkbtrc_ctrl_change_path_callback;
        avrcpCallback.set_browsed_player_cb = &impl_sinkbtrc_ctrl_set_browsed_player_callback;
        avrcpCallback.set_addressed_player_cb = &impl_sinkbtrc_ctrl_set_addressed_player_callback;
        avrcpCallback.available_player_changed_cb = &impl_btrc_ctrl_available_player_changed_callback;
        avrcpCallback.get_cover_art_psm_cb = &impl_btrc_ctrl_get_cover_art_psm_callback;
        avrcpCallback.addressed_player_changed_cb = &impl_sinkbtrc_ctrl_addressed_player_changed_callback;
        avrcpCallback.now_playing_contents_changed_cb = &impl_sinkbtrc_ctrl_now_playing_contents_changed_callback;
    }

    bool BluetoothAvrcpInterfaceImpl::SendGetPlayBackStateCmd(BluetoothAddress const& a_address)
    {
        RawAddress address;
        memcpy(address.address, a_address.address, BluetoothAddress::kLength);
        bt_status_t status = m_avrcpCtrolInterface->get_playback_state_cmd(address);
        return status == BT_STATUS_SUCCESS;
    }

    bool BluetoothAvrcpInterfaceImpl::SendPassThroughCmd
        (
        BluetoothAddress const& a_address,
        AvrcpPassThroughKeyState a_state,
        AvrcpPassThroughKeyCode a_key
        )
    {
        RawAddress address;
        memcpy(address.address, a_address.address, BluetoothAddress::kLength);
        bt_status_t status = m_avrcpCtrolInterface->send_pass_through_cmd
            (
            address,
            static_cast<uint8_t>(a_key),
            static_cast<uint8_t>(a_state)
            );
        return status == BT_STATUS_SUCCESS;
    }

    bool BluetoothAvrcpInterfaceImpl::init()
    {
        bt_interface_t* interfaceBt = nullptr;
        interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();

        btrc_ctrl_interface_t const* inter2 =
            reinterpret_cast<btrc_ctrl_interface_t const*>(interfaceBt->get_profile_interface(BT_PROFILE_AV_RC_CTRL_ID));

        m_avrcpCtrolInterface = const_cast<btrc_ctrl_interface_t*>(inter2);
        bt_status_t status = m_avrcpCtrolInterface->init(&avrcpCallback);
        return status == BT_STATUS_SUCCESS;
    }

}

