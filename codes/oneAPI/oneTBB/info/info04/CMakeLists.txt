cmake_minimum_required(VERSION 3.15)

project ( testprj )

find_package ( TBB )

message( STATUS "TBB_FOUND = ${TBB_FOUND}" )
message( STATUS "TBB_VERSION = ${TBB_VERSION}" )
message( STATUS "TBB_VERSION_MAJOR = ${TBB_VERSION_MAJOR}" )
message( STATUS "TBB_VERSION_MINOR = ${TBB_VERSION_MINOR}" )