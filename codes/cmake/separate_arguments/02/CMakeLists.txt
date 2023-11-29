cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

separate_arguments (out1 UNIX_COMMAND    PROGRAM "cmd.exe -c main.c")
separate_arguments (out2 WINDOWS_COMMAND PROGRAM "cmd.exe -c main.c")
separate_arguments (out3 NATIVE_COMMAND  PROGRAM "cmd.exe -c main.c")

message ( STATUS "out1 = ${out1}" )
message ( STATUS "out2 = ${out2}" )
message ( STATUS "out3 = ${out3}" )

list(LENGTH out1 nlen1)
list(LENGTH out2 nlen2)
list(LENGTH out3 nlen3)

message ( STATUS "nlen1 = ${nlen1}" )
message ( STATUS "nlen2 = ${nlen2}" )
message ( STATUS "nlen3 = ${nlen3}" )

