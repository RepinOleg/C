#ifndef CPP2_S21_CONTAINERS_1_TESTS_TEST_CONTAINERS_H_
#define CPP2_S21_CONTAINERS_1_TESTS_TEST_CONTAINERS_H_
#include <gtest/gtest.h>

#include "../s21_containers/s21_containers.h"
#include "../s21_containersplus/s21_containersplus.h"

class SomeClass {
 public:
  int x_;
  int y_;
  SomeClass() : x_(0), y_(0) {}
  SomeClass(int x, int y) : x_(x), y_(y) {}
  bool operator<(const SomeClass& b) const noexcept {
    return x_ * 10 + y_ < b.x_ * 10 + b.y_;
  }
  int operator*() const noexcept { return x_ * 10 + y_; }
};

class Functor {
 public:
  bool operator()(const SomeClass& a, const SomeClass& b) const noexcept {
    return a.x_ * 10 + a.y_ > b.x_ * 10 + b.y_;
  }
};

#endif  // CPP2_S21_CONTAINERS_1_TESTS_TEST_CONTAINERS_H_
