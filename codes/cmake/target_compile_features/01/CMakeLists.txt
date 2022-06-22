cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )
list ( APPEND PRJ_COMPILE_FEATURES cxx_std_17 )

add_executable ( ${PROJECT_NAME}
    main.cpp
)

list ( APPEND PRJ_LIBRARIES lib1 )
list ( APPEND PRJ_LIBRARIES lib2 )
list ( APPEND PRJ_LIBRARIES lib3 )

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

get_target_property(prj_libs ${PROJECT_NAME} LINK_LIBRARIES)
foreach(lib ${prj_libs})
    message( STATUS "prj_lib = ${lib}" )
endforeach()

get_target_property(prj_features ${PROJECT_NAME} COMPILE_FEATURES)
foreach(feature ${prj_features})
    message( STATUS "prj_feature = ${feature}" )
endforeach()