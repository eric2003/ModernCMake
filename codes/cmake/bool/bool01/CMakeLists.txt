cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( SHARED FALSE CACHE BOOL "build a shared library" )

message ( STATUS "SHARED=${SHARED}" )