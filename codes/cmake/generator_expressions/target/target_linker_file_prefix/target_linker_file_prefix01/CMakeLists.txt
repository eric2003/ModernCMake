cmake_minimum_required ( VERSION 3.20 )

project( testprj )

set ( MyLibName hello )

add_library( ${MyLibName} STATIC 
    hello.cpp
)

add_executable( ${PROJECT_NAME}
    main.cpp
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${MyLibName}
)

add_custom_target ( print 
    ${CMAKE_COMMAND} -E 
    echo 
    TARGET_FILE:${PROJECT_NAME} = $<TARGET_FILE:${PROJECT_NAME}> &
    echo 
    TARGET_FILE_BASE_NAME:${PROJECT_NAME} = $<TARGET_FILE_BASE_NAME:${PROJECT_NAME}> &
    echo 
    TARGET_FILE_PREFIX:${PROJECT_NAME} = $<TARGET_FILE_PREFIX:${PROJECT_NAME}> &
    echo 
    TARGET_FILE_SUFFIX:${PROJECT_NAME} = $<TARGET_FILE_SUFFIX:${PROJECT_NAME}> &
    echo 
    TARGET_FILE_NAME:${PROJECT_NAME} = $<TARGET_FILE_NAME:${PROJECT_NAME}> &
    echo 
    TARGET_LINKER_FILE:${MyLibName} = $<TARGET_LINKER_FILE:${MyLibName}> &
    echo 
    TARGET_LINKER_FILE_BASE_NAME:${MyLibName} = $<TARGET_LINKER_FILE_BASE_NAME:${MyLibName}> &
    echo 
    TARGET_LINKER_FILE_PREFIX:${MyLibName} = $<TARGET_LINKER_FILE_PREFIX:${MyLibName}>
)