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

#set_target_properties ( myTarget PROPERTIES DEBUG_POSTFIX _d )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )
set( exeName "${PROJECT_NAME}${EXE_POSTFIX}" )
message ( STATUS "exeName = ${exeName} " )
add_executable ( ${exeName}
    main.cpp
)

target_include_directories ( ${exeName}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${exeName} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${exeName} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)
get_target_property ( mypostfix ${exeName} DEBUG_POSTFIX )
get_target_property ( myaaa ${exeName} AAA )

message ( STATUS "mypostfix = ${mypostfix} " )
message ( STATUS "myaaa = ${myaaa} " )