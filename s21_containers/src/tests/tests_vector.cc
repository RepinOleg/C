#include <vector>

#include "test_containers.h"

// Default constructor
TEST(Vector, Constructor_Default_Int) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, Constructor_Default_Float) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, Constructor_Default_Double) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, Constructor_Default_Char) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(Vector, Constructor_Default_String) {
  s21::vector<std::string> s21_vector;
  std::vector<std::string> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

// Size_t constructor
TEST(Vector, Constructor_Size_N_Int) {
  s21::vector<int> s21_vector(5);
  std::vector<int> std_vector(5);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(Vector, Constructor_Size_N_Float) {
  s21::vector<float> s21_vector(18);
  std::vector<float> std_vector(18);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(Vector, Constructor_Size_N_Double) {
  s21::vector<double> s21_vector(103);
  std::vector<double> std_vector(103);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(Vector, Constructor_Size_N_Char) {
  s21::vector<char> s21_vector(512);
  std::vector<char> std_vector(512);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(Vector, Constructor_Size_N_String) {
  s21::vector<std::string> s21_vector(309);
  std::vector<std::string> std_vector(309);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

// Initializer list constructor
TEST(Vector, Constructor_List_Int) {
  s21::vector<int> s21_vector = {1, 2, 3, 45, 111};
  std::vector<int> std_vector = {1, 2, 3, 45, 111};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_List_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  std::vector<float> std_vector = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_List_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.876543};
  std::vector<double> std_vector = {1.123456, 2.222222, 3.987654, 999.876543};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_List_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  std::vector<char> std_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_List_String) {
  s21::vector<std::string> s21_vector = {
      "Hey ", "there!", "\n", "It's a", " real cool", " test ", "string!\n"};
  std::vector<std::string> std_vector = {
      "Hey ", "there!", "\n", "It's a", " real cool", " test ", "string!\n"};
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], std_vector[i]);
  }
}

// Copy constructor
TEST(Vector, Constructor_Copy_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21::vector<int> s21_copy_vector(s21_vector);
  EXPECT_EQ(s21_vector.size(), s21_copy_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], s21_copy_vector[i]);
  }
}

TEST(Vector, Constructor_Copy_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21::vector<float> s21_copy_vector(s21_vector);
  EXPECT_EQ(s21_vector.size(), 3);
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_vector[i], s21_copy_vector[i]);
  }
}

TEST(Vector, Constructor_Copy_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  s21::vector<double> s21_copy_vector(s21_vector);
  EXPECT_EQ(s21_vector.size(), 3);
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_vector[i], s21_copy_vector[i]);
  }
}

TEST(Vector, Constructor_Copy_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  s21::vector<char> s21_copy_vector(s21_vector);
  EXPECT_EQ(s21_vector.size(), 5);
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], s21_copy_vector[i]);
  }
}

TEST(Vector, Constructor_Copy_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  s21::vector<std::string> s21_copy_vector(s21_vector);
  EXPECT_EQ(s21_vector.size(), 5);
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_EQ(s21_vector[i], s21_copy_vector[i]);
  }
}

// Move constructor
TEST(Vector, Constructor_Move_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21::vector<int> s21_move_vector(std::move(s21_vector));
  std::vector<int> std_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_move_vector.size(), 5);
  EXPECT_TRUE(s21_vector.empty());
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_Move_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21::vector<float> s21_move_vector(std::move(s21_vector));
  std::vector<float> std_vector = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_move_vector.size(), 3);
  EXPECT_TRUE(s21_vector.empty());
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_Move_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  s21::vector<double> s21_move_vector(std::move(s21_vector));
  std::vector<double> std_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_EQ(s21_move_vector.size(), 3);
  EXPECT_TRUE(s21_vector.empty());
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_Move_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  s21::vector<char> s21_move_vector(std::move(s21_vector));
  std::vector<char> std_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_move_vector.size(), 5);
  EXPECT_TRUE(s21_vector.empty());
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Constructor_Move_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  s21::vector<std::string> s21_move_vector(std::move(s21_vector));
  std::vector<std::string> std_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_EQ(s21_move_vector.size(), 5);
  EXPECT_TRUE(s21_vector.empty());
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

// Assignment + copy operator
TEST(Vector, Assign_Via_Copy_Operator_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21::vector<int> s21_copy_vector;
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_copy_vector.size(); ++i) {
    EXPECT_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

TEST(Vector, Assign_Via_Copy_Operator_Int2) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21::vector<int> s21_copy_vector = {33, 22, 11};
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_copy_vector.size(); ++i) {
    EXPECT_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

TEST(Vector, Assign_Via_Copy_Operator_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21::vector<float> s21_copy_vector;
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_vector.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

TEST(Vector, Assign_Via_Copy_Operator_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  s21::vector<double> s21_copy_vector;
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_copy_vector.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

TEST(Vector, Assign_Via_Copy_Operator_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  s21::vector<char> s21_copy_vector;
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_copy_vector.size(); ++i) {
    EXPECT_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

TEST(Vector, Assign_Via_Copy_Operator_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  s21::vector<std::string> s21_copy_vector;
  s21_copy_vector = s21_vector;
  EXPECT_EQ(s21_copy_vector.size(), s21_vector.size());
  for (size_t i = 0; i != s21_copy_vector.size(); ++i) {
    EXPECT_EQ(s21_copy_vector[i], s21_vector[i]);
  }
}

// Assignment + move operator
TEST(Vector, Assign_Via_Move_Operator_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21::vector<int> s21_move_vector;
  s21_move_vector = std::move(s21_vector);
  std::vector<int> std_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_move_vector.size(), 5);
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Assign_Via_Move_Operator_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21::vector<float> s21_move_vector;
  s21_move_vector = std::move(s21_vector);
  std::vector<float> std_vector = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_move_vector.size(), 3);
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Assign_Via_Move_Operator_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  s21::vector<double> s21_move_vector;
  s21_move_vector = std::move(s21_vector);
  std::vector<double> std_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_EQ(s21_move_vector.size(), 3);
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Assign_Via_Move_Operator_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  s21::vector<char> s21_move_vector;
  s21_move_vector = std::move(s21_vector);
  std::vector<char> std_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_move_vector.size(), 5);
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

TEST(Vector, Assign_Via_Move_Operator_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  s21::vector<std::string> s21_move_vector;
  s21_move_vector = std::move(s21_vector);
  std::vector<std::string> std_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_EQ(s21_move_vector.size(), 5);
  for (size_t i = 0; i != s21_move_vector.size(); ++i) {
    EXPECT_EQ(s21_move_vector[i], std_vector[i]);
  }
}

// Destructor
TEST(Vector, Destructor) {
  s21::vector<int> *s21_vector = new s21::vector<int>;
  delete s21_vector;
}

TEST(Vector, Destructor2) {
  s21::vector<int> *s21_vector = new s21::vector<int>{5, 4, 3, 2, 1};
  delete s21_vector;
}

// At, inside correct bounds
TEST(Vector, At_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector.at(0), 5);
  EXPECT_EQ(s21_vector.at(1), 4);
  EXPECT_EQ(s21_vector.at(2), 3);
  EXPECT_EQ(s21_vector.at(3), 2);
  EXPECT_EQ(s21_vector.at(4), 1);
}

TEST(Vector, At_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector.at(0), 1.3);
  EXPECT_FLOAT_EQ(s21_vector.at(1), 2.22);
  EXPECT_FLOAT_EQ(s21_vector.at(2), 3.111);
}

TEST(Vector, At_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector.at(0), 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector.at(1), 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector.at(2), 3.987654);
}

TEST(Vector, At_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector.at(0), 'a');
  EXPECT_EQ(s21_vector.at(1), 'c');
  EXPECT_EQ(s21_vector.at(2), 'b');
  EXPECT_EQ(s21_vector.at(3), 'x');
  EXPECT_EQ(s21_vector.at(4), 'y');
}

TEST(Vector, At_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_EQ(s21_vector.at(0), "Hey ");
  EXPECT_EQ(s21_vector.at(1), "there!\n");
  EXPECT_EQ(s21_vector.at(2), "It's a");
  EXPECT_EQ(s21_vector.at(3), " test ");
  EXPECT_EQ(s21_vector.at(4), "string!\n");
}

// At, outside correct bounds
TEST(Vector, At_Int_Wrong_Pos) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, At_Int_Wrong_Pos2) {
  s21::vector<int> s21_vector;
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, At_Float_Wrong_Pos) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, At_Double_Wrong_Pos) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, At_Char_Wrong_Pos) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, At_String_Wrong_Pos) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

// Const at, outside correct bounds
TEST(Vector, Const_At_Int_Wrong_Pos) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, Const_At_Int_Wrong_Pos2) {
  const s21::vector<int> s21_vector;
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, Const_At_Float_Wrong_Pos) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, Const_At_Double_Wrong_Pos) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, Const_At_Char_Wrong_Pos) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

TEST(Vector, Const_At_String_Wrong_Pos) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_vector.at(-1));
  EXPECT_ANY_THROW(s21_vector.at(5));
  EXPECT_ANY_THROW(s21_vector.at(15));
}

// Const at, inside correct bounds
TEST(Vector, At_Int_Const) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector.at(0), 5);
  EXPECT_EQ(s21_vector.at(1), 4);
  EXPECT_EQ(s21_vector.at(2), 3);
  EXPECT_EQ(s21_vector.at(3), 2);
  EXPECT_EQ(s21_vector.at(4), 1);
}

TEST(Vector, At_Float_Const) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector.at(0), 1.3);
  EXPECT_FLOAT_EQ(s21_vector.at(1), 2.22);
  EXPECT_FLOAT_EQ(s21_vector.at(2), 3.111);
}

TEST(Vector, At_Double_Const) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector.at(0), 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector.at(1), 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector.at(2), 3.987654);
}

TEST(Vector, At_Char_Const) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector.at(0), 'a');
  EXPECT_EQ(s21_vector.at(1), 'c');
  EXPECT_EQ(s21_vector.at(2), 'b');
  EXPECT_EQ(s21_vector.at(3), 'x');
  EXPECT_EQ(s21_vector.at(4), 'y');
}

TEST(Vector, At_String_Const) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_EQ(s21_vector.at(0), "Hey ");
  EXPECT_EQ(s21_vector.at(1), "there!\n");
  EXPECT_EQ(s21_vector.at(2), "It's a");
  EXPECT_EQ(s21_vector.at(3), " test ");
  EXPECT_EQ(s21_vector.at(4), "string!\n");
}

// Access operator, inside correct bounds
TEST(Vector, Access_Operator_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector[0], 5);
  EXPECT_EQ(s21_vector[1], 4);
  EXPECT_EQ(s21_vector[2], 3);
  EXPECT_EQ(s21_vector[3], 2);
  EXPECT_EQ(s21_vector[4], 1);
}

TEST(Vector, Access_Operator_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector[0], 1.3);
  EXPECT_FLOAT_EQ(s21_vector[1], 2.22);
  EXPECT_FLOAT_EQ(s21_vector[2], 3.111);
}

TEST(Vector, Access_Operator_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector[2], 3.987654);
}

TEST(Vector, Access_Operator_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector[0], 'a');
  EXPECT_EQ(s21_vector[1], 'c');
  EXPECT_EQ(s21_vector[2], 'b');
  EXPECT_EQ(s21_vector[3], 'x');
  EXPECT_EQ(s21_vector[4], 'y');
}

TEST(Vector, Access_Operator_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_EQ(s21_vector[0], "Hey ");
  EXPECT_EQ(s21_vector[1], "there!\n");
  EXPECT_EQ(s21_vector[2], "It's a");
  EXPECT_EQ(s21_vector[3], " test ");
  EXPECT_EQ(s21_vector[4], "string!\n");
}

// Access operator, outside correct bounds
TEST(Vector, Access_Operator_Int_Wrong_Pos) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Float_Wrong_Pos) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Double_Wrong_Pos) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Char_Wrong_Pos) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_String_Wrong_Pos) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

// Access const operator, inside correct bounds
TEST(Vector, Access_Operator_Int_Const) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector[0], 5);
  EXPECT_EQ(s21_vector[1], 4);
  EXPECT_EQ(s21_vector[2], 3);
  EXPECT_EQ(s21_vector[3], 2);
  EXPECT_EQ(s21_vector[4], 1);
}

TEST(Vector, Access_Operator_Float_Const) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector[0], 1.3);
  EXPECT_FLOAT_EQ(s21_vector[1], 2.22);
  EXPECT_FLOAT_EQ(s21_vector[2], 3.111);
}

TEST(Vector, Access_Operator_Double_Const) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector[2], 3.987654);
}

TEST(Vector, Access_Operator_Char_Const) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector[0], 'a');
  EXPECT_EQ(s21_vector[1], 'c');
  EXPECT_EQ(s21_vector[2], 'b');
  EXPECT_EQ(s21_vector[3], 'x');
  EXPECT_EQ(s21_vector[4], 'y');
}

TEST(Vector, Access_Operator_String_Const) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_EQ(s21_vector[0], "Hey ");
  EXPECT_EQ(s21_vector[1], "there!\n");
  EXPECT_EQ(s21_vector[2], "It's a");
  EXPECT_EQ(s21_vector[3], " test ");
  EXPECT_EQ(s21_vector[4], "string!\n");
}

// Const access operator, outside correct bounds
TEST(Vector, Access_Operator_Int_Wrong_Pos_Const) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Float_Wrong_Pos_Const) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Double_Wrong_Pos_Const) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_Char_Wrong_Pos_Const) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

TEST(Vector, Access_Operator_String_Wrong_Pos_Const) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_ANY_THROW(s21_vector[-1]);
  EXPECT_ANY_THROW(s21_vector[5]);
  EXPECT_ANY_THROW(s21_vector[15]);
}

// Front
TEST(Vector, Front_Int) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector.front(), 5);
}

TEST(Vector, Front_Float) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector.front(), 1.3);
}

TEST(Vector, Front_Double) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector.front(), 1.123456);
}

TEST(Vector, Front_Char) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector.front(), 'a');
}

TEST(Vector, Front_String) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_EQ(s21_vector.front(), "Hey ");
}

// Back
TEST(Vector, Back_Int) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector.back(), 1);
}

TEST(Vector, Back_Float) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(s21_vector.back(), 3.111);
}

TEST(Vector, Back_Double) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(s21_vector.back(), 3.987654);
}

TEST(Vector, Back_Char) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(s21_vector.back(), 'y');
}

TEST(Vector, Back_String) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  EXPECT_EQ(s21_vector.back(), "string!\n");
}

// Data
TEST(Vector, Data_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  std::vector<int> std_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(Vector, Data_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  std::vector<float> std_vector = {1.3, 2.22, 3.111};
  EXPECT_FLOAT_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(Vector, Data_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  std::vector<double> std_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_DOUBLE_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(Vector, Data_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  std::vector<char> std_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(Vector, Data_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  std::vector<std::string> std_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_EQ(*s21_vector.data(), *std_vector.data());
}

// Iterator begin
TEST(Vector, Begin_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto it = s21_vector.begin();
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(*(it + 1), 4);
  EXPECT_EQ(*(it + 2), 3);
  *it = 1;
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*(it + 3), 2);
  EXPECT_EQ(*(it + 4), 1);
}

TEST(Vector, Begin_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto it = s21_vector.begin();
  EXPECT_FLOAT_EQ(*it, 1.3);
  EXPECT_FLOAT_EQ(*(it + 1), 2.22);
  *it = 13.31;
  EXPECT_FLOAT_EQ(*it, 13.31);
  EXPECT_FLOAT_EQ(*(it + 2), 3.111);
}

TEST(Vector, Begin_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  auto it = s21_vector.begin();
  EXPECT_DOUBLE_EQ(*it, 1.123456);
  EXPECT_DOUBLE_EQ(*(it + 1), 2.222222);
  *it = 1.654321;
  EXPECT_DOUBLE_EQ(*it, 1.654321);
  EXPECT_DOUBLE_EQ(*(it + 2), 3.987654);
}

TEST(Vector, Begin_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_vector.begin();
  EXPECT_EQ(*it, 'a');
  EXPECT_EQ(*(it + 1), 'c');
  EXPECT_EQ(*(it + 2), 'b');
  *it = '0';
  EXPECT_EQ(*it, '0');
  EXPECT_EQ(*(it + 3), 'x');
  EXPECT_EQ(*(it + 4), 'y');
}

TEST(Vector, Begin_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  auto it = s21_vector.begin();
  EXPECT_EQ(*it, "Hey ");
  EXPECT_EQ(*(it + 1), "there!\n");
  EXPECT_EQ(*(it + 2), "It's a");
  *it = "Hello ";
  EXPECT_EQ(*it, "Hello ");
  EXPECT_EQ(*(it + 3), " test ");
  EXPECT_EQ(*(it + 4), "string!\n");
}

// Const iterator cbegin
TEST(Vector, Cbegin_Int) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto it = s21_vector.cbegin();
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(*(it + 1), 4);
  EXPECT_EQ(*(it + 2), 3);
  EXPECT_EQ(*(it + 3), 2);
  EXPECT_EQ(*(it + 4), 1);
}

TEST(Vector, Cbegin_Float) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto it = s21_vector.cbegin();
  EXPECT_FLOAT_EQ(*it, 1.3);
  EXPECT_FLOAT_EQ(*(it + 1), 2.22);
  EXPECT_FLOAT_EQ(*(it + 2), 3.111);
}

TEST(Vector, Cbegin_Double) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  auto it = s21_vector.cbegin();
  EXPECT_DOUBLE_EQ(*it, 1.123456);
  EXPECT_DOUBLE_EQ(*(it + 1), 2.222222);
  EXPECT_DOUBLE_EQ(*(it + 2), 3.987654);
}

TEST(Vector, Cbegin_Char) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_vector.cbegin();
  EXPECT_EQ(*it, 'a');
  EXPECT_EQ(*(it + 1), 'c');
  EXPECT_EQ(*(it + 2), 'b');
  EXPECT_EQ(*(it + 3), 'x');
  EXPECT_EQ(*(it + 4), 'y');
}

TEST(Vector, Cbegin_String) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  auto it = s21_vector.cbegin();
  EXPECT_EQ(*it, "Hey ");
  EXPECT_EQ(*(it + 1), "there!\n");
  EXPECT_EQ(*(it + 2), "It's a");
  EXPECT_EQ(*(it + 3), " test ");
  EXPECT_EQ(*(it + 4), "string!\n");
}

// Iterator end
TEST(Vector, End_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto it = s21_vector.end();
  EXPECT_NE(s21_vector.begin(), it);
}

TEST(Vector, End_Int2) {
  s21::vector<int> s21_vector;
  auto it = s21_vector.end();
  EXPECT_EQ(s21_vector.begin(), it);
}

TEST(Vector, End_Int3) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto it = s21_vector.end();
  auto beg = s21_vector.begin();
  EXPECT_EQ(it, beg + 5);
}

TEST(Vector, End_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto it = s21_vector.end();
  EXPECT_NE(s21_vector.begin(), it);
}

TEST(Vector, End_Float2) {
  s21::vector<float> s21_vector;
  auto it = s21_vector.end();
  EXPECT_EQ(s21_vector.begin(), it);
}

TEST(Vector, End_Float3) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto it = s21_vector.end();
  auto beg = s21_vector.begin();
  EXPECT_EQ(it, beg + 3);
}

TEST(Vector, End_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  auto it = s21_vector.end();
  EXPECT_NE(s21_vector.begin(), it);
}

TEST(Vector, End_Double2) {
  s21::vector<double> s21_vector;
  auto it = s21_vector.end();
  EXPECT_EQ(s21_vector.begin(), it);
}

TEST(Vector, End_Double3) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  auto it = s21_vector.end();
  auto beg = s21_vector.begin();
  EXPECT_EQ(it, beg + 3);
}

TEST(Vector, End_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_vector.end();
  EXPECT_NE(s21_vector.begin(), it);
}

TEST(Vector, End_Char2) {
  s21::vector<char> s21_vector;
  auto it = s21_vector.end();
  EXPECT_EQ(s21_vector.begin(), it);
}

TEST(Vector, End_Char3) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  auto it = s21_vector.end();
  auto beg = s21_vector.begin();
  EXPECT_EQ(it, beg + 5);
}

TEST(Vector, End_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  auto it = s21_vector.end();
  EXPECT_NE(s21_vector.begin(), it);
}

TEST(Vector, End_String2) {
  s21::vector<std::string> s21_vector;
  auto it = s21_vector.end();
  EXPECT_EQ(s21_vector.begin(), it);
}

TEST(Vector, End_String3) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  auto it = s21_vector.end();
  auto beg = s21_vector.begin();
  EXPECT_EQ(it, beg + 5);
}

// Const iterator end
TEST(Vector, End_Int_Const) {
  const s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto it = s21_vector.cend();
  auto beg = s21_vector.cbegin();
  EXPECT_EQ(it, beg + 5);
}

TEST(Vector, End_Int_Const2) {
  const s21::vector<int> s21_vector;
  const auto it = s21_vector.cend();
  EXPECT_EQ(s21_vector.cbegin(), it);
}

TEST(Vector, End_Float_Const) {
  const s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  const auto it = s21_vector.cend();
  auto beg = s21_vector.cbegin();
  EXPECT_EQ(it, beg + 3);
}

TEST(Vector, End_Float_Const2) {
  const s21::vector<float> s21_vector;
  const auto it = s21_vector.cend();
  EXPECT_EQ(s21_vector.cbegin(), it);
}

TEST(Vector, End_Double_Const) {
  const s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  const auto it = s21_vector.cend();
  auto beg = s21_vector.cbegin();
  EXPECT_EQ(it, beg + 3);
}

TEST(Vector, End_Double_Const2) {
  const s21::vector<double> s21_vector;
  auto it = s21_vector.cend();
  EXPECT_EQ(s21_vector.cbegin(), it);
}

TEST(Vector, End_Char_Const) {
  const s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  const auto it = s21_vector.cend();
  auto beg = s21_vector.cbegin();
  EXPECT_EQ(it, beg + 5);
}

TEST(Vector, End_Char_Const2) {
  const s21::vector<char> s21_vector;
  const auto it = s21_vector.cend();
  EXPECT_EQ(s21_vector.cbegin(), it);
}

TEST(Vector, End_String_Const) {
  const s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a",
                                               " test ", "string!\n"};
  const auto it = s21_vector.cend();
  auto beg = s21_vector.cbegin();
  EXPECT_EQ(it, beg + 5);
}

TEST(Vector, End_String_Const2) {
  const s21::vector<std::string> s21_vector;
  const auto it = s21_vector.cend();
  EXPECT_EQ(s21_vector.cbegin(), it);
}

// Empty
TEST(Vector, Empty_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(Vector, Empty_Int2) {
  s21::vector<int> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

TEST(Vector, Empty_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(Vector, Empty_Float2) {
  s21::vector<float> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

TEST(Vector, Empty_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(Vector, Empty_Double2) {
  s21::vector<double> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

TEST(Vector, Empty_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y'};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(Vector, Empty_Char2) {
  s21::vector<char> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

TEST(Vector, Empty_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n", "It's a", " test ",
                                         "string!\n"};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(Vector, Empty_String2) {
  s21::vector<std::string> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

// Size
TEST(Vector, Size_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_EQ(s21_vector.size(), 5);
}

TEST(Vector, Size_Int2) {
  s21::vector<int> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

TEST(Vector, Size_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_EQ(s21_vector.size(), 3);
}

TEST(Vector, Size_Float2) {
  s21::vector<float> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

TEST(Vector, Size_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  EXPECT_EQ(s21_vector.size(), 4);
}

TEST(Vector, Size_Double2) {
  s21::vector<double> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

TEST(Vector, Size_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_EQ(s21_vector.size(), 6);
}

TEST(Vector, Size_Char2) {
  s21::vector<char> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

TEST(Vector, Size_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  EXPECT_EQ(s21_vector.size(), 2);
}

TEST(Vector, Size_String2) {
  s21::vector<std::string> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

// Max_size
TEST(Vector, Max_Size_Int) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

TEST(Vector, Max_Size_Float) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

TEST(Vector, Max_Size_Double) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

TEST(Vector, Max_Size_Char) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

TEST(Vector, Max_Size_String) {
  s21::vector<std::string> s21_vector;
  std::vector<std::string> std_vector;
  EXPECT_EQ(s21_vector.max_size(), std_vector.max_size());
}

// Reserve
TEST(Vector, Reserve_Int) {
  s21::vector<int> s21_vector;

  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(Vector, Reserve_Int2) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity - 2;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(Vector, Reserve_Int3) {
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5};
  size_t newCapacity = SIZE_MAX / sizeof(int);
  EXPECT_ANY_THROW(s21_vector.reserve(newCapacity));
}

TEST(Vector, Reserve_Float) {
  s21::vector<float> s21_vector;
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(Vector, Reserve_Double) {
  s21::vector<double> s21_vector;
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(Vector, Reserve_Char) {
  s21::vector<char> s21_vector;
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(Vector, Reserve_String) {
  s21::vector<std::string> s21_vector;
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

// Capacity
TEST(Vector, Capacity_Int) {
  s21::vector<int> s21_vector;
  EXPECT_GE(s21_vector.capacity(), 0);
}

TEST(Vector, Capacity_Int2) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  EXPECT_GE(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Capacity_Float) {
  s21::vector<float> s21_vector;
  EXPECT_GE(s21_vector.capacity(), 0);
}

TEST(Vector, Capacity_Float2) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  EXPECT_GE(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Capacity_Double) {
  s21::vector<double> s21_vector;
  EXPECT_GE(s21_vector.capacity(), 0);
}

TEST(Vector, Capacity_Double2) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  EXPECT_GE(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Capacity_Char) {
  s21::vector<char> s21_vector;
  EXPECT_GE(s21_vector.capacity(), 0);
}

TEST(Vector, Capacity_Char2) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  EXPECT_GE(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Capacity_String) {
  s21::vector<std::string> s21_vector;
  EXPECT_GE(s21_vector.capacity(), 0);
}

TEST(Vector, Capacity_String2) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  EXPECT_GE(s21_vector.capacity(), s21_vector.size());
}

// Shrink to fit
TEST(Vector, Shrink_To_Fit_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GT(s21_vector.capacity(), s21_vector.size());
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Shrink_To_Fit_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GT(s21_vector.capacity(), s21_vector.size());
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Shrink_To_Fit_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GT(s21_vector.capacity(), s21_vector.size());
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Shrink_To_Fit_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GT(s21_vector.capacity(), s21_vector.size());
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
}

TEST(Vector, Shrink_To_Fit_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GT(s21_vector.capacity(), s21_vector.size());
  s21_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), s21_vector.size());
}

// Clear
TEST(Vector, Clear_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21_vector.clear();
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.begin(), s21_vector.end());
}

TEST(Vector, Clear_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21_vector.clear();
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.begin(), s21_vector.end());
}

TEST(Vector, Clear_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  s21_vector.clear();
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.begin(), s21_vector.end());
}

TEST(Vector, Clear_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21_vector.clear();
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.begin(), s21_vector.end());
}

TEST(Vector, Clear_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  s21_vector.clear();
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.begin(), s21_vector.end());
}

// Insert
TEST(Vector, Insert_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto pos = s21_vector.begin();
  ++pos;
  ++pos;
  s21_vector.insert(pos, 6);  // {5, 4, 6, 3, 2, 1}
  EXPECT_EQ(s21_vector.size(), 6);
  EXPECT_EQ(s21_vector[0], 5);
  EXPECT_EQ(s21_vector[1], 4);
  EXPECT_EQ(s21_vector[2], 6);
  EXPECT_EQ(s21_vector[3], 3);
  EXPECT_EQ(s21_vector[4], 2);
  EXPECT_EQ(s21_vector[5], 1);
}

TEST(Vector, Insert_Int2) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto pos = s21_vector.begin() + 8;
  EXPECT_ANY_THROW(s21_vector.insert(pos, 6));
}

TEST(Vector, Insert_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto pos = s21_vector.begin();
  ++pos;
  s21_vector.insert(pos, -11.567);
  EXPECT_FLOAT_EQ(s21_vector.size(), 4);
  EXPECT_FLOAT_EQ(s21_vector[0], 1.3);
  EXPECT_FLOAT_EQ(s21_vector[1], -11.567);
  EXPECT_FLOAT_EQ(s21_vector[2], 2.22);
  EXPECT_FLOAT_EQ(s21_vector[3], 3.111);
}

TEST(Vector, Insert_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  auto pos = s21_vector.end();
  s21_vector.insert(pos, -11.1111567);
  EXPECT_EQ(s21_vector.size(), 5);
  EXPECT_DOUBLE_EQ(s21_vector[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector[2], 3.987654);
  EXPECT_DOUBLE_EQ(s21_vector[3], 999.83756556);
  EXPECT_DOUBLE_EQ(s21_vector[4], -11.1111567);
}

TEST(Vector, Insert_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  auto pos = s21_vector.begin();
  ++pos;
  ++pos;
  ++pos;
  s21_vector.insert(pos, 'w');
  EXPECT_EQ(s21_vector.size(), 7);
  EXPECT_EQ(s21_vector[0], 'a');
  EXPECT_EQ(s21_vector[1], 'c');
  EXPECT_EQ(s21_vector[2], 'b');
  EXPECT_EQ(s21_vector[3], 'w');
  EXPECT_EQ(s21_vector[4], 'x');
  EXPECT_EQ(s21_vector[5], 'y');
  EXPECT_EQ(s21_vector[6], 'z');
}

TEST(Vector, Insert_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there"};
  auto pos = s21_vector.end();
  s21_vector.insert(pos, ", beautiful!\n");
  EXPECT_EQ(s21_vector.size(), 3);
  EXPECT_EQ(s21_vector[0], "Hey ");
  EXPECT_EQ(s21_vector[1], "there");
  EXPECT_EQ(s21_vector[2], ", beautiful!\n");
}

// Erase
TEST(Vector, Erase_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto pos = s21_vector.begin();
  ++pos;
  s21_vector.erase(pos);
  EXPECT_EQ(s21_vector.size(), 4);
  EXPECT_EQ(s21_vector[1], 3);
}

TEST(Vector, Erase_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  auto pos = s21_vector.begin();
  ++pos;
  ++pos;
  s21_vector.erase(pos);
  EXPECT_EQ(s21_vector.size(), 2);
  EXPECT_EQ(s21_vector.begin() + 2, s21_vector.end());
}

TEST(Vector, Erase_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  auto pos = s21_vector.begin();
  s21_vector.erase(pos);
  EXPECT_EQ(s21_vector.size(), 3);
  EXPECT_EQ(s21_vector[0], 2.222222);
}

TEST(Vector, Erase_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  auto pos = s21_vector.begin();
  ++pos;
  ++pos;
  ++pos;
  ++pos;
  s21_vector.erase(pos);
  EXPECT_EQ(s21_vector.size(), 5);
  EXPECT_EQ(s21_vector[4], 'z');
}

TEST(Vector, Erase_String) {
  s21::vector<std::string> s21_vector = {"Hey there!\n"};
  auto pos = s21_vector.begin();
  s21_vector.erase(pos);
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_TRUE(s21_vector.empty());
}

// Push back
TEST(Vector, Push_Back_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21_vector.push_back(-1);
  EXPECT_EQ(s21_vector.size(), 6);
  EXPECT_EQ(s21_vector[5], -1);
}

TEST(Vector, Push_Back_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21_vector.push_back(99.2462);
  EXPECT_EQ(s21_vector.size(), 4);
  EXPECT_FLOAT_EQ(s21_vector[3], 99.2462);
}

TEST(Vector, Push_Back_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  s21_vector.push_back(-13426.3684545297);
  EXPECT_EQ(s21_vector.size(), 5);
  EXPECT_DOUBLE_EQ(s21_vector[4], -13426.3684545297);
}

TEST(Vector, Push_Back_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21_vector.push_back('w');
  EXPECT_EQ(s21_vector.size(), 7);
  EXPECT_EQ(s21_vector[6], 'w');
}

TEST(Vector, Push_Back_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  s21_vector.push_back("How u doing?\n");
  EXPECT_EQ(s21_vector.size(), 3);
  EXPECT_EQ(s21_vector[2], "How u doing?\n");
}

// Pop back
TEST(Vector, Pop_Back_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), 4);
}

TEST(Vector, Pop_Back_Float) {
  s21::vector<float> s21_vector = {1.3, 2.22, 3.111};
  s21_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), 2);
}

TEST(Vector, Pop_Back_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  s21_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), 3);
}

TEST(Vector, Pop_Back_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), 5);
}

TEST(Vector, Pop_Back_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  s21_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), 1);
}

// Swap
TEST(Vector, Swap_Int) {
  s21::vector<int> s21_vector_1 = {5, 4, 3, 2, 1};
  s21::vector<int> s21_vector_2 = {1, 2, 3, 4, 5};
  s21_vector_1.swap(s21_vector_2);
  for (size_t i = 0; i != s21_vector_1.size(); ++i) {
    EXPECT_EQ(s21_vector_1[i], static_cast<int>(i) + 1);
  }
  int val = 5;
  for (size_t i = 0; i != s21_vector_2.size(); ++i) {
    EXPECT_EQ(s21_vector_2[i], val--);
  }
}

TEST(Vector, Swap_Float) {
  s21::vector<float> s21_vector_1 = {1.3, 2.22, 3.111};
  s21::vector<float> s21_vector_2 = {314.7, -0.567, 9.456};
  std::vector<float> std_vector_2 = {1.3, 2.22, 3.111};
  std::vector<float> std_vector_1 = {314.7, -0.567, 9.456};
  s21_vector_1.swap(s21_vector_2);
  for (size_t i = 0; i != s21_vector_1.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_vector_1[i], std_vector_1[i]);
  }
  for (size_t i = 0; i != s21_vector_2.size(); ++i) {
    EXPECT_FLOAT_EQ(s21_vector_2[i], std_vector_2[i]);
  }
}

TEST(Vector, Swap_Double) {
  s21::vector<double> s21_vector_1 = {1.123456, 2.222222, 3.987654, 8.327862};
  s21::vector<double> s21_vector_2 = {9.1234567, 0.678293, -11.35376,
                                      678.2784689};
  std::vector<double> std_vector_2 = {1.123456, 2.222222, 3.987654, 8.327862};
  std::vector<double> std_vector_1 = {9.1234567, 0.678293, -11.35376,
                                      678.2784689};
  s21_vector_1.swap(s21_vector_2);
  for (size_t i = 0; i != s21_vector_1.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_vector_1[i], std_vector_1[i]);
  }
  for (size_t i = 0; i != s21_vector_2.size(); ++i) {
    EXPECT_DOUBLE_EQ(s21_vector_2[i], std_vector_2[i]);
  }
}

TEST(Vector, Swap_Char) {
  s21::vector<char> s21_vector_1 = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21::vector<char> s21_vector_2 = {'9', '0', '1', 't', '7', '?'};
  std::vector<char> std_vector_2 = {'a', 'c', 'b', 'x', 'y', 'z'};
  std::vector<char> std_vector_1 = {'9', '0', '1', 't', '7', '?'};
  s21_vector_1.swap(s21_vector_2);
  for (size_t i = 0; i != s21_vector_1.size(); ++i) {
    EXPECT_EQ(s21_vector_1[i], std_vector_1[i]);
  }
  for (size_t i = 0; i != s21_vector_2.size(); ++i) {
    EXPECT_EQ(s21_vector_2[i], std_vector_2[i]);
  }
}

TEST(Vector, Swap_String) {
  s21::vector<std::string> s21_vector_1 = {"Hey ", "there!\n", "It's a",
                                           " test ", "string!\n"};
  s21::vector<std::string> s21_vector_2 = {"It's ", "still", " a ", "test ",
                                           "string!\n"};
  std::vector<std::string> std_vector_2 = {"Hey ", "there!\n", "It's a",
                                           " test ", "string!\n"};
  std::vector<std::string> std_vector_1 = {"It's ", "still", " a ", "test ",
                                           "string!\n"};
  s21_vector_1.swap(s21_vector_2);
  for (size_t i = 0; i != s21_vector_1.size(); ++i) {
    EXPECT_EQ(s21_vector_1[i], std_vector_1[i]);
  }
  for (size_t i = 0; i != s21_vector_2.size(); ++i) {
    EXPECT_EQ(s21_vector_2[i], std_vector_2[i]);
  }
}

// Insert many
TEST(Vector, Insert_Many_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  auto pos = s21_vector.cbegin();
  s21_vector.insert_many(pos, -1, -2, -3);
  EXPECT_EQ(s21_vector.size(), 8);
  EXPECT_EQ(s21_vector[0], -1);
  EXPECT_EQ(s21_vector[1], -2);
  EXPECT_EQ(s21_vector[2], -3);
  EXPECT_EQ(s21_vector[3], 5);
  EXPECT_EQ(s21_vector[4], 4);
  EXPECT_EQ(s21_vector[5], 3);
  EXPECT_EQ(s21_vector[6], 2);
  EXPECT_EQ(s21_vector[7], 1);
}

TEST(Vector, Insert_Many_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  auto pos = s21_vector.cbegin() + 3;
  s21_vector.insert_many(pos, -13426.3684545297, -3480.248768, 3789.37464298,
                         99999999.3862);
  EXPECT_EQ(s21_vector.size(), 8);
  EXPECT_DOUBLE_EQ(s21_vector[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector[2], 3.987654);
  EXPECT_DOUBLE_EQ(s21_vector[3], -13426.3684545297);
  EXPECT_DOUBLE_EQ(s21_vector[4], -3480.248768);
  EXPECT_DOUBLE_EQ(s21_vector[5], 3789.37464298);
  EXPECT_DOUBLE_EQ(s21_vector[6], 99999999.3862);
  EXPECT_DOUBLE_EQ(s21_vector[7], 999.83756556);
}

TEST(Vector, Insert_Many_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  auto pos = s21_vector.cend();
  s21_vector.insert_many(pos, 'w', 'v', 'u', 't', 's', 'r');
  EXPECT_EQ(s21_vector.size(), 12);
  EXPECT_EQ(s21_vector[0], 'a');
  EXPECT_EQ(s21_vector[1], 'c');
  EXPECT_EQ(s21_vector[2], 'b');
  EXPECT_EQ(s21_vector[3], 'x');
  EXPECT_EQ(s21_vector[4], 'y');
  EXPECT_EQ(s21_vector[5], 'z');
  EXPECT_EQ(s21_vector[6], 'w');
  EXPECT_EQ(s21_vector[7], 'v');
  EXPECT_EQ(s21_vector[8], 'u');
  EXPECT_EQ(s21_vector[9], 't');
  EXPECT_EQ(s21_vector[10], 's');
  EXPECT_EQ(s21_vector[11], 'r');
}

TEST(Vector, Insert_Many_String) {
  s21::vector<std::string> s21_vector = {"Hey, ", "there?\n"};
  auto pos = s21_vector.cbegin() + 1;
  s21_vector.insert_many(pos, "how u doing, ", "beautiful?", "\n",
                         "U alright ");
  EXPECT_EQ(s21_vector.size(), 6);
  EXPECT_EQ(s21_vector[0], "Hey, ");
  EXPECT_EQ(s21_vector[1], "how u doing, ");
  EXPECT_EQ(s21_vector[2], "beautiful?");
  EXPECT_EQ(s21_vector[3], "\n");
  EXPECT_EQ(s21_vector[4], "U alright ");
  EXPECT_EQ(s21_vector[5], "there?\n");
}

// Insert many back
TEST(Vector, Insert_Many_Back_Int) {
  s21::vector<int> s21_vector = {5, 4, 3, 2, 1};
  s21_vector.insert_many_back(-1, -2, -3);
  EXPECT_EQ(s21_vector.size(), 8);
  EXPECT_EQ(s21_vector[0], 5);
  EXPECT_EQ(s21_vector[1], 4);
  EXPECT_EQ(s21_vector[2], 3);
  EXPECT_EQ(s21_vector[3], 2);
  EXPECT_EQ(s21_vector[4], 1);
  EXPECT_EQ(s21_vector[5], -1);
  EXPECT_EQ(s21_vector[6], -2);
  EXPECT_EQ(s21_vector[7], -3);
}

TEST(Vector, Insert_Many_Back_Double) {
  s21::vector<double> s21_vector = {1.123456, 2.222222, 3.987654, 999.83756556};
  s21_vector.insert_many_back(-13426.3684545297, -3480.248768, 3789.37464298,
                              99999999.3862);
  EXPECT_EQ(s21_vector.size(), 8);
  EXPECT_DOUBLE_EQ(s21_vector[0], 1.123456);
  EXPECT_DOUBLE_EQ(s21_vector[1], 2.222222);
  EXPECT_DOUBLE_EQ(s21_vector[2], 3.987654);
  EXPECT_DOUBLE_EQ(s21_vector[3], 999.83756556);
  EXPECT_DOUBLE_EQ(s21_vector[4], -13426.3684545297);
  EXPECT_DOUBLE_EQ(s21_vector[5], -3480.248768);
  EXPECT_DOUBLE_EQ(s21_vector[6], 3789.37464298);
  EXPECT_DOUBLE_EQ(s21_vector[7], 99999999.3862);
}

TEST(Vector, Insert_Many_Back_Char) {
  s21::vector<char> s21_vector = {'a', 'c', 'b', 'x', 'y', 'z'};
  s21_vector.insert_many_back('w', 'v', 'u', 't', 's', 'r');
  EXPECT_EQ(s21_vector.size(), 12);
  EXPECT_EQ(s21_vector[0], 'a');
  EXPECT_EQ(s21_vector[1], 'c');
  EXPECT_EQ(s21_vector[2], 'b');
  EXPECT_EQ(s21_vector[3], 'x');
  EXPECT_EQ(s21_vector[4], 'y');
  EXPECT_EQ(s21_vector[5], 'z');
  EXPECT_EQ(s21_vector[6], 'w');
  EXPECT_EQ(s21_vector[7], 'v');
  EXPECT_EQ(s21_vector[8], 'u');
  EXPECT_EQ(s21_vector[9], 't');
  EXPECT_EQ(s21_vector[10], 's');
  EXPECT_EQ(s21_vector[11], 'r');
}

TEST(Vector, Insert_Many_Back_String) {
  s21::vector<std::string> s21_vector = {"Hey ", "there!\n"};
  s21_vector.insert_many_back("How u doing, ", "beautiful?", "\n");
  EXPECT_EQ(s21_vector.size(), 5);
  EXPECT_EQ(s21_vector[0], "Hey ");
  EXPECT_EQ(s21_vector[1], "there!\n");
  EXPECT_EQ(s21_vector[2], "How u doing, ");
  EXPECT_EQ(s21_vector[3], "beautiful?");
  EXPECT_EQ(s21_vector[4], "\n");
}
