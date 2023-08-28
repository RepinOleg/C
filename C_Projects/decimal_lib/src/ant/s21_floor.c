#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = S21_CALC_ERR;
  if (s21_is_correct_decimal(value) && result) {
    s21_decimal one = {{1, 0, 0, 0}};
    // * Отбрасываем целую часть в любом случае
    s21_truncate(value, result);
    // * Проверим, есть ли у числа знак
    // * Если он есть и у числа была дробная часть, то уменьшим число на 1
    // * Проверить была ли у числа дробная часть можно сравнивая число
    // * до отбрасывания [value] и после [*result]
    if (s21_get_sign(value) && s21_is_not_equal(value, *result)) {
      s21_sub(*result, one, result);
    }
    res = S21_OK;
  }
  return res;
}

// 12345.723
// 12345.000

// 12345.12300
// 12345.00000