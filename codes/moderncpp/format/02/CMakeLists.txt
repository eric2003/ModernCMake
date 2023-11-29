cmake_minimum_required(VERSION 3.20)

project ( testprj )

set ( PRJ_COMPILE_FEATURES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_23 )

set_property ( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )

add_executable( ${PROJECT_NAME}
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)
