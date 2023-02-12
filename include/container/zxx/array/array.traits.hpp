
#include <type_traits>

#include "config/config.h"

#ifndef _ARRAY_TRAITS_H_

#define _ARRAY_TRAITS_H_

_BEGIN_XSTL

/**
 * `_array_traits` is a class template that is used to provide information about
 * the size and element type of an `xstl::array` object. It is an implementation
 * detail of the `xstl::array` class, and it is not intended to be used directly
 * by users of `xstl::array`.
 *
 * The purpose of `_array_traits` is to allow the `xstl::array` class to support
 * arrays of both fixed and zero size. By using a class template,
 * `_array_traits` can provide different implementations of `xstl::array` for
 * arrays of fixed size and zero size.
 *
 * The specialization `template<typename _T> struct _array_traits<_T, 0>` is
 * used to provide information about an `xstl::array` object that has a size of
 * 0. This specialization allows the use of `xstl::array` objects with a size of
 * 0, which may cause errors and undefined behavior if it is left unnoticed.
 *
 * On the other hand, the primary template `template<typename _T, size_t _Size>
 * struct _array_traits` is used to provide information about an `xstl::array`
 * object that has a size of _Size, where _Size is a non-zero size specified as
 * a template argument. This primary template provides the default
 * implementation of `xstl::array` for arrays of non-zero size.
 *
 * This is a slightly more clever way to deal with array of zero size case
 * rather than overload the class `xstl::array` with `template<typename _T,
 * size_t 0>` as it is done in other compiler vendors.
 *
 * It's worth noting that the `_array_traits` class template is derived from the
 * GCC implementation of the Standard Template Library (STL), and it may not be
 * present in other implementations of the STL. In the standard C++ library, the
 * `xstl::array` class is implemented using other class templates and helper
 * functions, rather than using a class template like `_array_traits`.
 *
 */
template <typename _T, size_t _N>
struct XSTL_INTERNAL _array_traits {
  // _CStyle_array aliases a c style array type
  using _CStyle_array = _T[_N];

  // uncomment those later when <xstl/type_traits> is included - only works with
  // standard c++17 and highers
  // using _Is_swappable = xstl::is_swappable<_T>;
  // using _Is_nothrow_swappable = xstl::is_nothrow_swappable<_T>;

  // cast away the constantness of the array
  // return a reference
  static CONSTEXPR20 _T& _s_ref(const _CStyle_array& _t, size_t _n) noexcept {
    return const_cast<_T&>(_t[_n]);
  }

  // cast away the constantness of the array
  // return a reference
  static CONSTEXPR20 _T* _s_ptr(const _CStyle_array& _t) noexcept {
    return const_cast<_T*>(_t);
  }
};

template <typename _T>
struct XSTL_INTERNAL _array_traits<_T, 0> {
  
  struct _CStyle_array {
    // Indexing is undefined.
    XSTL_NORETURN _T& operator[](size_t) const noexcept { error("undefined!");}
    // Conversion to a pointer produces a null pointer.
    XSTL_FORCE_INLINE operator _T*() const noexcept { return nullptr; } 
  };

  // uncomment those later when <xstl/type_traits> is included - only works with
  // standard c++17 and highers
  // using _Is_swappable = xstl::true_type;
  // using _Is_nothrow_swappable = xstl::true_type;

  static CONSTEXPR20 _T& _s_ref(const _CStyle_array&, size_t) noexcept {
    return *static_cast<_T*>(nullptr);
  }

  static CONSTEXPR20 _T* _s_ptr(const _CStyle_array&) noexcept { return nullptr; }
};

_END_XSTL

#endif  // !_ARRAY_TRAITS_H_
