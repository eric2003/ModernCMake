cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

execute_process(COMMAND cmake --help-property-list OUTPUT_VARIABLE my_property_lists )
STRING ( REGEX REPLACE "\n" ";" my_property_lists "${my_property_lists}" )
list ( SORT my_property_lists )
foreach ( my_property ${my_property_lists})
	message( STATUS "PROPERTY : ${my_property}" )
endforeach()