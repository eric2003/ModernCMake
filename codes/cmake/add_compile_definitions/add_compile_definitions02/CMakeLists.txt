cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_compile_definitions(Haha1 Haha2)
get_directory_property( MyDef DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_DEFINITIONS )
foreach( d ${MyDef} )
    message( STATUS "Found Define: " ${d} )
endforeach()
message( STATUS "MyDef: " ${MyDef} )