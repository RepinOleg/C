#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;
  int res = 0;
  i = 0;
  while ((str1[i] || str2[i]) && (i < n)) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }
    i++;
  }
  return res;
}