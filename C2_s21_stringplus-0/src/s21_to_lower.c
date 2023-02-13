#include "s21_string.h"
void *s21_to_lower(const char *str) {
  char *lower_str = malloc((s21_strlen(str) + 1) * sizeof(char));
  void *result = S21_NULL;
  if (lower_str != S21_NULL) {
    result = lower_str;
    if (str != NULL) {
      s21_strcpy(lower_str, str);
      for (; *lower_str != '\0'; lower_str++) {
        if (*lower_str >= 'A' && *lower_str <= 'Z') {
          *lower_str = *lower_str + 32;
        }
      }
    } else
      result = S21_NULL;
  }
  return result;
}