namespace s21 {

template <class T>
deque<T>::deque() {
  list_.size = 0;
  list_.head = nullptr;
  list_.tail = nullptr;
}

template <class T>
deque<T>::deque(std::initializer_list<value_type> const &items) : deque() {
  for (auto i = items.begin(); i != items.end(); ++i) {
    push_back(*i);
  }
}

template <class T>
deque<T>::deque(const deque &other) : deque() {
  Node *current = other.list_.head;
  while (current) {
    push_back(current->value);
    current = current->next;
  }
}

template <class T>
deque<T>::deque(deque &&other) noexcept : deque() {
  list_.size = std::exchange(other.list_.size, 0);
  list_.head = std::exchange(other.list_.head, nullptr);
  list_.tail = std::exchange(other.list_.tail, nullptr);
}

template <class T>
deque<T> &deque<T>::operator=(const deque &other) {
  if (this != &other) {
    // Сперва удалить текущую очередь
    while (!empty()) {
      pop_front();
    }
    // Затем скопировать в пустую очередь содержимое other
    Node *current = other.list_.head;
    while (current) {
      push_back(current->value);
      current = current->next;
    }
  }
  return *this;
}

template <class T>
deque<T> &deque<T>::operator=(deque &&other) noexcept {
  if (this != &other) {
    // Сперва удалить текущую очередь
    while (!empty()) {
      pop_front();
    }
    // Затем захватить ресурсы other и оставить other в удаляемом состоянии
    list_.size = std::exchange(other.list_.size, 0);
    list_.head = std::exchange(other.list_.head, nullptr);
    list_.tail = std::exchange(other.list_.tail, nullptr);
  }
  return *this;
}

template <class T>
deque<T>::~deque() {
  clear();
}

template <class T>
const typename deque<T>::value_type &deque<T>::front() const noexcept {
  return list_.head->value;
}

template <class T>
const typename deque<T>::value_type &deque<T>::back() const noexcept {
  return list_.tail->value;
}

template <class T>
bool deque<T>::empty() const noexcept {
  return list_.head == nullptr;
}

template <class T>
typename deque<T>::size_type deque<T>::size() const noexcept {
  return list_.size;
}

template <class T>
void deque<T>::clear() noexcept {
  while (!empty()) {
    pop_front();
  }
}

template <class T>
void deque<T>::swap(deque &other) noexcept {
  std::swap(list_.size, other.list_.size);
  std::swap(list_.head, other.list_.head);
  std::swap(list_.tail, other.list_.tail);
}

template <class T>
void deque<T>::push_back(deque::const_reference value) noexcept {
  Node *temp_node = new Node(value);
  temp_node->next = nullptr;
  temp_node->prev = list_.tail;
  if (list_.tail) {
    list_.tail->next = temp_node;
  }
  list_.tail = temp_node;
  if (list_.head == nullptr) {
    list_.head = temp_node;
  }
  ++list_.size;
}

template <class T>
void deque<T>::pop_back() noexcept {
  if (list_.tail) {
    Node *temp_node = list_.tail;
    list_.tail = list_.tail->prev;
    if (list_.tail) {
      list_.tail->next = nullptr;
    } else {
      list_.head = nullptr;
    }
    delete temp_node;
    --list_.size;
  }
}

template <class T>
void deque<T>::push_front(deque::const_reference value) noexcept {
  Node *temp_node = new Node(value);
  temp_node->next = list_.head;
  temp_node->prev = nullptr;
  if (list_.head) {
    list_.head->prev = temp_node;
  }
  list_.head = temp_node;
  if (list_.tail == nullptr) {
    list_.tail = temp_node;
  }
  ++list_.size;
}

template <class T>
void deque<T>::pop_front() noexcept {
  if (list_.head) {
    Node *temp_node = list_.head;
    list_.head = list_.head->next;
    if (list_.head) {
      list_.head->prev = nullptr;
    } else {
      list_.tail = nullptr;
    }
    delete temp_node;
    --list_.size;
  }
}

}  // namespace s21
