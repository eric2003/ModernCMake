cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(testprj Fortran C)

add_library(fsub fsub.f90)
add_library(csub csub.c)

add_executable ( CFPrj
    cmain.c
)

target_link_directories( CFPrj
    PRIVATE 
        ${CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES}
)

target_link_libraries( CFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
)

add_executable ( CCPrj
    cmain.c
)

target_link_libraries( CCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)

add_executable ( FCPrj
    fmain.f90
)

target_link_libraries( FCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)

add_executable ( FFPrj
    fmain.f90
)

target_link_libraries( FFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
)
