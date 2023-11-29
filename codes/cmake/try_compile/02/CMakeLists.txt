cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

message ( STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}" )
message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )

try_compile(COMPILE_SUCCEEDED
    ${CMAKE_BINARY_DIR}/test_compile
    ${CMAKE_CURRENT_SOURCE_DIR}/test_compile.cpp
    OUTPUT_VARIABLE _output
)

message ( STATUS "_output = ${_output}" )

if(COMPILE_SUCCEEDED)
    message("Compilation succeeded!")
else()
    message("Compilation failed!")
endif()

