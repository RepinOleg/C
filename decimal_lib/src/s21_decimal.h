#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define S21_OK 0
#define S21_OVERFLOW 1
#define S21_CONVERT_ERR 1
#define S21_CALC_ERR 1
#define S21_UNDERFLOW 2
#define S21_DIVISION_BY_ZERO 3
#define S21_COMPUTE_ERR 4
#define S21_MINUS_SIGN 0x80000000

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

//
// * ---=== Common operations ===--- *
//
void s21_abs(s21_decimal *value);
int s21_bin_exp(int e);
int s21_is_correct_sign(int sign);
int s21_is_correct_exp(int exp);
int s21_is_correct_decimal(s21_decimal value);
int s21_get_sign(s21_decimal value);
int s21_get_exp(s21_decimal value);
void s21_set_sign(s21_decimal *value, int sign);
void s21_set_exp(s21_decimal *value, int exp);
void s21_init_decimal(int value[3], int sign, int exponent,
                      s21_decimal *result);
// void s21_print_decimal(s21_decimal value);
int s21_div_by_ten(s21_decimal *result);
int s21_normalize(s21_decimal *value_1, s21_decimal *value_2);
int s21_lower_exp_decimal(int lower_to_exp, s21_decimal *result);
int s21_is_values_equal(s21_decimal a, s21_decimal b);
void s21_init_decimal_result(s21_decimal *result);

//
// * ---=== Arithmetic Operators ===--- *
//

//
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void result_0(s21_decimal *result);

//
// * ---=== Comparison Operators ===--- *
//

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

//
// * ---=== Convertors and parsers ===--- *
//

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//
// * ---=== Another functions ===--- *
//

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);