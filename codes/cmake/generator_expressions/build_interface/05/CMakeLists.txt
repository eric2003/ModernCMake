cmake_minimum_required ( VERSION 3.20 )

project( testprj )

add_custom_target ( myprint 
    COMMAND
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
    AND:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin> = $<AND:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin>> &
    echo 
    1:a = $<1:a> &
    echo 
    0:a = $<0:a> &
    echo 
    BUILD_INTERFACE:a = $<BUILD_INTERFACE:a> &
    echo 
    INSTALL_INTERFACE:a = $<INSTALL_INTERFACE:a>
)