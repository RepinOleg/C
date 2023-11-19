namespace s21 {
template <class T, class Container>
queue<T, Container>::queue() : deque_() {}

template <class T, class Container>
queue<T, Container>::queue(std::initializer_list<value_type> const &items)
    : deque_(items) {}

template <class T, class Container>
queue<T, Container>::queue(const queue &other) : deque_(other.deque_) {}

template <class T, class Container>
queue<T, Container>::queue(queue &&other) noexcept
    : deque_(std::move(other.deque_)) {}

template <class T, class Container>
queue<T, Container> &queue<T, Container>::operator=(const queue &other) {
  if (this != &other) {
    deque_ = other.deque_;
  }
  return *this;
}

template <class T, class Container>
queue<T, Container> &queue<T, Container>::operator=(queue &&other) noexcept {
  if (this != &other) {
    deque_ = std::move(other.deque_);
  }
  return *this;
}

template <class T, class Container>
queue<T, Container>::~queue() {}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::front()
    const noexcept {
  return deque_.front();
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::back()
    const noexcept {
  return deque_.back();
}

template <class T, class Container>
bool queue<T, Container>::empty() const noexcept {
  return deque_.empty();
}

template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size()
    const noexcept {
  return deque_.size();
}

template <class T, class Container>
void queue<T, Container>::push(queue::const_reference value) noexcept {
  deque_.push_back(value);
}

template <class T, class Container>
void queue<T, Container>::pop() noexcept {
  deque_.pop_front();
}

template <class T, class Container>
void queue<T, Container>::swap(queue &other) noexcept {
  std::swap(deque_, other.deque_);
}

template <class T, class Container>
template <class... Args>
void queue<T, Container>::insert_many_back(Args &&...args) noexcept {
  for (const auto &arg : {args...}) {
    deque_.push_back(arg);
  }
}

}  // namespace s21
