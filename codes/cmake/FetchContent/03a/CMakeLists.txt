cmake_minimum_required ( VERSION 3.28 )

include(FetchContent)
FetchContent_Declare(
  mytest
  GIT_REPOSITORY    git@github.com:eric2003/Foo.git
  GIT_TAG           0.0.2  
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        605a34765aa5d5ecbf476b4598a862ada971b0cc # v3.0.1
)

FetchContent_MakeAvailable(mytest)
FetchContent_MakeAvailable(Catch2)

message( STATUS "mytest_POPULATED = ${mytest_POPULATED}" )
message( STATUS "mytest_SOURCE_DIR = ${mytest_SOURCE_DIR}" )
message( STATUS "mytest_BINARY_DIR = ${mytest_BINARY_DIR}" )
message( STATUS "FETCHCONTENT_BASE_DIR = ${FETCHCONTENT_BASE_DIR}" )
message( STATUS "FETCHCONTENT_QUIET = ${FETCHCONTENT_QUIET}" )
message( STATUS "FETCHCONTENT_FULLY_DISCONNECTED = ${FETCHCONTENT_FULLY_DISCONNECTED}" )
message( STATUS "FETCHCONTENT_UPDATES_DISCONNECTED = ${FETCHCONTENT_UPDATES_DISCONNECTED}" )
message( STATUS "FETCHCONTENT_TRY_FIND_PACKAGE_MODE = ${FETCHCONTENT_TRY_FIND_PACKAGE_MODE}" )
message( STATUS "FETCHCONTENT_SOURCE_DIR_MYTEST = ${FETCHCONTENT_SOURCE_DIR_MYTEST}" )
message( STATUS "FETCHCONTENT_UPDATES_DISCONNECTED_MYTEST = ${FETCHCONTENT_UPDATES_DISCONNECTED_MYTEST}" )
message( STATUS "CMAKE_FIND_PACKAGE_REDIRECTS_DIR = ${CMAKE_FIND_PACKAGE_REDIRECTS_DIR}" )


set(FOO_ROOT ${CMAKE_BINARY_DIR}/thirdparty/Foo)

set ( FOO_LIB          ${FOO_ROOT}/lib/foo.lib)
set ( FOO_INCLUDE_DIR  ${FOO_ROOT}/include )

project ( testprj )

add_executable( testprj )

target_sources( testprj 
    PRIVATE 
      main.cpp
)

target_include_directories(testprj 
    PRIVATE 
        ${FOO_INCLUDE_DIR}
)

 target_link_libraries(testprj 
    PRIVATE 
        ${FOO_LIB}
)
