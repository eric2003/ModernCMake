cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

message ( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE} " )
set ( EXE_POSTFIX )
if ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set ( EXE_POSTFIX "_d")
else ()
    message ( STATUS "else CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE} " )
endif ()


list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)
get_target_property ( my_debug_postfix ${PROJECT_NAME} DEBUG_POSTFIX )

message ( STATUS "my_debug_postfix = ${my_debug_postfix} " )
