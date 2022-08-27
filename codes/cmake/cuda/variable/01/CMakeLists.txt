cmake_minimum_required ( VERSION 3.24 )

project ( testprj )

#find_package ( CUDAToolkit )

get_property(_variableNames DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VARIABLES)

list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    string( TOUPPER ${_variableName} upperVarName )
    string ( FIND ${upperVarName} "CUDA" myloc )
    if ( myloc GREATER_EQUAL 0 )
        get_directory_property(_variableValue DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DEFINITION ${_variableName})
        message( STATUS "${_variableName}=${_variableValue}" )
    endif ()    
endforeach()