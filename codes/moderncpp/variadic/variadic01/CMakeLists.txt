cmake_minimum_required(VERSION 3.15)

project ( testprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_COMPILE_DEFINITIONS )

message ( STATUS "MSVC      = ${MSVC}" )

if ( MSVC )
    list ( APPEND PRJ_COMPILE_DEFINITIONS USE_MSVC )
endif()

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable( ${PROJECT_NAME}
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