cmake_minimum_required(VERSION 3.15)

project(testprj LANGUAGES CXX)
find_package(hello CONFIG REQUIRED)

message("hello_DIR: ${hello_DIR}")
message("hello_INCLUDE_DIR: ${hello_INCLUDE_DIR}")

include_directories(${hello_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} hello::hello)