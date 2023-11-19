namespace s21 {
template <class T, class Container>
stack<T, Container>::stack() : deque_() {}

template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const &items)
    : deque_() {
  for (auto i = items.begin(); i != items.end(); ++i) {
    deque_.push_front(*i);
  }
}

template <class T, class Container>
stack<T, Container>::stack(const stack &other) : deque_(other.deque_) {}

template <class T, class Container>
stack<T, Container>::stack(stack &&other) noexcept
    : deque_(std::move(other.deque_)) {}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(const stack &other) {
  if (this != &other) {
    deque_ = other.deque_;
  }
  return *this;
}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=(stack &&other) noexcept {
  if (this != &other) {
    deque_ = std::move(other.deque_);
  }
  return *this;
}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top()
    const noexcept {
  return deque_.front();
}

template <class T, class Container>
bool stack<T, Container>::empty() const noexcept {
  return deque_.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size()
    const noexcept {
  return deque_.size();
}

template <class T, class Container>
void stack<T, Container>::push(stack::const_reference value) noexcept {
  deque_.push_front(value);
}

template <class T, class Container>
void stack<T, Container>::pop() noexcept {
  deque_.pop_front();
}

template <class T, class Container>
void stack<T, Container>::swap(stack &other) noexcept {
  std::swap(deque_, other.deque_);
}

template <class T, class Container>
template <class... Args>
void stack<T, Container>::insert_many_front(Args &&...args) noexcept {
  for (const auto &arg : {args...}) {
    deque_.push_front(arg);
  }
}

}  // namespace s21
