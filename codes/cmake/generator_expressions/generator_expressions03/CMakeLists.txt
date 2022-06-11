cmake_minimum_required ( VERSION 3.15 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

set ( a1 1 )
#set ( a2 1 )
set ( a2 0 )
set ( a3 1 )
set ( foo_conditions ${a1},${a2},${a3} )

message ( STATUS "a1 = ${a1}" )
message ( STATUS "a2 = ${a2}" )
message ( STATUS "a3 = ${a3}" )
message ( STATUS "foo_conditions = ${foo_conditions}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = $<PLATFORM_ID>" 
    "foo_conditions = $<AND:${foo_conditions}>"
)