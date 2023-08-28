#include "test.h"

START_TEST(test_s21_sub_matrix_1_1) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t *result = NULL;
  int status = s21_sub_matrix(A, B, result);
  ck_assert_int_eq(status, INCORRECT);
}
END_TEST

START_TEST(test_s21_sub_matrix_1_2) {
  matrix_t A, B, result;
  s21_create_matrix(0, 4, &A);
  s21_create_matrix(0, 4, &B);
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_1_3) {
  matrix_t A, B, result;
  s21_create_matrix(3, 0, &A);
  s21_create_matrix(3, 0, &B);
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_2_1) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  matrix_t matrix_result;
  s21_create_matrix(3, 2, &matrix_test);
  s21_create_matrix(3, 4, &matrix_test1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_test.matrix[i][j] = i;
      matrix_test1.matrix[i][j] = i;
    }
  }
  int x = s21_sub_matrix(&matrix_test, &matrix_test1, &matrix_result);
  ck_assert_int_eq(x, 2);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2_2) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  matrix_t matrix_result;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 3, &matrix_test1);
  matrix_test.matrix[0][0] = 123;
  matrix_test1.matrix[0][0] = 63;
  matrix_test.matrix[0][1] = 5;
  matrix_test1.matrix[0][1] = 3;
  matrix_test.matrix[0][2] = 1;
  matrix_test1.matrix[0][2] = 1;
  matrix_test.matrix[1][0] = 123;
  matrix_test1.matrix[1][0] = 63;
  matrix_test.matrix[1][1] = 123;
  matrix_test1.matrix[1][1] = 63;
  matrix_test.matrix[1][2] = -23;
  matrix_test1.matrix[1][2] = 25;
  matrix_test.matrix[2][0] = 123;
  matrix_test1.matrix[2][0] = 63;
  int x = s21_sub_matrix(&matrix_test, &matrix_test1, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_double_eq(matrix_result.matrix[0][0], 60.0);
  ck_assert_double_eq(matrix_result.matrix[1][0], 60.0);
  ck_assert_double_eq(matrix_result.matrix[2][0], 60.0);
  ck_assert_double_eq(matrix_result.matrix[0][1], 2.0);
  ck_assert_double_eq(matrix_result.matrix[0][2], 0.0);
  ck_assert_double_eq(matrix_result.matrix[1][1], 60.0);
  ck_assert_double_eq(matrix_result.matrix[1][2], -48.0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2_3) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  matrix_t matrix_result;
  s21_create_matrix(3, 2, &matrix_test);
  s21_create_matrix(3, 2, &matrix_test1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_test.matrix[i][j] = i;
      matrix_test1.matrix[i][j] = i;
    }
  }
  int x = s21_sub_matrix(&matrix_test, &matrix_test1, &matrix_result);
  ck_assert_int_eq(x, 0);
  ck_assert_double_eq(matrix_result.matrix[0][0], 0.0);
  ck_assert_double_eq(matrix_result.matrix[1][0], 0.0);
  ck_assert_double_eq(matrix_result.matrix[2][0], 0.0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

void test_s21_sub_matrix(SRunner *runner) {
  Suite *tests = suite_create("test_s21_sub_matrix");
  tests = add_test(tests, test_s21_sub_matrix_1_1);
  tests = add_test(tests, test_s21_sub_matrix_1_2);
  tests = add_test(tests, test_s21_sub_matrix_1_3);
  tests = add_test(tests, test_s21_sub_matrix_2_1);
  tests = add_test(tests, test_s21_sub_matrix_2_2);
  tests = add_test(tests, test_s21_sub_matrix_2_3);

  srunner_add_suite(runner, tests);
}