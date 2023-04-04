#include "test.h"

// TODO: Тесты на некорректные данные //
START_TEST(test_from_decimal_to_int_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_int_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

// TODO: Tests for correct data

START_TEST(test_from_decimal_to_int_ok1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok2) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok3) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok4) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok5) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok6) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok7) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok8) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok9) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok10) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok11) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok12) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok13) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok14) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok15) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok16) {
  // -429496729.7
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok17) {
  // 42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok18) {
  // -42949672.97
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok19) {
  // 429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  int check = 429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok20) {
  // -429496.7297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  int check = -429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok21) {
  // 4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok22) {
  // -4.294967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok23) {
  // 42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok24) {
  // -42.94967297
  s21_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok25) {
  // 429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok26) {
  // -429496729.6
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok27) {
  // 42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok28) {
  // -42949672.96
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok29) {
  // 4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  int check = 4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok30) {
  // -4294967.296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  int check = -4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok31) {
  // 669134488
  s21_decimal decimal = {{0x27E22E98, 0x0, 0x0, 0x0}};
  int check = 669134488;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok32) {
  // 1135755779
  s21_decimal decimal = {{0x43B24203, 0x0, 0x0, 0x0}};
  int check = 1135755779;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok33) {
  // -1135755779
  s21_decimal decimal = {{0x43B24203, 0x0, 0x0, 0x80000000}};
  int check = -1135755779;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok34) {
  // -1066687460
  s21_decimal decimal = {{0x3F945BE4, 0x0, 0x0, 0x80000000}};
  int check = -1066687460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok35) {
  // 1066687460
  s21_decimal decimal = {{0x3F945BE4, 0x0, 0x0, 0x0}};
  int check = 1066687460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok36) {
  // 1775.200759
  s21_decimal decimal = {{0x69CF69F7, 0x0, 0x0, 0x60000}};
  int check = 1775;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok37) {
  // -1775.200759
  s21_decimal decimal = {{0x69CF69F7, 0x0, 0x0, 0x80060000}};
  int check = -1775;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok38) {
  // 2049377039
  s21_decimal decimal = {{0x7A27030F, 0x0, 0x0, 0x0}};
  int check = 2049377039;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok39) {
  // -2049377039
  s21_decimal decimal = {{0x7A27030F, 0x0, 0x0, 0x80000000}};
  int check = -2049377039;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok40) {
  // 644156872
  s21_decimal decimal = {{0x26650DC8, 0x0, 0x0, 0x0}};
  int check = 644156872;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok41) {
  // -644156872
  s21_decimal decimal = {{0x26650DC8, 0x0, 0x0, 0x80000000}};
  int check = -644156872;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok42) {
  // 411899256
  s21_decimal decimal = {{0x188D1578, 0x0, 0x0, 0x0}};
  int check = 411899256;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok43) {
  // -411899256
  s21_decimal decimal = {{0x188D1578, 0x0, 0x0, 0x80000000}};
  int check = -411899256;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok44) {
  // -0.0000000000000000321044217
  s21_decimal decimal = {{0x1322BEF9, 0x0, 0x0, 0x80190000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok45) {
  // 0.0000000000000000321044217
  s21_decimal decimal = {{0x1322BEF9, 0x0, 0x0, 0x190000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

// TODO: Tests for incorrect data

START_TEST(test_from_decimal_to_int_fail1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail16) {
  // -26409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail17) {
  // 2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail18) {
  // -2640938749860586450804312200.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail19) {
  // 26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail20) {
  // -26409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail21) {
  // 2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail22) {
  // -2640938749860586450661146624.0
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail23) {
  // 6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail24) {
  // -6148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail25) {
  // 614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail26) {
  // -614891469123651720.5
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail27) {
  // 6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail28) {
  // -6148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail29) {
  // 614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail30) {
  // -614891468980486144.0
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail31) {
  // -12345678901234.12345678901234
  s21_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail32) {
  // 9999999999.9999999999
  s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail33) {
  // -9999999999.9999999999
  s21_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail34) {
  // 2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail35) {
  // 2147483648.00
  s21_decimal decimal = {{0x0, 0x32, 0x0, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail36) {
  // 2147483648.99
  s21_decimal decimal = {{0x63, 0x32, 0x0, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail37) {
  // 2147483648.999999999999999999
  s21_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail38) {
  // 3436350754
  s21_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail39) {
  // -3436350754
  s21_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail40) {
  // -2467171175
  s21_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail41) {
  // 2467171175
  s21_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail42) {
  // -2296067528
  s21_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail43) {
  // 2296067528
  s21_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail44) {
  // 3848964437
  s21_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail45) {
  // -3848964437
  s21_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

END_TEST

Suite *s21_test_from_decimal_to_int(void) {
  Suite *s = suite_create("\033[43m-=s21_from_decimal_to_int=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_int_rc");

  // TODO: Тесты на некорректные данные //
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual1);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual2);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual3);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual4);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual5);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual6);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual7);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual8);
  // tcase_add_test(tc, test_from_decimal_to_int_fail_manual9);

  // TODO: Tests for correct data

  tcase_add_test(tc, test_from_decimal_to_int_ok1);
  tcase_add_test(tc, test_from_decimal_to_int_ok2);
  tcase_add_test(tc, test_from_decimal_to_int_ok3);
  tcase_add_test(tc, test_from_decimal_to_int_ok4);
  tcase_add_test(tc, test_from_decimal_to_int_ok5);
  tcase_add_test(tc, test_from_decimal_to_int_ok6);
  tcase_add_test(tc, test_from_decimal_to_int_ok7);
  tcase_add_test(tc, test_from_decimal_to_int_ok8);
  tcase_add_test(tc, test_from_decimal_to_int_ok9);
  tcase_add_test(tc, test_from_decimal_to_int_ok10);
  tcase_add_test(tc, test_from_decimal_to_int_ok11);
  tcase_add_test(tc, test_from_decimal_to_int_ok12);
  tcase_add_test(tc, test_from_decimal_to_int_ok13);
  tcase_add_test(tc, test_from_decimal_to_int_ok14);
  tcase_add_test(tc, test_from_decimal_to_int_ok15);
  tcase_add_test(tc, test_from_decimal_to_int_ok16);
  tcase_add_test(tc, test_from_decimal_to_int_ok17);
  tcase_add_test(tc, test_from_decimal_to_int_ok18);
  tcase_add_test(tc, test_from_decimal_to_int_ok19);
  tcase_add_test(tc, test_from_decimal_to_int_ok20);
  tcase_add_test(tc, test_from_decimal_to_int_ok21);
  tcase_add_test(tc, test_from_decimal_to_int_ok22);
  tcase_add_test(tc, test_from_decimal_to_int_ok23);
  tcase_add_test(tc, test_from_decimal_to_int_ok24);
  tcase_add_test(tc, test_from_decimal_to_int_ok25);
  tcase_add_test(tc, test_from_decimal_to_int_ok26);
  tcase_add_test(tc, test_from_decimal_to_int_ok27);
  tcase_add_test(tc, test_from_decimal_to_int_ok28);
  tcase_add_test(tc, test_from_decimal_to_int_ok29);
  tcase_add_test(tc, test_from_decimal_to_int_ok30);
  tcase_add_test(tc, test_from_decimal_to_int_ok31);
  tcase_add_test(tc, test_from_decimal_to_int_ok32);
  tcase_add_test(tc, test_from_decimal_to_int_ok33);
  tcase_add_test(tc, test_from_decimal_to_int_ok34);
  tcase_add_test(tc, test_from_decimal_to_int_ok35);
  tcase_add_test(tc, test_from_decimal_to_int_ok36);
  tcase_add_test(tc, test_from_decimal_to_int_ok37);
  tcase_add_test(tc, test_from_decimal_to_int_ok38);
  tcase_add_test(tc, test_from_decimal_to_int_ok39);
  tcase_add_test(tc, test_from_decimal_to_int_ok40);
  tcase_add_test(tc, test_from_decimal_to_int_ok41);
  tcase_add_test(tc, test_from_decimal_to_int_ok42);
  tcase_add_test(tc, test_from_decimal_to_int_ok43);
  tcase_add_test(tc, test_from_decimal_to_int_ok44);
  tcase_add_test(tc, test_from_decimal_to_int_ok45);

  // TODO: Tests for incorrect data

  tcase_add_test(tc, test_from_decimal_to_int_fail1);
  tcase_add_test(tc, test_from_decimal_to_int_fail2);
  tcase_add_test(tc, test_from_decimal_to_int_fail3);
  tcase_add_test(tc, test_from_decimal_to_int_fail4);
  tcase_add_test(tc, test_from_decimal_to_int_fail5);
  tcase_add_test(tc, test_from_decimal_to_int_fail6);
  tcase_add_test(tc, test_from_decimal_to_int_fail7);
  tcase_add_test(tc, test_from_decimal_to_int_fail8);
  tcase_add_test(tc, test_from_decimal_to_int_fail9);
  tcase_add_test(tc, test_from_decimal_to_int_fail10);
  tcase_add_test(tc, test_from_decimal_to_int_fail11);
  tcase_add_test(tc, test_from_decimal_to_int_fail12);
  tcase_add_test(tc, test_from_decimal_to_int_fail13);
  tcase_add_test(tc, test_from_decimal_to_int_fail14);
  tcase_add_test(tc, test_from_decimal_to_int_fail15);
  tcase_add_test(tc, test_from_decimal_to_int_fail16);
  tcase_add_test(tc, test_from_decimal_to_int_fail17);
  tcase_add_test(tc, test_from_decimal_to_int_fail18);
  tcase_add_test(tc, test_from_decimal_to_int_fail19);
  tcase_add_test(tc, test_from_decimal_to_int_fail20);
  tcase_add_test(tc, test_from_decimal_to_int_fail21);
  tcase_add_test(tc, test_from_decimal_to_int_fail22);
  tcase_add_test(tc, test_from_decimal_to_int_fail23);
  tcase_add_test(tc, test_from_decimal_to_int_fail24);
  tcase_add_test(tc, test_from_decimal_to_int_fail25);
  tcase_add_test(tc, test_from_decimal_to_int_fail26);
  tcase_add_test(tc, test_from_decimal_to_int_fail27);
  tcase_add_test(tc, test_from_decimal_to_int_fail28);
  tcase_add_test(tc, test_from_decimal_to_int_fail29);
  tcase_add_test(tc, test_from_decimal_to_int_fail30);
  tcase_add_test(tc, test_from_decimal_to_int_fail31);
  tcase_add_test(tc, test_from_decimal_to_int_fail32);
  tcase_add_test(tc, test_from_decimal_to_int_fail33);
  tcase_add_test(tc, test_from_decimal_to_int_fail34);
  tcase_add_test(tc, test_from_decimal_to_int_fail35);
  tcase_add_test(tc, test_from_decimal_to_int_fail36);
  tcase_add_test(tc, test_from_decimal_to_int_fail37);
  tcase_add_test(tc, test_from_decimal_to_int_fail38);
  tcase_add_test(tc, test_from_decimal_to_int_fail39);
  tcase_add_test(tc, test_from_decimal_to_int_fail40);
  tcase_add_test(tc, test_from_decimal_to_int_fail41);
  tcase_add_test(tc, test_from_decimal_to_int_fail42);
  tcase_add_test(tc, test_from_decimal_to_int_fail43);
  tcase_add_test(tc, test_from_decimal_to_int_fail44);
  tcase_add_test(tc, test_from_decimal_to_int_fail45);

  suite_add_tcase(s, tc);
  return s;
}

void test_from_decimal_to_int(s21_decimal decimal, int check) {
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}

void test_from_decimal_to_int_fail(s21_decimal decimal) {
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}