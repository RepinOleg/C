#include <queue>

#include "test_containers.h"

TEST(Queue, Constructor_Default) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Constructor_List) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(Queue, Constructor_Copy) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_copy(s21_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  EXPECT_EQ(s21_queue_copy.front(), std_queue.front());
  EXPECT_EQ(s21_queue_copy.back(), std_queue.back());
}

TEST(Queue, Constructor_Move) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_move(std::move(s21_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  EXPECT_EQ(s21_queue_move.front(), std_queue.front());
  EXPECT_EQ(s21_queue_move.back(), std_queue.back());
}

TEST(Queue, Operator_Copy) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_copy;
  s21_queue_copy = s21_queue;
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std::queue<int> std_queue_copy = std_queue;
  EXPECT_EQ(s21_queue_copy.front(), std_queue_copy.front());
  EXPECT_EQ(s21_queue_copy.back(), std_queue_copy.back());
}

TEST(Queue, Operator_Copy_2) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_copy = {5, 4, 3, 2, 1};
  s21_queue_copy = s21_queue;
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std::queue<int> std_queue_copy = std_queue;
  EXPECT_EQ(s21_queue_copy.front(), std_queue_copy.front());
  EXPECT_EQ(s21_queue_copy.back(), std_queue_copy.back());
}

TEST(Queue, Operator_Move) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_move;
  s21_queue_move = std::move(s21_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
  EXPECT_EQ(s21_queue_move.back(), std_queue_move.back());
}

TEST(Queue, Operator_Move_2) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_move = {5, 4, 3, 2, 1};
  s21_queue_move = std::move(s21_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
  EXPECT_EQ(s21_queue_move.back(), std_queue_move.back());
}

TEST(Queue, Front) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Front_2) {
  s21::queue<int> s21_queue_int = {101, 202, 303};
  std::queue<int> std_queue_int;
  std_queue_int.push(101);
  std_queue_int.push(202);
  std_queue_int.push(303);
  s21::queue<double> s21_queue_double = {133.987f, -2.666f, 313.131f};
  std::queue<double> std_queue_double;
  std_queue_double.push(133.987f);
  std_queue_double.push(-2.666f);
  std_queue_double.push(313.131f);
  s21::queue<std::string> s21_queue_string = {"xyz", "vw", "rstu", "opq"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("xyz");
  std_queue_string.push("vw");
  std_queue_string.push("rstu");
  std_queue_string.push("opq");
  EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(s21_queue_double.front(), std_queue_double.front());
  EXPECT_EQ(s21_queue_string.front(), std_queue_string.front());
}

TEST(Queue, Back) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std_queue.push(4);
  std_queue.push(5);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Back_2) {
  s21::queue<int> s21_queue_int = {101, 202, 303};
  std::queue<int> std_queue_int;
  std_queue_int.push(101);
  std_queue_int.push(202);
  std_queue_int.push(303);
  s21::queue<double> s21_queue_double = {133.987f, -2.666f, 313.131f};
  std::queue<double> std_queue_double;
  std_queue_double.push(133.987f);
  std_queue_double.push(-2.666f);
  std_queue_double.push(313.131f);
  s21::queue<std::string> s21_queue_string = {"xyz", "vw", "rstu", "opq"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("xyz");
  std_queue_string.push("vw");
  std_queue_string.push("rstu");
  std_queue_string.push("opq");
  EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(s21_queue_double.back(), std_queue_double.back());
  EXPECT_EQ(s21_queue_string.back(), std_queue_string.back());
}

TEST(Queue, Empty) {
  s21::queue<int> s21_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  std_queue.push(4);
  s21_queue.push(4);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  std_queue.push(5);
  s21_queue.push(5);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Size) {
  s21::queue<int> s21_queue = {5, 4, 3, 2, 1};
  std::queue<int> std_queue;
  std_queue.push(5);
  std_queue.push(4);
  std_queue.push(3);
  std_queue.push(2);
  std_queue.push(1);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(Queue, Push) {
  s21::queue<int> s21_queue = {10, 20, 30};
  std::queue<int> std_queue;
  std_queue.push(10);
  std_queue.push(20);
  std_queue.push(30);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  std_queue.push(44);
  s21_queue.push(44);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  std_queue.push(58);
  s21_queue.push(58);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(Queue, Pop) {
  s21::queue<int> s21_queue = {103, 202, 301};
  std::queue<int> std_queue;
  std_queue.push(103);
  std_queue.push(202);
  std_queue.push(301);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  std_queue.push(144);
  s21_queue.push(144);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  std_queue.push(589);
  s21_queue.push(589);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Swap) {
  s21::queue<int> s21_queue_1 = {1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_2 = {5, 4, 3, 2, 1};
  std::queue<int> std_queue_1;
  std::queue<int> std_queue_2;
  std_queue_1.push(1);
  std_queue_1.push(2);
  std_queue_1.push(3);
  std_queue_1.push(4);
  std_queue_1.push(5);
  std_queue_2.push(5);
  std_queue_2.push(4);
  std_queue_2.push(3);
  std_queue_2.push(2);
  std_queue_2.push(1);
  s21_queue_1.swap(s21_queue_2);
  std_queue_1.swap(std_queue_2);
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.back());
  EXPECT_EQ(std_queue_1.front(), std_queue_2.back());
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
  EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
  EXPECT_EQ(s21_queue_2.back(), std_queue_2.back());
}

TEST(Queue, Insert_Many) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21_queue.insert_many_back(4, 5, 6);
  EXPECT_EQ(s21_queue.front(), 1);
  EXPECT_EQ(s21_queue.back(), 6);
  s21_queue.pop();
  EXPECT_EQ(s21_queue.front(), 2);
  s21_queue.pop();
  EXPECT_EQ(s21_queue.front(), 3);
  s21_queue.pop();
  EXPECT_EQ(s21_queue.front(), 4);
  s21_queue.pop();
  EXPECT_EQ(s21_queue.front(), 5);
  s21_queue.pop();
  EXPECT_EQ(s21_queue.front(), 6);
}
