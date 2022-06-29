cmake_minimum_required(VERSION 3.15)
project(DownstreamComponents)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find MathLib
#find_package(MathLib 3.4 COMPONENTS Addition SquareRoot)
find_package(MathLib 3.4)

message( STATUS "MathLib_FOUND = ${MathLib_FOUND}" )
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
  PROPERTIES IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG
)


# create executable
add_executable(myexe main.cc)

# use MathLib library
#target_link_libraries(myexe PRIVATE MathLib::Addition MathLib::SquareRoot)
target_link_libraries(myexe PRIVATE MathLib::MathLib)

# Workaround for GCC on AIX to avoid -isystem, not needed in general.
set_property(TARGET myexe PROPERTY NO_SYSTEM_FROM_IMPORTED 1)
