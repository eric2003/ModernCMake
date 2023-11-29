cmake_minimum_required ( VERSION 3.28 )

project ( testprj LANGUAGES Fortran C )

include(FortranCInterface)
FortranCInterface_VERIFY()

message ( STATUS "CMAKE_Fortran_FLAGS = ${CMAKE_Fortran_FLAGS}" )

add_library(fsub OBJECT fsub.f90)

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


