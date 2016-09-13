cmake_minimum_required(VERSION 2.6)
project (hello_world)
add_executable(hello_world main.c)

enable_testing()
add_test(NAME runtestprog
    COMMAND ${CMAKE_COMMAND}
    -DTEST_PROG=$<TARGET_FILE:hello_world>
    -DSOURCEDIR=${CMAKE_CURRENT_SOURCE_DIR}
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtest.cmake)
