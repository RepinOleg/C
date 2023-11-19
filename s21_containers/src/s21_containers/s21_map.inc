namespace s21 {

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map() {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(std::initializer_list<value_type> const& items) {
  for (auto i : items) {
    insert(i);
  }
}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(const map& m) {
  for (auto i : m) {
    insert(i);
  }
}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(map&& m) noexcept : tree_(std::move(m.tree_)) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::~map() {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>& map<Key, T, Compare>::operator=(map&& m) noexcept {
  tree_ = std::move(m.tree_);
  return *this;
}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>& map<Key, T, Compare>::operator=(const map& m) noexcept {
  tree_ = std::copy(m.tree_);
  return *this;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::at(const key_type& key) -> mapped_type& {
  auto i = iterator(tree_.find(key));
  if (i == end()) {
    throw std::out_of_range("map::at");
  }
  return (*i).second;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::operator[](const key_type& key) noexcept
    -> mapped_type& {
  auto i = iterator(tree_.find(key));
  if (i == end()) {
    i = insert(key, mapped_type()).first;
  }
  return (*i).second;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::begin() const noexcept -> iterator {
  return tree_.begin();
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::end() const noexcept -> iterator {
  return tree_.end();
}

template <typename Key, typename T, typename Compare>
bool map<Key, T, Compare>::empty() const noexcept {
  return tree_.size() == 0;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::size() const noexcept -> size_type {
  return tree_.size();
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::max_size() const noexcept -> size_type {
  return tree_.max_size();
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::clear() noexcept {
  tree_.delete_tree();
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::insert(const value_type& value) noexcept
    -> std::pair<iterator, bool> {
  std::pair<iterator, bool> res;
  node_type* x = tree_.insert(value.first, value);
  res.second = true;
  if (!x) {
    x = tree_.find(value.first);
    res.second = false;
  } else {
    tree_.fix(x);
  }
  res.first = iterator(x);
  return res;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::insert(const key_type& key,
                                  const mapped_type& obj) noexcept
    -> std::pair<iterator, bool> {
  std::pair<iterator, bool> res;
  node_type* x = tree_.insert(key, value_type(key, obj));
  res.second = true;
  if (!x) {
    x = tree_.find(key);
    res.second = false;
  } else {
    tree_.fix(x);
  }
  res.first = iterator(x);
  return res;
}

template <typename Key, typename T, typename Compare>
auto map<Key, T, Compare>::insert_or_assign(const key_type& key,
                                            const mapped_type& obj) noexcept
    -> std::pair<iterator, bool> {
  std::pair<iterator, bool> res;
  node_type* x = tree_.insert(key, value_type(key, obj));
  res.second = true;
  if (!x) {
    x = tree_.find(key);
    operator[](key) = obj;
    res.second = false;
  } else {
    tree_.fix(x);
  }
  res.first = iterator(x);
  return res;
}

template <typename Key, typename T, typename Compare>
template <typename... Args>
auto map<Key, T, Compare>::insert_many(Args&&... args) noexcept
    -> std::vector<std::pair<iterator, bool>> {
  std::vector<std::pair<iterator, bool>> res;
  for (const auto& arg : {args...}) {
    res.push_back(insert(arg));
  }
  return res;
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::erase(iterator pos) noexcept {
  tree_.delete_node(pos);
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::swap(map& other) noexcept {
  tree_.swap(other.tree_);
}

template <typename Key, typename T, typename Compare>
void map<Key, T, Compare>::merge(map& other) noexcept {
  tree_.merge(other.tree_);
}

template <typename Key, typename T, typename Compare>
bool map<Key, T, Compare>::contains(const key_type& key) const noexcept {
  return iterator(tree_.find(key)) != end();
}

}  // namespace s21
