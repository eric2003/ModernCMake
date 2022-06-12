cmake_minimum_required ( VERSION 3.20 )

project( testprj )
set ( foo hello )
add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    UPPER_CASE:haha = $<UPPER_CASE:haha> &
    echo
    UPPER_CASE:string = $<UPPER_CASE:string> &
    echo
    UPPER_CASE:${foo} = $<UPPER_CASE:${foo}>
)