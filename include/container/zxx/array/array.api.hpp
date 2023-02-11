/**
 * @file array.api.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Defines array class and its functions accessible by users
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
#include "config/config.h"

// <--- array headers --->
//#include "array.traits.hpp"

_BEGIN_XSTL

/**
 * @brief Represents a fixed-size array with elements of type T and size N.
 * @tparam T The type of the elements stored in the array.
 * @tparam N The size of the array.
 */
template <typename T, size_t N> struct XSTL_API array {

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

  // Don't look for array constructors
  // no explicit construct/copy/destroy for aggregate type

  // ***********************************
  // iterators:
  // ***********************************

  iterator begin() noexcept {
      return iterator(_m_data);
  }

  const_iterator begin() const noexcept {
      return const_iterator(_m_data);
  }

  iterator end() noexcept {
      return iterator(_m_data + N);
  }

  const_iterator end() const noexcept {
      return const_iterator(_m_data + N);
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
      return const_iterator(_m_data);
  }

  const_iterator cend() const noexcept {
      return const_iterator(_m_data + N);
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
      return N;
  }

  XSTL_FORCE_INLINE CONSTEXPR11 size_type max_size() const {
      return N;
  }

  XSTL_FORCE_INLINE CONSTEXPR11 bool empty() const {
      return false;
  }

  // ***********************************
  // element access:
  // ***********************************

  reference operator[](size_type n) {
      if (n < 0 || n >= N) throw std::out_of_range("Invalid index");

      return _m_data[n];
  }

  const_reference operator[](size_type n) const {
      if (n < 0 || n >= N) throw std::out_of_range("Invalid index");

      return _m_data[n];
  }

  const_reference at(size_type n) const {
      if (n < 0 || n >= N) throw std::out_of_range("Invalid index");

      return _m_data[n];
  }

  reference at(size_type n) {
      if (n < 0 || n >= N) throw std::out_of_range("Invalid index");

      return _m_data[n];
  }

  reference front() {
      return _m_data[0];
  }

  const_reference front() const {
      return _m_data[0];
  }

  reference back() {
      return _m_data[N-1];
  }

  const_reference back() const {
      return _m_data[N - 1];
  }
 
  // observers:

  pointer data() {
      return _m_data;
  }
  
  const_pointer data() const {
      return _m_data;
  }

  // ***********************************
  // modifiers:
  // ***********************************

  void fill(const_reference val) noexcept {
      for (size_t i = 0; i < N; i++)
          _m_data[i] = val;
  }

  void swap(array<T, N>& x) {
      value_type temp;
      size_t i = 0 ;
      for (auto &e : x)
      {
        temp = _m_data[i];
        _m_data[i] = e;
        e = temp;
        ++i;
      }
  }

private:
    value_type _m_data[N];
};

template <typename T> struct XSTL_API array<T, 0> {

    // types:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    // ***********************************
    // iterators:
    // ***********************************

    const_iterator begin() noexcept {
        return _m_data;
    }

    iterator begin() const noexcept {
        return _m_data;
    }

    const_iterator end() noexcept {
        return _m_data;
    }

    iterator end() const noexcept {
        return _m_data;
    }

    const_reverse_iterator rbegin() noexcept {
        return _m_data;
    }

    const_reverse_iterator rbegin() const noexcept {
        return _m_data;
    }

    reverse_iterator rend() noexcept {
        return _m_data;
    }

    reverse_iterator rend() const noexcept {
        return _m_data;
    }

    const_reverse_iterator cbegin() const noexcept {
        return _m_data;
    }

    const_iterator cend() const noexcept {
        return _m_data;
    }

    const_iterator crbegin() const noexcept {
        return _m_data;
    }

    const_reverse_iterator crend() const noexcept {
        return _m_data;
    }

    // ***********************************
    // capacity and storage:
    // ***********************************

    XSTL_FORCE_INLINE CONSTEXPR11 size_type size() const {
        return 0;
    }

    XSTL_FORCE_INLINE CONSTEXPR11 size_type max_size() const {
        return 0;
    }

    XSTL_FORCE_INLINE CONSTEXPR11 bool empty() const {
        return true;
    }

    // ***********************************
    // element access:
    // ***********************************

    reference operator[](size_type n) noexcept {
        if (n < 0 || n >= N) std::cerr << "Invalid operation; array is empty!\n";

        return _m_data[0];
    }

    const_reference operator[](size_type n) const noexcept {
        if (n < 0 || n >= N) std::cerr << "Invalid operation; array is empty!\n"

        return _m_data[0];
    }

    const_reference at(size_type n) const {
        throw std::out_of_range("Invalid operation; array is empty!\n")
    }

    reference at(size_type n) {
        throw std::out_of_range("Invalid operation; array is empty!\n");
    }

    reference front() {
        return _m_data[0];
    }

    const_reference front() const {
        return _m_data[0];
    }

    reference back() {
        return _m_data[0];
    }

    const_reference back() const {
        return _m_data[0];
    }

    // observers:

    pointer data() {
        return nullptr;
    }

    const_pointer data() const {
        return nullptr;
    }

    // ***********************************
    // modifiers:
    // ***********************************

    void fill(const_reference val) {

    }

    void swap(array<T, 0>& x) {
    }

private:
    value_type _m_data[1];
};

// ops:


// Array comparisons.
template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator==(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return std::equal(_one.begin(), _one.end(), _two.begin());
}

template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator!=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one == _two);
}

template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator<(const array<_T, _N> &_a, const array<_T, _N> &_b) {
  return std::lexicographical_compare(_a.begin(), _a.end(), _b.begin(),
                                      _b.end());
}

template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator>(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return _two < _one;
}

template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator<=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one > _two);
}

template <typename _T, size_t _N>
XSTL_FORCE_INLINE bool operator>=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one < _two);
}

template <class _T, size_t _N>
std::ostream &operator<<(std::ostream &os, const array<_T, _N> &arr) {
  os << "[";
  for (const auto &x : arr) {
    os << x << ", ";
  }
  os << "]";
  return os;
}

_END_XSTL

#endif // !_ARRAY_API_H_
