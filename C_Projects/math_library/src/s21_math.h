#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <ctype.h>
#include <stdint.h>

#define S21_ESP 1e-9
#define S21_EPS 1e-17
#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)
#define LOOP 5000
#define S21_ATAN_INFINITY 1.5707963267948965579989817342720925807952880859375
#define S21_DBL_MAX (double)1.79769313486231570814527423731704357e+308L
#define S21_DBL_MIN (double)2.22507385850720138309023271733240406e-308L
#define S21_MATH_PI 3.14159265358979323846
#define S21_MATH_E 2.71828182845904523536
#define S21_PI 3.14159265358979324
#define S21_2PI 6.283185307179

// #define S21_POS_INFINITY (1.0 / 0.0)
// #define S21_NEG_INFINITY (-1.0 / 0.0)

int8_t s21_is_zero(double x);
double re_mod(double x);
int s21_abs(int x);
double reader(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(int x);
double decrease_in_the_number(double x);
#endif  //  S21_MATH_H_
