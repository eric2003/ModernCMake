cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

add_library(sub OBJECT sub.c)

add_executable ( CPrj
    main.c
)

enable_language(Fortran)

add_executable ( FPrj
    fmain.f90
)

target_link_libraries( CPrj
    PRIVATE 
        $<TARGET_OBJECTS:sub>
)

target_link_libraries( FPrj
    PRIVATE 
        $<TARGET_OBJECTS:sub>
)

get_target_property(cprj_LINK_LIBRARIES CPrj LINK_LIBRARIES)
get_target_property(fprj_LINK_LIBRARIES FPrj LINK_LIBRARIES)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    cprj_LINK_LIBRARIES = ${cprj_LINK_LIBRARIES} &
    echo 
    fprj_LINK_LIBRARIES = ${fprj_LINK_LIBRARIES} &
    echo 
    TARGET_OBJECTS:sub = $<TARGET_OBJECTS:sub>
)
