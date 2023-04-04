#include "help.h"
#include "test.h"

// TODO: Тесты на некорректные данные

START_TEST(test_truncate_fail1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_truncate(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_truncate_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

// TODO: Tests for correct data //

START_TEST(test_truncate_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok21) {
  // 1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok22) {
  // -1.000000000000000000000000000
  s21_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok23) {
  // 1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok24) {
  // -1.0000000000000000000000000000
  s21_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok25) {
  // 1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok26) {
  // -1.1
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok27) {
  // 12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  // 12
  s21_decimal decimal_check = {{0xC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok28) {
  // -12.12
  s21_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  // -12
  s21_decimal decimal_check = {{0xC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok29) {
  // 123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  // 123
  s21_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok30) {
  // -123.123
  s21_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  // -123
  s21_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok31) {
  // 1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  // 1234
  s21_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok32) {
  // -1234.1234
  s21_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  // -1234
  s21_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok33) {
  // 12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  // 12345
  s21_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok34) {
  // -12345.12345
  s21_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  // -12345
  s21_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok35) {
  // 123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  // 123456
  s21_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok36) {
  // -123456.123456
  s21_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  // -123456
  s21_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok37) {
  // 1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  // 1234567
  s21_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok38) {
  // -1234567.1234567
  s21_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  // -1234567
  s21_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok39) {
  // 1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  // 1234567890
  s21_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok40) {
  // -1234567890.1234567890
  s21_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  // -1234567890
  s21_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok41) {
  // -2743733667457.649596996030498
  s21_decimal decimal = {{0xE5389022, 0x262241AD, 0x8DD9034, 0x800F0000}};
  // -2743733667457
  s21_decimal decimal_check = {{0xD3454681, 0x27E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok42) {
  // 2743733667457.649596996030498
  s21_decimal decimal = {{0xE5389022, 0x262241AD, 0x8DD9034, 0xF0000}};
  // 2743733667457
  s21_decimal decimal_check = {{0xD3454681, 0x27E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok43) {
  // 7033970046697049902273.0934353
  s21_decimal decimal = {{0x3545B851, 0xE9D8131F, 0xE347A2F2, 0x70000}};
  // 7033970046697049902273
  s21_decimal decimal_check = {{0x83774CC1, 0x4FF199E6, 0x17D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok44) {
  // -7033970046697049902273.0934353
  s21_decimal decimal = {{0x3545B851, 0xE9D8131F, 0xE347A2F2, 0x80070000}};
  // -7033970046697049902273
  s21_decimal decimal_check = {{0x83774CC1, 0x4FF199E6, 0x17D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok45) {
  // 49326179389907.080515603920193
  s21_decimal decimal = {{0xBE13F541, 0xBF523B87, 0x9F61A8C6, 0xF0000}};
  // 49326179389907
  s21_decimal decimal_check = {{0xA56691D3, 0x2CDC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok46) {
  // -49326179389907.080515603920193
  s21_decimal decimal = {{0xBE13F541, 0xBF523B87, 0x9F61A8C6, 0x800F0000}};
  // -49326179389907
  s21_decimal decimal_check = {{0xA56691D3, 0x2CDC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok47) {
  // -15588824774156734894220.621836
  s21_decimal decimal = {{0x5D45B80C, 0x54F2C2FE, 0x325EC60C, 0x80060000}};
  // -15588824774156734894220
  s21_decimal decimal_check = {{0x4D2B108C, 0x126702F6, 0x34D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok48) {
  // 15588824774156734894220.621836
  s21_decimal decimal = {{0x5D45B80C, 0x54F2C2FE, 0x325EC60C, 0x60000}};
  // 15588824774156734894220
  s21_decimal decimal_check = {{0x4D2B108C, 0x126702F6, 0x34D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok49) {
  // 326102205602944283462484921.49
  s21_decimal decimal = {{0x7C327475, 0xD5CB59E5, 0x695E8ACE, 0x20000}};
  // 326102205602944283462484921
  s21_decimal decimal_check = {{0x5FF643B9, 0xFD0497F0, 0x10DBED3, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok50) {
  // -326102205602944283462484921.49
  s21_decimal decimal = {{0x7C327475, 0xD5CB59E5, 0x695E8ACE, 0x80020000}};
  // -326102205602944283462484921
  s21_decimal decimal_check = {{0x5FF643B9, 0xFD0497F0, 0x10DBED3, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok51) {
  // -78829919.639878877119137613007
  s21_decimal decimal = {{0x676684CF, 0x854DF1E7, 0xFEB694CA, 0x80150000}};
  // -78829919
  s21_decimal decimal_check = {{0x4B2D95F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok52) {
  // 78829919.639878877119137613007
  s21_decimal decimal = {{0x676684CF, 0x854DF1E7, 0xFEB694CA, 0x150000}};
  // 78829919
  s21_decimal decimal_check = {{0x4B2D95F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok53) {
  // -6436090.8162131382309171482727
  s21_decimal decimal = {{0x90B7D067, 0xA04AF869, 0xCFF6186E, 0x80160000}};
  // -6436090
  s21_decimal decimal_check = {{0x6234FA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok54) {
  // 6436090.8162131382309171482727
  s21_decimal decimal = {{0x90B7D067, 0xA04AF869, 0xCFF6186E, 0x160000}};
  // 6436090
  s21_decimal decimal_check = {{0x6234FA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok55) {
  // -17024844397833208357931845.4
  s21_decimal decimal = {{0xF928F0B6, 0xA4245237, 0x8CD382, 0x80010000}};
  // -17024844397833208357931845
  s21_decimal decimal_check = {{0x65B74B45, 0xAA03A1D2, 0xE1526, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok56) {
  // 17024844397833208357931845.4
  s21_decimal decimal = {{0xF928F0B6, 0xA4245237, 0x8CD382, 0x10000}};
  // 17024844397833208357931845
  s21_decimal decimal_check = {{0x65B74B45, 0xAA03A1D2, 0xE1526, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok57) {
  // -3306.6596212280347416372581915
  s21_decimal decimal = {{0xBBE6161B, 0x80B5390B, 0x6AD80C1C, 0x80190000}};
  // -3306
  s21_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok58) {
  // 3306.6596212280347416372581915
  s21_decimal decimal = {{0xBBE6161B, 0x80B5390B, 0x6AD80C1C, 0x190000}};
  // 3306
  s21_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok59) {
  // 5574480338.8062228364817330784
  s21_decimal decimal = {{0xFF53F260, 0xE7DD3002, 0xB41F0546, 0x130000}};
  // 5574480338
  s21_decimal decimal_check = {{0x4C43D1D2, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok60) {
  // -5574480338.8062228364817330784
  s21_decimal decimal = {{0xFF53F260, 0xE7DD3002, 0xB41F0546, 0x80130000}};
  // -5574480338
  s21_decimal decimal_check = {{0x4C43D1D2, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

Suite *s21_test_truncate(void) {
  Suite *s = suite_create("\033[43m-=s21_truncate=-\033[0m");
  TCase *tc = tcase_create("truncate_rc");

  // TODO: Тесты на некорректные данные
  tcase_add_test(tc, test_truncate_fail1);
  tcase_add_test(tc, test_truncate_fail2);
  tcase_add_test(tc, test_truncate_fail3);
  tcase_add_test(tc, test_truncate_fail4);
  // tcase_add_test(tc, test_truncate_fail5);
  // tcase_add_test(tc, test_truncate_fail6);
  // tcase_add_test(tc, test_truncate_fail7);
  // tcase_add_test(tc, test_truncate_fail8);
  // tcase_add_test(tc, test_truncate_fail9);

  // TODO: Tests for correct data //
  tcase_add_test(tc, test_truncate_ok1);
  tcase_add_test(tc, test_truncate_ok2);
  tcase_add_test(tc, test_truncate_ok3);
  tcase_add_test(tc, test_truncate_ok4);
  tcase_add_test(tc, test_truncate_ok5);
  tcase_add_test(tc, test_truncate_ok6);
  tcase_add_test(tc, test_truncate_ok7);
  tcase_add_test(tc, test_truncate_ok8);
  tcase_add_test(tc, test_truncate_ok9);
  tcase_add_test(tc, test_truncate_ok10);
  tcase_add_test(tc, test_truncate_ok11);
  tcase_add_test(tc, test_truncate_ok12);
  tcase_add_test(tc, test_truncate_ok13);
  tcase_add_test(tc, test_truncate_ok14);
  tcase_add_test(tc, test_truncate_ok15);
  tcase_add_test(tc, test_truncate_ok16);
  tcase_add_test(tc, test_truncate_ok17);
  tcase_add_test(tc, test_truncate_ok18);
  tcase_add_test(tc, test_truncate_ok19);
  tcase_add_test(tc, test_truncate_ok20);
  tcase_add_test(tc, test_truncate_ok21);
  tcase_add_test(tc, test_truncate_ok22);
  tcase_add_test(tc, test_truncate_ok23);
  tcase_add_test(tc, test_truncate_ok24);
  tcase_add_test(tc, test_truncate_ok25);
  tcase_add_test(tc, test_truncate_ok26);
  tcase_add_test(tc, test_truncate_ok27);
  tcase_add_test(tc, test_truncate_ok28);
  tcase_add_test(tc, test_truncate_ok29);
  tcase_add_test(tc, test_truncate_ok30);
  tcase_add_test(tc, test_truncate_ok31);
  tcase_add_test(tc, test_truncate_ok32);
  tcase_add_test(tc, test_truncate_ok33);
  tcase_add_test(tc, test_truncate_ok34);
  tcase_add_test(tc, test_truncate_ok35);
  tcase_add_test(tc, test_truncate_ok36);
  tcase_add_test(tc, test_truncate_ok37);
  tcase_add_test(tc, test_truncate_ok38);
  tcase_add_test(tc, test_truncate_ok39);
  tcase_add_test(tc, test_truncate_ok40);
  tcase_add_test(tc, test_truncate_ok41);
  tcase_add_test(tc, test_truncate_ok42);
  tcase_add_test(tc, test_truncate_ok43);
  tcase_add_test(tc, test_truncate_ok44);
  tcase_add_test(tc, test_truncate_ok45);
  tcase_add_test(tc, test_truncate_ok46);
  tcase_add_test(tc, test_truncate_ok47);
  tcase_add_test(tc, test_truncate_ok48);
  tcase_add_test(tc, test_truncate_ok49);
  tcase_add_test(tc, test_truncate_ok50);
  tcase_add_test(tc, test_truncate_ok51);
  tcase_add_test(tc, test_truncate_ok52);
  tcase_add_test(tc, test_truncate_ok53);
  tcase_add_test(tc, test_truncate_ok54);
  tcase_add_test(tc, test_truncate_ok55);
  tcase_add_test(tc, test_truncate_ok56);
  tcase_add_test(tc, test_truncate_ok57);
  tcase_add_test(tc, test_truncate_ok58);
  tcase_add_test(tc, test_truncate_ok59);
  tcase_add_test(tc, test_truncate_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_truncate(s21_decimal decimal, s21_decimal decimal_check) {
  s21_decimal result;

  int code = s21_truncate(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);
  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}