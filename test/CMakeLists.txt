cmake_minimum_required(VERSION 3.24)

#
# Project details
#

project(
  container.test
  LANGUAGES CXX
)

<<<<<<< HEAD
add_subdirectory(libs/gtest)

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
=======
option(TEST_ALL "toggle option to execute all unit tests from all test suites" ON)
option(TEST_ARRAY "toggle option to execute array container test cases" OFF)
option(TEST_DARRAY "toggle option to execute darray container test cases" OFF)
option(TEST_DEQUE "toggle option to execute deque container test cases" OFF)
option(TEST_FORWARD_LIST "toggle option to execute deque container test cases" OFF)
option(TEST_LIST "toggle option to execute deque container test cases" OFF)
option(TEST_SET "toggle option to execute set container test cases" OFF)
option(TEST_MULTISET "toggle option to execute multiset container test cases" OFF)
option(TEST_UNORDERED_SET "toggle option to execute unordered_set container test cases" OFF)
option(TEST_UNORDERED_MULTISET "toggle option to execute unordered_multiset container test cases" OFF)
option(TEST_MAP "toggle option to execute map container test cases" OFF)
option(TEST_MULTIMAP "toggle option to execute multimap container test cases" OFF)
option(TEST_UNORDERED_MAP "toggle option to execute unordered_map container test cases" OFF)
option(TEST_UNORDERED_MULTIMAP "toggle option to execute unordered_multimap container test cases" OFF)




if(TEST_ALL)
  add_subdirectory(container/array.test)
  add_subdirectory(container/darray.test)
  add_subdirectory(container/deque.test)
  add_subdirectory(container/forward_list.test)
  add_subdirectory(container/list.test)
  add_subdirectory(container/set.test)
  add_subdirectory(container/multiset.test)
  add_subdirectory(container/map.test)
  add_subdirectory(container/multimap.test)
  add_subdirectory(container/unordered_map.test)
  add_subdirectory(container/unordered_multimap.test)
  add_subdirectory(container/unordered_set.test)
  add_subdirectory(container/unordered_multiset.test)
elseif(TEST_ARRAY)
  add_subdirectory(container/array.test)
elseif(TEST_DARRAY)
  add_subdirectory(container/darray.test)
elseif(TEST_DEQUE)
  add_subdirectory(container/deque.test)
elseif(TEST_FORWARD_LIST)
  add_subdirectory(container/forward_list.test)
elseif(TEST_LIST)
  add_subdirectory(container/list.test)
elseif(TEST_SET)
  add_subdirectory(container/set.test)
elseif(TEST_MULTISET)
  add_subdirectory(container/multiset.test)
elseif(TEST_UNORDERED_SET)
  add_subdirectory(container/unordered_set.test)
elseif(TEST_UNORDERED_MULTISET)
  add_subdirectory(container/unordered_multiset.test)
elseif(TEST_MAP)
  add_subdirectory(container/map.test)
elseif(TEST_MULTIMAP)
  add_subdirectory(container/multimap.test)
elseif(TEST_UNORDERED_MAP)
  add_subdirectory(container/unordered_map.test)
elseif(TEST_UNORDERED_MULTIMAP)
  add_subdirectory(container/unordered_multimap.test)
endif()
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6
