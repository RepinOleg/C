#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERS_STACK_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERS_STACK_H_

#include <iostream>

#include "s21_deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class stack {
 public:
  // Переопределения типов:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  // Конструкторы:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &other);
  stack(stack &&other) noexcept;
  // Перегрузка операторов:
  stack &operator=(const stack &other);
  stack &operator=(stack &&other) noexcept;
  // Деструктор:
  ~stack();
  // Доступ к элементам класса:
  const_reference top() const noexcept;
  // Методы для доступа к информации о наполнении контейнера:
  bool empty() const noexcept;
  size_type size() const noexcept;
  // Методы для изменения контейнера:
  void push(const_reference value) noexcept;
  void pop() noexcept;
  void swap(stack &other) noexcept;
  // Бонусный метод вставки нескольких элементов:
  template <class... Args>
  void insert_many_front(Args &&...args) noexcept;

 private:
  Container deque_;
};
}  // namespace s21

#include "s21_stack.inc"

#endif  // CPP_S21_CONTAINERS_1_S21_CONTAINERS_STACK_H_
