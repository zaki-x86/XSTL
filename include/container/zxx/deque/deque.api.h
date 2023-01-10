#ifndef _DEQUE_API_H_

#define _DEQUE_API_H_

#include <iostream>
#include <memory>
#include <initializer_list>

#include "config/zxx.config.h"
#include "deque.base.h"
#include "deque.iterator.h"
#include "deque.utils.h"

BEGIN_NS_ZXX_CORE_CONTAINER

template <class T, class Allocator = std::allocator<T>>
class deque : protected _Deque_base<T, Allocator> {
public:
  /**
   * @name Public Type Aliases
   *
   */
  ///@{
  typedef T value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef deque_iterator<T> iterator;
  typedef deque_iterator<const T> const_iterator;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef Allocator allocator_type;
  typedef typename std::allocator_traits<Allocator>::pointer pointer;
  typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  ///@}

  /**
   * @name Constructors, Destructors, and Assignment
   *
   */
  ///@{
  explicit deque(const Allocator &allocator = Allocator());
  explicit deque(size_type n);
  deque(size_type n, const T &value, const Allocator &allocator = Allocator());
  template <class InputIterator>
  deque(InputIterator first, InputIterator last,
        const Allocator & = Allocator());
  deque(const deque<T, Allocator> &x);
  deque(deque &&);
  deque(const deque &, const Allocator &);
  deque(deque &&, const Allocator &allocator);
  deque(std::initializer_list<T>, const Allocator &allocator = Allocator());
  ~deque();
  deque<T, Allocator> &operator=(const deque<T, Allocator> &x);
  deque<T, Allocator> &operator=(deque<T, Allocator> &&x);
  deque &operator=(std::initializer_list<T>);
  //template <class InputIterator>
  //void operator=(InputIterator first, InputIterator last);
  //void operator=(size_type n, const T &t);
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
   * @name Storage and capcaity
   *
   */
  ///@{
  size_type size() const;
  size_type max_size() const;
  void resize(size_type sz);
  void resize(size_type sz, const T &c);
  void shrink_to_fit();
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
  void swap(deque<T, Allocator> &);
  void clear();
  ///@}

  /**
   * @name Observers
   *
   */
  ///@{
  allocator_type get_allocator() const;
  ///@}
};
END_NS_ZXX_CORE_CONTAINER

#endif // !_DEQUE_API_H_
