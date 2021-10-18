cmake_minimum_required ( VERSION 3.15 )

project( app )

find_package ( Foo )

message ( STATUS "Foo_FOUND = ${Foo_FOUND}" )
message ( STATUS "Foo_LIBRARIES = ${Foo_LIBRARIES}" )
message ( STATUS "PROJECT_NAME = ${PROJECT_NAME}" )

add_executable ( ${PROJECT_NAME} main.cpp )
target_link_libraries ( ${PROJECT_NAME}  PRIVATE ${Foo_LIBRARIES} )
target_include_directories( ${PROJECT_NAME}  PRIVATE ${Foo_INCLUDE_DIR} )

