cmake_minimum_required ( VERSION 3.24 )

project ( testprj )

find_package ( CUDAToolkit )

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build directory: ${PROJECT_BINARY_DIR}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

find_package ( CUDAToolkit )
message ( STATUS  "CUDAToolkit_FOUND=${CUDAToolkit_FOUND}" )
if ( CUDAToolkit_FOUND )
    enable_language( CUDA )
    set ( CMAKE_CUDA_STANDARD 20 )
    set ( CMAKE_CUDA_ARCHITECTURES "60;72;75" )
    set ( CUDA_INCLUDE_DIRS )
endif ()

add_executable ( ${PROJECT_NAME}
    main.cu
)

set_target_properties ( ${PROJECT_NAME}
    PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

get_property(_variableNames DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VARIABLES)
#message( STATUS "_variableNames=${_variableNames}" )
list (SORT _variableNames)
foreach ( _variableName ${_variableNames})
    string( TOUPPER ${_variableName} upperVarName )
    string ( FIND ${upperVarName} "CUDA" myloc )
    if ( myloc GREATER_EQUAL 0 )
        #message( STATUS "${_variableName}" )
        get_directory_property(_variableValue DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DEFINITION ${_variableName})
        message( STATUS "${_variableName}=${_variableValue}" )		
    endif () 
endforeach()

message( STATUS "CMAKE_CUDA_HOST_COMPILER=${CMAKE_CUDA_HOST_COMPILER}" )
message( STATUS "CMAKE_CUDA_COMPILER_ID=${CMAKE_CUDA_COMPILER_ID}" )

