#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_DEQUE_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_DEQUE_H_

#include <iostream>
#include <utility>

namespace s21 {

template <class T>
class deque {
 public:
  // Переопределения типов:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  // Конструкторы:
  deque();
  deque(std::initializer_list<value_type> const &items);
  deque(const deque &other);
  deque(deque &&other) noexcept;
  // Перегрузка операторов:
  deque &operator=(const deque &other);
  deque &operator=(deque &&other) noexcept;
  // Деструктор:
  ~deque();
  // Доступ к элементам класса:
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  // Методы для доступа к информации о наполнении контейнера:
  bool empty() const noexcept;
  size_type size() const noexcept;
  // Методы для изменения контейнера:
  void clear() noexcept;
  void swap(deque &other) noexcept;
  void push_back(const_reference value) noexcept;
  void pop_back() noexcept;
  void push_front(const_reference value) noexcept;
  void pop_front() noexcept;

 protected:
  struct Node {
    value_type value;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(const value_type &val = value_type(), Node *next_node = nullptr,
         Node *prev_node = nullptr)
        : value(val), next(next_node), prev(prev_node) {}
  };
  struct LinkedList {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };
  LinkedList list_;
};

}  // namespace s21

#include "s21_deque.inc"

#endif  // CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_DEQUE_H_
