#include "test.h"

START_TEST(test_s21_mult_number_1_1) {
  matrix_t *A = NULL;
  matrix_t *result = NULL;
  int status = s21_mult_number(A, 0.0, result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(A);
}
END_TEST

START_TEST(test_s21_mult_number_1_2) {
  matrix_t A, result;
  s21_create_matrix(0, 4, &A);
  int status = s21_mult_number(&A, 0.0, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_1_3) {
  matrix_t matrix_test;
  matrix_t matrix_result;
  s21_create_matrix(3, 3, &matrix_test);
  double number = 2.0;
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;
  int x = s21_mult_number(&matrix_test, number, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(matrix_result.rows, 3);
  ck_assert_int_eq(matrix_result.columns, 3);
  ck_assert_double_eq(matrix_result.matrix[0][0], 2.0);
  ck_assert_double_eq(matrix_result.matrix[0][1], 4.0);
  ck_assert_double_eq(matrix_result.matrix[0][2], 6.0);
  ck_assert_double_eq(matrix_result.matrix[1][0], 0.0);
  ck_assert_double_eq(matrix_result.matrix[1][1], 8.0);
  ck_assert_double_eq(matrix_result.matrix[1][2], 4.0);
  ck_assert_double_eq(matrix_result.matrix[2][0], 4.0);
  ck_assert_double_eq(matrix_result.matrix[2][1], 6.0);
  ck_assert_double_eq(matrix_result.matrix[2][2], 8.0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(test_s21_mult_number_2_1) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  int status = s21_mult_number(&A, 1.0, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(result.matrix[0][0], 0.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_2_2) {
  matrix_t matrix_test;
  matrix_t matrix_result;
  s21_create_matrix(2, 2, &matrix_test);
  double number = 1.0;
  matrix_test.matrix[0][0] = 123;
  matrix_test.matrix[0][1] = 333;

  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 44;

  int x = s21_mult_number(&matrix_test, number, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(matrix_result.rows, 2);
  ck_assert_int_eq(matrix_result.columns, 2);
  ck_assert_double_eq(matrix_result.matrix[0][0], 123.0);
  ck_assert_double_eq(matrix_result.matrix[0][1], 333.0);

  ck_assert_double_eq(matrix_result.matrix[1][0], 0.0);
  ck_assert_double_eq(matrix_result.matrix[1][1], 44.0);

  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

void test_s21_mult_number(SRunner *runner) {
  Suite *tests = suite_create("test_s21_mult_number");
  tests = add_test(tests, test_s21_mult_number_1_1);
  tests = add_test(tests, test_s21_mult_number_1_2);
  tests = add_test(tests, test_s21_mult_number_1_3);
  tests = add_test(tests, test_s21_mult_number_2_1);
  tests = add_test(tests, test_s21_mult_number_2_2);
  srunner_add_suite(runner, tests);
}