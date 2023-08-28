#include <math.h>
#include <stdio.h>

#include "../s21_decimal.h"

static const float decimal_border = 79228162514264337593543950335.f;

s21_decimal s21_str_to_dec(char *buffer, int sign);

int valid_float(float src) {
  return !(isnan(src) || isinf(src) || decimal_border < src ||
           src < -decimal_border || (0 < src && src < 1e-28) ||
           (0 > src && src > -1e-28));
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = S21_CONVERT_ERR;
  if (dst && valid_float(src)) {
    res = S21_OK;
    char float_buffer[100];
    sprintf(float_buffer, "%.6E", fabs(src));
    *dst = s21_str_to_dec(float_buffer, src < 0);
  }
  return res;
}

s21_decimal s21_str_to_dec(char *buffer, int sign) {
  s21_decimal result = {{0, 0, 0, 0}}, ten = {{10, 0, 0, 0}};
  int value[3], exponent = 0, power = 0;
  value[0] = buffer[0] - '0';
  for (int i = 2; i < 8; ++i) {
    value[0] *= 10;
    value[0] += buffer[i] - '0';
  }
  value[1] = 0;
  value[2] = 0;
  if (buffer[9] == '-' || (buffer[10] == '0' && buffer[11] == '0')) {
    exponent = (buffer[10] - '0') * 10 + (buffer[11] - '0') + 6;
  } else {
    power = (buffer[10] - '0') * 10 + (buffer[11] - '0') - 6;
  }
  s21_init_decimal(value, sign, exponent, &result);
  for (; power > 0; --power) {
    s21_mul(result, ten, &result);
  }
  for (; exponent > 28; --exponent) {
    s21_div_by_ten(&result);
  }
  s21_set_exp(&result, exponent);
  return result;
}