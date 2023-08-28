#include "s21_string.h"

char *s21_strrchr(const char *str, int ch) {
  char *result = S21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == ch) {
      result = (char *)str + i;
    }
  }
  return result;
}