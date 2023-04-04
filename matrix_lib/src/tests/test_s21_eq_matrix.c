#include "test.h"

START_TEST(test_s21_eq_matrix_1_1) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  int status = s21_eq_matrix(A, B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(A);
  s21_remove_matrix(B);
}
END_TEST

START_TEST(test_s21_eq_matrix_1_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(0, 4, &A);
  s21_create_matrix(0, 4, &B);
  int status = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_1_3) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 3, &matrix_test1);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;
  matrix_test1.matrix[0][0] = 1;
  matrix_test1.matrix[0][1] = 2;
  matrix_test1.matrix[0][2] = 3;
  matrix_test1.matrix[1][0] = 0;
  matrix_test1.matrix[1][1] = 4;
  matrix_test1.matrix[1][2] = 2;
  matrix_test1.matrix[2][0] = 2;
  matrix_test1.matrix[2][1] = 3;
  matrix_test1.matrix[2][2] = 4;
  int x = s21_eq_matrix(&matrix_test, &matrix_test1);
  ck_assert_int_eq(x, 1);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
}
END_TEST

START_TEST(test_s21_eq_matrix_1_4) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 0, &matrix_test1);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;

  int x = s21_eq_matrix(&matrix_test, &matrix_test1);
  ck_assert_int_eq(x, 0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
}
END_TEST

START_TEST(test_s21_eq_matrix_2_1) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 3, &matrix_test1);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;
  matrix_test1.matrix[0][0] = 1.0000001;
  matrix_test1.matrix[0][1] = 2.0000001;
  matrix_test1.matrix[0][2] = 3;
  matrix_test1.matrix[1][0] = 0;
  matrix_test1.matrix[1][1] = 4;
  matrix_test1.matrix[1][2] = 2;
  matrix_test1.matrix[2][0] = 2;
  matrix_test1.matrix[2][1] = 3;
  matrix_test1.matrix[2][2] = 4;
  int x = s21_eq_matrix(&matrix_test, &matrix_test1);
  ck_assert_int_eq(x, 0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
}
END_TEST

START_TEST(test_s21_eq_matrix_2_2) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 2, &matrix_test1);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;
  matrix_test1.matrix[0][0] = 1.0000001;
  matrix_test1.matrix[0][1] = 2.0000001;
  matrix_test1.matrix[1][0] = 0;
  matrix_test1.matrix[1][1] = 4;
  matrix_test1.matrix[2][0] = 2;
  int x = s21_eq_matrix(&matrix_test, &matrix_test1);
  ck_assert_int_eq(x, 0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
}
END_TEST

START_TEST(test_s21_eq_matrix_2_3) {
  matrix_t matrix_test;
  matrix_t matrix_test1;
  s21_create_matrix(3, 3, &matrix_test);
  s21_create_matrix(3, 0, &matrix_test1);
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 2;
  matrix_test.matrix[2][0] = 2;
  matrix_test.matrix[2][1] = 3;
  matrix_test.matrix[2][2] = 4;

  int x = s21_eq_matrix(&matrix_test, &matrix_test1);
  ck_assert_int_eq(x, 0);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_test1);
}
END_TEST

void test_s21_eq_matrix(SRunner *runner) {
  Suite *tests = suite_create("test_s21_eq_matrix");
  tests = add_test(tests, test_s21_eq_matrix_1_1);
  tests = add_test(tests, test_s21_eq_matrix_1_2);
  tests = add_test(tests, test_s21_eq_matrix_1_3);
  tests = add_test(tests, test_s21_eq_matrix_1_4);
  tests = add_test(tests, test_s21_eq_matrix_2_1);
  tests = add_test(tests, test_s21_eq_matrix_2_2);
  tests = add_test(tests, test_s21_eq_matrix_2_3);
  srunner_add_suite(runner, tests);
}
