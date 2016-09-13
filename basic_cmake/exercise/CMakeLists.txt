cmake_minimum_required(VERSION 2.6)
project (mat_mul C CXX Fortran)

option(USEBLAS "use blas" ON)

add_executable(mat_mul main.c matmul.F90)

enable_testing()
add_test(NAME runtestprog
    COMMAND ${CMAKE_COMMAND}
    -DTEST_PROG=$<TARGET_FILE:mat_mul>
    -DSOURCEDIR=${CMAKE_CURRENT_SOURCE_DIR}
    -P ${CMAKE_CURRENT_SOURCE_DIR}/runtest.cmake)
