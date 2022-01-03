cmake_minimum_required(VERSION 3.15)

project ( myprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

find_package(HDF5 REQUIRED)

if ( HDF5_FOUND )
	list ( APPEND PRJ_LIBRARIES ${HDF5_LIBRARIES} )
	list ( APPEND PRJ_INCLUDE_DIRS ${HDF5_INCLUDE_DIRS} )
endif ()

add_executable( ${PROJECT_NAME} 
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
	PRIVATE 
		${PRJ_COMPILE_FEATURES}
)

