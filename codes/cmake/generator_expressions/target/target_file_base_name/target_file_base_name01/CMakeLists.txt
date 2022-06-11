cmake_minimum_required ( VERSION 3.20 )

project( testprj )

message ( STATUS "CMAKE_COMMAND = ${CMAKE_COMMAND}" )

add_executable( ${PROJECT_NAME}
    main.cpp
)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo
    "TARGET_FILE:${PROJECT_NAME} = " $<TARGET_FILE:${PROJECT_NAME}>
    "TARGET_FILE_BASE_NAME:${PROJECT_NAME} = " $<TARGET_FILE_BASE_NAME:${PROJECT_NAME}>
)