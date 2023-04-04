// #include "../s21_decimal.h"

// void s21_print_decimal_sign(s21_decimal value);
// void s21_print_decimal_value(s21_decimal value);
// void s21_print_decimal_exp(s21_decimal value);

// void s21_print_decimal(s21_decimal value) {
//   s21_print_decimal_sign(value);
//   s21_print_decimal_value(value);
//   s21_print_decimal_exp(value);
// }

// void s21_print_decimal_sign(s21_decimal value) {
//   if (s21_get_sign(value)) putchar('-');
// }

// void s21_print_decimal_value(s21_decimal value) {
//   putchar('[');
//   for (int i = 2; i >= 0; --i) {
//     printf("%2x|", value.bits[i]);
//   }
//   putchar(']');
// }

// void s21_print_decimal_exp(s21_decimal value) {
//   printf(".%d", s21_get_exp(value));
// }
