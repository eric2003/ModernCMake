cmake_minimum_required(VERSION 3.15)
project(MainUseLib)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find MathFunctions
find_package(MathLib 3.4.1 EXACT)

message ( STATUS "MathLib_FOUND=${MathLib_FOUND}" )
message ( STATUS "MathLib_INCLUDE_DIR=${MathLib_INCLUDE_DIR}" )
message ( STATUS "MathLib_INCLUDES=${MathLib_INCLUDES}" )
message ( STATUS "MathLib_LIBRARY=${MathLib_LIBRARY}" )
message ( STATUS "MathLib_LIBRARIES=${MathLib_LIBRARIES}" )
message ( STATUS "MathLib_INCLUDE_DIRS=${MathLib_INCLUDE_DIRS}" )


include(CMakePrintHelpers)
cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES COMPILE_FLAGS
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES EXPORT_PROPERTIES
)
cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES IMPORTED
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES IMPORTED_LIBNAME
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES INTERFACE_LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES COMPATIBLE_INTERFACE_STRING
)

cmake_print_properties(
  TARGETS MathFunctions::MathLib
  PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
)



# create executable
add_executable(myexe main.cc)

# use MathFunctions library
target_link_libraries(myexe PRIVATE MathFunctions::MathLib)
