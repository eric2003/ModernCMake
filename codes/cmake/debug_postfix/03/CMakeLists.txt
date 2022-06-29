cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

message ( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE} " )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

set( MyLib MathLib )
# create library
add_library( ${MyLib}
    STATIC 
        MathFunctions.cxx
)

target_include_directories ( ${MyLib}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${MyLib}
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${MyLib}
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)
get_target_property ( my_debug_postfix ${MyLib} DEBUG_POSTFIX )

message ( STATUS "my_debug_postfix = ${my_debug_postfix} " )
