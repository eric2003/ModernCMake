cmake_minimum_required ( VERSION 3.20 )

project ( testprj )

function(echo_target tgt)
    if(NOT TARGET ${tgt})
        message("There is no target named '${tgt}'")
        return()
    endif()

    set(props
        DEBUG_OUTPUT_NAME
        DEBUG_POSTFIX
        RELEASE_OUTPUT_NAME
        LINK_SEARCH_START_STATIC
        LOCATION
        LOCATION_DEBUG
        WIN32_EXECUTABLE
        XCODE_ATTRIBUTE_WHATEVER
    )
    message ( STATUS "props=${props}" )
    message ( STATUS "======================== ${tgt} ========================" )

    # Push the current (NEW) CMake policy onto the stack, and apply the OLD policy.
    cmake_policy(PUSH)
    cmake_policy(SET CMP0026 OLD)

    foreach(p ${props})
        # v for value, d for defined, s for set
        get_property(v TARGET ${tgt} PROPERTY ${p})
        get_property(d TARGET ${tgt} PROPERTY ${p} DEFINED)
        get_property(s TARGET ${tgt} PROPERTY ${p} SET)
        message ( STATUS "p=${p}" )
        message ( STATUS "v=${v}" )
        message ( STATUS "d=${d}" )
        message ( STATUS "s=${s}" )
        # only produce output for values that are set
        if( s )
            message(STATUS "tgt='${tgt}' p='${p}'")
            message(STATUS "  value='${v}'")
            message(STATUS "  defined='${d}'")
            message(STATUS "  set='${s}'")
            message(STATUS "")
        endif()
    endforeach()

    # Pop the previous policy from the stack to re-apply the NEW behavior.
    cmake_policy(POP)

    message(STATUS "")
endfunction()

add_executable ( ${PROJECT_NAME}
    main.cpp
)

target_include_directories ( ${PROJECT_NAME}
    PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries( ${PROJECT_NAME} 
    PUBLIC 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_COMPILE_FEATURES}
)

#echo_target( ${PROJECT_NAME} )
echo_target( haha )
echo_target( ${PROJECT_NAME} )
