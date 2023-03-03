#ifndef _XSTL_ASSERTIONS_H_
#define _XSTL_ASSERTIONS_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#endif

#include <xstl/config/config.h>
#include <doctest/doctest.h>


#define _xstl_assert(expr, ...) DOCTEST_CHECK_MESSAGE(expr, __VA_ARGS__)
#define _xstl_assert_eq(lhs, rhs) CHECK_EQ(lhs, rhs)
#define _xstl_assert_ne(lhs, rhs) CHECK_NE(lhs, rhs)
#define _xstl_assert_lt(lhs, rhs) CHECK_LT(lhs, rhs)
#define _xstl_assert_le(lhs, rhs) CHECK_LE(lhs, rhs)
#define _xstl_assert_gt(lhs, rhs) CHECK_GT(lhs, rhs)
#define _xstl_assert_ge(lhs, rhs) CHECK_GE(lhs, rhs)
#define _xstl_assert_throws(expr, exception) CHECK_THROWS_AS(expr, exception)
#define _xstl_assert_nothrow(expr) CHECK_NOTHROW(expr)
#define _xstl_assert_any_throw(expr) CHECK_THROWS(expr)
#define _xstl_require(expr, ...) DOCTEST_REQUIRE_MESSAGE(cond, __VA_ARGS__)
#define _xstl_require_eq(lhs, rhs) REQUIRE_EQ(lhs, rhs)
#define _xstl_require_ne(lhs, rhs) REQUIRE_NE(lhs, rhs)
#define _xstl_require_lt(lhs, rhs) REQUIRE_LT(lhs, rhs)
#define _xstl_require_le(lhs, rhs) REQUIRE_LE(lhs, rhs)
#define _xstl_require_gt(lhs, rhs) REQUIRE_GT(lhs, rhs)
#define _xstl_require_ge(lhs, rhs) REQUIRE_GE(lhs, rhs)
#define _xstl_require_throws(expr, exception) REQUIRE_THROWS_AS(expr, exception)
#define _xstl_require_nothrow(expr) REQUIRE_NOTHROW(expr)
#define _xstl_require_any_throw(expr) REQUIRE_THROWS(expr)


#ifdef XSTL_MSVC
#define ASSERT_DEATH(statement) \
  do { \
    __try { \
      statement; \
    } \
    __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? \
              EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) { \
      exit(EXIT_FAILURE); \
    } \
    exit(EXIT_SUCCESS); \
  } while (0)

long WINAPI MyUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo) {
  if (pExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
    TerminateProcess(GetCurrentProcess(), EXIT_FAILURE);
    return EXCEPTION_EXECUTE_HANDLER;
  }
  return EXCEPTION_CONTINUE_SEARCH;
}
#endif

#ifdef XSTL_MSVC
#define _xstl_assert_death(expr) \
  do {                           \
    SetUnhandledExceptionFilter(MyUnhandledExceptionFilter); \
    ASSERT_DEATH(expr);          \
  } while (0)
#else
#define _xstl_assert_death(expr) \
  do { \
    struct sigaction sa; \
    sa.sa_handler = exit(EXIT_FAILURE); \
    sigemptyset(&sa.sa_mask); \
    sa.sa_flags = 0; \
    sigaction(SIGABRT, &sa, NULL); \
    if (fork() == 0) { \
      int status = system(expr); \
      exit(WIFEXITED(status) && !WEXITSTATUS(status)); \
    } else { \
      int status; \
      wait(&status); \
      if (status != (1 << 8)) { \
        fprintf(stderr, "Death test failed: %s\n", #expr); \
        exit(EXIT_FAILURE); \
      } \
    } \
  } while (0)
#endif // XSTL_WIN

#endif // _XSTL_ASSERTIONS_H_