cmake_minimum_required ( VERSION 3.28 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

set ( HAVE_SOME_FEATURE YES )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    BOOL:{HAVE_SOME_FEATURE} = $<BOOL:${HAVE_SOME_FEATURE}> &
    echo
    BOOL:{HAVE_SOME_FEATURE}=  $<$<BOOL:${HAVE_SOME_FEATURE}>:-DENABLE_SOME_FEATURE>
)