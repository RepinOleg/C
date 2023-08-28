#include "test.h"

START_TEST(test_s21_inverse_matrix_1_1) {
  matrix_t *A = NULL;
  matrix_t *result = NULL;
  int status = s21_inverse_matrix(A, result);
  ck_assert_int_eq(status, INCORRECT);
}
END_TEST

START_TEST(test_s21_inverse_matrix_1_2) {
  matrix_t A, result;
  s21_create_matrix(0, 4, &A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_1_3) {
  matrix_t matrix_test;
  matrix_t matrix_result;
  s21_create_matrix(3, 3, &matrix_test);
  matrix_test.matrix[0][0] = 2;
  matrix_test.matrix[0][1] = 5;
  matrix_test.matrix[0][2] = 7;
  matrix_test.matrix[1][0] = 6;
  matrix_test.matrix[1][1] = 3;
  matrix_test.matrix[1][2] = 4;
  matrix_test.matrix[2][0] = 5;
  matrix_test.matrix[2][1] = -2;
  matrix_test.matrix[2][2] = -3;

  int x = s21_inverse_matrix(&matrix_test, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_double_eq(matrix_result.matrix[0][0], 1.0);
  ck_assert_double_eq(matrix_result.matrix[0][1], -1.0);
  ck_assert_double_eq(matrix_result.matrix[0][2], 1.0);
  ck_assert_double_eq(matrix_result.matrix[1][0], -38.0);
  ck_assert_double_eq(matrix_result.matrix[1][1], 41.0);
  ck_assert_double_eq(matrix_result.matrix[1][2], -34.0);
  ck_assert_double_eq(matrix_result.matrix[2][0], 27.0);
  ck_assert_double_eq(matrix_result.matrix[2][1], -29.0);
  ck_assert_double_eq(matrix_result.matrix[2][2], 24.0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2_1) {
  matrix_t matrix_test;
  matrix_t matrix_result;
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

  int x = s21_inverse_matrix(&matrix_test, &matrix_result);
  ck_assert_int_eq(x, 2);

  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2_2) {
  matrix_t matrix_test;
  matrix_t matrix_result;
  s21_create_matrix(2, 3, &matrix_test);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 4;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[1][2] = 6;

  int x = s21_inverse_matrix(&matrix_test, &matrix_result);
  ck_assert_int_eq(x, 2);

  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3_2) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][0], 1.0);
  ck_assert_double_eq(result.matrix[0][1], -1.0);
  ck_assert_double_eq(result.matrix[0][2], 1.0);
  ck_assert_double_eq(result.matrix[1][0], -38.0);
  ck_assert_double_eq(result.matrix[1][1], 41.0);
  ck_assert_double_eq(result.matrix[1][2], -34.0);
  ck_assert_double_eq(result.matrix[2][0], 27.0);
  ck_assert_double_eq(result.matrix[2][1], -29.0);
  ck_assert_double_eq(result.matrix[2][2], 24.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

void test_s21_inverse_matrix(SRunner *runner) {
  Suite *tests = suite_create("test_s21_inverse_matrix");
  tests = add_test(tests, test_s21_inverse_matrix_1_1);
  tests = add_test(tests, test_s21_inverse_matrix_1_2);
  tests = add_test(tests, test_s21_inverse_matrix_1_3);
  tests = add_test(tests, test_s21_inverse_matrix_2_1);
  tests = add_test(tests, test_s21_inverse_matrix_2_2);
  tests = add_test(tests, test_s21_inverse_matrix_3_2);
  srunner_add_suite(runner, tests);
}