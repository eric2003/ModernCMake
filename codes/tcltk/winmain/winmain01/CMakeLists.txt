cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_LIBRARIES )
set ( PRJ_COMPILE_FEATURES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

find_package ( TCL )
message( STATUS "TCL_INCLUDE_PATH = ${TCL_INCLUDE_PATH}" )
message( STATUS "TK_INCLUDE_PATH = ${TK_INCLUDE_PATH}" )
list ( APPEND PRJ_INCLUDE_DIRS ${TCL_INCLUDE_PATH} )
list ( APPEND PRJ_LIBRARIES ${TCL_LIBRARY} )
list ( APPEND PRJ_LIBRARIES ${TK_LIBRARY} )

set ( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS" ) 

add_executable ( ${PROJECT_NAME}
    main.cpp
    mycgio.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)
