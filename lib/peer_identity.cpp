//
// Part of Metta OS. Check http://atta-metta.net for latest version.
//
// Copyright 2007 - 2014, Stanislav Karchebnyy <berkus@atta-metta.net>
//
// Distributed under the Boost Software License, Version 1.0.
// (See file LICENSE_1_0.txt or a copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "uia/peer_identity.h"
#include "arsenal/logging.h"
#include "arsenal/settings_provider.h"

using namespace std;

namespace uia {

//=================================================================================================
// identity
//=================================================================================================

peer_identity::peer_identity(byte_array const& id)
    : id_(id.as_string())
{
}

peer_identity::peer_identity(byte_array const& id, byte_array const& key)
    : id_(id.as_string())
{
    if (!set_key(key)) {
        throw bad_key();
    }
}

void
peer_identity::clear_key()
{
    private_key_.clear();
}

bool
peer_identity::set_key(byte_array const& key)
{
    clear_key();

    private_key_ = key.as_string();

    // Verify that the supplied key actually matches the ID we have.
    // *** This is a crucial step for security! ***
    // byte_array key_id = key_->id();
    // key_id[0] = (key_id[0] & 7) | (ksch << 3); // replace top 5 bits of ID with scheme used

    // if (key_id != id_)
    // {
    //     clear_key();
    //     logger::warning() << "Attempt to set mismatching identity key!";
    return false;
    // }

    // return true;
}

peer_identity
peer_identity::generate()
{
    // shared_ptr<crypto::sign_key> key{nullptr};
    // switch (sch) {
    //     case dsa160:
    //         logger::debug() << "Generating new DSA160 sign key";
    //         key = make_shared<crypto::dsa160_key>(bits);
    //         break;
    //     case rsa160:
    //         logger::debug() << "Generating new RSA160 sign key";
    //         key = make_shared<crypto::rsa160_key>(bits);
    //         break;
    //     default:
    //         logger::fatal() << "Unsupported signing scheme " << sch;
    // }

    // byte_array id = key->id();
    // id[0] = (id[0] & 7) | (sch << 3); // replace top 5 bits of ID with scheme used
    // logger::debug() << "Generated key id " << id;

    // identity ident(id);
    // ident.key_ = key;

    return peer_identity(byte_array("blablab"));
}

byte_array
peer_identity::public_key() const
{
    if (id_.empty())
        return byte_array();
    return id_;
}

byte_array
peer_identity::secret_key() const
{
    if (private_key_.empty())
        return byte_array();
    return private_key_;
}

//=================================================================================================
// identity_host_state
//=================================================================================================

peer_identity
identity_host_state::host_identity()
{
    if (!host_identity_.has_private_key()) {
        host_identity_ = peer_identity::generate();
    }
    return host_identity_;
}

void
identity_host_state::set_host_identity(peer_identity const& ident)
{
    if (!ident.has_private_key()) {
        logger::warning() << "Using a host identity with no private key!";
    }
    host_identity_ = ident;
}

void
identity_host_state::init_identity(settings_provider* settings)
{
    if (host_identity_.has_private_key())
        return; // Already initialized.

    if (!settings) {
        host_identity(); // No persistence available.
        return;
    }

    // Find and decode the host's existing key, if any.
    byte_array id  = settings->get_byte_array("id");
    byte_array key = settings->get_byte_array("key");

    if (!id.is_empty() and !key.is_empty()) {
        host_identity_.set_id(id);
        if (host_identity_.set_key(key) and host_identity_.has_private_key())
            return; // Success
    }

    logger::warning() << "Invalid host identity in settings: generating new identity";

    // Generate a new key pair
    host_identity_ = peer_identity::generate();

    // Save it in our host settings
    settings->set("id", host_identity_.id().as_vector());
    settings->set("key", host_identity_.secret_key().as_vector());
    settings->sync();
}

} // uia namespace
