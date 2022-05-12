cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

find_package ( TCL )

message( STATUS "TCL_FOUND = ${TCL_FOUND}" )
message( STATUS "TK_FOUND = ${TK_FOUND}" )
message( STATUS "TCLTK_FOUND = ${TCLTK_FOUND}" )
message( STATUS "TCL_LIBRARY = ${TCL_LIBRARY}" )
message( STATUS "TCL_INCLUDE_PATH = ${TCL_INCLUDE_PATH}" )
message( STATUS "TCL_TCLSH = ${TCL_TCLSH}" )
message( STATUS "TK_LIBRARY = ${TK_LIBRARY}" )
message( STATUS "TK_INCLUDE_PATH = ${TK_INCLUDE_PATH}" )
message( STATUS "TK_WISH = ${TK_WISH}" )


