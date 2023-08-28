#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;
  if (src) {
    char *trim_str = malloc((s21_strlen(src) + 1) * sizeof(char));
    if (trim_str) {
      s21_strcpy(trim_str, src);
      if (trim_chars) {
        char *trim_pointer = trim_str;
        trim_pointer += s21_strspn(trim_pointer, trim_chars);
        int i = s21_strlen(trim_pointer);
        for (; s21_strchr(trim_chars, trim_pointer[i]); --i)
          ;
        trim_pointer[++i] = '\0';
        s21_strcpy(trim_str, trim_pointer);
      }
      trim_str = realloc(trim_str, (s21_strlen(trim_str) + 1) * sizeof(char));
      result = trim_str;
    }
  }

  return result;
}