cmake_minimum_required(VERSION 3.15)

project ( testprj )

set ( foo_conditions )
set ( a1 1 )
#set ( a2 1 )
set ( a2 0 )
set ( a3 1 )
list ( APPEND foo_conditions ${a1} )
list ( APPEND foo_conditions ${a2} )
list ( APPEND foo_conditions ${a3} )

message ( STATUS "a1 = ${a1}" )
message ( STATUS "a2 = ${a2}" )
message ( STATUS "a3 = ${a3}" )
message ( STATUS "foo_conditions = ${foo_conditions}" )
string ( REPLACE ";" "," foo_conditions "${foo_conditions}" )
message ( STATUS "foo_conditions = ${foo_conditions}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = $<PLATFORM_ID>" 
    "foo and = $<AND:${foo_conditions}>"
    "foo or = $<OR:${foo_conditions}>"
)
