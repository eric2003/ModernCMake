cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}" )
message ( STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}" )

file ( REAL_PATH main.cpp var1 )
file ( REAL_PATH ../main.cpp var2 )

message ( STATUS "var1 = ${var1}" )
message ( STATUS "var2 = ${var2}" )
