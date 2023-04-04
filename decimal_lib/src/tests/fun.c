
#include "test.h"

// TODO: прверить значения
//! value_1.bits[0] = 4294967295;

START_TEST(part1_add_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  s21_set_exp(&value_2, 1);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(part1_add_both_neg) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  s21_set_sign(&value_2, 1);
  s21_set_sign(&value_1, 1);
  s21_set_exp(&value_2, 1);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(part1_add_error) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  //! value_1.bits[0] = 4294967295;
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 35;
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
  s21_set_sign(&value_2, 1);
  s21_set_sign(&value_1, 1);

  memset(&result, 0, sizeof(s21_decimal));
  res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(part1_add_one_greater) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 540;
  value_2.bits[0] = 560;
  s21_decimal test = {{20}};
  s21_set_sign(&value_2, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_add_one_sign) {
  s21_decimal value_1 = {{150}};
  s21_decimal value_2 = {{50}};
  s21_decimal result = {0};
  s21_decimal test = {{100}};
  s21_set_sign(&value_1, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 1);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  memset(&result, 0, sizeof(s21_decimal));
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

// sub

START_TEST(part1_sub_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 155;
  value_2.bits[0] = 55;
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  memset(&result, 0, sizeof(s21_decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)150;
  s21_sub(value_1, value_2, &result);
  int sign = s21_get_sign(result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(sign, 1);

  memset(&value_1, 0, sizeof(s21_decimal));
  memset(&value_2, 0, sizeof(s21_decimal));
  memset(&result, 0, sizeof(s21_decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)15;
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_exp(&value_2, 1);
  s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], 485);
  ck_assert_uint_eq(s21_get_exp(result), 1);
  ck_assert_uint_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(part1_sub_inf) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  //! value_1.bits[0] = 4294967295;
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 55;
  s21_set_sign(&value_1, 1);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_sub_one_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_sign(&value_1, 1);
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 200;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

START_TEST(part1_sub_two_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);

  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 1);
  value_1.bits[0] = 50;
  value_2.bits[0] = 150;
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

// mult

START_TEST(part1_mult_value_1_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 1;
  value_2.bits[0] = 10;
  test.bits[0] = 10;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  s21_set_sign(&value_1, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_max) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  //! value_1.bits[0] = 4294967295;
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 1);

  s21_set_sign(&value_2, 1);
  res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_mult_big_power) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 2147483647;
  value_2.bits[0] = 255;
  test.bits[0] = 2147483393;
  test.bits[1] = 127;
  s21_set_exp(&value_2, 10);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_uint_eq(s21_get_exp(result), 10);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part1_mult_big_negative_over) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 2147483647;
  value_1.bits[1] = 2147483647;
  value_1.bits[2] = 2147483647;
  value_2.bits[0] = 15;
  s21_set_exp(&value_2, 1);
  s21_set_sign(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_mult_big_over) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 2147483647;
  value_1.bits[1] = 2147483647;
  value_1.bits[2] = 2147483647;
  value_2.bits[0] = 15;
  s21_set_exp(&value_2, 1);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 1);
}
END_TEST

START_TEST(part1_mult_value_1_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  s21_set_sign(&value_2, 1);
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  s21_set_sign(&value_2, 1);
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_1_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  s21_set_exp(&value_1, 5);
  s21_set_exp(&value_2, 29);
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

// div

START_TEST(part1_div_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  int res = s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 3);

  s21_set_sign(&value_1, 1);
  res = s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 3);
}
END_TEST

START_TEST(part2_div) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  int res = s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 3);
}
END_TEST

START_TEST(part3_div) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 1000;
  value_2.bits[0] = 100;
  test.bits[0] = 1000000;
  int res = s21_div(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

// // mod

START_TEST(part1_mod) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 1000;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part2_mod) {
  s21_decimal value_1 = {{0}};
  s21_decimal value_2 = {{0}};
  s21_decimal result = {{0}};
  s21_decimal test = {{0}};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_exp(&value_2, 1);
  value_1.bits[0] = 1000;
  value_2.bits[0] = 1007;
  test.bits[0] = 937;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(s21_get_exp(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part3_mod) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  value_1.bits[0] = 5;
  value_2.bits[0] = 10;
  test.bits[0] = 5;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part4_mod) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_exp(&value_1, 3);
  s21_set_exp(&value_2, 6);
  value_1.bits[0] = 1565;
  value_2.bits[0] = 109397;
  test.bits[0] = 33442;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(s21_get_exp(result), 6);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 1);
  ck_assert_uint_eq(s21_get_exp(result), 6);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(s21_get_exp(result), 6);
  ck_assert_uint_eq(res, 0);

  s21_set_sign(&value_2, 0);
  res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_get_sign(result), 0);
  ck_assert_uint_eq(s21_get_exp(result), 6);
  ck_assert_uint_eq(res, 0);
}
END_TEST

START_TEST(part5_mod) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  s21_set_exp(&value_1, 3);
  s21_set_exp(&value_2, 6);
  value_1.bits[0] = 1565;
  int res = s21_mod(value_1, value_2, &result);
  ck_assert_uint_eq(res, 3);
}
END_TEST

// COMPARISON

// less

START_TEST(part2_less_null) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
}
END_TEST

START_TEST(part2_less_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 0; i < 50; i++) {
    for (int j = 2; j < 52; j++) {
      for (int i = 0, j = 2; i < 50 || j < 51; i++, j++) {
        value_1.bits[0] = i;
        value_2.bits[0] = j;
        ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
        ck_assert_int_eq(s21_is_less(value_2, value_1), FALSE);
      }
    }
  }
}
END_TEST

START_TEST(part2_less_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);

  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);

  for (int i = 50; i < 0; i++) {
    for (int j = 48; j < 2; j++) {
      value_1.bits[0] = i;
      value_2.bits[0] = j;
      ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
      ck_assert_int_eq(s21_is_less(value_2, value_1), FALSE);
    }
  }
}
END_TEST

START_TEST(part2_less_pow) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 50;
  value_2.bits[0] = 30;
  s21_set_exp(&value_1, 8);
  s21_set_exp(&value_2, 8);
  ck_assert_int_eq(s21_is_less(value_1, value_2), FALSE);
  s21_set_exp(&value_2, 0);
  ck_assert_int_eq(s21_is_less(value_1, value_2), TRUE);
}
END_TEST

// less or equal

START_TEST(part2_less_or_equal_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 0, j = 1; i < 51 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
  }
  for (int i = 0, j = 0; i < 52 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
  }
}
END_TEST

START_TEST(part2_less_or_equal_with_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 123450;
  value_2.bits[0] = 123450;

  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), FALSE);

  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);

  s21_set_sign(&value_2, 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), TRUE);
}
END_TEST

// greater

START_TEST(part2_greater_null) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(part2_greater_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 1, j = 2; i < 50 || j < 51; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
    ck_assert_int_eq(s21_is_greater(value_2, value_1), TRUE);
  }
}
END_TEST

START_TEST(part2_greater_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
}
END_TEST

START_TEST(part2_greater_two_negative) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 20;
  value_2.bits[0] = 5;
  s21_set_sign(&value_1, 1);
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

START_TEST(part2_greater_pow) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 50;
  value_2.bits[0] = 30;
  s21_set_exp(&value_1, 8);
  s21_set_exp(&value_2, 8);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), TRUE);
  s21_set_exp(&value_2, 0);
  ck_assert_int_eq(s21_is_greater(value_1, value_2), FALSE);
}
END_TEST

// greater or equal

START_TEST(part2_greater_or_equal_normal) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  for (int i = 0, j = 1; i < 51 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
  }
  for (int i = 0, j = 0; i < 52 || j < 52; i++, j++) {
    value_1.bits[0] = i;
    value_2.bits[0] = j;
    ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  }
}
END_TEST

START_TEST(part2_greater_or_equal_with_sign) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  value_1.bits[0] = 123450;
  value_2.bits[0] = 123450;
  s21_set_sign(&value_2, 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  s21_set_sign(&value_1, 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), TRUE);
  s21_set_sign(&value_2, 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), FALSE);
}
END_TEST

// equal

START_TEST(part2_equal_1) {
  s21_decimal a = {{56, 0}}, b = {{56, 0}};
  ck_assert_uint_eq(s21_is_equal(a, b), TRUE);
}
END_TEST

START_TEST(part2_equal_2) {
  s21_decimal a = {{0, 0, 0, 1}}, b = {{0, 0, 0, 2147483647}};
  ck_assert_uint_eq(s21_is_equal(a, b), TRUE);
}
END_TEST

START_TEST(part2_equal_3) {
  s21_decimal a = {{0}}, b = {{0}};
  ck_assert_uint_eq(s21_is_equal(a, b), TRUE);
}
END_TEST

START_TEST(part2_equal_4) {
  s21_decimal a = {{111, 111, 122, 1}}, b = {{111, 111, 122, 1}};
  ck_assert_uint_eq(s21_is_equal(a, b), TRUE);
}
END_TEST

START_TEST(part2_equal_5) {
  s21_decimal a = {{111, 11231, 12332, 12222}}, b = {{111, 111, 122, 1}};
  ck_assert_uint_eq(s21_is_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_equal_6) {
  s21_decimal a = {{111, 11, 12332, 1222222}},
              b = {{119981, 1100001, 122, 1000001}};
  ck_assert_uint_eq(s21_is_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_equal_7) {
  s21_decimal a = {{0}}, b = {{0}};
  a.bits[0] = 12;
  b.bits[0] = 120;
  s21_set_exp(&a, 1);
  s21_set_exp(&b, 2);
  ck_assert_uint_eq(s21_is_equal(a, b), TRUE);
}
END_TEST

// not equal

START_TEST(part2_notequal_1) {
  s21_decimal a = {{56, 0}}, b = {{56, 0}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_notequal_2) {
  s21_decimal a = {{0, 0, 0, 2147483647}}, b = {{0, 0, 0, 2147483647}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_notequal_3) {
  s21_decimal a = {{0}}, b = {{0}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_notequal_4) {
  s21_decimal a = {{111, 111, 122, 1}}, b = {{111, 111, 122, 1}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), FALSE);
}
END_TEST

START_TEST(part2_notequal_5) {
  s21_decimal a = {{111, 11231, 12332, 12222}}, b = {{111, 111, 122, 1}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), TRUE);
}
END_TEST

START_TEST(part2_notequal_6) {
  s21_decimal a = {{111, 11, 12332, 1222222}},
              b = {{119981, 1100001, 122, 1000001}};
  ck_assert_uint_eq(s21_is_not_equal(a, b), TRUE);
}
END_TEST

// CONVERT

// from_int_to_decimal
START_TEST(part1_conv_int) {
  int a = 123123;
  s21_decimal result = {0};
  s21_from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], a);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);
  a = 2147483647;
  s21_from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], a);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);
  a = -2147483648;
  s21_from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], abs(a));
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);

  a = 0;
  s21_decimal temp = {0};
  //! init(&temp) ;
  temp.bits[0] = 1U;
  s21_set_sign(&temp, 1);
  s21_from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, -1);

  a = 0;
  //! init(&temp);
  temp.bits[0] = 1U;
  temp.bits[3] = 0;
  s21_from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, 1);

  a = 0;
  //! init(&temp);
  temp.bits[0] = 123;
  temp.bits[1] = 123;
  int res = 0;
  res = s21_from_decimal_to_int(temp, &a);
  ck_assert_uint_eq(res, 1);
}
END_TEST

// FLOAT

START_TEST(part1_conv_float) {
  s21_decimal temp = {0};
  //! init(&temp);
  float a = 0.0;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 0);
  ck_assert_int_eq(s21_get_sign(temp), 0);

  //! init(&temp);
  a = 20.0;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(s21_get_sign(temp), 0);
  ck_assert_int_eq(s21_get_exp(temp), 0);

  //! init(&temp);
  a = -20.0;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(s21_get_sign(temp), 1);
  ck_assert_int_eq(s21_get_exp(temp), 0);

  //! init(&temp);
  a = 0.0 / 0.0;
  int res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  //! init(&temp);
  a = 1.0 / 0.0;
  res = 0;
  res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  //! init(&temp);
  a = -1.0 / 0.0;
  res = 0;
  res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  //! init(&temp);
  a = 0;
  temp.bits[0] = 45;
  s21_set_exp(&temp, 1);
  s21_from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, 4.5);

  //! init(&temp);
  a = 0;
  temp.bits[0] = 45;
  s21_set_exp(&temp, 1);
  s21_set_sign(&temp, 1);
  s21_from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, -4.5);
}
END_TEST

// ANOTHER

START_TEST(part4_negate_normal) {
  s21_decimal value_1 = {{154345}};
  s21_decimal result = {0};
  s21_decimal test = {{154345}};
  s21_set_sign(&value_1, 0);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part4_negate_null) {
  s21_decimal value_1 = {{0}};
  s21_decimal result = {0};
  s21_decimal test = {0};
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(part4_negate_negative) {
  s21_decimal value_1 = {{123455}};
  s21_decimal result = {0};
  s21_decimal test = {{123455}};
  s21_set_sign(&value_1, 1);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(part4_negate_pow) {
  s21_decimal value_1 = {{123455}};
  s21_decimal result = {0};
  s21_decimal test = {{123455}};
  s21_set_sign(&value_1, 1);
  s21_set_exp(&value_1, 3);
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 3);
}
END_TEST

START_TEST(part1_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 97;
  test.bits[0] = 97;
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part2_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 976546;
  test.bits[0] = 976;
  s21_set_exp(&value_1, 3);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  test.bits[0] = 977;
  s21_set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part3_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 9765;
  test.bits[0] = 976;
  s21_set_exp(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  test.bits[0] = 977;
  s21_set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part4_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part5_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 30);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 30);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part1_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 97;
  test.bits[0] = 97;
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part2_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 976546;
  test.bits[0] = 977;
  s21_set_exp(&value_1, 3);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  test.bits[0] = 977;
  s21_set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part3_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 9765;
  test.bits[0] = 977;
  s21_set_exp(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part4_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part5_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 30);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part1_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 97;
  test.bits[0] = 97;
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part2_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 976546;
  test.bits[0] = 976;
  s21_set_exp(&value_1, 3);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part3_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 9765;
  test.bits[0] = 976;
  s21_set_exp(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part4_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

START_TEST(part5_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  s21_set_exp(&value_1, 30);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_exp(result), 0);

  s21_set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_exp(result), 0);
}
END_TEST

Suite *s21_test_fun(void) {
  Suite *s = suite_create("\033[43m-=s21_fun=-\033[0m");
  TCase *tc = tcase_create("fun_rc");

  tcase_add_test(tc, part1_add_normal);
  tcase_add_test(tc, part1_add_both_neg);
  tcase_add_test(tc, part1_add_error);
  tcase_add_test(tc, part1_add_one_sign);
  tcase_add_test(tc, part1_add_one_greater);

  tcase_add_test(tc, part1_sub_normal);
  tcase_add_test(tc, part1_sub_inf);
  tcase_add_test(tc, part1_sub_one_sign);
  tcase_add_test(tc, part1_sub_two_sign);

  tcase_add_test(tc, part1_mult_value_1_is_one);
  tcase_add_test(tc, part1_mult_value_2_is_one);
  tcase_add_test(tc, part1_mult_value_1_is_zero);
  tcase_add_test(tc, part1_mult_value_2_is_zero);
  tcase_add_test(tc, part1_mult_max);
  tcase_add_test(tc, part1_mult_big_power);
  tcase_add_test(tc, part1_mult_big_over);
  tcase_add_test(tc, part1_mult_big_negative_over);
  tcase_add_test(tc, part1_mult_value_1_is_minus);
  tcase_add_test(tc, part1_mult_value_2_is_minus);
  tcase_add_test(tc, part1_mult_value_1_is_zero_minus);
  tcase_add_test(tc, part1_mult_value_2_is_zero_minus);
  tcase_add_test(tc, part1_mult_value_1_2_is_minus);

  tcase_add_test(tc, part1_div_zero);
  tcase_add_test(tc, part2_div);
  tcase_add_test(tc, part3_div);

  tcase_add_test(tc, part1_mod);
  tcase_add_test(tc, part2_mod);
  tcase_add_test(tc, part3_mod);
  tcase_add_test(tc, part4_mod);
  tcase_add_test(tc, part5_mod);

  suite_add_tcase(s, tc);
  return s;
}