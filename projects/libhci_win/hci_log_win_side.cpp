#include "hci_log_win_side.h"
#include <fstream>
#include <mutex>
#include <chrono>

#include <WinSock2.h>

static std::ofstream logfile_fd_windows;
static std::mutex btsnoop_mutex;

// The size of the L2CAP header. All information past this point is removed from
// a filtered packet.
static constexpr uint32_t L2C_HEADER_SIZE = 9;
// Epoch in microseconds since 01/01/0000.
static constexpr uint64_t BTSNOOP_EPOCH_DELTA = 0x00dcddb30f2f8000ULL;

#define HCI_AIR_SIDE_LOG "D:/bluetooth/hci_air_side.log"

#pragma pack(1)
struct btsnoop_header
{
    uint32_t length_original;
    uint32_t length_captured;
    uint32_t flags;
    uint32_t dropped_packets;
    uint64_t timestamp;
};
#pragma pack()

enum packet_type_t : uint8_t
{
    kCommandPacket = 1,
    kAclPacket = 2,
    kScoPacket = 3,
    kEventPacket = 4
};

static uint64_t htonll_( uint64_t ll )
{
    const uint32_t l = 1;
    if( *( reinterpret_cast<const uint8_t*>( &l ) ) == 1 )
        return static_cast<uint64_t>( htonl( ll & 0xffffffff ) ) << 32 |
        htonl( ll >> 32 );

    return ll;
}

void record_hci_log_win_side
    (
    bool is_received,
    char a_type,    // The packet type. Command, event, or acl packet
    char* packet, // Packet buffer
    uint16_t a_size // Packet size
    )
{
#ifndef ENABLE_HCI_AIR_SIDE_LOG
    return;
#endif

    btsnoop_header header;
    uint32_t length_he = a_size + 1; // Because we have a data type byte.
    uint32_t flags = 0;

    switch( a_type )
    {
    case kCommandPacket:
        flags = 2;
    break;
    case kAclPacket:
        flags = is_received ? 0x01 : 0x00;
    break;
    case kScoPacket:
        flags = is_received ? 0x01 : 0x00;
    break;
    case kEventPacket:
        flags = 3;
    break;
    }

    if( a_type == kEventPacket )
    {
        if( packet[3] == 0x02 && packet[4] == 0x10 )
        {
            int x = 0;
            x++;
        }
    }

    header.length_original = htonl( length_he );

    timespec tp;
    int r = timespec_get( &tp, TIME_UTC );
    uint64_t timestamp_us =
        ( (uint64_t)tp.tv_sec * 1000000L ) + ( (uint64_t)tp.tv_nsec / 1000 );
    timestamp_us += std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::hours( 8 ) ).count();

    header.length_captured = header.length_original;
    header.flags = htonl( flags );
    header.dropped_packets = 0;
    header.timestamp = htonll_( timestamp_us + BTSNOOP_EPOCH_DELTA );

    std::lock_guard<std::mutex> locker( btsnoop_mutex );

    if( !logfile_fd_windows.is_open() )
    {
        std::string log_path( HCI_AIR_SIDE_LOG );
        logfile_fd_windows.open( log_path, std::ios::binary | std::ios::out | std::ios::trunc );
        if( !logfile_fd_windows.is_open() )
        {
            return;
        }
        logfile_fd_windows.write( "btsnoop\0\0\0\0\1\0\0\x3\xea", 16 );
    }

    logfile_fd_windows.write( reinterpret_cast<char*>( &header ), 24 );
    logfile_fd_windows.write( reinterpret_cast<char*>( &a_type ), 1 );
    logfile_fd_windows.write( reinterpret_cast<char*>( packet ), a_size );
    logfile_fd_windows.flush();

}

