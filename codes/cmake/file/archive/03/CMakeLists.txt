cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message ( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )

set ( my_archive ${CMAKE_CURRENT_SOURCE_DIR}/my_archive.tar )

file ( ARCHIVE_EXTRACT 
  INPUT ${my_archive}
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tmp
  #LIST_ONLY
  VERBOSE
)
