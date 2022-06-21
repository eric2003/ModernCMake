cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_link_options(bar1 bar2)
get_directory_property( MyBar DIRECTORY ${CMAKE_SOURCE_DIR} LINK_OPTIONS )

foreach( d ${MyBar} )
    message( STATUS "Found LINK_OPTIONS: " ${d} )
endforeach()

message( STATUS "MyBar: " ${MyBar} )

include_directories(sub1)
include_directories(sub2)

get_property( dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES )
message( STATUS "dirs= ${dirs}" )
foreach(dir ${dirs})
    message( STATUS "dir='${dir}'" )
endforeach()