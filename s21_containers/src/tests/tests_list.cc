#include <list>

#include "test_containers.h"

TEST(ListTests, ConstructTest) {
  s21::list<int> my;
  std::list<int> other;
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);
}

TEST(ListTests, ConstructTest2) {
  s21::list<int> my(1);
  std::list<int> other(1);
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);
  ++it_other;
  ++it_my;
  EXPECT_EQ(*it_other, *it_my);
}

TEST(ListTests, ConstructTest3) {
  s21::list<int> my(0);
  std::list<int> other(0);
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);
  ++it_other;
  ++it_my;
  EXPECT_EQ(*it_other, *it_my);
}

TEST(ListTests, ConstructTest4) {
  s21::list<int> my(100);
  std::list<int> other(100);
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);
  ++it_other;
  ++it_my;
  EXPECT_EQ(*it_other, *it_my);
}

TEST(ListTests, ConstructTest5) {
  s21::list<int> my{100};
  std::list<int> other{100};
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);
  ++it_other;
  ++it_my;
  EXPECT_EQ(*it_other, *it_my);
}

TEST(ListTests, ConstructTest6) {
  s21::list<int> my{-3, 4, 5, 6};
  std::list<int> other{-3, 4, 5, 6};
  std::list<int>::iterator it_other = other.begin();
  s21::list<int>::iterator it_my = my.begin();

  EXPECT_EQ(my.max_size(), other.max_size());
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(*it_other, *it_my);

  std::list<int>::iterator it_other2 = other.end();
  s21::list<int>::iterator it_my2 = my.end();
  EXPECT_EQ(*it_other2, *it_my2);
}

TEST(ListTests, ConstructTest7) {
  s21::list<bool> my(5);
  std::list<bool> other(5);
  std::list<bool>::iterator it_other = other.begin();
  s21::list<bool>::iterator it_my = my.begin();

  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(my.max_size(), other.max_size());
  EXPECT_FALSE(*it_other);
  EXPECT_FALSE(*it_my);

  std::list<bool>::iterator it_other2 = other.end();
  s21::list<bool>::iterator it_my2 = my.end();
  EXPECT_TRUE(*it_my2);
  EXPECT_TRUE(*it_other2);
}

TEST(ListTests, ConstructTest8) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  s21::list<int>::iterator my_it1 = my.begin();
  std::list<int>::iterator other_it1 = other.begin();

  s21::list<int> my2(my);
  std::list<int> other2(other);

  while (other_it1 != other.end()) {
    EXPECT_EQ(*my_it1++, *other_it1++);
  }

  s21::list<int>::iterator my_it = my2.begin();
  std::list<int>::iterator other_it = other2.begin();

  EXPECT_EQ(my2.size(), other2.size());
  while (other_it != other2.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, ConstructTest9) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  s21::list<int> my2(std::move(my));
  std::list<int> other2(std::move(other));

  s21::list<int>::iterator my_it = my2.begin();
  std::list<int>::iterator other_it = other2.begin();

  EXPECT_EQ(my2.size(), other2.size());
  while (other_it != other2.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, OperatorEqualTest1) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  s21::list<int> my2;
  std::list<int> other2;

  my2 = my;
  other2 = other;

  s21::list<int>::iterator my_it = my2.begin();
  std::list<int>::iterator other_it = other2.begin();

  EXPECT_EQ(my2.size(), other2.size());
  while (other_it != other2.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, OperatorEqualTest2) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  s21::list<int> my2;
  std::list<int> other2;
  my2 = std::move(my);
  other2 = std::move(other);

  s21::list<int>::iterator my_it = my2.begin();
  std::list<int>::iterator other_it = other2.begin();

  EXPECT_EQ(my2.size(), other2.size());
  while (other_it != other2.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, PushBack) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  my.push_back(5);
  other.push_back(5);
  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, PushFront) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  my.push_front(5);
  other.push_front(5);
  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, PushFront2) {
  s21::list<int> my;
  std::list<int> other;

  my.push_front(5);
  other.push_front(5);
  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, PushFront3) {
  s21::list<std::string> my;
  std::list<std::string> other;

  my.push_front("HI");
  other.push_front("HI");
  std::list<std::string>::iterator other_it = other.begin();
  s21::list<std::string>::iterator my_it = my.begin();
  EXPECT_EQ(my.max_size(), other.max_size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, FrontValue1) {
  s21::list<int> my;
  std::list<int> other;

  EXPECT_EQ(my.front(), other.front());

  s21::list<bool> my2;
  std::list<bool> other2;

  EXPECT_EQ(my2.front(), other2.front());
}

TEST(ListTests, FrontValue2) {
  s21::list<int> my{-50};
  std::list<int> other{-50};

  EXPECT_EQ(my.front(), other.front());

  s21::list<bool> my2{true};
  std::list<bool> other2{true};

  EXPECT_EQ(my2.front(), other2.front());
}

TEST(ListTests, BackValue1) {
  s21::list<int> my;
  std::list<int> other;

  EXPECT_EQ(my.back(), other.back());

  s21::list<bool> my2;
  std::list<bool> other2;

  EXPECT_EQ(my2.back(), other2.back());
}

TEST(ListTests, BackValue2) {
  s21::list<int> my{15, 16};
  std::list<int> other{15, 16};

  EXPECT_EQ(my.back(), other.back());

  s21::list<bool> my2{true, false};
  std::list<bool> other2{true, false};

  EXPECT_EQ(my2.back(), other2.back());
}

TEST(ListTests, Clear) {
  s21::list<int> my{1, 2, 3, 4};
  std::list<int> other{1, 2, 3, 4};

  my.clear();
  other.clear();
  EXPECT_EQ(my.front(), 0);
  EXPECT_EQ(other.front(), 0);
}

TEST(ListTests, PopBack1) {
  s21::list<int> my;
  EXPECT_ANY_THROW(my.pop_back());
}

TEST(ListTests, PopFront1) {
  s21::list<int> my{1, 2, 3};
  std::list<int> other{1, 2, 3};
  my.pop_front();
  other.pop_front();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, PopFront2) {
  s21::list<int> my;
  EXPECT_ANY_THROW(my.pop_front());
}

TEST(ListTests, PopFront3) {
  s21::list<int> my{1};
  std::list<int> other{1};
  my.pop_front();
  other.pop_front();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(other_it, other.end());
  EXPECT_EQ(my_it, my.end());
}

TEST(ListTests, Reverse) {
  s21::list<int> my{1};
  std::list<int> other{1};
  my.reverse();
  other.reverse();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Reverse2) {
  s21::list<int> my{1, 6, 7, 2, 3};
  std::list<int> other{1, 6, 7, 2, 3};
  my.reverse();
  other.reverse();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Unique1) {
  s21::list<int> my{1, 6, 7, 2, 3};
  std::list<int> other{1, 6, 7, 2, 3};
  my.unique();
  other.unique();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Unique2) {
  s21::list<int> my{1, 1, 1, 2, 3};
  std::list<int> other{1, 1, 1, 2, 3};
  my.unique();
  other.unique();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Unique3) {
  s21::list<int> my{1, 2, 1, 2, 2};
  std::list<int> other{1, 2, 1, 2, 2};
  my.unique();
  other.unique();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Unique4) {
  s21::list<int> my{1};
  std::list<int> other{1};
  my.unique();
  other.unique();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Unique5) {
  s21::list<int> my;
  std::list<int> other;
  my.unique();
  other.unique();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(other_it, other.end());
  EXPECT_EQ(my_it, my.end());
}

TEST(ListTests, Sort1) {
  s21::list<int> my{1, 2, 3, 4, 5};
  std::list<int> other{1, 2, 3, 4, 5};
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Sort2) {
  s21::list<int> my{6, 5, 3, 4, 5};
  std::list<int> other{6, 5, 3, 4, 5};
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Sort3) {
  s21::list<int> my{1, 1, 1, 1, 1};
  std::list<int> other{1, 1, 1, 1, 1};
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Sort4) {
  s21::list<int> my{0};
  std::list<int> other{0};
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Sort5) {
  s21::list<int> my;
  std::list<int> other;
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  EXPECT_EQ(other_it, other.end());
  EXPECT_EQ(my_it, my.end());
}

TEST(ListTests, Sort6) {
  s21::list<std::string> my{"jucie", "apple", "banana"};
  std::list<std::string> other{"jucie", "apple", "banana"};
  my.sort();
  other.sort();

  std::list<std::string>::iterator other_it = other.begin();
  s21::list<std::string>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Sort7) {
  s21::list<int> my{1,  1,   1, 1, 1, 1,  1, 1, 1,  1, 2,    3,
                    -5, 100, 6, 2, 5, 32, 3, 0, -1, 0, 5555, 10000000};
  std::list<int> other{1,  1,   1, 1, 1, 1,  1, 1, 1,  1, 2,    3,
                       -5, 100, 6, 2, 5, 32, 3, 0, -1, 0, 5555, 10000000};
  my.sort();
  other.sort();

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge1) {
  s21::list<int> my{1, 2, 3};
  s21::list<int> my2{1, 2, 3};
  std::list<int> other{1, 2, 3};
  std::list<int> other2{1, 2, 3};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge2) {
  s21::list<int> my;
  s21::list<int> my2{1, 2, 3};
  std::list<int> other;
  std::list<int> other2{1, 2, 3};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge3) {
  s21::list<int> my{8, 7, 6};
  s21::list<int> my2{3, 2, 1};
  std::list<int> other{8, 7, 6};
  std::list<int> other2{3, 2, 1};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge4) {
  s21::list<int> my{0};
  s21::list<int> my2{1, 2, 3};
  std::list<int> other{0};
  std::list<int> other2{1, 2, 3};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge5) {
  s21::list<int> my{0};
  s21::list<int> my2{-1, -2, -3};
  std::list<int> other{0};
  std::list<int> other2{-1, -2, -3};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListTests, Merge6) {
  s21::list<int> my{0};
  s21::list<int> my2{0};
  std::list<int> other{0};
  std::list<int> other2{0};
  my.merge(my2);
  other.merge(other2);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  EXPECT_EQ(my.size(), other.size());
  while (other_it != other.end()) {
    EXPECT_EQ(*my_it++, *other_it++);
  }
}

TEST(ListIteratorTests, OperatorMinusMinus) {
  s21::list<int> my;
  std::list<int> other;
  s21::list<int>::iterator my_it = my.end();
  std::list<int>::iterator other_it = other.end();
  EXPECT_EQ(*my_it--, *other_it--);
}

TEST(ListIteratorTests, OperatorMinusMinus2) {
  s21::list<int> my;
  std::list<int> other;
  s21::list<int>::iterator my_it = my.end();
  std::list<int>::iterator other_it = other.end();
  EXPECT_EQ(*--my_it, *--other_it);
}

TEST(ListConstIteratorTests, OperatorPlusPlus1) {
  s21::list<int> my;
  std::list<int> other;
  s21::list<int>::const_iterator my_it = my.end();
  std::list<int>::const_iterator other_it = other.end();
  EXPECT_EQ(*my_it, *other_it);
  ++my_it;
  ++other_it;
  EXPECT_EQ(*my_it, *other_it);
}

TEST(ListConstIteratorTests, OperatorPLusPlus2) {
  s21::list<int> my{1, 2, 3};
  std::list<int> other{1, 2, 3};
  s21::list<int>::const_iterator my_it = my.cbegin();
  std::list<int>::const_iterator other_it = other.cbegin();
  EXPECT_EQ(*my_it, *other_it);
  ++my_it;
  ++other_it;
  EXPECT_EQ(*my_it, *other_it);
}

TEST(ListConstIteratorTests, OperatorMinusMinus3) {
  s21::list<int> my{1, 2, 3};
  std::list<int> other{1, 2, 3};
  s21::list<int>::const_iterator my_it = my.cend();
  std::list<int>::const_iterator other_it = other.cend();
  EXPECT_EQ(*my_it, *other_it);
  --my_it;
  --other_it;
  EXPECT_EQ(*--my_it, *--other_it);
}

TEST(ListConstIteratorTests, OperatorMinusMinus4) {
  s21::list<int> my{1, 2, 3};
  std::list<int> other{1, 2, 3};
  s21::list<int>::const_iterator my_it = my.cend();
  std::list<int>::const_iterator other_it = other.cend();
  EXPECT_EQ(*my_it, *other_it);
  --my_it;
  --other_it;
  EXPECT_EQ(*--my_it, *--other_it);
}

TEST(ListConstIteratorTests, OperatorEqual) {
  s21::list<int> my{1, 2, 3};
  s21::list<int>::const_iterator my_it = my.cbegin();
  s21::list<int>::const_iterator my_it2 = my.cbegin();

  EXPECT_TRUE(my_it == my_it2);
}

TEST(ListConstIteratorTests, NotEqual) {
  s21::list<int> my{1, 2, 3};
  s21::list<int>::const_iterator my_it = my.cbegin();
  s21::list<int>::const_iterator my_it2 = my.cbegin();

  EXPECT_FALSE(my_it != my_it2);
}

TEST(ListTests, Erase) {
  s21::list<int> my{1, 2};
  std::list<int> other{1, 2};

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  ++other_it;
  ++my_it;
  my.erase(my_it);
  other.erase(other_it);
  EXPECT_EQ(my.size(), other.size());

  std::list<int>::iterator other_test = other.begin();
  s21::list<int>::iterator my_test = my.begin();
  while (other_test != other.end()) {
    EXPECT_EQ(*my_test++, *other_test++);
  }
}

TEST(ListTests, Erase2) {
  s21::list<int> my{1};
  std::list<int> other{1};

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  my.erase(my_it);
  other.erase(other_it);
  EXPECT_EQ(my.size(), other.size());

  std::list<int>::iterator other_test = other.begin();
  s21::list<int>::iterator my_test = my.begin();
  EXPECT_EQ(other_test, other.end());
  EXPECT_EQ(my_test, my.end());
}

TEST(ListTests, Erase3) {
  s21::list<int> my{1};
  s21::list<int>::iterator my_it = my.end();
  EXPECT_ANY_THROW(my.erase(my_it));
}

TEST(ListTests, Erase4) {
  s21::list<int> my(10);
  std::list<int> other(10);

  std::list<int>::iterator other_it = other.begin();
  s21::list<int>::iterator my_it = my.begin();
  my.erase(my_it);
  other.erase(other_it);
  EXPECT_EQ(my.size(), other.size());

  std::list<int>::iterator other_test = other.begin();
  s21::list<int>::iterator my_test = my.begin();
  while (other_test != other.end()) {
    EXPECT_EQ(*my_test++, *other_test++);
  }
}

TEST(ListTests, Erase5) {
  s21::list<int> my{5, 4, 3, 2, 1};
  std::list<int> other{5, 4, 3, 2, 1};

  std::list<int>::iterator other_it = other.end();
  s21::list<int>::iterator my_it = my.end();
  --other_it;
  --my_it;
  my.erase(my_it);
  other.erase(other_it);
  EXPECT_EQ(my.size(), other.size());

  std::list<int>::iterator other_test = other.begin();
  s21::list<int>::iterator my_test = my.begin();
  while (other_test != other.end()) {
    EXPECT_EQ(*my_test++, *other_test++);
  }
}

TEST(ListBonusPart, InsertManyBack) {
  s21::list<std::string> myList{"Hi", "Apple"};
  myList.insert_many_back("Loco", "Poco");
  s21::list<std::string>::const_iterator my_it = myList.cend();
  --my_it;
  EXPECT_EQ(*my_it, "Poco");
  --my_it;
  EXPECT_EQ(*my_it, "Loco");
}

TEST(ListBonusPart, InsertManyBack2) {
  s21::list<std::string> myList;
  myList.insert_many_back("Loco", "Poco");
  s21::list<std::string>::const_iterator my_it = myList.cend();
  --my_it;
  EXPECT_EQ(*my_it, "Poco");
  --my_it;
  EXPECT_EQ(*my_it, "Loco");
}

TEST(ListBonusPart, InsertManyFront1) {
  s21::list<std::string> myList;
  myList.insert_many_front("Loco", "Poco");
  s21::list<std::string>::const_iterator my_it = myList.cbegin();
  EXPECT_EQ(*my_it, "Poco");
  ++my_it;
  EXPECT_EQ(*my_it, "Loco");
}

TEST(ListBonusPart, InsertManyFront2) {
  s21::list<int> myList{1, 2, 3};
  myList.insert_many_front(100, 101);
  s21::list<int>::const_iterator my_it = myList.cbegin();
  EXPECT_EQ(*my_it, 101);
  ++my_it;
  EXPECT_EQ(*my_it, 100);
  ++my_it;
  EXPECT_EQ(*my_it, 1);
  ++my_it;
  EXPECT_EQ(*my_it, 2);
  ++my_it;
  EXPECT_EQ(*my_it, 3);
  EXPECT_EQ(myList.size(), 5);
}

TEST(ListBonusPart, InsertMany1) {
  s21::list<int> myList{1, 2, 3};
  s21::list<int>::const_iterator my_it = myList.cbegin();
  myList.insert_many(my_it, 100, 101);
  s21::list<int>::const_iterator test_it = myList.cbegin();
  EXPECT_EQ(*test_it, 100);
  ++test_it;
  EXPECT_EQ(*test_it, 101);
  ++test_it;
  EXPECT_EQ(*test_it, 1);
  ++test_it;
  EXPECT_EQ(*test_it, 2);
  ++test_it;
  EXPECT_EQ(*test_it, 3);
  EXPECT_EQ(myList.size(), 5);
}
