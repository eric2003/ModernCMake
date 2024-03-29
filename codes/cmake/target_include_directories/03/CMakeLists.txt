cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable ( ${PROJECT_NAME}
    main.cpp
)

list ( APPEND PRJ_INCLUDE_DIRS sub1 )
list ( APPEND PRJ_INCLUDE_DIRS sub2 )

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

get_property( dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES )

message( STATUS "dirs= ${dirs}" )
foreach(dir ${dirs})
    message( STATUS "dir='${dir}'" )
endforeach()