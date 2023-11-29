cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )
message ( STATUS "CMAKE_ROOT = ${CMAKE_ROOT}" )
message ( STATUS "CMAKE_Fortran_COMPILER_FORCED = ${CMAKE_Fortran_COMPILER_FORCED}" )

enable_language(Fortran)
message ( STATUS "CMAKE_Fortran_COMPILER_FORCED = ${CMAKE_Fortran_COMPILER_FORCED}" )

