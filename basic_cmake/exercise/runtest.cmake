set(INPUT_VAR 3)
execute_process(COMMAND ${TEST_PROG} ${INPUT_VAR}
                RESULT_VARIABLE HAD_ERROR)

message("execute process ${HAD_ERROR}")

if(HAD_ERROR)
    message(FATAL_ERROR "Test failed")
endif()

#set(CMAKE_COMMAND "${CMAKE_COMMAND} 3")
message("command ${CMAKE_COMMAND}")
execute_process(COMMAND ${CMAKE_COMMAND} -E compare_files
    output.txt ${SOURCEDIR}/expected.txt
    RESULT_VARIABLE DIFFERENT)

message("result variable ${DIFFERENT}")

if(DIFFERENT)
    message(FATAL_ERROR "Test failed - files differ")
endif()
