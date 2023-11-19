#include <stack>

#include "test_containers.h"

TEST(Stack, Constructor_Default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Constructor_List) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack, Constructor_Copy) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_copy(s21_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  EXPECT_EQ(s21_stack_copy.top(), std_stack.top());
}

TEST(Stack, Constructor_Move) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_move(std::move(s21_stack));
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  EXPECT_EQ(s21_stack_move.top(), std_stack.top());
}

TEST(Stack, Operator_Copy) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_copy;
  s21_stack_copy = s21_stack;
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std::stack<int> std_stack_copy = std_stack;
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(Stack, Operator_Copy_2) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_copy = {5, 4, 3, 2, 1};
  s21_stack_copy = s21_stack;
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std::stack<int> std_stack_copy = std_stack;
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(Stack, Operator_Move) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_move;
  s21_stack_move = std::move(s21_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std::stack<int> std_stack_move = std::move(std_stack);
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(Stack, Operator_Move_2) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_move = {5, 4, 3, 2, 1};
  s21_stack_move = std::move(s21_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std::stack<int> std_stack_move = std::move(std_stack);
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(Stack, Top) {
  s21::stack<int> s21_stack = {1, 2, 3, 4, 5};
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Top_2) {
  s21::stack<int> s21_stack_int = {101, 202, 303};
  std::stack<int> std_stack_int;
  std_stack_int.push(101);
  std_stack_int.push(202);
  std_stack_int.push(303);
  s21::stack<double> s21_stack_double = {133.987f, -2.666f, 313.131f};
  std::stack<double> std_stack_double;
  std_stack_double.push(133.987f);
  std_stack_double.push(-2.666f);
  std_stack_double.push(313.131f);
  s21::stack<std::string> s21_stack_string = {"xyz", "vw", "rstu", "opq"};
  std::stack<std::string> std_stack_string;
  std_stack_string.push("xyz");
  std_stack_string.push("vw");
  std_stack_string.push("rstu");
  std_stack_string.push("opq");
  EXPECT_EQ(s21_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(s21_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(s21_stack_string.top(), std_stack_string.top());
}

TEST(Stack, Empty) {
  s21::stack<int> s21_stack = {1, 2, 3};
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
  std_stack.push(4);
  s21_stack.push(4);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
  std_stack.push(5);
  s21_stack.push(5);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Size) {
  s21::stack<int> s21_stack = {5, 4, 3, 2, 1};
  std::stack<int> std_stack;
  std_stack.push(5);
  std_stack.push(4);
  std_stack.push(3);
  std_stack.push(2);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, Push) {
  s21::stack<int> s21_stack = {10, 20, 30};
  std::stack<int> std_stack;
  std_stack.push(10);
  std_stack.push(20);
  std_stack.push(30);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  std_stack.push(44);
  s21_stack.push(44);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  std_stack.push(58);
  s21_stack.push(58);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack, Pop) {
  s21::stack<int> s21_stack = {103, 202, 301};
  std::stack<int> std_stack;
  std_stack.push(103);
  std_stack.push(202);
  std_stack.push(301);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  std_stack.push(144);
  s21_stack.push(144);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  std_stack.push(589);
  s21_stack.push(589);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Swap) {
  s21::stack<int> s21_stack_1 = {1, 2, 3, 4, 5};
  s21::stack<int> s21_stack_2 = {5, 4, 3, 2, 1};
  std::stack<int> std_stack_1;
  std::stack<int> std_stack_2;
  std_stack_1.push(5);
  std_stack_1.push(4);
  std_stack_1.push(3);
  std_stack_1.push(2);
  std_stack_1.push(1);
  std_stack_2.push(1);
  std_stack_2.push(2);
  std_stack_2.push(3);
  std_stack_2.push(4);
  std_stack_2.push(5);
  s21_stack_1.swap(s21_stack_2);
  std_stack_1.swap(std_stack_2);
  EXPECT_EQ(s21_stack_1.top(), 1);
  EXPECT_EQ(s21_stack_2.top(), 5);
  EXPECT_EQ(std_stack_1.top(), 5);
  EXPECT_EQ(std_stack_2.top(), 1);
}

TEST(Stack, Insert_Many) {
  s21::stack<int> s21_stack = {1, 2, 3};  // front 3 2 1
  s21_stack.insert_many_front(3, 2, 1);   // front 1 2 3 3 2 1
  EXPECT_EQ(s21_stack.top(), 1);
  s21_stack.pop();
  EXPECT_EQ(s21_stack.top(), 2);
  s21_stack.pop();
  EXPECT_EQ(s21_stack.top(), 3);
  s21_stack.pop();
  EXPECT_EQ(s21_stack.top(), 3);
  s21_stack.pop();
  EXPECT_EQ(s21_stack.top(), 2);
  s21_stack.pop();
  EXPECT_EQ(s21_stack.top(), 1);
}
