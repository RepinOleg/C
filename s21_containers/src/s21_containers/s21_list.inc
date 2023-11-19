namespace s21 {

/* конструктор по умолчанию */

template <typename value_type>
list<value_type>::list() {
  end_ = new ListNode;
  change_end();
}

/* конструктор копирования */

template <typename value_type>
list<value_type>::list(const list& other) : list() {
  if (this != &other) {
    clear();
    ListNode* tmp = other.front_;
    while (tmp != other.end_) {
      push_back(tmp->data_);
      tmp = tmp->next_;
    }
    change_end();
  }
}

/* конструктор перемещения */

template <typename value_type>
list<value_type>::list(list&& other) noexcept {
  swap(other);
}

/* Перегрузка оператора = */

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(
    const list& other) {
  if (this != &other && other.size() > 0) {
    clear();
    ListNode* current = other.front_;
    while (current != other.end_) {
      push_back(current->data_);
      current = current->next_;
    }
    change_end();
  }
  return *this;
}

/* Перегрузка оператора = */

template <typename value_type>
typename list<value_type>::list& list<value_type>::operator=(
    list&& other) noexcept {
  swap(other);
  return *this;
}

/* конструктор c n элементов листа */

template <typename value_type>
list<value_type>::list(size_type n) noexcept : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
  change_end();
}

/* конструктор с рядом значений */

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : list() {
  for (auto item : items) push_back(item);
  change_end();
}

/* деструктор */

template <typename value_type>
list<value_type>::~list() {
  clear();
  delete end_;
}

/* Добавление элемента в конец списка */

template <typename value_type>
void list<value_type>::push_back(const_reference value) noexcept {
  /* Выделяем память под узел*/
  ListNode* tmp = new ListNode;
  tmp->data_ = value;
  tmp->prev_ = back_;
  tmp->next_ = nullptr;
  /* Если у нас уже есть узлы, то указываем в предыдущем узле тот который мы
   * только что создали*/
  if (front_ != nullptr) {
    back_->next_ = tmp;
  }
  if (count_ == 0) {
    front_ = back_ = tmp;
  } else {
    back_ = tmp;
  }
  ++count_;
  change_end();
}

/* Добавление элемента в начало */

template <typename value_type>
void list<value_type>::push_front(const_reference value) noexcept {
  ListNode* tmp = new ListNode;
  tmp->data_ = value;
  tmp->next_ = front_;
  tmp->prev_ = end_;
  if (front_) front_->prev_ = tmp;
  front_ = tmp;
  if (!back_) {
    back_ = tmp;
  }
  ++count_;
  change_end();
}

/* Получение первого значения из списка */

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front()
    const noexcept {
  return front_ ? front_->data_ : end_->data_;
}

/* Получение последнего значения из списка */

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back()
    const noexcept {
  return back_ ? back_->data_ : end_->data_;
}

/* Проверка пустой ли список */

template <typename value_type>
bool list<value_type>::empty() const noexcept {
  return count_ == 0;
}

/* Возвращает размер списка */

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() const noexcept {
  return count_;
}

/* Возвращает максимально возможное число элементов которое мы можем добавить в
 * наш список */

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size()
    const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(ListNode) / 2;
}

/* Очистка списка */

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
}

/* Вспомогательная функция которое изменяет указатели в end, чтобы end->next
 * указывал на первый элемент, a end->prev на последний элемент в списке */

template <typename value_type>
void list<value_type>::change_end() noexcept {
  if (end_) {
    end_->next_ = front_;
    end_->prev_ = back_;
    end_->data_ = count_;
  }
  if (front_) {
    front_->prev_ = end_;
  }

  if (back_) {
    back_->next_ = end_;
  }
}

/* Получение последнего значения из списка и его удаление */

template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  ListNode* tmp = back_;
  if (count_ == 1) {
    back_ = nullptr;
    front_ = nullptr;
  } else {
    back_ = back_->prev_;
  }
  delete tmp;
  --count_;
  change_end();
}

/* Получение первого элемента из списка и его удаление */

template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  ListNode* tmp = front_;
  if (count_ == 1) {
    front_ = nullptr;
    back_ = nullptr;
  } else {
    front_ = front_->next_;
  }
  delete tmp;
  --count_;
  change_end();
}

/* Разворот списка в обратную сторону */

template <typename value_type>
void list<value_type>::reverse() noexcept {
  if (back_) {
    ListNode* tmp = front_;
    while (tmp != end_) {
      ListNode* next = tmp->next_;
      std::swap(tmp->prev_, tmp->next_);
      tmp = next;
    }
    std::swap(front_, back_);
    change_end();
  }
}

/* Метод удаляет не уникальные элементы следующие друг за другом */

template <typename value_type>
void list<value_type>::unique() noexcept {
  if (!empty()) {
    ListNode* tmp = back_;
    while (tmp != front_) {
      ListNode* tmp2 = tmp->prev_;
      if (tmp2->data_ == tmp->data_) {
        tmp2->next_ = tmp->next_;
        if (tmp == back_) {
          back_ = tmp2;
        } else {
          tmp->next_->prev_ = tmp2;
        }
        --count_;
        delete tmp;
        change_end();
      }
      tmp = tmp2;
    }
  }
}

/* Быстрая сортировка списка по возрастанию */

template <typename value_type>
void list<value_type>::sort() noexcept {
  if (count_ > 1) {
    quick_sort(begin(), --end());
  }
}

/* Рекурсивная функция сортировки */

template <typename value_type>
void list<value_type>::quick_sort(iterator start, iterator end) noexcept {
  if (start == end || start == end_ || end == end_) {
    return;
  }
  iterator pivot = partition(start, end);
  quick_sort(start, --pivot);
  quick_sort(++pivot, end);
}

/* Вспомогательная функцию для сортировки, которая разбивает список на части
 */

template <typename value_type>
typename list<value_type>::iterator list<value_type>::partition(
    iterator start, iterator end) noexcept {
  value_type pivot = *end;
  iterator pivotIndex = start;

  for (iterator i = start; i != end; ++i) {
    if (*i <= pivot) {
      std::swap(pivotIndex.node_->data_, i.node_->data_);
      ++pivotIndex;
    }
  }
  std::swap(pivotIndex.node_->data_, end.node_->data_);
  return pivotIndex;
}

/* Swap двух list */

template <typename value_type>
void list<value_type>::swap(list& other) noexcept {
  if (this != &other) {
    std::swap(front_, other.front_);
    std::swap(end_, other.end_);
    std::swap(count_, other.count_);
    std::swap(back_, other.back_);
  }
}

/* merge двух отсортированных list */

template <typename value_type>
void list<value_type>::merge(list& other) noexcept {
  if (this != &other) {
    iterator current = begin();
    if (current.node_ != end_) {
      iterator other_current = other.begin();
      iterator other_end = other.end();
      while (other_current != other_end && current != end_) {
        if (*other_current < *current)
          insert(current, *other_current++);
        else
          ++current;
      }
      if (current == end_) {
        while (other_current != other_end) {
          insert(current, *other_current++);
        }
      }
    } else {
      splice(current, other);
    }
  }
}

/* Переносит элементы из другого списка в текущий начиная с pos */

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) noexcept {
  if (this != &other && !other.empty()) {
    iterator it_pos{const_cast<ListNode*>(pos.node_)};
    iterator other_list = other.begin();
    iterator other_end = other.end();
    while (other_list != other_end) {
      insert(it_pos, *other_list++);
    }
  }
}

/* Методы класса ListIterator */

template <typename value_type>
bool list<value_type>::ListIterator::operator==(
    const ListIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator!=(
    const ListIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename value_type>
typename list<value_type>::ListIterator&
list<value_type>::ListIterator::operator++() noexcept {
  if (node_->next_) node_ = node_->next_;
  return *this;
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator++(int) noexcept {
  ListIterator tmp(*this);
  if (node_->next_) operator++();
  return tmp;
}

template <typename value_type>
typename list<value_type>::ListIterator&
list<value_type>::ListIterator::operator--() noexcept {
  if (node_->prev_) node_ = node_->prev_;
  return *this;
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator--(int) noexcept {
  ListIterator tmp(*this);
  this->operator--();
  return tmp;
}

template <typename value_type>
typename list<value_type>::reference list<value_type>::ListIterator::operator*()
    const noexcept {
  return this->node_->data_;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() const noexcept {
  return front_ ? iterator(front_) : iterator(end_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() const noexcept {
  return iterator(end_);
}

/* методы класса ListConstIterator */

template <typename value_type>
typename list<value_type>::const_reference
list<value_type>::ListConstIterator::operator*() const noexcept {
  return const_reference(this->node_->data_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin()
    const noexcept {
  return const_iterator(this->front_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend()
    const noexcept {
  return const_iterator(this->end_);
}

template <typename value_type>
typename list<value_type>::ListConstIterator&
list<value_type>::ListConstIterator::operator++() noexcept {
  if (node_->next_) node_ = node_->next_;
  return *this;
}

template <typename value_type>
typename list<value_type>::ListConstIterator
list<value_type>::ListConstIterator::operator++(int) noexcept {
  ListConstIterator tmp(node_);
  operator++();
  return tmp;
}

template <typename value_type>
typename list<value_type>::ListConstIterator&
list<value_type>::ListConstIterator::operator--() noexcept {
  if (node_->prev_) node_ = node_->prev_;
  return *this;
}

template <typename value_type>
typename list<value_type>::ListConstIterator
list<value_type>::ListConstIterator::operator--(int) noexcept {
  ListConstIterator tmp(node_);
  operator--();
  return tmp;
}

template <typename value_type>
bool list<value_type>::ListConstIterator::operator==(
    const ListConstIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename value_type>
bool list<value_type>::ListConstIterator::operator!=(
    const ListConstIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) noexcept {
  iterator result = begin();
  if (!empty()) {
    ListNode* tmp = new ListNode;
    ListNode* current = pos.node_;
    tmp->next_ = current;
    tmp->prev_ = current->prev_;
    tmp->data_ = value;
    if (front_ == current) {
      front_ = tmp;
    } else if (end_ == current) {
      back_ = tmp;
    }
    current->prev_->next_ = tmp;
    current->prev_ = tmp;
    ++count_;
    change_end();

    result = iterator(tmp);
  } else {
    push_back(value);
  }
  return result;
}
template <typename value_type>
template <class... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    const_iterator pos, Args&&... args) {
  iterator it_current{const_cast<ListNode*>(pos.node_)};
  for (const auto& arg : {args...}) {
    insert(it_current, arg);
  }
  return it_current;
}

template <typename value_type>
template <class... Args>
void list<value_type>::insert_many_back(Args&&... args) noexcept {
  for (const auto& arg : {args...}) {
    push_back(arg);
  }
}

template <typename value_type>
template <class... Args>
void list<value_type>::insert_many_front(Args&&... args) noexcept {
  for (const auto& arg : {args...}) {
    push_front(arg);
  }
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos.node_ == end_) {
    throw std::out_of_range("Can't delete end");
  }

  if (!empty()) {
    ListNode* current = pos.node_;
    current->prev_->next_ = current->next_;
    current->next_->prev_ = current->prev_;
    --count_;
    if (current == front_) {
      front_ = current->next_;
    } else if (current == back_) {
      back_ = current->prev_;
    }

    change_end();
    delete current;
  }
}

}  // namespace s21
