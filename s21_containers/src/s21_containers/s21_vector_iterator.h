#ifndef CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_ITERATOR_H_
#define CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_ITERATOR_H_

namespace s21 {

template <typename T>
class vector<T>::VectorIterator {
 public:
  // Конструкторы:
  VectorIterator() noexcept;
  VectorIterator(value_type *ptr) noexcept;
  // Перегрузка операторов:
  reference operator*() noexcept;
  VectorIterator operator++(int) noexcept;
  VectorIterator operator--(int) noexcept;
  VectorIterator &operator++() noexcept;
  VectorIterator &operator--() noexcept;
  bool operator==(const VectorIterator &other) const noexcept;
  bool operator!=(const VectorIterator &other) const noexcept;
  VectorIterator operator+(int n) const noexcept;
  VectorIterator operator-(int n) const noexcept;
  ptrdiff_t operator-(const VectorIterator &other) const noexcept;

 private:
  value_type *ptr_;
};

template <typename T>
class vector<T>::VectorConstIterator {
 public:
  // Конструкторы:
  VectorConstIterator() noexcept;
  VectorConstIterator(const value_type *ptr) noexcept;
  // Перегрузка операторов:
  const_reference operator*() const noexcept;
  VectorConstIterator operator++(int) noexcept;
  VectorConstIterator operator--(int) noexcept;
  VectorConstIterator &operator++() noexcept;
  VectorConstIterator &operator--() noexcept;
  bool operator==(const VectorConstIterator &other) const noexcept;
  bool operator!=(const VectorConstIterator &other) const noexcept;
  VectorConstIterator operator+(int n) const noexcept;
  VectorConstIterator operator-(int n) const noexcept;
  ptrdiff_t operator-(const VectorConstIterator &other) const noexcept;

 private:
  const value_type *ptr_;
};

}  // namespace s21

#include "s21_vector_iterator.inc"

#endif  //  CPP_S21_CONTAINERS_1_S21_CONTAINERS_S21_VECTOR_ITERATOR_H_
