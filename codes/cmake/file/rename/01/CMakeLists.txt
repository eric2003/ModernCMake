cmake_minimum_required(VERSION 3.28)

project(testprj)

message ( STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}" )

file ( WRITE "${CMAKE_BINARY_DIR}/a.cpp"
      "#include <iostream>\n\nint main(int argc, char* argv[])\n{\n    return 0;\n}\n"
)

file ( RENAME ${CMAKE_BINARY_DIR}/a.cpp ${CMAKE_BINARY_DIR}/b.cpp )


