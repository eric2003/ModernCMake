cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set(var "String_0 String_1 String_2")

string(FIND ${var} " " wsloc)

message(STATUS "position of first whitespace character: ${wsloc}")

string(SUBSTRING ${var} 0 ${wsloc} newvar)
message(STATUS "selected substring: \"${newvar}\"")