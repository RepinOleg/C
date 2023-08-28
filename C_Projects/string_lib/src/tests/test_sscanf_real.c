#include <stdbool.h>

#include "all_test.h"

START_TEST(sscanf_spec_real_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_10) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_18) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_19) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(test_s21_d_spec) {
  int a = 2;
  int b = 0;

  ck_assert_int_eq(s21_sscanf("123", "%*d", &a), 0);
  ck_assert_int_eq(a, 2);

  ck_assert_int_eq(s21_sscanf("123", "%d", &a), sscanf("123", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("++123", "%d", &a), sscanf("++123", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("--123", "%d", &a), sscanf("--123", "%d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("f", "%5d", &a), sscanf("f", "%5d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf(" ", "%5d", &a), sscanf(" ", "%5d", &b));
  ck_assert_int_eq(a, b);

  short sa = 0;
  short sb = 0;
  ck_assert_int_eq(s21_sscanf("123456", "%hd", &sa),
                   sscanf("123456", "%hd", &sb));
  ck_assert_int_eq(sa, sb);

  ck_assert_int_eq(s21_sscanf("98765", "%3d", &a), sscanf("98765", "%3d", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("98765", "%3hd%d", &sa, &a),
                   sscanf("98765", "%3hd%d", &sb, &b));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(a, b);

  int c = 0;
  int d = 0;
  ck_assert_int_eq(s21_sscanf("111%111", "%d%%%d", &a, &b),
                   sscanf("111%111", "%d%%%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("222%222", "%d %d", &a, &b),
                   sscanf("222%222", "%d %d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("333abcde333", "%dabcde%d", &a, &b),
                   sscanf("333abcde333", "%dabcde%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("44", "%1d %1d", &a, &b),
                   sscanf("44", "%1d %1d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("4 4", "%d%d", &a, &b),
                   sscanf("4 4", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("123as 234", "%d%d", &a, &b),
                   sscanf("123as 234", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("", "%d", &a), sscanf("", "%d", &c));
  ck_assert_int_eq(a, c);

  ck_assert_int_eq(s21_sscanf(" ", "%d", &a), sscanf(" ", "%d", &c));
  ck_assert_int_eq(a, c);

  int res = s21_sscanf("123", "");
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_sscanf("123", "a"), 0);

  ck_assert_int_eq(s21_sscanf("123123", "%3d%d", &a, &b),
                   sscanf("123123", "%3d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("123", "%y", &a), 0);

  ck_assert_int_eq(s21_sscanf("-123", "%d", &a), sscanf("-123", "%d", &c));
  ck_assert_int_eq(a, c);

  ck_assert_int_eq(s21_sscanf("+123", "%d", &a), sscanf("+123", "%d", &c));
  ck_assert_int_eq(a, c);

  ck_assert_int_eq(s21_sscanf("4 f", "%d%d", &a, &b),
                   sscanf("4 f", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("4", "%d%d", &a, &b),
                   sscanf("4", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  ck_assert_int_eq(s21_sscanf("", "%d%d", &a, &b), sscanf("", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long int a1 = 2;
  long int b1 = 2;

  ck_assert_int_eq(s21_sscanf("123", "%ld", &a1), sscanf("123", "%ld", &b1));
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_parse_uint) {
  unsigned int a = 0, b = 0;
  unsigned long la = 0, lb = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%u", &a),
                   sscanf("1234567890", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("12345678901", "%u", &a),
                   sscanf("12345678901", "%u", &b));
  ck_assert_int_eq(a, b);

  unsigned short sa = 0, sb = 0;
  ck_assert_int_eq(s21_sscanf("1234567890", "%5hu%lu", &sa, &la),
                   sscanf("1234567890", "%5hu%lu", &sb, &lb));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(la, lb);

  ck_assert_int_eq(s21_sscanf("123", "%5u", &a), sscanf("123", "%5u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-123", "%u", &a), sscanf("-123", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+123", "%u", &a), sscanf("+123", "%u", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+123", "%2u", &a), sscanf("+123", "%2u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_hex) {
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
                   sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
                   sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
                   sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0X1ACDEF", "%X", &a),
                   sscanf("0X1ACDEF", "%X", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0x1aBcDeF", "%x", &a),
                   sscanf("0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%x", &a),
                   sscanf("01AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%X", &a),
                   sscanf("01AbCdEf", "%X", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("x1aBcDeF", "%x", &a),
                   sscanf("x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(s21_sscanf("X1aBcDeF", "%X", &a),
                   sscanf("X1AbCdEf", "%X", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-0x1aBcDeF", "%x", &a),
                   sscanf("-0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("++0x1aBcDeF", "%x", &a),
                   sscanf("++0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+0x1aBcDeF", "%x", &a),
                   sscanf("+0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+0x1aBcDeF", "%5x", &a),
                   sscanf("+0x1AbCdEf", "%5x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_oct) {
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("01234567", "%o", &a),
                   sscanf("01234567", "%o", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("21234567", "%o", &a),
                   sscanf("21234567", "%o", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-01234567", "%o", &a),
                   sscanf("-01234567", "%o", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0-1234567", "%o", &a),
                   sscanf("0-1234567", "%o", &b));

  a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("++01234567", "%o", &a),
                   sscanf("++01234567", "%o", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+01234567", "%o", &a),
                   sscanf("+01234567", "%o", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+01234567", "%5o", &a),
                   sscanf("+01234567", "%5o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_i_uint) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%i", &a),
                   sscanf("1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("01234567", "%i", &a),
                   sscanf("01234567", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("0x1234567890", "%i", &a),
                   sscanf("0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-1234567890", "%i", &a),
                   sscanf("-1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-01234567", "%i", &a),
                   sscanf("-01234567", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-0x1234567890", "%i", &a),
                   sscanf("-0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("--1234567890", "%i", &a),
                   sscanf("--1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-0-1234567890", "%i", &a),
                   sscanf("-0-1234567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("-0x-ab34567890", "%i", &a),
                   sscanf("-0x-ab34567890", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("123abcdef", "%i", &a),
                   sscanf("123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("a123abcdef", "%i", &a),
                   sscanf("a123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("+0xfaf", "%i", &a), sscanf("+0xfaf", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_parse_string) {
  char buf1[100] = {0}, buf2[100] = {0};

  ck_assert_int_eq(s21_sscanf("123", "%c", buf1), sscanf("123", "%c", buf2));
  ck_assert_int_eq(buf1[0], buf2[0]);

  ck_assert_int_eq(s21_sscanf("qwertyuiop", "%9c", buf1),
                   sscanf("qwertyuiop", "%9c", buf2));
  ck_assert_str_eq(buf1, buf2);

  ck_assert_int_eq(s21_sscanf("qwe", "%2c", buf1), sscanf("qwe", "%2c", buf2));
  ck_assert_str_eq(buf1, buf2);

  ck_assert_int_eq(s21_sscanf("1234567890", "%s", buf1),
                   sscanf("1234567890", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  ck_assert_int_eq(s21_sscanf("abcdefghk", "%5s", buf1),
                   sscanf("abcdefghk", "%5s", buf2));
  ck_assert_str_eq(buf1, buf2);

  ck_assert_int_eq(s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);

  char buf3[100] = {0}, buf4[100] = {0};
  ck_assert_int_eq(s21_sscanf("123 456", "%s %s", buf1, buf3),
                   sscanf("123 456", "%s %s", buf2, buf4));
  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf3, buf4);
}
END_TEST

START_TEST(test_scan_n) {
  char buf1[100] = {0}, buf2[100] = {0};
  int a = 0, b = 0;
  ck_assert_int_eq(s21_sscanf("1234567890", "%5s%n", buf1, &a),
                   sscanf("1234567890", "%5s%n", buf2, &b));
  ck_assert_int_eq(a, b);

  ck_assert_int_eq(s21_sscanf("", "%s%n", buf1, &a),
                   sscanf("", "%s%n", buf2, &b));
  ck_assert_int_eq(a, b);
}
END_TEST

long double ldabs(long double x) { return x < 0 ? -x : x; }

bool float_eq(float a, float b) { return fabs(a - b) < 0.00001; }
bool double_eq(double a, double b) { return fabs(a - b) < 0.00001; }
bool ldouble_eq(long double a, long double b) { return ldabs(a - b) < 0.00001; }

START_TEST(test_scan_float) {
  float a = 0, b = 0;
  double da = 0, db = 0;
  long double lda = 0, ldb = 0;
  ck_assert_int_eq(s21_sscanf("123.456", "%f", &a),
                   sscanf("123.456", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123.456", "%lf", &da),
                   sscanf("123.456", "%lf", &db));
  ck_assert(double_eq(da, db));

  ck_assert_int_eq(s21_sscanf("123.456", "%Lf", &lda),
                   sscanf("123.456", "%Lf", &ldb));
  ck_assert(ldouble_eq(lda, ldb));

  ck_assert_int_eq(s21_sscanf("123.456", "%hf", &a),
                   sscanf("123.456", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("1.23e-4", "%e", &a),
                   sscanf("1.23e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf(".123e-4", "%e", &a),
                   sscanf(".123e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf(".123e+4", "%e", &a),
                   sscanf(".123e+4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("-1.23e-4", "%e", &a),
                   sscanf("-1.23e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("+1.23e-4", "%e", &a),
                   sscanf("+1.23e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("+1.23e+4", "%e", &a),
                   sscanf("+1.23e+4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("+123e+4", "%e", &a),
                   sscanf("+123e+4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("1.23e4", "%e", &a), sscanf("1.23e4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123e-4", "%e", &a), sscanf("123e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123e--4", "%e", &a),
                   sscanf("123e--4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123e-4", "%e", &a), sscanf("123e-4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123e-e4", "%e", &a),
                   sscanf("123e-e4", "%e", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("", "%f", &a), sscanf("", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("-", "%f", &a), sscanf("-", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123.456", "%6f", &a),
                   sscanf("123.456", "%6f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("1.23E10", "%6E", &a),
                   sscanf("1.23E10", "%6E", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf(".", "%f", &a), sscanf(".", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("abc", "%f", &a), sscanf("abc", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123.", "%f", &a), sscanf("123.", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf(".123", "%f", &a), sscanf(".123", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("123.abc", "%f", &a),
                   sscanf("123.abc", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("222", "%f", &a), sscanf("222", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("abc", "%f", &a), sscanf("abc", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("++abc", "%f", &a), sscanf("++abc", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("--abc", "%f", &a), sscanf("--abc", "%f", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("1", "%g", &a), sscanf("1", "%g", &b));
  ck_assert(float_eq(a, b));

  ck_assert_int_eq(s21_sscanf("1", "%G", &a), sscanf("1", "%G", &b));
  ck_assert(float_eq(a, b));
}
END_TEST

Suite *test_sscanf_real(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_REAL=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_real_1);
  tcase_add_test(tc, sscanf_spec_real_2);
  tcase_add_test(tc, sscanf_spec_real_3);
  tcase_add_test(tc, sscanf_spec_real_4);
  tcase_add_test(tc, sscanf_spec_real_5);
  tcase_add_test(tc, sscanf_spec_real_6);
  tcase_add_test(tc, sscanf_spec_real_7);
  tcase_add_test(tc, sscanf_spec_real_8);
  tcase_add_test(tc, sscanf_spec_real_9);
  tcase_add_test(tc, sscanf_spec_real_10);
  tcase_add_test(tc, sscanf_spec_real_11);
  tcase_add_test(tc, sscanf_spec_real_12);
  tcase_add_test(tc, sscanf_spec_real_13);
  tcase_add_test(tc, sscanf_spec_real_14);
  tcase_add_test(tc, sscanf_spec_real_15);
  tcase_add_test(tc, sscanf_spec_real_18);
  tcase_add_test(tc, sscanf_spec_real_19);

  tcase_add_test(tc, test_s21_d_spec);
  tcase_add_test(tc, test_parse_uint);
  tcase_add_test(tc, test_parse_hex);
  tcase_add_test(tc, test_parse_oct);
  tcase_add_test(tc, test_parse_i_uint);
  tcase_add_test(tc, test_parse_string);
  tcase_add_test(tc, test_scan_n);
  tcase_add_test(tc, test_scan_float);

  suite_add_tcase(s, tc);
  return s;
}