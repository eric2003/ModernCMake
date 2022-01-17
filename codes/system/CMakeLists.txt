cmake_minimum_required(VERSION 3.15)

project ( test )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_COMPILE_DEFINITIONS )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

if ( CMAKE_SYSTEM_NAME MATCHES "Windows" )
	list ( APPEND PRJ_COMPILE_DEFINITIONS WINDOWS_SYS )
endif()

add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)

target_compile_definitions ( ${PROJECT_NAME}
	PRIVATE
	   ${PRJ_COMPILE_DEFINITIONS} 
)
