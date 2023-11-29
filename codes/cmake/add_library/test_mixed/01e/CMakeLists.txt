cmake_minimum_required(VERSION 3.0)

project(CallingFortranFromC)

# 设置Fortran编译器
enable_language(Fortran)
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -cpp")

# 添加可执行文件并包含Fortran和C源文件
add_executable(main_program main.c my_subroutine.f90)