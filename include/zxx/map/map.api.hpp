#ifndef _MAP_H_
#define _MAP_H_

#include <map>

#include "config/zxx.config.h"

BEGIN_NS_ZXX_CORE_CONTAINER
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
class ZXX_PUBLIC map {
public:
  // types:
  typedef Key key_type;
  typedef std::pair<const Key, T> value_type;
  typedef T mapped_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef typename Allocator::size_type size_type;
  typedef typename Allocator::difference_type difference_type;
  typedef typename Allocator::const_reference const_reference;
  typedef typename Allocator::const_pointer const_pointer;
  typedef Key* iterator; // temp
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef const Key* const_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  class value_compare {
  protected:
    Compare comp;
    value_compare(Compare c) : comp(c) {}

  public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator()(const value_type &x, const value_type &y) const {
      return comp(x.first, y.first);
    }
  };

  // construct/copy/destroy:
  explicit map(const Compare &comp = Compare(),
               const Allocator & = Allocator());

  template <class InputIterator>
  map(InputIterator first, InputIterator last, const Compare &comp = Compare(),
      const Allocator & = Allocator());

  map(const map &);
  map(map &&);
  map(std::initializer_list<value_type>, const Compare &comp = Compare(),
      const Allocator & = Allocator());

  ~map();

  map &operator=(const map &);
  map &operator=(map &&);
  map &operator=(std::initializer_list<value_type>);

  // iterators:
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

  // capacity:
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // element access:
  T &operator[](const key_type &x);
  T &operator[](key_type &&x);

  // modifiers:
  std::pair<iterator, bool> insert(const value_type &x);
  template <class P> pair<iterator, bool> insert(P &&x);
  iterator insert(const_iterator position, const value_type &x);
  template <class P>
  iterator insert(const_iterator position, P &&) template <class InputIterator>
  void insert(InputIterator first, InputIterator last);
  void insert(std::initializer_list<value_type>);
  iterator erase(iterator position);
  size_type erase(const key_type &x);
  iterator erase(iterator first, iterator last);
  void swap(map &);
  void clear();

  // observers:
  key_compare key_comp() const;
  value_compare value_comp() const;

  // map operations:
  iterator find(const key_type &x);
  const_iterator find(const key_type &x) const;
  size_type count(const key_type &x) const;

  iterator lower_bound(const key_type &x);
  const_iterator lower_bound(const key_type &x) const;
  iterator upper_bound(const key_type &x);
  const_iterator upper_bound(const key_type &x) const;

  std::pair<iterator, iterator> equal_range(const key_type &x);
  std::pair<const_iterator, const_iterator>
  equal_range(const key_type &x) const;
};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator> &x,
                const map<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator> &x,
               const map<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator> &x,
                const map<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator> &x,
               const map<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator> &x,
                const map<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator> &x,

                const map<Key, T, Compare, Allocator> &y);
// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator> &x,
          map<Key, T, Compare, Allocator> &y);
END_NS_ZXX_CORE_CONTAINER

#endif // !_MAP_H_