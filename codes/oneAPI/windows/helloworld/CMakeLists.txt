cmake_minimum_required(VERSION 3.15)

message( STATUS "Before project command: CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}" )
message( STATUS "Before project command: CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" )

message( STATUS "Before project command: CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}" )
message( STATUS "Before project command: CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}" )
message( STATUS "Before project command: CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}" )

message( STATUS "Before project command: CMAKE_VS_DEVENV_COMMAND = ${CMAKE_VS_DEVENV_COMMAND}" )
message( STATUS "Before project command: CMAKE_VS_MSBUILD_COMMAND = ${CMAKE_VS_MSBUILD_COMMAND}" )

project ( test )

set ( CMAKE_VERBOSE_MAKEFILE TRUE )

message( STATUS "After project command: CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}" )
message( STATUS "After project command: CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" )

message( STATUS "After project command: CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}" )
message( STATUS "After project command: CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}" )
message( STATUS "After project command: CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}" )
message( STATUS "After project command: CMAKE_VS_DEVENV_COMMAND = ${CMAKE_VS_DEVENV_COMMAND}" )
message( STATUS "After project command: CMAKE_VS_MSBUILD_COMMAND = ${CMAKE_VS_MSBUILD_COMMAND}" )


set ( PRJ_COMPILE_FEATURES )

#set( CMAKE_C_COMPILER icx )
#set( CMAKE_CXX_COMPILER icx )

#set( CMAKE_CXX_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/clll.exe" )

message( STATUS "After set command: CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" )

message( STATUS "After set command: CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}" )
message( STATUS "After set command: CMAKE_VS_DEVENV_COMMAND = ${CMAKE_VS_DEVENV_COMMAND}" )
message( STATUS "After set command: CMAKE_VS_MSBUILD_COMMAND = ${CMAKE_VS_MSBUILD_COMMAND}" )
message( STATUS "After set command: CMAKE_VERBOSE_MAKEFILE = ${CMAKE_VERBOSE_MAKEFILE}" )


list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
