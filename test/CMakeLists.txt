##################################################################################
# Define test options

# TODO : Define test options
##################################################################################

option(XSTLEnableValgrind   ""  OFF)
option(XSTLFastTests        ""  OFF)

set(XSTLTestStandard     ""  CACHE STRING "cxx standard to set explicitly")

if(XSTLEnableValgrind)
    find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
    message(STATUS "Executing test suite with Valgrind (${CMAKE_MEMORYCHECK_COMMAND})")
    set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1 --leak-check=full")
    separate_arguments(memcheck_command)
endif()

#############################################################################
# detect standard support
#############################################################################

# C++11 is the minimum required
set(compiler_supports_cpp_11 TRUE)

foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
    if (${feature} STREQUAL cxx_std_14)
        set(compiler_supports_cpp_14 TRUE)
    elseif (${feature} STREQUAL cxx_std_17)
        set(compiler_supports_cpp_17 TRUE)
    elseif (${feature} STREQUAL cxx_std_20)
        set(compiler_supports_cpp_20 TRUE)
    elseif (${feature} STREQUAL cxx_std_23)
        set(compiler_supports_cpp_23 TRUE)
    endif()
endforeach()

##################################################################################
# Override standard support

# source : https://github.com/nlohmann/json/blob/develop/tests/CMakeLists.txt
##################################################################################

# Clang only supports C++17 starting from Clang 5.0
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
    unset(compiler_supports_cpp_17)
endif()
# MSVC 2015 (14.0) does not support C++17
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.1)
    unset(compiler_supports_cpp_17)
endif()

# Clang C++20 support appears insufficient prior to Clang 9.0 (based on CI build failure)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
    unset(compiler_supports_cpp_20)
endif()
# GCC started supporting C++20 features in 8.0 but a test for #3070 segfaults prior to 9.0
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.0)
    unset(compiler_supports_cpp_20)
endif()

##################################################################################
# Adding tests

# source : https://github.com/nlohmann/json/blob/develop/tests/CMakeLists.txt
##################################################################################

#
# Load the desired unit testing framework
#

include(GoogleTest)

set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)

verbose_message("Adding tests ...")

file(GLOB TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

foreach(file ${TEST_SRCS})
    get_filename_component(TEST_NAME ${file} NAME_WE)
    add_executable(${TEST_NAME} ${file})

  #
  # Set the compiler standard
  #

  if(XSTLTestStandard STREQUAL "14" AND compiler_supports_cpp_14)
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_14)
  elseif(XSTLTestStandard STREQUAL "17" AND compiler_supports_cpp_17)
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_17)
  elseif(XSTLTestStandard STREQUAL "20" AND compiler_supports_cpp_20)
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_20)
  elseif(XSTLTestStandard STREQUAL "23" AND compiler_supports_cpp_23)
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_23)
  else()
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_11)
  endif()
  

    target_include_directories(
        ${TEST_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

    target_link_libraries(
        ${TEST_NAME}
        zicx::xstl
        GTest::gtest_main
    #    Only if needed, uncomment line below
    #    ${GOOGLE_MOCK_LIBRARIES}
    )
    

    #
    # Add the unit tests
    #
    #add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})  
    gtest_discover_tests(${TEST_NAME})


endforeach()

verbose_message("Finished adding unit tests for ${PROJECT_NAME_LOWERCASE}.")