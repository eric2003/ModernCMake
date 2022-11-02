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


get_directory_property( my_system_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} BUILDSYSTEM_TARGETS )
get_directory_property( my_import_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} IMPORTED_TARGETS )

message( STATUS "my_system_targets=${my_system_targets}" )
message( STATUS "my_import_targets=${my_import_targets}" )

