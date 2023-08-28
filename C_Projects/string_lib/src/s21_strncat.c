#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  s21_size_t len_dest = s21_strlen(dest);
  while (i < n) {
    dest[len_dest + i] = src[i];
    i++;
  }

  return dest;
}