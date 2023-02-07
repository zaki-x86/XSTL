cmake_minimum_required(VERSION 3.15)

project(array.test)

include(GoogleTest)

message(STATUS "gtest found: " ${GTEST_FOUND})

# build test executable
set(test_exe runner.cc)

add_executable(
    ${PROJECT_NAME}
    ${test_exe}
)

# set cxx standard
target_compile_features( ${PROJECT_NAME} PUBLIC cxx_std_11 )

# link gtest to executable target
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    GTest::gtest_main
    ${GOOGLE_MOCK_LIBRARIES}
)

# include directories
message(STATUS "linking directories to target '${test_exe}' ..")
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/test/include
    ${CMAKE_SOURCE_DIR}/include
)

# add unit tests
message(STATUS "Adding unit tests")
gtest_discover_tests(${PROJECT_NAME})