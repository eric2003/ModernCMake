cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

#set ( HAVE_SOME_FEATURE YES )

add_library(my_obj OBJECT bar.c)

#add_library(my_shared SHARED b.c c.c  $<$<BOOL:${HAVE_SOME_FEATURE}>:$<TARGET_OBJECTS:my_obj>> )
add_executable ( ${PROJECT_NAME}
    main.c
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        my_obj
)