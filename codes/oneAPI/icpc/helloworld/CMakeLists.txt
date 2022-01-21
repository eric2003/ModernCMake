cmake_minimum_required(VERSION 3.15)

project ( test )

set ( PRJ_COMPILE_FEATURES )

set(CMAKE_C_COMPILER icc)
set(CMAKE_CXX_COMPILER icpc)

message( STATUS "CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}" )
message( STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}" )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
