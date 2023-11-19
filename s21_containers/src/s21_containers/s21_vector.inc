namespace s21 {
template <typename T>
vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : data_(new value_type[items.size()]),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector &other)
    : data_(new value_type[other.capacity_]),
      size_(other.size_),
      capacity_(other.capacity_) {
  std::copy(other.data_, other.data_ + other.size_, data_);
}

template <typename T>
vector<T>::vector(vector &&other) noexcept {
  data_ = std::exchange(other.data_, nullptr);
  size_ = std::exchange(other.size_, 0);
  capacity_ = std::exchange(other.capacity_, 0);
}

template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &other) {
  delete[] data_;
  data_ = new value_type[other.size()];
  std::copy(other.data_, other.data_ + other.size_, data_);
  size_ = other.size_;
  capacity_ = other.capacity_;
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&other) noexcept {
  if (this != &other) {
    this->swap(other);
    delete[] other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

template <typename T>
vector<T>::~vector() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
typename vector<T>::value_type &vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error! Position out of vector range!\n");
  }
  return data_[pos];
}

template <typename T>
const typename vector<T>::value_type &vector<T>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Error! Position out of vector range!\n");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::value_type &vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error! Position out of vector range!\n");
  }
  return data_[pos];
}

template <typename T>
const typename vector<T>::value_type &vector<T>::operator[](
    size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Error! Position out of vector range!\n");
  }
  return data_[pos];
}

template <typename T>
const typename vector<T>::value_type &vector<T>::front() const noexcept {
  return data_[0];
}

template <typename T>
const typename vector<T>::value_type &vector<T>::back() const noexcept {
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::iterator vector<T>::data() noexcept {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() noexcept {
  return iterator(data_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
  return const_iterator(data_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept {
  return iterator(data_ + size_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const noexcept {
  return const_iterator(data_ + size_);
}

template <typename T>
bool vector<T>::empty() const noexcept {
  return !size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return SIZE_MAX / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size <= capacity_) {
    return;
  }
  if (size > max_size()) {
    throw std::out_of_range("Error! New size is too big!\n");
  }
  value_type *new_data = new value_type[size];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = size;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    value_type *new_data = new value_type[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::clear() noexcept {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(
    iterator pos,
    const_reference value) {  // pos = iterator before which the content will be
                              // inserted (may be the end() iterator!)
  // Check that pos is in correct bounds
  size_type ind = pos - begin();
  if (ind > size_) {
    throw std::out_of_range("Eror! Position out of vector range!\n");
  }
  // Add memory if necessary
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  // Define position for the new element and move those after it
  iterator new_ind = begin() + ind;
  for (iterator it = end(); it != new_ind; --it) {
    *it = *(it - 1);
  }
  // Insert the new value and increase size
  *new_ind = value;
  ++size_;
  return new_ind;
}

template <typename T>
void vector<T>::erase(iterator pos) noexcept {
  size_type ind = pos - begin();
  iterator new_ind = begin() + ind;
  for (iterator it = new_ind; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --size_;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_] = value;
  ++size_;
}

template <typename T>
void vector<T>::pop_back() noexcept {
  if (size_) {
    --size_;
  }
}

template <typename T>
void vector<T>::swap(vector &other) noexcept {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  vector<value_type> new_data{args...};
  iterator new_ind = begin() + (pos - cbegin());
  for (size_t i = 0; i != new_data.size(); ++i) {
    new_ind = insert(new_ind, new_data[i]);
    ++new_ind;
  }
  return new_ind;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(cend(), args...);
}

}  // namespace s21
