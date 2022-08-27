cmake_minimum_required ( VERSION 3.24 )

project ( testprj )

find_package ( CUDAToolkit )

get_property(_variableNames DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VARIABLES)
#message( STATUS "_variableNames=${_variableNames}" )
list (SORT _variableNames)
foreach ( _variableName ${_variableNames})
    string( TOUPPER ${_variableName} upperVarName )
    string ( FIND ${upperVarName} "CUDA" myloc )
    if ( myloc GREATER_EQUAL 0 )
        message( STATUS "${_variableName}" )
    endif () 
endforeach()

message( STATUS "CMAKE_CUDA_HOST_COMPILER=${CMAKE_CUDA_HOST_COMPILER}" )
message( STATUS "CMAKE_CUDA_COMPILER_ID=${CMAKE_CUDA_COMPILER_ID}" )

