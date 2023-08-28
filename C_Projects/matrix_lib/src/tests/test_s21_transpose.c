#include "test.h"

START_TEST(test_s21_transpose_1_1) {
  matrix_t *A = NULL;
  matrix_t *result = NULL;
  int status = s21_transpose(A, result);
  ck_assert_int_eq(status, INCORRECT);
}
END_TEST

START_TEST(test_s21_transpose_1_2) {
  matrix_t A, result;
  s21_create_matrix(0, 4, &A);
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_1_3) {
  matrix_t A, result;
  s21_create_matrix(3, 0, &A);
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_3_1) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2.0;
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(result.matrix[0][0], 2.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3_2) {
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);
  A.matrix[2][0] = 2.0;
  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][2], 2.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3_3) {
  matrix_t matrix_test;
  matrix_t matrix_result;
  s21_create_matrix(3, 2, &matrix_test);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 4;

  matrix_test.matrix[1][0] = 2;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[2][0] = 3;
  matrix_test.matrix[2][1] = 6;

  int x = s21_transpose(&matrix_test, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(matrix_result.rows, 2);
  ck_assert_int_eq(matrix_result.columns, 3);
  ck_assert_double_eq(matrix_result.matrix[0][0], 1.0);
  ck_assert_double_eq(matrix_result.matrix[0][1], 2.0);
  ck_assert_double_eq(matrix_result.matrix[0][2], 3.0);
  ck_assert_double_eq(matrix_result.matrix[1][0], 4.0);
  ck_assert_double_eq(matrix_result.matrix[1][1], 5.0);
  ck_assert_double_eq(matrix_result.matrix[1][2], 6.0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

void test_s21_transpose(SRunner *runner) {
  Suite *tests = suite_create("test_s21_transpose");
  tests = add_test(tests, test_s21_transpose_1_1);
  tests = add_test(tests, test_s21_transpose_1_2);
  tests = add_test(tests, test_s21_transpose_1_3);
  tests = add_test(tests, test_s21_transpose_3_1);
  tests = add_test(tests, test_s21_transpose_3_2);
  tests = add_test(tests, test_s21_transpose_3_3);
  srunner_add_suite(runner, tests);
}