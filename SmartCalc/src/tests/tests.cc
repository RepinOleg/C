#include "../model/calculator_model.h"
#include "../model/credit_model.h"
#include "gtest/gtest.h"
TEST(Calculator, SimpleExpression) {
  s21::CalcModel my_model("2+3", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, SimpleExpression2) {
  s21::CalcModel my_model("10/2", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, SimpleExpression3) {
  s21::CalcModel my_model("1*5", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, SimpleExpression4) {
  s21::CalcModel my_model("1*5-4", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 1.0);
}

TEST(Calculator, SimpleExpression5) {
  s21::CalcModel my_model("1*5-4mod1", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, SimpleExpression6) {
  s21::CalcModel my_model("2^3", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 8.0);
}

TEST(Calculator, SimpleExpression7) {
  s21::CalcModel my_model("cos(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 1.0);
}

TEST(Calculator, SimpleExpression8) {
  s21::CalcModel my_model("ln(1)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, SimpleExpression9) {
  s21::CalcModel my_model("log(100)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 2.0);
}

TEST(Calculator, SimpleExpression10) {
  s21::CalcModel my_model("sqrt(25)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, SimpleExpression11) {
  s21::CalcModel my_model("sin(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, SimpleExpression12) {
  s21::CalcModel my_model("tan(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, SimpleExpression13) {
  s21::CalcModel my_model("acos(1)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, SimpleExpression14) {
  s21::CalcModel my_model("asin(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, SimpleExpression15) {
  s21::CalcModel my_model("atan(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, HardExpression1) {
  s21::CalcModel my_model("(2+3)*4", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 20.0);
}

TEST(Calculator, HardExpression2) {
  s21::CalcModel my_model("5-(2+3)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, HardExpression3) {
  s21::CalcModel my_model("(4+6)/2", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 5.0);
}

TEST(Calculator, HardExpression4) {
  s21::CalcModel my_model("10/(2+3)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 2.0);
}

TEST(Calculator, HardExpression5) {
  s21::CalcModel my_model("(2+3)^2", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 25.0);
}

TEST(Calculator, HardExpression6) {
  s21::CalcModel my_model("(7+3)mod4", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 2.0);
}

TEST(Calculator, HardExpression7) {
  s21::CalcModel my_model("cos(0)+sin(0)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 1.0);
}

TEST(Calculator, HardExpression8) {
  s21::CalcModel my_model("ln(1)+log(100)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 2.0);
}

TEST(Calculator, HardExpression9) {
  s21::CalcModel my_model("(5-(2+3))/(4-1)", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, HardExpression10) {
  s21::CalcModel my_model("(asin(0)+atan(0))/2", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, HardExpression11) {
  s21::CalcModel my_model("(asin(0)+atan(0))/2", 0);
  EXPECT_DOUBLE_EQ(my_model.MainCalculation(), 0.0);
}

TEST(Calculator, HardExpression12) {
  s21::CalcModel my_model("(9+(-3))*sqrt(16+25)", 0);
  EXPECT_TRUE(std::fabs(my_model.MainCalculation() - 38.4187454246) < 1e-9);
}

TEST(Calculator, HardExpression13) {
  s21::CalcModel my_model("3^2*3.24-5.66/9*(-1)", 0);
  EXPECT_TRUE(std::fabs(my_model.MainCalculation() - 29.788888888) < 1e-9);
}

TEST(Calculator, x) {
  s21::CalcModel my_model("3^2*3.24-5.66/9*(x)", -1);
  EXPECT_TRUE(std::fabs(my_model.MainCalculation() - 29.788888888) < 1e-9);
}

TEST(Calculator, x2) {
  s21::CalcModel my_model("(9+(-3))*sqrt(x)", 41);
  EXPECT_TRUE(std::fabs(my_model.MainCalculation() - 38.4187454246) < 1e-9);
}

TEST(Calculator, Validator) {
  s21::Validator my_validator;
  EXPECT_FALSE(my_validator.Validation("2+3)"));
}

TEST(Calculator, Validator2) {
  s21::Validator my_validator;
  EXPECT_FALSE(my_validator.Validation("2+3+"));
}
TEST(Calculator, Validator3) {
  s21::Validator my_validator;
  EXPECT_FALSE(my_validator.Validation("(2+3"));
}

TEST(Calculator, Validator4) {
  s21::Validator my_validator;
  EXPECT_TRUE(my_validator.Validation("(9+(-3))*sqrt(x)"));
}

TEST(Calculator, CredirCalc) {
  s21::CreditCalc my_credit_calc;

  auto res = my_credit_calc.CreditCalculation(100000, 10, 12, 0);
  EXPECT_TRUE(std::fabs(res.at("total") - 105499.06) < 1e-2);
  EXPECT_TRUE(std::fabs(res.at("payment") - 8791.59) < 1e-2);
  EXPECT_TRUE(std::fabs(res.at("diff") - 5499.06) < 1e-2);
}

TEST(Calculator, CredirCal2) {
  s21::CreditCalc my_credit_calc;

  auto res = my_credit_calc.CreditCalculation(100000, 10, 12, 1);
  EXPECT_TRUE(std::fabs(res.at("total") - 105416.67) < 1e-2);
  EXPECT_TRUE(std::fabs(res.at("first_payment") - 9166.67) < 1e-2);
  EXPECT_TRUE(std::fabs(res.at("last_payment") - 8402.78) < 1e-2);
  EXPECT_TRUE(std::fabs(res.at("diff") - 5416.67) < 1e-2);
}
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}