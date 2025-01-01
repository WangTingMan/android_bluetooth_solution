#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <gd/os/queue.h>
#include <base/rand_util.h>
#include <hci/acl_manager/acl_connection.h>

#include <memory>
#include <thread>

class QueueElementTest
{

public:

    std::string decriptor;
    int value = 0;
};

bluetooth::common::BidiQueueEnd<QueueElementTest, QueueElementTest>* down_end = nullptr;
bluetooth::common::BidiQueueEnd<QueueElementTest, QueueElementTest>* up_end = nullptr;

class packet_builder : public bluetooth::packet::BasePacketBuilder
{

public:

    size_t size() const
    {
        return 10;
    }

    void Serialize(bluetooth::packet::BitInserter& it) const
    {
        int x = 0;
        x = 90;
    }

};

void dequeue_callback()
{
    auto data = down_end->TryDequeue();
    if( data )
    {
        data->value;
        LOG( INFO ) << "dequeue a element with value " << data->value;
    }

    auto data1 = up_end->TryDequeue();
}

std::unique_ptr<QueueElementTest> enqueue_callback()
{
    static int count = 0;

    std::unique_ptr<QueueElementTest> builder;
    builder = std::make_unique<QueueElementTest>();
    builder->decriptor = ( "enqueue_callback generated." );
    builder->value = ++count;
    LOG( INFO ) << "Enqueue a element with value " << builder->value;
    return builder;
}

void test_impl()
{
    bluetooth::os::Thread thread_dequeue("dequeue_test", bluetooth::os::Thread::Priority::NORMAL);
    bluetooth::os::Handler handler_dequeue(&thread_dequeue);
    bluetooth::os::Thread thread_enqueue("enqueue_test", bluetooth::os::Thread::Priority::NORMAL);
    bluetooth::os::Handler handler_enqueue(&thread_enqueue);

    bluetooth::common::BidiQueue<QueueElementTest, QueueElementTest> queue(20);
    up_end = queue.GetUpEnd();
    down_end = queue.GetDownEnd();

    down_end->RegisterDequeue(&handler_dequeue, base::Bind(dequeue_callback), FROM_HERE);

    for( int i = 0; i < 10; ++i )
    {
        up_end->RegisterEnqueue( &handler_enqueue, base::Bind( &enqueue_callback ) );
        std::this_thread::sleep_for( std::chrono::milliseconds( base::RandInt( 10, 200 ) ) );
    }

    std::this_thread::sleep_for(std::chrono::hours(1));
    int x = 0;
    x = 90;
}

