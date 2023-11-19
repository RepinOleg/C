#ifndef CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MULTISET_H_

#include "../s21_containers/s21_rbtree.h"

namespace s21 {

template <typename T, typename Compare = std::less<T>>
class multiset {
 public:
  // Typedefs
  using key_type = T;
  using value_type = T;
  using compare_type = Compare;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator =
      typename RBTree<key_type, value_type, compare_type>::iterator;
  using const_iterator =
      typename RBTree<key_type, value_type, compare_type>::const_iterator;
  using size_type = size_t;
  using node_type = typename RBTree<key_type, value_type, compare_type>::Node;

  // Member functions
  multiset();
  explicit multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& s);
  multiset(multiset&& s) noexcept;
  multiset& operator=(const multiset& s) noexcept;
  multiset& operator=(multiset&& s) noexcept;
  ~multiset();

  // Iterators
  iterator begin() const noexcept;
  iterator end() const noexcept;

  // Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // Modifiers
  void clear() noexcept;
  iterator insert(const value_type& value) noexcept;
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept;
  void erase(iterator pos) noexcept;
  void swap(multiset& other) noexcept;
  void merge(multiset& other) noexcept;

  // Lookup
  size_type count(const key_type& key) const noexcept;
  iterator find(const key_type& key) const noexcept;
  bool contains(const key_type& key) const noexcept;
  std::pair<iterator, iterator> equal_range(const key_type& key) const noexcept;
  iterator lower_bound(const key_type& key) const noexcept;
  iterator upper_bound(const key_type& key) const noexcept;

 private:
  RBTree<key_type, value_type, compare_type> tree_;
};
}  // namespace s21
#include "s21_multiset.inc"
#endif  // CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MULTISET_H_
