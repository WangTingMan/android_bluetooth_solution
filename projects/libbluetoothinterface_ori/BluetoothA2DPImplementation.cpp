#include "BluetoothA2DPImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <BT/BluetoothAddress.h>
#include <BT/a2dp/BluetoothA2DPSource.h>

#include <Zhen/PageManager.h>
#include <Zhen/ExecutbleEvent.h>

static constexpr int MAX_SNK_ALLOWED = 1;

BluetoothA2DPInterface& BluetoothA2DPInterface::GetInterface()
{
    return BluetoothA2DPImplementation::GetInterface();
}

BluetoothA2DPImplementation& BluetoothA2DPImplementation::GetInterface()
{
    static BluetoothA2DPImplementation instance;
    return instance;
}

static void PostA2DPSourceEvent(std::function<void(Bluetooth::BluetoothA2DPSource*)> a_fun)
{
    std::shared_ptr<Bluetooth::BluetoothA2DPSource> hfModule = Bluetooth::BluetoothA2DPSource::GetMoudle();
    if (hfModule)
    {
        std::function<void()> fun = [a_fun, hfModule]() { a_fun(hfModule.get()); };
        auto executableEvent = std::make_shared<ExecutbleEvent>(fun);
        PageManager::GetInstance().PostEvent(executableEvent);
    }
}

bool impl_btav_mandatory_codec_preferred_callback(
    const RawAddress& bd_addr)
{
    bool isSbcPreferred = false;// Whether the mandatory codec is more preferred than others.
    BluetoothAddress address(bd_addr.address);
    auto fun = std::bind
        (
        &Bluetooth::BluetoothA2DPSource::handle_btav_mandatory_codec_preferred_callback,
        std::placeholders::_1,
        address
        );

    PostA2DPSourceEvent(fun);

    isSbcPreferred = true;
    return isSbcPreferred;
}

void impl_btav_audio_source_config_callback(
    const RawAddress& bd_addr, btav_a2dp_codec_config_t codec_config,
    std::vector<btav_a2dp_codec_config_t> codecs_local_capabilities,
    std::vector<btav_a2dp_codec_config_t> codecs_selectable_capabilities)
{
    BluetoothAddress address(bd_addr.address);
}

void impl_btav_connection_state_callback
    (
    const RawAddress& bd_addr,
    btav_connection_state_t state,
    const btav_error_t& error
    )
{
}

/** Callback for audiopath state change.
 *  state will have one of the values from btav_audio_state_t
 */
void impl_btav_audio_state_callback(const RawAddress& bd_addr,
    btav_audio_state_t state)
{
    BluetoothAddress address(bd_addr.address);
}

void BluetoothA2DPImplementation::Init()
{
    memset(&m_callBack, 0x00, sizeof m_callBack);
    m_callBack.size = sizeof(btav_source_callbacks_t);
    m_callBack.audio_config_cb = &impl_btav_audio_source_config_callback;
    m_callBack.audio_state_cb = &impl_btav_audio_state_callback;
    m_callBack.connection_state_cb = &impl_btav_connection_state_callback;
    m_callBack.mandatory_codec_preferred_cb = &impl_btav_mandatory_codec_preferred_callback;

    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    m_av_source_interface = (btav_source_interface_t*)interfaceBt->get_profile_interface
        (BT_PROFILE_ADVANCED_AUDIO_ID);

    btav_a2dp_codec_config_t sbcCodeConfig;
    sbcCodeConfig.bits_per_sample = BTAV_A2DP_CODEC_BITS_PER_SAMPLE_32;
    sbcCodeConfig.channel_mode = BTAV_A2DP_CODEC_CHANNEL_MODE_STEREO;
    sbcCodeConfig.codec_type = BTAV_A2DP_CODEC_INDEX_SOURCE_SBC;
    sbcCodeConfig.codec_priority = BTAV_A2DP_CODEC_PRIORITY_DEFAULT;
    sbcCodeConfig.sample_rate = BTAV_A2DP_CODEC_SAMPLE_RATE_48000;
    sbcCodeConfig.codec_specific_1 = 0;
    sbcCodeConfig.codec_specific_2 = 0;
    sbcCodeConfig.codec_specific_3 = 0;
    sbcCodeConfig.codec_specific_4 = 0;

    btav_a2dp_codec_config_t aacCodeConfig;
    aacCodeConfig.bits_per_sample = BTAV_A2DP_CODEC_BITS_PER_SAMPLE_32;
    aacCodeConfig.channel_mode = BTAV_A2DP_CODEC_CHANNEL_MODE_STEREO;
    aacCodeConfig.codec_type = BTAV_A2DP_CODEC_INDEX_SOURCE_AAC;
    aacCodeConfig.codec_priority = BTAV_A2DP_CODEC_PRIORITY_HIGHEST;
    aacCodeConfig.sample_rate = BTAV_A2DP_CODEC_SAMPLE_RATE_48000;
    aacCodeConfig.codec_specific_1 = 0;
    aacCodeConfig.codec_specific_2 = 0;
    aacCodeConfig.codec_specific_3 = 0;
    aacCodeConfig.codec_specific_4 = 0;

    std::vector<btav_a2dp_codec_config_t> codec_priorities;
    codec_priorities.push_back(sbcCodeConfig);
    codec_priorities.push_back(aacCodeConfig);

    std::vector<btav_a2dp_codec_info_t> supported_codecs;

    m_av_source_interface->init
        (
        &m_callBack,
        MAX_SNK_ALLOWED,
        codec_priorities,
        codec_priorities,
        &supported_codecs
        );
}

bool BluetoothA2DPImplementation::Connect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_av_source_interface->connect(address);
    return true;
}

bool BluetoothA2DPImplementation::disconnect
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_av_source_interface->disconnect(address);
    return true;
}

bool BluetoothA2DPImplementation::setActiveDevice
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    bt_status_t ret_status = BT_STATUS_SUCCESS;
    ret_status = m_av_source_interface->set_active_device(address);
    return BT_STATUS_SUCCESS == ret_status;
}

bool BluetoothA2DPImplementation::setSilenceDevice
    (
    BluetoothAddress a_address
    )
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_av_source_interface->set_silence_device(address, true);
    return true;
}

