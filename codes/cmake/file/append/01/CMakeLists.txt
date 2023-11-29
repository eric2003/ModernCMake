cmake_minimum_required(VERSION 3.28)

project(testprj)

file ( APPEND "${CMAKE_BINARY_DIR}/a.txt"
      "haha\n"
)
