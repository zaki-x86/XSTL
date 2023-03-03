##########################################################################
# Source: https://github.com/nlohmann/json
##########################################################################

# number of parallel jobs for CTest
set(N 10)

file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/include/xstl/*.hpp
    ${PROJECT_SOURCE_DIR}/include/xstl/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/include/xstl/*.cpp
    ${PROJECT_SOURCE_DIR}/include/xstl/*.c
    ${PROJECT_SOURCE_DIR}/test/src/*.cpp
    ${PROJECT_SOURCE_DIR}/test/src/*.c
    ${PROJECT_SOURCE_DIR}/test/src/*.hpp
    ${PROJECT_SOURCE_DIR}/test/src/*.h
    ${PROJECT_SOURCE_DIR}/test/include/*.cpp
    ${PROJECT_SOURCE_DIR}/test/include/*.c
    ${PROJECT_SOURCE_DIR}/test/include/*.hpp
    ${PROJECT_SOURCE_DIR}/test/include/*.h
    ${PROJECT_SOURCE_DIR}/test/benchmarks/src/benchmarks.cpp
    ${PROJECT_SOURCE_DIR}/docs/examples/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${PROJECT_SOURCE_DIR}/include/xstl/*.hpp
    ${PROJECT_SOURCE_DIR}/include/xstl/*.h
)
###############################################################################
# Needed tools.
###############################################################################

include(FindPython3)
find_package(Python3 COMPONENTS Interpreter)

find_program(ASTYLE_TOOL NAMES astyle)
execute_process(COMMAND ${ASTYLE_TOOL} --version OUTPUT_VARIABLE ASTYLE_TOOL_VERSION ERROR_VARIABLE ASTYLE_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" ASTYLE_TOOL_VERSION "${ASTYLE_TOOL_VERSION}")
message(STATUS "🔖 Artistic Style ${ASTYLE_TOOL_VERSION} (${ASTYLE_TOOL})")

find_program(CLANG_TOOL NAMES clang++-HEAD clang++-16 clang++-15 clang++-14 clang++-13 clang++-12 clang++-11 clang++)
execute_process(COMMAND ${CLANG_TOOL} --version OUTPUT_VARIABLE CLANG_TOOL_VERSION ERROR_VARIABLE CLANG_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" CLANG_TOOL_VERSION "${CLANG_TOOL_VERSION}")
message(STATUS "🔖 Clang ${CLANG_TOOL_VERSION} (${CLANG_TOOL})")

find_program(CLANG_TIDY_TOOL NAMES clang-tidy-15 clang-tidy-14 clang-tidy-13 clang-tidy-12 clang-tidy-11 clang-tidy)
execute_process(COMMAND ${CLANG_TIDY_TOOL} --version OUTPUT_VARIABLE CLANG_TIDY_TOOL_VERSION ERROR_VARIABLE CLANG_TIDY_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" CLANG_TIDY_TOOL_VERSION "${CLANG_TIDY_TOOL_VERSION}")
message(STATUS "🔖 Clang-Tidy ${CLANG_TIDY_TOOL_VERSION} (${CLANG_TIDY_TOOL})")

message(STATUS "🔖 CMake ${CMAKE_VERSION} (${CMAKE_COMMAND})")

find_program(CPPCHECK_TOOL NAMES cppcheck)
execute_process(COMMAND ${CPPCHECK_TOOL} --version OUTPUT_VARIABLE CPPCHECK_TOOL_VERSION ERROR_VARIABLE CPPCHECK_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" CPPCHECK_TOOL_VERSION "${CPPCHECK_TOOL_VERSION}")
message(STATUS "🔖 Cppcheck ${CPPCHECK_TOOL_VERSION} (${CPPCHECK_TOOL})")

find_program(GCC_TOOL NAMES g++-latest g++-HEAD g++-12 g++-11 g++-10)
execute_process(COMMAND ${GCC_TOOL} --version OUTPUT_VARIABLE GCC_TOOL_VERSION ERROR_VARIABLE GCC_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" GCC_TOOL_VERSION "${GCC_TOOL_VERSION}")
message(STATUS "🔖 GCC ${GCC_TOOL_VERSION} (${GCC_TOOL})")

find_program(GCOV_TOOL NAMES gcov-HEAD gcov-11 gcov-10 gcov)
execute_process(COMMAND ${GCOV_TOOL} --version OUTPUT_VARIABLE GCOV_TOOL_VERSION ERROR_VARIABLE GCOV_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" GCOV_TOOL_VERSION "${GCOV_TOOL_VERSION}")
message(STATUS "🔖 GCOV ${GCOV_TOOL_VERSION} (${GCOV_TOOL})")

find_program(GIT_TOOL NAMES git)
execute_process(COMMAND ${GIT_TOOL} --version OUTPUT_VARIABLE GIT_TOOL_VERSION ERROR_VARIABLE GIT_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" GIT_TOOL_VERSION "${GIT_TOOL_VERSION}")
message(STATUS "🔖 Git ${GIT_TOOL_VERSION} (${GIT_TOOL})")

find_program(IWYU_TOOL NAMES include-what-you-use iwyu)
execute_process(COMMAND ${IWYU_TOOL} --version OUTPUT_VARIABLE IWYU_TOOL_VERSION ERROR_VARIABLE IWYU_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" IWYU_TOOL_VERSION "${IWYU_TOOL_VERSION}")
message(STATUS "🔖 include-what-you-use ${IWYU_TOOL_VERSION} (${IWYU_TOOL})")

find_program(INFER_TOOL NAMES infer)
execute_process(COMMAND ${INFER_TOOL} --version OUTPUT_VARIABLE INFER_TOOL_VERSION ERROR_VARIABLE INFER_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" INFER_TOOL_VERSION "${INFER_TOOL_VERSION}")
message(STATUS "🔖 Infer ${INFER_TOOL_VERSION} (${INFER_TOOL})")

find_program(LCOV_TOOL NAMES lcov)
execute_process(COMMAND ${LCOV_TOOL} --version OUTPUT_VARIABLE LCOV_TOOL_VERSION ERROR_VARIABLE LCOV_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" LCOV_TOOL_VERSION "${LCOV_TOOL_VERSION}")
message(STATUS "🔖 LCOV ${LCOV_TOOL_VERSION} (${LCOV_TOOL})")

find_program(NINJA_TOOL NAMES ninja)
execute_process(COMMAND ${NINJA_TOOL} --version OUTPUT_VARIABLE NINJA_TOOL_VERSION ERROR_VARIABLE NINJA_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" NINJA_TOOL_VERSION "${NINJA_TOOL_VERSION}")
message(STATUS "🔖 Ninja ${NINJA_TOOL_VERSION} (${NINJA_TOOL})")

find_program(OCLINT_TOOL NAMES oclint-json-compilation-database)
find_program(OCLINT_VERSION_TOOL NAMES oclint)
execute_process(COMMAND ${OCLINT_VERSION_TOOL} --version OUTPUT_VARIABLE OCLINT_TOOL_VERSION ERROR_VARIABLE OCLINT_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" OCLINT_TOOL_VERSION "${OCLINT_TOOL_VERSION}")
message(STATUS "🔖 OCLint ${OCLINT_TOOL_VERSION} (${OCLINT_TOOL})")

find_program(VALGRIND_TOOL NAMES valgrind)
execute_process(COMMAND ${VALGRIND_TOOL} --version OUTPUT_VARIABLE VALGRIND_TOOL_VERSION ERROR_VARIABLE VALGRIND_TOOL_VERSION)
string(REGEX MATCH "[0-9]+(\\.[0-9]+)+" VALGRIND_TOOL_VERSION "${VALGRIND_TOOL_VERSION}")
message(STATUS "🔖 Valgrind ${VALGRIND_TOOL_VERSION} (${VALGRIND_TOOL})")

find_program(GENHTML_TOOL NAMES genhtml)
find_program(PLOG_CONVERTER_TOOL NAMES plog-converter)
find_program(PVS_STUDIO_ANALYZER_TOOL NAMES pvs-studio-analyzer)
find_program(SCAN_BUILD_TOOL NAMES scan-build-15 scan-build-14 scan-build-13 scan-build-12 scan-build-11 scan-build)

########################################################################
# default gcc compiler test

## Removed CXXFLAGS="${GCC_CXXFLAGS}" b/c it enables aggressive warnings for all targets, even 3rd party targets (gtest). In order to avoid this, i am subjecting the specified target directory to these warnings
########################################################################
add_custom_target(ci_test_gcc
    COMMAND CXX=${GCC_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_gcc
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_gcc
    COMMAND cd ${PROJECT_BINARY_DIR}/build_gcc && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMENT "Compile and test with GCC using maximal warning flags"
)

########################################################################
# default clang compiler test
########################################################################
add_custom_target(ci_test_clang
    COMMAND CXX=${CLANG_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_clang
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_clang
    COMMAND cd ${PROJECT_BINARY_DIR}/build_clang && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMENT "Compile and test with Clang using maximal warning flags"
)

###############################################################################
# Different C++ Standards.
###############################################################################

foreach(CXX_STANDARD 11 14 17 20)
    add_custom_target(ci_test_gcc_cxx${CXX_STANDARD}
        COMMAND CXX=${GCC_TOOL} ${CMAKE_COMMAND}
            -DCMAKE_BUILD_TYPE=Debug -GNinja
            -DXSTLEnableTesting=ON 
            -DXSTLTestStandard=${CXX_STANDARD}
            -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_gcc_cxx${CXX_STANDARD}
        COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_gcc_cxx${CXX_STANDARD}
        COMMAND cd ${PROJECT_BINARY_DIR}/build_gcc_cxx${CXX_STANDARD} && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
        COMMENT "Compile and test with GCC for C++${CXX_STANDARD}"
    )

    add_custom_target(ci_test_clang_cxx${CXX_STANDARD}
        COMMAND CXX=${CLANG_TOOL} ${CMAKE_COMMAND}
            -DCMAKE_BUILD_TYPE=Debug -GNinja
            -DXSTLEnableTesting=ON 
            -DXSTLTestStandard=${CXX_STANDARD}
            -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_clang_cxx${CXX_STANDARD}
        COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_clang_cxx${CXX_STANDARD}
        COMMAND cd ${PROJECT_BINARY_DIR}/build_clang_cxx${CXX_STANDARD} && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
        COMMENT "Compile and test with Clang for C++${CXX_STANDARD}"
    )
endforeach()

###############################################################################
# Disable exceptions.
###############################################################################

add_custom_target(ci_test_noexceptions
    COMMAND ${CMAKE_COMMAND}
    -DCMAKE_BUILD_TYPE=Debug -GNinja
    -DXSTLEnableTesting=ON -DXSTLEnableExceptions=OFF
    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_noexceptions
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_noexceptions
    COMMAND cd ${PROJECT_BINARY_DIR}/build_noexceptions && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMENT "Compile and test with exceptions switched off"
)

###############################################################################
# Disable implicit conversions.
###############################################################################

#add_custom_target(ci_test_noimplicitconversions
#    COMMAND ${CMAKE_COMMAND}
#    -DCMAKE_BUILD_TYPE=Debug -GNinja
#    -DXSTLEnableTesting=ON -DJSON_ImplicitConversions=OFF
#    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_noimplicitconversions
#    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_noimplicitconversions
#    COMMAND cd ${PROJECT_BINARY_DIR}/build_noimplicitconversions && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
#    COMMENT "Compile and test with implicit conversions switched off"
#)
#
###############################################################################
# Enable improved diagnostics.
###############################################################################

#add_custom_target(ci_test_diagnostics
#    COMMAND ${CMAKE_COMMAND}
#    -DCMAKE_BUILD_TYPE=Debug -GNinja
#    -DXSTLEnableTesting=ON -DJSON_Diagnostics=ON
#    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_diagnostics
#    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_diagnostics
#    COMMAND cd ${PROJECT_BINARY_DIR}/build_diagnostics && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
#    COMMENT "Compile and test with improved diagnostics enabled"
#)
#
###############################################################################
# Enable legacy discarded value comparison.
###############################################################################

#add_custom_target(ci_test_legacycomparison
#    COMMAND ${CMAKE_COMMAND}
#    -DCMAKE_BUILD_TYPE=Debug -GNinja
#    -DXSTLEnableTesting=ON -DJSON_LegacyDiscardedValueComparison=ON
#    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_legacycomparison
#    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_legacycomparison
#    COMMAND cd ${PROJECT_BINARY_DIR}/build_legacycomparison && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
#    COMMENT "Compile and test with legacy discarded value comparison enabled"
#)

###############################################################################
# Disable global UDLs.
###############################################################################

#add_custom_target(ci_test_noglobaludls
#    COMMAND ${CMAKE_COMMAND}
#    -DCMAKE_BUILD_TYPE=Debug -GNinja
#    -DXSTLEnableTesting=ON  -DJSON_GlobalUDLs=OFF
#    -DCMAKE_CXX_FLAGS=-DJSON_TEST_NO_GLOBAL_UDLS
#    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_noglobaludls
#    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_noglobaludls
#    COMMAND cd ${PROJECT_BINARY_DIR}/build_noglobaludls && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
#    COMMENT "Compile and test with global UDLs disabled"
#)

###############################################################################
# Coverage.

## MAYFAIL Need to check where html directory is created to see the coverage report
###############################################################################
# FIXME  Coverage is not working
add_custom_target(ci_test_coverage
    COMMAND CXX=g++ ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja -DCMAKE_CXX_FLAGS="--coverage;-fprofile-arcs;-ftest-coverage"
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_coverage
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_coverage
    COMMAND cd ${PROJECT_BINARY_DIR}/build_coverage && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure

    # No 32bit tests are considered -- yet --
    # COMMAND CXX=g++ ${CMAKE_COMMAND}
    #    -DCMAKE_BUILD_TYPE=Debug -GNinja -DCMAKE_CXX_FLAGS="-m32;--coverage;-fprofile-arcs;-ftest-coverage"
    #    -DXSTLEnableTesting=ON
    #    -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_coverage32
    # COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_coverage32
    # COMMAND cd ${PROJECT_BINARY_DIR}/build_coverage32 && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMAND ${LCOV_TOOL} --directory . --capture --output-file xstl.info --rc lcov_branch_coverage=1
    COMMAND ${LCOV_TOOL} -e xstl.info ${SRC_FILES} --output-file xstl.info.filtered --rc lcov_branch_coverage=1
    # MAYFAIL permission denied error was raised, so I add python interpreter to the command
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/test/utils/imapdl/filterbr.py xstl.info.filtered > xstl.info.filtered.noexcept
    COMMAND genhtml --title "XSTL for Modern C++" --legend --demangle-cpp --output-directory html --show-details --branch-coverage xstl.info.filtered.noexcept

    COMMENT "Compile and test with coverage"
)

###############################################################################
# Sanitizers.
###############################################################################

set(CLANG_CXX_FLAGS_SANITIZER "-g -O1 -fsanitize=address -fsanitize=undefined -fsanitize=integer -fsanitize=nullability -fno-omit-frame-pointer -fno-sanitize-recover=all -fno-sanitize=unsigned-integer-overflow -fno-sanitize=unsigned-shift-base")

add_custom_target(ci_test_clang_sanitizer
    COMMAND CXX=${CLANG_TOOL} CXXFLAGS=${CLANG_CXX_FLAGS_SANITIZER} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_clang_sanitizer
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_clang_sanitizer
    COMMAND cd ${PROJECT_BINARY_DIR}/build_clang_sanitizer && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMENT "Compile and test with sanitizers"
)

###############################################################################
# Check if header is amalgamated and sources are properly indented.
###############################################################################

set(ASTYLE_FLAGS --style=allman --indent=spaces=4 --indent-modifiers --indent-switches --indent-preproc-block --indent-preproc-define --indent-col1-comments --pad-oper --pad-header --align-pointer=type --align-reference=type --add-brackets --convert-tabs --close-templates --lineend=linux --preserve-date --formatted)

add_custom_target(ci_test_identation
   COMMAND ${ASTYLE_TOOL} ${ASTYLE_FLAGS} ${SRC_FILES}
   # TODO Understand what the next line does exactly
   COMMAND for FILE in `find . -name '*.orig'`\; do false \; done

   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
   COMMENT "Check indentation"
)

###############################################################################
# Valgrind.

## Run all tests that has a label "valgrind"
## FIXME 
## MAYFAIL 
###############################################################################

add_custom_target(ci_test_valgrind
    COMMAND CXX=${GCC_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON -DXSTLEnableValgrind=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_valgrind
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_valgrind
    COMMAND cd ${PROJECT_BINARY_DIR}/build_valgrind && ${CMAKE_CTEST_COMMAND} -L valgrind --parallel ${N} --output-on-failure
    COMMENT "Compile and test with Valgrind"
)

###############################################################################
# Check code with Clang Static Analyzer.
###############################################################################

set(CLANG_ANALYZER_CHECKS "fuchsia.HandleChecker,nullability.NullableDereferenced,nullability.NullablePassedToNonnull,nullability.NullableReturnedFromNonnull,optin.cplusplus.UninitializedObject,optin.cplusplus.VirtualCall,optin.mpi.MPI-Checker,optin.osx.OSObjectCStyleCast,optin.osx.cocoa.localizability.EmptyLocalizationContextChecker,optin.osx.cocoa.localizability.NonLocalizedStringChecker,optin.performance.GCDAntipattern,optin.performance.Padding,optin.portability.UnixAPI,security.FloatLoopCounter,security.insecureAPI.DeprecatedOrUnsafeBufferHandling,security.insecureAPI.bcmp,security.insecureAPI.bcopy,security.insecureAPI.bzero,security.insecureAPI.rand,security.insecureAPI.strcpy,valist.CopyToSelf,valist.Uninitialized,valist.Unterminated,webkit.NoUncountedMemberChecker,webkit.RefCntblBaseVirtualDtor,core.CallAndMessage,core.DivideZero,core.NonNullParamChecker,core.NullDereference,core.StackAddressEscape,core.UndefinedBinaryOperatorResult,core.VLASize,core.uninitialized.ArraySubscript,core.uninitialized.Assign,core.uninitialized.Branch,core.uninitialized.CapturedBlockVariable,core.uninitialized.UndefReturn,cplusplus.InnerPointer,cplusplus.Move,cplusplus.NewDelete,cplusplus.NewDeleteLeaks,cplusplus.PlacementNew,cplusplus.PureVirtualCall,deadcode.DeadStores,nullability.NullPassedToNonnull,nullability.NullReturnedFromNonnull,osx.API,osx.MIG,osx.NumberObjectConversion,osx.OSObjectRetainCount,osx.ObjCProperty,osx.SecKeychainAPI,osx.cocoa.AtSync,osx.cocoa.AutoreleaseWrite,osx.cocoa.ClassRelease,osx.cocoa.Dealloc,osx.cocoa.IncompatibleMethodTypes,osx.cocoa.Loops,osx.cocoa.MissingSuperCall,osx.cocoa.NSAutoreleasePool,osx.cocoa.NSError,osx.cocoa.NilArg,osx.cocoa.NonNilReturnValue,osx.cocoa.ObjCGenerics,osx.cocoa.RetainCount,osx.cocoa.RunLoopAutoreleaseLeak,osx.cocoa.SelfInit,osx.cocoa.SuperDealloc,osx.cocoa.UnusedIvars,osx.cocoa.VariadicMethodTypes,osx.coreFoundation.CFError,osx.coreFoundation.CFNumber,osx.coreFoundation.CFRetainRelease,osx.coreFoundation.containers.OutOfBounds,osx.coreFoundation.containers.PointerSizedValues,security.insecureAPI.UncheckedReturn,security.insecureAPI.decodeValueOfObjCType,security.insecureAPI.getpw,security.insecureAPI.gets,security.insecureAPI.mkstemp,security.insecureAPI.mktemp,security.insecureAPI.vfork,unix.API,unix.Malloc,unix.MallocSizeof,unix.MismatchedDeallocator,unix.Vfork,unix.cstring.BadSizeArg,unix.cstring.NullArg")

add_custom_target(ci_clang_analyze
    COMMAND CXX=${CLANG_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_clang_analyze
    COMMAND cd ${PROJECT_BINARY_DIR}/build_clang_analyze && ${SCAN_BUILD_TOOL} -enable-checker ${CLANG_ANALYZER_CHECKS} --use-c++=${CLANG_TOOL} -analyze-headers -o ${PROJECT_BINARY_DIR}/report ninja
    COMMENT "Check code with Clang Analyzer"
)

###############################################################################
# Check code with Cppcheck.

# MAYFAIL
###############################################################################

add_custom_target(ci_cppcheck
    COMMAND ${CPPCHECK_TOOL} --language=c++ --enable=warning --suppress=missingReturn --inline-suppr --inconclusive --force --std=c++11 ${SRC_FILES} --error-exitcode=1
    COMMENT "Check code with Cppcheck"
)

###############################################################################
# Check code with cpplint.
###############################################################################

add_custom_target(ci_cpplint
    COMMAND ${Python3_EXECUTABLE} -mvenv venv_cpplint
    COMMAND venv_cpplint/bin/pip3 --quiet install cpplint
    COMMAND venv_cpplint/bin/cpplint --filter=-whitespace,-legal,-runtime/references,-runtime/explicit,-runtime/indentation_namespace,-readability/casting,-readability/nolint --quiet --recursive ${SRC_FILES}
    COMMENT "Check code with cpplint"
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)



###############################################################################
# Check code with Clang-Tidy.
###############################################################################

add_custom_target(ci_clang_tidy
    COMMAND CXX=${CLANG_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_CLANG_TIDY=${CLANG_TIDY_TOOL}
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_clang_tidy
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_clang_tidy
    COMMENT "Check code with Clang-Tidy"
)

###############################################################################
# Check code with PVS-Studio Analyzer <https://www.viva64.com/en/pvs-studio/>.
###############################################################################

add_custom_target(ci_pvs_studio
    COMMAND CXX=${CLANG_TOOL} ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
        -DXSTLEnableTesting=ON
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_pvs_studio
    COMMAND cd ${PROJECT_BINARY_DIR}/build_pvs_studio && ${PVS_STUDIO_ANALYZER_TOOL} analyze -j 10
    COMMAND cd ${PROJECT_BINARY_DIR}/build_pvs_studio && ${PLOG_CONVERTER_TOOL} -a'GA:1,2;64:1;CS' -t fullhtml PVS-Studio.log -o pvs
    COMMENT "Check code with PVS Studio"
)

###############################################################################
# Check code with Infer <https://fbinfer.com> static analyzer.
###############################################################################

add_custom_target(ci_infer
    COMMAND mkdir -p ${PROJECT_BINARY_DIR}/build_infer
    COMMAND cd ${PROJECT_BINARY_DIR}/build_infer && ${INFER_TOOL} compile -- ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${PROJECT_SOURCE_DIR} -DXSTLEnableTesting=ON
    COMMAND cd ${PROJECT_BINARY_DIR}/build_infer && ${INFER_TOOL} run -- make
    COMMENT "Check code with Infer"
)


###############################################################################
# Run test suite when project was not checked out from Git
###############################################################################

add_custom_target(ci_non_git_tests
    COMMAND git config --global --add safe.directory ${PROJECT_SOURCE_DIR}
    COMMAND mkdir -p ${PROJECT_BINARY_DIR}/build_non_git_tests/sources
    COMMAND cd ${PROJECT_SOURCE_DIR} && for FILE in `${GIT_TOOL} ls-tree --name-only HEAD`\; do cp -r $$FILE ${PROJECT_BINARY_DIR}/build_non_git_tests/sources \; done
    COMMAND ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON 
        -S${PROJECT_BINARY_DIR}/build_non_git_tests/sources -B${PROJECT_BINARY_DIR}/build_non_git_tests
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_non_git_tests
    COMMAND cd ${PROJECT_BINARY_DIR}/build_non_git_tests && ${CMAKE_CTEST_COMMAND} --parallel ${N} -LE git_required --output-on-failure
    COMMENT "Check code when project was not checked out from Git"
)

###############################################################################
# Run test suite and exclude tests that change installed files

# MAYFAIL
###############################################################################

add_custom_target(ci_reproducible_tests
    COMMAND ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON 
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_reproducible_tests
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_reproducible_tests
    COMMAND cd ${PROJECT_BINARY_DIR}/build_reproducible_tests && ${CMAKE_CTEST_COMMAND} --parallel ${N} -LE not_reproducible --output-on-failure
    COMMENT "Check code and exclude tests that change installed files"
)

###############################################################################
# Check if every header in the include folder includes sufficient headers to
# be compiled individually.
###############################################################################

set(iwyu_path_and_options ${IWYU_TOOL} -Xiwyu --max_line_length=300)

foreach(SRC_FILE ${HEADER_FILES})
    # get relative path of the header file
    file(RELATIVE_PATH RELATIVE_SRC_FILE "${PROJECT_SOURCE_DIR}/include/xstl" "${SRC_FILE}")
    # replace slashes and strip suffix
    string(REPLACE "/" "_" RELATIVE_SRC_FILE "${RELATIVE_SRC_FILE}")
    string(REPLACE ".hpp" "" RELATIVE_SRC_FILE "${RELATIVE_SRC_FILE}")
    # create code file
    file(WRITE "${PROJECT_BINARY_DIR}/src_single/${RELATIVE_SRC_FILE}.cpp" "#include \"${SRC_FILE}\" // IWYU pragma: keep\n\nint main()\n{}\n")
    # create executable
    add_executable(single_${RELATIVE_SRC_FILE} EXCLUDE_FROM_ALL ${PROJECT_BINARY_DIR}/src_single/${RELATIVE_SRC_FILE}.cpp)
    target_include_directories(single_${RELATIVE_SRC_FILE} PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_compile_features(single_${RELATIVE_SRC_FILE} PRIVATE cxx_std_11)
    set_property(TARGET single_${RELATIVE_SRC_FILE} PROPERTY CXX_INCLUDE_WHAT_YOU_USE "${iwyu_path_and_options}")
    # remember binary for ci_single_binaries target
    list(APPEND single_binaries single_${RELATIVE_SRC_FILE})
endforeach()

add_custom_target(ci_single_binaries
    DEPENDS ${single_binaries}
    COMMENT "Check if headers are self-contained"
)

###############################################################################
# Benchmarks

# TODO CI Benchmarks
###############################################################################

#add_custom_target(ci_benchmarks
#    COMMAND ${CMAKE_COMMAND}
#        -DCMAKE_BUILD_TYPE=Release -GNinja
#        -S${PROJECT_SOURCE_DIR}/benchmarks -B${PROJECT_BINARY_DIR}/build_benchmarks
#    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_benchmarks --target json_benchmarks
#    COMMAND cd ${PROJECT_BINARY_DIR}/build_benchmarks && ./json_benchmarks
#    COMMENT "Run benchmarks"
#)
#
###############################################################################
# CMake flags
###############################################################################

# function(ci_get_cmake version var)
#     set(${var} ${PROJECT_BINARY_DIR}/cmake-${version}/bin/cmake)
#     add_custom_command(
#         OUTPUT ${${var}}
#         COMMAND wget -nc https://github.com/Kitware/CMake/releases/download/v${version}/cmake-${version}.tar.gz
#         COMMAND tar xfz cmake-${version}.tar.gz
#         COMMAND rm cmake-${version}.tar.gz
#         COMMAND ${CMAKE_COMMAND} -S cmake-${version} -B cmake-${version}
#         COMMAND ${CMAKE_COMMAND} --build cmake-${version} --parallel 10
#         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
#         COMMENT "Download CMake ${version}"
#     )
#     set(${var} ${${var}} PARENT_SCOPE)
# endfunction()

# ci_get_cmake(3.1.0 CMAKE_3_1_0_BINARY)
# ci_get_cmake(3.13.0 CMAKE_3_13_0_BINARY)

# set(JSON_CMAKE_FLAGS_3_1_0 JSON_Diagnostics JSON_GlobalUDLs JSON_ImplicitConversions JSON_DisableEnumSerialization
#     JSON_LegacyDiscardedValueComparison JSON_Install JSON_MultipleHeaders JSON_SystemInclude JSON_Valgrind)
# set(JSON_CMAKE_FLAGS_3_13_0 JSON_BuildTests)

# function(ci_add_cmake_flags_targets flag min_version)
#     string(TOLOWER "ci_cmake_flag_${flag}" flag_target)
#     string(REPLACE . _ min_version_var ${min_version})
#     set(cmake_binary ${CMAKE_${min_version_var}_BINARY})
#     add_custom_target(${flag_target}
#         COMMENT "Check CMake flag ${flag} (CMake ${CMAKE_VERSION})"
#         COMMAND ${CMAKE_COMMAND}
#             -Werror=dev
#             -D${flag}=ON
#             -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_${flag_target}
#     )
#     add_custom_target(${flag_target}_${min_version_var}
#         COMMENT "Check CMake flag ${JSON_CMAKE_FLAG} (CMake ${min_version})"
#         COMMAND mkdir -pv ${PROJECT_BINARY_DIR}/build_${flag_target}_${min_version_var}
#         COMMAND cd ${PROJECT_BINARY_DIR}/build_${flag_target}_${min_version_var}
#             && ${cmake_binary} -Werror=dev ${PROJECT_SOURCE_DIR} -D${flag}=ON
#         DEPENDS ${cmake_binary}
#     )
#     list(APPEND JSON_CMAKE_FLAG_TARGETS ${JSON_CMAKE_FLAG_TARGET} ${flag_target}_${min_version_var})
#     list(APPEND JSON_CMAKE_FLAG_BUILD_DIRS ${PROJECT_BINARY_DIR}/build_${flag_target} ${PROJECT_BINARY_DIR}/build_${flag_target}_${min_version_var})
#     set(JSON_CMAKE_FLAG_TARGETS ${JSON_CMAKE_FLAG_TARGETS} PARENT_SCOPE)
#     set(JSON_CMAKE_FLAG_BUILD_DIRS ${JSON_CMAKE_FLAG_BUILD_DIRS} PARENT_SCOPE)
# endfunction()

# foreach(JSON_CMAKE_FLAG ${JSON_CMAKE_FLAGS_3_1_0})
#     ci_add_cmake_flags_targets(${JSON_CMAKE_FLAG} 3.1.0)
# endforeach()

# foreach(JSON_CMAKE_FLAG ${JSON_CMAKE_FLAGS_3_13_0})
#     ci_add_cmake_flags_targets(${JSON_CMAKE_FLAG} 3.13.0)
# endforeach()

# add_custom_target(ci_cmake_flags
#     DEPENDS ${JSON_CMAKE_FLAG_TARGETS}
#     COMMENT "Check CMake flags"
# )

###############################################################################
# Use more installed compilers.
###############################################################################

foreach(COMPILER g++-4.8 g++-4.9 g++-5 g++-6 g++-7 g++-8 g++-9 g++-10 g++-11 clang++-3.5 clang++-3.6 clang++-3.7 clang++-3.8 clang++-3.9 clang++-4.0 clang++-5.0 clang++-6.0 clang++-7 clang++-8 clang++-9 clang++-10 clang++-11 clang++-12 clang++-13 clang++-14)
    find_program(COMPILER_TOOL NAMES ${COMPILER})
    if (COMPILER_TOOL)
        unset(ADDITIONAL_FLAGS)

        add_custom_target(ci_test_compiler_${COMPILER}
            COMMAND CXX=${COMPILER} ${CMAKE_COMMAND}
                -DCMAKE_BUILD_TYPE=Debug -GNinja
                -DXSTLEnableTesting=ON 
                -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_compiler_${COMPILER}
                ${ADDITIONAL_FLAGS}
            COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_compiler_${COMPILER}
            COMMAND cd ${PROJECT_BINARY_DIR}/build_compiler_${COMPILER} && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
            COMMENT "Compile and test with ${COMPILER}"
        )
    endif()
    unset(COMPILER_TOOL CACHE)
endforeach()

add_custom_target(ci_test_compiler_default
    COMMAND ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DXSTLEnableTesting=ON 
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_compiler_default
        ${ADDITIONAL_FLAGS}
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_compiler_default --parallel ${N}
    COMMAND cd ${PROJECT_BINARY_DIR}/build_compiler_default && ${CMAKE_CTEST_COMMAND} --parallel ${N} -LE git_required --output-on-failure
    COMMENT "Compile and test with default C++ compiler"
)

###############################################################################
# Intel C++ Compiler
###############################################################################

add_custom_target(ci_icpc
    COMMAND ${CMAKE_COMMAND}
        -DCMAKE_BUILD_TYPE=Debug -GNinja
        -DCMAKE_C_COMPILER=icc -DCMAKE_CXX_COMPILER=icpc
        -DXSTLEnableTesting=ON 
        -S${PROJECT_SOURCE_DIR} -B${PROJECT_BINARY_DIR}/build_icpc
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/build_icpc
    COMMAND cd ${PROJECT_BINARY_DIR}/build_icpc && ${CMAKE_CTEST_COMMAND} --parallel ${N} --output-on-failure
    COMMENT "Compile and test with ICPC"
)

###############################################################################
# test documentation

# TODO
###############################################################################

# add_custom_target(ci_test_examples
#     COMMAND make CXX="${GCC_TOOL}" check_output_portable -j8
#     WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/docs
#     COMMENT "Check that all examples compile and create the desired output"
# )

# add_custom_target(ci_test_api_documentation
#     COMMAND ${Python3_EXECUTABLE} scripts/check_structure.py
#     WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/docs/mkdocs
#     COMMENT "Lint the API documentation"
# )

###############################################################################
# Clean up all generated files.
###############################################################################

add_custom_target(ci_clean
    COMMAND rm -fr ${PROJECT_BINARY_DIR}/build_* cmake-3.1.0-Darwin64 ${single_binaries}
    COMMENT "Clean generated directories"
)