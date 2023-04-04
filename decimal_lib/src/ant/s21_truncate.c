#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = S21_CALC_ERR;
  if (s21_is_correct_decimal(value) && result) {
    for (int exp = s21_get_exp(value); exp > 0; --exp) {
      s21_div_by_ten(&value);
    }
    *result = value;
    s21_set_exp(result, 0);
    res = S21_OK;
  }
  return res;
}
