#include <array>

#include "test_containers.h"

// Default constructor
TEST(Array, Constructor_Default_Int) {
  s21::array<int, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], 0);
  }
}

TEST(Array, Constructor_Default_Float) {
  s21::array<float, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array[i], 0.f);
  }
}

TEST(Array, Constructor_Default_Double) {
  s21::array<double, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array[i], 0.0);
  }
}

TEST(Array, Constructor_Default_Char) {
  s21::array<char, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], '\0');
  }
}

TEST(Array, Constructor_Default_String) {
  s21::array<std::string, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], "");
  }
}

// Initializer list constructor
TEST(Array, Constructor_List_Int) {
  s21::array<int, 3> s21_array = {1, 2, 3};
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], static_cast<int>(i) + 1);
  }
}

TEST(Array, Constructor_List_Int_2) {
  s21::array<int, 10> s21_array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.size(), 10);
  int val = 10;
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], val--);
  }
}

TEST(Array, Constructor_List_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  std::array<float, 3> std_array = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_List_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  std::array<double, 3> std_array = {1.123456, 2.222222, 3.987654};
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_List_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  std::array<char, 5> std_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_List_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  std::array<std::string, 5> std_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], std_array[i]);
  }
}

// Copy constructor
TEST(Array, Constructor_Copy_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  s21::array<int, 5> s21_copy_array(s21_array);
  EXPECT_EQ(s21_array.size(), s21_copy_array.size());
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Constructor_Copy_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  s21::array<float, 3> s21_copy_array(s21_array);
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Constructor_Copy_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  s21::array<double, 3> s21_copy_array(s21_array);
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Constructor_Copy_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  s21::array<char, 5> s21_copy_array(s21_array);
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Constructor_Copy_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  s21::array<std::string, 5> s21_copy_array(s21_array);
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

// Move constructor
TEST(Array, Constructor_Move_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  s21::array<int, 5> s21_move_array(std::move(s21_array));
  std::array<int, 5> std_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_Move_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  s21::array<float, 3> s21_move_array(std::move(s21_array));
  std::array<float, 3> std_array = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_move_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_Move_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  s21::array<double, 3> s21_move_array(std::move(s21_array));
  std::array<double, 3> std_array = {1.123456, 2.222222, 3.987654};
  EXPECT_EQ(s21_move_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_Move_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  s21::array<char, 5> s21_move_array(std::move(s21_array));
  std::array<char, 5> std_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Constructor_Move_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  s21::array<std::string, 5> s21_move_array(std::move(s21_array));
  std::array<std::string, 5> std_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

// Assignment operator
TEST(Array, Assign_Operator_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  s21::array<int, 5> s21_copy_array;
  s21_copy_array = s21_array;
  EXPECT_EQ(s21_array.size(), s21_copy_array.size());
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Assign_Operator_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  s21::array<float, 3> s21_copy_array;
  s21_copy_array = s21_array;
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Assign_Operator_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  s21::array<double, 3> s21_copy_array;
  s21_copy_array = s21_array;
  EXPECT_EQ(s21_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Assign_Operator_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  s21::array<char, 5> s21_copy_array;
  s21_copy_array = s21_array;
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

TEST(Array, Assign_Operator_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  s21::array<std::string, 5> s21_copy_array;
  s21_copy_array = s21_array;
  EXPECT_EQ(s21_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], s21_copy_array[i]);
  }
}

// Assignment + move operator
TEST(Array, Assign_Via_Move_Operator_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  s21::array<int, 5> s21_move_array;
  s21_move_array = std::move(s21_array);
  std::array<int, 5> std_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Assign_Via_Move_Operator_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  s21::array<float, 3> s21_move_array;
  s21_move_array = std::move(s21_array);
  std::array<float, 3> std_array = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_move_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Assign_Via_Move_Operator_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  s21::array<double, 3> s21_move_array;
  s21_move_array = std::move(s21_array);
  std::array<double, 3> std_array = {1.123456, 2.222222, 3.987654};
  EXPECT_EQ(s21_move_array.size(), 3);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Assign_Via_Move_Operator_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  s21::array<char, 5> s21_move_array;
  s21_move_array = std::move(s21_array);
  std::array<char, 5> std_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

TEST(Array, Assign_Via_Move_Operator_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  s21::array<std::string, 5> s21_move_array;
  s21_move_array = std::move(s21_array);
  std::array<std::string, 5> std_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(s21_move_array.size(), 5);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_move_array[i], std_array[i]);
  }
}

// Access operator, inside correct bounds
TEST(Array, Access_Operator_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array[0], 5);
  EXPECT_EQ(s21_array[1], 4);
  EXPECT_EQ(s21_array[2], 3);
  EXPECT_EQ(s21_array[3], 2);
  EXPECT_EQ(s21_array[4], 1);
}

TEST(Array, Access_Operator_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array[0], 1.3);
  EXPECT_FLOAT_EQ(s21_array[1], 2.22);
  EXPECT_FLOAT_EQ(s21_array[2], 3.111);
}

TEST(Array, Access_Operator_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_array[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_array[2], 3.987654);
}

TEST(Array, Access_Operator_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array[0], 'a');
  EXPECT_EQ(s21_array[1], 'c');
  EXPECT_EQ(s21_array[2], 'b');
  EXPECT_EQ(s21_array[3], 'x');
  EXPECT_EQ(s21_array[4], 'y');
}

TEST(Array, Access_Operator_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(s21_array[0], "Hey ");
  EXPECT_EQ(s21_array[1], "there!\n");
  EXPECT_EQ(s21_array[2], "It's a");
  EXPECT_EQ(s21_array[3], " test ");
  EXPECT_EQ(s21_array[4], "string!\n");
}

// Access operator, outside correct bounds
TEST(Array, Access_Operator_Int_Wrong_Pos) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Float_Wrong_Pos) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Double_Wrong_Pos) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Char_Wrong_Pos) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_String_Wrong_Pos) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

// Access const operator, inside correct bounds
TEST(Array, Access_Operator_Int_Const) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array[0], 5);
  EXPECT_EQ(s21_array[1], 4);
  EXPECT_EQ(s21_array[2], 3);
  EXPECT_EQ(s21_array[3], 2);
  EXPECT_EQ(s21_array[4], 1);
}

TEST(Array, Access_Operator_Float_Const) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array[0], 1.3);
  EXPECT_FLOAT_EQ(s21_array[1], 2.22);
  EXPECT_FLOAT_EQ(s21_array[2], 3.111);
}

TEST(Array, Access_Operator_Double_Const) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_array[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_array[2], 3.987654);
}

TEST(Array, Access_Operator_Char_Const) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array[0], 'a');
  EXPECT_EQ(s21_array[1], 'c');
  EXPECT_EQ(s21_array[2], 'b');
  EXPECT_EQ(s21_array[3], 'x');
  EXPECT_EQ(s21_array[4], 'y');
}

TEST(Array, Access_Operator_String_Const) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_EQ(s21_array[0], "Hey ");
  EXPECT_EQ(s21_array[1], "there!\n");
  EXPECT_EQ(s21_array[2], "It's a");
  EXPECT_EQ(s21_array[3], " test ");
  EXPECT_EQ(s21_array[4], "string!\n");
}

// Const access operator, outside correct bounds
TEST(Array, Access_Operator_Int_Wrong_Pos_Const) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Float_Wrong_Pos_Const) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Double_Wrong_Pos_Const) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_Char_Wrong_Pos_Const) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

TEST(Array, Access_Operator_String_Wrong_Pos_Const) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_array[-1]);
  EXPECT_ANY_THROW(s21_array[5]);
  EXPECT_ANY_THROW(s21_array[15]);
}

// Iterator begin
TEST(Array, Begin_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  auto it = s21_array.begin();
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(*(it + 1), 4);
  EXPECT_EQ(*(it + 2), 3);
  *it = 1;
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*(it + 3), 2);
  EXPECT_EQ(*(it + 4), 1);
}

TEST(Array, Begin_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  auto it = s21_array.begin();
  EXPECT_FLOAT_EQ(*it, 1.3);
  EXPECT_FLOAT_EQ(*(it + 1), 2.22);
  *it = 13.31;
  EXPECT_FLOAT_EQ(*it, 13.31);
  EXPECT_FLOAT_EQ(*(it + 2), 3.111);
}

TEST(Array, Begin_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  auto it = s21_array.begin();
  EXPECT_DOUBLE_EQ(*it, 1.123456);
  EXPECT_DOUBLE_EQ(*(it + 1), 2.222222);
  *it = 1.654321;
  EXPECT_DOUBLE_EQ(*it, 1.654321);
  EXPECT_DOUBLE_EQ(*(it + 2), 3.987654);
}

TEST(Array, Begin_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_array.begin();
  EXPECT_EQ(*it, 'a');
  EXPECT_EQ(*(it + 1), 'c');
  EXPECT_EQ(*(it + 2), 'b');
  *it = '0';
  EXPECT_EQ(*it, '0');
  EXPECT_EQ(*(it + 3), 'x');
  EXPECT_EQ(*(it + 4), 'y');
}

TEST(Array, Begin_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  auto it = s21_array.begin();
  EXPECT_EQ(*it, "Hey ");
  EXPECT_EQ(*(it + 1), "there!\n");
  EXPECT_EQ(*(it + 2), "It's a");
  *it = "Hello ";
  EXPECT_EQ(*it, "Hello ");
  EXPECT_EQ(*(it + 3), " test ");
  EXPECT_EQ(*(it + 4), "string!\n");
}

// Const iterator cbegin
TEST(Array, Cbegin_Int) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  auto it = s21_array.cbegin();
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(*(it + 1), 4);
  EXPECT_EQ(*(it + 2), 3);
  EXPECT_EQ(*(it + 3), 2);
  EXPECT_EQ(*(it + 4), 1);
}

TEST(Array, Cbegin_Float) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  auto it = s21_array.cbegin();
  EXPECT_FLOAT_EQ(*it, 1.3);
  EXPECT_FLOAT_EQ(*(it + 1), 2.22);
  EXPECT_FLOAT_EQ(*(it + 2), 3.111);
}

TEST(Array, Cbegin_Double) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  auto it = s21_array.cbegin();
  EXPECT_DOUBLE_EQ(*it, 1.123456);
  EXPECT_DOUBLE_EQ(*(it + 1), 2.222222);
  EXPECT_DOUBLE_EQ(*(it + 2), 3.987654);
}

TEST(Array, Cbegin_Char) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_array.cbegin();
  EXPECT_EQ(*it, 'a');
  EXPECT_EQ(*(it + 1), 'c');
  EXPECT_EQ(*(it + 2), 'b');
  EXPECT_EQ(*(it + 3), 'x');
  EXPECT_EQ(*(it + 4), 'y');
}

TEST(Array, Cbegin_String) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  auto it = s21_array.cbegin();
  EXPECT_EQ(*it, "Hey ");
  EXPECT_EQ(*(it + 1), "there!\n");
  EXPECT_EQ(*(it + 2), "It's a");
  EXPECT_EQ(*(it + 3), " test ");
  EXPECT_EQ(*(it + 4), "string!\n");
}

// Iterator end
TEST(Array, End_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  auto it = s21_array.end();
  EXPECT_EQ(*(it - 1), 1);
  EXPECT_EQ(*(it - 2), 2);
  EXPECT_EQ(*(it - 3), 3);
  *(it - 3) = 5;
  EXPECT_EQ(*(it - 3), 5);
  EXPECT_EQ(*(it - 4), 4);
  EXPECT_EQ(*(it - 5), 5);
}

TEST(Array, End_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  auto it = s21_array.end();
  EXPECT_FLOAT_EQ(*(it - 3), 1.3);
  EXPECT_FLOAT_EQ(*(it - 2), 2.22);
  *(it - 3) = 13.31;
  EXPECT_FLOAT_EQ(*(it - 3), 13.31);
  EXPECT_FLOAT_EQ(*(it - 1), 3.111);
}

TEST(Array, End_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  auto it = s21_array.end();
  EXPECT_DOUBLE_EQ(*(it - 3), 1.123456);
  EXPECT_DOUBLE_EQ(*(it - 2), 2.222222);
  *(it - 3) = 1.654321;
  EXPECT_DOUBLE_EQ(*(it - 3), 1.654321);
  EXPECT_DOUBLE_EQ(*(it - 1), 3.987654);
}

TEST(Array, End_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_array.end();
  EXPECT_EQ(*(it - 5), 'a');
  EXPECT_EQ(*(it - 4), 'c');
  EXPECT_EQ(*(it - 3), 'b');
  *(it - 5) = '0';
  EXPECT_EQ(*(it - 5), '0');
  EXPECT_EQ(*(it - 2), 'x');
  EXPECT_EQ(*(it - 1), 'y');
}

TEST(Array, End_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  auto it = s21_array.end();
  EXPECT_EQ(*(it - 5), "Hey ");
  EXPECT_EQ(*(it - 4), "there!\n");
  EXPECT_EQ(*(it - 3), "It's a");
  *(it - 5) = "Hello ";
  EXPECT_EQ(*(it - 5), "Hello ");
  EXPECT_EQ(*(it - 2), " test ");
  EXPECT_EQ(*(it - 1), "string!\n");
}

// Const iterator end
TEST(Array, Cend_Int) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  auto it = s21_array.cend();
  EXPECT_EQ(*(it - 1), 1);
  EXPECT_EQ(*(it - 2), 2);
  EXPECT_EQ(*(it - 3), 3);
  EXPECT_EQ(*(it - 4), 4);
  EXPECT_EQ(*(it - 5), 5);
}

TEST(Array, Cend_Float) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  auto it = s21_array.cend();
  EXPECT_FLOAT_EQ(*(it - 3), 1.3);
  EXPECT_FLOAT_EQ(*(it - 2), 2.22);
  EXPECT_FLOAT_EQ(*(it - 1), 3.111);
}

TEST(Array, Cend_Double) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  auto it = s21_array.cend();
  EXPECT_DOUBLE_EQ(*(it - 3), 1.123456);
  EXPECT_DOUBLE_EQ(*(it - 2), 2.222222);
  EXPECT_DOUBLE_EQ(*(it - 1), 3.987654);
}

TEST(Array, Cend_Char) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_array.cend();
  EXPECT_EQ(*(it - 5), 'a');
  EXPECT_EQ(*(it - 4), 'c');
  EXPECT_EQ(*(it - 3), 'b');
  EXPECT_EQ(*(it - 2), 'x');
  EXPECT_EQ(*(it - 1), 'y');
}

TEST(Array, Cend_String) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  auto it = s21_array.cend();
  EXPECT_EQ(*(it - 5), "Hey ");
  EXPECT_EQ(*(it - 4), "there!\n");
  EXPECT_EQ(*(it - 3), "It's a");
  EXPECT_EQ(*(it - 2), " test ");
  EXPECT_EQ(*(it - 1), "string!\n");
}

// At, inside correct bounds
TEST(Array, At_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.at(0), 5);
  EXPECT_EQ(s21_array.at(1), 4);
  EXPECT_EQ(s21_array.at(2), 3);
  EXPECT_EQ(s21_array.at(3), 2);
  EXPECT_EQ(s21_array.at(4), 1);
}

TEST(Array, At_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array.at(0), 1.3);
  EXPECT_FLOAT_EQ(s21_array.at(1), 2.22);
  EXPECT_FLOAT_EQ(s21_array.at(2), 3.111);
}

TEST(Array, At_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array.at(0), 1.123456);
  EXPECT_DOUBLE_EQ(s21_array.at(1), 2.222222);
  EXPECT_DOUBLE_EQ(s21_array.at(2), 3.987654);
}

TEST(Array, At_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array.at(0), 'a');
  EXPECT_EQ(s21_array.at(1), 'c');
  EXPECT_EQ(s21_array.at(2), 'b');
  EXPECT_EQ(s21_array.at(3), 'x');
  EXPECT_EQ(s21_array.at(4), 'y');
}

TEST(Array, At_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(s21_array.at(0), "Hey ");
  EXPECT_EQ(s21_array.at(1), "there!\n");
  EXPECT_EQ(s21_array.at(2), "It's a");
  EXPECT_EQ(s21_array.at(3), " test ");
  EXPECT_EQ(s21_array.at(4), "string!\n");
}

// At, outside correct bounds
TEST(Array, At_Int_Wrong_Pos) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Float_Wrong_Pos) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Double_Wrong_Pos) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Char_Wrong_Pos) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_String_Wrong_Pos) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

// Const at, inside correct bounds
TEST(Array, At_Int_Const) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.at(0), 5);
  EXPECT_EQ(s21_array.at(1), 4);
  EXPECT_EQ(s21_array.at(2), 3);
  EXPECT_EQ(s21_array.at(3), 2);
  EXPECT_EQ(s21_array.at(4), 1);
}

TEST(Array, At_Float_Const) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array.at(0), 1.3);
  EXPECT_FLOAT_EQ(s21_array.at(1), 2.22);
  EXPECT_FLOAT_EQ(s21_array.at(2), 3.111);
}

TEST(Array, At_Double_Const) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array.at(0), 1.123456);
  EXPECT_DOUBLE_EQ(s21_array.at(1), 2.222222);
  EXPECT_DOUBLE_EQ(s21_array.at(2), 3.987654);
}

TEST(Array, At_Char_Const) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array.at(0), 'a');
  EXPECT_EQ(s21_array.at(1), 'c');
  EXPECT_EQ(s21_array.at(2), 'b');
  EXPECT_EQ(s21_array.at(3), 'x');
  EXPECT_EQ(s21_array.at(4), 'y');
}

TEST(Array, At_String_Const) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_EQ(s21_array.at(0), "Hey ");
  EXPECT_EQ(s21_array.at(1), "there!\n");
  EXPECT_EQ(s21_array.at(2), "It's a");
  EXPECT_EQ(s21_array.at(3), " test ");
  EXPECT_EQ(s21_array.at(4), "string!\n");
}

// Front
TEST(Array, Front_Int) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.front(), 5);
}

TEST(Array, Front_Float) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array.front(), 1.3);
}

TEST(Array, Front_Double) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array.front(), 1.123456);
}

TEST(Array, Front_Char) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array.front(), 'a');
}

TEST(Array, Front_String) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_EQ(s21_array.front(), "Hey ");
}

// Back
TEST(Array, Back_Int) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.back(), 1);
}

TEST(Array, Back_Float) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_array.back(), 3.111);
}

TEST(Array, Back_Double) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_array.back(), 3.987654);
}

TEST(Array, Back_Char) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_array.back(), 'y');
}

TEST(Array, Back_String) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_EQ(s21_array.back(), "string!\n");
}

// Data
TEST(Array, Data_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  std::array<int, 5> std_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(*s21_array.data(), *std_array.data());
}

TEST(Array, Data_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  std::array<float, 3> std_array = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(*s21_array.data(), *std_array.data());
}

TEST(Array, Data_Double) {
  s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  std::array<double, 3> std_array = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(*s21_array.data(), *std_array.data());
}

TEST(Array, Data_Char) {
  s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  std::array<char, 5> std_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(*s21_array.data(), *std_array.data());
}

TEST(Array, Data_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  std::array<std::string, 5> std_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  EXPECT_EQ(*s21_array.data(), *std_array.data());
}

// Const at, outside correct bounds
TEST(Array, At_Int_Wrong_Pos_Const) {
  const s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Float_Wrong_Pos_Const) {
  const s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Double_Wrong_Pos_Const) {
  const s21::array<double, 3> s21_array = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_Char_Wrong_Pos_Const) {
  const s21::array<char, 5> s21_array = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

TEST(Array, At_String_Wrong_Pos_Const) {
  const s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                                " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_array.at(-1));
  EXPECT_ANY_THROW(s21_array.at(5));
  EXPECT_ANY_THROW(s21_array.at(15));
}

// Empty
TEST(Array, Empty_No_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_FALSE(s21_array.empty());
}

TEST(Array, Empty_No_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_FALSE(s21_array.empty());
}

TEST(Array, Empty_No_Double) {
  s21::array<double, 4> s21_array = {1.123456, 2.222222, 3.987654, 8.327862};
  EXPECT_FALSE(s21_array.empty());
}

TEST(Array, Empty_No_Char) {
  s21::array<char, 6> s21_array = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_FALSE(s21_array.empty());
}

TEST(Array, Empty_No_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n"};
  EXPECT_FALSE(s21_array.empty());
}

TEST(Array, Empty_Int) {
  // -Wpedantic ругается, что низя создавать нулевые массивы.
  s21::array<int, 0> s21_array;
  EXPECT_TRUE(s21_array.empty());
}

// Size
TEST(Array, Size_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.size(), 5);
}

TEST(Array, Size_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_array.size(), 3);
}

TEST(Array, Size_Double) {
  s21::array<double, 4> s21_array = {1.123456, 2.222222, 3.987654, 8.327862};
  EXPECT_EQ(s21_array.size(), 4);
}

TEST(Array, Size_Char) {
  s21::array<char, 6> s21_array = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_EQ(s21_array.size(), 6);
}

TEST(Array, Size_String) {
  s21::array<std::string, 2> s21_array = {"Hey ", "there!\n"};
  EXPECT_EQ(s21_array.size(), 2);
}

TEST(Array, Size_Int_Empty) {
  // -Wpedantic ругается, что низя создавать нулевые массивы.
  s21::array<int, 0> s21_array;
  EXPECT_EQ(s21_array.size(), 0);
}

// Max_size
TEST(Array, Max_Size_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_array.max_size(), 5);
}

TEST(Array, Max_Size_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_array.max_size(), 3);
}

TEST(Array, Max_Size_Double) {
  s21::array<double, 4> s21_array = {1.123456, 2.222222, 3.987654, 8.327862};
  EXPECT_EQ(s21_array.max_size(), 4);
}

TEST(Array, Max_Size_Char) {
  s21::array<char, 6> s21_array = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_EQ(s21_array.max_size(), 6);
}

TEST(Array, Max_Size_String) {
  s21::array<std::string, 2> s21_array = {"Hey ", "there!\n"};
  EXPECT_EQ(s21_array.max_size(), 2);
}

TEST(Array, Max_Size_Int_Empty) {
  // -Wpedantic ругается, что низя создавать нулевые массивы.
  s21::array<int, 0> s21_array;
  EXPECT_EQ(s21_array.max_size(), 0);
}

// Swap
TEST(Array, Swap_Int) {
  s21::array<int, 5> s21_array_1 = {5, 4, 3, 2, 1};
  s21::array<int, 5> s21_array_2 = {1, 2, 3, 4, 5};
  s21_array_1.swap(s21_array_2);
  for (size_t i = 0; i != s21_array_1.size(); ++i) {
    EXPECT_EQ(s21_array_1[i], static_cast<int>(i) + 1);
  }
  int val = 5;
  for (size_t i = 0; i != s21_array_2.size(); ++i) {
    EXPECT_EQ(s21_array_2[i], val--);
  }
}

TEST(Array, Swap_Float) {
  s21::array<float, 3> s21_array_1 = {1.3, 2.22, 3.111};
  s21::array<float, 3> s21_array_2 = {314.7, -0.567, 9.456};
  std::array<float, 3> std_array_2 = {1.3, 2.22, 3.111};
  std::array<float, 3> std_array_1 = {314.7, -0.567, 9.456};
  s21_array_1.swap(s21_array_2);
  for (size_t i = 0; i != s21_array_1.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array_1[i], std_array_1[i]);
  }
  for (size_t i = 0; i != s21_array_2.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array_2[i], std_array_2[i]);
  }
}

TEST(Array, Swap_Double) {
  s21::array<double, 4> s21_array_1 = {1.123456, 2.222222, 3.987654, 8.327862};
  s21::array<double, 4> s21_array_2 = {9.1234567, 0.678293, -11.35376,
                                       678.2784689};
  std::array<double, 4> std_array_2 = {1.123456, 2.222222, 3.987654, 8.327862};
  std::array<double, 4> std_array_1 = {9.1234567, 0.678293, -11.35376,
                                       678.2784689};
  s21_array_1.swap(s21_array_2);
  for (size_t i = 0; i != s21_array_1.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array_1[i], std_array_1[i]);
  }
  for (size_t i = 0; i != s21_array_2.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array_2[i], std_array_2[i]);
  }
}

TEST(Array, Swap_Char) {
  s21::array<char, 6> s21_array_1 = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21::array<char, 6> s21_array_2 = {'9', '0', '1', 't', '7', '?'};
  std::array<char, 6> std_array_2 = {'a', 'c', 'b', 'x', 'y', 'z'};
  std::array<char, 6> std_array_1 = {'9', '0', '1', 't', '7', '?'};
  s21_array_1.swap(s21_array_2);
  for (size_t i = 0; i != s21_array_1.size(); ++i) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
  }
  for (size_t i = 0; i != s21_array_2.size(); ++i) {
    EXPECT_EQ(s21_array_2[i], std_array_2[i]);
  }
}

TEST(Array, Swap_String) {
  s21::array<std::string, 5> s21_array_1 = {"Hey ", "there!\n", "It's a",
                                            " test ", "string!\n"};
  s21::array<std::string, 5> s21_array_2 = {"It's ", "still", " a ", "test ",
                                            "string!\n"};
  std::array<std::string, 5> std_array_2 = {"Hey ", "there!\n", "It's a",
                                            " test ", "string!\n"};
  std::array<std::string, 5> std_array_1 = {"It's ", "still", " a ", "test ",
                                            "string!\n"};
  s21_array_1.swap(s21_array_2);
  for (size_t i = 0; i != s21_array_1.size(); ++i) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
  }
  for (size_t i = 0; i != s21_array_2.size(); ++i) {
    EXPECT_EQ(s21_array_2[i], std_array_2[i]);
  }
}

// Fill
TEST(Array, Fill_Int) {
  s21::array<int, 5> s21_array = {5, 4, 3, 2, 1};
  const int value = 999;
  s21_array.fill(value);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], value);
  }
}

TEST(Array, Fill_Float) {
  s21::array<float, 3> s21_array = {1.3, 2.22, 3.111};
  const float value = 0.999;
  s21_array.fill(value);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_array[i], value);
  }
}

TEST(Array, Fill_Double) {
  s21::array<double, 4> s21_array = {1.123456, 2.222222, 3.987654, 8.327862};
  const double value = -9.87654321;
  s21_array.fill(value);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_array[i], value);
  }
}

TEST(Array, Fill_Char) {
  s21::array<char, 6> s21_array = {'a', 'c', 'b', 'x', 'y', 'z'};
  const char value = '?';
  s21_array.fill(value);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], value);
  }
}

TEST(Array, Fill_String) {
  s21::array<std::string, 5> s21_array = {"Hey ", "there!\n", "It's a",
                                          " test ", "string!\n"};
  const std::string value = "Winter is coming!\n";
  s21_array.fill(value);
  for (size_t i = 0; i != s21_array.size(); ++i) {
    EXPECT_EQ(s21_array[i], value);
  }
}
