#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERS_QUEUE_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERS_QUEUE_H_

#include <iostream>

#include "s21_deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class queue {
 public:
  // Переопределения типов:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  // Конструкторы:
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &other);
  queue(queue &&other) noexcept;
  // Перегрузка операторов:
  queue &operator=(const queue &other);
  queue &operator=(queue &&other) noexcept;
  // Деструктор:
  ~queue();
  // Доступ к элементам класса:
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  // Методы для доступа к информации о наполнении контейнера:
  bool empty() const noexcept;
  size_type size() const noexcept;
  // Методы для изменения контейнера:
  void push(const_reference value) noexcept;
  void pop() noexcept;
  void swap(queue &other) noexcept;
  // Бонусный метод вставки нескольких элементов:
  template <class... Args>
  void insert_many_back(Args &&...args) noexcept;

 private:
  Container deque_;
};

}  // namespace s21

#include "s21_queue.inc"

#endif  // CPP_S21_CONTAINERS_1_S21_CONTAINERS_QUEUE_H_
