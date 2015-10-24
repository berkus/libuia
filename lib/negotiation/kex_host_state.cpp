#include "uia/negotiation/kex_host_state.h"

namespace uia {
namespace negotiation {

void
kex_host_state::instantiate_responder()
{}

initiator_ptr
kex_host_state::get_initiator(uia::comm::endpoint ep)
{
    auto it = initiators_.find(ep);
    if (it == initiators_.end()) {
        return nullptr;
    }
    return it->second;
}

void
kex_host_state::register_initiator(uia::comm::endpoint ep, initiator_ptr ki)
{
    initiators_.insert(make_pair(ep, ki));
}

void
kex_host_state::unregister_initiator(uia::comm::endpoint ep)
{
    initiators_.erase(ep);
}

} // negotiation namespace
} // uia namespace
