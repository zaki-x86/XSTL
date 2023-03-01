cmake_minimum_required(VERSION 3.20)

project(array_example)

add_executable(array_example main.cpp)

target_link_libraries(array_example PRIVATE zicx::xstl)

