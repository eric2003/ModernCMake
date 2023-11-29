cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message ( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )

set ( output_archive ${CMAKE_BINARY_DIR}/my_archive.tar )
set ( my_archive ${CMAKE_CURRENT_SOURCE_DIR}/my_archive.tar )

#file ( ARCHIVE_CREATE
#  OUTPUT ${output_archive}
#  PATHS  ${CMAKE_SOURCE_DIR}/1.txt
#  PATHS  ${CMAKE_SOURCE_DIR}/2.txt
#  PATHS  ${CMAKE_SOURCE_DIR}/3.txt
#)


file ( ARCHIVE_EXTRACT 
  INPUT ${my_archive}
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
  #LIST_ONLY
  VERBOSE
)
