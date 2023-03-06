find_program(CMAKE_MEMORYCHECK_COMMAND valgrind)
message(STATUS "Executing test suite with Valgrind (${CMAKE_MEMORYCHECK_COMMAND})")
set(memcheck_command "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1 --leak-check=full")
separate_arguments(memcheck_command)