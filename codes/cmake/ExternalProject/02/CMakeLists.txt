cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

include(ExternalProject)

ExternalProject_Add(foobar
  GIT_REPOSITORY    git@github.com:eric2003/Foo.git
  GIT_TAG           0.0.1
)

 
#ExternalProject_Get_property(foobar PREFIX)
ExternalProject_Get_property(foobar TMP_DIR)
ExternalProject_Get_property(foobar STAMP_DIR)
ExternalProject_Get_property(foobar LOG_DIR)
ExternalProject_Get_property(foobar DOWNLOAD_DIR)
ExternalProject_Get_property(foobar SOURCE_DIR)
ExternalProject_Get_property(foobar BINARY_DIR)
ExternalProject_Get_property(foobar INSTALL_DIR)



#message( STATUS "PREFIX = ${PREFIX}" )
message( STATUS "TMP_DIR = ${TMP_DIR}" )
message( STATUS "STAMP_DIR = ${STAMP_DIR}" )
message( STATUS "LOG_DIR = ${LOG_DIR}" )
message( STATUS "DOWNLOAD_DIR = ${DOWNLOAD_DIR}" )
message( STATUS "SOURCE_DIR = ${SOURCE_DIR}" )
message( STATUS "BINARY_DIR = ${BINARY_DIR}" )
message( STATUS "INSTALL_DIR = ${INSTALL_DIR}" )
  

