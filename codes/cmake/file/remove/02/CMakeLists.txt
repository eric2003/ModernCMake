cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}" )

file ( REMOVE "${CMAKE_SOURCE_DIR}/tmp/*.*" )
file ( REMOVE "${CMAKE_SOURCE_DIR}/tmp/a.txt" )


