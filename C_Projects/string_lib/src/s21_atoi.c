#include "s21_string.h"

int s21_atoi(const char *str) {
  int res = 0, negative = 0;
  while (*str == ' ') str++;
  if (*str == '-') {
    negative = 1;
    str++;
  }
  if (*str == '+') str++;

  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    str++;
  }
  if (negative) res = -res;

  return res;
}