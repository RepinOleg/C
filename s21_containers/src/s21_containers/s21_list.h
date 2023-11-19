#ifndef S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_
#define S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_

#include <cstddef>
#include <iostream>
#include <limits>
namespace s21 {
template <typename T>
class list {
 public:
  /* переопределения типов */
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  /* Конструкторы */
  list();
  explicit list(size_type n) noexcept;
  explicit list(std::initializer_list<value_type> const &items);
  list(const list &other);
  list(list &&other) noexcept;
  ~list();

  /* присваивание */
  list &operator=(const list &other);
  list &operator=(list &&other) noexcept;

  /* pop */
  void pop_back();
  void pop_front();

  /* push */
  void push_back(const_reference value) noexcept;
  void push_front(const_reference value) noexcept;

  /* take const value */
  const_reference front() const noexcept;
  const_reference back() const noexcept;

  /* Методы изменяющие список */
  void clear();
  void reverse() noexcept;
  void unique() noexcept;
  void sort() noexcept;
  void swap(list &other) noexcept;
  void merge(list &other) noexcept;

  /* List Capacity */
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  /* Структура со значением и указателями */
 protected:
  struct ListNode {
    ListNode *prev_;
    ListNode *next_;
    value_type data_;
  };

  /* Указатели на первую, последнюю и end структуры */
  ListNode *front_ = nullptr;
  ListNode *back_ = nullptr;
  ListNode *end_ = nullptr;
  /* Количество элементов в списке */
  size_type count_ = 0;

 public:
  class ListIterator {
    friend class list<value_type>;

   public:
    ListIterator() noexcept : node_(nullptr) {}
    ListIterator(ListNode *other) noexcept : node_(other) {}

    reference operator*() const noexcept;
    ListIterator &operator++() noexcept;
    ListIterator operator++(int) noexcept;
    ListIterator &operator--() noexcept;
    ListIterator operator--(int) noexcept;

    bool operator==(const ListIterator &other) const noexcept;
    bool operator!=(const ListIterator &other) const noexcept;

   private:
    ListNode *node_ = nullptr;
  };

  class ListConstIterator {
    friend class list<value_type>;

   public:
    ListConstIterator() : node_(nullptr) {}
    ListConstIterator(const ListNode *other) : node_(other) {}
    ListConstIterator(const ListIterator &other) : node_(other.node_) {}

    const_reference operator*() const noexcept;

    ListConstIterator &operator++() noexcept;
    ListConstIterator operator++(int) noexcept;
    ListConstIterator &operator--() noexcept;
    ListConstIterator operator--(int) noexcept;

    bool operator==(const ListConstIterator &other) const noexcept;
    bool operator!=(const ListConstIterator &other) const noexcept;

   private:
    const ListNode *node_ = nullptr;
  };

  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  /* iterators */
  iterator begin() const noexcept;
  iterator end() const noexcept;
  iterator insert(iterator pos, const_reference value) noexcept;
  void erase(iterator pos);

  /* const_iterators */
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;
  void splice(const_iterator pos, list &other) noexcept;

  /* bonus part*/
  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args) noexcept;
  template <class... Args>
  void insert_many_front(Args &&...args) noexcept;

 private:
  void quick_sort(iterator start, iterator end) noexcept;
  iterator partition(iterator start, iterator end) noexcept;
  void change_end() noexcept;
};
}  // namespace s21
#include "s21_list.inc"
#endif  // S21_CONTAINERS_S21_CONTAINERS_S21_LIST_H_
