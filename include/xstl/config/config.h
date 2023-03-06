#ifndef _XSTL_CONFIG_H_

#define _XSTL_CONFIG_H_

// =================================================================================================
// == COMPILER SUPPRORT HELPERS ====================================================================
// =================================================================================================

#if defined(__GNUC__)
#define XSTL_GCC 1
#elif defined(__clang__)
#define XSTL_CLANG 1
#elif defined(_MSC_VER)
#define XSTL_MSVC 1
#endif


// =================================================================================================
// == OS HELPERS ====================================================================
// =================================================================================================

#if defined(_WIN32) && !defined(_WIN64)
#define XSTL_WIN
#define XSTL_WIN32
#elif defined(_WIN64) && !defined(_WIN32)
#define XSTL_WIN
#define XSTL_WIN64
#elif defined(_WIN32) && defined(_WIN64)
#define XSTL_WIN
#define XSTL_WIN32
#define XSTL_WIN64
#elif defined(__CYGWIN__) || defined(__CYGWIN32__) || defined(__CYGWIN64__) || defined(_WIN32) && defined(_WIN64)
#define XSTL_WIN
#endif

#if defined(__linux__) || defined(__unix__)
#define XSTL_UNIX
#elif defined(__APPLE__)
#define XSTL_MAC
#endif

// =================================================================================================
// == COMPILER WARNINGS HELPERS ====================================================================
// =================================================================================================

#ifdef XSTL_CLANG
#define XSTL_PRAGMA_TO_STR(x) _Pragma(#x)
#define XSTL_CLANG_SUPPRESS_WARNING_PUSH _Pragma("clang diagnostic push")
#define XSTL_CLANG_SUPPRESS_WARNING(w) XSTL_PRAGMA_TO_STR(clang diagnostic ignored w)
#define XSTL_CLANG_SUPPRESS_WARNING_POP _Pragma("clang diagnostic pop")
#define XSTL_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)                                                \
    XSTL_CLANG_SUPPRESS_WARNING_PUSH XSTL_CLANG_SUPPRESS_WARNING(w)
#else // XSTL_CLANG
#define XSTL_CLANG_SUPPRESS_WARNING_PUSH
#define XSTL_CLANG_SUPPRESS_WARNING(w)
#define XSTL_CLANG_SUPPRESS_WARNING_POP
#define XSTL_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // XSTL_CLANG

#if XSTL_GCC
#define XSTL_PRAGMA_TO_STR(x) _Pragma(#x)
#define XSTL_GCC_SUPPRESS_WARNING_PUSH _Pragma("GCC diagnostic push")
#define XSTL_GCC_SUPPRESS_WARNING(w) XSTL_PRAGMA_TO_STR(GCC diagnostic ignored w)
#define XSTL_GCC_SUPPRESS_WARNING_POP _Pragma("GCC diagnostic pop")
#define XSTL_GCC_SUPPRESS_WARNING_WITH_PUSH(w)                                                  \
    XSTL_GCC_SUPPRESS_WARNING_PUSH XSTL_GCC_SUPPRESS_WARNING(w)
#else // XSTL_GCC
#define XSTL_GCC_SUPPRESS_WARNING_PUSH
#define XSTL_GCC_SUPPRESS_WARNING(w)
#define XSTL_GCC_SUPPRESS_WARNING_POP
#define XSTL_GCC_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // XSTL_GCC

#ifdef XSTL_MSVC
#define XSTL_MSVC_SUPPRESS_WARNING_PUSH __pragma(warning(push))
#define XSTL_MSVC_SUPPRESS_WARNING(w) __pragma(warning(disable : w))
#define XSTL_MSVC_SUPPRESS_WARNING_POP __pragma(warning(pop))
#define XSTL_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)                                                 \
    XSTL_MSVC_SUPPRESS_WARNING_PUSH XSTL_MSVC_SUPPRESS_WARNING(w)
#else // XSTL_MSVC
#define XSTL_MSVC_SUPPRESS_WARNING_PUSH
#define XSTL_MSVC_SUPPRESS_WARNING(w)
#define XSTL_MSVC_SUPPRESS_WARNING_POP
#define XSTL_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // XSTL_MSVC



// cpp version:

#if defined(__cplusplus)
#define XSTL_CXX11 __cplusplus >= 201103L
#define XSTL_CXX14 __cplusplus >= 201403L
#define XSTL_CXX17 __cplusplus >= 201703L
#define XSTL_CXX20 __cplusplus >= 202003L
#define XSTL_CXX23 __cplusplus >  202003L
#endif

// Library options:
#if defined(_DEBUG) || NDEBUG
#define XSTL_DEBUG 1
#endif

#if defined(ENABLE_EXCEPTIONS)
#define XSTL_EXCEPTIONS_ENABLED 1
#else
#define XSTL_EXCEPTIONS_DISABLED 1
#endif

#if defined(XSTL_WIN)
#ifdef XSTL_MSVC
#define XSTL_SYMBOL_EXPORT __declspec(dllexport)
#define XSTL_SYMBOL_IMPORT __declspec(dllimport)
#else // MSVC
#define XSTL_SYMBOL_EXPORT __attribute__((dllexport))
#define XSTL_SYMBOL_IMPORT __attribute__((dllimport))
#endif // MSVC
#else  // XSTL_WIN
#define XSTL_SYMBOL_EXPORT __attribute__((visibility("default")))
#define XSTL_SYMBOL_IMPORT
#endif // XSTL_WIN

#ifdef XSTL_CONFIG_IMPLEMENTATION_IN_DLL
#ifdef XSTL_CONFIG_IMPLEMENT
#define XSTL_INTERFACE XSTL_SYMBOL_EXPORT
#else // XSTL_CONFIG_IMPLEMENT
#define XSTL_INTERFACE XSTL_SYMBOL_IMPORT
#endif // XSTL_CONFIG_IMPLEMENT
#else  // XSTL_CONFIG_IMPLEMENTATION_IN_DLL
#define XSTL_INTERFACE
#endif // XSTL_CONFIG_IMPLEMENTATION_IN_DLL


// **************************************
/// Features Test
// **************************************

/// inline
/// see:

/// When to use `inline` function?
/// see: msc: https://learn.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-170
/// They are best used for small functions, such as accessing private data member

#if !defined(__cpp_inline_variables) && __cplusplus >= 201606L
#define __cpp_inline_variables 201606L
#endif

#if defined(__cpp_inline_variables) || defined(XSTL_CXX17)
#define XSTL_INLINE_VAR inline
#else
#define XSTL_INLINE_VAR
#endif

#ifdef XSTL_MSVC
#define XSTL_FORCE_INLINE __forceinline
#elif defined(XSTL_GCC) || defined(XSTL_CLANG)
#define XSTL_FORCE_INLINE __attribute__((always_inline)) inline
#else
#define XSTL_FORCE_INLINE
#endif

/// constexpr
/// See: https://en.cppreference.com/w/cpp/language/constexpr

/// strict - cxx11
/// declare variables as const in compile time, simple math ops (compute size, find max of 2 vals, ... etc) 
#if defined(__cpp_constexpr) && __cpp_constexpr >= 200704L
#define CONSTEXPR11 constexpr
#else
#define CONSTEXPR11
#endif

/// relaxed use - cxx14
///  more complex expressions involving loops and user-defined types to be used in a constexpr context.
#if defined(__cpp_constexpr) && __cpp_constexpr >= 201304L
#define CONSTEXPR14 constexpr
#else
#define CONSTEXPR14
#endif

/// more relaxed - cxx17
/// allowing for if-statements, switch-statements and more flexible definition of constexpr functions.
///  introduced a new concept of "integral constant expressions" 
/// that can be used in more places in the language, such as in array dimensions or non-type template arguments.
#if defined(__cpp_constexpr) && __cpp_constexpr >= 201603L
#define CONSTEXPR17 constexpr
#else
#define CONSTEXPR17
#endif

/// improved - cxx20
///  constexpr lambdas and improved reflection capabilities.
#if defined(__cpp_constexpr) && __cpp_constexpr >= 201907L
#define CONSTEXPR20 constexpr
#else
#define CONSTEXPR20
#endif

/// ? - cxx23
#if defined(__cpp_constexpr) && __cpp_constexpr >= 202110L
#define CONSTEXPR23 constexpr
#else
#define CONSTEXPR23
#endif

/// Attributes
/// See: https://en.cppreference.com/w/cpp/feature_test#:~:text=of%20said%20features.-,Attributes,-__has_cpp_attribute(%20attribute

#ifdef XSTL_CXX14
#define XSTL_DEPRECATED(msg) [[deprecated(msg)]]
#else
#define XSTL_DEPRECATED
#endif

#ifdef XSTL_CXX17
#define XSTL_NODISCARD [[nodiscard]]
#else
#define XSTL_NODISCARD
#endif

#if defined(__GNUC__) && (__GNUC__ >= 4) || defined(XSTL_CLANG)
#define XSTL_CHECK_RETURN __attribute__ ((warn_unused_result))
#elif defined(_MSC_VER) && (_MSC_VER >= 1700)
#define XSTL_CHECK_RETURN _Check_return_
#else
#define XSTL_CHECK_RETURN
#endif

// functions that exit the application, loop forever or throw exceptions.
#ifdef XSTL_CXX11
    #if defined(_MSC_VER)
    #define XSTL_NORETURN __declspec(noreturn)
    #elif defined(__GNUC__) || defined(__clang__)
    #define XSTL_NORETURN __attribute__((noreturn))
    #else
    #define XSTL_NORETURN
    #endif
#else
#define XSTL_NORETURN
#endif

// MSVC ignores [[maybe_unused]] on function parameters
#if XSTL_CXX17
#define XSTL_UNUSED [[maybe_unused]]
#elif defined(XSTL_GCC) && (__GNUC__  >= 7)
#define XSTL_UNUSED [[gnu::unused]]
#elif defined(XSTL_CLANG)
#define XSTL_UNUSED __attribute__((unused))
#else
#define XSTL_UNUSED
#endif


// To be used for MSVC, as XSTL_UNUSED won't work for MSVC
#ifdef XSTL_MSVC
#define XSTL_IGNORE(exp) (void)(exp)
#else
#define XSTL_IGNORE(exp)
#endif


#ifdef XSTL_CXX23
#define XSTL_ASSUME(exp) [[maybe_unused(exp)]]
#else
#define XSTL_ASSUME(exp)
#endif

#ifdef XSTL_CXX20
#define XSTL_LIKELY [[likely]]
#define XSTL_UNLIKELY [[unlikely]]
#else
#define XSTL_LIKELY
#define XSTL_UNLIKELY
#endif

/// GCC specific:
/// https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes
/// !TODO
#ifdef XSTL_GCC
/// __XSTL_ReadOnlyAccess, __XSTL_ReadWriteAccess, __XSTL_WriteOnlyAccess 
/// enable the detection of invalid or unsafe accesses by functions to which they apply or their callers, as well as write-only accesses to objects that are never read from. Such accesses may be diagnosed by warnings such as -Wstringop-overflow, -Wuninitialized, -Wunused, and others.
#define _XSTL_ReadOnlyAccess(arg_index) __attribute__ ((access (read_only, arg_index)))
#define _XSTL_ReadWriteAccess(arg_index) __attribute__ ((access (read_write, arg_index)))
#define _XSTL_WriteOnlyAccess(arg_index) __attribute__ ((access (write_only, arg_index)))

#define _XSTL_COLD __attribute__((cold))
#define _XSTL_HOT __attribute__((hot))
#else
#define _XSTL_ReadOnlyAccess(arg_index)
#define _XSTL_ReadWriteAccess(arg_index)
#define _XSTL_WriteOnlyAccess(arg_index)
#define _XSTL_COLD
#define _XSTL_HOT
#endif

// **************************************
/// Namespace
// **************************************

#define _BEGIN_XSTL namespace xstl {
#define _END_XSTL }

#define _XSTL xstl::

#define _BEGIN_INTERNAL namespace internal {
#define _END_INTERNAL }

#define _INTERNAL internal::

#if defined(__cplusplus) && __cplusplus >= 201703L
#define _BEGIN_XSTL_TEST namespace xstl::test {
#define _END_XSTL_TEST }
#else                                   
#define _BEGIN_XSTL_TEST                \
    namespace xstl {                    \
        namespace test {            

#define _END_XSTL_TEST  }}
#endif




#endif // !_XSTL_CONFIG_H
