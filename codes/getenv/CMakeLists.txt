cmake_minimum_required(VERSION 3.15)

project ( test )

set ( PRJ_COMPILE_FEATURES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

add_executable( test
    main.cpp
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
