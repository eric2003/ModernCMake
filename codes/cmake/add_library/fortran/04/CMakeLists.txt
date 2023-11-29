cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(IntelFortranImplicit Fortran)
list(APPEND implicit_dirs "C:/Program Files (x86)/Intel/oneAPI/compiler/2023.2.0/windows/compiler/lib/Intel64_win")
add_library(FortranLib hello.f)
