cmake_minimum_required ( VERSION 3.20 )

project( testprj )

set ( foo "HELLO World" )
set ( bar HELLO World )
set ( s abc )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    foo = ${foo} &
    echo
    bar = ${bar} &
    echo
    JOIN:foo,s = $<JOIN:${foo},${s}>
)