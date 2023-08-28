#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper_str = malloc((s21_strlen(str) + 1) * sizeof(char));
  void *result = S21_NULL;
  if (upper_str) {
    result = upper_str;
    if (str != NULL) {
      s21_strcpy(upper_str, str);
      for (; *upper_str != '\0'; upper_str++) {
        if (*upper_str >= 'a' && *upper_str <= 'z') {
          *upper_str = *upper_str - 32;
        }
      }
    } else
      result = S21_NULL;
  }
  return result;
}
