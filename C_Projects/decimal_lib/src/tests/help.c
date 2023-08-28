
#include "help.h"

int test_decimal_is_full_equal(s21_decimal value_1, s21_decimal value_2) {
  union {
    struct s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes1;

  union {
    struct s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes2;

  decimal_bytes1.d = value_1;
  decimal_bytes2.d = value_2;

  return decimal_bytes1.parts.part0 == decimal_bytes2.parts.part0 &&
         decimal_bytes1.parts.part1 == decimal_bytes2.parts.part1 &&
         decimal_bytes1.parts.part2 == decimal_bytes2.parts.part2 &&
         decimal_bytes1.parts.part3 == decimal_bytes2.parts.part3;
}

int test_decimal_get_sign(s21_decimal value) {
  test_decimal_bytes decimal_bytes;
  decimal_bytes.d = value;
  return decimal_bytes.parts.sign;
}

int test_decimal_get_power(s21_decimal value) {
  test_decimal_bytes decimal_bytes;
  decimal_bytes.d = value;
  return decimal_bytes.parts.power;
}

int s21_random_int(int min, int max) {
  if (min < 0) {
    min = 0;
  }

  if (max < 0) {
    max = -max;
  }

  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}