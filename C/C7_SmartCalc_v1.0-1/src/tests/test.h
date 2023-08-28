#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <check.h>
#include <stdio.h>

#include "../s21_smart_calc.h"

Suite *add_test(Suite *suite, const TTest *test);

void test_s21_smart_calc(SRunner *runner);

#endif  // SRC_TEST_H_
