/**
 * @file vector.api.hpp
 * @author M Zaki (mamadov_zicx@gmail.com)
 * @brief dynamic array container API
 * @version 0.1
 * @date 2022-12-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _VECTOR_API_H_

#define _VECTOR_API_H_

// <--- std header files  --->
#include <vector>

// <--- XSTL headers needed --->
#include "xstl/config/config.h"

// <--- vector headers --->
#include "vector.base.hpp"
#include "vector.iterator.hpp"
#include "vector.utils.hpp"

_BEGIN_XSTL

/**
 * @brief A dynamic array class template that provides a similar
 * interface to std::vector.
 *
 * The vector class template is a container that provides random
 * access to its elements, much like an array, but with the
 * ability to grow or shrink dynamically as needed. It is
 * implemented using a dynamic array that is internally managed
 * using an allocator object.
 *
 * @tparam T The type of the elements that will be stored in the
 * vector.
 * @tparam Allocator The type of the allocator object used to
 * manage the internal memory of the vector.
 *
 * @note The vector class template does not provide a full
 * implementation, but rather provides a partial interface that
 * is similar to the one provided by std::vector.
 */
template <typename T, typename Allocator = std::allocator<T>>
class vector : protected vector_base<T, Allocator> {
private:
  // These aliases will be useful later on, bc we will no longer use any std::something in the future, therefore, I grouped them here and aliased them, so I can easily change them later when I create my own zxx::something
  using zxx_ptrdiff_t = std::ptrdiff_t;
  using zxx_size_t = std::size_t ;

protected:
  using vector_type = vector<T, Allocator>;
  using _Base = vector_base<T, Allocator>; 
  using _Tp_alloc_type = typename _Base::_Tp_alloc_type;
  using _alloc_traits = std::allocator_traits<_Tp_alloc_type>;
  using _Base::_m_allocate;
  using _Base::_m_deallocate;
  using _Base::_m_get_Tp_allocator;
  using _Base::_m_impl;

public:
  /**
   * @name Public Type Aliases
   */
  ///@{
    /**
   * @brief The type of the elements stored in the vector.
   */
  using value_type = T;

  /**
   * @brief The type of the allocator object used by the vector.
   */
  using allocator_type = Allocator;

  /**
   * @brief An unsigned integer type used to represent the size of the vector.
   */
  using size_type = zxx_size_t;

  /**
   * @brief A signed integer type used to represent the difference between two
   * indices in the vector.
   */
  using difference_type = zxx_ptrdiff_t;

  /**
   * @brief A reference to an element in the vector.
   */
  using reference = typename _alloc_traits::value_type&;

  /**
   * @brief A const reference to an element in the vector.
   */
  using const_reference = const typename _alloc_traits::value_type&;

  /**
   * @brief A pointer to an element in the vector.
   */
  using pointer = typename _alloc_traits::pointer;

  /**
   * @brief A const pointer to an element in the vector.
   */
  using const_pointer = typename _alloc_traits::const_pointer;

  /**
   * @brief An iterator that can be used to access and modify elements in the
   * vector.
   *
   * The iterator type provides bidirectional iterator semantics, meaning that
   * it can be incremented or decremented to move to the next or previous
   * element in the vector, respectively. It also provides random access
   * iterator semantics, meaning that it supports arithmetic operators such as
   * `+` and `-` to move a specific number of elements forward or backward, as
   * well as the `<`, `>`, `<=`, and `>=` operators for comparing the distance
   * between two iterators.
   *
   * @note The implementation of the iterator type is implementation-defined.
   */
  using iterator = T*;

  /**
   * @brief A const iterator that can be used to access elements in the
   * vector.
   *
   * The const iterator type provides bidirectional iterator semantics,
   * meaning that it can be incremented or decremented to move to the next or
   * previous element in the vector, respectively. It also provides random
   * access iterator semantics, meaning that it supports arithmetic operators
   * such as `+` and `-` to move a specific number of elements forward or
   * backward, as well as the `<`, `>`, `<=`, and `>=` operators for comparing
   * the distance between two iterators.
   *
   * @note The implementation of the const iterator type is
   * implementation-defined.
   */
  using const_iterator = const T*;

  /**
   * @brief A reverse iterator that can be used to access and modify elements
   * in the vector in reverse order.
   *
   * The reverse iterator type provides bidirectional iterator semantics,
   * meaning that it can be incremented or decremented to move to the next or
   * previous element in the vector in reverse order, respectively. It also
   * provides random access iterator semantics, meaning that it supports
   * arithmetic operators such as `+` and `-` to move a specific number of
   * elements forward or backward, as well as the `<`, `>`, `<=`, and `>=`
   * operators for comparing the distance between two iterators.
   *
   * @note The implementation of the reverse iterator type is based on
   * std::reverse_iterator.
   */
  using reverse_iterator = std::reverse_iterator<iterator>;

  /**
   * @brief A const reverse iterator that can be used to access elements in
   * the vector in reverse order.
   *
   *
   * The const reverse iterator type provides bidirectional iterator
   * semantics, meaning that it can be incremented or decremented to move to
   * the next or previous element in the vector in reverse order,
   * respectively. It also provides random access iterator semantics, meaning
   * that it supports arithmetic operators such as `+` and `-` to move a
   * specific number of elements forward or backward, as well as the `<`, `>`,
   * `<=`, and `>=` operators for comparing the distance between two
   * iterators.
   *
   * @note The implementation of the const reverse iterator type is based on
   * std::reverse_iterator.
   */
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  ///@}

  /**
   * @name Constructors and Destructors
   */
  ///@{
  /**
   * @brief Constructs an empty vector with the default allocator.
   *
   * This constructor creates an empty vector with a default-constructed
   * allocator object. If the allocator has a noexcept default constructor,
   * the constructor of vector is noexcept. Otherwise, it may throw an
   * exception if the allocator's default constructor throws an exception.
   *
   * @note The size of the vector is initialized to 0.
   *
   * @code
   * vector<int> v;
   * assert(v.empty());
   * @endcode
   */
  CONSTEXPR20 vector() noexcept(noexcept(Allocator()))
    : _Base(Allocator()) {}

  /**
   * @brief Constructs an empty vector with a copy of the given allocator.
   *
   * This constructor creates an empty vector with a copy of the given
   * allocator object. If the allocator has a noexcept copy constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's copy constructor throws an exception.
   *
   * @param alloc The allocator object to use for the vector.
   *
   * @note The size of the vector is initialized to 0.
   *
   * @code
   * vector<int> v(std::allocator<int>{});
   * assert(v.empty());
   * @endcode
   */
  CONSTEXPR20 explicit vector(const Allocator &alloc);

  /**
   * @brief Constructs a vector with the given size and the default allocator.
   *
   * This constructor creates a vector with a default-constructed allocator
   * object and the given size. The vector is initialized with the default
   * value of `T`. If the allocator has a noexcept default constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's default constructor throws an exception.
   *
   * @param count The number of elements to initialize the vector with.
   *
   * @note The size of the vector is initialized to `count`.
   *
   * @code
   * vector<int> v(3);
   * assert(v.size() == 3);
   * assert(v[0] == 0);
   * assert(v[1] == 0);
   * assert(v[2] == 0);
   * @endcode
   */
  CONSTEXPR20 explicit vector(size_type count);

  /**
   * @brief Constructs a vector with the given size and a copy of the given
   * allocator.
   *
   * This constructor creates a vector with a copy of the given allocator
   * object and the given size. The vector is initialized with the default
   * value of `T`. If the allocator has a noexcept copy constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's copy constructor throws an exception.
   *
   * @param count The number of elements to initialize the vector with.
   * @param alloc The allocator object to use for the vector.
   *
   * @note The size of the vector is initialized to `count`.
   *
   * @code
   * vector<int> v(3, std::allocator<int>{});
   * assert(v.size() == 3);
   * assert(v[0] == 0);
   * assert(v[1] == 0);
   * assert(v[2] == 0);
   * @endcode
   */
  CONSTEXPR20 explicit vector(size_type count, const Allocator &alloc);

  /**
   * @brief Constructs a vector with the given size and the default allocator,
   *        and initializes the elements with the given value.
   *
   * This constructor creates a vector with a default-constructed allocator
   * object, the given size, and the given value to initialize the elements.
   * If the allocator has a noexcept default constructor, the constructor of
   * vector is noexcept. Otherwise, it may throw an exception if the
   * allocator's default constructor throws an exception.
   *
   * @param count The number of elements to initialize the vector with.
   * @param value The value to initialize the elements of the vector with.
   *
   * @note The size of the vector is initialized to `count`.
   *
   * @code
   * vector<int> v(3, 5);
   * assert(v.size() == 3);
   * assert(v[0] == 5);
   * assert(v[1] == 5);
   * assert(v[2] == 5);
   * @endcode
   */
  vector(size_type count, const T &value);

  /**
   * @brief Constructs a vector with the given size and a copy of the given
   * allocator, and initializes the elements with the given value.
   *
   * This constructor creates a vector with a copy of the given alloc * ator
   * object, the given size, and the given value to initialize the elements.
   * If the allocator has a noexcept copy constructor, the constructor of
   * vector is noexcept. Otherwise, it may throw an exception if the
   * allocator's copy constructor throws an exception.
   *
   * @param count The number of elements to initialize the vector with.
   * @param value The value to initialize the elements of the vector with.
   * @param alloc The allocator object to use for the vector.
   *
   * @note The size of the vector is initialized to `count`.
   *
   * @code
   * vector<int> v(3, 5, std::allocator<int>{});
   * assert(v.size() == 3);
   * assert(v[0] == 5);
   * assert(v[1] == 5);
   * assert(v[2] == 5);
   * @endcode
   */
  vector(size_type count, const T &value, const Allocator &alloc);

  /**
   * @brief Constructs a vector with the elements in the given range and the
   * default allocator.
   *
   * This constructor creates a vector with a default-constructed allocator
   * object and copies the elements in the given range into the vector. If the
   * allocator has a noexcept default constructor, the constructor of vector
   * is noexcept. Otherwise, it may throw an exception if the allocator's
   * default constructor throws an exception.
   *
   * @tparam InputIt A forward iterator type that points to elements that are
   * convertible to `T`.
   * @param first The start of the range to copy elements from.
   * @param last The end of the range to copy elements from.
   *
   * @note The size of the vector is initialized to the number of elements in
   * the range.
   *
   * @code
   * std::vector<int> src = {1, 2, 3};
   * vector<int> v(src.begin(), src.end());
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  template <typename InputIt> vector(InputIt first, InputIt last);

  /**
   * @brief Constructs a vector with the elements in the given range and a
   * copy of the given allocator.
   *
   * This constructor creates a vector with a copy of the given alloc * ator
   * object and copies the elements in the given range into the vector. If the
   * allocator has a noexcept copy constructor, the constructor of vector is
   * noexcept. Otherwise, it may throw an exception if the allocator's copy
   * constructor throws an exception.
   *
   * @tparam InputIt A forward iterator type that points to elements that are
   * convertible to `T`.
   * @param first The start of the range to copy elements from.
   * @param last The end of the range to copy elements from.
   * @param alloc The allocator object to use for the vector.
   *
   * @note The size of the vector is initialized to the number of elements in
   * the range.
   *
   * @code
   * std::vector<int> src = {1, 2, 3};
   * vector<int> v(src.begin(), src.end(), std::allocator<int>{});
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  template <typename InputIt>
  vector(InputIt first, InputIt last, const Allocator &alloc);

  /**
   * @brief Constructs a vector with the elements in the initializer list and
   * the default allocator.
   *
   * This constructor creates a vector with a default-constructed allocator
   * object and copies the elements in the initializer list into the vector.
   * If the allocator has a noexcept default constructor, the constructor of
   * vector is noexcept. Otherwise, it may throw an exception if the
   * allocator's default constructor throws an exception.
   *
   * @param list The initializer list to copy elements from.
   *
   * @note The size of the vector is initialized to the number of elements in
   * the initializer list.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector(std::initializer_list<T> list);

  /**
   * @brief Constructs a vector with the elements in the initializer list and
   * a copy of the given allocator.
   *
   * This constructor creates a vector with a copy of the given allocator
   * object and copies the elements in the initializer list into the vector.
   * If the allocator has a noexcept copy constructor, the constructor of
   * vector is noexcept. Otherwise, it may throw an exception if the
   * allocator's copy constructor throws an exception.
   *
   * @param list The initializer list to copy elements from.
   * @param alloc The allocator object to use for the vector.
   *
   * @note The size of the vector is initialized to the number of elements in
   * the initializer list.
   *
   * @code
   * vector<int> v = {1, 2, 3, std::allocator<int>{}};
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2
   * assert(v[2] == 3);
   * @endcode
   */
  vector(std::initializer_list<T> list, const Allocator &alloc);

  /**
   * @brief Constructs a vector by copying the elements from another vector.
   *
   * This constructor creates a vector by copying the elements from another
   * vector. The allocator object used for the new vector is copied from the
   * other vector. If the allocator has a noexcept copy constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's copy constructor throws an exception.
   *
   * @param other The vector to copy elements from.
   *
   * @code
   * vector<int> src = {1, 2, 3};
   * vector<int> v(src);
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector(const vector &other);

  /**
   * @brief Constructs a vector by moving the elements from another vector.
   *
   * This constructor creates a vector by moving the elements from another
   * vector. The allocator object used for the new vector is copied from the
   * other vector. If the allocator has a noexcept move constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's move constructor throws an exception.
   *
   * @param other The vector to move elements from.
   *
   * @code
   * vector<int> src = {1, 2, 3};
   * vector<int> v(std::move(src));
   * assert(src.empty());
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector(vector &&other) noexcept(
      noexcept(Allocator(std::declval<Allocator &&>())));

  /**
   * @brief Constructs a vector by copying the elements from another vector
   * with a different allocator type.
   *
   * This constructor creates a vector by copying the elements from another
   * vector with a different allocator type. The allocator object used for the
   * new vector is constructed with the copy constructor of the other vector's
   * allocator. If the allocator has a noexcept copy constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's copy constructor throws an exception.
   *
   * @tparam OtherAlloc The allocator type of the other vector.
   * @param other The vector to copy elements from.
   *
   * @code
   * vector<int, std::allocator<int>> src = {1, 2, 3};
   * vector<int, std::allocator<long>> v(src);
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  template <typename OtherAlloc> vector(const vector<T, OtherAlloc> &other);

  /**
   * @brief Constructs a vector by moving the elements from another vector
   * with a different allocator type.
   *
   * This constructor creates a vector by moving the elements from another
   * vector with a different allocator type. The allocator object used for the
   * new vector is constructed with the copy constructor of the other vector's
   * allocator. If the allocator has a noexcept move constructor, the
   * constructor of vector is noexcept. Otherwise, it may throw an exception
   * if the allocator's move constructor throws an exception.
   *
   * @tparam OtherAlloc The allocator type of the other vector.
   * @param other The vector to move elements from.
   *
   * @code
   * vector<int, std::allocator<int>> src = {1, 2, 3};
   * vector<int, std::allocator<long>> v(std::move(src));
   * assert(src.empty());
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  template <typename OtherAlloc>
  vector(vector<T, OtherAlloc> &&other) noexcept(
      noexcept(Allocator(std::declval<Allocator &&>())));

  /**
   * @brief Destructs the vector.
   *
   * The destructor of the vector frees the memory used by the vector and
   * calls the destructor of each element. If the allocator has a noexcept
   * destructor, the destructor of vector is noexcept. Otherwise, it may throw
   * an exception if the allocator's destructor throws an exception.
   */
  ~vector(){}
  ///@}

  /**
   * @name Assignment
   * Copy, move, initializer_list assignments.
   */
  ///@{
    /**
   * @brief Assigns the elements from another vector to the vector.
   *
   * This operator assigns the elements from another vector to the vector. If
   * the allocator has a noexcept copy assignment operator, the operator= is
   * noexcept. Otherwise, it may throw an exception if the allocator's copy
   * assignment operator throws an exception.
   *
   * @param other The vector to copy elements from.
   * @return A reference to the vector.
   *
   * @code
   * vector<int> src = {1, 2, 3};
   * vector<int> v;
   * v = src;
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector &operator=(const vector &other);

  /**
   * @brief Assigns the elements from another vector to the vector using move
   * semantics.
   *
   * This operator assigns the elements from another vector to the vector
   * using move semantics. If the allocator has a noexcept move assignment
   * operator, the operator= is noexcept. Otherwise, it may throw an exception
   * if the allocator's move assignment operator throws an exception.
   *
   * @param other The vector to move elements from.
   * @return A reference to the vector.
   *
   * @code
   * vector<int> src = {1, 2, 3};
   * vector<int> v;
   * v = std::move(src);
   * assert(src.empty());
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector &operator=(vector &&other) noexcept(
      noexcept(Allocator(std::declval<Allocator &&>())));

  /**
   * @brief Assigns the elements from an initializer list to the vector.
   *
   * This operator assigns the elements from an initializer list to the
   * vector. If the allocator has a noexcept copy assignment operator, the
   * operator= is noexcept. Otherwise, it may throw an exception if the
   * allocator's copy assignment operator throws an exception.
   *
   * @param list The initializer list to copy elements from.
   * @return A reference to the vector.
   *
   * @code
   * vector<int> v;
   * v = {1, 2, 3};
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  vector &operator=(std::initializer_list<T> list);
  ///@}

  /**
   * @name iterators
   */
  ///@{
    /**
   * @brief Returns an iterator to the beginning of the vector.
   *
   * This function returns an iterator to the beginning of the vector.
   *
   * @return An iterator to the beginning of the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::iterator it = v.begin();
   * assert(*it == 1);
   * @endcode
   */
  iterator begin();

  /**
   * @brief Returns an iterator to the end of the vector.
   *
   * This function returns an iterator to the end of the vector.
   *
   * @return An iterator to the end of the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::iterator it = v.end();
   * --it;
   * assert(*it == 3);
   * @endcode
   */
  iterator end();

  /**
   * @brief Returns a const_iterator to the beginning of the vector.
   *
   * This function returns a const_iterator to the beginning of the vector.
   *
   * @return A const_iterator to the beginning of the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::const_iterator it = v.cbegin();
   * assert(*it == 1);
   * @endcode
   */
  const_iterator cbegin() const;

  /**
   * @brief Returns a const_iterator to the end of the vector.
   *
   * This function returns a const_iterator to the end of the vector.
   *
   * @return A const_iterator to the end of the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::const_iterator it = v.cend();
   * --it;
   * assert(*it == 3);
   * @endcode
   */
  const_iterator cend() const;

  /**
   * @brief Returns a const iterator to the beginning of the vector.
   *
   * This function returns a const iterator to the beginning of the vector.
   *
   * @return A const iterator to the beginning of the vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * vector<int>::const_iterator it = v.begin();
   * assert(*it == 1);
   * @endcode
   */
  const_iterator begin() const;

  /**
   * @brief Returns a const_iterator to the end of the vector.
   *
   * This function returns a const_iterator to the end of the vector.
   *
   * @return A const_iterator to the end of the vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * vector<int>::const_iterator it = v.end();
   * --it;
   * assert(*it == 3);
   * @endcode
   */
  const_iterator end() const;

  /**
   * @brief Returns a reverse iterator to the beginning of the reversed
   * vector.
   *
   * This function returns a reverse iterator to the beginning of the reversed
   * vector.
   *
   * @return A reverse iterator to the beginning of the reversed vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::reverse_iterator it = v.rbegin();
   * assert(*it == 3);
   * @endcode
   */
  reverse_iterator rbegin();

  /**
   * @brief Returns a reverse iterator to the end of the reversed vector.
   *
   * This function returns a reverse iterator to the end of the reversed
   * vector.
   *
   * @return A reverse iterator to the end of the reversed vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::reverse_iterator it = v.rend();
   * --it;
   * assert(*it == 1);
   * @endcode
   */
  reverse_iterator rend();

  /**
   * @brief Returns a const reverse iterator to the beginning of the reversed
   * vector.
   *
   * This function returns a const reverse iterator to the beginning of the
   * reversed vector.
   *
   * @return A const reverse iterator to the beginning of the reversed vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * vector<int>::const_reverse_iterator it = v.rbegin();
   * assert(*it == 3);
   * @endcode
   */
  const_reverse_iterator rbegin() const;
  
  /**
   * @brief Returns a reverse iterator to the end of the reversed vector.
   *
   * This function returns a reverse iterator to the end of the reversed
   * vector.
   *
   * @return A reverse iterator to the end of the reversed vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::reverse_iterator it = v.rend();
   * --it;
   * assert(*it == 1);
   * @endcode
   */
  const_reverse_iterator rend() const;

  /**
   * @brief Returns a const reverse iterator to the beginning of the reversed
   * vector.
   *
   * This function returns a const reverse iterator to the beginning of the
   * reversed vector.
   *
   * @return A const reverse iterator to the beginning of the reversed vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * vector<int>::const_reverse_iterator it = v.rbegin();
   * assert(*it == 3);
   * @endcode
   */
  const_reverse_iterator crbegin() const;

  /**
   * @brief Returns a const reverse iterator to the end of the reversed
   * vector.
   *
   * This function returns a const reverse iterator to the end of the reversed
   * vector.
   *
   * @return A const reverse iterator to the end of the reversed vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::const_reverse_iterator it = v.crend();
   * --it;
   * assert(*it == 1);
   * @endcode
   */
  const_reverse_iterator crend() const;
  ///@}

  /**
   * @name Storage and memory
   */
  ///@{
  /**
   * @brief Returns the number of elements in the vector.
   *
   * This function returns the number of elements in the vector.
   *
   * @return The number of elements in the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * assert(v.size() == 3);
   * @endcode
   */
  size_type size() const { return size_type(end() - begin()); }

  /**
   * @brief Returns whether the vector is empty.
   *
   * This function returns whether the vector is empty, i.e. whether its size
   * is 0.
   *
   * @return `true` if the vector is empty, `false` otherwise.
   *
   * @code
   * vector<int> v;
   * assert(v.empty());
   * @endcode
   */
  bool empty() const;

  /**
   * @brief Returns the capacity of the array.
   */
  size_type capacity() const;

  /**
   * @brief Resizes the vector.
   *
   * This function resizes the vector. If the new size is smaller than the
   * current size, the vector is truncated. If the new size is larger than the
   * current size, the vector is expanded and the new elements are value
   * initialized. If the allocator has a noexcept move constructor, the
   * function is noexcept. Otherwise, it may throw an exception if the
   * allocator's move constructor throws an exception.
   *
   * @param new_size The new size of the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * v.resize(5);
   * assert(v.size() == 5);
   * assert(v[3] == 0);
   * assert(v[4] == 0);
   * @endcode
   */
  void resize(size_type new_size);

  /**
   * @brief Resizes the vector to the specified size.
   *
   * This function resizes the vector to the specified size. If the size is
   * smaller than the current size, the vector is truncated. If the size is
   * larger than the current size, the vector is expanded by adding copies of
   * the specified value to the end.
   *
   * @param size The new size of the vector.
   * @param value The value to initialize new elements with.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * v.resize(5, 0);
   * assert(v.size() == 5);
   * @endcode
   */
  void resize(size_type size, const_reference value);

  /**
   * @brief Returns the maximum number of elements the vector can hold.
   *
   * This function returns the maximum number of elements the vector can hold.
   *
   * @return The maximum number of elements the vector can hold.
   *
   * @code
   * vector<int> v;
   * assert(v.max_size() > 0);
   * @endcode
   */
  size_type max_size() const;

  /**
   * @brief Reserves storage for the vector.
   *
   * This function reserves storage for the vector. If the requested size is
   * larger than the current capacity, the vector is expanded to the new size.
   * If the requested size is smaller than the current size, the function has
   * no effect.
   *
   * @param size The new size of the vector.
   *
   * @code
   * vector<int> v;
   * v.reserve(100);
   * assert(v.capacity() >= 100);
   * @endcode
   */
  void reserve(size_type size);
  ///@}

  /**
   * @name Accessors
   */
  ///@{

  /**
   * @brief Returns a reference to the element at the specified location in
   * the vector.
   *
   * This function returns a reference to the element at the specified
   * location in the vector. If the index is not within the bounds of the
   * vector, the function throws an std::out_of_range exception.
   *
   * @param index The index of the element to return.
   * @return A const reference to the element at the specified location in the
   * vector.
   *
   * @throws std::out_of_range if the index is not within the bounds of the
   * vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * assert(v.at(0) == 1);
   * @endcode
   */
  const_reference at(size_type index) const;

  /**
   * @brief Returns a reference to the element at the given
   * position in the vector.
   *
   * This function returns a reference to the element at the given position in
   * the vector. The function does not perform any bounds checking, so calling
   * it with an invalid position results in undefined behavior.
   *
   * @param n The position of the element to access.
   * @return A reference to the element at the given position.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  reference operator[](size_type n);

  /**
   * @brief Returns a const reference to the element at the given position in
   * the vector.
   *
   * This function returns a const reference to the element at the given
   * position in the vector. The function does not perform any bounds
   * checking, so calling it with an invalid position results in undefined
   * behavior.
   *
   * @param n The position of the element to access.
   * @return A const reference to the element at the given position.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  const_reference operator[](size_type n) const;

  /**
   * @brief Returns a reference to the front element in the vector.
   *
   * This function returns a const reference to the front element in the
   * vector. If the vector is empty, the function results in undefined
   * behavior.
   *
   * @return A const reference to the front element in the vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * assert(v.front() == 1);
   * @endcode
   */
  reference front();

  /**
   * @brief Returns a const reference to the front element in the vector.
   *
   * This function returns a const reference to the front element in the
   * vector. If the vector is empty, the function results in undefined
   * behavior.
   *
   * @return A const reference to the front element in the vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * assert(v.front() == 1);
   * @endcode
   */
  const_reference front() const;

  /**
   * @brief Returns a reference to the back element in the vector.
   *
   * This function returns a reference to the back element in the vector. If
   * the vector is empty, the function results in undefined behavior.
   *
   * @return A reference to the back element in the vector.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * assert(v.back() == 3);
   * @endcode
   */
  reference back();

  /**
   * @brief Returns a const reference to the back element in the vector.
   *
   * This function returns a const reference to the back element in the
   * vector. If the vector is empty, the function results in undefined
   * behavior.
   *
   * @return A const reference to the back element in the vector.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * assert(v.back() == 3);
   * @endcode
   */
  const_reference back() const;
  ///@}
  
  /**
   * @name Modifiers
   */
  ///@{
  
  /**
   * @brief Inserts an element at the end of the vector.
   *
   * This function inserts an element at the end of the vector. If the new
   * size of the vector is larger than the capacity of the vector, the
   * function will reallocate the vector to a larger size. If the allocator
   * has a noexcept move constructor, the function is noexcept. Otherwise, it
   * may throw an exception if the allocator's move constructor throws an
   * exception.
   *
   * @param value The value to insert.
   *
   * @code
   * vector<int> v;
   * v.push_back(1);
   * v.push_back(2);
   * v.push_back(3);
   * assert(v.size() == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * @endcode
   */
  void push_back(const T &value);

  /**
   * @brief Inserts an element at the end of the vector using move semantics.
   *
   *
   * This function inserts an element at the end of the vector using move
   * semantics. If the new size of the vector is larger than the capacity of
   * the vector, the function will reallocate the vector to a larger size. If
   * the allocator has a noexcept move constructor, the function is noexcept.
   * Otherwise, it may throw an exception if the allocator's move constructor
   * throws an exception.
   *
   * @param value The value to insert.
   *
   * @code
   * vector<std::string> v;
   * v.push_back("hello");
   * v.push_back("world");
   * assert(v.size() == 2);
   * assert(v[0] == "hello");
   * assert(v[1] == "world");
   * @endcode
   */
  void push_back(T &&value);

  /**
   * @brief Removes the last element from the vector.
   *
   * This function removes the last element from the vector. Calling this
   * function on an empty vector results in undefined behavior.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * v.pop_back();
   * assert(v.size() == 2);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * @endcode
   */
  void pop_back();

  /**
   * @brief Inserts an element at the beginning of the vector.
   *
   * This function inserts an element at the beginning of the vector. If the
   * new size of the vector is larger than the capacity of the vector, the
   * function will reallocate the vector to a larger size. If the allocator
   * has a noexcept move constructor, the function is noexcept. Otherwise, it
   * may throw an exception if the allocator's move constructor throws an
   * exception.
   *
   * @param value The value to insert.
   *
   * @code
   * vector<std::string> v;
   * v.push_front("hello");
   * v.push_front("world");
   * assert(v.size() == 2);
   * assert(v[0] == "world");
   * assert(v[1] == "hello");
   * @endcode
   */
  void push_front(T &&value);

  /**
   * @brief Removes the first element from the vector.
   *
   * This function removes the first element from the vector. Calling this
   * function on an empty vector results in undefined behavior.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * v.pop_front();
   * assert(v.size() == 2);
   * assert(v[0] == 2);
   * assert(v[1] == 3);
   * @endcode
   */
  void pop_front();

  /**
   * @brief Inserts an element at the given position in the vector.
   *
   * This function inserts an element at the given position in the vector. If
   * the new size of the vector is larger than the capacity of the vector, the
   * function will reallocate the vector to a larger size. If the allocator
   * has a noexcept move constructor, the function is noexcept. Otherwise, it
   * may throw an exception if the allocator's move constructor throws an
   * exception.
   *
   * @param pos The position to insert the element at.
   * @param value The value to insert.
   * @return An iterator to the inserted element.
   *
   * @code
   * vector<std::string> v = {"hello", "world"};
   * vector<std::string>::iterator it = v.insert(v.begin() + 1, "foo");
   * assert(v.size() == 3);
   * assert(*it == "foo");
   * assert(v[0] == "hello");
   * assert(v[1] == "foo");
   * assert(v[2] == "world");
   * @endcode
   */
  iterator insert(const_iterator pos, T &&value);

  /**
   * @brief Inserts a number of copies of an element at the given position in
   * the vector.
   *
   * This function inserts a number of copies of an element at the given
   * position in the vector. If the new size of the vector is larger than the
   * capacity of the vector, the function will reallocate the vector to a
   * larger size. If the allocator has a noexcept move constructor, the
   * function is noexcept. Otherwise, it may throw an exception if the
   * allocator's move constructor throws an exception.
   *
   * @param pos The position to insert the element at.
   * @param count The number of copies to insert.
   * @param value The value to insert.
   * @return An iterator to the first inserted element.
   *
   * @code
   * vector<int> v = {1, 2, 4};
   * vector<int>::iterator it = v.insert(v.begin() + 2, 2, 3);
   * assert(v.size() == 5);
   * assert(*it == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * assert(v[3] == 3);
   * assert(v[4] == 4);
   * @endcode
   */
  iterator insert(const_iterator pos, size_type count, const T &value);

  /**
   * @brief Inserts a range of elements at the given position in the vector.
   *
   * This function inserts a range of elements at the given position in the
   * vector. If the new size of the vector is larger than the capacity of the
   * vector, the function will reallocate the vector to a larger size. If the
   * allocator has a noexcept move constructor, the function is noexcept.
   * Otherwise, it may throw an exception if the allocator's move constructor
   * throws an exception.
   *
   * @param pos The position to insert the elements at.
   * @param first The start of the range to insert.
   * @param last The end of the range to insert.
   * @return An iterator to the first inserted element.
   *
   * @code
   * vector<int> v = {1, 2, 4};
   * std::vector<int> vec = {3, 3};
   * vector<int>::iterator it = v.insert(v.begin() + 2, vec.begin(),
   * vec.end()); assert(v.size() == 5); assert(*it == 3); assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * assert(v[3] == 3);
   * assert(v[4] == 4);
   * @endcode
   */
  template <class InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last);

  /**
   * @brief Inserts a list of elements at the given position in the vector.
   *
   * This function inserts a list of elements at the given position in the
   * vector. If the new size of the vector is larger than the capacity of the
   * vector, the function will reallocate the vector to a larger size. If the
   * allocator has a noexcept move constructor, the function is noexcept.
   * Otherwise, it may throw an exception if the allocator's move constructor
   * throws an exception.
   *
   * @param pos The position to insert the elements at.
   * @param ilist The list of elements to insert.
   * @return An iterator to the first inserted element.
   *
   * @code
   * vector<int> v = {1, 2, 4};
   * vector<int>::iterator it = v.insert(v.begin() + 2, {3, 3});
   * assert(v.size() == 5);
   * assert(*it == 3);
   * assert(v[0] == 1);
   * assert(v[1] == 2);
   * assert(v[2] == 3);
   * assert(v[3] == 3);
   * assert(v[4] == 4);
   * @endcode
   */
  iterator insert(const_iterator pos, std::initializer_list<T> ilist);

  /**
   * @brief Erases an element from the vector.
   *
   * This function erases an element from the vector. If the iterator is at
   * the end of the vector, the function results in undefined behavior.
   *
   * @param first The start of the range to erase.
   * @param last The end of the range to erase.
   * @return An iterator to the element after the erased range.
   *
   * @code
   * vector<int> v = {1, 2, 3, 4};
   * vector<int>::iterator it = v.erase(v.begin() + 1, v.begin() + 3);
   * assert(v.size() == 2);
   * assert(*it == 4);
   * assert(v[0] == 1);
   * assert(v[1] == 4);
   * @endcode
   */
  iterator erase(const_iterator first, const_iterator last);

  /**
   * @brief Removes all elements from the vector.
   *
   * This function removes all elements from the vector. If the allocator has
   * a noexcept swap function, the function is noexcept. Otherwise, it may
   * throw an exception if the allocator's swap function throws an exception.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * v.clear();
   * assert(v.empty());
   * @endcode
   */
  void clear();

  /**
   * @brief Inserts elements into the vector.
   *
   * This function inserts elements into the vector. The elements are inserted
   * before the element at the specified position. If the position is not
   * within the bounds of the vector, the function results in undefined
   * behavior.
   *
   * @param position The
   * @param args The arguments to forward to the element constructor.
   *
   * @return An iterator pointing to the inserted element.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::iterator it = v.emplace(v.begin() + 1, 0);
   * assert(*it == 0);
   * @endcode
   */
  template <class... Args> iterator emplace(iterator position, Args &&... args);

  /**
   * @brief Constructs an element in-place at the end of the vector.
   *
   * @tparam Args The types of the arguments to be forwarded to the constructor of the element.
   * @param args The arguments to be forwarded to the constructor of the element.
   *
   * @note This function avoids the need to construct a temporary object of the element type, and then move the temporary object to the vector. 
   * Instead, the element is constructed directly in the vector's memory. This can be more efficient in some cases.
   *
   * @code
   * #include <zxx/core/container/vector.h>
   * #include <string>
   *
   * int main()
   * {
   *     XSTL::vector<std::string> v;
   *
   *     // Add an element to the end of the vector using emplace_back
   *     v.emplace_back("hello");
   *
   *     return 0;
   * }
   * @endcode
   */
  template<class... Args>
  void emplace_back(Args&&... args);

  /**
   * @brief Erases an element from the vector.
   *
   * This function erases an element from the vector. The element at the
   * specified position is removed. If the position is not within the bounds
   * of the vector, the function results in undefined behavior.
   *
   * @param position The position of the element to erase.
   *
   * @return An iterator pointing to the element following the erased element.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * vector<int>::iterator it = v.erase(v.begin() + 1);
   * assert(*it == 3);
   * @endcode
   */
  iterator erase(iterator position);

  /**
   * @brief Erases elements from the vector.
   *
   * This function erases elements from the vector. The elements in the range
   * [first, last) are removed. If the positions are not within the bounds of
   * the vector, the function results in undefined behavior.
   *
   * @param first The position of the first element to erase.
   * @param last The position of the element following the last element to
   * erase.
   *
   * @return An iterator pointing to the element following the last erased
   * element.
   *
   * @code
   * vector<int> v = {1, 2, 3, 4, 5};
   * vector<int>::iterator it = v.erase(v.begin() + 1, v.begin() + 4);
   * assert(*it == 5);
   * @endcode
   */
  iterator erase(iterator first, iterator last);

    /**
   * @brief Swaps the elements and the allocator object of two vectors.
   *
   * This function swaps the elements and the allocator object
   * of two vectors. If the allocator has a noexcept swap function, the
   * function is noexcept. Otherwise, it may throw an exception if the
   * allocator's swap function throws an exception.
   *
   * @param other The vector to swap with.
   *
   * @code
   * vector<int> v1 = {1, 2, 3};
   * vector<int> v2 = {4, 5, 6};
   * v1.swap(v2);
   * assert(v1.size() == 3);
   * assert(v1[0] == 4);
   * assert(v1[1] == 5);
   * assert(v1[2] == 6);
   * assert(v2.size() == 3);
   * assert(v2[0] == 1);
   * assert(v2[1] == 2);
   * assert(v2[2] == 3);
   * @endcode
   */
  void swap(vector &other) noexcept(
      noexcept(Allocator(std::declval<Allocator &&>())));
  ///@}

  /**
   * @name Observers
   */
  ///@{

  /**
   * @brief Returns a pointer to the underlying element array.
   *
   * This function returns a pointer to the underlying element array. The
   * pointer is such that the range
   * `[data(); data() + size()]` is always a valid range, even if the
   * container is empty.
   *
   * @return A pointer to the underlying element array.
   *
   * @code
   * vector<int> v = {1, 2, 3};
   * int* p = v.data();
   * assert(p[0] == 1);
   * assert(p[1] == 2);
   * assert(p[2] == 3);
   * @endcode
   */
  T *data();

  /**
   * @brief Returns a const pointer to the underlying element array.
   *
   * This function returns a const pointer to the underlying element array.
   * The pointer is such that the range `[data(); data() + size()]` is always
   * a valid range, even if the container is empty.
   *
   * @return A const pointer to the underlying element array.
   *
   * @code
   * const vector<int> v = {1, 2, 3};
   * const int* p = v.data();
   * assert(p[0] == 1);
   * assert(p[1] == 2);
   * assert(p[2] == 3);
   * @endcode
   */
  const T *data() const;
  /**
   * @brief Retrieves the allocator used by the vector.
   *
   * @return The allocator used by the vector.
   *
   * @note The allocator is used to allocate and deallocate memory for the vector's elements.
   *
   * @code
   * #include <zxx/core/container/vector.h>
   * #include <iostream>
   *
   * int main()
   * {
   *     XSTL::vector<int> v;
   *
   *     // Print the type of the allocator used by the vector
   *     std::cout << typeid(v.get_allocator()).name() << std::endl;
   *
   *     return 0;
   * }
   * @endcode
   */
  allocator_type get_allocator() const noexcept;
  ///@}


};

/**
 * @defgroup vector-specialized-algorithms Specialized Algorithms 
 */
///@{
  /**
   * @brief Swaps the contents of the vector with those of another vector.
   *
   * This function swaps the contents of the vector with those of another
   * vector. The two vectors must be of the same type.
   *
   * @param other The vector to swap with.
   *
   * @code
   * vector<int> v1 = {1, 2, 3};
   * vector<int> v2 = {4, 5, 6};
   * swap(v1, v2);
   * assert(v1 == vector<int>({4, 5, 6}));
   * @endcode
   */
  template <class U> void swap(vector<U> &lhs, vector<U> &rhs);
///@}

/**
  * @defgroup vector-comparisons Comparison Operators
  * 
  * operators allow you to compare two vector objects for
  * equality, inequality, and lexicographic ordering. Note that the comparison
  * operators are implemented as friend functions, rather than member
  * functions, because they need to compare the elements of two different
  * vector objects.
  */
  ///@{   
  template <class U>
  bool operator==(const vector<U> &lhs, const vector<U> &rhs) {
    return lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin());
  }

  template <class U>
  bool operator!=(const vector<U> &lhs, const vector<U> &rhs) {
    return !(lhs == rhs);
  }

  template <class U>
  bool operator<(const vector<U> &lhs, const vector<U> &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end());
  }

  template <class U>
  bool operator<=(const vector<U> &lhs, const vector<U> &rhs) {
    return !(rhs < lhs);
  }

  template <class U>
  bool operator>(const vector<U> &lhs, const vector<U> &rhs) {
    return rhs < lhs;
  }

  template <class U>
  bool operator>=(const vector<U> &lhs, const vector<U> &rhs) {
    return !(lhs < rhs);
  }

  #if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  CONSTEXPR20 bool
  operator>=<(const XSTL::container::vector<U, Alloc> &x,
              const XSTL::container::vector<U, Alloc> &y) {
    return false;
  }
  #endif
  ///@}

/**
 * @defgroup vector-streams Streaming
 */
///@{
/**
 * @brief Outputs the elements of a vector to a stream.
 *
 * This function outputs the elements of the vector to the given output stream
 * in the format `[x1, x2, x3, ..., xn]`, where `xi` is the i-th element of the
 * vector.
 *
 * @param os The output stream to write to.
 * @param d The vector to output.
 *
 * @return The output stream.
 *
 * @code
 * vector<int> v = {1, 2, 3};
 * std::cout << v << std::endl;  // prints "[1, 2, 3]"
 * @endcode
 */
template <class T>
std::ostream &operator<<(std::ostream &os, const vector<T> &d) {
  os << "[";
  for (const auto &x : d) {
    os << x << ", ";
  }
  os << "]";
  return os;
}
///@}




_END_XSTL


#endif // !_VECTOR_API_H_