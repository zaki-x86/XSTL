#ifndef _LIST_API_H_

#define _LIST_API_H_

#include <initializer_list>
#include <iostream>
#include <memory>

#include "config/zxx.config.h"
#include "list.iterator.h"

BEGIN_NS_ZXX_CORE_CONTAINER

template <class T, class Allocator = std::allocator<T>> 
class ZXX_PUBLIC list {
public:
  /**
   * @name Public Type Aliases
   *
   */
  ///@{
  typedef T value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef list_iterator<T> iterator;
  typedef list_iterator<const T> const_iterator;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef Allocator allocator_type;
  typedef typename std::allocator_traits<Allocator>::pointer pointer;
  typedef
      typename std::allocator_traits<Allocator>::const_pointer const_pointer;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  ///@}

  /**
   * @name Constructors, Destructors and Assignment
   *
   */
  ///@{
  explicit list(const Allocator &allocator = Allocator());
  explicit list(size_type n);
  list(size_type n, const T &value, const Allocator &allocator = Allocator());
  template <class InputIterator>
  list(InputIterator first, InputIterator last,
       const Allocator &allocator = Allocator());
  list(const list &x);
  list(list &&x);
  list(const list &x, const Allocator &allocator);
  list(list &&x, const Allocator &);
  list(std::initializer_list<T>, const Allocator &allocator = Allocator());
  ~list();
  list<T, Allocator> &operator=(const list<T, Allocator> &x);
  list<T, Allocator> &operator=(list<T, Allocator> &&x);
  list &operator=(std::initializer_list<T>);
  ///@}

  /**
   * @name Iterators
   *
   */
  ///@{
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  const_iterator cbegin() const;
  const_iterator cend() const;
  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;
  ///@}

  /**
   * @name Capacity and Storage
   *
   */
  ///@{
  size_type size() const;
  size_type max_size() const;
  void resize(size_type sz);
  void resize(size_type sz, const T &c);
  bool empty() const;
  ///@}

  /**
   * @name Accessors
   *
   */
  ///@{
  reference operator[](size_type n);
  const_reference operator[](size_type n) const;
  reference at(size_type n);
  const_reference at(size_type n) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  ///@}

  /**
   * @name Modifiers
   *
   */
  ///@{
  template <class... Args> void emplace_front(Args &&... args);
  template <class... Args> void emplace_back(Args &&... args);
  template <class... Args>
  iterator emplace(const_iterator position, Args &&... args);
  void push_front(const T &x);
  void push_front(T &&x);
  void push_back(const T &x);
  void push_back(T &&x);
  iterator insert(const_iterator position, const T &x);
  iterator insert(const_iterator position, T &&x);
  iterator insert(const_iterator position, size_type n, const T &x);
  template <class InputIterator>
  iterator insert(const_iterator position, InputIterator first,
                  InputIterator last);
  iterator insert(const_iterator position, std::initializer_list<T>);
  void pop_front();
  void pop_back();
  iterator erase(const_iterator position);
  iterator erase(const_iterator first, const_iterator last);
  void swap(list<T, Allocator> &);
  void clear();
  ///@}

  /**
   * @name Forward List Operations
   *
   */
  ///@{
  void splice(const_iterator position, list<T, Allocator> &x) noexcept;

  void splice(const_iterator position, list<T, Allocator> &&x) noexcept;

  void splice(const_iterator position, list<T, Allocator> &x,
              const_iterator i) noexcept;
  void splice(const_iterator position, list<T, Allocator> &&x,
              const_iterator i) noexcept;
  void splice(const_iterator position, list<T, Allocator> &x,
              const_iterator first, const_iterator last) noexcept;
  void splice(const_iterator position, list<T, Allocator> &&x,
              const_iterator first, const_iterator last) noexcept;

  void remove(const T &value);
  template <class Predicate> void remove_if(Predicate pred);

  void unique();
  template <class BinaryPredicate> void unique(BinaryPredicate binary_pred);

  void merge(list<T, Allocator> &x);
  void merge(list<T, Allocator> &&x);
  template <class Compare> void merge(list<T, Allocator> &x, Compare comp);
  template <class Compare> void merge(list<T, Allocator> &&x, Compare comp);

  void sort();
  template <class Compare> void sort(Compare comp);

  void reverse() noexcept;
  ///@}

  /**
   * @name Observers
   *
   */
  ///@{
  allocator_type get_allocator() const;
  ///@}
};

template <class T, class Allocator>
void swap(list<T, Allocator> &x, list<T, Allocator> &y);

/**
 * @defgroup flist-comparisons Comparisons
 *
 */
///@{
template <class T, class Allocator>
bool operator==(const list<T, Allocator> &x, const list<T, Allocator> &y);
template <class T, class Allocator>
bool operator<(const list<T, Allocator> &x, const list<T, Allocator> &y);
template <class T, class Allocator>
bool operator!=(const list<T, Allocator> &x, const list<T, Allocator> &y);
template <class T, class Allocator>
bool operator>(const list<T, Allocator> &x, const list<T, Allocator> &y);
template <class T, class Allocator>
bool operator>=(const list<T, Allocator> &x, const list<T, Allocator> &y);
template <class T, class Allocator>
bool operator<=(const list<T, Allocator> &x, const list<T, Allocator> &y);

///@}

END_NS_ZXX_CORE_CONTAINER

#endif // !_LIST_H_