cmake_minimum_required ( VERSION 3.28 )

project ( testprj LANGUAGES Fortran C )

include(FortranCInterface)
FortranCInterface_VERIFY()

add_library(fsub OBJECT fsub.f90)

set( F_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/FortranLib.lib )

add_executable ( CFPrj
    cmain.c
)

message ( STATUS "implicit_dirs = ${implicit_dirs}" )
message ( STATUS "CMAKE_Fortran_COMPILER_FORCED = ${CMAKE_Fortran_COMPILER_FORCED}" )


#target_link_directories( CFPrj
#    PRIVATE 
#        ${CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES}
#)

target_link_libraries( CFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
        ${F_LIB}
)


