#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  // Push pointer till the end and count this moves in len
  if (str != NULL) {
    for (; str[len]; len++)
      ;
  }
  return len;
}
