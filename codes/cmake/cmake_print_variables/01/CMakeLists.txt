cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

include(CMakePrintHelpers)

cmake_print_variables(CMAKE_C_COMPILER CMAKE_MAJOR_VERSION DOES_NOT_EXIST)
