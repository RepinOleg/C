#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = S21_CONVERT_ERR;
  if (s21_is_correct_decimal(src) && dst) {
    double contain = 0.0;
    for (int i = 0; i < 3; ++i) {
      contain += (double)src.bits[i] * pow(pow(2, 32), i);
    }
    contain *= pow(10, (-1) * s21_get_exp(src));
    contain *= pow(-1, s21_get_sign(src));
    *dst = contain;
    res = S21_OK;
  }
  return res;
}
