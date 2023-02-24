cmake_minimum_required(VERSION 3.20)

##################################################################################
# Project details

# TODO: Add project documentation website in HOMEPAGE_URL
# TODO : Add project description
# TODO: Configure automated version adjustment from a version.txt file
##################################################################################

project(
  XSTL
  VERSION 0.1.0
  DESCRIPTION ""
  LANGUAGES CXX
)

##################################################################################
# MAIN_PROJECT CHECK

# determine if project is built as a subproject (using add_subdirectory) or if it is the main project
##################################################################################

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
    message(STATUS "XSTL is being built as a main project")
endif()

##################################################################################
# Setup the include path
##################################################################################

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})
message(STATUS "Module path is set to: ${CMAKE_MODULE_PATH}")
include(Utils)

##################################################################################
# Set project options
##################################################################################

set(XSTL_TARGET ${PROJECT_NAME})

option(XSTLUseAltNames "Use alternative names for the project, such as naming the include directory all lowercase." ON)

# Package Managers
option(XSTLEnableConan "Enable the Conan package manager for this project." OFF)
option(XSTLEnableVcPkg "Enable the Vcpkg package manager for this project." OFF)

# TODO : EnableTesting should be OFF, it is ON for now when project is not built as a subproject
# prior to release 1.0.0 this option should be turned off
option(XSTLEnableTesting "Enable unit tests for the projects (from the `test` subfolder)." OFF)
option(XSTLEnableCi "Enable CI build targets." OFF)
option(XSTLEnableDoxygen "Enable Doxygen documentation builds of source." OFF)

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(XSTLVerboseOutput "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(XSTLGenerateExportHeader "Create a `project_export.h` file containing all exported symbols." OFF)
option(XSTLEnableLTO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)." OFF)
option(XSTLEnableCCache "Enable the usage of Ccache, in order to speed up rebuild times." ON)

# Export all symbols when building a shared library
if(BUILD_SHARED_LIBS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()

if(XSTLEnableLTO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT result OUTPUT output)
  if(result)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(SEND_ERROR "IPO is not supported: ${output}.")
  endif()
endif()

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Started CMake for ${XSTL_TARGET} v${PROJECT_VERSION}...\n")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if (UNIX)
    add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
  endif (UNIX)  
  message(STATUS "_DEBUG macro is added for debugging specific code\n")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")


#
# Setup alternative names
#

if(XSTLUseAltNames)
  string(TOLOWER ${XSTL_TARGET} PROJECT_NAME_LOWERCASE)
  string(TOUPPER ${XSTL_TARGET} PROJECT_NAME_UPPERCASE)
else()
  set(PROJECT_NAME_LOWERCASE ${XSTL_TARGET})
  set(PROJECT_NAME_UPPERCASE ${XSTL_TARGET})
endif()

#
# Prevent building in the source directory
#

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

##################################################################################
# Build CI/CD targets
##################################################################################

if(XSTLEnableCi)
  include(ci)
endif(XSTLEnableCi)

##################################################################################
# Enable package managers
##################################################################################

include(Conan)
include(Vcpkg)

##################################################################################
# Add configuration related header files
##################################################################################

set(VERSION_CONFIG_IN "${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/config/version.h.in")
set(VERSION_CONFIG_OUT "${CMAKE_CURRENT_SOURCE_DIR}/include/xstl/config/version.h")
set(VERSION_CONFIG_INSTALL_LOCATION "include/xstl/config")

set(XSTL_CONFIG_IN "${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/config/config.h.in")
set(XSTL_CONFIG_OUT "${CMAKE_CURRENT_SOURCE_DIR}/include/xstl/config/config.h")
set(XSTL_CONFIG_INSTALL_LOCATION "include/xstl/config")

#
# Add version header
#

configure_file(
  ${VERSION_CONFIG_IN}
  ${VERSION_CONFIG_OUT}
  @ONLY
)

install(
  FILES
  ${VERSION_CONFIG_OUT}
  DESTINATION
  ${VERSION_CONFIG_INSTALL_LOCATION}
)

#
# Add config header
## Only if project is built as a main project
#

configure_file(
  ${XSTL_CONFIG_IN}
  ${XSTL_CONFIG_OUT}
  @ONLY
)

install(
  FILES
  ${XSTL_CONFIG_OUT}
  DESTINATION
  ${XSTL_CONFIG_INSTALL_LOCATION}
)

verbose_message("Successfully generated configuration files for ${XSTL_TARGET}.")

##################################################################################
# Create library, setup headers and source files
##################################################################################

#
# Find all headers and implementation files
#

file(GLOB XSTL_HEADER_FILES "include/xstl/*.hpp")
file(GLOB_RECURSE XSTL_SOURCE_FILES "src/*.cpp")
file(GLOB XSTL_CONFIG_HEADER_FILES "include/xstl/config/*.h")

add_library(${XSTL_TARGET} ${XSTL_SOURCE_FILES})
if(XSTLVerboseOutput)
    verbose_message("Found the following headers:")
    foreach(HEADER_FILE ${XSTL_HEADER_FILES})
        verbose_message("* ${HEADER_FILE}")
    endforeach()

    if(XSTL_SOURCE_FILES)
      verbose_message("Found the following sources:")
      foreach(SOURCE_FILE ${XSTL_SOURCE_FILES})
        verbose_message("* ${SOURCE_FILE}")
      endforeach()
    endif(XSTL_SOURCE_FILES)
    
endif(XSTLVerboseOutput)

if(TARGET ${XSTL_TARGET})
  message(STATUS "Added all header and implementation files.\n")
endif(TARGET)


#
# Provide alias to library for
#

add_library(zicx::${PROJECT_NAME_LOWERCASE} ALIAS ${XSTL_TARGET})

verbose_message("Project is now aliased as zicx::${PROJECT_NAME_LOWERCASE}.\n")

#
# Set Target Properties
#

set_target_properties(
  ${XSTL_TARGET}
  PROPERTIES
  LINKER_LANGUAGE CXX
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
)


#
# Set the build/user include directories
#

target_include_directories(
    ${XSTL_TARGET}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

message(STATUS "Finished setting up include directories.")

#
# Check if the library is being built as a shared library
#

if(BUILD_SHARED_LIBS)
    message(STATUS "Building ${XSTL_TARGET} as a shared library")
    target_compile_definitions(${XSTL_TARGET} INTERFACE -DBUILD_SHARED)
else()
    message(STATUS "Building ${XSTL_TARGET} as a static library")
    target_compile_definitions(${XSTL_TARGET} INTERFACE -DBUILD_STATIC)
endif(BUILD_SHARED_LIBS)

##################################################################################
# Set the project standard and warnings
##################################################################################

target_compile_features(${XSTL_TARGET} INTERFACE cxx_std_11)

verbose_message("Applied compiler warnings. Using standard ${CMAKE_CXX_STANDARD}.\n")

##################################################################################
# Enable Doxygen

## TODO : Export xml docs
##################################################################################

# include(Doxygen)

##################################################################################
# Install library for easy downstream inclusion

## TODO : Debug and test if it works as expected
##################################################################################

include(GNUInstallDirs)
install(
  TARGETS
  ${XSTL_TARGET}
  EXPORT
  XSTLTargets
  LIBRARY DESTINATION
  ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION
  ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION
  ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION
  include
  PUBLIC_HEADER DESTINATION
  include
)

install(
  EXPORT
  XSTLTargets
  FILE
  XSTLTargets.cmake
  NAMESPACE
  xstl::
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/XSTL
)

##################################################################################
# Install the `include` directory

## TODO : Debug and test if it works as expected
##################################################################################

install(
  DIRECTORY
  include/${PROJECT_NAME_LOWERCASE}
  DESTINATION
  include
)

verbose_message("Install targets successfully built. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

##################################################################################
# Quick `ConfigVersion.cmake` creation

## TODO : Debug and test if it works as expected
## TODO : install src files
##################################################################################

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION
  ${PROJECT_VERSION}
  COMPATIBILITY
  SameMajorVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/XSTLConfig.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/XSTL
)

install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/XSTLConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/XSTLConfigVersion.cmake
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/XSTL
)

##################################################################################
# Generate export header if specified

# TODO : Debug and test if it works as expected
##################################################################################

if(GenerateExportHeader)
  include(GenerateExportHeader)
  generate_export_header(${XSTL_TARGET})
  install(
    FILES
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}_export.h
    DESTINATION
    include
  )

  message(STATUS "Generated the export header `${PROJECT_NAME_LOWERCASE}_export.h` and installed it.")
endif()

message(STATUS "Finished building requirements for installing the package.\n")

##################################################################################
# Unit testing setup

##################################################################################

if(XSTLEnableTesting)
  add_subdirectory(libs/googletest)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()