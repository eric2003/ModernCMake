cmake_minimum_required ( VERSION 3.20 )

project( testprj )

file( GENERATE
    OUTPUT "my_$<CONFIG>.log"
    CONTENT
"PLATFORM_ID = $<PLATFORM_ID>
CONFIG = $<CONFIG>
BUILD_INTERFACE:a = $<BUILD_INTERFACE:a>
INSTALL_INTERFACE:a = $<INSTALL_INTERFACE:a>
"
)