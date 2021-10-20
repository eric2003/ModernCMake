cmake_minimum_required ( VERSION 3.15 )

project ( app )

find_package ( Foo )

message ( STATUS "Foo_FOUND = ${Foo_FOUND}" )
message ( STATUS "Foo_LIBRARIES = ${Foo_LIBRARIES}" )
message ( STATUS "Foo_LIBRARIES_STATIC = ${Foo_LIBRARIES_STATIC}" )
message ( STATUS "PROJECT_NAME = ${PROJECT_NAME}" )

add_executable ( ${PROJECT_NAME}
	main.cpp
)

target_compile_definitions ( ${PROJECT_NAME}
	PRIVATE
		USE_DLL
)

target_link_libraries ( ${PROJECT_NAME}
	PRIVATE
		${Foo_LIBRARIES}
)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE
		${Foo_INCLUDE_DIR}
)

set( app_static ${PROJECT_NAME}_static )

add_executable ( ${app_static}
	main.cpp
)

target_link_libraries ( ${app_static}
	PRIVATE
		${Foo_LIBRARIES_STATIC}
)

target_include_directories ( ${app_static}
	PRIVATE
		${Foo_INCLUDE_DIR}
)


add_executable ( app_static_namespace
	main.cpp
)

target_link_libraries ( app_static_namespace
	PRIVATE
		FooSpace::foolib_static
)

target_include_directories ( app_static_namespace
	PRIVATE
		${Foo_INCLUDE_DIR}
)

