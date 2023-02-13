#ifndef SRC_ALL_TEST
#define SRC_ALL_TEST

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define S21_NULL ((void *)0)

#include "../s21_sscanf.h"
#include "../s21_string.h"

Suite *test_fun(void);
Suite *test_sscanf_c(void);
Suite *test_sscanf_d(void);
Suite *test_sscanf_i(void);
Suite *test_sscanf_o(void);
Suite *test_sscanf_x(void);
Suite *test_sscanf_p(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_real(void);
Suite *test_sscanf_empty(void);

Suite *test_sprintf_c(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_g(void);

Suite *test_sprintf(void);
Suite *test_sprintf_signed(void);
Suite *test_sprintf_signed_i(void);
Suite *test_sprintf_octal(void);
Suite *test_sprintf_unsigned(void);
Suite *test_sprintf_hex(void);
Suite *test_sprintf_HEX(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_pointer(void);
Suite *test_sprintf_n(void);
Suite *test_sprintf_new(void);

Suite *test_sprintf_string(void);

#endif  // SRC_ALL_TEST