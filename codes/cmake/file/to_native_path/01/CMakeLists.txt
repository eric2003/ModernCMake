cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message ( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )

file ( TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" nvar1 )
file ( TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}" nvar2 )

message ( STATUS "nvar1 = ${nvar1}" )
message ( STATUS "nvar2 = ${nvar2}" )
