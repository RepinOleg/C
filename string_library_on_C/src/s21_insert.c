#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  void *result = S21_NULL;
  if (str != S21_NULL) {
    char *insert_str =
        malloc((s21_strlen(src) + s21_strlen(str) + 1) * sizeof(char));
    if (insert_str) {
      if (s21_strlen(src) < start_index) {
        free(insert_str);
      } else {
        result = insert_str;
        s21_strncpy(insert_str, src, start_index);
        insert_str[start_index] = '\0';
        s21_strcat(insert_str, str);
        s21_strcat(insert_str, src + start_index);
      }
    }
  }
  return result;
}