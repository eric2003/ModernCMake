cmake_minimum_required(VERSION 3.15)

project ( test )

set ( PRJ_COMPILE_FEATURES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

if ( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
	set ( MY_CXX_FLAGS )
else()
	set ( MY_CXX_FLAGS "-fcoroutines -pthread" )
endif()

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}" )
#message ( STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}" )
	
add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
