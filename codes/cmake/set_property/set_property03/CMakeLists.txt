cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_library(pic_on INTERFACE)
set_property(
    TARGET pic_on
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON
)
add_library(pic_off INTERFACE)
set_property(
    TARGET pic_off
    PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE OFF
)

#message ( STATUS "my_prop_value=${my_prop_value}" )
