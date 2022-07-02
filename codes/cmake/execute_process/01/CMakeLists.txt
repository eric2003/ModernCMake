cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

execute_process(COMMAND echo "hello world"
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                TIMEOUT 3
                RESULT_VARIABLE result_var
                OUTPUT_VARIABLE output_var
                ERROR_VARIABLE error_var
                OUTPUT_STRIP_TRAILING_WHITESPACE
                ERROR_STRIP_TRAILING_WHITESPACE
)

message( STATUS "result: ${result_var}" )
message( STATUS "output: ${output_var}" )
message( STATUS "error: ${error_var}" )