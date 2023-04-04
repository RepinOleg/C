#ifndef SRC_TESTS_HELP_H
#define SRC_TESTS_HELP_H

#include "test.h"

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

typedef union test_decimal_bytes {
  struct s21_decimal d;
  struct {
    uint32_t part0;
    uint32_t part1;
    uint32_t part2;
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} test_decimal_bytes;

int test_decimal_get_sign(s21_decimal value);
int test_decimal_is_full_equal(s21_decimal value_1, s21_decimal value_2);
int test_decimal_get_power(s21_decimal value);
int s21_random_int(int min, int max);

#endif  // SRC_TESTS_HELP_H