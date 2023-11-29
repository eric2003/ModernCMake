cmake_minimum_required(VERSION 3.28)

project(testprj)

file ( TOUCH_NOCREATE  "${CMAKE_BINARY_DIR}/a.txt" )
