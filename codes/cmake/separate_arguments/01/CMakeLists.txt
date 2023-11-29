cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

separate_arguments (out1 UNIX_COMMAND    PROGRAM "cc -c main.c")
separate_arguments (out2 WINDOWS_COMMAND PROGRAM "cc -c main.c")
separate_arguments (out3 NATIVE_COMMAND  PROGRAM "cc -c main.c")

message ( STATUS "out1 = ${out1}" )
message ( STATUS "out2 = ${out2}" )
message ( STATUS "out3 = ${out3}" )
