cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

message( STATUS "BLA_VENDOR=${BLA_VENDOR}" )

find_package(BLAS REQUIRED)
message( STATUS "BLAS_FOUND=${BLAS_FOUND}" )
message( STATUS "BLAS_LIBRARIES=${BLAS_LIBRARIES}" )
message( STATUS "BLAS_LINKER_FLAGS=${BLAS_LINKER_FLAGS}" )
message( STATUS "BLAS95_FOUND=${BLAS95_FOUND}" )

