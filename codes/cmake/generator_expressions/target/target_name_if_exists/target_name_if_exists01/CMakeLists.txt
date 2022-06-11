cmake_minimum_required ( VERSION 3.20 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_executable( ${PROJECT_NAME}
    main.cpp
)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "TARGET_NAME_IF_EXISTS:${PROJECT_NAME} = " $<TARGET_NAME_IF_EXISTS:${PROJECT_NAME}>
    "TARGET_NAME_IF_EXISTS:foo = " $<TARGET_NAME_IF_EXISTS:foo>

)