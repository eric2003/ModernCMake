cmake_minimum_required ( VERSION 3.20 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = $<PLATFORM_ID>" 
    "<CONFIG> = " $<CONFIG>

)