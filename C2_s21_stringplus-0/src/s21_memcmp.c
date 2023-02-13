#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int answer = 0;
  int flag = 0;
  for (s21_size_t i = 0; flag != 1 && i < n; i++) {
    answer = *ptr1 - *ptr2;
    if (*ptr1 != *ptr2) {
      flag = 1;
    }
    ptr1++;
    ptr2++;
  }
  return answer;
}
