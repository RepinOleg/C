#include "../s21_decimal.h"

int s21_add_bits(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = S21_COMPUTE_ERR;
  if (result) s21_init_decimal_result(result);
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2) &&
      result) {
    // ? #4 - Не может понять когда [+-]
    // * Это просто кошмар - в ифе снизу стоял неправильный value_1
    if (s21_get_sign(value_1) == 0 && s21_get_sign(value_2) == 1) {
      // ? [a + (-b)] <=> [a - |b|]
      s21_abs(&value_2);
      res = s21_sub(value_1, value_2, result);
    } else if (s21_get_sign(value_1) == 1 && s21_get_sign(value_2) == 0) {
      // ? [(-a) + b] <=> [b - |a|]
      s21_abs(&value_1);
      res = s21_sub(value_2, value_1, result);
    } else {
      // ? (-a) + (-b) <=> -(a + b) || (a + b)
      s21_set_sign(result, s21_get_sign(value_1));
      s21_normalize(&value_1, &value_2);
      res = s21_add_bits(value_1, value_2, result);
    }
  }
  return res;
}

int s21_add_bits(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  // ? #2 - при установке степени она почему-то обнуляется
  // * Без понятия, с чем это связано, но чтобы разобраться, перенес установку
  // * степени в эту функцию, и все заработало
  // * Аналогичная проблема была и в s21_sub
  int res = S21_OK;
  long contain = 0, remainder = 0;
  unsigned int current_1 = 0, current_2 = 0;
  s21_set_exp(result, s21_get_exp(value_1));
  // ? #6 - неправильный переход от 0xffffffff к 0 в разрядах
  // * Было забыто добавление remainder к contain, что приводило к потерю
  // * единицы, а далее к целому разряду
  for (int i = 0; i < 3; ++i) {
    current_1 = value_1.bits[i];
    current_2 = value_2.bits[i];
    contain = (long)current_1 + (long)current_2 + (long)remainder;
    result->bits[i] = value_1.bits[i] + value_2.bits[i] + remainder;
    remainder = contain / 0x100000000;
  }
  if (remainder && s21_get_sign(*result) == 0)
    res = S21_OVERFLOW;
  else if (remainder && s21_get_sign(*result) == 1)
    res = S21_UNDERFLOW;
  // printf("Sum of bits: ");
  // s21_print_decimal(value_1);
  // printf(" + ");
  // s21_print_decimal(value_2);
  // printf(" = ");
  // s21_print_decimal(*result);
  // putchar('\n');
  // printf("{%d}", res);
  return res;
}
