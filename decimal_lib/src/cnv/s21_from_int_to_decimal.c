#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = S21_CONVERT_ERR;
  if (dst) {
    int tmp = src;
    if (src < 0) {
      tmp = (-1) * src;
    }
    int value[3] = {tmp, 0, 0};
    s21_init_decimal(value, src < 0, 0, dst);
    res = S21_OK;
  }
  return res;
}
