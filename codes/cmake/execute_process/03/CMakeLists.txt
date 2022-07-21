cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

execute_process( COMMAND ${CMAKE_COMMAND} --help-property-list
                 OUTPUT_VARIABLE CMAKE_PROPERTY_LIST
)

message( STATUS "CMAKE_PROPERTY_LIST: ${CMAKE_PROPERTY_LIST}" )
