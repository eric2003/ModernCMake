# look at each path and try to find ifconsol.lib
message ( STATUS "MYDEBUG detect.cmake ENV{LIB} = $ENV{LIB}" )
set(LIB "$ENV{LIB}")
foreach(dir ${LIB})
  file(TO_CMAKE_PATH "${dir}" dir)
  message ( STATUS "MYDEBUG dir = ${dir}" )
  if(EXISTS "${dir}/ifconsol.lib")
    message ( STATUS "MYDEBUG EXISTS ${dir}/ifconsol.lib" )
    file(WRITE output.cmake "list(APPEND implicit_dirs \"${dir}\")\n")
    break()
  endif()
endforeach()
