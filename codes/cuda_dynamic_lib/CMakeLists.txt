cmake_minimum_required ( VERSION 3.15 )

#set ( CMAKE_VERBOSE_MAKEFILE ON )

project ( test )

find_package ( CUDAToolkit )
if ( CUDAToolkit_FOUND )
	enable_language( CUDA )
endif ()

set ( CMAKE_CUDA_ARCHITECTURES "35;50;52;72;75" )

add_library( cuda_lib SHARED 
    cuda_lib.cu
)

target_compile_definitions ( cuda_lib
	PRIVATE
		BUILD_DLL
)

add_executable( test
    main.cpp
)

target_compile_definitions ( test
	PRIVATE
		USE_DLL
)

target_link_libraries( test
    PRIVATE 
        cuda_lib
)