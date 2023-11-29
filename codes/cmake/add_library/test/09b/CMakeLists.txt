cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

enable_language(Fortran)

add_library(csub OBJECT csub.c)
add_library(fsub OBJECT fsub.f90)

add_executable ( CCPrj
    cmain.c
)

add_executable ( CFPrj
    cmain.c
)

add_executable ( FCPrj
    fmain.f90
)

add_executable ( FFPrj
    fmain.f90
)


target_link_libraries( CCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)

target_link_libraries( CFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
)

target_link_libraries( FCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)

target_link_libraries( FFPrj
    PRIVATE 
        $<TARGET_OBJECTS:fsub>
)
