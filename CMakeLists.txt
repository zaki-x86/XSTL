
cmake_minimum_required(VERSION 3.21)

##################################################################################
##################################################################################

#
# Project details
#

project(
  container
  VERSION 0.1.0
  DESCRIPTION "An extension to the standard container library in c++"
  HOMEPAGE_URL ""
  LANGUAGES CXX
)

##################################################################################
##################################################################################

##
## MAIN_PROJECT CHECK
## determine if project is built as a subproject (using add_subdirectory) or if it is the main project
##
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

##################################################################################
##################################################################################

##
## Setup the include path
##
##
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})

##################################################################################
##################################################################################

#
# Set project options
#

include(Utils)

option(BuildTests "Build the unit tests when BUILD_TESTING is enabled." ${MAIN_PROJECT})
option(CI         "Enable CI build targets." OFF)
option(TreatWarningsAsErrors "Treat compiler warnings as errors." OFF)
option(EnableConan "Enable the Conan package manager for this project." OFF)
option(EnableVcPkg "Enable the Vcpkg package manager for this project." OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(${PROJECT_NAME}_VERBOSE_OUTPUT "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(${PROJECT_NAME}_GENERATE_EXPORT_HEADER "Create a `project_export.h` file containing all exported symbols." OFF)

if (CI)
    include(ci)
endif ()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

if (UNIX)
    add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
endif (UNIX)

##################################################################################
##################################################################################

#
# Setup alternative names
#

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)

##################################################################################
##################################################################################

#
# Prevent building in the source directory
#

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

##################################################################################
##################################################################################

#
# Enable package managers
#

include(Conan)
include(Vcpkg)

##################################################################################
##################################################################################

#
# Create library, setup header and source files
#

# Find all headers and implementation files
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# if(${PROJECT_NAME}_VERBOSE_OUTPUT)
#   verbose_message("Found the following headers:")
#   foreach(header IN LISTS visible_headers)
#     verbose_message("* ${header}")
#   endforeach()
# endif()

# Check if the library is being built as a shared library
if(BUILD_SHARED_LIBS)
    message(STATUS "Building ${PROJECT_NAME} as a shared library")
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DBUILD_SHARED)
else()
    message(STATUS "Building ${PROJECT_NAME} as a static library")
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DBUILD_STATIC)
endif()

#
# Set the build/user include directories
#

# Allow usage of header files in the `src` directory, but only for utilities

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
  $<INSTALL_INTERFACE:include/container>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
)

message(STATUS "Finished setting up include directories.")

message(STATUS "Added all header and implementation files.\n")
verbose_message("Project is now aliased as ${PROJECT_NAME}::${PROJECT_NAME}.\n")

##################################################################################
##################################################################################

#
# Set the project standard and warnings
#

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

verbose_message("Applied compiler warnings. Using standard ${CMAKE_CXX_STANDARD}.\n")

##################################################################################
##################################################################################

#
# Enable Doxygen
#

# include(cmake/Doxygen.cmake)

##################################################################################
##################################################################################

#
# Model project dependencies
#

# Identify and link with the specific "packages" the project uses
#find_package(package_name package_version REQUIRED package_type [other_options])
#target_link_libraries(
#  ${PROJECT_NAME}
#  PUBLIC
#    dependency1 ...
#  PRIVATE
#    dependency2 ...
#    ${PROJECT_NAME}_PROJECT_OPTIONS
#    ${PROJECT_NAME}_PROJECT_WARNINGS
#)
#if(${PROJECT_NAME}_BUILD_EXECUTABLE AND ${PROJECT_NAME}_ENABLE_UNIT_TESTING)
#  target_link_libraries(
#    ${PROJECT_NAME}_LIB
#    PUBLIC
#      dependency1 ...
#  )
#endif()

# For Windows, it is necessary to link with the MultiThreaded library.
# Depending on how the rest of the project's dependencies are linked, it might be necessary
# to change the line to statically link with the library.
#
# This is done as follows:
#
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#
# On Linux and Mac this variable is ignored. If any issues rise from it, try commenting it out
# and letting CMake decide how to link with it.
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

verbose_message("Successfully added all dependencies and linked against them.")

##################################################################################
##################################################################################


#
# Install library for easy downstream inclusion
#

include(GNUInstallDirs)
install(
  TARGETS
  ${PROJECT_NAME}
  EXPORT
  ${PROJECT_NAME}Targets
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
  ${PROJECT_NAME}Targets
  FILE
  ${PROJECT_NAME}Targets.cmake
  NAMESPACE
  ${PROJECT_NAME}::
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

##################################################################################
##################################################################################

#
# Add version header
#

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/version.hpp.in
  include/${PROJECT_NAME_LOWERCASE}/version.hpp
  @ONLY
)

install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME_LOWERCASE}/version.hpp
  DESTINATION
  include/${PROJECT_NAME_LOWERCASE}
)

##################################################################################
##################################################################################

#
# Install the `include` directory
#

install(
  DIRECTORY
  include/${PROJECT_NAME_LOWERCASE}
  DESTINATION
  include
)

verbose_message("Install targets successfully built. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

##################################################################################
##################################################################################

#
# Quick `ConfigVersion.cmake` creation
#

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION
  ${PROJECT_VERSION}
  COMPATIBILITY
  SameMajorVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

##################################################################################
##################################################################################

#
# Generate export header if specified
#

if(${PROJECT_NAME}_GENERATE_EXPORT_HEADER)
  include(GenerateExportHeader)
  generate_export_header(${PROJECT_NAME})
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
##################################################################################

#
# Unit testing setup
#

if(BuildTests)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()

##################################################################################
##################################################################################

#
# Examples setup
#

message(STATUS "Building dynamic_array examples: ")
#add_subdirectory(examples/darray)

