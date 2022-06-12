cmake_minimum_required ( VERSION 3.20 )

project( testprj )
set ( foo "HELLO World" )
set ( bar HELLO World )
message ( STATUS "foo=${foo}" )
message ( STATUS "bar=${bar}" )
add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    LOWER_CASE:HAHA = $<LOWER_CASE:HAHA> &
    echo
    LOWER_CASE:String = $<LOWER_CASE:String> &
    echo
    LOWER_CASE:${foo} = $<LOWER_CASE:${foo}>
)