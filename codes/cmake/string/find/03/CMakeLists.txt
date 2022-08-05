cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( var "Haha012302" )

string ( TOUPPER ${var} upvar )

message ( STATUS "var=${var}" )
message ( STATUS "upvar=${upvar}" )

string ( FIND ${upvar} "01" loc1 )
string ( FIND ${upvar} "02" loc2 )

message ( STATUS "loc1=${loc1}" )
message ( STATUS "loc2=${loc2}" )

string ( FIND ${upvar} "HAHA" myloc )
if ( myloc GREATER_EQUAL 0 )
    message ( STATUS "Find var=${var}" )
endif ()
