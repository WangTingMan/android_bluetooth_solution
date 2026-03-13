
#if __has_include("windows/windows_usb_transport.h")
#include "windows/windows_usb_transport.h"
#define USE_BLUETOOTH_DRIVER_WITH_STATIC
#endif

#include "hardware/intel_bluetooth_chipset_initializer.h"
#include "hardware/log.h"
#include "utils/direct.h"

#include <atomic>
#include <thread>
#include <chrono>
#include <string>
#include <future>

#include <log/log.h>

#ifdef USE_BLUETOOTH_DRIVER_WITH_STATIC

std::atomic_bool s_initialized = false;
std::promise<void> s_initial_promise;
std::function<void( char, char*, uint16_t )> s_hci_data_callback;

windows_usb_transport s_windows_usb_transport;;
intel_bluetooth_chipset_initializer s_intel_chipset_initializer;

std::vector<std::string> prepare_intel_fw_path( std::string a_fw_name )
{
    std::vector<std::string> paths;

    std::string cur_dir = GetCurrentDir();
    if( cur_dir.back() != '/' &&
        cur_dir.back() != '\\' )
    {
        cur_dir.push_back( '/' );
    }

    cur_dir.append( "intel_fw/" ).append( a_fw_name );

    paths.push_back( cur_dir );

    return paths;
}

void capture_hci_during_initializing
    (
    uint8_t a_type,
    uint8_t* a_data,
    uint16_t a_size
    )
{
    
}

void initialization_complete( int status )
{
    s_initialized.store( true );
    s_initial_promise.set_value();
}

void hci_initialize
    (
    std::promise<void> initial_promise,
    std::function<void( char, char*, uint16_t )> call_back
    )
{
    if( s_initialized.load() )
    {
        ALOG( LOG_WARN, LOG_TAG, "Already initialized. %s. line: %d", __func__, __LINE__ );
        initial_promise.set_value();
        return;
    }
    s_hci_data_callback = call_back;
    s_initial_promise = std::move( initial_promise );

    s_intel_chipset_initializer.set_fw_file_preparer( std::bind( &prepare_intel_fw_path,
        std::placeholders::_1 ) );

    set_transport_logger( []( __log_message a_log )
        {
            android_LogPriority prio = ANDROID_LOG_INFO;
            switch( a_log.priority )
            {
            case LOG_DEBUG_LEVEL:
                prio = ANDROID_LOG_DEBUG;
            break;
            case LOG_ERROR_LEVEL:
                prio = ANDROID_LOG_ERROR;
            break;
            case LOG_FATAL_LEVEL:
                prio = ANDROID_LOG_FATAL;
            break;
            case LOG_INFO_LEVEL:
                prio = ANDROID_LOG_INFO;
            break;
            case LOG_VERBOSE_LEVEL:
                prio = ANDROID_LOG_VERBOSE;
            break;
            case LOG_WARN_LEVEL:
                prio = ANDROID_LOG_WARN;
            break;
            }
            __android_log_print_ext( prio, "TRANSPORT", a_log.file, a_log.line, a_log.message );
        } );

    bool status = s_windows_usb_transport.open_bluetooth_usb();
    if( !status )
    {
        return;
    }

    s_windows_usb_transport.set_controller_data_handler( std::bind(
        &intel_bluetooth_chipset_initializer::hci_packet_bringup_handler, &s_intel_chipset_initializer,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );

    intel_bluetooth_chipset_initializer::hci_sender sender;
    intel_bluetooth_chipset_initializer::initialize_completed_callback initialize_callback;
    sender = std::bind( &windows_usb_transport::send_data_to_controller,
        &s_windows_usb_transport, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 );
    initialize_callback = []( bool a_result )
        {
            controller_data_handler_type handler;
            handler = []( uint8_t a_type, uint8_t* a_data, uint16_t a_size )
                {
                    s_hci_data_callback( ( char )a_type, ( char* )a_data, a_size );
                };
            s_windows_usb_transport.set_controller_data_handler( handler );
            initialization_complete( true );
        };

    s_intel_chipset_initializer.set_sender( sender );
    s_intel_chipset_initializer.set_hci_recorder( std::bind( &capture_hci_during_initializing,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );
    s_intel_chipset_initializer.set_initialization_callback( initialize_callback );

    s_intel_chipset_initializer.initialize();
}

bool hci_transmit
    (
    char a_type,    // The packet type. Command, event, or acl packet
    char* a_buffer, // Packet buffer
    uint16_t a_size // Packet size
    )
{
    s_windows_usb_transport.send_data_to_controller( a_type, (uint8_t*)a_buffer, a_size );
    return true;
}

#endif

