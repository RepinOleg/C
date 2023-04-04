#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = S21_CALC_ERR;
  if (s21_is_correct_decimal(value) && result) {
    s21_set_sign(&value, s21_get_sign(value) == 0);
    *result = value;
    res = S21_OK;
  }
  return res;
}
