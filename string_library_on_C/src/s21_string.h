#ifndef S21_STRING_H_
#define S21_STRING_H_

typedef long unsigned int s21_size_t;
#define S21_NULL ((void *)0)

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_sprintf.h"
#include "s21_sscanf.h"

//
// * ---=== string.h Functions ===--- *
//

void *s21_memchr(const void *str, int ch, s21_size_t len);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t count);
void *s21_memset(void *dest, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int ch);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str, const char *sym);
char *s21_strrchr(const char *str, int ch);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *str, const char *find_str);
char *s21_strtok(char *str, const char *delim);

//
// * ---=== Special string processing functions ===--- *
//

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

//
// * ---=== Additional functions ===--- *
//

int s21_atoi(const char *str);
int s21_isdigit(char ch);

#endif  // S21_STRING_H_
