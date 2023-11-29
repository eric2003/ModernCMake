cmake_minimum_required(VERSION 3.28)

project(testprj)

set( url https://file-examples.com/storage/fe83b11fb06553bbba686e7/2017/02/ )
set( filename file_example_JSON_1kb.json )


message ( STATUS "url = ${url}" )
message ( STATUS "filename = ${filename}" )

file ( DOWNLOAD ${url} ${filename} )
