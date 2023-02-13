#include "s21_sscanf.h"
int s21_read_int(specifier sp, const char **src, void *to) {
  int64_t val = 0;
  int res = s21_numerical_system(sp, src, (uint64_t *)&val);
  if (!sp.no_assign && res > 0) {
    if (sp.length == 'h')
      *(short *)to = (short)val;
    else if (sp.length == 'l')
      *(long long *)to = (long long)val;
    else
      *(int *)to = (int)val;
  }
  return res;
}

int s21_read_uint(specifier sp, const char **src, void *to) {
  uint64_t val;
  int res = s21_numerical_system(sp, src, &val);
  if (!sp.no_assign && res > 0) {
    if (sp.length == 'h')
      *(unsigned short *)to = (unsigned short)val;
    else if (sp.length == 'l')
      *(unsigned long long *)to = (unsigned long long)val;
    else
      *(unsigned int *)to = (unsigned int)val;
  }
  return res;
}

int s21_numerical_system(specifier sp, const char **src, uint64_t *to) {
  const char *format = *src;
  uint64_t number = 0;
  char negative = 0;
  int res = 0;
  if (sp.width != 0) {
    if (*format == '-' || *format == '+') {
      if (*format == '-') {
        negative = 1;
      }
      format++;
      sp.width--;
    }
  }
  // проверяем какая система счисления
  if (sp.type == 'd')
    sp.ns = 10;
  else if (*(format + 1) == 'x' || *(format + 1) == 'X' || sp.type == 'x' ||
           sp.type == 'X')
    sp.ns = 16;
  else if (*format == '0' || sp.type == 'o')
    sp.ns = 8;
  else
    sp.ns = 10;

  if (*format == '0' && (*(format + 1) == 'x' || *(format + 1) == 'X')) {
    format += 2;
    res = 1;
    sp.width -= 2;
  } else if (*format == '0') {
    format++;
    res = 1;
    sp.width--;
  }

  while (sp.width < 0) {
    format--;
    sp.width++;
  }

  if (hex_digit(*format) != '?' && sp.width) {
    while (hex_digit(*format) != '?' && sp.width--) {
      int next_nummber =
          hex_digit(*format);  // sp.ns переводим на выбранную систему счисления
      if (next_nummber < sp.ns)
        number = number * sp.ns + next_nummber;
      else
        break;
      format++;
      res = 1;
    }
  }

  *src = format;
  if (negative) {
    number = -number;
  }
  if (res >= 0) *to = number;
  return res;
}

int read_float(specifier sp, const char **src, void *to) {
  const char *format = *src;
  long double number = 0, mantiss = 0;
  char negative = 0;
  int res = 0, flag_bad = 0;
  sp.ns = 10;
  if (*format == '\0') res = -1;
  if (sp.length != 'L') {
    number = (double)number;
  }
  if (sp.width != 0) {
    if (*format == '-' || *format == '+') {
      if (*format == '-') {
        negative = 1;
      }
      format++;
      sp.width--;
      if (*format == '\0') {
        res = 0;
        flag_bad = 1;
      }
    } else if (*format == '.') {
      format++;
      if (*format == '\0') {
        res = 0;
        flag_bad = 1;
      } else
        format--;
    }
  }
  if (s21_isdigit(*format) == 0 && *format != '.' &&
      s21_strchr("NnIi", *format) == 0)
    flag_bad = 1;
  if (hex_digit(*format) != '?' && sp.width) {
    while (hex_digit(*format) != '?' && sp.width > 0) {
      int next_nummber = hex_digit(*format);
      if (next_nummber < sp.ns)
        number = number * sp.ns + next_nummber;
      else
        break;
      format++;
      res = 1;
      sp.width--;
    }
  }
  if (*format == '.' && sp.width) {
    format++;
    sp.width--;
  }
  int count = 0;
  if (hex_digit(*format) != '?' && sp.width) {
    while (hex_digit(*format) != '?' && sp.width--) {
      int next_nummber = hex_digit(*format);
      if (next_nummber < sp.ns) {
        count++;
        mantiss = mantiss * sp.ns + next_nummber;
        res = 1;
      } else
        break;
      format++;
    }
    mantiss /= powl(10.0, count);
    number += mantiss;
  }
  if ((*format == 'e' || *format == 'E') && sp.width) {
    format++;
    int negative_notation = 0, degree = 0;
    if (*format == '-') {
      negative_notation = 1;
      format++;
    } else if (*format == '+') {
      format++;
    }
    while (hex_digit(*format) != '?' && sp.width--) {
      int next_nummber = hex_digit(*format);
      if (next_nummber < sp.ns)
        degree = degree * sp.ns + next_nummber;
      else
        break;
      format++;
    }
    if (negative_notation) {
      number /= powl(10.0, degree);
    } else {
      number *= powl(10.0, degree);
    }
  }
  if (*format == 'N' || *format == 'n') {
    if (s21_strstr(format, "NAN") != NULL ||
        s21_strstr(format, "nan") != NULL) {
      number = NAN;
      format += 3;
      res = 1;
    }
  } else if (*format == 'I' || *format == 'i') {
    if (s21_strstr(format, "INF") != NULL ||
        s21_strstr(format, "inf") != NULL) {
      number = INFINITY;
      format += 3;
      res = 1;
    }
  }
  *src = format;
  if (negative) number = -number;
  if (!sp.no_assign && res != -1 && !flag_bad) {
    if (!sp.length)
      *(float *)to = (float)number;
    else if (sp.length == 'l')
      *(double *)to = (double)number;
    else if (sp.length == 'L')
      *(long double *)to = (long double)number;
  }
  return res;
}
