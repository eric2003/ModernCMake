cmake_minimum_required(VERSION 3.28)

project(testprj)

file ( WRITE "${CMAKE_BINARY_DIR}/main.cpp"
      "#include <iostream>\n\nint main(int argc, char* argv[])\n{\n    return 0;\n}\n"
)
