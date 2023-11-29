cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

add_library(my_obj OBJECT a.c)

add_library(my_shared SHARED b.c c.c $<TARGET_OBJECTS:my_obj> )

include(CMakePrintHelpers)
cmake_print_properties(
  TARGETS my_shared
  PROPERTIES LINK_LIBRARIES
)

cmake_print_properties(
  TARGETS my_shared
  PROPERTIES SOURCES
)

cmake_print_properties(
  TARGETS my_obj
  PROPERTIES SOURCES
)


message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    CONFIG = $<CONFIG> &
    echo 
    PLATFORM_ID:Windows = $<PLATFORM_ID:Windows>
    CONFIG = $<CONFIG> &
    echo 
    TARGET_OBJECTS:my_obj = $<TARGET_OBJECTS:my_obj>
)
