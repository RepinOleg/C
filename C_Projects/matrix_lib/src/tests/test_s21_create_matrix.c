#include "test.h"

START_TEST(test_s21_create_matrix_1_1) {
  matrix_t matrix_test;
  int x = s21_create_matrix(0, -1, &matrix_test);
  ck_assert_int_eq(x, 1);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix_1_2) {
  matrix_t matrix_test;
  int x = s21_create_matrix(1, 1, &matrix_test);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(matrix_test.rows, 1);
  ck_assert_int_eq(matrix_test.columns, 1);
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix_1_3) {
  matrix_t matrix_test;
  int x = s21_create_matrix(10, 8, &matrix_test);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(matrix_test.rows, 10);
  ck_assert_int_eq(matrix_test.columns, 8);
  s21_remove_matrix(&matrix_test);
}
END_TEST

void test_s21_create_matrix(SRunner *runner) {
  Suite *tests = suite_create("test_s21_create_matrix");
  tests = add_test(tests, test_s21_create_matrix_1_1);
  tests = add_test(tests, test_s21_create_matrix_1_2);
  tests = add_test(tests, test_s21_create_matrix_1_3);
  srunner_add_suite(runner, tests);
}
