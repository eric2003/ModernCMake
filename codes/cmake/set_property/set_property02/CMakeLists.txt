cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set_property( GLOBAL APPEND PROPERTY MYPROP VAR1 VAR2 )
get_property( MYPROP_VALUE GLOBAL PROPERTY MYPROP )

message ( STATUS "MYPROP_VALUE=${MYPROP_VALUE}" )
