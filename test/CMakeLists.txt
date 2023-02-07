cmake_minimum_required(VERSION 3.15)

##################################################################
# Project details
##################################################################

project(
  container.test
  LANGUAGES CXX
)

##################################################################
# Project Options
##################################################################

option(EnableValgrind    "Execute test suite with Valgrind." OFF)
option(EnableFastTests   "Skip expensive/slow tests." OFF)

set(32bitTest     AUTO CACHE STRING "Enable the 32bit unit test (ON/OFF/AUTO/ONLY).")
set(TestStandards "" CACHE STRING "The list of standards to test explicitly.")

##################################################################
# Import testing framework
##################################################################

if(GCC_VERSION VERSION_LESS 5.0)
  message(STATUS "GCC version is less than 5.0, using gtest-1.8.0")
  add_subdirectory(libs/gtest-1.8.0 EXCLUDE_FROM_ALL)
else()
  message(STATUS "GCC version is greater than or equal to 5.0, using gtest-1.8.1")
  add_subdirectory(libs/gtest-1.8.1 EXCLUDE_FROM_ALL)
endif()



##################################################################
# Setup Valgrind
##################################################################

if(EnableValgrind)
    include(Valgrind)
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

##################################################################
# Build Target
##################################################################

set(test_exe src/all.cc)

add_executable(
    container.test
    ${test_exe}
)

##################################################################
# Set CXX standards
##################################################################

# set cxx standard

if(TestStandards STREQUAL "11")
    message(STATUS "testing library against c++11")
    target_compile_features( container.test PUBLIC cxx_std_11 )
elseif(TestStandards STREQUAL "14" AND compiler_supports_cpp_14)
    message(STATUS "testing library against c++14")
    target_compile_features( container.test PUBLIC cxx_std_14 )
elseif(TestStandards STREQUAL "17" AND compiler_supports_cpp_17)
    message(STATUS "testing library against c++17")
    target_compile_features( container.test PUBLIC cxx_std_17 )
elseif(TestStandards STREQUAL "20" AND compiler_supports_cpp_20)
    message(STATUS "testing library against c++20")
    target_compile_features( container.test PUBLIC cxx_std_20 )
elseif(TestStandards STREQUAL "23" AND compiler_supports_cpp_23)
    message(STATUS "testing library against c++20")
    target_compile_features( container.test PUBLIC cxx_std_20 )
else()
    message(WARNING "forcing testing library against c++11, because requested standard is not supported by this compiler")
    target_compile_features( container.test PUBLIC cxx_std_11 )
endif()


# link gtest to executable target
target_link_libraries(
    container.test
    PUBLIC
    GTest::gtest_main
    ${GOOGLE_MOCK_LIBRARIES}
)

# include directories
message(STATUS "linking directories to target '${test_exe}' ..")
target_include_directories(
    container.test
    PUBLIC
    ${CMAKE_SOURCE_DIR}/test/include
    ${CMAKE_SOURCE_DIR}/include
)

# add unit tests
message(STATUS "Adding unit tests")

include(GoogleTest)
gtest_discover_tests(container.test)
