#include "../s21_decimal.h"

int s21_get_sign(s21_decimal value) { return (value.bits[3] & (1 << 31)) != 0; }
int s21_get_exp(s21_decimal value) {
  return (value.bits[3] >> 16) & ((1 << 8) - 1);
}