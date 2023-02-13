#include "s21_string.h"
char *s21_strstr(const char *str, const char *find_str) {
  char *result = S21_NULL;
  if (s21_strlen(str) >= s21_strlen(find_str)) {
    for (s21_size_t i = 0;
         i <= s21_strlen(str) - s21_strlen(find_str) && !result; i++) {
      int flag = 1;
      for (s21_size_t j = i, m = 0; find_str[m]; m++, j++) {
        if (str[j] != find_str[m]) {
          flag = 0;
        }
      }
      if (flag) {
        result = (char *)str + i;
      }
    }
  }
  return result;
}