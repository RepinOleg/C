#include "help.h"
#include "test.h"

// TODO: Тесты на некорректные данные

START_TEST(test_negate_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_negate(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_negate_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

// TODO: Tests for correct data //

START_TEST(test_negate_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // -792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // 792281625142643375935439503.35
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // -79228162514264337593543950.335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // 79228162514264337593543950.335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // -7922816251426433759354395.0335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // 7922816251426433759354395.0335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // -792281625142643375935439.50335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // 792281625142643375935439.50335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // -79228162514264337593543.950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // 79228162514264337593543.950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // -7922816251426433759354.3950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // 7922816251426433759354.3950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // -792281625142643375935.43950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // 792281625142643375935.43950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // -79228162514264337593.543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // 79228162514264337593.543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok21) {
  // 1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  // -1.000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok22) {
  // -1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  // 1.000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok23) {
  // 1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -1.0000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok24) {
  // -1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 1.0000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok25) {
  // 1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  // -1.1
  s21_decimal decimal_check = {{0xB, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok26) {
  // -1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  // 1.1
  s21_decimal decimal_check = {{0xB, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok27) {
  // 12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  // -12.12
  s21_decimal decimal_check = {{0x4BC, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok28) {
  // -12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  // 12.12
  s21_decimal decimal_check = {{0x4BC, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok29) {
  // 123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  // -123.123
  s21_decimal decimal_check = {{0x1E0F3, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok30) {
  // -123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  // 123.123
  s21_decimal decimal_check = {{0x1E0F3, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok31) {
  // 1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  // -1234.1234
  s21_decimal decimal_check = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok32) {
  // -1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  // 1234.1234
  s21_decimal decimal_check = {{0xBC4FF2, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok33) {
  // 12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  // -12345.12345
  s21_decimal decimal_check = {{0x499529D9, 0x0, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok34) {
  // -12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  // 12345.12345
  s21_decimal decimal_check = {{0x499529D9, 0x0, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok35) {
  // 123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  // -123456.123456
  s21_decimal decimal_check = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok36) {
  // -123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  // 123456.123456
  s21_decimal decimal_check = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok37) {
  // 1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  // -1234567.1234567
  s21_decimal decimal_check = {{0x73593407, 0xB3A, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok38) {
  // -1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  // 1234567.1234567
  s21_decimal decimal_check = {{0x73593407, 0xB3A, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok39) {
  // 1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  // -1234567890.1234567890
  s21_decimal decimal_check = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok40) {
  // -1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  // 1234567890.1234567890
  s21_decimal decimal_check = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok41) {
  // 5694011593981989243301.7721765
  s21_decimal decimal = {{0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x70000}};
  // -5694011593981989243301.7721765
  s21_decimal decimal_check = {
      {0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok42) {
  // 7391817384113353885252676556.8
  s21_decimal decimal = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x10000}};
  // -7391817384113353885252676556.8
  s21_decimal decimal_check = {
      {0xD4363600, 0x3C647D46, 0xEED7AE29, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok43) {
  // -7391817384113353885252676556.8
  s21_decimal decimal = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x80010000}};
  // 7391817384113353885252676556.8
  s21_decimal decimal_check = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok44) {
  // 67381264773976866357.851509099
  s21_decimal decimal = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x90000}};
  // -67381264773976866357.851509099
  s21_decimal decimal_check = {
      {0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok45) {
  // -67381264773976866357.851509099
  s21_decimal decimal = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x80090000}};
  // 67381264773976866357.851509099
  s21_decimal decimal_check = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok46) {
  // 3880207503319540203.1112505076
  s21_decimal decimal = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0xA0000}};
  // -3880207503319540203.1112505076
  s21_decimal decimal_check = {
      {0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok47) {
  // -3880207503319540203.1112505076
  s21_decimal decimal = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0x800A0000}};
  // 3880207503319540203.1112505076
  s21_decimal decimal_check = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok48) {
  // -52231370183613270.792051465171
  s21_decimal decimal = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0x800C0000}};
  // 52231370183613270.792051465171
  s21_decimal decimal_check = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok49) {
  // 52231370183613270.792051465171
  s21_decimal decimal = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0xC0000}};
  // -52231370183613270.792051465171
  s21_decimal decimal_check = {
      {0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok50) {
  // 762012.47518574196197311629136
  s21_decimal decimal = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x170000}};
  // -762012.47518574196197311629136
  s21_decimal decimal_check = {
      {0xFDDBC750, 0x4985467C, 0xF63831D1, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok51) {
  // -762012.47518574196197311629136
  s21_decimal decimal = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x80170000}};
  // 762012.47518574196197311629136
  s21_decimal decimal_check = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok52) {
  // 528160336985692.03305796312337
  s21_decimal decimal = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0xE0000}};
  // -528160336985692.03305796312337
  s21_decimal decimal_check = {
      {0x783F9D11, 0xE71F058C, 0xAAA8662B, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok53) {
  // -528160336985692.03305796312337
  s21_decimal decimal = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0x800E0000}};
  // 528160336985692.03305796312337
  s21_decimal decimal_check = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok54) {
  // 53331962353.888666415154074761
  s21_decimal decimal = {{0x8381489, 0x599DA089, 0xAC532A50, 0x120000}};
  // -53331962353.888666415154074761
  s21_decimal decimal_check = {{0x8381489, 0x599DA089, 0xAC532A50, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok55) {
  // -53331962353.888666415154074761
  s21_decimal decimal = {{0x8381489, 0x599DA089, 0xAC532A50, 0x80120000}};
  // 53331962353.888666415154074761
  s21_decimal decimal_check = {{0x8381489, 0x599DA089, 0xAC532A50, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok56) {
  // 21469522554935341566486.374228
  s21_decimal decimal = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x60000}};
  // -21469522554935341566486.374228
  s21_decimal decimal_check = {
      {0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok57) {
  // -21469522554935341566486.374228
  s21_decimal decimal = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x80060000}};
  // 21469522554935341566486.374228
  s21_decimal decimal_check = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok58) {
  // -48282841899130.570326498609779
  s21_decimal decimal = {{0x32F40A73, 0xA632221, 0x9C02A178, 0x800F0000}};
  // 48282841899130.570326498609779
  s21_decimal decimal_check = {{0x32F40A73, 0xA632221, 0x9C02A178, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok59) {
  // 48282841899130.570326498609779
  s21_decimal decimal = {{0x32F40A73, 0xA632221, 0x9C02A178, 0xF0000}};
  // -48282841899130.570326498609779
  s21_decimal decimal_check = {{0x32F40A73, 0xA632221, 0x9C02A178, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok60) {
  // -743355137752.71190832768620564
  s21_decimal decimal = {{0xC2E01814, 0x66150693, 0xF030E554, 0x80110000}};
  // 743355137752.71190832768620564
  s21_decimal decimal_check = {{0xC2E01814, 0x66150693, 0xF030E554, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok61) {
  // 743355137752.71190832768620564
  s21_decimal decimal = {{0xC2E01814, 0x66150693, 0xF030E554, 0x110000}};
  // -743355137752.71190832768620564
  s21_decimal decimal_check = {
      {0xC2E01814, 0x66150693, 0xF030E554, 0x80110000}};

  test_negate(decimal, decimal_check);
}

Suite *s21_test_negate(void) {
  Suite *s = suite_create("\033[43m-=s21_negate=-\033[0m");
  TCase *tc = tcase_create("negate_rc");

  // TODO: Тесты на некорректные данные
  tcase_add_test(tc, test_negate_fail1);
  tcase_add_test(tc, test_negate_fail2);
  tcase_add_test(tc, test_negate_fail3);
  tcase_add_test(tc, test_negate_fail4);
  // tcase_add_test(tc, test_negate_fail5);
  // tcase_add_test(tc, test_negate_fail6);
  // tcase_add_test(tc, test_negate_fail7);
  // tcase_add_test(tc, test_negate_fail8);
  // tcase_add_test(tc, test_negate_fail9);

  // TODO: Tests for correct data //
  tcase_add_test(tc, test_negate_ok1);
  tcase_add_test(tc, test_negate_ok2);
  tcase_add_test(tc, test_negate_ok3);
  tcase_add_test(tc, test_negate_ok4);
  tcase_add_test(tc, test_negate_ok5);
  tcase_add_test(tc, test_negate_ok6);
  tcase_add_test(tc, test_negate_ok7);
  tcase_add_test(tc, test_negate_ok8);
  tcase_add_test(tc, test_negate_ok9);
  tcase_add_test(tc, test_negate_ok10);
  tcase_add_test(tc, test_negate_ok11);
  tcase_add_test(tc, test_negate_ok12);
  tcase_add_test(tc, test_negate_ok13);
  tcase_add_test(tc, test_negate_ok14);
  tcase_add_test(tc, test_negate_ok15);
  tcase_add_test(tc, test_negate_ok16);
  tcase_add_test(tc, test_negate_ok17);
  tcase_add_test(tc, test_negate_ok18);
  tcase_add_test(tc, test_negate_ok19);
  tcase_add_test(tc, test_negate_ok20);
  tcase_add_test(tc, test_negate_ok21);
  tcase_add_test(tc, test_negate_ok22);
  tcase_add_test(tc, test_negate_ok23);
  tcase_add_test(tc, test_negate_ok24);
  tcase_add_test(tc, test_negate_ok25);
  tcase_add_test(tc, test_negate_ok26);
  tcase_add_test(tc, test_negate_ok27);
  tcase_add_test(tc, test_negate_ok28);
  tcase_add_test(tc, test_negate_ok29);
  tcase_add_test(tc, test_negate_ok30);
  tcase_add_test(tc, test_negate_ok31);
  tcase_add_test(tc, test_negate_ok32);
  tcase_add_test(tc, test_negate_ok33);
  tcase_add_test(tc, test_negate_ok34);
  tcase_add_test(tc, test_negate_ok35);
  tcase_add_test(tc, test_negate_ok36);
  tcase_add_test(tc, test_negate_ok37);
  tcase_add_test(tc, test_negate_ok38);
  tcase_add_test(tc, test_negate_ok39);
  tcase_add_test(tc, test_negate_ok40);
  tcase_add_test(tc, test_negate_ok41);
  tcase_add_test(tc, test_negate_ok42);
  tcase_add_test(tc, test_negate_ok43);
  tcase_add_test(tc, test_negate_ok44);
  tcase_add_test(tc, test_negate_ok45);
  tcase_add_test(tc, test_negate_ok46);
  tcase_add_test(tc, test_negate_ok47);
  tcase_add_test(tc, test_negate_ok48);
  tcase_add_test(tc, test_negate_ok49);
  tcase_add_test(tc, test_negate_ok50);
  tcase_add_test(tc, test_negate_ok51);
  tcase_add_test(tc, test_negate_ok52);
  tcase_add_test(tc, test_negate_ok53);
  tcase_add_test(tc, test_negate_ok54);
  tcase_add_test(tc, test_negate_ok55);
  tcase_add_test(tc, test_negate_ok56);
  tcase_add_test(tc, test_negate_ok57);
  tcase_add_test(tc, test_negate_ok58);
  tcase_add_test(tc, test_negate_ok59);
  tcase_add_test(tc, test_negate_ok60);
  tcase_add_test(tc, test_negate_ok61);

  suite_add_tcase(s, tc);
  return s;
}

void test_negate(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_negate(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);
  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}