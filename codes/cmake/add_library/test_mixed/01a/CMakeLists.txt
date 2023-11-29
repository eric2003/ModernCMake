cmake_minimum_required ( VERSION 3.22 )

project(CallingFortranFromC)

# 添加Fortran源文件
enable_language(Fortran)
set(Fortran_SOURCES my_subroutine.f90)

# 添加C源文件
set(C_SOURCES main.c)

# 添加可执行文件并包含Fortran和C源文件
add_executable(main_program ${Fortran_SOURCES} ${C_SOURCES})


