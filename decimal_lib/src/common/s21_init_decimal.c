#include "../s21_decimal.h"

void s21_set_sign(s21_decimal *result, int sign);
void s21_set_value(s21_decimal *result, int value[3]);
void s21_set_exp(s21_decimal *result, int exponent);

void s21_init_decimal(int value[3], int sign, int exponent,
                      s21_decimal *result) {
  s21_set_sign(result, sign);
  s21_set_value(result, value);
  s21_set_exp(result, exponent);
}

void s21_set_sign(s21_decimal *result, int sign) {
  if (s21_is_correct_sign(sign)) {
    // ? (1 << 31) = 100...00
    // ?                 ^x31
    // ? ~(1 << 31) = 011...11
    // ?                ^x31
    // ? result->bits[3] = 10101010101010100011111000 &
    // ? ~(1 << 31)      = 01111111111111111111111111
    // ?                   10101010101010100011111000
    result->bits[3] = result->bits[3] & ~(1 << 31);
    result->bits[3] = result->bits[3] | (sign << 31);
  }
}

void s21_set_value(s21_decimal *result, int value[3]) {
  for (int i = 0; i < 3; ++i) {
    result->bits[i] = value[i];
  }
}

void s21_set_exp(s21_decimal *result, int exponent) {
  if (s21_is_correct_exp(exponent)) {
    result->bits[3] = result->bits[3] & ~(((1 << 8) - 1) << 16);
    result->bits[3] = result->bits[3] | (exponent << 16);
  }
}
