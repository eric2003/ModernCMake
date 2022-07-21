cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

set(BLA_VENDOR OpenBLAS)
message( STATUS "BLA_VENDOR=${BLA_VENDOR}" )

find_package(BLAS REQUIRED)
