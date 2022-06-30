cmake_minimum_required(VERSION 3.15)

project(hello VERSION 1.0.0 LANGUAGES CXX)

# make cache variables for install destinations
include(GNUInstallDirs)

message( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}" )
message( STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}" )
message( STATUS "CMAKE_INSTALL_INCLUDEDIR = ${CMAKE_INSTALL_INCLUDEDIR}" )
message( STATUS "CMAKE_INSTALL_LIBDIR = ${CMAKE_INSTALL_LIBDIR}" )
message( STATUS "CMAKE_INSTALL_BINDIR = ${CMAKE_INSTALL_BINDIR}" )

# create library
add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME}
    INTERFACE
        cxx_std_11
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# install the target and create export-set
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# install header file
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

# generate and install export file
install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
# generate the version file for the config file
write_basic_package_version_file(
  "${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

if(NOT INCLUDE_INSTALL_DIR)
  set(INCLUDE_INSTALL_DIR include)
endif()

# create config file
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
  PATH_VARS INCLUDE_INSTALL_DIR
)
  
# install config files
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
)

# generate the export targets for the build tree
export(EXPORT ${PROJECT_NAME}_Targets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake"
       NAMESPACE ${PROJECT_NAME}::
)

