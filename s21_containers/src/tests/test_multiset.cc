#include <set>

#include "test_containers.h"

TEST(Multiset, Constructor1) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(Multiset, Constructor2) {
  s21::multiset<std::string> s21_multiset;
  std::multiset<std::string> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(Multiset, ParametrizedConstructor1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4, 4, 0});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4, 4, 0});

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  std::multiset<int> std_multiset2({1, 0, 0, 0, 0, 0});
  s21::multiset<int> s21_multiset2({1, 0, 0, 0, 0, 0});

  EXPECT_EQ(s21_multiset2.size(), std_multiset2.size());

  s21_i = s21_multiset2.begin();
  std_i = std_multiset2.begin();
  for (size_t i = 0; i < s21_multiset2.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, ParametrizedConstructor2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4", "4", "0"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4", "4", "0"});

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  std::multiset<std::string> std_multiset2({"1", "0", "0", "0", "0", "0"});
  s21::multiset<std::string> s21_multiset2({"1", "0", "0", "0", "0", "0"});

  EXPECT_EQ(s21_multiset2.size(), std_multiset2.size());

  s21_i = s21_multiset2.begin();
  std_i = std_multiset2.begin();
  for (size_t i = 0; i < s21_multiset2.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, CopyConstructor1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  s21::multiset<int> s21_multiset_copy(s21_multiset);
  std::multiset<int> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());

  auto s21_i = s21_multiset_copy.begin();
  auto std_i = std_multiset_copy.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, CopyConstructor2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  s21::multiset<std::string> s21_multiset_copy(s21_multiset);
  std::multiset<std::string> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());

  auto s21_i = s21_multiset_copy.begin();
  auto std_i = std_multiset_copy.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, MoveConstructor1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  s21::multiset<int> s21_multiset_move(move(s21_multiset));
  std::multiset<int> std_multiset_move(move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset_move.begin();
  auto std_i = std_multiset_move.begin();
  for (size_t i = 0; i < s21_multiset_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, MoveConstructor2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  s21::multiset<std::string> s21_multiset_move(move(s21_multiset));
  std::multiset<std::string> std_multiset_move(move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset_move.begin();
  auto std_i = std_multiset_move.begin();
  for (size_t i = 0; i < s21_multiset_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, MoveAssingmentOperator1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  s21::multiset<int> s21_multiset_move = move(s21_multiset);
  std::multiset<int> std_multiset_move = move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset_move.begin();
  auto std_i = std_multiset_move.begin();
  for (size_t i = 0; i < s21_multiset_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, MoveAssingmentOperator2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  s21::multiset<std::string> s21_multiset_move = move(s21_multiset);
  std::multiset<std::string> std_multiset_move = move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset_move.begin();
  auto std_i = std_multiset_move.begin();
  for (size_t i = 0; i < s21_multiset_move.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Begin1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Multiset, Begin2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Multiset, End1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});

  auto s21_i = s21_multiset.end();
  auto std_i = std_multiset.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Multiset, End2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});

  auto s21_i = s21_multiset.end();
  auto std_i = std_multiset.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Multiset, Empty1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21::multiset<int> s21_empty_multiset;
  std::multiset<int> std_empty_multiset;
  EXPECT_EQ(s21_empty_multiset.empty(), std_empty_multiset.empty());
}

TEST(Multiset, Empty2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21::multiset<std::string> s21_empty_multiset;
  std::multiset<std::string> std_empty_multiset;
  EXPECT_EQ(s21_empty_multiset.empty(), std_empty_multiset.empty());
}

TEST(Multiset, Size1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  s21::multiset<int> s21_empty_multiset;
  std::multiset<int> std_empty_multiset;
  EXPECT_EQ(s21_empty_multiset.size(), std_empty_multiset.size());
}

TEST(Multiset, Size2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  s21::multiset<std::string> s21_empty_multiset;
  std::multiset<std::string> std_empty_multiset;
  EXPECT_EQ(s21_empty_multiset.size(), std_empty_multiset.size());
}

TEST(Multiset, MaxSize1) {
  s21::multiset<bool> s21_multiset;
  EXPECT_EQ(s21_multiset.max_size(),
            std::numeric_limits<s21::multiset<bool>::size_type>::max() /
                sizeof(s21::multiset<bool>::node_type) / 2);
}

TEST(Multiset, MaxSize2) {
  s21::multiset<int> s21_multiset;
  EXPECT_EQ(s21_multiset.max_size(),
            std::numeric_limits<s21::multiset<int>::size_type>::max() /
                sizeof(s21::multiset<int>::node_type) / 2);
}
TEST(Multiset, MaxSize3) {
  s21::multiset<std::string> s21_multiset;
  EXPECT_EQ(s21_multiset.max_size(),
            std::numeric_limits<s21::multiset<std::string>::size_type>::max() /
                sizeof(s21::multiset<std::string>::node_type) / 2);
}
TEST(Multiset, MaxSize4) {
  s21::multiset<double> s21_multiset;
  EXPECT_EQ(s21_multiset.max_size(),
            std::numeric_limits<s21::multiset<double>::size_type>::max() /
                sizeof(s21::multiset<double>::node_type) / 2);
}

TEST(Multiset, Clear1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  s21_multiset.clear();
  std_multiset.clear();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(Multiset, Clear2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  s21_multiset.clear();
  std_multiset.clear();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(Multiset, Insert1) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  auto s21_insert_res = s21_multiset.insert(0);
  auto std_insert_res = std_multiset.insert(0);
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  s21_insert_res = s21_multiset.insert(1);
  std_insert_res = std_multiset.insert(1);
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  s21_insert_res = s21_multiset.insert(1);
  std_insert_res = std_multiset.insert(1);
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Insert2) {
  s21::multiset<std::string> s21_multiset;
  std::multiset<std::string> std_multiset;
  auto s21_insert_res = s21_multiset.insert("0");
  auto std_insert_res = std_multiset.insert("0");
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  s21_insert_res = s21_multiset.insert("1");
  std_insert_res = std_multiset.insert("1");
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  s21_insert_res = s21_multiset.insert("1");
  std_insert_res = std_multiset.insert("1");
  EXPECT_EQ(*s21_insert_res, *std_insert_res);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, InsertMany1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  auto s21_res_vector = s21_multiset.insert_many(5, 6, 7, 8, 8);
  std::vector<std::multiset<int>::iterator> std_res_vector;
  std_res_vector.push_back(std_multiset.insert(5));
  std_res_vector.push_back(std_multiset.insert(6));
  std_res_vector.push_back(std_multiset.insert(7));
  std_res_vector.push_back(std_multiset.insert(8));
  std_res_vector.push_back(std_multiset.insert(8));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); i++) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i]);
  }
}

TEST(Multiset, InsertMany2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  auto s21_res_vector = s21_multiset.insert_many("5", "6", "7", "8", "8");
  std::vector<std::multiset<std::string>::iterator> std_res_vector;
  std_res_vector.push_back(std_multiset.insert("5"));
  std_res_vector.push_back(std_multiset.insert("6"));
  std_res_vector.push_back(std_multiset.insert("7"));
  std_res_vector.push_back(std_multiset.insert("8"));
  std_res_vector.push_back(std_multiset.insert("8"));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); i++) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i]);
  }
}

TEST(Multiset, Erase1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});

  s21_multiset.erase(s21_multiset.begin());
  std_multiset.erase(std_multiset.begin());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_multiset.erase(--s21_multiset.end());
  std_multiset.erase(--std_multiset.end());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  s21_i = s21_multiset.begin();
  std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Erase2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});

  s21_multiset.erase(s21_multiset.begin());
  std_multiset.erase(std_multiset.begin());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_multiset.erase(--s21_multiset.end());
  std_multiset.erase(--std_multiset.end());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  s21_i = s21_multiset.begin();
  std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Swap1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  s21::multiset<int> s21_multiset_swap({5, 6, 7});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset_swap({5, 6, 7});

  s21_multiset.swap(s21_multiset_swap);
  std_multiset.swap(std_multiset_swap);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_swap.size(), std_multiset_swap.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_multiset_swap.begin();
  auto std_i_swap = std_multiset_swap.begin();
  for (size_t i = 0; i < s21_multiset_swap.size(); i++) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Multiset, Swap2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  s21::multiset<std::string> s21_multiset_swap({"5", "6", "7"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset_swap({"5", "6", "7"});

  s21_multiset.swap(s21_multiset_swap);
  std_multiset.swap(std_multiset_swap);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_swap.size(), std_multiset_swap.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_multiset_swap.begin();
  auto std_i_swap = std_multiset_swap.begin();
  for (size_t i = 0; i < s21_multiset_swap.size(); i++) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Multiset, Merge1) {
  s21::multiset<int> s21_multiset({0, 1, 2, 3, 4});
  s21::multiset<int> s21_multiset_merge({5, 6, 7});
  std::multiset<int> std_multiset({0, 1, 2, 3, 4});
  std::multiset<int> std_multiset_merge({5, 6, 7});

  s21_multiset.merge(s21_multiset_merge);
  std_multiset.merge(std_multiset_merge);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_merge.size(), std_multiset_merge.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Merge2) {
  s21::multiset<std::string> s21_multiset({"0", "1", "2", "3", "4"});
  s21::multiset<std::string> s21_multiset_merge({"5", "6", "7"});
  std::multiset<std::string> std_multiset({"0", "1", "2", "3", "4"});
  std::multiset<std::string> std_multiset_merge({"5", "6", "7"});

  s21_multiset.merge(s21_multiset_merge);
  std_multiset.merge(std_multiset_merge);

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset_merge.size(), std_multiset_merge.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Multiset, Count1) {
  s21::multiset<int> s21_multiset({1, 0, 0, 0, 0, 0});
  std::multiset<int> std_multiset({1, 0, 0, 0, 0, 0});
  EXPECT_EQ(s21_multiset.count(0), std_multiset.count(0));
  EXPECT_EQ(s21_multiset.count(1), std_multiset.count(1));
  EXPECT_EQ(s21_multiset.count(2), std_multiset.count(2));
}

TEST(Multiset, Count2) {
  s21::multiset<std::string> s21_multiset({"1", "0", "0", "0", "0", "0"});
  std::multiset<std::string> std_multiset({"1", "0", "0", "0", "0", "0"});
  EXPECT_EQ(s21_multiset.count("0"), std_multiset.count("0"));
  EXPECT_EQ(s21_multiset.count("1"), std_multiset.count("1"));
  EXPECT_EQ(s21_multiset.count("2"), std_multiset.count("2"));
}

TEST(Multiset, EqualRange1) {
  s21::multiset<int> s21_multiset({1, 2, 3, 4, 4, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4, 4});
  EXPECT_EQ(*s21_multiset.equal_range(1).first,
            *std_multiset.equal_range(1).first);
  EXPECT_EQ(*s21_multiset.equal_range(1).second,
            *std_multiset.equal_range(1).second);

  EXPECT_EQ(*s21_multiset.equal_range(2).first,
            *std_multiset.equal_range(2).first);
  EXPECT_EQ(*s21_multiset.equal_range(2).second,
            *std_multiset.equal_range(2).second);

  auto s21_i = s21_multiset.equal_range(4).first;
  auto std_i = std_multiset.equal_range(4).first;
  while (s21_i != s21_multiset.equal_range(4).second &&
         std_i != std_multiset.equal_range(4).second) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }

  EXPECT_EQ(s21_multiset.equal_range(8).first, s21_multiset.end());
  EXPECT_EQ(std_multiset.equal_range(8).first, std_multiset.end());
  EXPECT_EQ(s21_multiset.equal_range(8).second, s21_multiset.end());
  EXPECT_EQ(std_multiset.equal_range(8).second, std_multiset.end());
}

TEST(Multiset, EqualRange2) {
  s21::multiset<std::string> s21_multiset({"1", "2", "3", "4", "4", "4", "4"});
  std::multiset<std::string> std_multiset({"1", "2", "3", "4", "4", "4", "4"});
  EXPECT_EQ(*s21_multiset.equal_range("1").first,
            *std_multiset.equal_range("1").first);
  EXPECT_EQ(*s21_multiset.equal_range("1").second,
            *std_multiset.equal_range("1").second);

  EXPECT_EQ(*s21_multiset.equal_range("2").first,
            *std_multiset.equal_range("2").first);
  EXPECT_EQ(*s21_multiset.equal_range("2").second,
            *std_multiset.equal_range("2").second);

  auto s21_i = s21_multiset.equal_range("4").first;
  auto std_i = std_multiset.equal_range("4").first;
  while (s21_i != s21_multiset.equal_range("4").second &&
         std_i != std_multiset.equal_range("4").second) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }

  EXPECT_EQ(s21_multiset.equal_range("8").first, s21_multiset.end());
  EXPECT_EQ(std_multiset.equal_range("8").first, std_multiset.end());
  EXPECT_EQ(s21_multiset.equal_range("8").second, s21_multiset.end());
  EXPECT_EQ(std_multiset.equal_range("8").second, std_multiset.end());
}

TEST(Multiset, LowerBound1) {
  s21::multiset<int> s21_multiset({1, 2, 3, 4, 4, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4, 4});
  EXPECT_EQ(*s21_multiset.lower_bound(1), *std_multiset.lower_bound(1));

  EXPECT_EQ(*s21_multiset.lower_bound(2), *std_multiset.lower_bound(2));

  auto s21_i = s21_multiset.lower_bound(4);
  auto std_i = std_multiset.lower_bound(4);
  while (s21_i != s21_multiset.end() && std_i != std_multiset.end()) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  EXPECT_EQ(s21_multiset.lower_bound(8), s21_multiset.end());
  EXPECT_EQ(std_multiset.lower_bound(8), std_multiset.end());
}

TEST(Multiset, LowerBound2) {
  s21::multiset<std::string> s21_multiset({"1", "2", "3", "4", "4", "4", "4"});
  std::multiset<std::string> std_multiset({"1", "2", "3", "4", "4", "4", "4"});
  EXPECT_EQ(*s21_multiset.lower_bound("1"), *std_multiset.lower_bound("1"));

  EXPECT_EQ(*s21_multiset.lower_bound("2"), *std_multiset.lower_bound("2"));

  auto s21_i = s21_multiset.lower_bound("4");
  auto std_i = std_multiset.lower_bound("4");
  while (s21_i != s21_multiset.end() && std_i != std_multiset.end()) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  EXPECT_EQ(s21_multiset.lower_bound("8"), s21_multiset.end());
  EXPECT_EQ(std_multiset.lower_bound("8"), std_multiset.end());
}

TEST(Multiset, UpperBound1) {
  s21::multiset<int> s21_multiset({1, 2, 3, 4, 4, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 4, 4, 4, 4});
  EXPECT_EQ(*s21_multiset.upper_bound(1), *std_multiset.upper_bound(1));

  EXPECT_EQ(*s21_multiset.upper_bound(2), *std_multiset.upper_bound(2));

  EXPECT_EQ(s21_multiset.upper_bound(4), s21_multiset.end());
  EXPECT_EQ(std_multiset.upper_bound(4), std_multiset.end());

  auto s21_i = s21_multiset.upper_bound(3);
  auto std_i = std_multiset.upper_bound(3);
  while (s21_i != s21_multiset.end() && std_i != std_multiset.end()) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  EXPECT_EQ(s21_multiset.upper_bound(8), s21_multiset.end());
  EXPECT_EQ(std_multiset.upper_bound(8), std_multiset.end());
}

TEST(Multiset, UpperBound2) {
  s21::multiset<std::string> s21_multiset({"1", "2", "3", "4", "4", "4", "4"});
  std::multiset<std::string> std_multiset({"1", "2", "3", "4", "4", "4", "4"});
  EXPECT_EQ(*s21_multiset.upper_bound("1"), *std_multiset.upper_bound("1"));

  EXPECT_EQ(*s21_multiset.upper_bound("2"), *std_multiset.upper_bound("2"));

  EXPECT_EQ(s21_multiset.upper_bound("4"), s21_multiset.end());
  EXPECT_EQ(std_multiset.upper_bound("4"), std_multiset.end());

  auto s21_i = s21_multiset.upper_bound("3");
  auto std_i = std_multiset.upper_bound("3");
  while (s21_i != s21_multiset.end() && std_i != std_multiset.end()) {
    EXPECT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  EXPECT_EQ(s21_multiset.upper_bound("8"), s21_multiset.end());
  EXPECT_EQ(std_multiset.upper_bound("8"), std_multiset.end());
}

TEST(Multiset, OperatorLessUsage) {
  s21::multiset<SomeClass> s21_multiset({SomeClass(3, 3), SomeClass(1, 1),
                                         SomeClass(0, 0), SomeClass(2, 2),
                                         SomeClass(2, 2)});
  std::multiset<SomeClass> std_multiset({SomeClass(3, 3), SomeClass(1, 1),
                                         SomeClass(0, 0), SomeClass(2, 2),
                                         SomeClass(2, 2)});

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(**s21_i++, **std_i++);
  }
}

TEST(Multiset, FunctorUsage) {
  s21::multiset<SomeClass, Functor> s21_multiset(
      {SomeClass(3, 3), SomeClass(1, 1), SomeClass(0, 0), SomeClass(2, 2),
       SomeClass(2, 2)});
  std::multiset<SomeClass, Functor> std_multiset(
      {SomeClass(3, 3), SomeClass(1, 1), SomeClass(0, 0), SomeClass(2, 2),
       SomeClass(2, 2)});

  auto s21_i = s21_multiset.begin();
  auto std_i = std_multiset.begin();
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    EXPECT_EQ(**s21_i++, **std_i++);
  }
}
