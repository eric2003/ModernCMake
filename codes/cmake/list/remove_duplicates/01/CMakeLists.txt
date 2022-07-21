cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( mylist a a b b b c )
message ( STATUS "mylist= ${mylist}" )
list ( REMOVE_DUPLICATES mylist )
message ( STATUS "mylist= ${mylist}" )

