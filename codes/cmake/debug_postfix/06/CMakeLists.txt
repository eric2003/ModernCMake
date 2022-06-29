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

add_executable ( ${PROJECT_NAME}
    main.cpp
)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES OUTPUT_NAME
        ${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}
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


get_target_property ( my_debug_postfix ${MyLib} DEBUG_POSTFIX )
get_target_property ( my_lib_outname ${MyLib} OUTPUT_NAME )
get_target_property ( my_prjname_debug ${PROJECT_NAME} OUTPUT_NAME_DEBUG )
get_target_property ( my_prjname_release ${PROJECT_NAME} OUTPUT_NAME_RELEASE )
get_target_property ( my_prj_outname ${PROJECT_NAME} OUTPUT_NAME )
message ( STATUS "OUTPUT_NAME_DEBUG = ${OUTPUT_NAME_DEBUG} " )
message ( STATUS "my_debug_postfix = ${my_debug_postfix} " )
message ( STATUS "my_lib_outname = ${my_lib_outname} " )
message ( STATUS "my_prjname_debug = ${my_prjname_debug} " )
message ( STATUS "my_prjname_release = ${my_prjname_release} " )
message ( STATUS "my_prj_outname = ${my_prj_outname} " )

install ( 
    TARGETS ${MyLib} ${PROJECT_NAME}
    EXPORT ${PackageName}Targets
    RUNTIME DESTINATION bin 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)