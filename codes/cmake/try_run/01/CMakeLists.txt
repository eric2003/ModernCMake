cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

message ( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )
message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )

try_run(
    # Name of variable to store the run result (process exit status; number) in:
    test_run_result

    # Name of variable to store the compile result (TRUE or FALSE) in:
    test_compile_result

    # Binary directory:
    ${CMAKE_CURRENT_BINARY_DIR}/test_run

    # Source file to be compiled:
    ${CMAKE_CURRENT_SOURCE_DIR}/test_compile.cpp

    # Where to store the output produced during compilation:
    COMPILE_OUTPUT_VARIABLE test_compile_output

    # Where to store the output produced by running the compiled executable:
    RUN_OUTPUT_VARIABLE test_run_output
)

message ( STATUS "test_run_result = ${test_run_result}" )
message ( STATUS "test_compile_result = ${test_compile_result}" )
message ( STATUS "test_compile_output = ${test_compile_output}" )
message ( STATUS "test_run_output = ${test_run_output}" )
