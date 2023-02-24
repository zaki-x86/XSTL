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
#include <iterator>
#include <memory>

// <--- XSTL headers --->
#include "xstl/config/config.h"

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
  using difference_type = ptrdiff_t;

  typename _array_traits<T, _Size>::_CStyle_array _m_Elements; 

  // Don't look for array constructors
  // no explicit construct/copy/destroy for aggregate type

  // ***********************************
  // iterators:
  // ***********************************

  iterator begin() noexcept {
      return iterator(_m_Elements);
  }

  const_iterator begin() const noexcept {
      return const_iterator(_m_Elements);
  }

  iterator end() noexcept {
      return iterator(_m_Elements + _Size);
  }

  const_iterator end() const noexcept {
      return const_iterator(_m_Elements + _Size);
  }

  reverse_iterator rbegin() noexcept {
      return reverse_iterator(end());
  }

  const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
  }

  reverse_iterator rend() noexcept {
      return reverse_iterator(begin());
  }

  const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
  }

  const_iterator cbegin() const noexcept {
      return const_iterator(_m_Elements);
  }

  const_iterator cend() const noexcept {
      return const_iterator(_m_Elements + _Size);
  }

  const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(end());
  }

  const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(begin());
  }

  // ***********************************
  // capacity and storage:
  // ***********************************

  XSTL_FORCE_INLINE CONSTEXPR11 size_type size() const {
      return _Size;
  }

  XSTL_FORCE_INLINE CONSTEXPR11 size_type max_size() const {
      return _Size;
  }

  XSTL_FORCE_INLINE CONSTEXPR11 bool empty() const {
      return false;
  }

  // ***********************************
  // element access:
  // ***********************************

  reference operator[](size_type n) {
      if (n < 0 || n >= _Size) throw std::out_of_range("Invalid index");

      return _m_Elements[n];
  }

  const_reference operator[](size_type n) const {
      if (n < 0 || n >= _Size) throw std::out_of_range("Invalid index");

      return _m_Elements[n];
  }

  const_reference at(size_type n) const {
      if (n < 0 || n >= _Size) throw std::out_of_range("Invalid index");

      return _m_Elements[n];
  }

  reference at(size_type n) {
      if (n < 0 || n >= _Size) throw std::out_of_range("Invalid index");

      return _m_Elements[n];
  }

  reference front() {
      return _m_Elements[0];
  }

  const_reference front() const {
      return _m_Elements[0];
  }

  reference back() {
      return _m_Elements[_Size-1];
  }

  const_reference back() const {
      return _m_Elements[_Size - 1];
  }
 
  // observers:

  pointer data() {
      return _m_Elements;
  }
  
  const_pointer data() const {
      return _m_Elements;
  }

  // ***********************************
  // modifiers:
  // ***********************************

  void fill(const_reference val) noexcept {
      for (size_t i = 0; i < _Size; i++)
          data()[i] = val;
  }

  void swap(array<T, _Size>& x) {
      value_type temp;
      size_t i = 0 ;
      for (auto &e : x)
      {
        temp = data()[i];
        data()[i] = e;
        e = temp;
        ++i;
      }
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
  os << "[";
  for (const auto &x : arr) {
    os << x << ", ";
  }
  os << "]";
  return os;
}

_END_XSTL

#endif // !_ARRAY_API_H_
