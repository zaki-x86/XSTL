#ifndef _UNORDERED_MULTIMAP_API_H_

#define _UNORDERED_MULTIMAP_API_H_

#include <unordered_map>
#include "config/zxx.config.h"

BEGIN_NS_ZXX_CORE_CONTAINER

template <class Key, class T, class Hash = std::hash<Key>,
          class KeyEqual = std::equal_to<Key>,
          class Allocator = std::allocator<std::pair<const Key, T>>>
class ZXX_PUBLIC unordered_multimap {
public:
  // types:
  typedef Key* iterator;
  typedef const Key* const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  
  typedef Key key_type;
  typedef std::pair<const Key, T> value_type;
  typedef T mapped_type;
  typedef Hash hasher;
  typedef KeyEqual key_equal;
  typedef Allocator allocator_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef typename Allocator::size_type size_type;
  typedef typename Allocator::difference_type difference_type;
  typedef typename Allocator::local_iterator local_iterator;
  typedef typename Allocator::const_local_iterator const_local_iterator;
  typedef Key* iterator; // temp
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef const Key* const_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  // construct/copy/destroy:
  explicit unordered_multimap(size_type n = 0, const Hash &hf = Hash(),
                         const KeyEqual &eql = KeyEqual(),
                         const Allocator & = Allocator());

  template <class InputIterator>
  unordered_multimap(InputIterator first, InputIterator last, size_type n = 0,
                const Hash &hf = Hash(), const KeyEqual &eql = KeyEqual(),
                const Allocator & = Allocator());

  unordered_multimap(const unordered_multimap &);
  unordered_multimap(unordered_multimap &&);
  unordered_multimap(std::initializer_list<value_type>, size_type n = 0,
                const Hash &hf = Hash(), const KeyEqual &eql = KeyEqual(),
                const Allocator & = Allocator());

  ~unordered_multimap();

  unordered_multimap &operator=(const unordered_multimap &);
  unordered_multimap &operator=(unordered_multimap &&);
  unordered_multimap &operator=(std::initializer_list<value_type>);

  // iterators:
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  const_iterator cbegin() const;
  const_iterator cend() const;

  // capacity:
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // modifiers:
  template <class... Args> std::pair<iterator, bool> emplace(Args &&... args);

  template <class... Args>
  iterator emplace_hint(const_iterator position, Args &&... args);

  std::pair<iterator, bool> insert(const value_type &x);
  std::pair<iterator, bool> insert(value_type &&x);
  iterator insert(const_iterator position, const value_type &x);
  iterator insert(const_iterator position, value_type &&x);
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last);
  void insert(std::initializer_list<value_type>);
  iterator erase(const_iterator position);
  size_type erase(const key_type &x);
  iterator erase(const_iterator first, const_iterator last);
  void clear();
  void swap(unordered_multimap &);

  // observers:
  hasher hash_function() const;
  key_equal key_eq() const;
  allocator_type get_allocator() const;

  // map operations:
  iterator find(const key_type &x);
  const_iterator find(const key_type &x) const;
  size_type count(const key_type &x) const;
  std::pair<iterator, iterator> equal_range(const key_type& k);
  std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

  // bucket interface:
  size_type bucket_count() const;
  size_type max_bucket_count() const;
  size_type bucket_size(size_type n) const;
  size_type bucket(const key_type &x) const;
  local_iterator begin(size_type n);
  local_iterator end(size_type n);
  const_local_iterator begin(size_type n) const;
  const_local_iterator end(size_type n) const;
  const_local_iterator cbegin(size_type n) const;
  const_local_iterator cend(size_type n) const;

  // hash policy
  float load_factor() const;
  float max_load_factor() const;
  void max_load_factor(float z);
  void rehash(size_type n);
  void reserve(size_type n);
};

template <class Key, class T, class Hash, class Pred, class Alloc>
void swap(unordered_multimap<Key, T, Hash, Pred, Alloc>& x,
unordered_multimap<Key, T, Hash, Pred, Alloc>& y);

template <class Key, class T, class Hash, class Pred, class Alloc>
bool operator==(const unordered_multimap<Key, T, Hash, Pred, Alloc> &a,
                const unordered_multimap<Key, T, Hash, Pred, Alloc> &b);

template <class Key, class T, class Hash, class Pred, class Alloc>
bool operator!=(const unordered_multimap<Key, T, Hash, Pred, Alloc> &a,
                const unordered_multimap<Key, T, Hash, Pred, Alloc> &b);

END_NS_ZXX_CORE_CONTAINER

#endif // !_UNORDERED_MULTIMAP_API_H_