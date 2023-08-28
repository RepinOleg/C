#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  // s21_size_t i = 0;
  unsigned char *dest_cp = dest;
  unsigned char *src_cp = (unsigned char *)src;
  // if (!n || dest_cp == src_cp) {
  //     return dest;
  // }
  for (s21_size_t i = 0; i < n; i++) {
    dest_cp[i] = src_cp[i];
  }
  return dest_cp;
}