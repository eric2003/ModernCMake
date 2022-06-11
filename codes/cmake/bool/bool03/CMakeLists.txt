cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

message ( STATUS "SHARED=${SHARED}" )

set ( SHARED FALSE CACHE BOOL "build a shared library" )

message ( STATUS "SHARED=${SHARED}" )
message ( STATUS "TTT=${TTT}" )

if ( TTT )
  message ( STATUS "TTT=${TTT} 0000" )
else()
  message ( STATUS "TTT=${TTT} 1111" )
endif()