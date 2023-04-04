#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = S21_OK;
  s21_decimal zero = {{0, 0, 0, 0}};
  float float_1, float_2, float_result;
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2) &&
      result) {
    if (s21_is_not_equal(value_2, zero)) {
      s21_from_decimal_to_float(value_1, &float_1);
      s21_from_decimal_to_float(value_2, &float_2);
      float_result = float_1 / float_2;
      res = s21_from_float_to_decimal(float_result, result);
    } else {
      res = S21_DIVISION_BY_ZERO;
    }
  } else {
    res = S21_COMPUTE_ERR;
  }
  return res;
}