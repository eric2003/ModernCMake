cmake_minimum_required ( VERSION 3.20 )

project( testprj )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    PLATFORM_ID = $<PLATFORM_ID> &
    echo
    CONFIG = $<CONFIG>
)

add_custom_target ( myprint 
    COMMAND
    ${CMAKE_COMMAND} -E 
    echo
    PLATFORM_ID = $<PLATFORM_ID> &
    echo
    CONFIG = $<CONFIG>
)