cmake_minimum_required ( VERSION 3.28 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

set ( foo NO )
set ( bar YES )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    PLATFORM_ID = $<PLATFORM_ID> &
    echo 
    BOOL:${foo} = $<BOOL:${foo}> &
    echo 
    BOOL:${bar} = $<BOOL:${bar}> &
    echo
    BOOL:foo:contents =  $<$<BOOL:${foo}>:contents> & 
    echo
    BOOL:bar:contents =  $<$<BOOL:${bar}>:contents> & 
)