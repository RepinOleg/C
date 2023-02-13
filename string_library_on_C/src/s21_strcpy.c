#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *origin = dest;
  for (; *src != '\0'; src++) {
    *dest = *src;
    dest++;
  }
  *dest = '\0';
  return origin;
}
