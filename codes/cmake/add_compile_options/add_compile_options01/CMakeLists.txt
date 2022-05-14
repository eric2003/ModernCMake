cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_compile_options(foo1 foo2)
get_directory_property( MyFoo DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_OPTIONS )

foreach( d ${MyFoo} )
    message( STATUS "Found COMPILE_OPTIONS: " ${d} )
endforeach()

message( STATUS "MyFoo: " ${MyFoo} )