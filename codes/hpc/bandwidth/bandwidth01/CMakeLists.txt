cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set ( PRJ_COMPILE_FEATURES )
set ( PRJ_LIBRARIES )

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_23 )

find_package ( benchmark REQUIRED )
find_package ( TBB )
find_package ( OpenMP REQUIRED )

message( STATUS "TBB_FOUND = ${TBB_FOUND}" )

list ( APPEND PRJ_LIBRARIES benchmark::benchmark )
list ( APPEND PRJ_LIBRARIES TBB::tbb )
list ( APPEND PRJ_LIBRARIES OpenMP::OpenMP_CXX )

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
