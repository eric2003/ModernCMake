cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

enable_language(Fortran)

add_library(fsub OBJECT fsub.f90)

add_executable ( CFPrj
    cmain.c
)

add_executable ( CFLPrj
    cmain.c
)

target_link_libraries( CFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
)

target_link_libraries( CFLPrj
    PRIVATE 
        fsub
)

