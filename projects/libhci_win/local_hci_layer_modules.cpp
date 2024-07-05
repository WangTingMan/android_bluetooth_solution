#include <win_bluetooth.h>

#include <atomic>
#include <thread>
#include <chrono>
#include <string>
#include <future>

#include "hci_log_win_side.h"

#define USE_LOCAL_HCI_LAYRER_MODULE

#ifdef USE_LOCAL_HCI_LAYRER_MODULE

#pragma comment(lib, "libWinBluetooth.lib")

#if defined(__ANDROID__)
#define LOG_FOLDER_NAME "/data/misc/bluetooth/logs/"
#else 
#define LOG_FOLDER_NAME "D:/bluetooth/"
#define ALOG(...)
#endif

#define LOG_FILE_NAME "host_agent"

#define PRING_HCI_DETAIL_LOG

win_bluetooth_hci_callback_t hci_callback_s;
std::atomic_bool s_initialized = false;
std::promise<void> s_initial_promise;
std::function<void( char, char*, uint16_t )> s_hci_data_callback;

void initialization_complete( int status )
{
    s_initialized.store( true );
    s_initial_promise.set_value();
}

void handle_data_from_controller( uint8_t a_type, uint8_t* a_data, uint16_t a_size )
{
    record_hci_log_win_side( true, a_type, (char*)a_data, a_size );
    if( s_hci_data_callback )
    {
        s_hci_data_callback( static_cast<char>( a_type ),
                             reinterpret_cast<char*>( a_data ),
                             a_size
        );
    }
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
    hci_callback_s.chipset_initialization_completed = &initialization_complete;
    hci_callback_s.handle_data_from_controller = &handle_data_from_controller;
    get_win_bluetooth_hci_interface()->register_callback( &hci_callback_s );

    s_initial_promise = std::move( initial_promise );
    get_win_bluetooth_hci_interface()->initialize();
}

bool hci_transmit
    (
    char a_type,    // The packet type. Command, event, or acl packet
    char* a_buffer, // Packet buffer
    uint16_t a_size // Packet size
    )
{
    record_hci_log_win_side( false, a_type, a_buffer, a_size );

    if( ( a_buffer[0] == 0x53 ) && ( a_buffer[1] == 0xFD ) )
    {
        int x = 0;
        x = 90;
    }
    int size = get_win_bluetooth_hci_interface()
        ->send_data_to_controller( a_type,
                                   reinterpret_cast<uint8_t*>( a_buffer ),
                                   a_size
                                 );
    return true;
}

#endif

