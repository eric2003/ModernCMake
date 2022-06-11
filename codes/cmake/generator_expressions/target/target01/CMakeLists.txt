cmake_minimum_required ( VERSION 3.20 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_executable( ${PROJECT_NAME}
    main.cpp
)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "PLATFORM_ID = $<PLATFORM_ID>" 
    "TARGET_EXISTS:${PROJECT_NAME} = " $<TARGET_EXISTS:${PROJECT_NAME}>

)