cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

get_cmake_property( varlist VARIABLES )
list ( SORT varlist )
foreach (_variableName ${varlist})
    message( STATUS "${_variableName}=${${_variableName}}" )
endforeach()
