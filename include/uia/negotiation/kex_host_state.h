//
// Part of Metta OS. Check http://atta-metta.net for latest version.
//
// Copyright 2007 - 2015, Stanislav Karchebnyy <berkus@atta-metta.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include <memory>
#include <unordered_map>
#include "arsenal/byte_array.h"
#include "uia/comm/socket_endpoint.h"
#include "uia/forward_ptrs.h"

namespace uia {
namespace negotiation {

/**
 * Mixin for the host state that manages the key exchange state.
 */
class kex_host_state
{
    /**
     * Initiators by endpoint.
     * Used for handling R0 packets during hole-punching.
     */
    std::unordered_map<comm::endpoint, initiator_ptr> initiators_;

public:
    initiator_ptr get_initiator(comm::endpoint ep);
    void register_initiator(comm::endpoint ep, initiator_ptr ki);
    void unregister_initiator(comm::endpoint ep);

    void instantiate_responder(); // virtual abstract?
};

} // negotiation namespace
} // uia namespace
