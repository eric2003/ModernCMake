cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_COMPILE_OPTIONS )
set ( PRJ_LIBRARIES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

if ( MSVC )
    list ( APPEND PRJ_COMPILE_OPTIONS /fp:fast /arch:AVX )
else()
    list ( APPEND PRJ_COMPILE_OPTIONS -ffast-math -march=native )
endif()

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

target_compile_options ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_OPTIONS}
)
