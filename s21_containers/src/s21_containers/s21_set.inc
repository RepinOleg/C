namespace s21 {

template <typename T, typename Compare>
set<T, Compare>::set() {}

template <typename T, typename Compare>
set<T, Compare>::set(std::initializer_list<value_type> const& items) {
  for (auto i : items) {
    insert(i);
  }
}

template <typename T, typename Compare>
set<T, Compare>::set(const set& s) {
  for (auto i : s) {
    insert(i);
  }
}

template <typename T, typename Compare>
set<T, Compare>::set(set&& s) noexcept : tree_(std::move(s.tree_)) {}

template <typename T, typename Compare>
set<T, Compare>::~set() {}

template <typename T, typename Compare>
set<T, Compare>& set<T, Compare>::operator=(const set& s) noexcept {
  tree_ = std::copy(s.tree_);
  return *this;
}

template <typename T, typename Compare>
set<T, Compare>& set<T, Compare>::operator=(set&& s) noexcept {
  tree_ = std::move(s.tree_);
  return *this;
}

template <typename T, typename Compare>
auto set<T, Compare>::begin() const noexcept -> iterator {
  return tree_.begin();
}

template <typename T, typename Compare>
auto set<T, Compare>::end() const noexcept -> iterator {
  return tree_.end();
}

template <typename T, typename Compare>
bool set<T, Compare>::empty() const noexcept {
  return tree_.size() == 0;
}

template <typename T, typename Compare>
auto set<T, Compare>::size() const noexcept -> size_type {
  return tree_.size();
}

template <typename T, typename Compare>
auto set<T, Compare>::max_size() const noexcept -> size_type {
  return tree_.max_size();
}

template <typename T, typename Compare>
void set<T, Compare>::clear() noexcept {
  tree_.delete_tree();
}

template <typename T, typename Compare>
auto set<T, Compare>::insert(const value_type& value) noexcept
    -> std::pair<iterator, bool> {
  std::pair<iterator, bool> res;
  node_type* x = tree_.insert(value, value);
  res.second = true;
  if (!x) {
    x = tree_.find(value);
    res.second = false;
  } else {
    tree_.fix(x);
  }
  res.first = iterator(x);
  return res;
}

template <typename T, typename Compare>
template <typename... Args>
auto set<T, Compare>::insert_many(Args&&... args) noexcept
    -> std::vector<std::pair<iterator, bool>> {
  std::vector<std::pair<iterator, bool>> res;
  for (const auto& arg : {args...}) {
    res.push_back(insert(arg));
  }
  return res;
}

template <typename T, typename Compare>
void set<T, Compare>::erase(iterator pos) noexcept {
  tree_.delete_node(pos);
}

template <typename T, typename Compare>
void set<T, Compare>::swap(set& other) noexcept {
  tree_.swap(other.tree_);
}

template <typename T, typename Compare>
void set<T, Compare>::merge(set& other) noexcept {
  tree_.merge(other.tree_);
}

template <typename T, typename Compare>
auto set<T, Compare>::find(const key_type& key) const noexcept -> iterator {
  return iterator(tree_.find(key));
}

template <typename T, typename Compare>
bool set<T, Compare>::contains(const key_type& key) const noexcept {
  return find(key) != end();
}

}  // namespace s21
