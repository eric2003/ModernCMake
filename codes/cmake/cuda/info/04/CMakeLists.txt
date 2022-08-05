cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

find_package ( CUDAToolkit )

get_property(_variableNames DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VARIABLES)
#message( STATUS "_variableNames=${_variableNames}" )
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    get_directory_property(_variableValue DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DEFINITION ${_variableName})
    #message( STATUS "DIR : ${_variableName}=${_variableValue}" )
	message( STATUS "${_variableName}=${_variableValue}" )
endforeach()