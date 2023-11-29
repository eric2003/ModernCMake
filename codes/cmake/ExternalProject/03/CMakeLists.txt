cmake_minimum_required ( VERSION 3.28 )

include(ExternalProject)

message( STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}" )
message( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
set(FOO_ROOT ${CMAKE_BINARY_DIR}/thirdparty/Foo)
set(FOO_INSTALL cmake --install . --prefix ${FOO_ROOT} --config ${CMAKE_BUILD_TYPE})

ExternalProject_Add(foobar
  PREFIX            ${FOO_ROOT}
  GIT_REPOSITORY    git@github.com:eric2003/Foo.git
  GIT_TAG           0.0.2
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${FOO_ROOT}
  INSTALL_COMMAND   ${CMAKE_COMMAND} --build . --target install
)

set ( FOO_LIB          ${FOO_ROOT}/lib/foo.lib)
set ( FOO_INCLUDE_DIR  ${FOO_ROOT}/include )

ExternalProject_Get_property(foobar PREFIX)
message( STATUS "PREFIX = ${PREFIX}" )

project ( testprj )

add_executable( testprj )

add_dependencies( testprj foobar )

target_sources( testprj 
    PRIVATE 
      main.cpp
)

target_include_directories(testprj 
    PRIVATE 
        ${FOO_INCLUDE_DIR}
)

target_link_directories(testprj 
    PRIVATE 
        ${FOO_LIB}
)


