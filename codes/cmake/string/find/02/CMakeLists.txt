cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set(var "String_0 String_1 String_2")

string(FIND ${var} " " loc1)
string(FIND ${var} "*" loc2)

message(STATUS "loc1=${loc1}")
message(STATUS "loc2=${loc2}")