cmake_minimum_required(VERSION 3.15)

project ( testprj )

set ( PRJ_COMPILE_FEATURES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

find_package(TBB)

message( STATUS "TBB_FOUND = ${TBB_FOUND}" )

add_executable( ${PROJECT_NAME}
    main.cpp
)

target_link_libraries ( ${PROJECT_NAME}
	PRIVATE
		TBB::tbb
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)
