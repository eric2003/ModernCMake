cmake_minimum_required ( VERSION 3.15 )

project ( test )

set ( CMAKE_VERBOSE_MAKEFILE ON )

find_package ( OpenACC )

message ( STATUS "OpenACC_FOUND      = ${OpenACC_FOUND}" )
message ( STATUS "OpenACC_C_FOUND    = ${OpenACC_C_FOUND}" )
message ( STATUS "OpenACC_CXX_FOUND  = ${OpenACC_CXX_FOUND}" )

find_package ( OpenMP )
if ( OpenMP_FOUND )
	message ( STATUS "OpenMP_CXX_INCLUDE_DIRS  = ${OpenMP_CXX_INCLUDE_DIRS}" )
	message ( STATUS "OpenMP_CXX_LIBRARIES  = ${OpenMP_CXX_LIBRARIES}" )
	message ( STATUS "OpenMP_CXX_FLAGS  = ${OpenMP_CXX_FLAGS}" )
endif ()
#set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fast -acc -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -fast -acc -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )
#set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}" )

find_package ( CUDAToolkit )
if ( CUDAToolkit_FOUND )
	enable_language( CUDA )
endif ()

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CUDA_STANDARD 14 )
set ( CMAKE_CUDA_ARCHITECTURES "35;50;52;72;75" )

add_library( cuda_lib SHARED 
    cuda_sub.cu
)

target_compile_definitions ( cuda_lib
	PRIVATE
		BUILD_DLL
)

add_executable( test
    myopenacc.cpp
	main.cpp
)

target_compile_definitions ( test
	PRIVATE
		USE_DLL
)

target_link_libraries( test
    PRIVATE 
        cuda_lib
		${OpenMP_CXX_LIBRARIES}
)