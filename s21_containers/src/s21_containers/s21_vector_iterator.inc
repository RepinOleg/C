namespace s21 {

// Iterators

template <typename T>
vector<T>::VectorIterator::VectorIterator() noexcept : ptr_(nullptr) {}

template <typename T>
vector<T>::VectorIterator::VectorIterator(value_type *ptr) noexcept
    : ptr_(ptr) {}

template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() noexcept {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(
    int) noexcept {
  VectorIterator tmp(*this);
  ++ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(
    int) noexcept {
  VectorIterator tmp(*this);
  --ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator &
vector<T>::VectorIterator::operator++() noexcept {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator &
vector<T>::VectorIterator::operator--() noexcept {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(
    const VectorIterator &other) const noexcept {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(
    const VectorIterator &other) const noexcept {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(
    int n) const noexcept {
  VectorIterator tmp(*this);
  for (int i = 0; i != n; ++i) {
    ++tmp;
  }
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(
    int n) const noexcept {
  VectorIterator tmp(*this);
  for (int i = 0; i != n; ++i) {
    --tmp;
  }
  return tmp;
}

template <typename T>
ptrdiff_t vector<T>::VectorIterator::operator-(
    const VectorIterator &other) const noexcept {
  return ptr_ - other.ptr_;
}

// Const iterators

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator() noexcept
    : ptr_(nullptr) {}

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(
    const value_type *ptr) noexcept
    : ptr_(ptr) {}

template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const noexcept {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator++(int) noexcept {
  VectorConstIterator tmp(*this);
  ++ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator--(int) noexcept {
  VectorConstIterator tmp(*this);
  --ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator &
vector<T>::VectorConstIterator::operator++() noexcept {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorConstIterator &
vector<T>::VectorConstIterator::operator--() noexcept {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator &other) const noexcept {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator &other) const noexcept {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(int n) const noexcept {
  VectorConstIterator tmp(*this);
  for (int i = 0; i != n; ++i) {
    ++tmp;
  }
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator-(int n) const noexcept {
  VectorConstIterator tmp(*this);
  for (int i = 0; i != n; ++i) {
    --tmp;
  }
  return tmp;
}

template <typename T>
ptrdiff_t vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator &other) const noexcept {
  return ptr_ - other.ptr_;
}

}  // namespace s21
