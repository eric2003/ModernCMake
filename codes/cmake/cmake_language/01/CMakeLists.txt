cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

set(message_command "message")
cmake_language(CALL ${message_command} STATUS "Hello World!")