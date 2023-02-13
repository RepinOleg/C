#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  // We will roll further str1 pointer until some of the characters are DETECTED
  // in s21_strchr function call (or string is ended)
  for (; *str1 && !s21_strchr(str2, *str1++); result++)
    ;
  return result;
}
