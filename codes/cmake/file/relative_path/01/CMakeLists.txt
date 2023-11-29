cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message ( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )

file ( RELATIVE_PATH relPath1 ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
file ( RELATIVE_PATH relPath2 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
file ( RELATIVE_PATH relPath3 ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )

message ( STATUS "relPath1 = ${relPath1}" )
message ( STATUS "relPath2 = ${relPath2}" )
message ( STATUS "relPath3 = ${relPath3}" )
