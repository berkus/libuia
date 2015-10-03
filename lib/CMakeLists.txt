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
    )

add_library(uia STATIC
    peer_identity.cpp
    ${comm_SOURCES}
    ${platform_SOURCES})
