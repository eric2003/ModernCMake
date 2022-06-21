cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set_property( GLOBAL APPEND PROPERTY my_prop VAR1 VAR2 )
set_property( GLOBAL APPEND PROPERTY my_prop VAR3 )
get_property( my_prop_value GLOBAL PROPERTY my_prop )

message ( STATUS "my_prop_value=${my_prop_value}" )
