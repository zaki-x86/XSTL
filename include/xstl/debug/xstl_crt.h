/**
 * @file assertions.h
 * @brief Assertions for testing
 * @details This file contains macros for testing purposes.
 * @author M Zaki
 * @date 2021-07-01
 * @version 1.0
 *
 */
#include "xstl/config/config.h"
#include <stdarg.h>
#include <stdexcept>
#include <stdio.h>

#ifndef _XSTL_CRT_H_
#define _XSTL_CRT_H_

// **************************************
/// Built-in utility methods
// **************************************


enum class XSTL_EXIT_CODE { XSTL_SUCCESS = 0, XSTL_FAILURE = 1 };

enum class XSTL_EXIT { CRASH = 1, PANIC = 2 };

// This function is used to suppress warnings about functions that are marked
// as XSTL_NORETURN but do not actually return.
// This function is never called, and is only here to suppress warnings.


XSTL_NORETURN void _z_xstl_crash() {
#ifdef XSTL_CLANG
  __builtin_trap();
#elif defined(XSTL_GCC)
  __builtin_trap();
#elif defined(XSTL_MSVC)
  __debugbreak();
#else
  // Implement crash for other compilers here.
  // For example, you can use a segmentation fault:
  volatile int *ptr = nullptr;
  *ptr = 42;
#endif
}

XSTL_NORETURN void _z_xstl_panic() {
  // TODO Implement a graceful abortion mechanism.
  // This code is temporary and will be replaced with a better solution.
  exit(1);
}

XSTL_NORETURN XSTL_FORCE_INLINE void
_xstl_error(const char *file, int line, const char *msg,
            XSTL_EXIT _exit = XSTL_EXIT::CRASH) {
  fprintf(stderr, "Error: %s at %s:%d: ", msg, file, line);
  if (_exit == XSTL_EXIT::CRASH) {
    _z_xstl_crash();
  } else if (_exit == XSTL_EXIT::PANIC) {
    _z_xstl_panic();
  }
  exit(1); // This line is unreachable. Only here to suppress warnings.
}

XSTL_NORETURN void _z_xstl_out_of_range(XSTL_UNUSED const char *file, XSTL_UNUSED int line,
                                        const char *msg) {
#ifdef XSTL_EXCEPTIONS_ENABLED
  XSTL_IGNORE(file);
  XSTL_IGNORE(line);
  throw std::out_of_range(msg);
#else
  _xstl_error(file, line, msg, XSTL_EXIT::PANIC);
#endif

  #ifdef XSTL_MSVC                  
  __pragma(warning(push))             
  __pragma(warning(disable : 4702))
  exit(1);  // This line is unreachable. Only here to suppress warnings.
  #elif defined(XSTL_GCC) || defined(XSTL_CLANG)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunreachable-code"
  exit(1);  // This line is unreachable. Only here to suppress warnings.
  #endif                            
}

XSTL_NORETURN void _z_xstl_invalid_index(XSTL_UNUSED const char *file, XSTL_UNUSED int line,
                                         const char *msg) {
#ifdef XSTL_EXCEPTIONS_ENABLED
  XSTL_IGNORE(file);
  XSTL_IGNORE(line);
  throw std::invalid_argument(msg);
#else
  _xstl_error(file, line, msg, XSTL_EXIT::CRASH);
#endif
  exit(1);  // This line is unreachable. Only here to suppress warnings.
}

// ******************************************

#ifndef XSTL_DEBUG

#define _xstl_crash(msg)
#define _xstl_panic(msg)
#define _xstl_out_of_range(msg)
#define _xstl_invalid_index(msg)

#else

#define _xstl_crash(msg) _xstl_error(__FILE__, __LINE__, msg, XSTL_EXIT::CRASH);
#define _xstl_panic(msg) _xstl_error(__FILE__, __LINE__, msg, XSTL_EXIT::PANIC);
#define _xstl_out_of_range(msg) _z_xstl_out_of_range(__FILE__, __LINE__, msg);
#define _xstl_invalid_index(msg) _z_xstl_invalid_index(__FILE__, __LINE__, msg);

#endif

#endif // _XSTL_CRT_H_
