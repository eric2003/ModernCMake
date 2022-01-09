cmake_minimum_required(VERSION 3.5)

project(mytest LANGUAGES CXX VERSION 0.0.1)
set ( PRJ_INCLUDE_DIRS ../ )
add_executable(${PROJECT_NAME} test.cpp)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)