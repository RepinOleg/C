#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *old_str;
  char *result = S21_NULL;
  // If NULL str passsed, then we should use previous, which contains in
  // static old_str
  if (!str) {
    str = old_str;
  }
  if (str) {
    // Let's skip first delimiters to jump right to the token
    str += s21_strspn(str, delim);
    // If str is not at the end, we can extract token
    if (*str) {
      // It clearly a token, so let's pass pointer to that string in result
      result = str;
      // Roll string until we find delim
      str += s21_strcspn(str, delim);
      // Our token is nearly ready - we should close it with null symbol (if
      // it not already) to make it real string
      if (*str != '\0') {
        *str = '\0';
        str++;
      }
      // To save remainings of our strings we need to pass str to old_str, but
      // now it points to '\0' So we push it to the next symbol
    }
  }
  // Let's save our string in static variable
  old_str = str;
  return result;
}
