#include "s21_string.h"

char *s21_strpbrk(const char *str, const char *sym) {
  char *result = S21_NULL;
  for (s21_size_t j = 0; str[j] != '\0' && !result; j++) {
    for (s21_size_t i = 0; sym[i] != '\0' && !result; i++)
      if (sym[i] == str[j]) {
        result = (char *)str + j;
      }
  }
  return result;
}