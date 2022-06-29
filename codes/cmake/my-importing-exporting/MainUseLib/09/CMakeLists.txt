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
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES COMPATIBLE_INTERFACE_STRING
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_CONFIGURATIONS
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_LOCATION_DEBUG
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_LOCATION_RELEASE
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_IMPLIB
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG
)

cmake_print_properties(
  TARGETS MathLib::MathLib
  PROPERTIES IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE
) 

# create executable
add_executable(myexe main.cc)

# use MathLib library
target_link_libraries(myexe PRIVATE MathLib::MathLib)
