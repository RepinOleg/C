#include "../s21_decimal.h"

int s21_mul_bits(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // ? -1 * -1 <=> 1 * 1 | -1 * 1 <=> 1 * -1 =>
  // ? sign_1 == sign_2 => result_sign = 0, sign_1 != sign_2 => result_sign = 1
  int sign = s21_get_sign(value_1) != s21_get_sign(value_2);

  // ? 25 * 10^-7 * 35 * 10^-4 <=> 25 * 35 * 10^-7-4 <=> (25 * 35) * 10^-11
  // ! 2 * 10^-28 * 0.5 * 10^-1 != 20 * 10^-29
  // * Если порядок произведения чисел получается выше допустимого (28), то
  // * нужно попробовать понизить порядок, деля произведение на 10
  // * Так же порядок чисел не может быть ниже 0, ведь сумма положительных
  // * порядков положительна
  // ? 20 * 10^-29 <=> 2 * 10^-28 <-- OK
  // ? 2 * 10^-29 <=> 0.2 = 0 * 10^-28 <=> 0 <-- OK
  // ! 9 * 10^-29 <=> 0.9 != 0
  // * По аналогии с s21_normalize, нужно учитывать первую цифру отбрасываемой
  // * части
  int exponent = s21_get_exp(value_1) + s21_get_exp(value_2);

  int res = S21_COMPUTE_ERR;
  if (result) s21_init_decimal_result(result);
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2) &&
      result) {
    if (!s21_is_correct_exp(exponent)) {
      res = (sign) ? S21_UNDERFLOW : S21_OVERFLOW;
    } else {
      s21_set_sign(result, sign);
      s21_set_exp(result, exponent);
      res = s21_mul_bits(value_1, value_2, result);
    }
  }

  return res;
}

// ? bits[4] = bits[0] + bits[1] * T + bits[2] * T^2 = a0 + a1 * T + a2 * T^2
// ?
// ? T = 2^32
// ?
// ? (a0 + a1 * T + a2 * T^2) * (b0 + b1 * T + b2 * T^2) =
// ? +-------------------------------+
// ? | a0b0    + a0b1T   + a0b2T^2 + |
// ? | a1b0T   + a1b1T^2 + a1b2T^3 + |
// ? | a2b0T^2 + a2b1T^3 + a2b2T^4 = |
// ? +-------------------------------+
// ? T^0a0b0 +                     <=> .bits[0] = (a0b0)
// ? T^1(a0b1 + a1b0) +            <=> .bits[1] = (a0b1 + a1b0)
// ? T^2(a2b0 + a1b1 + a0b2) +     <=> .bits[2] = (a2b0 + a1b1 + a0b2)
// ? ...
// ? a1b2 == a2b1 == a2b2 == 0, else overflow
// ?

// ! max_num * 0.5 => overflow
int s21_mul_bits(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  int res = S21_OK;
  long long contain = 0, int_multi = 0, shift = 0;

  unsigned int a[3], b[3];

  for (int i = 0; i < 3; ++i) {
    a[i] = (unsigned int)value_1.bits[i];
    b[i] = (unsigned int)value_2.bits[i];
  }

  for (int n = 0; n < 3; ++n) {
    contain = 0;
    for (int i = 0; i <= n; ++i) {
      int_multi = (unsigned int)a[i];
      int_multi *= (unsigned int)b[n - i];
      contain += int_multi;
    }
    contain += shift;
    result->bits[n] = contain % 0x100000000;
    shift = contain / 0x100000000;
  }

  int_multi = (unsigned int)a[2];
  int_multi *= (unsigned int)b[1];
  if (int_multi) shift = 1;
  int_multi = (unsigned int)a[1];
  int_multi *= (unsigned int)b[2];
  if (int_multi) shift = 1;
  int_multi = (unsigned int)a[2];
  int_multi *= (unsigned int)b[2];
  if (int_multi) shift = 1;

  if (shift) res = (s21_get_sign(*result)) ? S21_UNDERFLOW : S21_OVERFLOW;

  return res;
}
