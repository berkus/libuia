//
// Part of Metta OS. Check http://atta-metta.net for latest version.
//
// Copyright 2007 - 2015, Stanislav Karchebnyy <berkus@atta-metta.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include <unordered_set>
#include <list>
#include "uia/comm/socket_endpoint.h"

namespace uia {
namespace comm {

/**
 * A set of endpoints with additional methods to calculate endpoint distance metrics.
 */
class endpoint_set : public std::unordered_set<uia::comm::endpoint>
{
    using super = std::unordered_set<uia::comm::endpoint>;

public:
    endpoint_set() : super() {}
    endpoint_set(std::initializer_list<uia::comm::endpoint> x) : super(x) {}

    /**
     * Return endpoints in the set sorted by affinity XOR-metric to given address @c other.
     */
    std::list<endpoint> affinity_sorted_to(const uia::comm::endpoint other);
};

} // comm namespace
} // uia namespace
