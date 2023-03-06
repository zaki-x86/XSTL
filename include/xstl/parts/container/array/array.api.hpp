/**
 * @file array.api.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Defines array class API
 * @version 0.1
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
*/

#ifndef _ARRAY_API_H_

#define _ARRAY_API_H_

// <--- std headers --->
#include<iostream>
#include<iterator>
#include<memory>
#include<algorithm>

// <--- XSTL headers --->
#include "xstl/config/config.h"
#include "xstl/debug/xstl_crt.h"

// <--- array headers --->
#include "array.traits.hpp"

_BEGIN_XSTL

/**
 * @brief Represents a fixed-size array with elements of type T and size N.
 * @tparam T The type of the elements stored in the array.
 * @tparam N The size of the array.
 */
template <typename T, size_t _Size> struct array {

  // types:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using iterator = T *;
  using const_iterator = const T *;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using size_type = size_t;
  using difference_type = std::ptrdiff_t;
  
  typedef _array_traits<T, _Size> _ArrayTraits;
  typename _ArrayTraits::_CStyle_array _m_Elements; 

  // Don't look for array constructors
  // no explicit construct/copy/destroy for aggregate type

  // ***********************************
  // iterators:
  // ***********************************

  CONSTEXPR17 iterator begin() noexcept {
      return iterator(data());
  }

  CONSTEXPR17 const_iterator begin() const noexcept {
      return const_iterator(data());
  }

  CONSTEXPR17 iterator end() noexcept {
      return iterator(data() + _Size);
  }

  CONSTEXPR17 const_iterator end() const noexcept {
      return const_iterator(data() + _Size);
  }

  CONSTEXPR17 reverse_iterator rbegin() noexcept {
      return reverse_iterator(end());
  }

  CONSTEXPR17 const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
  }

  CONSTEXPR17 reverse_iterator rend() noexcept {
      return reverse_iterator(begin());
  }

  CONSTEXPR17 const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
  }

  CONSTEXPR17 const_iterator cbegin() const noexcept {
      return const_iterator(data());
  }

  CONSTEXPR17 const_iterator cend() const noexcept {
      return const_iterator(data() + _Size);
  }

  CONSTEXPR17 const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(end());
  }

  CONSTEXPR17 const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(begin());
  }

  // ***********************************
  // capacity and storage:
  // ***********************************

  CONSTEXPR11 size_type size() const {
      return _Size;
  }

  CONSTEXPR11 size_type max_size() const {
      return _Size;
  }

  CONSTEXPR11 bool empty() const {
      return _Size == 0;
  }

  // ***********************************
  // element access:
  // ***********************************

  CONSTEXPR17 reference operator[](size_type n) noexcept {
      return _ArrayTraits::_s_ref(_m_Elements, n);
  }

  CONSTEXPR17 const_reference operator[](size_type n) const noexcept {
      return _ArrayTraits::_s_ref(_m_Elements, n);
  }

  CONSTEXPR17 const_reference at(size_type n) const {
      // NOTE no need to check if n < 0, since using size_t guarantees it to be unsigned
      if (n >= _Size)
        _xstl_out_of_range("index out of range");

      return (*this)[n];
  }

  CONSTEXPR17 reference at(size_type n) {
        if (n >= _Size)
            _xstl_out_of_range("index out of range");

        return (*this)[n];
  }

  XSTL_FORCE_INLINE CONSTEXPR17 reference front() {
      return (*this).at(0);
  }

  XSTL_FORCE_INLINE CONSTEXPR17 const_reference front() const {
      return (*this).at(0);
  }

  XSTL_FORCE_INLINE CONSTEXPR17 reference back() {
      return (*this).at(_Size-1);
  }

  XSTL_FORCE_INLINE CONSTEXPR17 const_reference back() const {
      return (*this).at(_Size - 1);
  }
 
  // observers:

  CONSTEXPR17 pointer data() {
      return _ArrayTraits::_s_ptr(_m_Elements);
  }
  
  CONSTEXPR17 const_pointer data() const {
      return _ArrayTraits::_s_ptr(_m_Elements);
  }

  // ***********************************
  // modifiers:
  // ***********************************

  void fill(const_reference val) noexcept {
      for (size_t i = 0; i < _Size; i++)
          data()[i] = val;
  }

  void swap(array<T, _Size>& x) noexcept {
      std::swap_ranges(begin(), end(), x.begin());
  }
};

// ops:
// Array comparisons.
template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator==(const array<_T, _Size> &_one, const array<_T, _Size> &_two) {
  return std::equal(_one.begin(), _one.end(), _two.begin());
}

template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator!=(const array<_T, _Size> &_one, const array<_T, _Size> &_two) {
  return !(_one == _two);
}

template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator<(const array<_T, _Size> &_a, const array<_T, _Size> &_b) {
  return std::lexicographical_compare(_a.begin(), _a.end(), _b.begin(),
                                      _b.end());
}

template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator>(const array<_T, _Size> &_one, const array<_T, _Size> &_two) {
  return _two < _one;
}

template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator<=(const array<_T, _Size> &_one, const array<_T, _Size> &_two) {
  return !(_one > _two);
}

template <typename _T, size_t _Size>
XSTL_FORCE_INLINE bool operator>=(const array<_T, _Size> &_one, const array<_T, _Size> &_two) {
  return !(_one < _two);
}

template <class _T, size_t _Size>
std::ostream &operator<<(std::ostream &os, const array<_T, _Size> &arr) {
  os << "{";
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    if (it == arr.end() - 1)
        os << *it;
    else
        os << *it << ", ";
  }
  os << "}";
  return os;
}

_END_XSTL

#endif // !_ARRAY_API_H_
