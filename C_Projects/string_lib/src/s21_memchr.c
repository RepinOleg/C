#include "s21_string.h"
/* the function returns a pointer to the found character
if the character is not found returns NULL */
void *s21_memchr(const void *str, int ch, s21_size_t len) {
  const char *ptr = str;
  void *result = S21_NULL;
  for (s21_size_t i = 0; i < len && !result; i++) {
    if (ptr[i] == ch) {
      result = (void *)(ptr + i);
    }
  }
  return result;
}
