#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Construct_Test, BasicConstruct) {
  S21Matrix tmp;
  EXPECT_EQ(tmp.get_cols(), 0);
  EXPECT_EQ(tmp.get_rows(), 0);
}

TEST(Construct_Test, Construct) {
  S21Matrix tmp(3, 1);
  EXPECT_EQ(tmp.get_rows(), 3);
  EXPECT_EQ(tmp.get_cols(), 1);
  EXPECT_EQ(tmp(0, 0), 0);
  EXPECT_EQ(tmp(1, 0), 0);
  EXPECT_EQ(tmp(2, 0), 0);
}

TEST(Construct_Test, ConstructException) {
  EXPECT_ANY_THROW(S21Matrix tmp(-1, 1));
}

TEST(Construct_Test, ConstructException1) {
  EXPECT_ANY_THROW(S21Matrix tmp(1, -100));
}

TEST(Construct_Test, CopyConstruct) {
  S21Matrix tmp(1, 1);
  S21Matrix cp(tmp);
  EXPECT_EQ(cp.get_rows(), 1);
  EXPECT_EQ(cp.get_cols(), 1);
}

TEST(Construct_Test, CopyConstruct1) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;
  S21Matrix cp(tmp);

  EXPECT_EQ(cp.get_rows(), 2);
  EXPECT_EQ(cp.get_cols(), 2);
  EXPECT_EQ(cp(0, 0), tmp(0, 0));
  EXPECT_EQ(cp(1, 0), tmp(1, 0));
  EXPECT_EQ(cp(0, 1), tmp(0, 1));
  EXPECT_EQ(cp(1, 1), tmp(1, 1));
}

TEST(Construct_Test, MoveConstruct) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;
  S21Matrix cp = std::move(tmp);

  EXPECT_EQ(cp.get_rows(), 2);
  EXPECT_EQ(cp.get_cols(), 2);
  EXPECT_EQ(cp(0, 0), 1);
  EXPECT_EQ(cp(1, 0), 3);
  EXPECT_EQ(cp(0, 1), 2);
  EXPECT_EQ(cp(1, 1), 4);
  EXPECT_EQ(tmp.get_cols(), 0);
  EXPECT_EQ(tmp.get_rows(), 0);
}

TEST(BracketsTest, BracketException) {
  S21Matrix tmp(2, 2);
  EXPECT_ANY_THROW(tmp(-1, 0) = 1);
}

TEST(BracketsTest, BracketException2) {
  S21Matrix tmp(2, 2);
  const S21Matrix res(2, 2);
  tmp(0, 0) = 2.5;
  EXPECT_ANY_THROW(tmp(0, 0) = res(-1, 0));
}

TEST(SetTest, SetRows) {
  S21Matrix tmp(1, 1);
  tmp.set_rows(10);
  EXPECT_EQ(tmp.get_rows(), 10);
  EXPECT_EQ(tmp(8, 0), 0);
}

TEST(SetTest, SetCols) {
  S21Matrix tmp(1, 1);
  tmp.set_cols(10);
  EXPECT_EQ(tmp.get_cols(), 10);
  EXPECT_EQ(tmp(0, 8), 0);
}

TEST(SetTest, SetColsException) {
  S21Matrix tmp(1, 1);
  EXPECT_ANY_THROW(tmp.set_cols(-5));
}

TEST(SetTest, SetRowsException) {
  S21Matrix tmp(1, 1);
  EXPECT_ANY_THROW(tmp.set_rows(-5));
}

TEST(EqMatrixTest, EqMatrixTrue) {
  S21Matrix tmp(2, 2);
  S21Matrix tmp1(2, 2);
  tmp(0, 0) = 0;
  tmp(0, 1) = 1;
  tmp(1, 0) = 2;
  tmp(1, 1) = 3;

  tmp1(0, 0) = 0;
  tmp1(0, 1) = 1;
  tmp1(1, 0) = 2;
  tmp1(1, 1) = 3;
  EXPECT_EQ(tmp.EqMatrix(tmp1), true);
}

TEST(EqMatrixTest, EqMatrixFalse) {
  S21Matrix tmp(2, 2);
  S21Matrix tmp1(2, 3);
  tmp(0, 0) = 0;
  tmp(0, 1) = 1;
  tmp(1, 0) = 2;
  tmp(1, 1) = 3;

  tmp1(0, 0) = 0;
  tmp1(0, 1) = 1;
  tmp1(1, 0) = 2;
  tmp1(1, 1) = 3;
  EXPECT_EQ(tmp.EqMatrix(tmp1), false);
}

TEST(SumTest, SumMatrixTest) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      first(i, j) = second(i, j) = i;
    }
  }
  first.SumMatrix(second);

  EXPECT_EQ(first(0, 0), 0);
  EXPECT_EQ(first(0, 1), 0);
  EXPECT_EQ(first(1, 0), 2);
  EXPECT_EQ(first(1, 1), 2);
}

TEST(SumTest, SumMatrixTestException) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 3);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      first(i, j) = second(i, j) = i;
    }
  }
  EXPECT_ANY_THROW(first.SumMatrix(second));
}

TEST(SubTest, SubMatrixTest) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      first(i, j) = second(i, j) = i;
    }
  }
  first.SubMatrix(second);

  EXPECT_EQ(first(0, 0), 0);
  EXPECT_EQ(first(0, 1), 0);
  EXPECT_EQ(first(1, 0), 0);
  EXPECT_EQ(first(1, 1), 0);
}

TEST(SubTest, SubMatrixTestException) {
  S21Matrix first(2, 2);
  S21Matrix second(2, 3);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      first(i, j) = second(i, j) = i;
    }
  }
  EXPECT_ANY_THROW(first.SubMatrix(second));
}

TEST(MulOnNumberTest, MulOnNumberTest) {
  S21Matrix first(2, 2);
  first(0, 0) = 1;
  first(0, 1) = 10;
  first(1, 0) = 0;
  first(1, 1) = 1.5;
  double x = 1.5;
  first.MulNumber(x);

  EXPECT_EQ(first(0, 0), 1.5);
  EXPECT_EQ(first(0, 1), 15);
  EXPECT_EQ(first(1, 0), 0);
  EXPECT_EQ(first(1, 1), 2.25);
}

TEST(MulMatrixTest, MulMatrtixTest1) {
  S21Matrix first(3, 2);
  S21Matrix second(2, 3);
  first(0, 0) = 1;
  first(0, 1) = 4;
  first(1, 0) = 2;
  first(1, 1) = 5;
  first(2, 0) = 3;
  first(2, 1) = 6;

  second(0, 0) = 1;
  second(0, 1) = -1;
  second(0, 2) = 1;
  second(1, 0) = 2;
  second(1, 1) = 3;
  second(1, 2) = 4;

  first.MulMatrix(second);

  EXPECT_EQ(first(0, 0), 9);
  EXPECT_EQ(first(0, 1), 11);
  EXPECT_EQ(first(0, 2), 17);
  EXPECT_EQ(first(1, 0), 12);
  EXPECT_EQ(first(1, 1), 13);
  EXPECT_EQ(first(1, 2), 22);
  EXPECT_EQ(first(2, 0), 15);
  EXPECT_EQ(first(2, 1), 15);
  EXPECT_EQ(first(2, 2), 27);
}

TEST(MulMatrixTest, MulMatrtixTestException) {
  S21Matrix tmp(1, 1), tmp1(2, 2);
  EXPECT_ANY_THROW(tmp.MulMatrix(tmp1));
}

TEST(TransposeMatrix, TransposeMatrixTest1) {
  S21Matrix tmp(2, 1);
  tmp(0, 0) = 1;
  tmp(1, 0) = 2;
  S21Matrix res;
  res = tmp.Transpose();
  EXPECT_EQ(res(0, 0), 1);
  EXPECT_EQ(res(0, 1), 2);
  EXPECT_EQ(res.get_rows(), 1);
  EXPECT_EQ(res.get_cols(), 2);
}

TEST(TransposeMatrix, TransposeMatrixTest2) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;
  S21Matrix res;
  res = tmp.Transpose();
  EXPECT_EQ(res(0, 0), 1);
  EXPECT_EQ(res(0, 1), 4);
  EXPECT_EQ(res(0, 2), 7);
  EXPECT_EQ(res(1, 0), 2);
  EXPECT_EQ(res(1, 1), 5);
  EXPECT_EQ(res(1, 2), 8);
  EXPECT_EQ(res(2, 0), 3);
  EXPECT_EQ(res(2, 1), 6);
  EXPECT_EQ(res(2, 2), 9);
  EXPECT_EQ(res.get_rows(), 3);
  EXPECT_EQ(res.get_cols(), 3);
}

TEST(DeterminantMatrix, DeterminantMatrixTest1) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;
  EXPECT_EQ(tmp.Determinant(), 0);
}

TEST(DeterminantMatrix, DeterminantMatrixTest2) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 22.3;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;
  ASSERT_DOUBLE_EQ(tmp.Determinant(), -63.9);
}

TEST(DeterminantMatrix, DeterminantMatrixTest3) {
  S21Matrix tmp(1, 1);
  tmp(0, 0) = 22.3;
  EXPECT_EQ(tmp.Determinant(), 22.3);
}

TEST(DeterminantMatrix, DeterminantMatrixTest4) {
  S21Matrix tmp(1, 2);
  tmp(0, 0) = 22.3;
  EXPECT_ANY_THROW(tmp.Determinant());
}

TEST(CalcComplements, CalcComplementsTest1) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 5;
  tmp(0, 1) = 7;
  tmp(0, 2) = 1;
  tmp(1, 0) = -4;
  tmp(1, 1) = 1;
  tmp(1, 2) = 0;
  tmp(2, 0) = 2;
  tmp(2, 1) = 0;
  tmp(2, 2) = 3;
  S21Matrix res = tmp.CalcComplements();
  EXPECT_EQ(res(0, 0), 3);
  EXPECT_EQ(res(0, 1), 12);
  EXPECT_EQ(res(0, 2), -2);
  EXPECT_EQ(res(1, 0), -21);
  EXPECT_EQ(res(1, 1), 13);
  EXPECT_EQ(res(1, 2), 14);
  EXPECT_EQ(res(2, 0), -1);
  EXPECT_EQ(res(2, 1), -4);
  EXPECT_EQ(res(2, 2), 33);
}

TEST(CalcComplements, CalcComplementsTest2) {
  S21Matrix tmp(3, 2);
  EXPECT_ANY_THROW(tmp.CalcComplements());
}

TEST(CalcComplements, CalcComplementsTest3) {
  S21Matrix tmp(1, 1);
  S21Matrix res = tmp.CalcComplements();
  EXPECT_EQ(res(0, 0), 1);
}

TEST(InversMatrix, InverseMatrixTest) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;
  S21Matrix res = tmp.InverseMatrix();
  EXPECT_EQ(res(0, 0), -2);
  EXPECT_EQ(res(0, 1), 1);
  EXPECT_EQ(res(1, 0), 1.5);
  EXPECT_EQ(res(1, 1), -0.5);
}

TEST(InversMatrix, InverseMatrixTest2) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;
  EXPECT_ANY_THROW(S21Matrix res = tmp.InverseMatrix());
}

TEST(TestOperators, OperatorsPlus) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;

  S21Matrix tmp2(3, 3);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = 2;
  tmp2(0, 2) = 3;
  tmp2(1, 0) = 4;
  tmp2(1, 1) = 5;
  tmp2(1, 2) = 6;
  tmp2(2, 0) = 7;
  tmp2(2, 1) = 8;
  tmp2(2, 2) = 9;

  S21Matrix res = tmp + tmp2;
  EXPECT_EQ(res(0, 0), 2);
  EXPECT_EQ(res(0, 1), 4);
  EXPECT_EQ(res(0, 2), 6);
  EXPECT_EQ(res(1, 0), 8);
  EXPECT_EQ(res(1, 1), 10);
  EXPECT_EQ(res(1, 2), 12);
  EXPECT_EQ(res(2, 0), 14);
  EXPECT_EQ(res(2, 1), 16);
  EXPECT_EQ(res(2, 2), 18);
}

TEST(TestOperators, OperatorsMinus) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;

  S21Matrix tmp2(3, 3);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = -3;
  tmp2(0, 2) = 3.9;
  tmp2(1, 0) = 4;
  tmp2(1, 1) = 5;
  tmp2(1, 2) = 6;
  tmp2(2, 0) = 7;
  tmp2(2, 1) = 8;
  tmp2(2, 2) = 9;

  S21Matrix res = tmp - tmp2;
  EXPECT_EQ(res(0, 0), 0);
  EXPECT_EQ(res(0, 1), 5);
  ASSERT_DOUBLE_EQ(res(0, 2), -0.9);
  EXPECT_EQ(res(1, 0), 0);
  EXPECT_EQ(res(1, 1), 0);
  EXPECT_EQ(res(1, 2), 0);
  EXPECT_EQ(res(2, 0), 0);
  EXPECT_EQ(res(2, 1), 0);
  EXPECT_EQ(res(2, 2), 0);
}

TEST(TestOperators, OperatorsPlusEqual) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;

  S21Matrix tmp2(3, 3);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = -3;
  tmp2(0, 2) = 3.9;
  tmp2(1, 0) = 4;
  tmp2(1, 1) = 5;
  tmp2(1, 2) = 6;
  tmp2(2, 0) = 7;
  tmp2(2, 1) = 8;
  tmp2(2, 2) = 9;

  tmp += tmp2;
  EXPECT_EQ(tmp(0, 0), 2);
  EXPECT_EQ(tmp(0, 1), -1);
  ASSERT_DOUBLE_EQ(tmp(0, 2), 6.9);
  EXPECT_EQ(tmp(1, 0), 8);
  EXPECT_EQ(tmp(1, 1), 10);
  EXPECT_EQ(tmp(1, 2), 12);
  EXPECT_EQ(tmp(2, 0), 14);
  EXPECT_EQ(tmp(2, 1), 16);
  EXPECT_EQ(tmp(2, 2), 18);
}

TEST(TestOperators, OperatorsMinusEqual) {
  S21Matrix tmp(3, 3);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 3;
  tmp(1, 0) = 4;
  tmp(1, 1) = 5;
  tmp(1, 2) = 6;
  tmp(2, 0) = 7;
  tmp(2, 1) = 8;
  tmp(2, 2) = 9;

  S21Matrix tmp2(3, 3);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = -3;
  tmp2(0, 2) = 3.9;
  tmp2(1, 0) = 4;
  tmp2(1, 1) = 5;
  tmp2(1, 2) = 6;
  tmp2(2, 0) = 7;
  tmp2(2, 1) = 8;
  tmp2(2, 2) = 9;

  tmp -= tmp2;
  EXPECT_EQ(tmp(0, 0), 0);
  EXPECT_EQ(tmp(0, 1), 5);
  ASSERT_DOUBLE_EQ(tmp(0, 2), -0.9);
  EXPECT_EQ(tmp(1, 0), 0);
  EXPECT_EQ(tmp(1, 1), 0);
  EXPECT_EQ(tmp(1, 2), 0);
  EXPECT_EQ(tmp(2, 0), 0);
  EXPECT_EQ(tmp(2, 1), 0);
  EXPECT_EQ(tmp(2, 2), 0);
}

TEST(TestOperators, OperatorMultEqualMatrix) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;

  S21Matrix tmp2(2, 2);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = -3;
  tmp2(1, 0) = 3.9;
  tmp2(1, 1) = 4;

  tmp *= tmp2;
  EXPECT_EQ(tmp(0, 0), 8.8);
  EXPECT_EQ(tmp(0, 1), 5);
  ASSERT_DOUBLE_EQ(tmp(1, 0), 18.6);
  EXPECT_EQ(tmp(1, 1), 7);
}

TEST(TestOperators, OperatorMultEqualNumber) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;

  double x = 2;
  tmp *= x;
  EXPECT_EQ(tmp(0, 0), 2);
  EXPECT_EQ(tmp(0, 1), 4);
  ASSERT_DOUBLE_EQ(tmp(1, 0), 6);
  EXPECT_EQ(tmp(1, 1), 8);
}

TEST(TestOperators, OperatorMultNumber) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1.1;
  tmp(0, 1) = -2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;

  double x = 2;
  S21Matrix tmp1 = tmp * x;
  ASSERT_DOUBLE_EQ(tmp1(0, 0), 2.2);
  EXPECT_EQ(tmp1(0, 1), -4);
  ASSERT_DOUBLE_EQ(tmp1(1, 0), 6);
  EXPECT_EQ(tmp1(1, 1), 8);
}

TEST(TestOperators, OperatorMultMatrix) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;

  S21Matrix tmp2(2, 2);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = -3;
  tmp2(1, 0) = 3.9;
  tmp2(1, 1) = 4;
  S21Matrix res = tmp * tmp2;
  EXPECT_EQ(res(0, 0), 8.8);
  EXPECT_EQ(res(0, 1), 5);
  ASSERT_DOUBLE_EQ(res(1, 0), 18.6);
  EXPECT_EQ(res(1, 1), 7);
}

TEST(TestOperators, OperatorEqualEqual) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;

  S21Matrix tmp2(2, 2);
  tmp2(0, 0) = 1;
  tmp2(0, 1) = 2;
  tmp2(1, 0) = 3;
  tmp2(1, 1) = 4;
  EXPECT_TRUE(tmp == tmp2);
}

TEST(TestOperators, OperatorEqualCopy) {
  S21Matrix tmp(2, 2);
  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 4;
  S21Matrix tmp2;
  tmp2 = tmp;
  EXPECT_EQ(tmp2(0, 0), 1);
  EXPECT_EQ(tmp2(0, 1), 2);
  EXPECT_EQ(tmp2(1, 0), 3);
  EXPECT_EQ(tmp2(1, 1), 4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}