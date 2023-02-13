#include "all_test.h"

START_TEST(sprintf1) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "HI, it's school 21");
  s21_sprintf(buf1, "HI, it's school 21");
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf2) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%d", 0);
  s21_sprintf(buf1, "%d", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf3) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%i", 10);
  s21_sprintf(buf1, "%i", 10);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf4) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%i", 123456789);
  s21_sprintf(buf1, "%i", 123456789);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf5) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%d", -123456789);
  s21_sprintf(buf1, "%d", -123456789);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf6) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%20d", 10);
  s21_sprintf(buf1, "%20d", 10);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf7) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%20i", 5);
  s21_sprintf(buf1, "%20i", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf8) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%ld", 12345678912345);
  s21_sprintf(buf1, "%ld", 12345678912345);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf9) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%+i", 5);
  s21_sprintf(buf1, "%+i", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf10) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%+i", -5);
  s21_sprintf(buf1, "%+i", -5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf11) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%+d", -5);
  s21_sprintf(buf1, "%+d", -5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf12) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%+d", 5);
  s21_sprintf(buf1, "%+d", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf13) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-d", 5);
  s21_sprintf(buf1, "%-d", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf14) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10d", 5);
  s21_sprintf(buf1, "%-10d", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf15) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% d", 5);
  s21_sprintf(buf1, "% d", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf16) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% i", 5);
  s21_sprintf(buf1, "% i", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf17) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%hi", 5);
  s21_sprintf(buf1, "%hi", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf18) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%hi", -5);
  s21_sprintf(buf1, "%hi", -5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf19) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%hd", -5);
  s21_sprintf(buf1, "%hd", -5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf20) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%u", 5);
  s21_sprintf(buf1, "%u", 5);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf21) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%hu", 100);
  s21_sprintf(buf1, "%hu", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf22) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%lu", 12345678912345);
  s21_sprintf(buf1, "%lu", 12345678912345);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf23) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10u", 100);
  s21_sprintf(buf1, "%-10u", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf24) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%10u", 100);
  s21_sprintf(buf1, "%10u", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf25) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.5u", 100);
  s21_sprintf(buf1, "%.5u", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf26) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.5d", 100);
  s21_sprintf(buf1, "%.5d", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf27) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.5i", 100);
  s21_sprintf(buf1, "%.5i", 100);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf28) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%lu", 10000012345);
  s21_sprintf(buf1, "%lu", 10000012345);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf29) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%20lu", 10000012345);
  s21_sprintf(buf1, "%20lu", 10000012345);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf30) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-20lu", 10000012345);
  s21_sprintf(buf1, "%-20lu", 10000012345);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf31) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10hu", 10000);
  s21_sprintf(buf1, "%-10hu", 10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf32) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-u", 10000);
  s21_sprintf(buf1, "%-u", 10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf33) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.15u", 10000);
  s21_sprintf(buf1, "%.15u", 10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf34) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.15i", 10000);
  s21_sprintf(buf1, "%.15i", 10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf35) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.15i", -10000);
  s21_sprintf(buf1, "%.15i", -10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf36) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.15u", 10000);
  s21_sprintf(buf1, "%.15u", 10000);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf37) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.2u", 0);
  s21_sprintf(buf1, "%.2u", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf38) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.2d", 0);
  s21_sprintf(buf1, "%.2d", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf39) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%.2d%10u", 0, 20);
  s21_sprintf(buf1, "%.2d%10u", 0, 20);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf40) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% 3d", 20);
  s21_sprintf(buf1, "% 3d", 20);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf41) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% 3i", 0);
  s21_sprintf(buf1, "% 3i", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf42) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% 3i", -1);
  s21_sprintf(buf1, "% 3i", -1);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf43) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%3u", 0);
  s21_sprintf(buf1, "%3u", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf44) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-3u", 0);
  s21_sprintf(buf1, "%-3u", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf45) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10u", 12);
  s21_sprintf(buf1, "%-10u", 12);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf46) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10d", 12);
  s21_sprintf(buf1, "%-10d", 12);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf47) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%-10d", 0);
  s21_sprintf(buf1, "%-10d", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf48) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%10d", 0);
  s21_sprintf(buf1, "%10d", 0);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf49) {
  char buf[100];
  char buf1[100];
  int x = 10;
  sprintf(buf, "gfgfg%p", &x);
  s21_sprintf(buf1, "gfgfg%p", &x);
  ck_assert_pstr_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf50) {
  char buf[100];
  char buf1[100];
  int x = 10;
  sprintf(buf, "gfgfg%n", &x);
  s21_sprintf(buf1, "gfgfg%n", &x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf52) {
  char buf[100];
  char buf1[100];
  int x = 123;
  sprintf(buf, "%20p", &x);
  s21_sprintf(buf1, "%20p", &x);
  ck_assert_pstr_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf53) {
  char buf[100];
  char buf1[100];
  char ch = 'k';
  sprintf(buf, "%c", ch);
  s21_sprintf(buf1, "%c", ch);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf54) {
  char buf[100];
  char buf1[100];
  char *k = "Hello Hello";
  sprintf(buf, "%s", k);
  s21_sprintf(buf1, "%s", k);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf55) {
  char buf[100];
  char buf1[100];
  char *str = "Hello Hello";
  sprintf(buf, "%20s", str);
  s21_sprintf(buf1, "%20s", str);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf56) {
  char buf[100];
  char buf1[100];
  char *str = NULL;
  sprintf(buf, "%20s", str);
  s21_sprintf(buf1, "%20s", str);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf57) {
  char buf[100];
  char buf1[100];
  char *str = "Hello 21";
  sprintf(buf, "%.20s", str);
  s21_sprintf(buf1, "%.20s", str);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf58) {
  char buf[100];
  char buf1[100];
  float x = 1.23456;
  sprintf(buf, "%f", x);
  s21_sprintf(buf1, "%f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf59) {
  char buf[100];
  char buf1[100];
  float x = 1.23456;
  sprintf(buf, "%10f", x);
  s21_sprintf(buf1, "%10f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf60) {
  char buf[100];
  char buf1[100];
  float x = 1.23456;
  sprintf(buf, "%10.10f", x);
  s21_sprintf(buf1, "%10.10f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf61) {
  char buf[100];
  char buf1[100];
  float x = -1.23456;
  sprintf(buf, "%10.10f", x);
  s21_sprintf(buf1, "%10.10f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf62) {
  char buf[100];
  char buf1[100];
  float x = 10.123456;
  sprintf(buf, "% 010.10f", x);
  s21_sprintf(buf1, "% 10.10f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf63) {
  char buf[100];
  char buf1[100];
  double x = 10.123456;
  sprintf(buf, "%#lf", x);
  s21_sprintf(buf1, "%#lf", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf64) {
  char buf[100];
  char buf1[100];
  long double x = 10.123456123456123222;
  sprintf(buf, "%0Lf", x);
  s21_sprintf(buf1, "%0Lf", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf65) {
  char buf[100];
  char buf1[100];
  float x = 10.1234;
  sprintf(buf, "%e", x);
  s21_sprintf(buf1, "%e", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf66) {
  char buf[100];
  char buf1[100];
  float x = 10.1234;
  sprintf(buf, "%E", x);
  s21_sprintf(buf1, "%E", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf67) {
  char buf[100];
  char buf1[100];
  int x = 10000;
  sprintf(buf, "%x", x);
  s21_sprintf(buf1, "%x", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf68) {
  char buf[100];
  char buf1[100];
  int x = 10000;
  sprintf(buf, "%x", x);
  s21_sprintf(buf1, "%x", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf69) {
  char buf[100];
  char buf1[100];
  float x = 1.123;
  sprintf(buf, "%g", x);
  s21_sprintf(buf1, "%g", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf70) {
  char buf[100];
  char buf1[100];
  float x = 1.123;
  sprintf(buf, "%G", x);
  s21_sprintf(buf1, "%G", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf71) {
  char buf[100];
  char buf1[100];
  char x = 'g';
  sprintf(buf, "%20c", x);
  s21_sprintf(buf1, "%20c", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf72) {
  char buf[100];
  char buf1[100];
  int x = 999;
  sprintf(buf, "%#x", x);
  s21_sprintf(buf1, "%#x", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf73) {
  char buf[100];
  char buf1[100];
  int x = 999;
  sprintf(buf, "%#X", x);
  s21_sprintf(buf1, "%#X", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf74) {
  char buf[100];
  char buf1[100];
  char x = 'g';
  sprintf(buf, "%-20c", x);
  s21_sprintf(buf1, "%-20c", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf75) {
  char buf[100];
  char buf1[100];
  char *str = "Hello 21";
  sprintf(buf, "%.*s", 5, str);
  s21_sprintf(buf1, "%.*s", 5, str);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf76) {
  char buf[100];
  char buf1[100];
  char *str = "Hello 21";
  sprintf(buf, "%*s", 5, str);
  s21_sprintf(buf1, "%*s", 5, str);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf77) {
  char buf[100];
  char buf1[100];
  int x = 010;
  sprintf(buf, "%o", x);
  s21_sprintf(buf1, "%o", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf78) {
  char buf[100];
  char buf1[100];
  float x = 0.000234;
  sprintf(buf, "%e", x);
  s21_sprintf(buf1, "%e", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf79) {
  char buf[100];
  char buf1[100];
  float x = -0.000234;
  sprintf(buf, "%e", x);
  s21_sprintf(buf1, "%e", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf80) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "%% hehe");
  s21_sprintf(buf1, "%% hehe");
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf81) {
  char buf[100];
  char buf1[100];
  char *str3 = "%p %.20p %.p";
  char *str = "123456789";
  sprintf(buf, str3, str, str, str);
  s21_sprintf(buf1, str3, str, str, str);
  ck_assert_pstr_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf82) {
  char buf[100];
  char buf1[100];
  int x = 010;
  sprintf(buf, "%#o", x);
  s21_sprintf(buf1, "%#o", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf83) {
  char buf[100];
  char buf1[100];
  float x = -0.000234;
  sprintf(buf, "%f", x);
  s21_sprintf(buf1, "%f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf84) {
  char buf[100];
  char buf1[100];
  float x = 0.000234;
  sprintf(buf, "%f", x);
  s21_sprintf(buf1, "%f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf85) {
  char buf[100];
  char buf1[100];
  float x = 12345;
  sprintf(buf, "%.12f", x);
  s21_sprintf(buf1, "%.12f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf86) {
  char buf[100];
  char buf1[100];
  float x = 999.99;
  sprintf(buf, "%.1f", x);
  s21_sprintf(buf1, "%.1f", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf87) {
  char buf[100];
  char buf1[100];
  double x = 999999999.99;
  sprintf(buf, "%.lg", x);
  s21_sprintf(buf1, "%.lg", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf88) {
  char buf[100];
  char buf1[100];
  double x = 0.00123;
  sprintf(buf, "%lg", x);
  s21_sprintf(buf1, "%lg", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf89) {
  char buf[100];
  char buf1[100];
  double x = 999999999.99;
  sprintf(buf, "%.lG", x);
  s21_sprintf(buf1, "%.lG", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf90) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% -20i", 10);
  s21_sprintf(buf1, "% -20i", 10);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf91) {
  char buf[100];
  char buf1[100];
  sprintf(buf, "% 010i", 10);
  s21_sprintf(buf1, "% 010i", 10);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

START_TEST(sprintf92) {
  char buf[100];
  char buf1[100];
  float x = 7.5;
  sprintf(buf, "%e", x);
  s21_sprintf(buf1, "%e", x);
  ck_assert_str_eq(buf, buf1);
}
END_TEST

Suite *test_sprintf_new(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_NEW=-\033[0m");
  TCase *tc = tcase_create("sprintf_new");

  tcase_add_test(tc, sprintf1);
  tcase_add_test(tc, sprintf2);
  tcase_add_test(tc, sprintf3);
  tcase_add_test(tc, sprintf4);
  tcase_add_test(tc, sprintf5);
  tcase_add_test(tc, sprintf6);
  tcase_add_test(tc, sprintf7);
  tcase_add_test(tc, sprintf8);
  tcase_add_test(tc, sprintf9);
  tcase_add_test(tc, sprintf10);
  tcase_add_test(tc, sprintf11);
  tcase_add_test(tc, sprintf12);
  tcase_add_test(tc, sprintf13);
  tcase_add_test(tc, sprintf14);
  tcase_add_test(tc, sprintf15);
  tcase_add_test(tc, sprintf16);
  tcase_add_test(tc, sprintf17);
  tcase_add_test(tc, sprintf18);
  tcase_add_test(tc, sprintf19);
  tcase_add_test(tc, sprintf20);
  tcase_add_test(tc, sprintf21);
  tcase_add_test(tc, sprintf22);
  tcase_add_test(tc, sprintf23);
  tcase_add_test(tc, sprintf24);
  tcase_add_test(tc, sprintf25);
  tcase_add_test(tc, sprintf26);
  tcase_add_test(tc, sprintf27);
  tcase_add_test(tc, sprintf28);
  tcase_add_test(tc, sprintf29);
  tcase_add_test(tc, sprintf30);
  tcase_add_test(tc, sprintf31);
  tcase_add_test(tc, sprintf32);
  tcase_add_test(tc, sprintf33);
  tcase_add_test(tc, sprintf34);
  tcase_add_test(tc, sprintf35);
  tcase_add_test(tc, sprintf36);
  tcase_add_test(tc, sprintf37);
  tcase_add_test(tc, sprintf38);
  tcase_add_test(tc, sprintf39);
  tcase_add_test(tc, sprintf40);
  tcase_add_test(tc, sprintf41);
  tcase_add_test(tc, sprintf42);
  tcase_add_test(tc, sprintf43);
  tcase_add_test(tc, sprintf44);
  tcase_add_test(tc, sprintf45);
  tcase_add_test(tc, sprintf46);
  tcase_add_test(tc, sprintf47);
  tcase_add_test(tc, sprintf48);
  tcase_add_test(tc, sprintf49);
  tcase_add_test(tc, sprintf50);
  tcase_add_test(tc, sprintf52);
  tcase_add_test(tc, sprintf53);
  tcase_add_test(tc, sprintf54);
  tcase_add_test(tc, sprintf55);
  tcase_add_test(tc, sprintf56);
  tcase_add_test(tc, sprintf57);
  tcase_add_test(tc, sprintf58);
  tcase_add_test(tc, sprintf59);
  tcase_add_test(tc, sprintf60);
  tcase_add_test(tc, sprintf61);
  tcase_add_test(tc, sprintf62);
  tcase_add_test(tc, sprintf63);
  tcase_add_test(tc, sprintf64);
  tcase_add_test(tc, sprintf65);
  tcase_add_test(tc, sprintf66);
  tcase_add_test(tc, sprintf67);
  tcase_add_test(tc, sprintf68);
  tcase_add_test(tc, sprintf69);
  tcase_add_test(tc, sprintf70);
  tcase_add_test(tc, sprintf71);
  tcase_add_test(tc, sprintf72);
  tcase_add_test(tc, sprintf73);
  tcase_add_test(tc, sprintf74);
  tcase_add_test(tc, sprintf75);
  tcase_add_test(tc, sprintf76);
  tcase_add_test(tc, sprintf77);
  tcase_add_test(tc, sprintf78);
  tcase_add_test(tc, sprintf79);
  tcase_add_test(tc, sprintf80);
  tcase_add_test(tc, sprintf81);
  tcase_add_test(tc, sprintf82);
  tcase_add_test(tc, sprintf83);
  tcase_add_test(tc, sprintf84);
  tcase_add_test(tc, sprintf85);
  tcase_add_test(tc, sprintf86);
  tcase_add_test(tc, sprintf87);
  tcase_add_test(tc, sprintf88);
  tcase_add_test(tc, sprintf89);
  tcase_add_test(tc, sprintf90);
  tcase_add_test(tc, sprintf91);
  tcase_add_test(tc, sprintf92);

  suite_add_tcase(s, tc);
  return s;
}
