cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(testprj)

enable_language(Fortran)

add_library(fsub OBJECT fsub.f90)
add_library(csub OBJECT csub.c)

add_executable ( CFPrj 
    $<TARGET_OBJECTS:fsub>
    cmain.c
)

target_link_directories( CFPrj
    PRIVATE 
        ${CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES}
)

#target_link_libraries( CFPrj
#    PRIVATE 
#        $<TARGET_OBJECTS:fsub>
#)

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

