function (vtk_module_third_party)
  cmake_parse_arguments(_vtk_third_party
    ""
    ""
    "INTERNAL;EXTERNAL"
    ${ARGN})

  if (_vtk_third_party_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "Unparsed arguments for vtk_module_third_party: "
      "${_vtk_third_party_UNPARSED_ARGUMENTS}")
  endif ()

  string(REPLACE "::" "_" _vtk_build_module_safe "${_vtk_build_module}")
  option("VTK_MODULE_USE_EXTERNAL_${_vtk_build_module_safe}"
    "Use externally provided ${_vtk_build_module}"
    "${_vtk_build_USE_EXTERNAL}")
  mark_as_advanced("VTK_MODULE_USE_EXTERNAL_${_vtk_build_module_safe}")
  get_property(_vtk_third_party_library_name GLOBAL
    PROPERTY "_vtk_module_${_vtk_build_module}_library_name")
  set("VTK_MODULE_USE_EXTERNAL_${_vtk_third_party_library_name}"
    "${VTK_MODULE_USE_EXTERNAL_${_vtk_build_module_safe}}"
    PARENT_SCOPE)

  if (VTK_MODULE_USE_EXTERNAL_${_vtk_build_module_safe})
    # XXX(cmake): https://gitlab.kitware.com/cmake/cmake/issues/16364.
    # Unset a variable which CMake doesn't like when switching between real
    # libraries (internal) and interface libraries (external).
    unset("${_vtk_build_module}_LIB_DEPENDS" CACHE)
    vtk_module_third_party_external(${_vtk_third_party_EXTERNAL})

    # Bubble up variables again.
    foreach (_vtk_third_party_variable IN LISTS _vtk_third_party_variables)
      set("${_vtk_third_party_variable}"
        "${${_vtk_third_party_variable}}"
        PARENT_SCOPE)
    endforeach ()
  else ()
    set(_vtk_third_party_has_external_support 1)
    vtk_module_third_party_internal(${_vtk_third_party_INTERNAL})
  endif ()
endfunction ()