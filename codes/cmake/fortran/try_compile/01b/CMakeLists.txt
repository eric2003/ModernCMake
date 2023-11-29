cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

set( lang Fortran )

enable_language( ${lang} )

message ( STATUS "IFORT_LIB_PATH_COMPILED = ${IFORT_LIB_PATH_COMPILED}" )
message ( STATUS "CMAKE_Fortran_FLAGS = ${CMAKE_Fortran_FLAGS}" )
message ( STATUS "IntelFortranImplicit_SOURCE_DIR = ${IntelFortranImplicit_SOURCE_DIR}" )


if("${lang}" MATCHES "Fortran"
    AND "${CMAKE_GENERATOR}" MATCHES "Visual Studio")
  message(CHECK_START "Determine Intel Fortran Compiler Implicit Link Path")
  # Build a sample project which reports symbols.
  try_compile(IFORT_LIB_PATH_COMPILED
    PROJECT IntelFortranImplicit
    SOURCE_DIR ${CMAKE_ROOT}/Modules/IntelVSImplicitPath
    BINARY_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/MY_IntelVSImplicitPath
    CMAKE_FLAGS
    "-DCMAKE_Fortran_FLAGS:STRING=${CMAKE_Fortran_FLAGS}"
    OUTPUT_VARIABLE _output)
  file(WRITE
    "${CMAKE_BINARY_DIR}/CMakeFiles/MY_IntelVSImplicitPath/output.txt"
    "${_output}")
  include(${CMAKE_BINARY_DIR}/CMakeFiles/MY_IntelVSImplicitPath/output.cmake OPTIONAL)
  message(CHECK_PASS "done")
endif()
