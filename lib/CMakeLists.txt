set(platform_SOURCES)
if (UNIX)
    list(APPEND platform_SOURCES
        comm/platform-unix.cpp)
endif()
if (WIN32)
    list(APPEND platform_SOURCES
        comm/platform-win.cpp)
endif()

set(comm_SOURCES
    comm/socket.cpp
    comm/udp_socket.cpp
    comm/socket_endpoint.cpp
    comm/packet_receiver.cpp
    comm/socket_host_state.cpp
    )

set(kex_SOURCES
    negotiation/channel_initiator.cpp
    negotiation/initiator.cpp
    negotiation/responder.cpp
    negotiation/kex_host_state.cpp
    )

add_library(uia STATIC
    host.cpp
    peer_identity.cpp
    peer.cpp
    channels/socket_channel.cpp
    timer.cpp
    asio_host_state.cpp
    ${comm_SOURCES}
    ${platform_SOURCES}
    ${kex_SOURCES})
