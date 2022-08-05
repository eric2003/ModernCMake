cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

get_property( my_cuda_features GLOBAL PROPERTY CMAKE_CUDA_KNOWN_FEATURES )

message( STATUS "my_cuda_features=${my_cuda_features}" )