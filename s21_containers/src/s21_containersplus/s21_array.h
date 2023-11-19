#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERSPLUS_S21_ARRAY_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERSPLUS_S21_ARRAY_H_

#include <iostream>
#include <stdexcept>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  // Переопределения типов:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;
  // Конструкторы:
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other) noexcept;
  // Перегрузка операторов:
  array &operator=(const array &other);
  array &operator=(array &&other) noexcept;
  // Деструктор:
  ~array();
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  // Методы итерирования:
  iterator begin() noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator cend() const noexcept;
  // Доступ к элементам класса:
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  const_reference front() const noexcept;
  const_reference back() const;
  iterator data() noexcept;
  // Методы для доступа к информации о наполнении контейнера:
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  // Методы для изменения контейнера:
  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  value_type elems_[N] = {};
  size_type size_ = N;
};
}  // namespace s21

#include "s21_array.inc"

#endif  // CPP_S21_CONTAINERS_1_S21_CONTAINERSPLUS_S21_ARRAY_H_
