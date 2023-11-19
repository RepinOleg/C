#ifndef CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MAP_H_

#include <functional>
#include <vector>

#include "s21_rbtree.h"

namespace s21 {

template <typename Key, typename T, typename Compare = std::less<Key>>
class map {
 public:
  // Typedefs
  using key_type = Key;
  using mapped_type = T;
  using compare_type = Compare;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator =
      typename RBTree<key_type, value_type, compare_type>::iterator;
  using const_iterator =
      typename RBTree<key_type, value_type, compare_type>::const_iterator;
  using size_type = size_t;
  using node_type = typename RBTree<key_type, value_type, compare_type>::Node;

  // Map Member functions
  map();
  explicit map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m) noexcept;
  map& operator=(const map& m) noexcept;
  map& operator=(map&& m) noexcept;
  ~map();

  // Map Element access
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key) noexcept;

  // Map Iterators
  iterator begin() const noexcept;
  iterator end() const noexcept;

  // Map Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // Map Modifiers
  void clear() noexcept;
  std::pair<iterator, bool> insert(const value_type& value) noexcept;
  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) noexcept;
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) noexcept;
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept;
  void erase(iterator pos) noexcept;
  void swap(map& other) noexcept;
  void merge(map& other) noexcept;

  // Map Lookup
  bool contains(const key_type& key) const noexcept;

 private:
  RBTree<key_type, value_type, compare_type> tree_;
};
}  // namespace s21
#include "s21_map.inc"
#endif  // CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_MAP_H_
