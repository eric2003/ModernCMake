cmake_minimum_required(VERSION 3.21)

set( ENV{MYTMPVAR} "Ninja1")
set( CMAKE_GENERATOR "Ninja" )
set( ENV{CMAKE_GENERATOR} "Ninja" )
#set( ENV{CMAKE_GENERATOR} "Visual Studio 17 2022")
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "ENV MYTMPVAR =  $ENV{MYTMPVAR}" )
message( STATUS "ENV CMAKE_GENERATOR =  $ENV{CMAKE_GENERATOR}" )
#set( CMAKE_GENERATOR "Visual Studio 17 2022" )
set( CMAKE_GENERATOR "Ninja" )
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
#set( ENV{PATH} "/home/martink")

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

message( STATUS "After set command: CMAKE_C_COMPILER_ID = ${CMAKE_C_COMPILER_ID}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" )

message( STATUS "After set command: CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}" )
message( STATUS "After set command: CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}" )
message( STATUS "After set command: CMAKE_VS_DEVENV_COMMAND = ${CMAKE_VS_DEVENV_COMMAND}" )
message( STATUS "After set command: CMAKE_VS_MSBUILD_COMMAND = ${CMAKE_VS_MSBUILD_COMMAND}" )
message( STATUS "After set command: CMAKE_VERBOSE_MAKEFILE = ${CMAKE_VERBOSE_MAKEFILE}" )

message( STATUS "CMAKE_ROOT = ${CMAKE_ROOT}" )
message( STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}" )
message( STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}" )
message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "CMAKE_GENERATOR_PLATFORM = ${CMAKE_GENERATOR_PLATFORM}" )
message( STATUS "CMAKE_GENERATOR_TOOLSET = ${CMAKE_GENERATOR_TOOLSET}" )
message( STATUS "CMAKE_GENERATOR_INSTANCE = ${CMAKE_GENERATOR_INSTANCE}" )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
