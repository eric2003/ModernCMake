cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )
set ( PRJ_INTERFACE_LIBRARIES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )
list ( APPEND PRJ_COMPILE_FEATURES cxx_std_17 )

add_library( ${PROJECT_NAME} INTERFACE )

list ( APPEND PRJ_LIBRARIES lib1 )
list ( APPEND PRJ_LIBRARIES lib2 )
list ( APPEND PRJ_LIBRARIES lib3 )

list ( APPEND PRJ_INTERFACE_LIBRARIES i_lib1 )
list ( APPEND PRJ_INTERFACE_LIBRARIES i_lib2 )


target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    INTERFACE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    INTERFACE 
        ${PRJ_COMPILE_FEATURES}
)

include(CMakePrintHelpers)
cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES LINK_INTERFACE_LIBRARIES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES INTERFACE_LINK_LIBRARIES
)


cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES COMPILE_FEATURES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES TYPE
)
