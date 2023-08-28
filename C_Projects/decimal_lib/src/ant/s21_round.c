#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = S21_CALC_ERR;
  if (s21_is_correct_decimal(value) && result) {
    *result = value;
    if (s21_get_exp(value) != 0) {
      res = s21_lower_exp_decimal(0, result);
    } else {
      res = S21_OK;
    }
  }
  return res;
}
