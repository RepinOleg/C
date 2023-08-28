#include "../s21_decimal.h"

int s21_is_values_equal(s21_decimal a, s21_decimal b);

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int result = 1;
  if (s21_get_sign(a) == s21_get_sign(b)) {
    s21_normalize(&a, &b);
    result = s21_is_values_equal(a, b);
  } else {
    // Единственный случай когда числа с разными знаками равны это -0 == 0
    // Также в этом случае можно игнорировать порядок чисел, если они окажутся
    // нулями, то порядок никак не повлияет на их "нулевость"
    s21_decimal zero = {{0, 0, 0, 0}};
    result = s21_is_values_equal(zero, a) && s21_is_values_equal(zero, b);
  }
  return result;
}

int s21_is_values_equal(s21_decimal a, s21_decimal b) {
  return a.bits[0] == b.bits[0] && a.bits[1] == b.bits[1] &&
         a.bits[2] == b.bits[2];
}
