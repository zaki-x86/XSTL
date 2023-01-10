set(ENV{CC} ${{ matrix.config.cc }})

set(ENV{CXX} ${{ matrix.config.cxx }})

if ("${{ runner.os }}" STREQUAL "Windows" AND NOT "x${{ matrix.config.environment_script }}" STREQUAL "x")

    execute_process(
        COMMAND "${{ matrix.config.environment_script }}" && set
        OUTPUT_FILE environment_script_output.txt
    )

    file(STRINGS environment_script_output.txt output_lines)

    foreach(line IN LISTS output_lines)
        if (line MATCHES "^([a-zA-Z0-9_-]+)=(.*)$")
            set(ENV{${CMAKE_MATCH_1}} "${CMAKE_MATCH_2}")
        endif()
    endforeach()
endif()

set(path_separator ":")
if ("${{ runner.os }}" STREQUAL "Windows")
  set(path_separator ";")
endif()

set(ENV{PATH} "$ENV{GITHUB_WORKSPACE}${path_separator}$ENV{PATH}")

execute_process(
    COMMAND cmake
      -S .
      -B build
      -D CMAKE_BUILD_TYPE=$ENV{BUILD_TYPE}
      -G Ninja
      -D CMAKE_MAKE_PROGRAM=ninja
      -D CMAKE_C_COMPILER_LAUNCHER=ccache
      -D CMAKE_CXX_COMPILER_LAUNCHER=ccache
      -D TEST_ALL=ON
    RESULT_VARIABLE result
)

if (NOT result EQUAL 0)
  message(FATAL_ERROR "Bad exit status")
endif()