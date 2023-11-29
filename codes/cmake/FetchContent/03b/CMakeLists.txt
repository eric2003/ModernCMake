cmake_minimum_required ( VERSION 3.28 )

include(FetchContent)

set(FOO_ROOT ${CMAKE_BINARY_DIR}/thirdparty/Foo)

FetchContent_Declare(
  Foo
  GIT_REPOSITORY    git@github.com:eric2003/Foo.git
  GIT_TAG           0.0.2
)

FetchContent_MakeAvailable(Foo)

message( STATUS "foo_POPULATED = ${foo_POPULATED}" )
message( STATUS "foo_SOURCE_DIR = ${foo_SOURCE_DIR}" )
message( STATUS "foo_BINARY_DIR = ${foo_BINARY_DIR}" )
message( STATUS "FETCHCONTENT_BASE_DIR = ${FETCHCONTENT_BASE_DIR}" )
message( STATUS "FETCHCONTENT_QUIET = ${FETCHCONTENT_QUIET}" )
message( STATUS "FETCHCONTENT_FULLY_DISCONNECTED = ${FETCHCONTENT_FULLY_DISCONNECTED}" )
message( STATUS "FETCHCONTENT_UPDATES_DISCONNECTED = ${FETCHCONTENT_UPDATES_DISCONNECTED}" )
message( STATUS "FETCHCONTENT_TRY_FIND_PACKAGE_MODE = ${FETCHCONTENT_TRY_FIND_PACKAGE_MODE}" )
message( STATUS "CMAKE_FIND_PACKAGE_REDIRECTS_DIR = ${CMAKE_FIND_PACKAGE_REDIRECTS_DIR}" )
message( STATUS "CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}" )

#set(FOO_ROOT ${CMAKE_BINARY_DIR}/thirdparty/Foo)

#set ( FOO_LIB          ${FOO_ROOT}/lib/foo.lib)
#set ( FOO_INCLUDE_DIR  ${FOO_ROOT}/include )

execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install OUTPUT_VARIABLE my_output )  
 
project ( testprj )

add_executable( testprj )

target_sources( testprj 
    PRIVATE 
      main.cpp
)

add_dependencies( testprj Foo )

#target_include_directories(testprj 
#    PRIVATE 
#        ${Foo_INCLUDE_DIR}
#)

target_link_libraries(testprj 
    PRIVATE 
        Foo
)
