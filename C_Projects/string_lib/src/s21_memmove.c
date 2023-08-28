#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  char *s = (char *)src;
  if (d < s) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
    char *lasts = s + n - 1;
    char *lastd = d + n - 1;
    while (n--) {
      *lastd-- = *lasts--;
    }
  }
  return dest;
}
