cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( mylist a b c d 1 2 3 4 )
message ( STATUS "mylist= ${mylist}" )
set ( mylist1 ${mylist} )
set ( mylist2 ${mylist} )
list (FILTER mylist1 INCLUDE REGEX [a-z])
message ( STATUS "mylist1= ${mylist1}" )
list (FILTER mylist2 EXCLUDE REGEX [a-z])
message ( STATUS "mylist2= ${mylist2}" )
