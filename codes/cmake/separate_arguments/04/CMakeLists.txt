cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

set(arguments "-DFOO=1 -DBAR=2 -DBAZ=3")
separate_arguments(arguments_list NATIVE_COMMAND ${arguments})

list( LENGTH arguments nlen1 )
list( LENGTH arguments_list nlen2 )

message ( STATUS "nlen1 = ${nlen1}" )
message ( STATUS "arguments = ${arguments}" )
message ( STATUS "nlen2 = ${nlen2}" )
message ( STATUS "arguments_list = ${arguments_list}" )
