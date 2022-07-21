cmake_minimum_required ( VERSION 3.20 )

project ( sub )

get_directory_property( my_directory_parent PARENT_DIRECTORY )

message( STATUS "my_directory_parent=${my_directory_parent}" )