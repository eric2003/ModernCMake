cmake_minimum_required ( VERSION 3.15 )

project( testprj )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = " $<PLATFORM_ID> "; " 
    "CONFIG = " $<CONFIG>
)