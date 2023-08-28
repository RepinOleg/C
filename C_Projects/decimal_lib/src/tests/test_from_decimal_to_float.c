#include "test.h"

// TODO: Тесты на некорректные данные //

START_TEST(test_from_decimal_to_float_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_float(decimal, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_float_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

// TODO: =====================================================

START_TEST(test_from_decimal_to_float_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok5) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok6) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok7) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok8) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok9) {
  // 2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok10) {
  // -2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok11) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok12) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok13) {
  // 209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok14) {
  // -209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok15) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok16) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok17) {
  // 20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok18) {
  // -20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok19) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok20) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok21) {
  // 1303569883462612969062.4000000
  s21_decimal decimal = {{0x0, 0xD1840000, 0x2A1EE099, 0x70000}};
  int check = 1653429589;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok22) {
  // -1303569883462612969062.4000000
  s21_decimal decimal = {{0x0, 0xD1840000, 0x2A1EE099, 0x80070000}};
  int check = -494054059;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok23) {
  // 491913163570797346816
  s21_decimal decimal = {{0x0, 0xAAAAA000, 0x1A, 0x0}};
  int check = 1641370965;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok24) {
  // -491913163570797346816
  s21_decimal decimal = {{0x0, 0xAAAAA000, 0x1A, 0x80000000}};
  int check = -506112683;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok25) {
  // 1303569883462612969062.40
  s21_decimal decimal = {{0x0, 0xAA9FA000, 0x1B9A, 0x20000}};
  int check = 1653429589;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok26) {
  // -1303569883462612969062.40
  s21_decimal decimal = {{0x0, 0xAA9FA000, 0x1B9A, 0x80020000}};
  int check = -494054059;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok27) {
  // 393530516782889041920.00000000
  s21_decimal decimal = {{0x0, 0x2D400000, 0x7F2814D6, 0x80000}};
  int check = 1638574762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok28) {
  // -393530516782889041920.00000000
  s21_decimal decimal = {{0x0, 0x2D400000, 0x7F2814D6, 0x80080000}};
  int check = -508908886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok29) {
  // 1042855869474655961088.0000000
  s21_decimal decimal = {{0x0, 0xA3080000, 0x21B24D33, 0x70000}};
  int check = 1650598433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok30) {
  // -1042855869474655961088.0000000
  s21_decimal decimal = {{0x0, 0xA3080000, 0x21B24D33, 0x80070000}};
  int check = -496885215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok31) {
  // 393530516782889041920
  s21_decimal decimal = {{0x0, 0x55554000, 0x15, 0x0}};
  int check = 1638574762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok32) {
  // -393530516782889041920
  s21_decimal decimal = {{0x0, 0x55554000, 0x15, 0x80000000}};
  int check = -508908886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok33) {
  // 1042855869474655961088.00
  s21_decimal decimal = {{0x0, 0x553F4000, 0x1615, 0x20000}};
  int check = 1650598433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok34) {
  // -1042855869474655961088.00
  s21_decimal decimal = {{0x0, 0x553F4000, 0x1615, 0x80020000}};
  int check = -496885215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok35) {
  // 147573952589676412928
  s21_decimal decimal = {{0x0, 0x0, 0x8, 0x0}};
  int check = 1627389952;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok36) {
  // -147573952589676412928
  s21_decimal decimal = {{0x0, 0x0, 0x8, 0x80000000}};
  int check = -520093696;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok37) {
  // 391070974362642494259.20
  s21_decimal decimal = {{0x0, 0x0, 0x848, 0x20000}};
  int check = 1638504858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok38) {
  // -391070974362642494259.20
  s21_decimal decimal = {{0x0, 0x0, 0x848, 0x80020000}};
  int check = -508978790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok39) {
  // 147573943793583390720.00000000
  s21_decimal decimal = {{0x0, 0x50F80000, 0x2FAF07D0, 0x80000}};
  int check = 1627389951;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok40) {
  // -147573943793583390720.00000000
  s21_decimal decimal = {{0x0, 0x50F80000, 0x2FAF07D0, 0x80080000}};
  int check = -520093697;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok41) {
  // 22985891230.286628444002574701
  s21_decimal decimal = {{0xBF03E16D, 0x6B6BC7AF, 0x4A457BCC, 0x120000}};
  int check = 1353400860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok42) {
  // -22985891230.286628444002574701
  s21_decimal decimal = {{0xBF03E16D, 0x6B6BC7AF, 0x4A457BCC, 0x80120000}};
  int check = -794082788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok43) {
  // 60912611760.259565376606822958
  s21_decimal decimal = {{0xED63E22E, 0x1CAA6AC4, 0xC4D1BB44, 0x120000}};
  int check = 1365437131;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok44) {
  // -60912611760.259565376606822958
  s21_decimal decimal = {{0xED63E22E, 0x1CAA6AC4, 0xC4D1BB44, 0x80120000}};
  int check = -782046517;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok45) {
  // -2223897579307571762450.2781231
  s21_decimal decimal = {{0x45DD852F, 0x6F6D520B, 0x47DBA64D, 0x80070000}};
  int check = -487514737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok46) {
  // 2223897579307571762450.2781231
  s21_decimal decimal = {{0x45DD852F, 0x6F6D520B, 0x47DBA64D, 0x70000}};
  int check = 1659968911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok47) {
  // 425018566.63775585139358453614
  s21_decimal decimal = {{0x44844F6E, 0x7A05BE84, 0x8954B63A, 0x140000}};
  int check = 1305127462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok48) {
  // -425018566.63775585139358453614
  s21_decimal decimal = {{0x44844F6E, 0x7A05BE84, 0x8954B63A, 0x80140000}};
  int check = -842356186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok49) {
  // 1126299201.5900530061929990208
  s21_decimal decimal = {{0x2BC1C840, 0x9DC6A468, 0x24648754, 0x130000}};
  int check = 1317422061;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok50) {
  // -1126299201.5900530061929990208
  s21_decimal decimal = {{0x2BC1C840, 0x9DC6A468, 0x24648754, 0x80130000}};
  int check = -830061587;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok51) {
  // -1116577040805.9696921400824500
  s21_decimal decimal = {{0xC3E7D2B4, 0xB1D38949, 0x24141BDA, 0x80100000}};
  int check = -746455913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok52) {
  // 1116577040805.9696921400824500
  s21_decimal decimal = {{0xC3E7D2B4, 0xB1D38949, 0x24141BDA, 0x100000}};
  int check = 1401027735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok53) {
  // -38905301871769420489788179.649
  s21_decimal decimal = {{0xC11744C1, 0x8761F3D9, 0x7DB5B620, 0x80030000}};
  int check = -369051117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok54) {
  // 38905301871769420489788179.649
  s21_decimal decimal = {{0xC11744C1, 0x8761F3D9, 0x7DB5B620, 0x30000}};
  int check = 1778432531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok55) {
  // 23002594240149661603.969415370
  s21_decimal decimal = {{0x2C1CB8CA, 0x660D514F, 0x4A534CCC, 0x90000}};
  int check = 1604295889;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok56) {
  // -23002594240149661603.969415370
  s21_decimal decimal = {{0x2C1CB8CA, 0x660D514F, 0x4A534CCC, 0x80090000}};
  int check = -543187759;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok57) {
  // 60956874736396603250.518950730
  s21_decimal decimal = {{0x1B2834A, 0xDB3CE445, 0xC4F65850, 0x90000}};
  int check = 1616084117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok58) {
  // -60956874736396603250.518950730
  s21_decimal decimal = {{0x1B2834A, 0xDB3CE445, 0xC4F65850, 0x80090000}};
  int check = -531399531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok59) {
  // -1336680634144334.0566723074386
  s21_decimal decimal = {{0x5C009952, 0xBAB30902, 0x2B30C357, 0x800D0000}};
  int check = -661129593;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok60) {
  // 1336680634144334.0566723074386
  s21_decimal decimal = {{0x5C009952, 0xBAB30902, 0x2B30C357, 0xD0000}};
  int check = 1486354055;

  test_from_decimal_to_float(decimal, check);
}

Suite *s21_test_from_decimal_to_float(void) {
  Suite *s = suite_create("\033[43m-=s21_from_decimal_to_float=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_float_rc");

  // TODO: Тесты на некорректные данные //
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual1);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual2);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual3);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual4);
  // tcase_add_test(tc, test_from_decimal_to_float_fail_manual5);
  // tcase_add_test(tc, test_from_decimal_to_float_fail_manual6);
  // tcase_add_test(tc, test_from_decimal_to_float_fail_manual7);
  // tcase_add_test(tc, test_from_decimal_to_float_fail_manual8);
  // tcase_add_test(tc, test_from_decimal_to_float_fail_manual9);

  tcase_add_test(tc, test_from_decimal_to_float_ok1);
  tcase_add_test(tc, test_from_decimal_to_float_ok2);
  tcase_add_test(tc, test_from_decimal_to_float_ok3);
  tcase_add_test(tc, test_from_decimal_to_float_ok4);
  tcase_add_test(tc, test_from_decimal_to_float_ok5);
  tcase_add_test(tc, test_from_decimal_to_float_ok6);
  tcase_add_test(tc, test_from_decimal_to_float_ok7);
  tcase_add_test(tc, test_from_decimal_to_float_ok8);
  tcase_add_test(tc, test_from_decimal_to_float_ok9);
  tcase_add_test(tc, test_from_decimal_to_float_ok10);
  tcase_add_test(tc, test_from_decimal_to_float_ok11);
  tcase_add_test(tc, test_from_decimal_to_float_ok12);
  tcase_add_test(tc, test_from_decimal_to_float_ok13);
  tcase_add_test(tc, test_from_decimal_to_float_ok14);
  tcase_add_test(tc, test_from_decimal_to_float_ok15);
  tcase_add_test(tc, test_from_decimal_to_float_ok16);
  tcase_add_test(tc, test_from_decimal_to_float_ok17);
  tcase_add_test(tc, test_from_decimal_to_float_ok18);
  tcase_add_test(tc, test_from_decimal_to_float_ok19);
  tcase_add_test(tc, test_from_decimal_to_float_ok20);
  tcase_add_test(tc, test_from_decimal_to_float_ok21);
  tcase_add_test(tc, test_from_decimal_to_float_ok22);
  tcase_add_test(tc, test_from_decimal_to_float_ok23);
  tcase_add_test(tc, test_from_decimal_to_float_ok24);
  tcase_add_test(tc, test_from_decimal_to_float_ok25);
  tcase_add_test(tc, test_from_decimal_to_float_ok26);
  tcase_add_test(tc, test_from_decimal_to_float_ok27);
  tcase_add_test(tc, test_from_decimal_to_float_ok28);
  tcase_add_test(tc, test_from_decimal_to_float_ok29);
  tcase_add_test(tc, test_from_decimal_to_float_ok30);
  tcase_add_test(tc, test_from_decimal_to_float_ok31);
  tcase_add_test(tc, test_from_decimal_to_float_ok32);
  tcase_add_test(tc, test_from_decimal_to_float_ok33);
  tcase_add_test(tc, test_from_decimal_to_float_ok34);
  tcase_add_test(tc, test_from_decimal_to_float_ok35);
  tcase_add_test(tc, test_from_decimal_to_float_ok36);
  tcase_add_test(tc, test_from_decimal_to_float_ok37);
  tcase_add_test(tc, test_from_decimal_to_float_ok38);
  tcase_add_test(tc, test_from_decimal_to_float_ok39);
  tcase_add_test(tc, test_from_decimal_to_float_ok40);
  tcase_add_test(tc, test_from_decimal_to_float_ok41);
  tcase_add_test(tc, test_from_decimal_to_float_ok42);
  tcase_add_test(tc, test_from_decimal_to_float_ok43);
  tcase_add_test(tc, test_from_decimal_to_float_ok44);
  tcase_add_test(tc, test_from_decimal_to_float_ok45);
  tcase_add_test(tc, test_from_decimal_to_float_ok46);
  tcase_add_test(tc, test_from_decimal_to_float_ok47);
  tcase_add_test(tc, test_from_decimal_to_float_ok48);
  tcase_add_test(tc, test_from_decimal_to_float_ok49);
  tcase_add_test(tc, test_from_decimal_to_float_ok50);
  tcase_add_test(tc, test_from_decimal_to_float_ok51);
  tcase_add_test(tc, test_from_decimal_to_float_ok52);
  tcase_add_test(tc, test_from_decimal_to_float_ok53);
  tcase_add_test(tc, test_from_decimal_to_float_ok54);
  tcase_add_test(tc, test_from_decimal_to_float_ok55);
  tcase_add_test(tc, test_from_decimal_to_float_ok56);
  tcase_add_test(tc, test_from_decimal_to_float_ok57);
  tcase_add_test(tc, test_from_decimal_to_float_ok58);
  tcase_add_test(tc, test_from_decimal_to_float_ok59);
  tcase_add_test(tc, test_from_decimal_to_float_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_from_decimal_to_float(s21_decimal decimal, int check) {
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  float_cast_test cast_result;
  cast_result.f = result;

  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}