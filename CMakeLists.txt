
cmake_minimum_required(VERSION 3.21)

##################################################################################
# Project details
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
# MAIN_PROJECT CHECK

## determine if project is built as a subproject (using add_subdirectory) or if it is the main project
##################################################################################

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

##################################################################################
# Setup the include path
##################################################################################

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})

include(StaticAnalyzers)
include(Utils)
##################################################################################
# Set project options
##################################################################################

option(BuildExe "Build the project as an executable, rather than a library." OFF)
option(BuildHeadersOnly "Build the project as a header-only library." OFF)
option(UseAltNames "Use alternative names for the project, such as naming the include directory all lowercase." ON)
option(WarningsAsErrors "Treat compiler warnings as errors." OFF)

# Package Managers
option(EnableConan "Enable the Conan package manager for this project." OFF)
option(EnableVcPkg "Enable the Vcpkg package manager for this project." OFF)

option(EnableTesting "Enable unit tests for the projects (from the `test` subfolder)." ${MAIN_PROJECT})
option(EnableCi "Enable CI build targets." OFF)

option(UseGTest "Use the GoogleTest library for creating unit tests." ON)
option(UseGMock "Use the GoogleMock library for extending the unit tests." OFF)
option(UseCatch2 "Use the Catch2 library for creating unit tests." OFF)
option(UseDoctest "Use the Doctest library for creating unit tests." OFF)

option(EnableClangTidy "Enable static analysis with Clang-Tidy." OFF)
option(EnableCppCheck "Enable static analysis with Cppcheck." OFF)

option(EnableCodeCoverage "Enable code coverage through GCC." OFF)

option(EnableDoxygen "Enable Doxygen documentation builds of source." OFF)

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(VerboseOutput "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(GenerateExportHeader "Create a `project_export.h` file containing all exported symbols." OFF)
option(EnableLTO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)." OFF)
option(EnableCCache "Enable the usage of Ccache, in order to speed up rebuild times." ON)

# Export all symbols when building a shared library
if(BUILD_SHARED_LIBS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()

if(EnableLTO)
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
message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

if (UNIX)
    add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
endif (UNIX)


#
# Setup alternative names
#

if(UseAltNames)
  string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
  string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
else()
  set(PROJECT_NAME_LOWERCASE ${PROJECT_NAME})
  set(PROJECT_NAME_UPPERCASE ${PROJECT_NAME})
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

if (EnableCi)
    include(ci)
endif ()

##################################################################################
# Enable package managers
##################################################################################

include(Conan)
include(Vcpkg)


##################################################################################
# Add configuration related header files
##################################################################################

#
# Add version header

## Only if project is built as a main project
#

if(MAIN_PROJECT)
    configure_file(
      ${CMAKE_CURRENT_LIST_DIR}/include/config/version.h.in
      ${CMAKE_CURRENT_SOURCE_DIR}/include/config/version.h
      @ONLY
    )
    install(
      FILES
      ${CMAKE_CURRENT_SOURCE_DIR}/include/config/version.h
      DESTINATION
      include/config
    )
endif()

#
# Add config header

## Only if project is built as a main project
#

if(MAIN_PROJECT)
    configure_file(
      ${CMAKE_CURRENT_LIST_DIR}/include/config/config.h.in
      ${CMAKE_CURRENT_SOURCE_DIR}/include/config/config.h
      @ONLY
    )
    install(
      FILES
      ${CMAKE_CURRENT_SOURCE_DIR}/include/config/config.h
      DESTINATION
      include/config
    )
endif()

verbose_message("Successfully generated configuration files.")


##################################################################################
# Create library, setup headers and source files
##################################################################################

#
# Find all headers and implementation files
#

file(GLOB_RECURSE CONTAINER_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/container/*")
file(GLOB_RECURSE CONFIG_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/config/*.h")

set(HEADER_FILES ${CONTAINER_HEADER_FILES} ${CONFIG_HEADER_FILES})
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} INTERFACE)

if(VerboseOutput)
    verbose_message("Found the following headers:")
    
    foreach(HEADER_FILE ${HEADER_FILES})
        verbose_message("* ${HEADER_FILE}")
    endforeach()
endif()

message(STATUS "Added all header and implementation files.\n")


#
# Provide alias to library for
#

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

verbose_message("Project is now aliased as ${PROJECT_NAME}::${PROJECT_NAME}.\n")

#
# Set Target Properties
#

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
)

#
# Set the build/user include directories
#

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${INC_DIR}>
     $<BUILD_INTERFACE:${INC_DIR}/container>
)

message(STATUS "Finished setting up include directories.")

#
# Check if the library is being built as a shared library
#

if(BUILD_SHARED_LIBS)
    message(STATUS "Building ${PROJECT_NAME} as a shared library")
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DBUILD_SHARED)
else()
    message(STATUS "Building ${PROJECT_NAME} as a static library")
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DBUILD_STATIC)
endif()


##################################################################################
# Set the project standard and warnings
##################################################################################

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

verbose_message("Applied compiler warnings. Using standard ${CMAKE_CXX_STANDARD}.\n")

##################################################################################
##################################################################################

#
# Enable Doxygen
#

# include(Doxygen)

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
# Install the `include` directory
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
# Generate export header if specified
##################################################################################

if(GenerateExportHeader)
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
# Unit testing setup
##################################################################################

if(EnableTesting)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()


