cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

message( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_library( MyLib STATIC IMPORTED )
set_target_properties( MyLib PROPERTIES
    IMPORTED_LOCATION_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/MathLib_d.lib
    IMPORTED_LOCATION_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/MathLib.lib 
)

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PUBLIC 
    debug ${CMAKE_CURRENT_SOURCE_DIR}/MathLib_d.lib 
    optimized ${CMAKE_CURRENT_SOURCE_DIR}/MathLib.lib
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

get_target_property(prj_libs ${PROJECT_NAME} LINK_LIBRARIES)
foreach(lib ${prj_libs})
    message( STATUS "prj_lib =${lib}" )
endforeach()

include(CMakePrintHelpers)
cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS ${PROJECT_NAME}
  PROPERTIES INTERFACE_LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS MyLib
  PROPERTIES IMPORTED_LOCATION_DEBUG
)

cmake_print_properties(
  TARGETS MyLib
  PROPERTIES IMPORTED_LOCATION_RELEASE
)

add_custom_target ( print 
    COMMAND
    ${CMAKE_COMMAND} -E 
    echo
    PLATFORM_ID = $<PLATFORM_ID> &
    echo
    CONFIG = $<CONFIG> &
    echo
    prj_libs =  ${prj_libs}
)