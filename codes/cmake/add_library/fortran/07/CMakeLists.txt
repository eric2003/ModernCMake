cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(IntelFortranImplicit Fortran C)
list(APPEND implicit_dirs "C:/Program Files (x86)/Intel/oneAPI/compiler/2023.2.0/windows/compiler/lib/Intel64_win")
add_library(FortranLib fsub.f90)
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
        $<TARGET_OBJECTS:FortranLib>
)

add_executable ( CCPrj
    cmain.c
)

target_link_libraries( CCPrj
    PRIVATE 
        $<TARGET_OBJECTS:csub>
)
