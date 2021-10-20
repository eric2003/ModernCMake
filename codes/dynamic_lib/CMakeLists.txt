cmake_minimum_required ( VERSION 3.15 )

project ( FooLibTest )

set ( PackageName "Foo" )
set ( INCLUDE_INSTALL_DIR include )
set ( LIB_INSTALL_DIR lib  )
set ( LIB_NAME "foolib" )

if ( CMAKE_SYSTEM_NAME MATCHES "Linux" )
	set ( LIB_NAME_STATIC "foolib" )
elseif ( CMAKE_SYSTEM_NAME MATCHES "Windows" )
	set ( LIB_NAME_STATIC "foolib_static" )
endif()

add_library ( ${LIB_NAME_STATIC}
	STATIC
		${CMAKE_CURRENT_SOURCE_DIR}/src/foo.cpp
)

target_include_directories ( ${LIB_NAME_STATIC} 
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library ( ${LIB_NAME}
	SHARED
		${CMAKE_CURRENT_SOURCE_DIR}/src/foo.cpp
)

target_include_directories ( ${LIB_NAME} 
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties ( ${LIB_NAME}
	PROPERTIES 
		PUBLIC_HEADER 
			${CMAKE_CURRENT_SOURCE_DIR}/include/foo.h
)

target_compile_definitions ( ${LIB_NAME}
	PRIVATE
		BUILD_DLL
)

add_executable ( app 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries ( app 
	PRIVATE 
		${LIB_NAME}
)

target_include_directories ( app
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

set ( dest ${LIB_INSTALL_DIR}/cmake/${PackageName} )

include ( CMakePackageConfigHelpers )
configure_package_config_file ( ${PackageName}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
  INSTALL_DESTINATION ${dest}
  PATH_VARS INCLUDE_INSTALL_DIR
)
  
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
  VERSION 1.2.3
  COMPATIBILITY AnyNewerVersion
)

install ( 
    TARGETS ${LIB_NAME} ${LIB_NAME_STATIC} app
    EXPORT ${PackageName}Targets
    RUNTIME DESTINATION bin 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
 
install ( 
    EXPORT ${PackageName}Targets
    NAMESPACE FooSpace::
    DESTINATION ${dest}
)
        
install (
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PackageName}ConfigVersion.cmake
    DESTINATION ${dest}
)