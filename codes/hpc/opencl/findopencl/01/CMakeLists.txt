cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

find_package ( OpenCL )

include(CMakePrintHelpers)

cmake_print_variables( OpenCL_FOUND )
cmake_print_variables( OpenCL_INCLUDE_DIRS )
cmake_print_variables( OpenCL_LIBRARIES )
cmake_print_variables( OpenCL_VERSION_STRING )
cmake_print_variables( OpenCL_VERSION_MAJOR )
cmake_print_variables( OpenCL_VERSION_MINOR )

cmake_print_variables( OpenCL_INCLUDE_DIR )
cmake_print_variables( OpenCL_LIBRARY )
