cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

add_library(sub OBJECT sub.c)

add_executable ( ${PROJECT_NAME}
    main.c
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        sub
)