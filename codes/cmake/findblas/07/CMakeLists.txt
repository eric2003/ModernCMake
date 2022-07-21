cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

message( STATUS "BLA_VENDOR=${BLA_VENDOR}" )

find_package(BLAS REQUIRED)
message( STATUS "BLAS_FOUND=${BLAS_FOUND}" )
message( STATUS "BLAS_LIBRARIES=${BLAS_LIBRARIES}" )
message( STATUS "BLAS_LINKER_FLAGS=${BLAS_LINKER_FLAGS}" )
message( STATUS "BLAS95_FOUND=${BLAS95_FOUND}" )

add_library( mylib INTERFACE )

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PUBLIC 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

get_directory_property( my_system_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} BUILDSYSTEM_TARGETS )
get_directory_property( my_import_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} IMPORTED_TARGETS )

message( STATUS "my_system_targets=${my_system_targets}" )
message( STATUS "my_import_targets=${my_import_targets}" )

