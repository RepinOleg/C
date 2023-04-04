#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

#define OK 0
#define INCORRECT 1
#define ERROR 2

Suite *add_test(Suite *suite, const TTest *test);

void test_s21_create_matrix(SRunner *runner);
void test_s21_remove_matrix(SRunner *runner);
void test_s21_eq_matrix(SRunner *runner);
void test_s21_sum_matrix(SRunner *runner);
void test_s21_sub_matrix(SRunner *runner);
void test_s21_mult_number(SRunner *runner);
void test_s21_mult_matrix(SRunner *runner);
void test_s21_transpose(SRunner *runner);
void test_s21_calc_complements(SRunner *runner);
void test_s21_determinant(SRunner *runner);
void test_s21_inverse_matrix(SRunner *runner);
void test_s21_matrix(SRunner *runner);

#endif  // SRC_TEST_H_
