#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include "s21_string.h"

typedef struct {
  int plus, minus, hash, space, l, zero, width, accuracy, flag_accuracy;
  char length, specif;
} flags;

//               === --- main sprintf --- ===
//

int s21_sprintf(char *buf, const char *format, ...);

//
//               === --- specifiers --- ===
//

void s21_n(int count, va_list ap);
void s21_int(va_list ap, char *buf, flags f, int *i);
void s21_p(va_list ap, int *count, char *buf, flags f);
void s21_u_int(va_list ap, char *buf, flags f, int *i);
void s21_ch(va_list ap, char *buf, flags f, int *count);
void s21_str(va_list ap, char *buf, flags f, int *count);
void s21_float(va_list ap, char *buf, int *count, flags f);

//
//        === --- additional items in sprintf --- ===
//         -- flags -- width -- accuracy -- length --
//

const char *pars_flags(flags *f, const char *format);
const char *pars_length(flags *f, const char *format);
const char *pars_width(flags *f, const char *format, va_list ap);
char *pars_specifiers(flags f, va_list ap, char *buf, int *count);
const char *pars_accurasy(flags *f, const char *format, va_list ap);

//
//                === ---general functions --- ===
//

int len_of_number(uint64_t number, int base);
char *add_space(flags f, int len, int *i, char *buf);
char *add_zero_integer(flags f, int len, int *i, char *buf);
char *plus_and_space(flags f, char *buf, int *i, int negative);
char *add_zero(flags f, int len, int *i, char *buf, int negative);
void num_to_str(uint64_t x, int len, int base, int *count, char *buf,
                int flag_X);

//
//                === --- fractional processing ---===
//                             * float *
//

char *add_x_X(flags f, int *count, char *buf);
void all_len_f(int *tmp_len, flags f, int negative, int accuracy);
void all_len_e_E(int *len_count_e, int count_e, flags f, int *tmp_len);
void cast_e(flags f, long double *numb, int *count_e, int *flag_e_minus);
void processing_g(flags *f, long double numb, int *accuracy, int *flag_g);
char *work_with_exponent(char *buf, long double exponent, int *count,
                         int len_exponent, int negative);
char *work_with_mantiss(long double mantiss, int len_mantiss, int *count,
                        char *buf, int accuracy, int zero, int flag_g);
void accurasy_in_float(flags f, long double *mantiss, int *number_of_zero,
                       int *count, int *len_mantiss, long double *exponent);
char *s21_e_E(flags f, char *buf, int count_e, int len_count_e, int *count,
              int flag);
void len_exp_mantiss(int *len_exponent, long double *exponent, int *len_mantiss,
                     long double *mantiss, int accuracy, flags f,
                     long double full_mantiss);

#endif  //  S21_SPRINTF_H_