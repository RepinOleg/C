#include "s21_sprintf.h"

int s21_sprintf(char *buf, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  int count = 0;
  while (*format) {
    if (*format != '%') {
      count++;
      *buf++ = *format++;
    } else {
      flags f = {0};
      int local_count = 0;
      format++;
      format = pars_flags(&f, format);
      format = pars_width(&f, format, ap);
      format = pars_accurasy(&f, format, ap);
      format = pars_length(&f, format);
      f.specif = *format++;
      buf = pars_specifiers(f, ap, buf, &local_count);
      if (f.specif == 'n') s21_n(count, ap);
      count += local_count;
    }
  }
  *buf = '\0';
  va_end(ap);
  return count;
}

const char *pars_flags(flags *f, const char *format) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    if (*format == '-')
      f->minus = 1;
    else if (*format == '+')
      f->plus = 1;
    else if (*format == '#')
      f->hash = 1;
    else if (*format == ' ')
      f->space = 1;
    else if (*format == '0')
      f->zero = 1;
    format += 1;
  }
  return format;
}

const char *pars_width(flags *f, const char *format, va_list ap) {
  if (*format == '*') {
    format++;
    f->width = va_arg(ap, int);
  } else {
    char buffer[4096] = {'\0'};
    int i = 0;
    while (s21_isdigit(*format)) {
      buffer[i] = *format;
      i++;
      format++;
    }
    f->width = s21_atoi(buffer);
  }
  return format;
}

const char *pars_accurasy(flags *f, const char *format, va_list ap) {
  if (*format == '.') {
    format++;
    f->flag_accuracy = 1;
    if (*format == '*') {
      f->accuracy = va_arg(ap, int);
      format++;
    } else {
      char buffer[4096] = {'\0'};
      int i = 0;
      while (s21_isdigit(*format)) {
        buffer[i] = *format;
        i++;
        format++;
      }
      f->accuracy = s21_atoi(buffer);
    }
  }
  return format;
}

const char *pars_length(flags *f, const char *format) {
  if (*format == 'h') {
    f->length = 'h';
    format++;
  } else if (*format == 'l') {
    f->length = 'l';
    format++;
  } else if (*format == 'L') {
    f->length = 'L';
    format++;
  }
  return format;
}

char *pars_specifiers(flags f, va_list ap, char *buf, int *count) {
  if (f.specif == 'c')
    s21_ch(ap, buf, f, count);
  else if (f.specif == 'd' || f.specif == 'i')
    s21_int(ap, buf, f, count);
  else if (f.specif == 'f' || f.specif == 'e' || f.specif == 'E' ||
           f.specif == 'g' || f.specif == 'G')
    s21_float(ap, buf, count, f);
  else if (f.specif == 's')
    s21_str(ap, buf, f, count);
  else if (f.specif == 'u' || f.specif == 'o' || f.specif == 'X' ||
           f.specif == 'x')
    s21_u_int(ap, buf, f, count);
  else if (f.specif == '%') {
    buf[0] = '%';
    *count += 1;
  } else if (f.specif == 'p')
    s21_p(ap, count, buf, f);

  buf += *count;
  return buf;
}

void s21_n(int count, va_list ap) {
  int *n = va_arg(ap, int *);
  *n = count;
}

void s21_p(va_list ap, int *count, char *buf, flags f) {
  intptr_t p = va_arg(ap, intptr_t);
  int tmp_len = 0;
  int len = len_of_number(p, 16);
  tmp_len = (f.plus) ? len + 1 : len;
  if (p == 0 && (!f.flag_accuracy || f.accuracy)) tmp_len++;
  if (f.accuracy > tmp_len) tmp_len = f.accuracy;
  if (!f.minus) {
    buf = add_space(f, tmp_len + 2, count, buf);
  }
  *buf++ = '0';
  *buf++ = 'x';
  *count += 2;
  if (p == 0 && (f.accuracy == 1 || !f.flag_accuracy)) {
    *buf++ = '0';
    *count += 1;
  }
  if (f.accuracy > len) {
    for (int i = 0; i < f.accuracy - len; i++) {
      *buf++ = '0';
      *count += 1;
    }
  }
  num_to_str(p, len, 16, count, buf, 0);
  buf += len;

  if (f.minus) add_space(f, tmp_len + 2, count, buf);
}

void s21_ch(va_list ap, char *buf, flags f, int *i) {
  char ch = va_arg(ap, int);
  if (f.width && !f.minus && !f.zero) {
    while (*i < f.width - 1) {
      *buf++ = ' ';
      *i += 1;
    }
    *buf++ = ch;
    *i += 1;
  } else if (f.zero && !f.minus) {
    while (*i < f.width - 1) {
      *buf++ = '0';
      *i += 1;
    }
    *buf++ = ch;
    *i += 1;
  } else if (f.width) {
    *buf++ = ch;
    *i += 1;
    for (; *i < f.width; *i += 1) {
      *buf++ = ' ';
    }
  } else {
    *buf++ = ch;
    *i += 1;
  }
}

void s21_int(va_list ap, char *buf, flags f, int *i) {
  int64_t number = va_arg(ap, int64_t);
  int negative_int = 0, length = 0;
  if (f.length == 'h')
    number = (int16_t)number;
  else if (!f.length)
    number = (int32_t)number;

  if (number < 0) {
    number *= -1;
    negative_int = 1;
    if (!f.accuracy) length++;
  }

  length += len_of_number(number, 10);
  int len = length, tmp_len = length;
  if (f.accuracy > len) tmp_len += f.accuracy - len;
  if ((f.width && negative_int && f.accuracy) ||
      (number == 0 && !f.flag_accuracy))
    tmp_len++;
  if (number == 0) len++;
  if (!negative_int && (f.space || f.plus)) {
    buf = plus_and_space(f, buf, i, negative_int);
    if (!f.plus && !f.minus) tmp_len++;
  }
  if (f.space && !negative_int && number && !f.minus) len++;
  if (!f.minus && f.width > f.accuracy - length && !f.zero)
    buf = add_space(f, tmp_len, i, buf);
  if ((f.accuracy || f.zero) && negative_int) {
    *buf++ = '-';
    *i += 1;
  }

  if (f.accuracy || (f.width && f.zero)) buf = add_zero_integer(f, len, i, buf);

  if (number == 0 && (!f.flag_accuracy || f.accuracy > 0)) {
    *buf = '0';
    *i += 1;
  }
  if (negative_int && !f.accuracy && !f.zero) {
    *buf = '-';
    *i += 1;
  }
  if (negative_int && f.zero && !f.accuracy) length--;
  num_to_str(number, length, 10, i, buf, 0);
  buf += len;
  if (f.space && !negative_int) tmp_len++;
  if (f.minus) add_space(f, tmp_len, i, buf);
}

void s21_str(va_list ap, char *buf, flags f, int *count) {
  char *arr = va_arg(ap, char *);
  int acc = f.flag_accuracy ? f.accuracy : 6;
  if (arr != NULL && (!f.flag_accuracy || f.accuracy > (int)s21_strlen(arr)))
    acc = s21_strlen(arr);
  if (!f.minus && arr != NULL && !f.zero)
    buf = add_space(f, acc, count, buf);
  else if (!f.minus && f.zero && arr != NULL)
    buf = add_zero(f, acc, count, buf, 0);
  if (arr == NULL) {
    char *nul = "(null)";
    acc = (acc >= 6) ? 6 : acc;
    if (!f.minus) buf = add_space(f, acc, count, buf);
    for (int i = 0; i < acc; i++) buf[i] = nul[i];
    *count += acc;
  } else {
    if (f.width && !f.minus && !f.flag_accuracy) {
      for (int i = 0; arr[i]; i++) {
        buf[i] = arr[i];
        *count += 1;
      }
    } else if (f.flag_accuracy) {
      for (int i = 0; i < acc; i++) {
        buf[i] = arr[i];
        *count += 1;
      }
    } else {
      for (int i = 0; arr[i]; i++) {
        buf[i] = arr[i];
        *count += 1;
      }
    }
    buf += acc;
  }
  if (f.minus) add_space(f, acc, count, buf);
}

void s21_u_int(va_list ap, char *buf, flags f, int *i) {
  uint64_t number = va_arg(ap, uint64_t);
  if (f.length == 'h') number = (uint16_t)number;
  int base = 0, flag_X = 0;
  if (f.specif == 'o')
    base = 8;
  else if (f.specif == 'u')
    base = 10;
  else {
    base = 16;
    if (f.specif == 'X') flag_X = 1;
  }

  int length = len_of_number(number, base);
  int len = length, tmp_len = length;

  if (!number && f.accuracy) len++, length++;
  if (!number && !f.flag_accuracy) tmp_len++;
  if (f.accuracy > len) tmp_len += f.accuracy - len;

  if (!f.minus && f.width > f.accuracy - length && !f.zero)
    buf = add_space(f, tmp_len, i, buf);
  if (f.hash && number && f.specif == 'o') len++;
  if (number) buf = add_x_X(f, i, buf);
  if (f.accuracy || (f.width && f.zero)) buf = add_zero_integer(f, len, i, buf);
  if (f.hash && number && f.specif == 'o') {
    *buf++ = '0';
    *i += 1;
  }

  if (number == 0 && (!f.flag_accuracy || f.accuracy > 0)) {
    *buf++ = '0';
    *i += 1;
  } else {
    num_to_str(number, length, base, i, buf, flag_X);
    buf += len;
  }
  if (f.minus) add_space(f, tmp_len, i, buf);
}

char *add_zero_integer(flags f, int len, int *i, char *buf) {
  int w = f.accuracy ? f.accuracy : f.width;
  for (int j = 0; j < w - len; j++) {
    *buf++ = '0';
    *i += 1;
  }
  return buf;
}

char *add_space(flags f, int len, int *i, char *buf) {
  for (int j = 0; j < f.width - len; j++) {
    *buf++ = ' ';
    *i += 1;
  }
  return buf;
}

void s21_float(va_list ap, char *buf, int *count, flags f) {
  long double numb = 0, exponent = 0, mantiss1 = 0, mantiss = 0;
  if (f.length == 'L')
    numb = va_arg(ap, long double);
  else
    numb = va_arg(ap, double);

  int negative = 0, accuracy = 0, count_e = 0, len_count_e = 0, len_mantiss = 0,
      len_exponent = 0, tmp_len = 0, flag_e_minus = 0, flag_g = 0;
  if (numb != numb) {
    char *Nan = "nan";
    for (int i = 0; i < 3; i++) {
      buf[i] = Nan[i];
      *count += 1;
    }
    buf += 3;
  } else if (numb == INFINITY) {
    char *Nan = "inf";
    for (int i = 0; i < 3; i++) {
      buf[i] = Nan[i];
      *count += 1;
    }
    buf += 3;
  } else {
    if (numb < 0) {
      negative = 1;
      numb = fabsl(numb);
      *count += 1;
    }

    if (!f.accuracy && !f.flag_accuracy)
      accuracy = 6;
    else if (!f.accuracy && f.flag_accuracy)
      accuracy = 1;
    else
      accuracy = f.accuracy;
    processing_g(&f, numb, &accuracy, &flag_g);
    cast_e(f, &numb, &count_e, &flag_e_minus);
    mantiss1 = modfl(numb, &exponent);
    int numb_of_zero = 0;
    for (long double x = mantiss1; x < 0.1 && x > 0; x *= 10) numb_of_zero++;
    mantiss = roundl(mantiss1 * powl(10.0l, accuracy));
    mantiss1 = mantiss1 * powl(10.0l, accuracy);
    if (flag_g && !f.hash) {
      uint64_t x = mantiss;
      while (x % 10 == 0 && x != 0) {
        mantiss /= 10;
        accuracy--;
        x /= 10;
      }
      if (mantiss == 0) accuracy = 0;
    }
    if (!f.accuracy && f.flag_accuracy) accuracy = 0;
    len_exp_mantiss(&len_exponent, &exponent, &len_mantiss, &mantiss, accuracy,
                    f, mantiss1);
    if (negative) len_exponent++;
    tmp_len = len_exponent + accuracy + 1;
    all_len_e_E(&len_count_e, count_e, f, &tmp_len);
    all_len_f(&tmp_len, f, negative, accuracy);

    if (!f.minus && !f.zero) buf = add_space(f, tmp_len, count, buf);
    buf = plus_and_space(f, buf, count, negative);
    if (negative) *buf = '-';
    if (!f.minus && f.zero) buf = add_zero(f, tmp_len, count, buf, negative);

    buf = work_with_exponent(buf, exponent, count, len_exponent, negative);
    if (accuracy != 0 || (!f.flag_accuracy && (!flag_g || mantiss1 != 0)) ||
        f.hash) {
      *buf++ = '.';
      *count += 1;
    }
    if (accuracy != 0 || !f.flag_accuracy)
      buf = work_with_mantiss(mantiss, len_mantiss, count, buf, accuracy,
                              numb_of_zero, flag_g);
    buf = s21_e_E(f, buf, count_e, len_count_e, count, flag_e_minus);

    if (f.minus) add_space(f, tmp_len, count, buf);
  }
}

char *work_with_exponent(char *buf, long double exponent, int *count,
                         int len_exponent, int negative) {
  if (exponent == 0) {
    if (!negative)
      *buf = '0';
    else
      buf[1] = '0';
    *count += 1;
  }
  for (uint64_t i = len_exponent - 1, main_exponent = exponent;
       main_exponent > 0; i--, main_exponent /= 10, *count += 1) {
    buf[i] = "0123456789abcdef"[main_exponent % 10];
  }
  buf += len_exponent;
  return buf;
}

char *work_with_mantiss(long double mantiss, int len_mantiss, int *count,
                        char *buf, int accuracy, int zero, int flag_g) {
  if (mantiss) {
    for (int i = 0; i < zero && i < accuracy; i++) {
      *buf++ = '0';
      *count += 1;
    }
  }
  for (uint64_t cp_len_mantiss = len_mantiss - 1, main_mantiss = mantiss;
       main_mantiss > 0; cp_len_mantiss--, main_mantiss /= 10, *count += 1) {
    buf[cp_len_mantiss] = "0123456789abcdef"[main_mantiss % 10];
  }
  if (mantiss == 0 && !flag_g) {
    for (int j = 0; j < accuracy; j++) {
      *buf++ = '0';
      *count += 1;
    }
  }
  buf += len_mantiss;
  return buf;
}

char *plus_and_space(flags f, char *buf, int *i, int negative) {
  if (!f.zero && f.space && !f.plus && !f.minus) {
    *buf++ = ' ';
    *i += 1;
  } else if (f.space && (f.minus || f.zero) && !f.plus && !negative) {
    *buf++ = ' ';
    *i += 1;
  }
  if (f.plus) {
    if (!negative) {
      *buf++ = '+';
      *i += 1;
    }
  }
  return buf;
}

char *add_zero(flags f, int len, int *i, char *buf, int negative) {
  if (f.plus && !negative) len++;
  for (int j = f.width - len; j > 0; j--) {
    buf[j] = '0';
    *i += 1;
  }
  if (!negative) buf[0] = '0';
  if (f.width > len) buf += f.width - len;
  return buf;
}

int len_of_number(uint64_t number, int base) {
  int length = 0;
  for (uint64_t n = number; n > 0; n /= base) length++;
  return length;
}

void num_to_str(uint64_t x, int len, int base, int *count, char *buf,
                int flag_X) {
  for (int i = len - 1; i >= 0 && x > 0; i--, x /= base) {
    if (flag_X)
      buf[i] = "0123456789ABCDEF"[x % base];
    else
      buf[i] = "0123456789abcdef"[x % base];
    *count += 1;
  }
}

char *s21_e_E(flags f, char *buf, int count_e, int len_count_e, int *count,
              int flag_minus) {
  if (f.specif == 'e' || f.specif == 'E') {
    if (f.specif == 'e') {
      *buf++ = 'e';
    } else
      *buf++ = 'E';
    if (!flag_minus)
      *buf++ = '+';
    else
      *buf++ = '-';
    if (count_e < 10) {
      *buf++ = '0';
      *count += 1;
    }
    if (count_e != 0) {
      num_to_str(count_e, len_count_e, 10, count, buf, 0);
    } else {
      *buf++ = '0';
      *count += 1;
    }
    *count += 2;
    buf += len_count_e;
  }
  return buf;
}

void all_len_e_E(int *len_count_e, int count_e, flags f, int *tmp_len) {
  if (f.specif == 'e' || f.specif == 'E') {
    *len_count_e = len_of_number(count_e, 10);
    *tmp_len += *len_count_e + 2;
    if (*len_count_e < 2) *tmp_len += 1;
  }
}

void cast_e(flags f, long double *numb, int *count_e, int *flag_e_minus) {
  if (f.specif == 'e' || f.specif == 'E') {
    *count_e = 0;
    if (*numb < 1 && *numb != 0) {
      while (*numb < 1) {
        *numb *= 10;
        *count_e += 1;
      }
      *flag_e_minus = 1;
    } else {
      while (*numb >= 10) {
        *numb /= 10;
        *count_e += 1;
      }
      if (roundl(*numb) == 10) {
        *numb /= 10;
        *count_e += 1;
      }
    }
  }
}

void all_len_f(int *tmp_len, flags f, int negative, int accuracy) {
  if (f.plus && !negative && (!f.zero || f.minus)) {
    *tmp_len += 1;
  }
  if (!f.hash && !accuracy) {
    *tmp_len -= 1;
  }
  if (f.space && !f.plus) {
    if ((!f.zero && !f.minus) || (!negative && f.minus) ||
        (f.zero && !negative)) {
      *tmp_len += 1;
    }
  }
}

void len_exp_mantiss(int *len_exponent, long double *exponent, int *len_mantiss,
                     long double *mantiss, int accuracy, flags f,
                     long double full_mantiss) {
  for (uint64_t i = *mantiss; i > 0; i /= 10) *len_mantiss += 1;
  if (*len_mantiss > accuracy && *mantiss >= 10) {
    *exponent += 1;
    *mantiss = 0;
    *len_mantiss -= 1;
  } else if (!accuracy && f.flag_accuracy && full_mantiss > 5) {
    *exponent += 1;
  }
  for (long double numb1 = *exponent; numb1 >= 1; numb1 /= 10.0)
    *len_exponent += 1;
  if (!*exponent && !*len_exponent) *len_exponent += 1;
}

char *add_x_X(flags f, int *count, char *buf) {
  if (f.hash) {
    if (f.specif == 'x') {
      *buf++ = '0';
      *buf++ = 'x';
      *count += 2;
    } else if (f.specif == 'X') {
      *buf++ = '0';
      *buf++ = 'X';
      *count += 2;
    }
  }
  return buf;
}

void processing_g(flags *f, long double numb, int *accuracy, int *flag_g) {
  if (s21_strchr("Gg", f->specif)) {
    int count_e = 0, exp = 0;
    *flag_g = 1;
    for (long double num_cp = roundl(numb); num_cp >= 10; num_cp /= 10)
      count_e++;
    for (long double num_cp = numb; num_cp > 0 && num_cp < 1; num_cp *= 10)
      count_e--;
    exp = (count_e < -4 || count_e >= *accuracy);
    if (exp) {
      if (f->specif == 'g')
        f->specif = 'e';
      else if (f->specif == 'G')
        f->specif = 'E';
      *accuracy -= 1;
    } else
      *accuracy -= count_e + 1;
    if (numb == 0) *accuracy = 0;
    if (!*accuracy) {
      f->accuracy = 0;
      *accuracy = 1;
      f->flag_accuracy = 1;
    }
  }
}
