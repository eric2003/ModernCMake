cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

set ( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS" ) 

add_executable ( ${PROJECT_NAME}
    main.cpp
)
