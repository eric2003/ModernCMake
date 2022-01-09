cmake_minimum_required(VERSION 3.5)

project(mytest LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 REQUIRED)

message ( STATUS "Catch2_FOUND      = ${Catch2_FOUND}" )
add_executable(foo test.cpp)
target_link_libraries(foo PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(foo)
