#include <map>

#include "test_containers.h"

TEST(Map, Constructor1) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(Map, Constructor2) {
  s21::map<std::string, std::string> s21_map;
  std::map<std::string, std::string> std_map;
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(Map, ParametrizedConstructor1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4), std::pair<int, int>(4, 4),
       std::pair<int, int>(0, 0)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4), std::pair<int, int>(4, 4),
       std::pair<int, int>(0, 0)});

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, ParametrizedConstructor2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4"),
       std::pair<std::string, std::string>("4", "4"),
       std::pair<std::string, std::string>("0", "0")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4"),
       std::pair<std::string, std::string>("4", "4"),
       std::pair<std::string, std::string>("0", "0")});

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, CopyConstructor1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21::map<int, int> s21_map_copy(s21_map);
  std::map<int, int> std_map_copy(std_map);

  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());

  auto s21_i = s21_map_copy.begin();
  auto std_i = std_map_copy.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, CopyConstructor2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21::map<std::string, std::string> s21_map_copy(s21_map);
  std::map<std::string, std::string> std_map_copy(std_map);

  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());

  auto s21_i = s21_map_copy.begin();
  auto std_i = std_map_copy.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, MoveConstructor1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21::map<int, int> s21_map_move(move(s21_map));
  std::map<int, int> std_map_move(move(std_map));

  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map_move.begin();
  auto std_i = std_map_move.begin();
  for (size_t i = 0; i < s21_map_move.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, MoveConstructor2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21::map<std::string, std::string> s21_map_move(move(s21_map));
  std::map<std::string, std::string> std_map_move(move(std_map));

  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map_move.begin();
  auto std_i = std_map_move.begin();
  for (size_t i = 0; i < s21_map_move.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, MoveAssingmentOperator1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21::map<int, int> s21_map_move = move(s21_map);
  std::map<int, int> std_map_move = move(std_map);

  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map_move.begin();
  auto std_i = std_map_move.begin();
  for (size_t i = 0; i < s21_map_move.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, MoveAssingmentOperator2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21::map<std::string, std::string> s21_map_move = move(s21_map);
  std::map<std::string, std::string> std_map_move = move(std_map);

  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map_move.begin();
  auto std_i = std_map_move.begin();
  for (size_t i = 0; i < s21_map_move.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, At1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});

  EXPECT_EQ(s21_map.at(0), std_map.at(0));
  EXPECT_EQ(s21_map.at(1), std_map.at(1));
  EXPECT_EQ(s21_map.at(2), std_map.at(2));
  EXPECT_EQ(s21_map.at(3), std_map.at(3));
  EXPECT_EQ(s21_map.at(4), std_map.at(4));
  EXPECT_THROW(s21_map.at(9), std::out_of_range);
  EXPECT_THROW(std_map.at(9), std::out_of_range);

  s21_map.at(0) = 23;
  std_map.at(0) = 23;
  EXPECT_EQ(s21_map.at(0), std_map.at(0));
}

TEST(Map, At2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  EXPECT_EQ(s21_map.at("0"), std_map.at("0"));
  EXPECT_EQ(s21_map.at("1"), std_map.at("1"));
  EXPECT_EQ(s21_map.at("2"), std_map.at("2"));
  EXPECT_EQ(s21_map.at("3"), std_map.at("3"));
  EXPECT_EQ(s21_map.at("4"), std_map.at("4"));
  EXPECT_THROW(s21_map.at("9"), std::out_of_range);
  EXPECT_THROW(std_map.at("9"), std::out_of_range);

  s21_map.at("0") = "23";
  std_map.at("0") = "23";
  EXPECT_EQ(s21_map.at("0"), std_map.at("0"));
}

TEST(Map, BracketsOperator1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});

  EXPECT_EQ(s21_map[0], std_map[0]);
  EXPECT_EQ(s21_map[1], std_map[1]);
  EXPECT_EQ(s21_map[2], std_map[2]);
  EXPECT_EQ(s21_map[3], std_map[3]);
  EXPECT_EQ(s21_map[4], std_map[4]);
  EXPECT_EQ(s21_map[9], std_map[9]);
  EXPECT_EQ(s21_map.at(9), std_map.at(9));

  s21_map[11] = 23;
  std_map[11] = 23;
  EXPECT_EQ(s21_map[11], std_map[11]);
}

TEST(Map, BracketsOperator2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});

  EXPECT_EQ(s21_map["0"], std_map["0"]);
  EXPECT_EQ(s21_map["1"], std_map["1"]);
  EXPECT_EQ(s21_map["2"], std_map["2"]);
  EXPECT_EQ(s21_map["3"], std_map["3"]);
  EXPECT_EQ(s21_map["4"], std_map["4"]);
  EXPECT_EQ(s21_map["9"], std_map["9"]);
  EXPECT_EQ(s21_map.at("9"), std_map.at("9"));

  s21_map["11"] = "23";
  std_map["11"] = "23";
  EXPECT_EQ(s21_map["11"], std_map["11"]);
}

TEST(Map, Begin1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Map, Begin2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  EXPECT_EQ(*s21_i++, *std_i++);
  EXPECT_EQ(*s21_i++, *std_i++);
}

TEST(Map, End1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});

  auto s21_i = s21_map.end();
  auto std_i = std_map.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Map, End2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});

  auto s21_i = s21_map.end();
  auto std_i = std_map.end();
  EXPECT_EQ(*--s21_i, *--std_i);
  EXPECT_EQ(*--s21_i, *--std_i);
}

TEST(Map, Empty1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  EXPECT_EQ(s21_map.empty(), std_map.empty());

  s21::map<int, int> s21_empty_map;
  std::map<int, int> std_empty_map;
  EXPECT_EQ(s21_empty_map.empty(), std_empty_map.empty());
}

TEST(Map, Empty2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  EXPECT_EQ(s21_map.empty(), std_map.empty());

  s21::map<std::string, std::string> s21_empty_map;
  std::map<std::string, std::string> std_empty_map;
  EXPECT_EQ(s21_empty_map.empty(), std_empty_map.empty());
}

TEST(Map, Size1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  EXPECT_EQ(s21_map.size(), std_map.size());

  s21::map<int, int> s21_empty_map;
  std::map<int, int> std_empty_map;
  EXPECT_EQ(s21_empty_map.size(), std_empty_map.size());
}

TEST(Map, Size2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  EXPECT_EQ(s21_map.size(), std_map.size());

  s21::map<std::string, std::string> s21_empty_map;
  std::map<std::string, std::string> std_empty_map;
  EXPECT_EQ(s21_empty_map.size(), std_empty_map.size());
}

TEST(Map, MaxSize1) {
  s21::map<bool, bool> s21_map;
  EXPECT_EQ(s21_map.max_size(), std::numeric_limits<size_t>::max() /
                                    sizeof(s21::map<bool, bool>::node_type) /
                                    2);
}

TEST(Map, MaxSize2) {
  s21::map<int, int> s21_map;
  EXPECT_EQ(s21_map.max_size(), std::numeric_limits<size_t>::max() /
                                    sizeof(s21::map<int, int>::node_type) / 2);
}
TEST(Map, MaxSize3) {
  s21::map<std::string, std::string> s21_map;
  EXPECT_EQ(s21_map.max_size(),
            std::numeric_limits<size_t>::max() /
                sizeof(s21::map<std::string, std::string>::node_type) / 2);
}
TEST(Map, MaxSize4) {
  s21::map<double, double> s21_map;
  EXPECT_EQ(s21_map.max_size(),
            std::numeric_limits<size_t>::max() /
                sizeof(s21::map<double, double>::node_type) / 2);
}

TEST(Map, Clear1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21_map.clear();
  std_map.clear();
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(Map, Clear2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21_map.clear();
  std_map.clear();
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(Map, InsertValueVersion1) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  auto s21_insert_res = s21_map.insert(std::pair<int, int>(0, 0));
  auto std_insert_res = std_map.insert(std::pair<int, int>(0, 0));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(std::pair<int, int>(1, 1));
  std_insert_res = std_map.insert(std::pair<int, int>(1, 1));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(std::pair<int, int>(1, 1));
  std_insert_res = std_map.insert(std::pair<int, int>(1, 1));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(std::pair<int, int>(1, 4));
  std_insert_res = std_map.insert(std::pair<int, int>(1, 4));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertValueVersion2) {
  s21::map<std::string, std::string> s21_map;
  std::map<std::string, std::string> std_map;
  auto s21_insert_res =
      s21_map.insert(std::pair<std::string, std::string>("0", "0"));
  auto std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("0", "0"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res =
      s21_map.insert(std::pair<std::string, std::string>("1", "1"));
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "1"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res =
      s21_map.insert(std::pair<std::string, std::string>("1", "1"));
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "1"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res =
      s21_map.insert(std::pair<std::string, std::string>("1", "4"));
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "4"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertKeyMapVersion1) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  auto s21_insert_res = s21_map.insert(0, 0);
  auto std_insert_res = std_map.insert(std::pair<int, int>(0, 0));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(1, 1);
  std_insert_res = std_map.insert(std::pair<int, int>(1, 1));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(1, 1);
  std_insert_res = std_map.insert(std::pair<int, int>(1, 1));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert(1, 4);
  std_insert_res = std_map.insert(std::pair<int, int>(1, 4));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertKeyMapVersion2) {
  s21::map<std::string, std::string> s21_map;
  std::map<std::string, std::string> std_map;
  auto s21_insert_res = s21_map.insert("0", "0");
  auto std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("0", "0"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert("1", "1");
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "1"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert("1", "1");
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "1"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert("1", "4");
  std_insert_res =
      std_map.insert(std::pair<std::string, std::string>("1", "4"));
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertOrAssign1) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  auto s21_insert_res = s21_map.insert_or_assign(0, 0);
  auto std_insert_res = std_map.insert_or_assign(0, 0);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign(1, 1);
  std_insert_res = std_map.insert_or_assign(1, 1);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign(1, 1);
  std_insert_res = std_map.insert_or_assign(1, 1);
  EXPECT_EQ(*s21_insert_res.first, *std_insert_res.first);
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign(1, 4);
  std_insert_res = std_map.insert_or_assign(1, 4);
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertOrAssign2) {
  s21::map<std::string, std::string> s21_map;
  std::map<std::string, std::string> std_map;
  auto s21_insert_res = s21_map.insert_or_assign("0", "0");
  auto std_insert_res = std_map.insert_or_assign("0", "0");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign("1", "1");
  std_insert_res = std_map.insert_or_assign("1", "1");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign("1", "1");
  std_insert_res = std_map.insert_or_assign("1", "1");
  EXPECT_EQ(*s21_insert_res.first, *std_insert_res.first);
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  s21_insert_res = s21_map.insert_or_assign("1", "4");
  std_insert_res = std_map.insert_or_assign("1", "4");
  EXPECT_EQ(*(s21_insert_res.first), *(std_insert_res.first));
  EXPECT_EQ(s21_insert_res.second, std_insert_res.second);

  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, InsertMany1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  auto s21_res_vector =
      s21_map.insert_many(std::pair<int, int>(5, 5), std::pair<int, int>(6, 6),
                          std::pair<int, int>(7, 7), std::pair<int, int>(8, 8),
                          std::pair<int, int>(8, 8));
  std::vector<std::pair<std::map<int, int>::iterator, bool>> std_res_vector;
  std_res_vector.push_back(std_map.insert(std::pair<const int, int>(5, 5)));
  std_res_vector.push_back(std_map.insert(std::pair<const int, int>(6, 6)));
  std_res_vector.push_back(std_map.insert(std::pair<const int, int>(7, 7)));
  std_res_vector.push_back(std_map.insert(std::pair<const int, int>(8, 8)));
  std_res_vector.push_back(std_map.insert(std::pair<const int, int>(8, 8)));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); ++i) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i].first);
    EXPECT_EQ(s21_res_vector[i].second, std_res_vector[i].second);
  }
}

TEST(Map, InsertMany2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  auto s21_res_vector =
      s21_map.insert_many(std::pair<std::string, std::string>("5", "5"),
                          std::pair<std::string, std::string>("6", "6"),
                          std::pair<std::string, std::string>("7", "7"),
                          std::pair<std::string, std::string>("8", "8"),
                          std::pair<std::string, std::string>("8", "8"));
  std::vector<std::pair<std::map<std::string, std::string>::iterator, bool>>
      std_res_vector;
  std_res_vector.push_back(
      std_map.insert(std::pair<const std::string, std::string>("5", "5")));
  std_res_vector.push_back(
      std_map.insert(std::pair<const std::string, std::string>("6", "6")));
  std_res_vector.push_back(
      std_map.insert(std::pair<const std::string, std::string>("7", "7")));
  std_res_vector.push_back(
      std_map.insert(std::pair<const std::string, std::string>("8", "8")));
  std_res_vector.push_back(
      std_map.insert(std::pair<const std::string, std::string>("8", "8")));
  EXPECT_EQ(s21_res_vector.size(), std_res_vector.size());
  for (size_t i = 0; i < s21_res_vector.size(); ++i) {
    EXPECT_EQ(*s21_res_vector[i].first, *std_res_vector[i].first);
    EXPECT_EQ(s21_res_vector[i].second, std_res_vector[i].second);
  }
}

TEST(Map, Erase1) {
  s21::map<int, int> s21_map;
  s21_map[0] = 90;
  s21_map[1] = 1;
  s21_map[2] = 2;
  s21_map[3] = 3;
  s21_map[4] = 4;
  std::map<int, int> std_map;
  std_map[0] = 90;
  std_map[1] = 1;
  std_map[2] = 2;
  std_map[3] = 3;
  std_map[4] = 4;

  auto s21_i = s21_map.end();
  auto std_i = std_map.end();
  --s21_i;
  std_i--;
  --s21_i;
  std_i--;
  s21_map.erase(s21_i);
  std_map.erase(std_i);
  EXPECT_EQ(s21_map.size(), std_map.size());
  s21_i = s21_map.begin();
  std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_map.erase(--s21_map.end());
  std_map.erase(--std_map.end());
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  s21_i = s21_map.begin();
  std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, Erase2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});

  s21_map.erase(s21_map.begin());
  std_map.erase(std_map.begin());
  EXPECT_EQ(s21_map.size(), std_map.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  s21_map.erase(--s21_map.end());
  std_map.erase(--std_map.end());
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map.size(), std_map.size());

  s21_i = s21_map.begin();
  std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, Swap1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21::map<int, int> s21_map_swap({std::pair<int, int>(5, 5),
                                   std::pair<int, int>(6, 6),
                                   std::pair<int, int>(7, 7)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map_swap({std::pair<int, int>(5, 5),
                                   std::pair<int, int>(6, 6),
                                   std::pair<int, int>(7, 7)});

  s21_map.swap(s21_map_swap);
  std_map.swap(std_map_swap);

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_map_swap.begin();
  auto std_i_swap = std_map_swap.begin();
  for (size_t i = 0; i < s21_map_swap.size(); ++i) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Map, Swap2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21::map<std::string, std::string> s21_map_swap(
      {std::pair<std::string, std::string>("5", "5"),
       std::pair<std::string, std::string>("6", "6"),
       std::pair<std::string, std::string>("7", "7")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map_swap(
      {std::pair<std::string, std::string>("5", "5"),
       std::pair<std::string, std::string>("6", "6"),
       std::pair<std::string, std::string>("7", "7")});

  s21_map.swap(s21_map_swap);
  std_map.swap(std_map_swap);

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }

  auto s21_i_swap = s21_map_swap.begin();
  auto std_i_swap = std_map_swap.begin();
  for (size_t i = 0; i < s21_map_swap.size(); ++i) {
    EXPECT_EQ(*s21_i_swap++, *std_i_swap++);
  }
}

TEST(Map, Merge1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  s21::map<int, int> s21_map_merge({std::pair<int, int>(5, 5),
                                    std::pair<int, int>(6, 6),
                                    std::pair<int, int>(7, 7)});
  std::map<int, int> std_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});
  std::map<int, int> std_map_merge({std::pair<int, int>(5, 5),
                                    std::pair<int, int>(6, 6),
                                    std::pair<int, int>(7, 7)});

  s21_map.merge(s21_map_merge);
  std_map.merge(std_map_merge);

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_merge.size(), std_map_merge.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, Merge2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  s21::map<std::string, std::string> s21_map_merge(
      {std::pair<std::string, std::string>("5", "5"),
       std::pair<std::string, std::string>("6", "6"),
       std::pair<std::string, std::string>("7", "7")});
  std::map<std::string, std::string> std_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});
  std::map<std::string, std::string> std_map_merge(
      {std::pair<std::string, std::string>("5", "5"),
       std::pair<std::string, std::string>("6", "6"),
       std::pair<std::string, std::string>("7", "7")});

  s21_map.merge(s21_map_merge);
  std_map.merge(std_map_merge);

  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map_merge.size(), std_map_merge.size());

  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (size_t i = 0; i < s21_map.size(); ++i) {
    EXPECT_EQ(*s21_i++, *std_i++);
  }
}

TEST(Map, Contains1) {
  s21::map<int, int> s21_map(
      {std::pair<int, int>(0, 0), std::pair<int, int>(1, 1),
       std::pair<int, int>(2, 2), std::pair<int, int>(3, 3),
       std::pair<int, int>(4, 4)});

  EXPECT_EQ(s21_map.contains(-1), false);
  EXPECT_EQ(s21_map.contains(0), true);
  EXPECT_EQ(s21_map.contains(1), true);
  EXPECT_EQ(s21_map.contains(2), true);
  EXPECT_EQ(s21_map.contains(3), true);
  EXPECT_EQ(s21_map.contains(4), true);
  EXPECT_EQ(s21_map.contains(5), false);
}

TEST(Map, Contains2) {
  s21::map<std::string, std::string> s21_map(
      {std::pair<std::string, std::string>("0", "0"),
       std::pair<std::string, std::string>("1", "1"),
       std::pair<std::string, std::string>("2", "2"),
       std::pair<std::string, std::string>("3", "3"),
       std::pair<std::string, std::string>("4", "4")});

  EXPECT_EQ(s21_map.contains("-1"), false);
  EXPECT_EQ(s21_map.contains("0"), true);
  EXPECT_EQ(s21_map.contains("1"), true);
  EXPECT_EQ(s21_map.contains("2"), true);
  EXPECT_EQ(s21_map.contains("3"), true);
  EXPECT_EQ(s21_map.contains("4"), true);
  EXPECT_EQ(s21_map.contains("5"), false);
}

TEST(Map, OperatorLessUsage) {
  s21::map<SomeClass, SomeClass> s21_map(
      {std::pair<SomeClass, SomeClass>(SomeClass(3, 3), SomeClass(3, 3)),
       std::pair<SomeClass, SomeClass>(SomeClass(1, 1), SomeClass(1, 1)),
       std::pair<SomeClass, SomeClass>(SomeClass(0, 0), SomeClass(0, 0)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2))});
  std::map<SomeClass, SomeClass> std_map(
      {std::pair<SomeClass, SomeClass>(SomeClass(3, 3), SomeClass(3, 3)),
       std::pair<SomeClass, SomeClass>(SomeClass(1, 1), SomeClass(1, 1)),
       std::pair<SomeClass, SomeClass>(SomeClass(0, 0), SomeClass(0, 0)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2))});
  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (; s21_i != s21_map.end(); ++s21_i, ++std_i) {
    EXPECT_EQ(*(*s21_i).first, *(*std_i).first);
    EXPECT_EQ(*(*s21_i).second, *(*std_i).second);
  }
}

TEST(Map, FunctorUsage) {
  s21::map<SomeClass, SomeClass, Functor> s21_map(
      {std::pair<SomeClass, SomeClass>(SomeClass(3, 3), SomeClass(3, 3)),
       std::pair<SomeClass, SomeClass>(SomeClass(1, 1), SomeClass(1, 1)),
       std::pair<SomeClass, SomeClass>(SomeClass(0, 0), SomeClass(0, 0)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2))});
  std::map<SomeClass, SomeClass, Functor> std_map(
      {std::pair<SomeClass, SomeClass>(SomeClass(3, 3), SomeClass(3, 3)),
       std::pair<SomeClass, SomeClass>(SomeClass(1, 1), SomeClass(1, 1)),
       std::pair<SomeClass, SomeClass>(SomeClass(0, 0), SomeClass(0, 0)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2)),
       std::pair<SomeClass, SomeClass>(SomeClass(2, 2), SomeClass(2, 2))});
  auto s21_i = s21_map.begin();
  auto std_i = std_map.begin();
  for (; s21_i != s21_map.end(); ++s21_i, ++std_i) {
    EXPECT_EQ(*(*s21_i).first, *(*std_i).first);
    EXPECT_EQ(*(*s21_i).second, *(*std_i).second);
  }
}
