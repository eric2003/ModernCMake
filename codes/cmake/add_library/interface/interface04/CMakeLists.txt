cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_library(mylib INTERFACE)
set_property(
    TARGET mylib
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON
)

get_property( my_prop_value
    TARGET mylib
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE
)

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
