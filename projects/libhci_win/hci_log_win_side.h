#pragma once
#include <cstdint>

void record_hci_log_win_side
    (
    bool is_received,
    char a_type,    // The packet type. Command, event, or acl packet
    char* a_buffer, // Packet buffer
    uint16_t a_size // Packet size
    );
