#ifndef S21_SSCANF_H_
#define S21_SSCANF_H_

#include "s21_string.h"

typedef struct spec_s {
  char type;
  char no_assign;
  int width, flag_width;
  char length;
  char double_len;
  char ns;
} specifier;

int s21_read_int(specifier sp, const char **src, void *to);
int s21_read_uint(specifier sp, const char **src, void *to);
int s21_sscanf(const char *str, const char *format, ...);
int read_float(specifier sp, const char **src, void *to);

int s21_strok(specifier sp, const char **src, void *to);
int s21_char(specifier sp, const char **src, void *to);

int s21_numerical_system(specifier sp, const char **src, uint64_t *to);

#define BUFF_SIZE 100

char hex_digit(char c);

#endif  // S21_SSCANF_H_