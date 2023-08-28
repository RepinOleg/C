#include "help.h"
#include "test.h"

// TODO: Тесты на ненормальные float //

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

// TODO: Тесты на некорректные данные //

START_TEST(test_from_float_to_decimal_incorrect1) {
  float f = 1.0f;
  int code = s21_from_float_to_decimal(f, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big) {
  float f = fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big_negate) {
  float f = -fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

// TODO: Tests for correct data //

START_TEST(test_from_float_to_decimal_ok1) {
  // 2.28401628E-19
  int f = 545706772;
  // 0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2) {
  // -2.28401628E-19
  int f = -1601776876;
  // -0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok3) {
  // 5.92141241E+23
  int f = 1727711253;
  // 592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok4) {
  // -5.92141241E+23
  int f = -419772395;
  // -592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok5) {
  // 2.1349025E-18
  int f = 572360491;
  // 0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok6) {
  // -2.1349025E-18
  int f = -1575123157;
  // -0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok7) {
  // 2.38582807E-08
  int f = 852291818;
  // 0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok8) {
  // -2.38582807E-08
  int f = -1295191830;
  // -0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok9) {
  // 7.91617864E+11
  int f = 1396199450;
  // 791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok10) {
  // -7.91617864E+11
  int f = -751284198;
  // -791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok11) {
  // 1.99102057E+21
  int f = 1658314220;
  // 1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok12) {
  // -1.99102057E+21
  int f = -489169428;
  // -1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok13) {
  // 9.29209423E+24
  int f = 1760949678;
  // 9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok14) {
  // -9.29209423E+24
  int f = -386533970;
  // -9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok15) {
  // 0.000115481133
  int f = 955395702;
  // 0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok16) {
  // -0.000115481133
  int f = -1192087946;
  // -0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok19) {
  // 3.91406387E+11
  int f = 1387676487;
  // 391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok20) {
  // -3.91406387E+11
  int f = -759807161;
  // -391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok21) {
  // 4.33683636E+17
  int f = 1556125727;
  // 433683600000000000
  s21_decimal decimal_check = {{0xBAE9A000, 0x604C0EF, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok22) {
  // -4.33683636E+17
  int f = -591357921;
  // -433683600000000000
  s21_decimal decimal_check = {{0xBAE9A000, 0x604C0EF, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok23) {
  // 1.41147295E+15
  int f = 1486911301;
  // 1411473000000000
  s21_decimal decimal_check = {{0x2AC66A00, 0x503BA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok24) {
  // -1.41147295E+15
  int f = -660572347;
  // -1411473000000000
  s21_decimal decimal_check = {{0x2AC66A00, 0x503BA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok25) {
  // 4.42169156E-14
  int f = 692527778;
  // 0.00000000000004421692
  s21_decimal decimal_check = {{0x43783C, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok26) {
  // -4.42169156E-14
  int f = -1454955870;
  // -0.00000000000004421692
  s21_decimal decimal_check = {{0x43783C, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok27) {
  // 9.34666258E+22
  int f = 1704875696;
  // 93466630000000000000000
  s21_decimal decimal_check = {{0x14A70000, 0xD60EE992, 0x13CA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok28) {
  // -9.34666258E+22
  int f = -442607952;
  // -93466630000000000000000
  s21_decimal decimal_check = {{0x14A70000, 0xD60EE992, 0x13CA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok29) {
  // 3.69914818
  int f = 1080868568;
  // 3.699148
  s21_decimal decimal_check = {{0x3871CC, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok30) {
  // -3.69914818
  int f = -1066615080;
  // -3.699148
  s21_decimal decimal_check = {{0x3871CC, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok31) {
  // 0.000194235196
  int f = 961260445;
  // 0.0001942352
  s21_decimal decimal_check = {{0x1DA350, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok32) {
  // -0.000194235196
  int f = -1186223203;
  // -0.0001942352
  s21_decimal decimal_check = {{0x1DA350, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok33) {
  // 1.47526702E-09
  int f = 818594392;
  // 0.000000001475267
  s21_decimal decimal_check = {{0x1682C3, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok34) {
  // -1.47526702E-09
  int f = -1328889256;
  // -0.000000001475267
  s21_decimal decimal_check = {{0x1682C3, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok35) {
  // 6.55416339E+17
  int f = 1561430043;
  // 655416300000000000
  s21_decimal decimal_check = {{0xFD803800, 0x91881A6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok36) {
  // -6.55416339E+17
  int f = -586053605;
  // -655416300000000000
  s21_decimal decimal_check = {{0xFD803800, 0x91881A6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok37) {
  // 5.50590079E+19
  int f = 1614743097;
  // 55059010000000000000
  s21_decimal decimal_check = {{0x3EAE2000, 0xFC18E5E1, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok38) {
  // -5.50590079E+19
  int f = -532740551;
  // -55059010000000000000
  s21_decimal decimal_check = {{0x3EAE2000, 0xFC18E5E1, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok39) {
  // 7.84344106E+27
  int f = 1842003850;
  // 7843441000000000000000000000
  s21_decimal decimal_check = {{0x4A00000, 0x991CAE08, 0x1957F13C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok40) {
  // -7.84344106E+27
  int f = -305479798;
  // -7843441000000000000000000000
  s21_decimal decimal_check = {{0x4A00000, 0x991CAE08, 0x1957F13C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok41) {
  // 1.49999994E-28
  int f = 289285576;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok42) {
  // -1.49999994E-28
  int f = -1858198072;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok43) {
  // 1.49999814E-28
  int f = 289285561;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok44) {
  // -1.49999814E-28
  int f = -1858198087;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok45) {
  // 1.00000018E-28
  int f = 285050809;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok46) {
  // -1.00000018E-28
  int f = -1862432839;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok47) {
  // 1.00000012E-28
  int f = 285050808;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok48) {
  // -1.00000012E-28
  int f = -1862432840;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok49) {
  // 1.00000006E-28
  int f = 285050807;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok50) {
  // -1.00000006E-28
  int f = -1862432841;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok51) {
  // 1E-28
  int f = 285050806;
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok52) {
  // -1E-28
  int f = -1862432842;
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok53) {
  // 10000005
  int f = 1259902597;
  // 10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok54) {
  // -10000005
  int f = -887581051;
  // -10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok55) {
  // 10000002
  int f = 1259902594;
  // 10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok56) {
  // -10000002
  int f = -887581054;
  // -10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok57) {
  // 10000001
  int f = 1259902593;
  // 10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok58) {
  // -10000001
  int f = -887581055;
  // -10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok59) {
  // 10000000
  int f = 1259902592;
  // 10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok60) {
  // -10000000
  int f = -887581056;
  // -10000000
  s21_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

Suite *s21_test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[43m-=s21_from_float_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_rc");

  // TODO: Тесты на ненормальные float //
  tcase_add_test(tc, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal6);

  // TODO: Тесты на некорректные данные //

  tcase_add_test(tc, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc, test_from_float_to_decimal_fail_big);
  tcase_add_test(tc, test_from_float_to_decimal_fail_big_negate);

  // TODO: Tests for correct data //

  tcase_add_test(tc, test_from_float_to_decimal_ok1);
  tcase_add_test(tc, test_from_float_to_decimal_ok2);
  tcase_add_test(tc, test_from_float_to_decimal_ok3);
  tcase_add_test(tc, test_from_float_to_decimal_ok4);
  tcase_add_test(tc, test_from_float_to_decimal_ok5);
  tcase_add_test(tc, test_from_float_to_decimal_ok6);
  tcase_add_test(tc, test_from_float_to_decimal_ok7);
  tcase_add_test(tc, test_from_float_to_decimal_ok8);
  tcase_add_test(tc, test_from_float_to_decimal_ok9);
  tcase_add_test(tc, test_from_float_to_decimal_ok10);
  tcase_add_test(tc, test_from_float_to_decimal_ok11);
  tcase_add_test(tc, test_from_float_to_decimal_ok12);
  tcase_add_test(tc, test_from_float_to_decimal_ok13);
  tcase_add_test(tc, test_from_float_to_decimal_ok14);
  tcase_add_test(tc, test_from_float_to_decimal_ok15);
  tcase_add_test(tc, test_from_float_to_decimal_ok16);
  tcase_add_test(tc, test_from_float_to_decimal_ok19);
  tcase_add_test(tc, test_from_float_to_decimal_ok20);
  tcase_add_test(tc, test_from_float_to_decimal_ok21);
  tcase_add_test(tc, test_from_float_to_decimal_ok22);
  tcase_add_test(tc, test_from_float_to_decimal_ok23);
  tcase_add_test(tc, test_from_float_to_decimal_ok24);
  tcase_add_test(tc, test_from_float_to_decimal_ok25);
  tcase_add_test(tc, test_from_float_to_decimal_ok26);
  tcase_add_test(tc, test_from_float_to_decimal_ok27);
  tcase_add_test(tc, test_from_float_to_decimal_ok28);
  tcase_add_test(tc, test_from_float_to_decimal_ok29);
  tcase_add_test(tc, test_from_float_to_decimal_ok30);
  tcase_add_test(tc, test_from_float_to_decimal_ok31);
  tcase_add_test(tc, test_from_float_to_decimal_ok32);
  tcase_add_test(tc, test_from_float_to_decimal_ok33);
  tcase_add_test(tc, test_from_float_to_decimal_ok34);
  tcase_add_test(tc, test_from_float_to_decimal_ok35);
  tcase_add_test(tc, test_from_float_to_decimal_ok36);
  tcase_add_test(tc, test_from_float_to_decimal_ok37);
  tcase_add_test(tc, test_from_float_to_decimal_ok38);
  tcase_add_test(tc, test_from_float_to_decimal_ok39);
  tcase_add_test(tc, test_from_float_to_decimal_ok40);
  tcase_add_test(tc, test_from_float_to_decimal_ok41);
  tcase_add_test(tc, test_from_float_to_decimal_ok42);
  tcase_add_test(tc, test_from_float_to_decimal_ok43);
  tcase_add_test(tc, test_from_float_to_decimal_ok44);
  tcase_add_test(tc, test_from_float_to_decimal_ok45);
  tcase_add_test(tc, test_from_float_to_decimal_ok46);
  tcase_add_test(tc, test_from_float_to_decimal_ok47);
  tcase_add_test(tc, test_from_float_to_decimal_ok48);
  tcase_add_test(tc, test_from_float_to_decimal_ok49);
  tcase_add_test(tc, test_from_float_to_decimal_ok50);
  tcase_add_test(tc, test_from_float_to_decimal_ok51);
  tcase_add_test(tc, test_from_float_to_decimal_ok52);
  tcase_add_test(tc, test_from_float_to_decimal_ok53);
  tcase_add_test(tc, test_from_float_to_decimal_ok54);
  tcase_add_test(tc, test_from_float_to_decimal_ok55);
  tcase_add_test(tc, test_from_float_to_decimal_ok56);
  tcase_add_test(tc, test_from_float_to_decimal_ok57);
  tcase_add_test(tc, test_from_float_to_decimal_ok58);
  tcase_add_test(tc, test_from_float_to_decimal_ok59);
  tcase_add_test(tc, test_from_float_to_decimal_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_from_float_to_decimal(int f, s21_decimal decimal_check) {
  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}