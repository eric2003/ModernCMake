cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( var "HahA" )
string ( TOUPPER ${var} myvar )

message ( STATUS "var=${var}" )
message ( STATUS "myvar=${myvar}" )
