#ifndef _FORWARD_LIST_API_H_

#define _FORWARD_LIST_API_H_

#include <forward_list>

#include "config/zxx.config.h"
#include "forward_list.iterator.hpp"

BEGIN_NS_ZXX_CORE_CONTAINER
template <class T, class Allocator = std::allocator<T>> 
class ZXX_PUBLIC forward_list {
public:
  /**
   * @name Public Type Aliases
   *
   */
  ///@{
  typedef T value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef forward_list_iterator<T> iterator;
  typedef forward_list_iterator<const T> const_iterator;
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
  explicit forward_list(const Allocator &allocator = Allocator());
  explicit forward_list(size_type n);
  forward_list(size_type n, const T &value,
               const Allocator &allocator = Allocator());
  template <class InputIterator>
  forward_list(InputIterator first, InputIterator last,
               const Allocator &allocator = Allocator());
  forward_list(const forward_list &x);
  forward_list(forward_list &&x);
  forward_list(const forward_list &x, const Allocator &);
  forward_list(forward_list &&x, const Allocator &);
  forward_list(std::initializer_list<T>,
               const Allocator &allocator = Allocator());
  ~forward_list();
  forward_list<T, Allocator> &operator=(const forward_list<T, Allocator> &x);
  forward_list<T, Allocator> &operator=(forward_list<T, Allocator> &&x);
  forward_list &operator=(std::initializer_list<T>);
  ///@}

  /**
   * @name Iterators
   *
   */
  ///@{
  iterator begin();
  const_iterator before_begin() const;
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  const_iterator cbegin() const;
  const_iterator cbefore_begin() const;
  const_iterator cend() const;
  ///@}

  /**
   * @name Capacity and Storage
   *
   */
  ///@{
  bool empty() const;
  size_type max_size() const;
  ///@}

  /**
   * @name Accessors
   *
   */
  ///@{
  reference front();
  const_reference front() const;
  ///@}

  /**
   * @name Modifiers
   *
   */
  ///@{
  template <class... Args> void emplace_front(Args &&... args);
  void push_front(const T &x);
  void push_front(T &&x);
  void pop_front();

  template <class... Args>
  iterator emplace_after(const_iterator position, Args &&... args);
  iterator insert_after(const_iterator position, const T &x);
  iterator insert_after(const_iterator position, T &&x);

  iterator insert_after(const_iterator position, size_type n, const T &x);
  template <class InputIterator>
  iterator insert_after(const_iterator position, InputIterator first,
                        InputIterator last);
  iterator insert_after(const_iterator position, std::initializer_list<T> il);

  iterator erase_after(const_iterator position) noexcept;
  iterator erase_after(const_iterator position, iterator last) noexcept;
  void swap(forward_list<T, Allocator> &);

  void resize(size_type sz);
  void resize(size_type sz, const value_type &c);
  void clear();
  ///@}

  /**
   * @name Forward List Operations
   *
   */
  ///@{
  void splice_after(const_iterator position,
                    forward_list<T, Allocator> &&x) noexcept;
  void splice_after(const_iterator position, forward_list<T, Allocator> &&x,
                    const_iterator i) noexcept;
  void splice_after(const_iterator position, forward_list<T, Allocator> &&x,
                    const_iterator first, const_iterator last);

  void remove(const T &value);
  template <class Predicate> void remove_if(Predicate pred);

  void unique();
  template <class BinaryPredicate> void unique(BinaryPredicate binary_pred);

  void merge(forward_list<T, Allocator> &&x);
  template <class Compare>
  void merge(forward_list<T, Allocator> &&x, Compare comp);

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
void swap(forward_list<T, Allocator> &x, forward_list<T, Allocator> &y);

/**
 * @defgroup flist-comparisons Comparisons
 *
 */
///@{
template <class T, class Allocator>
bool operator==(const forward_list<T, Allocator> &x,
                const forward_list<T, Allocator> &y);
template <class T, class Allocator>
bool operator<(const forward_list<T, Allocator> &x,
               const forward_list<T, Allocator> &y);
template <class T, class Allocator>
bool operator!=(const forward_list<T, Allocator> &x,
                const forward_list<T, Allocator> &y);
template <class T, class Allocator>
bool operator>(const forward_list<T, Allocator> &x,
               const forward_list<T, Allocator> &y);
template <class T, class Allocator>
bool operator>=(const forward_list<T, Allocator> &x,
                const forward_list<T, Allocator> &y);
template <class T, class Allocator>
bool operator<=(const forward_list<T, Allocator> &x,
                const forward_list<T, Allocator> &y);

///@}
END_NS_ZXX_CORE_CONTAINER

#endif // !_FORWARD_LIST_H_