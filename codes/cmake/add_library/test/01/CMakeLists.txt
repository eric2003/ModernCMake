cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

add_library(mylib INTERFACE)
add_library(interlib INTERFACE)
set_property(
    TARGET mylib
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON
)

get_property( my_prop_value
    TARGET mylib
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE
)

set_property(
    TARGET mylib
    APPEND
    PROPERTY
        INTERFACE_LINK_LIBRARIES interlib
        "$<$<OR:$<PLATFORM_ID:Windows>,$<PLATFORM_ID:Cygwin>>:$<BUILD_INTERFACE:interlib>>")

get_property( my_interface_compile_features
    TARGET mylib
    PROPERTY INTERFACE_COMPILE_FEATURES
)

get_property( my_interface_link_libraries
    TARGET mylib
    PROPERTY INTERFACE_LINK_LIBRARIES
)

message ( STATUS "my_prop_value=${my_prop_value}" )
message ( STATUS "my_interface_compile_features=${my_interface_compile_features}" )
message ( STATUS "my_interface_link_libraries=${my_interface_link_libraries}" )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    CONFIG = $<CONFIG> &
    echo 
    my_interface_link_libraries = ${my_interface_link_libraries} &
    echo 
    PLATFORM_ID:Windows = $<PLATFORM_ID:Windows>
)
