cmake_minimum_required ( VERSION 3.28 )

project(FortranCExample)

# 添加Fortran和C源文件
enable_language(Fortran)
enable_language(C)
add_executable(my_program main.f90 helper.c)


