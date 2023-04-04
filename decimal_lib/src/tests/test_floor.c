#include "help.h"
#include "test.h"

// TODO: Тесты на некорректные данные //

START_TEST(test_floor_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_floor(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_floor_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

// TODO: Tests for correct data //

START_TEST(test_floor_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439504
  s21_decimal decimal_check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543951
  s21_decimal decimal_check = {{0x9DB22D0F, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354396
  s21_decimal decimal_check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759355
  s21_decimal decimal_check = {{0xF485787B, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375936
  s21_decimal decimal_check = {{0x1873BF40, 0xF31DC461, 0x2A, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok21) {
  // 363366602747412.48
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x20000}};
  // 363366602747412
  s21_decimal decimal_check = {{0xE147AE14, 0x14A7A, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok22) {
  // -363366602747412.48
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80020000}};
  // -363366602747413
  s21_decimal decimal_check = {{0xE147AE15, 0x14A7A, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok23) {
  // 363366602.74741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};
  // 363366602
  s21_decimal decimal_check = {{0x15A888CA, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok24) {
  // -363366602.74741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};
  // -363366603
  s21_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok25) {
  // 36.336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};
  // 36
  s21_decimal decimal_check = {{0x24, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok26) {
  // -36.336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};
  // -37
  s21_decimal decimal_check = {{0x25, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok27) {
  // 3.6336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok28) {
  // -3.6336660274741248
  s21_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok29) {
  // 8460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};
  // 8460288
  s21_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok30) {
  // -8460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};
  // -8460288
  s21_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok31) {
  // 846028.8
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};
  // 846028
  s21_decimal decimal_check = {{0xCE8CC, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok32) {
  // -846028.8
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};
  // -846029
  s21_decimal decimal_check = {{0xCE8CD, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok33) {
  // 84602.88
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};
  // 84602
  s21_decimal decimal_check = {{0x14A7A, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok34) {
  // -84602.88
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};
  // -84603
  s21_decimal decimal_check = {{0x14A7B, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok35) {
  // 8460.288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};
  // 8460
  s21_decimal decimal_check = {{0x210C, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok36) {
  // -8460.288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -8461
  s21_decimal decimal_check = {{0x210D, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok37) {
  // 84.60288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};
  // 84
  s21_decimal decimal_check = {{0x54, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok38) {
  // -84.60288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};
  // -85
  s21_decimal decimal_check = {{0x55, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok39) {
  // 8.460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};
  // 8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok40) {
  // -8.460288
  s21_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};
  // -9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok41) {
  // -4493.3014343213978931642865294
  s21_decimal decimal = {{0x7AB9968E, 0x5C9B68BF, 0x912FB7E4, 0x80190000}};
  // -4494
  s21_decimal decimal_check = {{0x118E, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok42) {
  // 4493.3014343213978931642865294
  s21_decimal decimal = {{0x7AB9968E, 0x5C9B68BF, 0x912FB7E4, 0x190000}};
  // 4493
  s21_decimal decimal_check = {{0x118D, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok43) {
  // 2804562322050080374522.2289274
  s21_decimal decimal = {{0xA678E77A, 0x380629B5, 0x5A9ECBB9, 0x70000}};
  // 2804562322050080374522
  s21_decimal decimal_check = {{0x4FB8FEFA, 0x91EECB2, 0x98, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok44) {
  // -2804562322050080374522.2289274
  s21_decimal decimal = {{0xA678E77A, 0x380629B5, 0x5A9ECBB9, 0x80070000}};
  // -2804562322050080374523
  s21_decimal decimal_check = {{0x4FB8FEFB, 0x91EECB2, 0x98, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok45) {
  // -1.3773595030477839624555241923
  s21_decimal decimal = {{0x51D0A1C3, 0xBFBD392C, 0x2C814032, 0x801C0000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok46) {
  // 1.3773595030477839624555241923
  s21_decimal decimal = {{0x51D0A1C3, 0xBFBD392C, 0x2C814032, 0x1C0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok47) {
  // -6232396428889964695550075603.2
  s21_decimal decimal = {{0xABE25C40, 0xFF27B5EC, 0xC9612CC9, 0x80010000}};
  // -6232396428889964695550075604
  s21_decimal decimal_check = {
      {0x7796A2D4, 0x6650C564, 0x14235147, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok48) {
  // 6232396428889964695550075603.2
  s21_decimal decimal = {{0xABE25C40, 0xFF27B5EC, 0xC9612CC9, 0x10000}};
  // 6232396428889964695550075603
  s21_decimal decimal_check = {{0x7796A2D3, 0x6650C564, 0x14235147, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok49) {
  // 4071456280178008417014.1793669
  s21_decimal decimal = {{0x3558FD85, 0x130A2734, 0x838E4C08, 0x70000}};
  // 4071456280178008417014
  s21_decimal decimal_check = {{0x6F7A62F6, 0xB6CE6B52, 0xDC, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok50) {
  // -4071456280178008417014.1793669
  s21_decimal decimal = {{0x3558FD85, 0x130A2734, 0x838E4C08, 0x80070000}};
  // -4071456280178008417015
  s21_decimal decimal_check = {{0x6F7A62F7, 0xB6CE6B52, 0xDC, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok51) {
  // 62384159987888825957036205.053
  s21_decimal decimal = {{0x3623FD, 0x60AB863D, 0xC992F7B9, 0x30000}};
  // 62384159987888825957036205
  s21_decimal decimal_check = {{0x19DB30AD, 0x16E17397, 0x339A5C, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok52) {
  // -62384159987888825957036205.053
  s21_decimal decimal = {{0x3623FD, 0x60AB863D, 0xC992F7B9, 0x80030000}};
  // -62384159987888825957036206
  s21_decimal decimal_check = {{0x19DB30AE, 0x16E17397, 0x339A5C, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok53) {
  // -59661132671347.335693102082115
  s21_decimal decimal = {{0xB3C5E843, 0xC2D3267D, 0xC0C68842, 0x800F0000}};
  // -59661132671348
  s21_decimal decimal_check = {{0xF09EA974, 0x3642, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok54) {
  // 59661132671347.335693102082115
  s21_decimal decimal = {{0xB3C5E843, 0xC2D3267D, 0xC0C68842, 0xF0000}};
  // 59661132671347
  s21_decimal decimal_check = {{0xF09EA973, 0x3642, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok55) {
  // -1756702243.9163772433428207747
  s21_decimal decimal = {{0x43B95883, 0xA1D47999, 0x38C319B2, 0x80130000}};
  // -1756702244
  s21_decimal decimal_check = {{0x68B52624, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok56) {
  // 1756702243.9163772433428207747
  s21_decimal decimal = {{0x43B95883, 0xA1D47999, 0x38C319B2, 0x130000}};
  // 1756702243
  s21_decimal decimal_check = {{0x68B52623, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok57) {
  // 499690.17307003220935658068156
  s21_decimal decimal = {{0xDC4A58BC, 0xF995020, 0xA1756700, 0x170000}};
  // 499690
  s21_decimal decimal_check = {{0x79FEA, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok58) {
  // -499690.17307003220935658068156
  s21_decimal decimal = {{0xDC4A58BC, 0xF995020, 0xA1756700, 0x80170000}};
  // -499691
  s21_decimal decimal_check = {{0x79FEB, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok59) {
  // 1724370152434521045164.8495949
  s21_decimal decimal = {{0x1F12C14D, 0xB826473C, 0x37B7A7D4, 0x70000}};
  // 1724370152434521045164
  s21_decimal decimal_check = {{0xD9CF78AC, 0x7A716D88, 0x5D, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok60) {
  // -1724370152434521045164.8495949
  s21_decimal decimal = {{0x1F12C14D, 0xB826473C, 0x37B7A7D4, 0x80070000}};
  // -1724370152434521045165
  s21_decimal decimal_check = {{0xD9CF78AD, 0x7A716D88, 0x5D, 0x80000000}};

  test_floor(decimal, decimal_check);
}

Suite *s21_test_floor(void) {
  Suite *s = suite_create("\033[43m-=s21_floor=-\033[0m");
  TCase *tc = tcase_create("floor_rc");

  // TODO: Тесты на некорректные данные //
  tcase_add_test(tc, test_floor_fail1);
  tcase_add_test(tc, test_floor_fail2);
  tcase_add_test(tc, test_floor_fail3);
  tcase_add_test(tc, test_floor_fail4);
  // tcase_add_test(tc, test_floor_fail5);
  // tcase_add_test(tc, test_floor_fail6);
  // tcase_add_test(tc, test_floor_fail7);
  // tcase_add_test(tc, test_floor_fail8);
  // tcase_add_test(tc, test_floor_fail9);

  // TODO: Tests for correct data //
  tcase_add_test(tc, test_floor_ok1);
  tcase_add_test(tc, test_floor_ok2);
  tcase_add_test(tc, test_floor_ok3);
  tcase_add_test(tc, test_floor_ok4);
  tcase_add_test(tc, test_floor_ok5);
  tcase_add_test(tc, test_floor_ok6);
  tcase_add_test(tc, test_floor_ok7);
  tcase_add_test(tc, test_floor_ok8);
  tcase_add_test(tc, test_floor_ok9);
  tcase_add_test(tc, test_floor_ok10);
  tcase_add_test(tc, test_floor_ok11);
  tcase_add_test(tc, test_floor_ok12);
  tcase_add_test(tc, test_floor_ok13);
  tcase_add_test(tc, test_floor_ok14);
  tcase_add_test(tc, test_floor_ok15);
  tcase_add_test(tc, test_floor_ok16);
  tcase_add_test(tc, test_floor_ok17);
  tcase_add_test(tc, test_floor_ok18);
  tcase_add_test(tc, test_floor_ok19);
  tcase_add_test(tc, test_floor_ok20);
  tcase_add_test(tc, test_floor_ok21);
  tcase_add_test(tc, test_floor_ok22);
  tcase_add_test(tc, test_floor_ok23);
  tcase_add_test(tc, test_floor_ok24);
  tcase_add_test(tc, test_floor_ok25);
  tcase_add_test(tc, test_floor_ok26);
  tcase_add_test(tc, test_floor_ok27);
  tcase_add_test(tc, test_floor_ok28);
  tcase_add_test(tc, test_floor_ok29);
  tcase_add_test(tc, test_floor_ok30);
  tcase_add_test(tc, test_floor_ok31);
  tcase_add_test(tc, test_floor_ok32);
  tcase_add_test(tc, test_floor_ok33);
  tcase_add_test(tc, test_floor_ok34);
  tcase_add_test(tc, test_floor_ok35);
  tcase_add_test(tc, test_floor_ok36);
  tcase_add_test(tc, test_floor_ok37);
  tcase_add_test(tc, test_floor_ok38);
  tcase_add_test(tc, test_floor_ok39);
  tcase_add_test(tc, test_floor_ok40);
  tcase_add_test(tc, test_floor_ok41);
  tcase_add_test(tc, test_floor_ok42);
  tcase_add_test(tc, test_floor_ok43);
  tcase_add_test(tc, test_floor_ok44);
  tcase_add_test(tc, test_floor_ok45);
  tcase_add_test(tc, test_floor_ok46);
  tcase_add_test(tc, test_floor_ok47);
  tcase_add_test(tc, test_floor_ok48);
  tcase_add_test(tc, test_floor_ok49);
  tcase_add_test(tc, test_floor_ok50);
  tcase_add_test(tc, test_floor_ok51);
  tcase_add_test(tc, test_floor_ok52);
  tcase_add_test(tc, test_floor_ok53);
  tcase_add_test(tc, test_floor_ok54);
  tcase_add_test(tc, test_floor_ok55);
  tcase_add_test(tc, test_floor_ok56);
  tcase_add_test(tc, test_floor_ok57);
  tcase_add_test(tc, test_floor_ok58);
  tcase_add_test(tc, test_floor_ok59);
  tcase_add_test(tc, test_floor_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_floor(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_floor(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
