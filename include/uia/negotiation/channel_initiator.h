//
// Part of Metta OS. Check http://atta-metta.net for latest version.
//
// Copyright 2007 - 2015, Stanislav Karchebnyy <berkus@atta-metta.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "uia/negotiation/initiator.h"
#include "uia/comm/socket_endpoint.h"
#include "uia/peer_identity.h"

namespace uia {
namespace negotiation {

class channel_initiator : public initiator
{
public:
    /// Start key negotiation with remote peer. If successful, this negotiation will yield a
    /// new channel via `create_channel()` call to responder.
    channel_initiator(host_ptr host, peer_identity const& target_peer,
        comm::socket_endpoint target);
};

} // negotiation namespace
} // uia namespace
