#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

#define FALSE 0
#define TRUE 1

#define TEST_CONVERSION_OK 0
#define TEST_CONVERSION_ERROR 1

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;

//  Arithmetic operators
Suite *s21_test_add(void);
Suite *s21_test_mul(void);
Suite *s21_test_sub(void);
Suite *s21_test_fun(void);
Suite *s21_test_mod(void);
Suite *s21_test_div(void);

//  Comparison operators
Suite *s21_test_is_equal(void);
Suite *s21_test_is_greater_or_equal(void);
Suite *s21_test_is_greater(void);
Suite *s21_test_is_less(void);
Suite *s21_test_is_less_or_equal(void);
Suite *s21_test_is_not_equal(void);

//  Converters
Suite *s21_test_floor(void);
Suite *s21_test_negate(void);
Suite *s21_test_round(void);
Suite *s21_test_truncate(void);

// Another functions
Suite *s21_test_from_decimal_to_float(void);
Suite *s21_test_from_decimal_to_int(void);
Suite *s21_test_from_float_to_decimal(void);
Suite *s21_test_from_int_to_decimal(void);

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2, int code_check);
void test_mul_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);
void test_sub(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_sub_fail(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_mod_fail(s21_decimal decimal1, s21_decimal decimal2, int code_check);
void test_mod(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_div_fail1(s21_decimal decimal1, s21_decimal decimal2, int code_check);
void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);

void test_floor(s21_decimal decimal, s21_decimal decimal_check);
void test_negate(s21_decimal decimal, s21_decimal decimal_check);
void test_round(s21_decimal decimal, s21_decimal decimal_check);
void test_truncate(s21_decimal decimal, s21_decimal decimal_check);

void test_is_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                              int check);
void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_less(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                           int check);
void test_is_not_equal(s21_decimal decimal1, s21_decimal decimal2, int check);

void test_from_decimal_to_float(s21_decimal decimal, int check);
void test_from_decimal_to_int(s21_decimal decimal, int check);
void test_from_decimal_to_int_fail(s21_decimal decimal);
void test_from_float_to_decimal(int f, s21_decimal decimal_check);
void test_from_int_to_decimal(int number, s21_decimal decimal_check);

static const float fails_big[] = {
    340282346638528859811704183484516925440.f,
    340282326356119256160033759537265639424.f,
    340282306073709652508363335590014353408.f,
    170141173319264429905852091742258462720.f,
    226854897759019239874469455656344616960.f,
    283568632339978851668922031544056414208.f,
    85070586659632214952926045871129231360.f,
    85070591730234615865843651857942052864.f,
    5316911666227013434557877866945576960.f,
    2658455991569831745807614120560689152.f,
    20769186196199271228741710417756160.f,
    10384593717069655257060992658440192.f,
    158456325028528675187087900672.0f,
    158456315583795709447797473280.0f,
    158456306139062743708507045888.0f,
    316912631167591418895594946560.f,
    158456325028528675187087900672.f,
    79228190848463234811415232512.f,
    79228181403730269072124805120.f,
    79228171958997303332834377728.f,
    79228162514264337593543950336.f,
    79228162514264337593543950335.f,
};

static const float fails_small[] = {
    0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f,
    0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f,
    0.00000000000000000000000000009999998226151445646676901231373326364778153626990814f,
    0.00000000000000000000000000009000000028539691658739462124217382784332763280814999f,
    0.00000000000000000000000000005000000015855384254855256735676323769073757378230555f,
    0.00000000000000000000000000004999999714928830444349654695679770240178863856652172f,
    4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29f,
    1.2621774483536188886587657044524579674771302961744368076324462890625E-29f,
    1.0000000031710768509710513471352647538147514756461109453056224083411507308483123779296875E-29f,
    7.7037193183714626222678539700519994217126886949453196668630670929101000865557580254971981E-34f,
    4.8148245739821641389174087312824996385704304343408247917894169330688125540973487659357488E-35f,
    1.1754943508222875079687365372222456778186655567720875215087517062784172594547271728515625E-38f,
    1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f,
};

#endif  // SRC_TESTS_TEST_H