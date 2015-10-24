//
// Part of Metta OS. Check http://atta-metta.net for latest version.
//
// Copyright 2007 - 2015, Stanislav Karchebnyy <berkus@atta-metta.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "uia/negotiation/channel_initiator.h"

namespace uia {
namespace negotiation {

channel_initiator::channel_initiator(host_ptr host,
                                     peer_identity const& target_peer,
                                     comm::socket_endpoint target)
    : initiator(host, target_peer, target)
{
}

} // negotiation namespace
} // uia namespace
