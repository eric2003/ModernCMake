cmake_minimum_required(VERSION 3.15)

project ( myprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

list ( APPEND PRJ_COMPILE_DEF ENABLE_CGNS )
if ( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
	set ( CGNS_INCLUDE_DIRS "C:/cgns/include" CACHE PATH "path to CGNS headers" )
	set ( CGNS_LIBRARIES "C:/cgns/lib/cgnsdll.lib" CACHE PATH "path to CGNS library" )
endif()

list ( APPEND PRJ_LIBRARIES ${CGNS_LIBRARIES} )
list ( APPEND PRJ_INCLUDE_DIRS ${CGNS_INCLUDE_DIRS} )
	

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

