#ifndef CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_SET_H_

#include "s21_rbtree.h"

namespace s21 {

template <typename T, typename Compare = std::less<T>>
class set {
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
  set();
  explicit set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s) noexcept;
  set& operator=(const set& s) noexcept;
  set& operator=(set&& s) noexcept;
  ~set();

  // Iterators
  iterator begin() const noexcept;
  iterator end() const noexcept;

  // Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // Modifiers
  void clear() noexcept;
  std::pair<iterator, bool> insert(const value_type& value) noexcept;
  // vector<std::pair<iterator, bool>> insert_many(Args&&... args);
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept;
  void erase(iterator pos) noexcept;
  void swap(set& other) noexcept;
  void merge(set& other) noexcept;

  // Lookup
  iterator find(const key_type& key) const noexcept;
  bool contains(const key_type& key) const noexcept;

 private:
  RBTree<key_type, value_type, compare_type> tree_;
};
}  // namespace s21
#include "s21_set.inc"
#endif  // CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_SET_H_
