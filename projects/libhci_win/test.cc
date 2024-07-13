#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <gd/os/queue.h>
#include <hci/acl_manager/acl_connection.h>

#include <memory>

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
    int x = 0;
    x = 90;
}

std::unique_ptr<bluetooth::packet::BasePacketBuilder> enqueue_callback()
{
    std::unique_ptr<bluetooth::packet::BasePacketBuilder> builder;
    builder = std::make_unique<packet_builder>();
    return builder;
}

void test_impl()
{
    bluetooth::os::Thread thread_dequeue("dequeue_test", bluetooth::os::Thread::Priority::NORMAL);
    bluetooth::os::Handler handler_dequeue(&thread_dequeue);
    bluetooth::os::Thread thread_enqueue("enqueue_test", bluetooth::os::Thread::Priority::NORMAL);
    bluetooth::os::Handler handler_enqueue(&thread_enqueue);
    auto queue = std::make_shared<bluetooth::hci::acl_manager::AclConnection::Queue>(10);
    auto upend = queue->GetUpEnd();
    auto down_end = queue->GetDownEnd();
    down_end->RegisterDequeue(&handler_dequeue, base::Bind(dequeue_callback));
    upend->RegisterEnqueue(&handler_enqueue, base::Bind(&enqueue_callback));

    std::this_thread::sleep_for(std::chrono::hours(1));
    int x = 0;
    x = 90;
}

