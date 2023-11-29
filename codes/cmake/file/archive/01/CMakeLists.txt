cmake_minimum_required(VERSION 3.28)

project(testprj)

set ( output_archive ${CMAKE_BINARY_DIR}/my_archive.tar )

file ( ARCHIVE_CREATE
  OUTPUT ${output_archive}
  PATHS  ${CMAKE_SOURCE_DIR}/1.txt
  PATHS  ${CMAKE_SOURCE_DIR}/2.txt
  PATHS  ${CMAKE_SOURCE_DIR}/3.txt
)
