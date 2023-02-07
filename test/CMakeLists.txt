cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  container.test
  LANGUAGES CXX
)

add_subdirectory(libs/gtest EXCLUDE_FROM_ALL)

# option(TEST_ALL "toggle option to execute all unit tests from all test suites" ON)
# option(TEST_ARRAY "toggle option to execute array container test cases" OFF)
# option(TEST_DARRAY "toggle option to execute darray container test cases" OFF)
# option(TEST_DEQUE "toggle option to execute deque container test cases" OFF)
# option(TEST_FORWARD_LIST "toggle option to execute deque container test cases" OFF)
# option(TEST_LIST "toggle option to execute deque container test cases" OFF)

# if(TEST_ALL)
#   add_subdirectory(container/array.test)
#   add_subdirectory(container/darray.test)
#   add_subdirectory(container/deque.test)
#   add_subdirectory(container/forward_list.test)
#   add_subdirectory(container/list.test)
# elseif(TEST_ARRAY)
#   add_subdirectory(container/array.test)
# elseif(TEST_DARRAY)
#   add_subdirectory(container/darray.test)
# elseif(TEST_DEQUE)
#   add_subdirectory(container/deque.test)
# elseif(TEST_FORWARD_LIST)
#   add_subdirectory(container/forward_list.test)
# elseif(TEST_LIST)
#   add_subdirectory(container/list.test)
# endif()

# build test executable
set(test_exe src/all.cc)

add_executable(
    container.test
    ${test_exe}
)

# set cxx standard
target_compile_features( container.test PUBLIC cxx_std_11 )

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
