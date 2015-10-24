#include "uia/comm/packet_receiver.h"
#include "uia/comm/socket_host_interface.h"
#include "arsenal/logging.h"

using namespace std;

namespace uia {
namespace comm {

//=================================================================================================
// packet_receiver
//=================================================================================================

void
packet_receiver::bind(uint64_t magic)
{
    // assert(!is_bound()); @todo Make receiver possible to bind to multiple magic values...
    assert(magic != 0);
    assert(!host_interface_->has_receiver_for(magic));

    magic_ = magic;
    logger::debug() << "Link receiver " << this << " binds for magic " << hex << magic_;
    host_interface_->bind_receiver(magic_, shared_from_this());
}

void
packet_receiver::unbind()
{
    if (is_bound())
    {
        logger::debug() << "Link receiver " << this << " unbinds magic " << hex << magic_;
        host_interface_->unbind_receiver(magic_);
        // make it possible to unbind from multiple magic values too...
        magic_ = 0;
    }
}

} // comm namespace
} // uia namespace
