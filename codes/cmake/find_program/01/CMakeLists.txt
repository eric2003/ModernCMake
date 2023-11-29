cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

find_program(MY_PROGRAM
    NAMES cmd.exe
)

if(MY_PROGRAM)
    message(STATUS "Found the program at: ${MY_PROGRAM}")
else()
    message(STATUS "The program was not found")
endif()
