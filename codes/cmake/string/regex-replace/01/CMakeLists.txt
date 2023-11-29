cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

set(myString "Hello, World!")
string(REGEX REPLACE "Hello" "Hi" myOutString ${myString})
message ( STATUS "myString = ${myString}" )
message ( STATUS "myOutString = ${myOutString}" )
