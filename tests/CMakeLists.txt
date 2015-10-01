create_test(identity LIBS uia arsenal ${OPENSSL_LIBRARIES})

# These need a way to limit io_service run time (or a way to cancel async_receive_from).
create_test(udp_socket LIBS sss uia arsenal ${OPENSSL_LIBRARIES} NO_CTEST)
create_test(run_udp_receiver LIBS sss uia arsenal routing ${OPENSSL_LIBRARIES} NO_CTEST)
