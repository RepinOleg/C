#include "tests.h"

#include <math.h>
#include <stdio.h>
#include <time.h>

#include "check.h"

#define LEN 256

START_TEST(s21_tan_inf_tests) {
  long double result = s21_tan(S21_NAN);
  // test 1
  ck_assert_ldouble_nan(result);

  result = s21_tan(+S21_INFINITY);
  // test 2
  ck_assert_ldouble_nan(result);

  // test 3
  result = s21_tan(-S21_INFINITY);
  ck_assert_ldouble_nan(result);
}
END_TEST

START_TEST(s21_fmod_inf_tests) {
  // test 1
  long double result = s21_fmod(21., S21_INFINITY);
  ck_assert_ldouble_eq_tol(21., result, 0.000001);

  // test 2
  result = s21_fmod(42., -S21_INFINITY);
  ck_assert_ldouble_eq_tol(42., result, 0.000001);

  // test 3
  result = s21_fmod(-21., -S21_INFINITY);
  ck_assert_ldouble_eq_tol(-21., result, 0.000001);

  // test 4
  result = s21_fmod(-42., S21_INFINITY);
  ck_assert_ldouble_eq_tol(-42., result, 0.000001);

  // test 5
  result = s21_fmod(S21_INFINITY, S21_INFINITY);
  ck_assert_ldouble_nan(result);

  // test 6
  result = s21_fmod(-S21_INFINITY, S21_INFINITY);
  ck_assert_ldouble_nan(result);

  // test 7
  result = s21_fmod(S21_INFINITY, -S21_INFINITY);
  ck_assert_ldouble_nan(result);

  // test 8
  result = s21_fmod(-S21_INFINITY, -S21_INFINITY);
  ck_assert_ldouble_nan(result);

  // test 9
  result = s21_fmod(S21_NAN, 42.);
  ck_assert_ldouble_nan(result);

  // test 10
  result = s21_fmod(21., S21_NAN);
  ck_assert_ldouble_nan(result);

  // test 10
  result = s21_fmod(S21_NAN, S21_NAN);
  ck_assert_ldouble_nan(result);
}
END_TEST

START_TEST(s21_infnan_tests) {
  // test 1
  long double result = s21_pow(S21_NAN, 10);
  ck_assert_ldouble_nan(result);

  // test 2
  result = s21_pow(10, S21_NAN);
  ck_assert_ldouble_nan(S21_NAN);

  // test 3
  result = s21_pow(1., S21_INFINITY);
  ck_assert_ldouble_eq(result, 1.);

  // test 4
  result = s21_pow(1., -S21_INFINITY);
  ck_assert_ldouble_eq(result, 1.);

  // test 5
  result = s21_pow(S21_INFINITY, 0);
  ck_assert_ldouble_eq(result, 1.);

  // test 6
  result = s21_pow(-S21_INFINITY, 0);
  ck_assert_ldouble_eq(result, 1.);

  // test 7
  result = s21_pow(0, -5);
  ck_assert_ldouble_infinite(result);

  // test 8
  result = s21_pow(0, 5);
  ck_assert_ldouble_eq(result, 0.);
}
END_TEST

START_TEST(s21_sin_inf_tests) {
  // test 1
  long double result = s21_sin(+S21_INFINITY);
  ck_assert_ldouble_nan(result);

  // test 2
  result = s21_sin(S21_NAN);
  ck_assert_ldouble_nan(result);

  // test 3
  result = s21_sin(-S21_INFINITY);
  ck_assert_ldouble_nan(result);
}
END_TEST

START_TEST(s21_fabs_infnan_tests) {
  // test 1
  long double result = s21_fabs(S21_NAN);
  ck_assert_ldouble_nan(result);

  // test 2
  result = s21_fabs(S21_INFINITY);
  ck_assert_ldouble_infinite(result);

  // test 3
  result = s21_fabs(-S21_INFINITY);
  ck_assert_ldouble_infinite(result);
}
END_TEST

START_TEST(s21_abs_tests) {
  // test 1
  ck_assert_int_eq(s21_abs(1), abs(1));

  // test 2
  ck_assert_int_eq(s21_abs(0), abs(0));

  // test 3
  ck_assert_int_eq(s21_abs(-100), abs(-100));

  // test 4
  ck_assert_int_eq(s21_abs(-0), abs(-0));

  // test 5
  ck_assert_int_eq(s21_abs(-1000000), abs(-1000000));
}
END_TEST

START_TEST(s21_sin_tests) {
  // test 1
  ck_assert_float_eq(s21_sin(0.5), sin(0.5));

  // test 2
  ck_assert_float_eq(s21_sin(1), sin(1));

  // test 3
  ck_assert_float_eq(s21_sin(S21_EPS), sin(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_sin(0.123), sin(0.123));

  // test 5
  ck_assert_float_eq(s21_sin(-0.123), sin(-0.123));

  // test 5
  ck_assert_float_eq(s21_sin(0), sin(0));

  // test 6
  ck_assert_float_eq(s21_sin(-0), sin(-0));

  // test 7
  ck_assert_float_eq(s21_sin(S21_ESP), sin(S21_ESP));

  // test 8
  ck_assert_float_eq(s21_sin(7.18), sin(7.18));

  // test 9
  ck_assert_float_eq(s21_sin(-3.14), sin(-3.14));
}
END_TEST

START_TEST(s21_tan_tests) {
  // test 1
  ck_assert_float_eq(s21_tan(0.5), tan(0.5));

  // test 2
  ck_assert_float_eq(s21_tan(1), tan(1));

  // test 3
  ck_assert_float_eq(s21_tan(S21_EPS), tan(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_tan(0.123), tan(0.123));
}
END_TEST

START_TEST(s21_cos_tests) {
  // test 1
  ck_assert_float_eq(s21_cos(0.5), cos(0.5));

  // test 2
  ck_assert_float_eq(s21_cos(1), cos(1));

  // test 3
  ck_assert_float_eq(s21_cos(S21_EPS), cos(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_cos(0.123), cos(0.123));
}
END_TEST

START_TEST(s21_fmod_tests) {
  // test 1
  ck_assert_float_eq(s21_fmod(0.5, 2.0), fmod(0.5, 2.0));

  // test 2
  ck_assert_float_eq(s21_fmod(30., 4.), fmod(30., 4.));

  // test 3
  ck_assert_float_eq(s21_fmod(30., 5.), fmod(30., 5.));

  // test 4
  ck_assert_float_eq(s21_fmod(5., 5.), fmod(5., 5.));

  // test 5
  ck_assert_float_eq(s21_fmod(0., 5.), fmod(0., 5.));

  // test 6
  ck_assert_float_eq(s21_fmod(0.2, 5.), fmod(0.2, 5.));

  // test 7
  ck_assert_float_eq(s21_fmod(54.456, 5.), fmod(54.456, 5.));

  // test 8
  ck_assert_float_eq(s21_fmod(-54.456, -5.), fmod(-54.456, -5.));

  // test 9
  ck_assert_float_eq(s21_fmod(-54.456, 5.), fmod(-54.456, 5.));

  // test 10
  ck_assert_float_eq(s21_fmod(54.456, -5.), fmod(54.456, -5.));

  // test 11
  ck_assert_float_eq(s21_fmod(5.456, -6.), fmod(5.456, -6.));

  // test 12
  ck_assert_float_eq(s21_fmod(-5.456, -6.), fmod(-5.456, -6.));

  // test 13
  ck_assert_float_eq(s21_fmod(-5.456, 6.), fmod(-5.456, 6.));
}
END_TEST

START_TEST(s21_fabs_tests) {
  // test 1
  ck_assert_float_eq(s21_fabs(1.000000), fabs(1.000000));

  // test 2
  ck_assert_float_eq(s21_fabs(-1.00000), fabs(-1.00000));

  // test 3
  ck_assert_float_eq(s21_fabs(-1436.6789), fabs(-1436.6789));

  // test 4
  ck_assert_float_eq(s21_fabs(-0.5682), fabs(-0.5682));

  // test 5
  ck_assert_float_eq(s21_fabs(-0.0), fabs(-0.0));
}
END_TEST

START_TEST(s21_asin_tests) {
  // test 1
  ck_assert_float_eq(s21_asin(0.55555), asin(0.55555));

  // test 2
  ck_assert_float_eq(s21_asin(1), asin(1));

  // test 3
  ck_assert_float_eq(s21_asin(S21_EPS), asin(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_asin(0.123), asin(0.123));

  // test 5
  ck_assert_float_nan(s21_asin(5));
  ck_assert_float_nan(asin(5));

  // test 6
  ck_assert_float_eq(s21_asin(-1), asin(-1));
}
END_TEST

START_TEST(s21_atan_tests) {
  // test 1
  ck_assert_float_eq(s21_atan(0.5789), atan(0.5789));

  // test 2
  ck_assert_float_eq(s21_atan(1), atan(1));

  // test 3
  ck_assert_float_eq(s21_atan(S21_EPS), atan(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_atan(0.123), atan(0.123));

  // test 5
  ck_assert_float_eq(s21_atan(-1), atan(-1));

  // test 6
  ck_assert_float_eq(s21_atan(-S21_EPS), atan(-S21_EPS));

  // test 7
  ck_assert_float_eq(s21_atan(-0.1), atan(-0.1));

  // test 8
  ck_assert_float_eq(s21_atan(-100000000), atan(-100000000));

  // test 9
  ck_assert_float_eq(s21_atan(-10.00001), atan(-10.00001));

  // test 10
  ck_assert_float_eq(s21_atan(-0.00007), atan(-0.00007));

  // test 11
  ck_assert_float_eq(s21_atan(100000000), atan(100000000));
}
END_TEST

START_TEST(s21_sqrt_tests) {
  // test 1
  ck_assert_float_eq(s21_sqrt(0.5), sqrt(0.5));

  // test 2
  ck_assert_float_eq(s21_sqrt(4), sqrt(4));

  // test 3
  ck_assert_float_eq(s21_sqrt(22.5), sqrt(22.5));

  // test 4
  ck_assert_float_eq(s21_sqrt(17), sqrt(17));

  // test 5
  ck_assert_float_eq(s21_sqrt(900), sqrt(900));

}
END_TEST

START_TEST(s21_floor_tests) {
  // test 1
  ck_assert_float_eq(s21_floor(0.5), floor(0.5));

  // test 2
  ck_assert_float_eq(s21_floor(4.3), floor(4.3));

  // test 3
  ck_assert_float_eq(s21_floor(22.6), floor(22.6));

  // test 4
  ck_assert_float_eq(s21_floor(17), floor(17));

  // test 5
  ck_assert_float_eq(s21_floor(-17), floor(-17));

  // test 6
  ck_assert_float_eq(s21_floor(-3.6), floor(-3.6));

  // test 7
  ck_assert_float_eq(s21_floor(-10.56789), floor(-10.56789));

  // test 8
  ck_assert_float_eq(s21_floor(-10.99999), floor(-10.99999));
}
END_TEST

START_TEST(s21_exp_tests) {
  // test 1
  ck_assert_float_eq(s21_exp(0), exp(0));

  // test 2
  ck_assert_float_eq(s21_exp(3), exp(3));

  // test 3
  ck_assert_float_eq(s21_exp(-10), exp(-10));

  // test 4
  ck_assert_float_eq(s21_exp(10.5678), exp(10.5678));
}
END_TEST

START_TEST(s21_log_tests) {
  // test 1
  ck_assert_float_eq(s21_log(0.0001), log(0.0001));

  // test 2
  ck_assert_float_nan(s21_log(-10));
  ck_assert_float_nan(log(-10));

  // test 3
  ck_assert_float_eq(s21_log(3456), log(3456));

  // test 4
  ck_assert_float_eq(s21_log(3456.3456), log(3456.3456));

  // test 5
  ck_assert_float_infinite(s21_log(0));
  ck_assert_float_infinite(log(0));
}
END_TEST

START_TEST(s21_pow_tests) {
  // test 1
  ck_assert_float_eq(s21_pow(1.567, 10), pow(1.567, 10));

  // test 2
  ck_assert_float_eq(s21_pow(10, 10), pow(10, 10));

  // test 3
  ck_assert_float_nan(s21_pow(-1.456, -78.567));
  ck_assert_float_nan(pow(-1.456, -78.567));

  // test 4
  ck_assert_float_eq(s21_pow(0.0, -78), pow(0.0, -78));

  // test 5
  ck_assert_float_eq(s21_pow(0, -0.01), pow(0, -0.01));

  // test 5
  ck_assert_float_eq(s21_pow(0, 0.0000001), pow(0, 0.00000001));

  // test 6
  ck_assert_float_eq(s21_pow(-0.0, 78), pow(-0.0, 78));

  // test 7
  ck_assert_float_eq(s21_pow(-0.0, -78), pow(-0.0, -78));

  // test 8
  ck_assert_float_nan(s21_pow(-1.7899, 78.89));
  ck_assert_float_nan(pow(-1.7899, 78.89));

  // test 8
  ck_assert_float_eq(s21_pow(-456.7898, -78), pow(-456.7898, -78));

  // test 9
  ck_assert_float_eq(s21_pow(0, S21_INFINITY), pow(0, S21_INFINITY));
}
END_TEST

START_TEST(s21_acos_tests) {
  // test 1
  ck_assert_float_eq(s21_acos(0.5), acos(0.5));

  // test 2
  ck_assert_float_eq(s21_acos(1), acos(1));

  // test 3
  ck_assert_float_eq(s21_acos(S21_EPS), acos(S21_EPS));

  // test 4
  ck_assert_float_eq(s21_acos(-0.0000001), acos(-0.0000001));

  // test 5
  ck_assert_float_eq(s21_acos(0.1233333333), acos(0.1233333333));

  // test 6
  ck_assert_ldouble_nan(s21_acos(5));

  // test 7
  ck_assert_ldouble_nan(s21_acos(-5));
}
END_TEST

START_TEST(s21_ceil_tests) {
  // test 1
  ck_assert_float_eq(s21_ceil(0.5), ceil(0.5));

  // test 2
  ck_assert_float_eq(s21_ceil(4.3), ceil(4.3));

  // test 3
  ck_assert_float_eq(s21_ceil(22.6), ceil(22.6));

  // test 4
  ck_assert_float_eq(s21_ceil(17), ceil(17));

  // test 5
  ck_assert_float_eq(s21_ceil(-17), ceil(-17));

  // test 6
  ck_assert_float_eq(s21_ceil(-3.6), ceil(-3.6));

  // test 7
  ck_assert_float_eq(s21_ceil(-6.4), ceil(-6.4));

  // test 8
  ck_assert_float_eq(s21_ceil(-10.56732), ceil(-10.56732));

  // test 9
  ck_assert_float_eq(s21_ceil(-10.9999), ceil(-10.9999));
}
END_TEST

START_TEST(s21_sin_random_tests) {
  srand(time(NULL));

  size_t n = 10;
  double lowerBorder = -10 * S21_MATH_PI;
  double upperBorder = 10 * S21_MATH_PI;

  for (size_t i = 0; i < n; i++) {
    double arg =
        lowerBorder + (rand() / (double)RAND_MAX) * (upperBorder - lowerBorder);
    long double result = s21_sin(arg);
    double expected = sin(arg);
    ck_assert_ldouble_eq_tol(expected, result, 0.000001);
  }
}
END_TEST



START_TEST(s21_factorial_tests) {
  long double result = s21_factorial(-1);
  ck_assert_float_finite(result);

  result = s21_factorial(5);
  ck_assert_float_finite(result);
}
END_TEST

START_TEST(s21_exp_fast_tests) {
  // test 1
  long double result = s21_exp(-S21_EPS);
  ck_assert_ldouble_finite(result);

  // test 2
  result = s21_exp(S21_INFINITY);
  ck_assert_ldouble_finite(result);
}
END_TEST

Suite *s21_math(void) {
  Suite *s;
  TCase *tc_tests;

  s = suite_create("s21_math.h tests");
  tc_tests = tcase_create("TESTS");

  tcase_add_test(tc_tests, s21_exp_fast_tests);
  tcase_add_test(tc_tests, s21_factorial_tests);
  tcase_add_test(tc_tests, s21_sin_random_tests);
  tcase_add_test(tc_tests, s21_tan_inf_tests);
  tcase_add_test(tc_tests, s21_fmod_inf_tests);
  tcase_add_test(tc_tests, s21_sin_inf_tests);
  tcase_add_test(tc_tests, s21_fabs_infnan_tests);
  tcase_add_test(tc_tests, s21_infnan_tests);
  tcase_add_test(tc_tests, s21_acos_tests);
  tcase_add_test(tc_tests, s21_ceil_tests);
  tcase_add_test(tc_tests, s21_asin_tests);
  tcase_add_test(tc_tests, s21_atan_tests);
  tcase_add_test(tc_tests, s21_sin_tests);
  tcase_add_test(tc_tests, s21_cos_tests);
  tcase_add_test(tc_tests, s21_tan_tests);
  tcase_add_test(tc_tests, s21_sqrt_tests);
  tcase_add_test(tc_tests, s21_floor_tests);
  tcase_add_test(tc_tests, s21_fmod_tests);
  tcase_add_test(tc_tests, s21_abs_tests);
  tcase_add_test(tc_tests, s21_fabs_tests);
  tcase_add_test(tc_tests, s21_exp_tests);
  tcase_add_test(tc_tests, s21_log_tests);
  tcase_add_test(tc_tests, s21_pow_tests);

  

  suite_add_tcase(s, tc_tests);

  return s;
}

int main() {
  Suite *s;
  SRunner *runner;

  s = s21_math();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_VERBOSE);
  srunner_ntests_failed(runner);
  srunner_free(runner);

  return 0;
}
