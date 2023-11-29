cmake_minimum_required(VERSION 3.28)

project(testprj)

file ( TOUCH  "${CMAKE_BINARY_DIR}/a.txt" )
file ( TOUCH  "${CMAKE_BINARY_DIR}/b.txt" )
file ( TOUCH  "${CMAKE_BINARY_DIR}/c.txt" )

file ( REMOVE "${CMAKE_BINARY_DIR}/b.txt" )

