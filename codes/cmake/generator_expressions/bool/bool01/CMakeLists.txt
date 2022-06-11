cmake_minimum_required ( VERSION 3.15 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

set ( foo YES )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = $<PLATFORM_ID>" 
    "BOOL:foo:contents = " $<$<BOOL:${foo}>:contents>  

)