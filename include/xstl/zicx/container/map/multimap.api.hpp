#ifndef _MULTIMAP_API_H_
#define _MULTIMAP_API_H_

#include <map>

#include "xstl/config/config.h"

_BEGIN_XSTL
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
class multimap {
public:
  // types:
  typedef Key* iterator;
  typedef const Key* const_iterator; 
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  
  typedef Key key_type;
  typedef std::pair<const Key, T> value_type;
  typedef T mapped_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef typename Allocator::size_type size_type;
  typedef typename Allocator::difference_type difference_type;
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;

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
  explicit multimap(const Compare &comp = Compare(),
                    const Allocator & = Allocator());
  template <class InputIterator>
  multimap(InputIterator first, InputIterator last,
           const Compare &comp = Compare(), const Allocator & = Allocator());
  multimap(const multimap<Key, T, Compare, Allocator> &x);
  multimap(multimap<Key, T, Compare, Allocator> &&x);
  explicit multimap(const Allocator &);
  multimap(const multimap &, const Allocator &);
  multimap(multimap &&, const Allocator &);
  multimap(std::initializer_list<value_type>, const Compare & = Compare(),
           const Allocator & = Allocator());

  ~multimap();

  multimap &operator=(const multimap &);
  multimap &operator=(multimap &&);
  multimap &operator=(std::initializer_list<value_type>);

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
  template <class... Args> iterator emplace(Args &&... args);
  template <class... Args>
  iterator emplace_hint(const_iterator position, Args &&... args);
  iterator insert(const value_type &x);
  template <class P> iterator insert(P &&x);
  iterator insert(const_iterator position, const value_type &x);
  template <class P> iterator insert(const_iterator position, P &&x);
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);
  void insert(std::initializer_list<value_type>);
  iterator erase(iterator position);
  size_type erase(const key_type &x);
  iterator erase(iterator first, iterator last);
  void swap(multimap &);
  void clear();

  // observers:
  key_compare key_comp() const;
  value_compare value_comp() const;

  // multimap operations:
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
bool operator==(const multimap<Key, T, Compare, Allocator> &x,
                const multimap<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator<(const multimap<Key, T, Compare, Allocator> &x,
               const multimap<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const multimap<Key, T, Compare, Allocator> &x,
                const multimap<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator>(const multimap<Key, T, Compare, Allocator> &x,
               const multimap<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const multimap<Key, T, Compare, Allocator> &x,
                const multimap<Key, T, Compare, Allocator> &y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const multimap<Key, T, Compare, Allocator> &x,

                const multimap<Key, T, Compare, Allocator> &y);
// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(multimap<Key, T, Compare, Allocator> &x,
          multimap<Key, T, Compare, Allocator> &y);
          
_END_XSTL

#endif // !_MULTIMAP_API_H_