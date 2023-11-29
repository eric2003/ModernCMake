cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

set(myString "   Hello, World!   ")
string(STRIP ${myString} myStripString)
message ( STATUS "myString=${myString}" )
message ( STATUS "myStripString=${myStripString}" )

