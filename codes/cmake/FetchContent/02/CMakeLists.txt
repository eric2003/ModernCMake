cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# Check if population has already been performed
FetchContent_GetProperties(depname)
message( STATUS "depname = ${depname}" )
