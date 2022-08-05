cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

find_package ( CUDAToolkit )

get_property(_variableNames DIRECTORY ${dir} PROPERTY VARIABLES)
message( STATUS "_variableNames=${_variableNames}" )
