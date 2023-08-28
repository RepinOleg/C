#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0;
  s21_size_t len_dest = s21_strlen(dest);
  s21_size_t len_src = s21_strlen(src);
  while (i < len_src) {
    dest[len_dest + i] = src[i];
    i++;
  }
  dest[len_dest + i] = '\0';

  return dest;
}