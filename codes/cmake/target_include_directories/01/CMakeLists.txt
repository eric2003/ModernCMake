cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_link_options(bar1 bar2)
get_directory_property( MyBar DIRECTORY ${CMAKE_SOURCE_DIR} LINK_OPTIONS )

foreach( d ${MyBar} )
    message( STATUS "Found LINK_OPTIONS: " ${d} )
endforeach()

message( STATUS "MyBar: " ${MyBar} )