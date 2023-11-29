cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(testprj)

enable_language(Fortran)

list(APPEND implicit_dirs "C:/Program Files (x86)/Intel/oneAPI/compiler/2023.2.0/windows/compiler/lib/Intel64_win")

add_library(fsub OBJECT fsub.f90 output.cmake)
add_library(csub OBJECT csub.c)

add_executable ( CFPrj 
    fsub.f90
    cmain.c
)

target_link_directories( CFPrj
    PRIVATE 
        ${CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES}
)

add_executable ( CCPrj
    cmain.c
)

target_link_libraries( CCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)

add_executable ( FCPrj
    $<TARGET_OBJECTS:csub>
    fmain.f90
)

#target_link_libraries( FCPrj
#    PRIVATE 
#        $<TARGET_OBJECTS:csub>
#)

add_executable ( FFPrj
    $<TARGET_OBJECTS:fsub>
    fmain.f90
)

