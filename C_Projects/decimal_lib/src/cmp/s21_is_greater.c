#include "../s21_decimal.h"

int s21_compare_signs(s21_decimal a, s21_decimal b);
int s21_compare_values(s21_decimal a, s21_decimal b);

int s21_is_greater(s21_decimal a, s21_decimal b) {
  int result = 1;
  switch (s21_compare_signs(a, b)) {
    case -1: {
      result = 0;
      break;
    }
    case 0: {
      s21_normalize(&a, &b);
      result = s21_compare_values(a, b);
      if (s21_get_sign(a)) result *= -1;
      break;
    }
  }
  return result == 1 && s21_is_not_equal(a, b);
}

// @returns 1 если a > b, 0 если знаки совпадают, -1 если a < b
int s21_compare_signs(s21_decimal a, s21_decimal b) {
  return s21_get_sign(b) - s21_get_sign(a);
}

// @returns 1 если a > b по значениям, 0 если a == b, -1 если a < b
int s21_compare_values(s21_decimal a, s21_decimal b) {
  int result = 0;
  unsigned int value_a = 0, value_b = 0;
  for (int i = 2; i >= 0; --i) {
    value_a = a.bits[i];
    value_b = b.bits[i];
    if (value_a != value_b) {
      if (value_a > value_b)
        result = 1;
      else
        result = -1;
      break;
    }
  }
  return result;
}
