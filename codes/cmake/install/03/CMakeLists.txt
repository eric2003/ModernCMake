cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

message ( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE} " )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_library( mystatic_lib STATIC main.cpp )
add_library( myshared_lib SHARED main.cpp )

add_executable ( ${PROJECT_NAME}
    main.cpp
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

install( TARGETS ${PROJECT_NAME} mystatic_lib myshared_lib
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib )