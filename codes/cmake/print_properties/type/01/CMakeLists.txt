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

include(CMakePrintHelpers)
cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES COMPILE_FEATURES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES TYPE
)
