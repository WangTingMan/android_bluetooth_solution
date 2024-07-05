#define LOG_TAG "bt_osi_alarm"

#include "osi/include/alarm.h"
#include "stack/include/main_thread.h"

#include <utils/Timers.h>

struct alarm_t
{
    uint32_t id = 0;
};

alarm_t* alarm_new( const char* name )
{
    uint32_t id = create_timer( []() {}, name );
    alarm_t* ret = new alarm_t;
    ret->id = id;
    return ret;
}

alarm_t* alarm_new_periodic( const char* name )
{
    return alarm_new( name );
}

void alarm_free( alarm_t* alarm )
{
    if( !alarm )
    {
        return;
    }

    delete_timer( alarm->id );
    delete alarm;
}

void alarm_set( alarm_t* alarm, uint64_t interval_ms, alarm_callback_t cb,
                void* data )
{
    set_timer( alarm->id, interval_ms, cb, data );
}

void alarm_set_on_mloop( alarm_t* alarm, uint64_t interval_ms,
                         alarm_callback_t cb, void* data )
{
    std::function<void()> fun = std::bind( cb, data );
    set_timer_option( alarm->id, interval_ms, std::bind( post_on_bt_main, fun ) );
}

void alarm_cancel( alarm_t* alarm )
{
    if (!alarm) {
        return;
    }
    stop_timer( alarm->id );
}

bool alarm_is_scheduled( const alarm_t* alarm )
{
    if (!alarm) {
        return false;
    }
    return 0 != is_timer_scheduled( alarm->id );
}

uint64_t alarm_get_remaining_ms( const alarm_t* alarm )
{
    return get_timer_remaining_ms( alarm->id );
}

void alarm_cleanup( void )
{

}

void alarm_debug_dump( int fd )
{

}

