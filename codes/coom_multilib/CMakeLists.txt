cmake_minimum_required ( VERSION 3.15 )

project ( HybridMPICudaOpenAccOpenMP_Prj C CXX )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_LIBRARIES )
set ( PRJ_STATIC_LIBS )
set ( PRJ_COMPILE_DEF )

find_package ( CUDAToolkit )
find_package ( OpenACC )

message ( STATUS "OpenACC_FOUND      = ${OpenACC_FOUND}" )
message ( STATUS "OpenACC_C_FOUND    = ${OpenACC_C_FOUND}" )
message ( STATUS "OpenACC_CXX_FOUND  = ${OpenACC_CXX_FOUND}" )
if ( OpenACC_CXX_FOUND )
	list ( APPEND PRJ_COMPILE_DEF ENABLE_OPENACC )
	message ( STATUS "ENV{NVCC_COMPILER}  = $ENV{NVCC_COMPILER}" )
	if ( $ENV{NVCC_COMPILER} MATCHES "NVCC_COMPILER" )
		#set ( OpenACC_CXX_FLAGS "${OpenACC_CXX_FLAGS} -fast -acc -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )	
		set( ACC_FLAG "-fast -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )
	else()
		set( ACC_FLAG "-Ofast" )
	endif()
	if ( CUDAToolkit_FOUND )
		set ( OpenACC_CXX_FLAGS "${OpenACC_CXX_FLAGS} ${ACC_FLAG}" )
	else ()
		set ( OpenACC_CXX_FLAGS "${OpenACC_CXX_FLAGS} ${ACC_FLAG} -foffload=disable" )
	endif()	
endif ()

find_package ( OpenMP )
if ( OpenMP_FOUND )
	message ( STATUS "OpenMP_CXX_INCLUDE_DIRS  = ${OpenMP_CXX_INCLUDE_DIRS}" )
	message ( STATUS "OpenMP_CXX_LIBRARIES  = ${OpenMP_CXX_LIBRARIES}" )
	message ( STATUS "OpenMP_CXX_FLAGS  = ${OpenMP_CXX_FLAGS}" )
	list ( APPEND PRJ_COMPILE_DEF ENABLE_OPENMP )
	list ( APPEND PRJ_LIBRARIES ${OpenMP_CXX_LIBRARIES} )
	list ( APPEND PRJ_STATIC_LIBS ${OpenMP_CXX_LIBRARIES} )
endif ()

#set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -fast -acc -Minfo=accel -gpu=cc60,cc70,cc75,cc80" )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} ${OpenACC_CXX_FLAGS}" )

#message ( STATUS "CMAKE_SYSTEM_NAME    = ${CMAKE_SYSTEM_NAME}" )

find_package ( MPI )

message ( STATUS "MPI_FOUND  = ${MPI_FOUND}" )
message ( STATUS "MPI_C_FOUND  = ${MPI_C_FOUND}" )
message ( STATUS "MPI_CXX_FOUND  = ${MPI_CXX_FOUND}" )
message ( STATUS "MPI_INCLUDE_DIRS  = ${MPI_INCLUDE_DIRS}" )
message ( STATUS "MPI_C_INCLUDE_DIRS  = ${MPI_C_INCLUDE_DIRS}" )
message ( STATUS "MPI_CXX_INCLUDE_DIRS  = ${MPI_CXX_INCLUDE_DIRS}" )
message ( STATUS "MPI_LIBRARIES  = ${MPI_LIBRARIES}" )

if ( MPI_C_FOUND )
	list ( APPEND PRJ_LIBRARIES ${MPI_LIBRARIES} )
	list ( APPEND PRJ_STATIC_LIBS ${MPI_LIBRARIES} )
endif ()

#find_package ( CUDAToolkit )
if ( CUDAToolkit_FOUND )
	list ( APPEND PRJ_COMPILE_DEF ENABLE_CUDA )
	enable_language( CUDA )
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
	list ( APPEND PRJ_LIBRARIES cuda_lib )
	list ( APPEND PRJ_STATIC_LIBS cuda_static_lib )
endif ()

set ( CMAKE_CXX_STANDARD 17 )


add_executable( test
    myopenacc.cpp
	main.cpp
)

target_compile_definitions ( test
	PRIVATE
		USE_DLL
		${PRJ_COMPILE_DEF}
)

target_include_directories ( test
	PRIVATE
		${MPI_CXX_INCLUDE_DIRS}
)

target_link_libraries( test
    PRIVATE 
        ${PRJ_LIBRARIES}
		#${OpenMP_CXX_LIBRARIES}
		#${MPI_LIBRARIES}
)

add_executable( test_static
    myopenacc.cpp
	main.cpp
)

target_include_directories ( test_static
	PRIVATE
		${MPI_CXX_INCLUDE_DIRS}
)

target_compile_definitions ( test_static
	PRIVATE
		${PRJ_COMPILE_DEF}
)

target_link_libraries( test_static
    PRIVATE 
        ${PRJ_STATIC_LIBS}
		#${OpenMP_CXX_LIBRARIES}
		#${MPI_LIBRARIES}
)
