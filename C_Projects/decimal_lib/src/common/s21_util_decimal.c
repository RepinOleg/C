#include "../s21_decimal.h"

void s21_abs(s21_decimal *value) { s21_set_sign(value, 0); }

int s21_is_correct_sign(int sign) { return (sign == 0 || sign == 1); }

int s21_is_correct_exp(int exp) { return (0 <= exp && exp <= 28); }

int s21_is_correct_decimal(s21_decimal value) {
  int sign = s21_get_sign(value);
  int exp = s21_get_exp(value);
  return s21_is_correct_exp(exp) && s21_is_correct_sign(sign);
}

void s21_init_decimal_result(s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
}