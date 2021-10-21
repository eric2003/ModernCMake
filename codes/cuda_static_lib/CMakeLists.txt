cmake_minimum_required(VERSION 3.15)
set ( CMAKE_VERBOSE_MAKEFILE ON )

project ( test )

find_package ( CUDAToolkit )
if ( CUDAToolkit_FOUND )
	enable_language( CUDA )
endif ()

set ( CMAKE_CUDA_ARCHITECTURES "35;50;52;72;75" )

add_library( cuda_lib STATIC 
    cuda_lib.cu
)

add_executable( test
    main.cpp
)

target_link_libraries( test
    PRIVATE 
        cuda_lib
)