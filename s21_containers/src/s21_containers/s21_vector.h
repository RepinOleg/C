#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_H_

#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  class VectorIterator;
  class VectorConstIterator;
  // Переопределения типов:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = vector<T>::VectorIterator;
  using const_iterator = vector<T>::VectorConstIterator;
  using size_type = std::size_t;
  // Конструкторы:
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &other);
  vector(vector &&other) noexcept;
  // Перегрузка операторов:
  vector &operator=(const vector &other);
  vector &operator=(vector &&other) noexcept;
  // Деструктор:
  ~vector();
  // Доступ к элементам класса:
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  // Итераторы:
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  // Методы для доступа к информации о наполнении контейнера:
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit();
  // Методы для изменения контейнера:
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos) noexcept;
  void push_back(const_reference value);
  void pop_back() noexcept;
  void swap(vector &other) noexcept;
  // Вставка нескольких элементов:
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  value_type *data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace s21

#include "s21_vector.inc"
#include "s21_vector_iterator.h"

#endif  //  CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_H_
