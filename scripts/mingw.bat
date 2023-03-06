@echo off
rem Set the variables
set CMAKE_PATH=C:\Program Files\CMake\bin
set PATH=%CMAKE_PATH%;%PATH%

rem Configure the project
cmake -S . -B build/mingw64 -G Ninja -D CMAKE_CXX_COMPILER=g++.exe -D XSTLEnableTesting=ON -D XSTLWarningsAsErrors=OFF

if %ERRORLEVEL% neq 0 (
  echo "CMake configuration failed."
  exit /b %ERRORLEVEL%
)

rem Build the project
cmake --build build/mingw64

if %ERRORLEVEL% neq 0 (
  echo "Build failed."
  exit /b %ERRORLEVEL%
)

rem Run tests
ctest --test-dir build/mingw64 --output-on-failure --rerun-failed --extra-verbose

if %ERRORLEVEL% neq 0 (
  echo "Tests failed."
  exit /b %ERRORLEVEL%
)

echo "Build and tests completed successfully."
exit /b 0
