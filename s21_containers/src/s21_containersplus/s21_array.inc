namespace s21 {
template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), elems_);
}

template <typename T, std::size_t N>
array<T, N>::array(const array &other) {
  std::copy(other.elems_, other.elems_ + N, elems_);
}

template <typename T, std::size_t N>
array<T, N>::array(array &&other) noexcept {
  std::move(other.elems_, other.elems_ + N, elems_);
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array &other) {
  std::copy(other.elems_, other.elems_ + N, elems_);
  return *this;
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(array &&other) noexcept {
  for (size_t i = 0; i < N; ++i) {
    elems_[i] = std::move(other.elems_[i]);
  }
  return *this;
}

template <typename T, std::size_t N>
array<T, N>::~array() {}

template <typename T, std::size_t N>
typename array<T, N>::value_type &array<T, N>::operator[](size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Error! Position out of the array range\n");
  }
  return elems_[pos];
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type &array<T, N>::operator[](
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Error! Position out of the array range\n");
  }
  return elems_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::begin() noexcept {
  return elems_;
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type *array<T, N>::cbegin() const noexcept {
  return elems_;
}

template <typename T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::end() noexcept {
  return elems_ + size_;
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type *array<T, N>::cend() const noexcept {
  return elems_ + size_;
}

template <typename T, std::size_t N>
typename array<T, N>::value_type &array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Error! Position out of the array range\n");
  }
  return (*this)[pos];
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type &array<T, N>::at(size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Error! Position out of the array range\n");
  }
  return (*this)[pos];
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type &array<T, N>::front() const noexcept {
  return elems_[0];
}

template <typename T, std::size_t N>
const typename array<T, N>::value_type &array<T, N>::back() const {
  if (!size_) throw std::out_of_range("Current index is out of bounds");
  return elems_[N - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::value_type *array<T, N>::data() noexcept {
  return begin();
}

template <typename T, std::size_t N>
bool array<T, N>::empty() const noexcept {
  return !size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return size();
}

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap_ranges(elems_, elems_ + N, other.elems_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(elems_, elems_ + N, value);
}

}  // namespace s21
