#include "../s21_decimal.h"

int s21_sub_bits(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = S21_COMPUTE_ERR;
  if (result) s21_init_decimal_result(result);
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2) &&
      result) {
    if (s21_get_sign(value_1) == 1 && s21_get_sign(value_2) == 0) {
      // ? (-a) - b <=> (-a) + (-b)
      s21_negate(value_2, &value_2);
      res = s21_add(value_1, value_2, result);
    } else if (s21_get_sign(value_1) == 0 && s21_get_sign(value_2) == 1) {
      // ? a - (-b) <=> a + b
      s21_abs(&value_2);
      res = s21_add(value_1, value_2, result);
    } else {
      // ? (-a) - (-b) <=> -(a - b) || (a - b)
      s21_normalize(&value_1, &value_2);
      res = s21_sub_bits(value_1, value_2, result);
      if (s21_get_sign(value_1)) s21_negate(*result, result);
    }
  }
  return res;
}

int s21_sub_bits(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  int res = S21_OK, swap = 0, shift = 0;
  unsigned int bigger_value = 0, smaller_value = 0;
  s21_decimal bigger, smaller;
  long contain = 0;
  // * 0) В случае если в результате уже есть знак, он будет мешать
  s21_set_sign(result, 0);
  s21_set_exp(result, s21_get_exp(value_1));
  // * 1) Найдем большее число
  // ? a > b => a - b OK
  // ? a < b => a - b => -(b - a) OK
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  if (s21_is_greater_or_equal(value_1, value_2)) {
    bigger = value_1;
    smaller = value_2;
  } else {
    bigger = value_2;
    smaller = value_1;
    swap = 1;
  }
  // * 2) Вычтем из большего меньшее
  for (int i = 0; i < 3; ++i) {
    bigger_value = bigger.bits[i];
    smaller_value = smaller.bits[i];
    result->bits[i] = bigger.bits[i] - smaller.bits[i] - shift;
    // * Числа собираются в contain для случая возможного переполнения
    // ? int smaller_value = 0xffffffff, shift = 1
    // ? (unsigned int) (smaller_value + shift) = 0x00000000 <=> shift = 0
    // ? (long) (smaller_value + shift) = 0x0000000100000000 <=> shift = 1
    contain = (unsigned int)smaller_value;
    contain += (unsigned int)shift;
    shift = bigger_value < contain;
  }
  // * 3) Если очередность чисел была изменена, то результат умножается на -1
  if (swap) s21_set_sign(result, 1);
  // printf("Sub of bits: ");
  // s21_print_decimal(value_1);
  // printf(" - ");
  // s21_print_decimal(value_2);
  // printf(" = ");
  // s21_print_decimal(*result);
  // putchar('\n');
  return res;
}
