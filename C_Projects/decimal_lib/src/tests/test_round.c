#include "help.h"
#include "test.h"

// TODO: Тесты на некорректные данные

START_TEST(test_round_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_round(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_round_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

// TODO: Tests for correct data //

START_TEST(test_round_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok21) {
  // 1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok22) {
  // -1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok23) {
  // 1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok24) {
  // -1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok25) {
  // 1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok26) {
  // -1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok27) {
  // 12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  // 12
  s21_decimal decimal_check = {{0xC, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok28) {
  // -12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  // -12
  s21_decimal decimal_check = {{0xC, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok29) {
  // 123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  // 123
  s21_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok30) {
  // -123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  // -123
  s21_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok31) {
  // 1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  // 1234
  s21_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok32) {
  // -1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  // -1234
  s21_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok33) {
  // 12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  // 12345
  s21_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok34) {
  // -12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  // -12345
  s21_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok35) {
  // 123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  // 123456
  s21_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok36) {
  // -123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  // -123456
  s21_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok37) {
  // 1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  // 1234567
  s21_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok38) {
  // -1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  // -1234567
  s21_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok39) {
  // 1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  // 1234567890
  s21_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok40) {
  // -1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  // -1234567890
  s21_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok41) {
  // 74446002516229950.887323960855
  s21_decimal decimal = {{0xCB8B0617, 0xC42A85F, 0xF08C4A3B, 0xC0000}};
  // 74446002516229951
  s21_decimal decimal_check = {{0xAEED7F3F, 0x1087C3E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok42) {
  // -74446002516229950.887323960855
  s21_decimal decimal = {{0xCB8B0617, 0xC42A85F, 0xF08C4A3B, 0x800C0000}};
  // -74446002516229951
  s21_decimal decimal_check = {{0xAEED7F3F, 0x1087C3E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok43) {
  // -35342.281338525024327103373094
  s21_decimal decimal = {{0x31175F26, 0x64218805, 0x7232732E, 0x80180000}};
  // -35342
  s21_decimal decimal_check = {{0x8A0E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok44) {
  // 35342.281338525024327103373094
  s21_decimal decimal = {{0x31175F26, 0x64218805, 0x7232732E, 0x180000}};
  // 35342
  s21_decimal decimal_check = {{0x8A0E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok45) {
  // 29370909468199680092.879349758
  s21_decimal decimal = {{0x7BA67FE, 0xAA34265B, 0x5EE70C00, 0x90000}};
  // 29370909468199680093
  s21_decimal decimal_check = {{0x2E32F85D, 0x979A6E8C, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok46) {
  // -29370909468199680092.879349758
  s21_decimal decimal = {{0x7BA67FE, 0xAA34265B, 0x5EE70C00, 0x80090000}};
  // -29370909468199680093
  s21_decimal decimal_check = {{0x2E32F85D, 0x979A6E8C, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok47) {
  // 6134140995336725236707297.5985
  s21_decimal decimal = {{0x90325C71, 0xBCFD090A, 0xC6346CD0, 0x40000}};
  // 6134140995336725236707298
  s21_decimal decimal_check = {{0x3C126FE2, 0x731DD2DE, 0x512F4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok48) {
  // -6134140995336725236707297.5985
  s21_decimal decimal = {{0x90325C71, 0xBCFD090A, 0xC6346CD0, 0x80040000}};
  // -6134140995336725236707298
  s21_decimal decimal_check = {{0x3C126FE2, 0x731DD2DE, 0x512F4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok49) {
  // -337370225458386592065151.19902
  s21_decimal decimal = {{0xC295D71E, 0xDE99E789, 0x6D029C68, 0x80050000}};
  // -337370225458386592065151
  s21_decimal decimal_check = {{0x439BE67F, 0xE066CE57, 0x4770, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok50) {
  // 337370225458386592065151.19902
  s21_decimal decimal = {{0xC295D71E, 0xDE99E789, 0x6D029C68, 0x50000}};
  // 337370225458386592065151
  s21_decimal decimal_check = {{0x439BE67F, 0xE066CE57, 0x4770, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok51) {
  // -257113.40545930398492900669794
  s21_decimal decimal = {{0xCC4B3962, 0xDEE0DDAF, 0x5313EC23, 0x80170000}};
  // -257113
  s21_decimal decimal_check = {{0x3EC59, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok52) {
  // 257113.40545930398492900669794
  s21_decimal decimal = {{0xCC4B3962, 0xDEE0DDAF, 0x5313EC23, 0x170000}};
  // 257113
  s21_decimal decimal_check = {{0x3EC59, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok53) {
  // -4268705040.405676364420026866
  s21_decimal decimal = {{0x754711F2, 0xECE5E435, 0xDCAFD73, 0x80120000}};
  // -4268705040
  s21_decimal decimal_check = {{0xFE6F4510, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok54) {
  // 4268705040.405676364420026866
  s21_decimal decimal = {{0x754711F2, 0xECE5E435, 0xDCAFD73, 0x120000}};
  // 4268705040
  s21_decimal decimal_check = {{0xFE6F4510, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok55) {
  // -17448074565941395.88921593961
  s21_decimal decimal = {{0xAD2B1069, 0xC01B1C6A, 0x5A34559, 0x800B0000}};
  // -17448074565941396
  s21_decimal decimal_check = {{0x6E847894, 0x3DFCEE, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok56) {
  // 17448074565941395.88921593961
  s21_decimal decimal = {{0xAD2B1069, 0xC01B1C6A, 0x5A34559, 0xB0000}};
  // 17448074565941396
  s21_decimal decimal_check = {{0x6E847894, 0x3DFCEE, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok57) {
  // 245168512493259.49270848450357
  s21_decimal decimal = {{0xA9DC2F35, 0x59E57351, 0x4F37DD31, 0xE0000}};
  // 245168512493259
  s21_decimal decimal_check = {{0xBE18E6CB, 0xDEFA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok58) {
  // -245168512493259.49270848450357
  s21_decimal decimal = {{0xA9DC2F35, 0x59E57351, 0x4F37DD31, 0x800E0000}};
  // -245168512493259
  s21_decimal decimal_check = {{0xBE18E6CB, 0xDEFA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok59) {
  // -7058230657713062993592993630.0
  s21_decimal decimal = {{0xE9C6C9AC, 0x7F868D8F, 0xE41050CA, 0x80010000}};
  // -7058230657713062993592993630
  s21_decimal decimal_check = {
      {0x30FA475E, 0xA65A415B, 0x16CE6E7A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok60) {
  // 7058230657713062993592993630.0
  s21_decimal decimal = {{0xE9C6C9AC, 0x7F868D8F, 0xE41050CA, 0x10000}};
  // 7058230657713062993592993630
  s21_decimal decimal_check = {{0x30FA475E, 0xA65A415B, 0x16CE6E7A, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST

Suite *s21_test_round(void) {
  Suite *s = suite_create("\033[43m-=s21_round=-\033[0m");
  TCase *tc = tcase_create("round_rc");

  // TODO: Тесты на некорректные данные
  tcase_add_test(tc, test_round_fail1);
  tcase_add_test(tc, test_round_fail2);
  tcase_add_test(tc, test_round_fail3);
  tcase_add_test(tc, test_round_fail4);
  // tcase_add_test(tc, test_round_fail5);
  // tcase_add_test(tc, test_round_fail6);
  // tcase_add_test(tc, test_round_fail7);
  // tcase_add_test(tc, test_round_fail8);
  // tcase_add_test(tc, test_round_fail9);

  // TODO: Tests for correct data //
  tcase_add_test(tc, test_round_ok1);
  tcase_add_test(tc, test_round_ok2);
  tcase_add_test(tc, test_round_ok3);
  tcase_add_test(tc, test_round_ok4);
  tcase_add_test(tc, test_round_ok5);
  tcase_add_test(tc, test_round_ok6);
  tcase_add_test(tc, test_round_ok7);
  tcase_add_test(tc, test_round_ok8);
  tcase_add_test(tc, test_round_ok9);
  tcase_add_test(tc, test_round_ok10);
  tcase_add_test(tc, test_round_ok11);
  tcase_add_test(tc, test_round_ok12);
  tcase_add_test(tc, test_round_ok13);
  tcase_add_test(tc, test_round_ok14);
  tcase_add_test(tc, test_round_ok15);
  tcase_add_test(tc, test_round_ok16);
  tcase_add_test(tc, test_round_ok17);
  tcase_add_test(tc, test_round_ok18);
  tcase_add_test(tc, test_round_ok19);
  tcase_add_test(tc, test_round_ok20);
  tcase_add_test(tc, test_round_ok21);
  tcase_add_test(tc, test_round_ok22);
  tcase_add_test(tc, test_round_ok23);
  tcase_add_test(tc, test_round_ok24);
  tcase_add_test(tc, test_round_ok25);
  tcase_add_test(tc, test_round_ok26);
  tcase_add_test(tc, test_round_ok27);
  tcase_add_test(tc, test_round_ok28);
  tcase_add_test(tc, test_round_ok29);
  tcase_add_test(tc, test_round_ok30);
  tcase_add_test(tc, test_round_ok31);
  tcase_add_test(tc, test_round_ok32);
  tcase_add_test(tc, test_round_ok33);
  tcase_add_test(tc, test_round_ok34);
  tcase_add_test(tc, test_round_ok35);
  tcase_add_test(tc, test_round_ok36);
  tcase_add_test(tc, test_round_ok37);
  tcase_add_test(tc, test_round_ok38);
  tcase_add_test(tc, test_round_ok39);
  tcase_add_test(tc, test_round_ok40);
  tcase_add_test(tc, test_round_ok41);
  tcase_add_test(tc, test_round_ok42);
  tcase_add_test(tc, test_round_ok43);
  tcase_add_test(tc, test_round_ok44);
  tcase_add_test(tc, test_round_ok45);
  tcase_add_test(tc, test_round_ok46);
  tcase_add_test(tc, test_round_ok47);
  tcase_add_test(tc, test_round_ok48);
  tcase_add_test(tc, test_round_ok49);
  tcase_add_test(tc, test_round_ok50);
  tcase_add_test(tc, test_round_ok51);
  tcase_add_test(tc, test_round_ok52);
  tcase_add_test(tc, test_round_ok53);
  tcase_add_test(tc, test_round_ok54);
  tcase_add_test(tc, test_round_ok55);
  tcase_add_test(tc, test_round_ok56);
  tcase_add_test(tc, test_round_ok57);
  tcase_add_test(tc, test_round_ok58);
  tcase_add_test(tc, test_round_ok59);
  tcase_add_test(tc, test_round_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_round(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;
  int code = s21_round(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);
  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}