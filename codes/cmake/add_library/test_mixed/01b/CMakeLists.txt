cmake_minimum_required ( VERSION 3.22 )

project(CallingFortranFromC)

# 设置Fortran编译器
enable_language(Fortran)
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} /iface:stdref")

# 添加可执行文件并包含Fortran和C源文件
add_executable(main_program main.c my_subroutine.f90)

# 指定链接的库文件
target_link_libraries(main_program ${CMAKE_CURRENT_SOURCE_DIR}/main.def)

