cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_COMPILE_OPTIONS )
set ( PRJ_LIBRARIES )
set ( PRJ_SRCS )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

if ( MSVC )
    #list ( APPEND PRJ_COMPILE_OPTIONS /fp:fast /arch:AVX512 )
	#list ( APPEND PRJ_COMPILE_OPTIONS /fp:fast /arch:AVX /arch:AVX2 )
	list ( APPEND PRJ_COMPILE_OPTIONS /fp:fast /arch:AVX2 )
else()
	#list ( APPEND PRJ_COMPILE_OPTIONS -O3 -mavx512f )
    list ( APPEND PRJ_COMPILE_OPTIONS -ffast-math -march=native )
endif()

list ( APPEND PRJ_SRCS main.cpp )
list ( APPEND PRJ_SRCS boxblur.cpp )
list ( APPEND PRJ_SRCS gaussblur.cpp )
list ( APPEND PRJ_SRCS stb_image.cpp )
list ( APPEND PRJ_SRCS stb_image_write.cpp )
list ( APPEND PRJ_SRCS rwimage.cpp )
list ( APPEND PRJ_SRCS alignalloc.cpp )

add_executable( ${PROJECT_NAME}
    ${PRJ_SRCS}
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
