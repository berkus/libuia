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
#include <boost/asio/buffer.hpp>
#include "uia/channels/channel_host_state.h"
#include "uia/forward_ptrs.h"

class byte_array;

namespace uia {
namespace comm {

class socket_endpoint;

/**
 * Abstract base class for packet receivers.
 * Provides support to receive messages for registered types.
 */
class packet_receiver : public std::enable_shared_from_this<packet_receiver>
{
    host_ptr host_{nullptr};
    packet_magic_t magic_{0};

protected:
    inline packet_receiver(host_ptr hi)
        : host_(hi)
    {
    }

    inline packet_receiver(host_ptr hi, packet_magic_t magic)
        : host_(hi)
    {
        bind(magic);
    }

    inline ~packet_receiver() { unbind(); }

    inline packet_magic_t magic() const { return magic_; }

    inline bool is_bound() const { return magic_ != 0; }

public:
    void bind(packet_magic_t magic);
    void unbind();

    /**
     * Socket calls this method to dispatch packets.
     * @param msg Data packet.
     * @param src Origin endpoint.
     */
    virtual void receive(boost::asio::const_buffer msg, socket_endpoint src) = 0;
};

} // comm namespace
} // uia namespace
