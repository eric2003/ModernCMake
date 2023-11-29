cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

message ( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message ( STATUS "CMAKE_GENERIC_PROGRAM_FILES = ${CMAKE_GENERIC_PROGRAM_FILES}" )
message ( STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
message ( STATUS "ENV{ProgramW6432} = $ENV{ProgramW6432}" )
message ( STATUS "ENV{ProgramFiles} = $ENV{ProgramFiles}" )
message ( STATUS "ENV{ProgramFiles\(x86\)} = $ENV{ProgramFiles\(x86\)}" )

function(GetDefaultWindowsPrefixBase var)

  # Try to guess what architecture targets will end up being built as,
  # even if CMAKE_SIZEOF_VOID_P is not computed yet... We need to know
  # the architecture of the targets being built to choose the right
  # default value for CMAKE_INSTALL_PREFIX.
  #
  if("${CMAKE_GENERATOR}" MATCHES "(Win64|IA64)")
    set(arch_hint "x64")
  elseif("${CMAKE_GENERATOR_PLATFORM}" MATCHES "x64")
    set(arch_hint "x64")
  elseif("${CMAKE_GENERATOR_PLATFORM}" MATCHES "ARM64")
    set(arch_hint "ARM64")
  elseif("${CMAKE_GENERATOR}" MATCHES "ARM")
    set(arch_hint "ARM")
  elseif("${CMAKE_GENERATOR_PLATFORM}" MATCHES "ARM")
    set(arch_hint "ARM")
  elseif("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
    set(arch_hint "x64")
  elseif("$ENV{LIB}" MATCHES "(amd64|ia64)")
    set(arch_hint "x64")
  endif()
  
  message ( STATUS "arch_hint = ${arch_hint}" )

  if(NOT arch_hint)
    set(arch_hint "x86")
  endif()

  # default env in a 64-bit app on Win64:
  # ProgramFiles=C:\Program Files
  # ProgramFiles(x86)=C:\Program Files (x86)
  # ProgramW6432=C:\Program Files
  #
  # default env in a 32-bit app on Win64:
  # ProgramFiles=C:\Program Files (x86)
  # ProgramFiles(x86)=C:\Program Files (x86)
  # ProgramW6432=C:\Program Files
  #
  # default env in a 32-bit app on Win32:
  # ProgramFiles=C:\Program Files
  # ProgramFiles(x86) NOT DEFINED
  # ProgramW6432 NOT DEFINED

  # By default, use the ProgramFiles env var as the base value of
  # CMAKE_INSTALL_PREFIX:
  #
  set(_PREFIX_ENV_VAR "ProgramFiles")
  
  message ( STATUS "_PREFIX_ENV_VAR = ${_PREFIX_ENV_VAR}" )

  if ("$ENV{ProgramW6432}" STREQUAL "")
    # running on 32-bit Windows
    # must be a 32-bit CMake, too...
    #message("guess: this is a 32-bit CMake running on 32-bit Windows")
  else()
    # running on 64-bit Windows
    if ("$ENV{ProgramW6432}" STREQUAL "$ENV{ProgramFiles}")
      # 64-bit CMake
      #message("guess: this is a 64-bit CMake running on 64-bit Windows")
      if(NOT "${arch_hint}" STREQUAL "x64")
      # building 32-bit targets
        set(_PREFIX_ENV_VAR "ProgramFiles(x86)")
      endif()
    else()
      # 32-bit CMake
      #message("guess: this is a 32-bit CMake running on 64-bit Windows")
      if("${arch_hint}" STREQUAL "x64")
      # building 64-bit targets
        set(_PREFIX_ENV_VAR "ProgramW6432")
      endif()
    endif()
  endif()
  message ( STATUS "_PREFIX_ENV_VAR = ${_PREFIX_ENV_VAR}" )

  #if("${arch_hint}" STREQUAL "x64")
  #  message("guess: you are building a 64-bit app")
  #else()
  #  message("guess: you are building a 32-bit app")
  #endif()

  if(NOT "$ENV{${_PREFIX_ENV_VAR}}" STREQUAL "")
    file(TO_CMAKE_PATH "$ENV{${_PREFIX_ENV_VAR}}" _base)
  elseif(NOT "$ENV{SystemDrive}" STREQUAL "")
    set(_base "$ENV{SystemDrive}/Program Files")
  else()
    set(_base "C:/Program Files")
  endif()
  
  message ( STATUS "_base = ${_base}" )

  set(${var} "${_base}" PARENT_SCOPE)
endfunction()

GetDefaultWindowsPrefixBase(CMAKE_GENERIC_PROGRAM_FILES)

message ( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message ( STATUS "CMAKE_GENERIC_PROGRAM_FILES = ${CMAKE_GENERIC_PROGRAM_FILES}" )
message ( STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )

