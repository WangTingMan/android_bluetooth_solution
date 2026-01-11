#include "BluetoothAvrcpTargetInterfaceImpl.h"
#include "BluetoothBaseImplementation.h"

__BEGIN_DECLS

/** Callback for the controller's supported feautres */
void btrc_remote_features_callback_impl( const RawAddress& bd_addr,
                                         btrc_remote_features_t features )
{

}

/** Callback for play status request */
void btrc_get_play_status_callback_impl( const RawAddress& bd_addr )
{

}

/** Callback for list player application attributes (Shuffle, Repeat,...) */
void btrc_list_player_app_attr_callback_impl( const RawAddress& bd_addr )
{

}

/** Callback for list player application attributes (Shuffle, Repeat,...) */
void btrc_list_player_app_values_callback_impl( btrc_player_attr_t attr_id,
                                                const RawAddress& bd_addr )
{

}

/** Callback for getting the current player application settings value
**  num_attr: specifies the number of attribute ids contained in p_attrs
*/
void btrc_get_player_app_value_callback_impl( uint8_t num_attr,
                                                      btrc_player_attr_t* p_attrs,
                                              const RawAddress& bd_addr )
{

}

/** Callback for getting the player application settings attributes' text
**  num_attr: specifies the number of attribute ids contained in p_attrs
*/
void btrc_get_player_app_attrs_text_callback_impl(
    uint8_t num_attr, btrc_player_attr_t* p_attrs, const RawAddress& bd_addr )
{

}

/** Callback for getting the player application settings values' text
**  num_attr: specifies the number of value ids contained in p_vals
*/
void btrc_get_player_app_values_text_callback_impl(
    uint8_t attr_id, uint8_t num_val, uint8_t* p_vals,
    const RawAddress& bd_addr )
{

}

/** Callback for setting the player application settings values */
void btrc_set_player_app_value_callback_impl(
    btrc_player_settings_t* p_vals, const RawAddress& bd_addr )
{

}

/** Callback to fetch the get element attributes of the current song
**  num_attr: specifies the number of attributes requested in p_attrs
*/
void btrc_get_element_attr_callback_impl( uint8_t num_attr,
                                                  btrc_media_attr_t* p_attrs,
                                          const RawAddress& bd_addr )
{

}

/** Callback for register notification (Play state change/track change/...)
**  param: Is only valid if event_id is BTRC_EVT_PLAY_POS_CHANGED
*/
void btrc_register_notification_callback_impl( btrc_event_id_t event_id,
                                                       uint32_t param,
                                               const RawAddress& bd_addr )
{

}

/* AVRCP 1.4 Enhancements */
/** Callback for volume change on CT
**  volume: Current volume setting on the CT (0-127)
*/
void btrc_volume_change_callback_impl( uint8_t volume, uint8_t ctype,
                                       const RawAddress& bd_addr )
{

}

/** Callback for passthrough commands */
void btrc_passthrough_cmd_callback_impl( int id, int key_state,
                                         const RawAddress& bd_addr )
{

}

/** Callback for set addressed player response on TG **/
void btrc_set_addressed_player_callback_impl( uint16_t player_id,
                                              const RawAddress& bd_addr )
{

}

/** Callback for set browsed player response on TG **/
void btrc_set_browsed_player_callback_impl( uint16_t player_id,
                                            const RawAddress& bd_addr )
{

}

/** Callback for get folder items on TG
**  num_attr: specifies the number of attributes requested in p_attr_ids
*/
void btrc_get_folder_items_callback_impl(
    uint8_t scope, uint32_t start_item, uint32_t end_item, uint8_t num_attr,
    uint32_t* p_attr_ids, const RawAddress& bd_addr )
{

}

/** Callback for changing browsed path on TG **/
void btrc_change_path_callback_impl( uint8_t direction,
                                             uint8_t* folder_uid,
                                     const RawAddress& bd_addr )
{

}

/** Callback to fetch the get item attributes of the media item
**  num_attr: specifies the number of attributes requested in p_attrs
*/
void btrc_get_item_attr_callback_impl( uint8_t scope, uint8_t* uid,
                                               uint16_t uid_counter,
                                               uint8_t num_attr,
                                               btrc_media_attr_t* p_attrs,
                                       const RawAddress& bd_addr )
{

}

/** Callback for play request for the media item indicated by an identifier */
void btrc_play_item_callback_impl( uint8_t scope, uint16_t uid_counter,
                                           uint8_t* uid,
                                   const RawAddress& bd_addr )
{

}

/** Callback to fetch total number of items from a folder **/
void btrc_get_total_num_of_items_callback_impl( uint8_t scope,
                                                const RawAddress& bd_addr )
{

}

/** Callback for conducting recursive search on a current browsed path for a
 * specified string */
void btrc_search_callback_impl( uint16_t charset_id, uint16_t str_len,
                                uint8_t* p_str, const RawAddress& bd_addr )
{

}

/** Callback to add a specified media item indicated by an identifier to now
 * playing queue. */
void btrc_add_to_now_playing_callback_impl( uint8_t scope, uint8_t* uid,
                                                    uint16_t uid_counter,
                                            const RawAddress& bd_addr )
{

}
__END_DECLS

Bluetooth::BluetoothAvrcpTargetInterfaceImpl& Bluetooth::BluetoothAvrcpTargetInterfaceImpl::GetInterface()
{
    static BluetoothAvrcpTargetInterfaceImpl instance;
    return instance;
}

BluetoothAvrcpTargetInterface& BluetoothAvrcpTargetInterface::GetInterface()
{
    return Bluetooth::BluetoothAvrcpTargetInterfaceImpl::GetInterface();
}

Bluetooth::BluetoothAvrcpTargetInterfaceImpl::BluetoothAvrcpTargetInterfaceImpl()
{
    m_avrcpTargetInterface = nullptr;
    memset( &m_avrcpTargetCallback, 0x00, sizeof( m_avrcpTargetCallback ) );
}

void Bluetooth::BluetoothAvrcpTargetInterfaceImpl::Init()
{
    m_avrcpTargetCallback.remote_features_cb = btrc_remote_features_callback_impl;
    m_avrcpTargetCallback.get_play_status_cb = btrc_get_play_status_callback_impl;
    m_avrcpTargetCallback.list_player_app_attr_cb = btrc_list_player_app_attr_callback_impl;
    m_avrcpTargetCallback.list_player_app_values_cb = btrc_list_player_app_values_callback_impl;
    m_avrcpTargetCallback.get_player_app_value_cb = btrc_get_player_app_value_callback_impl;
    m_avrcpTargetCallback.get_player_app_attrs_text_cb = btrc_get_player_app_attrs_text_callback_impl;
    m_avrcpTargetCallback.get_player_app_values_text_cb = btrc_get_player_app_values_text_callback_impl;
    m_avrcpTargetCallback.set_player_app_value_cb = btrc_set_player_app_value_callback_impl;
    m_avrcpTargetCallback.get_element_attr_cb = btrc_get_element_attr_callback_impl;
    m_avrcpTargetCallback.register_notification_cb = btrc_register_notification_callback_impl;
    m_avrcpTargetCallback.volume_change_cb = btrc_volume_change_callback_impl;
    m_avrcpTargetCallback.passthrough_cmd_cb = btrc_passthrough_cmd_callback_impl;
    m_avrcpTargetCallback.set_addressed_player_cb = btrc_set_addressed_player_callback_impl;
    m_avrcpTargetCallback.set_browsed_player_cb = btrc_set_browsed_player_callback_impl;
    m_avrcpTargetCallback.get_folder_items_cb = btrc_get_folder_items_callback_impl;
    m_avrcpTargetCallback.change_path_cb = btrc_change_path_callback_impl;
    m_avrcpTargetCallback.get_item_attr_cb = btrc_get_item_attr_callback_impl;
    m_avrcpTargetCallback.play_item_cb = btrc_play_item_callback_impl;
    m_avrcpTargetCallback.get_total_num_of_items_cb = btrc_get_total_num_of_items_callback_impl;
    m_avrcpTargetCallback.search_cb = btrc_search_callback_impl;
    m_avrcpTargetCallback.add_to_now_playing_cb = btrc_add_to_now_playing_callback_impl;
    m_avrcpTargetCallback.size = sizeof( m_avrcpTargetCallback );

    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();

    btrc_interface_t const* inter2 =
        reinterpret_cast<btrc_interface_t const*>( interfaceBt->get_profile_interface( BT_PROFILE_AV_RC_ID ) );

    m_avrcpTargetInterface = const_cast<btrc_interface_t*>( inter2 );
    bt_status_t status = m_avrcpTargetInterface->init( &m_avrcpTargetCallback );
    return;
}

bool Bluetooth::BluetoothAvrcpTargetInterfaceImpl::Connect
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool Bluetooth::BluetoothAvrcpTargetInterfaceImpl::disconnect
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool Bluetooth::BluetoothAvrcpTargetInterfaceImpl::setActiveDevice
    (
    BluetoothAddress a_address
    )
{
    return true;
}

bool Bluetooth::BluetoothAvrcpTargetInterfaceImpl::setSilenceDevice
    (
    BluetoothAddress a_address
    )
{
    return true;
}

