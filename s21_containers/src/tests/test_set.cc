#include <set>

#include "test_containers.h"

TEST(Set, Constructor1) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(Set, Constructor2) {
  s21::set<std::string> s21_set;
  std::set<std::string> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(Set, ParametrizedConstructor1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4, 4, 0});
  std::set<int> std_set({0, 1, 2, 3, 4, 4, 0});

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, ParametrizedConstructor2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4", "4", "0"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4", "4", "0"});

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, CopyConstructor1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  s21::set<int> s21_set_copy(s21_set);
  std::set<int> std_set_copy(std_set);

  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());

  auto s21_i = s21_set_copy.begin();
  auto std_i = std_set_copy.begin();
  for (size_t i = 0; i < s21_set_copy.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, CopyConstructor2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  s21::set<std::string> s21_set_copy(s21_set);
  std::set<std::string> std_set_copy(std_set);

  EXPECT_EQ(s21_set_copy.size(), std_set_copy.size());

  auto s21_i = s21_set_copy.begin();
  auto std_i = std_set_copy.begin();
  for (size_t i = 0; i < s21_set_copy.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, MoveConstructor1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  s21::set<int> s21_set_move(move(s21_set));
  std::set<int> std_set_move(move(std_set));

  EXPECT_EQ(s21_set_move.size(), std_set_move.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set_move.begin();
  auto std_i = std_set_move.begin();
  for (size_t i = 0; i < s21_set_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, MoveConstructor2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  s21::set<std::string> s21_set_move(move(s21_set));
  std::set<std::string> std_set_move(move(std_set));

  EXPECT_EQ(s21_set_move.size(), std_set_move.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set_move.begin();
  auto std_i = std_set_move.begin();
  for (size_t i = 0; i < s21_set_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, MoveAssingmentOperator1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  s21::set<int> s21_set_move = move(s21_set);
  std::set<int> std_set_move = move(std_set);

  EXPECT_EQ(s21_set_move.size(), std_set_move.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set_move.begin();
  auto std_i = std_set_move.begin();
  for (size_t i = 0; i < s21_set_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, MoveAssingmentOperator2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  s21::set<std::string> s21_set_move = move(s21_set);
  std::set<std::string> std_set_move = move(std_set);

  EXPECT_EQ(s21_set_move.size(), std_set_move.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set_move.begin();
  auto std_i = std_set_move.begin();
  for (size_t i = 0; i < s21_set_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Begin1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Set, Begin2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Set, End1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});

  auto s21_i = s21_set.end();
  auto std_i = std_set.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Set, End2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});

  auto s21_i = s21_set.end();
  auto std_i = std_set.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Set, Empty1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  EXPECT_EQ(s21_set.empty(), std_set.empty());

  s21::set<int> s21_empty_set;
  std::set<int> std_empty_set;
  EXPECT_EQ(s21_empty_set.empty(), std_empty_set.empty());
}

TEST(Set, Empty2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  EXPECT_EQ(s21_set.empty(), std_set.empty());

  s21::set<std::string> s21_empty_set;
  std::set<std::string> std_empty_set;
  EXPECT_EQ(s21_empty_set.empty(), std_empty_set.empty());
}

TEST(Set, Size1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21::set<int> s21_empty_set;
  std::set<int> std_empty_set;
  EXPECT_EQ(s21_empty_set.size(), std_empty_set.size());
}

TEST(Set, Size2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21::set<std::string> s21_empty_set;
  std::set<std::string> std_empty_set;
  EXPECT_EQ(s21_empty_set.size(), std_empty_set.size());
}

TEST(Set, MaxSize1) {
  s21::set<bool> s21_set;
  EXPECT_EQ(s21_set.max_size(),
            std::numeric_limits<s21::set<bool>::size_type>::max() /
                sizeof(s21::set<bool>::node_type) / 2);
}

TEST(Set, MaxSize2) {
  s21::set<int> s21_set;
  EXPECT_EQ(s21_set.max_size(),
            std::numeric_limits<s21::set<int>::size_type>::max() /
                sizeof(s21::set<int>::node_type) / 2);
}
TEST(Set, MaxSize3) {
  s21::set<std::string> s21_set;
  EXPECT_EQ(s21_set.max_size(),
            std::numeric_limits<s21::set<std::string>::size_type>::max() /
                sizeof(s21::set<std::string>::node_type) / 2);
}
TEST(Set, MaxSize4) {
  s21::set<double> s21_set;
  EXPECT_EQ(s21_set.max_size(),
            std::numeric_limits<s21::set<double>::size_type>::max() /
                sizeof(s21::set<double>::node_type) / 2);
}

TEST(Set, Clear1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(Set, Clear2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(Set, Insert1) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  auto s21_insert_res = s21_set.insert(0);
  auto std_insert_res = std_set.insert(0);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_set.insert(1);
  std_insert_res = std_set.insert(1);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_set.insert(1);
  std_insert_res = std_set.insert(1);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Insert2) {
  s21::set<std::string> s21_set;
  std::set<std::string> std_set;
  auto s21_insert_res = s21_set.insert("0");
  auto std_insert_res = std_set.insert("0");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_set.insert("1");
  std_insert_res = std_set.insert("1");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_set.insert("1");
  std_insert_res = std_set.insert("1");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, InsertMany1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});
  auto s21_res_vector = s21_set.insert_many(5, 6, 7, 8, 8);
  std::vector<std::pair<std::set<int>::iterator, bool>> std_res_vector;
  std_res_vector.push_back(std_set.insert(5));
  std_res_vector.push_back(std_set.insert(6));
  std_res_vector.push_back(std_set.insert(7));
  std_res_vector.push_back(std_set.insert(8));
  std_res_vector.push_back(std_set.insert(8));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); i++) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i].first);
    EXPECT_EQ(s21_res_vector[i].second, std_res_vector[i].second);
  }
}

TEST(Set, InsertMany2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  auto s21_res_vector = s21_set.insert_many("5", "6", "7", "8", "8");
  std::vector<std::pair<std::set<std::string>::iterator, bool>> std_res_vector;
  std_res_vector.push_back(std_set.insert("5"));
  std_res_vector.push_back(std_set.insert("6"));
  std_res_vector.push_back(std_set.insert("7"));
  std_res_vector.push_back(std_set.insert("8"));
  std_res_vector.push_back(std_set.insert("8"));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); i++) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i].first);
    EXPECT_EQ(s21_res_vector[i].second, std_res_vector[i].second);
  }
}

TEST(Set, Erase1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});

  s21_set.erase(s21_set.begin());
  std_set.erase(std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_set.erase(--s21_set.end());
  std_set.erase(--std_set.end());
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_i = s21_set.begin();
  std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Erase2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});

  s21_set.erase(s21_set.begin());
  std_set.erase(std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_set.erase(--s21_set.end());
  std_set.erase(--std_set.end());
  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_i = s21_set.begin();
  std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Swap1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  s21::set<int> s21_set_swap({5, 6, 7});
  std::set<int> std_set({0, 1, 2, 3, 4});
  std::set<int> std_set_swap({5, 6, 7});

  s21_set.swap(s21_set_swap);
  std_set.swap(std_set_swap);

  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_swap.size(), std_set_swap.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_set_swap.begin();
  auto std_i_swap = std_set_swap.begin();
  for (size_t i = 0; i < s21_set_swap.size(); i++) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Set, Swap2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  s21::set<std::string> s21_set_swap({"5", "6", "7"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set_swap({"5", "6", "7"});

  s21_set.swap(s21_set_swap);
  std_set.swap(std_set_swap);

  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_swap.size(), std_set_swap.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_set_swap.begin();
  auto std_i_swap = std_set_swap.begin();
  for (size_t i = 0; i < s21_set_swap.size(); i++) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Set, Merge1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  s21::set<int> s21_set_merge({5, 6, 7});
  std::set<int> std_set({0, 1, 2, 3, 4});
  std::set<int> std_set_merge({5, 6, 7});

  s21_set.merge(s21_set_merge);
  std_set.merge(std_set_merge);

  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_merge.size(), std_set_merge.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Merge2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  s21::set<std::string> s21_set_merge({"5", "6", "7"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set_merge({"5", "6", "7"});

  s21_set.merge(s21_set_merge);
  std_set.merge(std_set_merge);

  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(s21_set_merge.size(), std_set_merge.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Set, Find1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});
  std::set<int> std_set({0, 1, 2, 3, 4});

  EXPECT_EQ(*s21_set.find(1), *std_set.find(1));
  EXPECT_EQ(*s21_set.find(3), *std_set.find(3));
  EXPECT_EQ(s21_set.find(7), s21_set.end());
  EXPECT_EQ(std_set.find(7), std_set.end());
}

TEST(Set, Find2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});
  std::set<std::string> std_set({"0", "1", "2", "3", "4"});

  EXPECT_EQ(*s21_set.find("1"), *std_set.find("1"));
  EXPECT_EQ(*s21_set.find("3"), *std_set.find("3"));
  EXPECT_EQ(s21_set.find("7"), s21_set.end());
  EXPECT_EQ(std_set.find("7"), std_set.end());
}

TEST(Set, Contains1) {
  s21::set<int> s21_set({0, 1, 2, 3, 4});

  EXPECT_EQ(s21_set.contains(-1), false);
  EXPECT_EQ(s21_set.contains(0), true);
  EXPECT_EQ(s21_set.contains(1), true);
  EXPECT_EQ(s21_set.contains(2), true);
  EXPECT_EQ(s21_set.contains(3), true);
  EXPECT_EQ(s21_set.contains(4), true);
  EXPECT_EQ(s21_set.contains(5), false);
}

TEST(Set, Contains2) {
  s21::set<std::string> s21_set({"0", "1", "2", "3", "4"});

  EXPECT_EQ(s21_set.contains("-1"), false);
  EXPECT_EQ(s21_set.contains("0"), true);
  EXPECT_EQ(s21_set.contains("1"), true);
  EXPECT_EQ(s21_set.contains("2"), true);
  EXPECT_EQ(s21_set.contains("3"), true);
  EXPECT_EQ(s21_set.contains("4"), true);
  EXPECT_EQ(s21_set.contains("5"), false);
}

TEST(Set, OperatorLessUsage) {
  s21::set<SomeClass> s21_set({SomeClass(3, 3), SomeClass(1, 1),
                               SomeClass(0, 0), SomeClass(2, 2),
                               SomeClass(2, 2)});
  std::set<SomeClass> std_set({SomeClass(3, 3), SomeClass(1, 1),
                               SomeClass(0, 0), SomeClass(2, 2),
                               SomeClass(2, 2)});

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(**s21_i++, **std_i++);
  }
}

TEST(Set, FunctorUsage) {
  s21::set<SomeClass, Functor> s21_set({SomeClass(3, 3), SomeClass(1, 1),
                                        SomeClass(0, 0), SomeClass(2, 2),
                                        SomeClass(2, 2)});
  std::set<SomeClass, Functor> std_set({SomeClass(3, 3), SomeClass(1, 1),
                                        SomeClass(0, 0), SomeClass(2, 2),
                                        SomeClass(2, 2)});

  auto s21_i = s21_set.begin();
  auto std_i = std_set.begin();
  for (size_t i = 0; i < s21_set.size(); i++) {
    EXPECT_EQ(**s21_i++, **std_i++);
  }
}
