cmake_minimum_required ( VERSION 3.15 )

project ( HybridMPICudaOpenAccOpenMP_Prj )

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

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -fast -acc -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )

message ( STATUS "CMAKE_SYSTEM_NAME    = ${CMAKE_SYSTEM_NAME}" )
if ( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
	find_package ( MPI )
else()
	find_package ( MPI )
	message ( STATUS "MPI_INCLUDE_DIRS  = ${MPI_INCLUDE_DIRS}" )
	message ( STATUS "MPI_C_INCLUDE_DIRS  = ${MPI_C_INCLUDE_DIRS}" )
	message ( STATUS "MPI_CXX_INCLUDE_DIRS  = ${MPI_CXX_INCLUDE_DIRS}" )
	message ( STATUS "MPI_LIBRARIES  = ${MPI_LIBRARIES}" )
endif()

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

add_library( cuda_static_lib STATIC
    cuda_sub.cu
)

add_executable( test
    myopenacc.cpp
	main.cpp
)

target_compile_definitions ( test
	PRIVATE
		USE_DLL
)

target_include_directories ( test
	PRIVATE
		${MPI_CXX_INCLUDE_DIRS}
)

target_link_libraries( test
    PRIVATE 
        cuda_lib
		${OpenMP_CXX_LIBRARIES}
		${MPI_LIBRARIES}
)

add_executable( test_static
    myopenacc.cpp
	main.cpp
)

target_include_directories ( test_static
	PRIVATE
		${MPI_CXX_INCLUDE_DIRS}
)

target_link_libraries( test_static
    PRIVATE 
        cuda_static_lib
		${OpenMP_CXX_LIBRARIES}
		${MPI_LIBRARIES}
)
