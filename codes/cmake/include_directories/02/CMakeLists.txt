cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

include_directories(sub1)
include_directories(sub2)

get_property( dirs1 DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES )
get_property( dirs2 DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} PROPERTY INCLUDE_DIRECTORIES )

foreach( dir ${dirs1} )
    message( STATUS "include 1 dir=${dir}" )
endforeach()

foreach( dir ${dirs2} )
    message( STATUS "include 2 dir=${dir}" )
endforeach()