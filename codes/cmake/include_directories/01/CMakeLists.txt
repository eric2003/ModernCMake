cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

include_directories(sub1)
include_directories(sub2)

get_property( dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES )

foreach( dir ${dirs} )
    message( STATUS "include dir=${dir}" )
endforeach()