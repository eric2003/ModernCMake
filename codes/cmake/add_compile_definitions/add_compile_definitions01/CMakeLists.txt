cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

add_compile_definitions(Haha1 Haha2)

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_compile_definitions( ${PROJECT_NAME} PUBLIC FOO )

add_definitions( -DDebug )
get_directory_property( DirDefs DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_DEFINITIONS )

message( STATUS "DirDefs: " ${DirDefs} )

set_target_properties ( ${PROJECT_NAME} PROPERTIES AAA 123 )

get_target_property( MyDef ${PROJECT_NAME} COMPILE_DEFINITIONS )
message ( STATUS "MyDef=${MyDef}" )
get_target_property( MyDef1 ${PROJECT_NAME} AAA )
message ( STATUS "MyDef1=${MyDef1}" )

get_property( MyDef2 GLOBAL PROPERTY COMPILE_DEFINITIONS )
message ( STATUS "MyDef2=${MyDef2}" )

get_property( MyDef3 GLOBAL PROPERTY COMPILE_OPTIONS )
message ( STATUS "MyDef3=${MyDef3}" )

get_target_property( MyDef4 ${PROJECT_NAME} COMPILE_OPTIONS )
message ( STATUS "MyDef4=${MyDef4}" )