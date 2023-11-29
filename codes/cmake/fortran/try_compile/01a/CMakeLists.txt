cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

set( lang Fortran )

enable_language( ${lang} )

message ( STATUS "IFORT_LIB_PATH_COMPILED = ${IFORT_LIB_PATH_COMPILED}" )
message ( STATUS "CMAKE_Fortran_FLAGS = ${CMAKE_Fortran_FLAGS}" )

