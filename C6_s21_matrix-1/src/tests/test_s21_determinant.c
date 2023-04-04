#include "test.h"

START_TEST(test_s21_determinant_1_1) {
  matrix_t *A = NULL;
  double result;
  int status = s21_determinant(A, &result);
  ck_assert_int_eq(status, INCORRECT);
}
END_TEST

START_TEST(test_s21_determinant_1_2) {
  matrix_t matrix_test;
  s21_create_matrix(1, 1, &matrix_test);
  matrix_test.matrix[0][0] = 1;
  double res = 0.0;
  int x = s21_determinant(&matrix_test, &res);
  ck_assert_int_eq(x, 0);
  ck_assert_double_eq(res, 1.0);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_determinant_1_3) {
  matrix_t matrix_test;
  s21_create_matrix(2, 3, &matrix_test);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 4;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[1][2] = 6;
  double res = 0.0;
  int x = s21_determinant(&matrix_test, &res);
  ck_assert_int_eq(x, 2);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_determinant_1_4) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 2, &A);
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2_1) {
  matrix_t matrix_test;
  s21_create_matrix(3, 3, &matrix_test);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 4;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[1][2] = 6;
  matrix_test.matrix[2][0] = 7;
  matrix_test.matrix[2][1] = 8;
  matrix_test.matrix[2][2] = 9;
  double res = 0.0;
  int x = s21_determinant(&matrix_test, &res);
  ck_assert_int_eq(x, 0);
  ck_assert_double_eq(res, 0.0);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_determinant_2_2) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[1][0] = 2.0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

void test_s21_determinant(SRunner *runner) {
  Suite *tests = suite_create("test_s21_determinant");
  tests = add_test(tests, test_s21_determinant_1_1);
  tests = add_test(tests, test_s21_determinant_1_2);
  tests = add_test(tests, test_s21_determinant_1_3);
  tests = add_test(tests, test_s21_determinant_1_4);
  tests = add_test(tests, test_s21_determinant_2_1);
  tests = add_test(tests, test_s21_determinant_2_2);
  srunner_add_suite(runner, tests);
}
