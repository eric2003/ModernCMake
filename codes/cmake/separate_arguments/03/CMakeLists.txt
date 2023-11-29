cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

separate_arguments( args WINDOWS_COMMAND "cmd.exe /C dir C:\\Windows\\ /w")
foreach(arg IN LISTS args)
    message( STATUS "${arg}" )
endforeach()

list(LENGTH args nlen)

message ( STATUS "nlen = ${nlen}" )


