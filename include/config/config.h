#ifndef _XSTL_CONFIG_H_

#define _XSTL_CONFIG_H_

// **************************************
/// General puprose macros
// **************************************

// compiler:

#if defined(__GNUC__)
#define XSTL_GCC 1
#define XSTL_CLANG 0
#define XSTL_MSVC 0
#elif defined(__clang__)
#define XSTL_GCC 0
#define XSTL_CLANG 1
#define XSTL_MSVC 0
#elif defined(_MSC_VER)
#define XSTL_GCC 0
#define XSTL_CLANG 0
#define XSTL_MSVC 1
#endif


// os:

#if defined(_WIN32) && !defined(_WIN64)
#define XSTL_WIN 1
#define XSTL_WIN32 1
#define XSTL_WIN64 0
#define XSTL_LINUX 0
#define XSTL_MAC 0
#elif defined(_WIN64) && !defined(_WIN32)
#define XSTL_WIN 1
#define XSTL_WIN64 0
#define XSTL_WIN32 0 
#define XSTL_LINUX 0
#define XSTL_MAC 0
#elif defined(_WIN32) && defined(_WIN64)
#define XSTL_WIN 1
#define XSTL_WIN32 1
#define XSTL_WIN64 1
#define XSTL_LINUX 0
#define XSTL_MAC 0
#endif

#if defined(__linux__) || defined(__unix__)
#define XSTL_LINUX 1
#else
#define XSTL_LINUX 0
#endif

#if defined(__APPLE__)
#define XSTL_MAC 1
#else
#define XSTL_MAC 0
#endif

// cpp version:

#define XSTL_CXX11 __cplusplus >= 201103L
#define XSTL_CXX14 __cplusplus >= 201403L
#define XSTL_CXX17 __cplusplus >= 201703L
#define XSTL_CXX20 __cplusplus >= 202003L
#define XSTL_CXX23 __cplusplus >  202003L

// Library options:
#if defined(_DEBUG) || NDEBUG
#define XSTL_DEBUG 1
#elif
#define XSTL_DEBUG 0
#endif

//#define XSTL_DISABLE_EXTENSIONS 
//#define XSTL_UNDER_TEST ON

// **************************************
/// Define internal and public components
// **************************************

#if !defined(XSTL_API) && !defined(XSTL_INTERNAL) && defined(_WIN32)
#define XSTL_API __declspec(dllexport)
#define XSTL_INTERNAL 
#endif // WIN32 || _WIN32

#if !defined(XSTL_API) && !defined(XSTL_INTERNAL) && !defined(_WIN32)
#define XSTL_API __attribute__((visibility("default")))
#define XSTL_INTERNAL __attribute__((visibility("hidden")))
#endif

// **************************************
/// Features Test
// **************************************

/// inline
/// see:

/// When to use `inline` function?
/// see: msc: https://learn.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-170
/// They are best used for small functions, such as accessing private data member

#if __cpp_inline_variables >= 201606L || __cplusplus >= 201703L
#define INLINE_VAR inline
#else
#define INLINE_VAR
#endif

#if XSTL_MSVC
#define XSTL_FORCE_INLINE __forceinline
#elif XSTL_GCC || XSTL_CLANG
#define XSTL_FORCE_INLINE __attribute__((always_inline))
#else
#define XSTL_FORCE_INLINE inline
#endif
/// constexpr
/// See: https://en.cppreference.com/w/cpp/language/constexpr

/// strict 
/// declare variables as const in compile time, simple math ops (compute size, find max of 2 vals, ... etc) 
#if __cpp_constexpr >= 200704L
#define CONSTEXPR11 constexpr
#else
#define CONSTEXPR11
#endif

/// relaxed use
///  more complex expressions involving loops and user-defined types to be used in a constexpr context.
#if __cpp_constexpr >= 201304L
#define CONSTEXPR14 constexpr
#else
#define CONSTEXPR14
#endif

/// allowing for if-statements, switch-statements and more flexible definition of constexpr functions.
///  introduced a new concept of "integral constant expressions" 
/// that can be used in more places in the language, such as in array dimensions or non-type template arguments.
#if __cpp_constexpr >= 201603L
#define CONSTEXPR17 constexpr
#endif

///  constexpr lambdas and improved reflection capabilities.
#if __cpp_constexpr >= 201907L
#define CONSTEXPR20 constexpr
#else
#define CONSTEXPR20
#endif

/// ?
#if __cpp_constexpr >= 202110L
#define CONSTEXPR23 constexpr
#else
#define CONSTEXPR23
#endif

/// Attributes
/// See: https://en.cppreference.com/w/cpp/feature_test#:~:text=of%20said%20features.-,Attributes,-__has_cpp_attribute(%20attribute

#if __has_cpp_attribute( deprecated ) >= 201309L
#define XSTL_DEPRECATED [[deprecated]]
#else
#define XSTL_DEPRECATED
#endif

#if __has_cpp_attribute( nodiscard ) >= 201603L
#define XSTL_NODISCARD [[nodiscard]]
#else
#define XSTL_NODISCARD
#endif

// functions that exit the application, loop forever or throw exceptions.
#if __has_cpp_attribute( noreturn ) >= 200809L
#define XSTL_NORETURN [[noreturn]]
#else
#define XSTL_NORETURN
#endif

#if __has_cpp_attribute( maybe_unused ) >= 201603L
#define XSTL_UNUSED [[maybe_unused]]
#else
#define XSTL_UNUSED
#endif

#if __has_cpp_attribute( assume ) >= 202207L
#define XSTL_ASSUME(exp) [[maybe_unused(exp)]]
#else
#define XSTL_ASSUME(exp)
#endif

#if __has_cpp_attribute( likely ) >= 201803L && __has_cpp_attribute( unlikely ) >= 201803L
#define XSTL_LIKELY [[likely]]
#define XSTL_UNLIKELY [[unlikely]]
#else
#define XSTL_LIKELY
#define XSTL_UNLIKELY
#endif

/// GCC specific:
/// https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes
/// !TODO
#if XSTL_GCC
/// __XSTL_ReadOnlyAccess, __XSTL_ReadWriteAccess, __XSTL_WriteOnlyAccess 
/// enable the detection of invalid or unsafe accesses by functions to which they apply or their callers, as well as write-only accesses to objects that are never read from. Such accesses may be diagnosed by warnings such as -Wstringop-overflow, -Wuninitialized, -Wunused, and others.
#define __XSTL_ReadOnlyAccess(arg_index) __attribute__ ((access (read_only, arg_index)))
#define __XSTL_ReadWriteAccess(arg_index) __attribute__ ((access (read_write, arg_index)))
#define __XSTL_WriteOnlyAccess(arg_index) __attribute__ ((access (write_only, arg_index)))

#define __XSTL_RarelyUsed __attribute__((cold))
#define __XSTL_AggressiveOptimize __attribute__((hot))
#endif

// **************************************
/// Namespace
// **************************************

#define _BEGIN_XSTL namespace xstl {
#define _END_XSTL }

#if __cplusplus >= 201703L
#define _BEGIN_XSTL_TEST namespace xstl::test {
#define _END_XSTL_TEST }
#else                                   
#define _BEGIN_XSTL_TEST                \
    namespace xstl {                    \
        namespace test {            

#define _END_XSTL_TEST  }}
#endif



#endif // !_XSTL_CONFIG_H
