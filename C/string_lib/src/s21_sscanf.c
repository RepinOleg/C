#include "s21_sscanf.h"

char hex_digit(char c) {
  if ('0' <= c && c <= '9') {
    return c - 48;
  } else if (c == 'a' || c == 'A') {
    return 10;
  } else if (c == 'b' || c == 'B') {
    return 11;
  } else if (c == 'c' || c == 'C') {
    return 12;
  } else if (c == 'd' || c == 'D') {
    return 13;
  } else if (c == 'e' || c == 'E') {
    return 14;
  } else if (c == 'f' || c == 'F') {
    return 15;
  }
  return '?';
}

const char *spec_symbol(const char *format, specifier *to) {
  long long int width = 0;
  specifier sp = {0};
  if (*format == '*') {
    sp.no_assign = 1;
    format++;
  }

  while (hex_digit(*format) != '?') {
    long long int next_number = hex_digit(*format);
    if (next_number < 10) {
      width = width * 10 + next_number;
      format++;
    } else
      break;
  }
  if (width) {
    sp.flag_width = 1;
    sp.width = width;
  } else
    sp.width = INT32_MAX;

  if (*format == 'h' || *format == 'l' || *format == 'L')
    sp.length = *(format++);
  if (*format == sp.length) {
    sp.double_len = 1;
    format++;
  }
  sp.type = *format;
  *to = sp;
  return format;
}

int s21_sscanf(const char *str, const char *format, ...) {
  const char *cur = str;
  int success_count = 0;
  va_list ap;
  va_start(ap, format);
  char success = 0;
  void *ptr = S21_NULL;
  if (*format) do {
      success = 0;

      if (*format == ' ' || *format == '\t' || *format == '\n') {
        while (*cur == ' ' || *cur == '\n' || *cur == '\t') cur++;
        success = 1;
      } else if (*format == '%') {
        specifier sp;
        format = spec_symbol(++format, &sp);
        if (sp.type != 'c')
          while (*cur == ' ' || *cur == '\t' || *cur == '\n') cur++;

        ptr = (sp.type != '%' && !sp.no_assign) ? va_arg(ap, void *) : S21_NULL;

        switch (sp.type) {
          case 'u':
          case 'i':
            success = s21_read_uint(sp, &cur, ptr);
            break;
          case 'd':
            if (*cur == '\0' && success_count < 1)
              success_count = -1;
            else
              success = s21_read_int(sp, &cur, ptr);
            break;
          case 'c':
          case 'C':
            success = s21_char(sp, &cur, ptr);
            break;
          case '%':
            success = *(cur++) == '%';
            break;
          case 'n':
            *(int *)ptr = cur - str;
            success = 1;
            break;
          case 's':
          case 'S':
            success = s21_strok(sp, &cur, ptr);
            break;
          case 'o':
            if (*cur == '\0')
              success_count = -1;
            else
              success = s21_read_uint(sp, &cur, ptr);
            break;
          case 'x':
          case 'X':
          case 'p':
            if (*cur == '\0')
              success_count = -1;
            else
              success = s21_read_uint(sp, &cur, ptr);
            break;
          case 'f':
          case 'g':
          case 'G':
          case 'F':
          case 'e':
          case 'E':
            success = read_float(sp, &cur, ptr);
        }
        if (success < 1 && success_count > 0) break;
        if (!sp.no_assign && sp.type != '%' && sp.type != 'n')
          success_count += success;
      } else {
        success = *cur == *format;
        cur++;
      }
    } while (success_count >= 0 && success && *format && *(++format));
  va_end(ap);
  return success_count;
}

int s21_char(specifier sp, const char **src, void *to) {
  const char *from = *src;
  char *ch = (char *)to;
  int res = -1;

  if (*from != '\0') {
    if (!sp.no_assign) {
      if (!sp.flag_width)
        *ch = *from;
      else {
        while (sp.width > 0) {
          *ch++ = *from++;
          sp.width--;
        }
      }
    }
    from++;
    res = 1;
  }

  *src = from;

  return res;
}

int s21_strok(specifier sp, const char **src, void *to) {
  const char *from = *src;
  char *string = (char *)to;
  int res = 0;

  if (*from != '\0') {
    while (*from != ' ' && *from != '\0' && *from != '\t' && *from != '\n' &&
           sp.width--) {
      if (!sp.no_assign) *string = *from;
      from++;
      string++;
    }
    if (!sp.no_assign) *string = '\0';
    res = from != *src;
  } else
    res = -1;
  *src = from;

  return res;
}
