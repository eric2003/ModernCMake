cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

add_library(sub OBJECT sub.c)

add_executable ( ${PROJECT_NAME}
    main.c
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        $<TARGET_OBJECTS:sub>
)

get_target_property(prj_LINK_LIBRARIES ${PROJECT_NAME}  LINK_LIBRARIES)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    prj_LINK_LIBRARIES = ${prj_LINK_LIBRARIES} &
    echo 
    TARGET_OBJECTS:sub = $<TARGET_OBJECTS:sub>
)
