cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    CONFIG = $<CONFIG> &
    echo 
    PLATFORM_ID:Windows = $<PLATFORM_ID:Windows> &
    echo 
    PLATFORM_ID:Cygwin = $<PLATFORM_ID:Cygwin> &
    echo 
    OR:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin> = $<OR:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin>> &
    echo 
    AND:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin> = $<AND:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin>>
)
