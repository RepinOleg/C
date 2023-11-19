namespace s21 {

template <typename T, typename Compare>
multiset<T, Compare>::multiset() {}

template <typename T, typename Compare>
multiset<T, Compare>::multiset(std::initializer_list<value_type> const& items) {
  for (auto i : items) {
    insert(i);
  }
}

template <typename T, typename Compare>
multiset<T, Compare>::multiset(const multiset& s) {
  for (auto i : s) {
    insert(i);
  }
}

template <typename T, typename Compare>
multiset<T, Compare>::multiset(multiset&& s) noexcept
    : tree_(std::move(s.tree_)) {}

template <typename T, typename Compare>
multiset<T, Compare>::~multiset() {}

template <typename T, typename Compare>
multiset<T, Compare>& multiset<T, Compare>::operator=(
    const multiset& s) noexcept {
  tree_ = std::copy(s.tree_);
  return *this;
}

template <typename T, typename Compare>
multiset<T, Compare>& multiset<T, Compare>::operator=(multiset&& s) noexcept {
  tree_ = std::move(s.tree_);
  return *this;
}

template <typename T, typename Compare>
auto multiset<T, Compare>::begin() const noexcept -> iterator {
  return tree_.begin();
}

template <typename T, typename Compare>
auto multiset<T, Compare>::end() const noexcept -> iterator {
  return tree_.end();
}

template <typename T, typename Compare>
bool multiset<T, Compare>::empty() const noexcept {
  return tree_.size() == 0;
}

template <typename T, typename Compare>
auto multiset<T, Compare>::size() const noexcept -> size_type {
  return tree_.size();
}

template <typename T, typename Compare>
auto multiset<T, Compare>::max_size() const noexcept -> size_type {
  return tree_.max_size();
}

template <typename T, typename Compare>
void multiset<T, Compare>::clear() noexcept {
  tree_.delete_tree();
}

template <typename T, typename Compare>
auto multiset<T, Compare>::insert(const value_type& value) noexcept
    -> iterator {
  node_type* x = tree_.insert_non_uniq(value, value);
  tree_.fix(x);
  return iterator(x);
}

template <typename T, typename Compare>
template <typename... Args>
auto multiset<T, Compare>::insert_many(Args&&... args) noexcept
    -> std::vector<std::pair<iterator, bool>> {
  std::vector<std::pair<iterator, bool>> res;
  for (const auto& arg : {args...}) {
    res.push_back(std::pair<iterator, bool>(insert(arg), true));
  }
  return res;
}

template <typename T, typename Compare>
void multiset<T, Compare>::erase(iterator pos) noexcept {
  tree_.delete_node(pos);
}

template <typename T, typename Compare>
void multiset<T, Compare>::swap(multiset& other) noexcept {
  tree_.swap(other.tree_);
}

template <typename T, typename Compare>
void multiset<T, Compare>::merge(multiset& other) noexcept {
  tree_.merge(other.tree_);
}

template <typename T, typename Compare>
auto multiset<T, Compare>::count(const key_type& key) const noexcept
    -> size_type {
  size_type res = 0;
  for (auto i = iterator(tree_.find(key)); i != end(); ++i) {
    ++res;
  }
  return res;
}

template <typename T, typename Compare>
auto multiset<T, Compare>::find(const key_type& key) const noexcept
    -> iterator {
  return iterator(tree_.find(key));
}

template <typename T, typename Compare>
bool multiset<T, Compare>::contains(const key_type& key) const noexcept {
  return find(key) != end();
}

template <typename T, typename Compare>
auto multiset<T, Compare>::equal_range(const key_type& key) const noexcept
    -> std::pair<iterator, iterator> {
  auto equality_start = iterator(tree_.find(key));
  auto equality_end = iterator(tree_.find(key));
  for (; *equality_end == key; ++equality_end) {
  }
  return std::pair<iterator, iterator>(equality_start, equality_end);
}

template <typename T, typename Compare>
auto multiset<T, Compare>::lower_bound(const key_type& key) const noexcept
    -> iterator {
  return iterator(tree_.find(key));
}

template <typename T, typename Compare>
auto multiset<T, Compare>::upper_bound(const key_type& key) const noexcept
    -> iterator {
  auto equality_end = iterator(tree_.find(key));
  for (; *equality_end == key; ++equality_end) {
  }
  return equality_end;
}

}  // namespace s21
