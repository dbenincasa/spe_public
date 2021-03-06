execute_process(COMMAND ${TEST_PROG}
                RESULT_VARIABLE HAD_ERROR)

message("result variable ${HAD_ERROR}")

if(HAD_ERROR)
    message(FATAL_ERROR "Test failed")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} -E compare_files
    output.txt ${SOURCEDIR}/expected.txt
    RESULT_VARIABLE DIFFERENT)

message("result variable ${DIFFERENT}")

if(DIFFERENT)
    message(FATAL_ERROR "Test failed - files differ")
endif()
