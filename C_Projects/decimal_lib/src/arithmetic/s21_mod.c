#include "../s21_decimal.h"

// ? extended euclid algorithm

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = S21_COMPUTE_ERR;
  int flag_minus = 1;
  if (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2]) {
    ret = S21_DIVISION_BY_ZERO;
  } else if (s21_is_correct_decimal(value_1) &&
             s21_is_correct_decimal(value_2) && result) {
    ret = S21_OK;
    s21_normalize(&value_1, &value_2);
    if (!s21_get_sign(value_1)) flag_minus = 0;
    s21_set_sign(&value_1, 0);
    s21_set_sign(&value_2, 0);
    if (s21_is_equal(value_1, value_2)) {
      result_0(result);
    } else {
      s21_decimal copy_value_2 = value_2;
      s21_decimal const value_2_cp = value_2;
      int q = 0;
      while (s21_is_greater(value_1, value_2)) {
        while (s21_is_greater(value_1, value_2)) {
          q++;
          value_2.bits[0] = value_2.bits[0] << q;
        }
        if (s21_is_greater(value_2, value_1)) {
          for (int i = 0; i < q; i++)
            copy_value_2.bits[0] = copy_value_2.bits[0] << i;
        }
        if (s21_is_greater(value_1, copy_value_2)) {
          s21_sub(value_1, copy_value_2, &value_1);
          q = 0;
          value_2 = value_2_cp;
          copy_value_2 = value_2_cp;
        }
      }
      if (s21_is_equal(value_1, value_2)) {
        result_0(result);
      } else {
        *result = value_1;
      }
    }
    if (flag_minus) s21_set_sign(result, 1);
  }
  return ret;
}

void result_0(s21_decimal *result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = 0;
  }
}