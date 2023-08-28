#include "test.h"

START_TEST(test_s21_smart_calc_1_1) {
  double result = 0, x = 0;
  char str[255] = "3+3";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 6.0);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_1_2) {
  double result = 0, x = 0;
  char str[255] = "(2.33+2.33)*10";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 46.6);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_1_3) {
  double result = 0, x = 0;
  char str[255] = "0+0.234";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0.234);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_1) {
  double result = 0, x = 0;
  char str[255] = "10-1+2*10-5*5";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 4);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_2) {
  double result = 0, x = 0;
  char str[255] = "cos(tan(1))";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.0133882) <= 0.00001, "test-1 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_3) {
  double result = 0, x = 0;
  char str[255] = "sin(log(2))";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.296504) <= 0.00001, "test-2_3 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_4) {
  double result = 0, x = 0;
  char str[255] = "log(ln(2))/10^2";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.001591) <= 0.00001, "test-2_4 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_5) {
  double result = 0, x = 1;
  char str[255] = "atan(x)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.785398) <= 0.00001, "test-2_5 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_6) {
  double result = 0, x = 1;
  char str[255] = "1+(";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_smart_calc_2_7) {
  double result = 0, x = 1;
  char str[255] = "1+2+";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_smart_calc_2_8) {
  double result = 0, x = 1;
  char str[255] = "10mod7";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 3);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_2_9) {
  double result = 0, x = 1;
  char str[255] = "sqrt(6)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(2.449489) <= 0.00001, "test-2_9 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_3_0) {
  double result = 0, x = 1;
  char str[255] = "sqrt(0)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_3_1) {
  double result = 0, x = 1;
  char str[255] = "1.22*2+(6-3.33)/log(2)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(11.309548) <= 0.00001, "test-3_1 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_3_2) {
  double result = 0, x = 1;
  char str[255] = "asin(1)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.570796) <= 0.00001, "test-3_2 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_3_3) {
  double result = 0, x = 1;
  char str[255] = "acos(0)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.570796) <= 0.00001, "test-3_3 failed");
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_smart_calc_3_4) {
  double result = 0, x = 1;
  char str[255] = "-2+3+(-2)-3-(+2)";
  int ret = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, -6);
  ck_assert_int_eq(ret, 0);
}
END_TEST

void test_s21_smart_calc(SRunner *runner) {
  Suite *tests = suite_create("test_s21_smart_calc");

  tests = add_test(tests, test_s21_smart_calc_1_1);
  tests = add_test(tests, test_s21_smart_calc_1_2);
  tests = add_test(tests, test_s21_smart_calc_1_3);
  tests = add_test(tests, test_s21_smart_calc_2_1);
  tests = add_test(tests, test_s21_smart_calc_2_2);
  tests = add_test(tests, test_s21_smart_calc_2_3);
  tests = add_test(tests, test_s21_smart_calc_2_4);
  tests = add_test(tests, test_s21_smart_calc_2_5);
  tests = add_test(tests, test_s21_smart_calc_2_6);
  tests = add_test(tests, test_s21_smart_calc_2_7);
  tests = add_test(tests, test_s21_smart_calc_2_8);
  tests = add_test(tests, test_s21_smart_calc_2_9);
  tests = add_test(tests, test_s21_smart_calc_3_0);
  tests = add_test(tests, test_s21_smart_calc_3_1);
  tests = add_test(tests, test_s21_smart_calc_3_2);
  tests = add_test(tests, test_s21_smart_calc_3_3);
  tests = add_test(tests, test_s21_smart_calc_3_4);

  srunner_add_suite(runner, tests);
}
