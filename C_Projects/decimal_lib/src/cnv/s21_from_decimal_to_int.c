#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = S21_CONVERT_ERR;
  if (s21_is_correct_decimal(src) && dst) {
    int sign = 1;
    if (s21_get_sign(src)) {
      sign = -1;
    }
    s21_decimal truncated;
    s21_truncate(src, &truncated);
    if (!truncated.bits[2] && !truncated.bits[1] &&
        truncated.bits[0] <= INT_MAX) {
      *dst = truncated.bits[0] * sign;
      res = S21_OK;
    }
  }
  return res;
}
