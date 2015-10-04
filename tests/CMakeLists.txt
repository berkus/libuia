create_test(identity LIBS uia arsenal sodiumpp)

# These need a way to limit io_service run time (or a way to cancel async_receive_from).
create_test(udp_socket LIBS sss uia arsenal sodiumpp NO_CTEST)
create_test(run_udp_receiver LIBS sss uia arsenal routing sodiumpp NO_CTEST)
