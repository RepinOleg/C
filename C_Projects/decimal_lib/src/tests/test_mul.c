#include "test.h"

// TODO: Тесты на некорректные данные

START_TEST(test_mul_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_mul(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_mul_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

// TODO: Тесты на все типы данных

START_TEST(test_mul_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mul_fail_manual17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

// TODO: tcase 1

START_TEST(test_mul_manual1) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.8228162514264337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
  // 61.978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual2) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.8228162514264337593543950335
  s21_decimal decimal2 = {{0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000}};
  // -6.5190219687391279469416894926
  s21_decimal check = {{0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual3) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.00000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800E0000}};
  // 0.0000000000003500000000000012
  s21_decimal check = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual4) {
  // -7922816251426.4337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 78228162514264.337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xF0000}};
  // -619787357287241642624224547.27
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80020000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual5) {
  // -79228162514264.337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  // -61978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80000000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual6) {
  // 79228162514264.1
  s21_decimal decimal1 = {{0x70D42571, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal decimal2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872410706900970254.4
  s21_decimal check = {{0x7F6C2E90, 0x3FD777DD, 0xC8439BCC, 0x10000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual7) {
  // 79228162514265.1
  s21_decimal decimal1 = {{0x70D4257B, 0x2D093, 0x0, 0x10000}};
  // 78228162514264.5
  s21_decimal decimal2 = {{0x22618575, 0x2C77B, 0x0, 0x10000}};
  // 6197873572872488935063484519.0
  s21_decimal check = {{0xA1CDB406, 0x3FDA3F58, 0xC8439BCC, 0x10000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual8) {
  // 5.0
  s21_decimal decimal1 = {{0x32, 0x0, 0x0, 0x10000}};
  // 4.5
  s21_decimal decimal2 = {{0x2D, 0x0, 0x0, 0x10000}};
  // 22.50
  s21_decimal check = {{0x8CA, 0x0, 0x0, 0x20000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual9) {
  // 79228162.5
  s21_decimal decimal1 = {{0x2F394219, 0x0, 0x0, 0x10000}};
  // 78228162.5555555555555
  s21_decimal decimal2 = {{0xB20798E3, 0x6856A1BC, 0x2A, 0xD0000}};
  // 6197873575027970.8333289317688
  s21_decimal check = {{0x34C52538, 0x6AFC5902, 0xC8439BCD, 0xD0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual10) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -2.00000000000005
  s21_decimal decimal2 = {{0x20F48005, 0xB5E6, 0x0, 0x800E0000}};
  // 14.000000000000400000000000001
  s21_decimal check = {{0xF1E90001, 0xBD686F20, 0x2D3C8750, 0x1B0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual11) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.0000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800D0000}};
  // 0.0000000000035000000000000125
  s21_decimal check = {{0x8723807D, 0x7C5850, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual12) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800F0000}};
  // 0.0000000000000350000000000001
  s21_decimal check = {{0xB9ABE001, 0x13E52, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual13) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.00000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x50000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, check);
}

START_TEST(test_mul_manual14) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul_manual15) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul_manual16) {
  // -7922816251426433759354395032.7
  s21_decimal decimal1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul_manual17) {
  // -7922816251426433759354395032.7
  s21_decimal decimal1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul_manual18) {
  // -0.0000000000000025
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // too small
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail2(decimal1, decimal2, decimal_check, code_check);
}

START_TEST(test_mul_manual19) {
  // 792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // -782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x800E0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  // test_mul(decimal1, decimal2, decimal_check);
  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul_manual20) {
  // 792281625142643.37593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  // test_mul(decimal1, decimal2, decimal_check);
  test_mul_fail1(decimal1, decimal2, code_check);
}

// TODO: =============================================================

START_TEST(test_mul1) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul2) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul3) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul4) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul5) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul6) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul7) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul8) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -6148914689804861440
  s21_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul9) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul10) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul11) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul12) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul13) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul14) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387.498605864508043122005
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul15) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul16) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_mul_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_mul17) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 52818775009509558395695964249
  s21_decimal decimal_check = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul18) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -52818775009509558395695964249
  s21_decimal decimal_check = {
      {0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul19) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul20) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul21) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal_check = {
      {0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul22) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal_check = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul23) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -3.9999999999999999999999999992
  s21_decimal decimal_check = {
      {0x3FFFFFF8, 0xF8940984, 0x813F3978, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul24) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 3.9999999999999999999999999992
  s21_decimal decimal_check = {{0x3FFFFFF8, 0xF8940984, 0x813F3978, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul25) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal_check = {
      {0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul26) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal_check = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul27) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975160
  s21_decimal decimal_check = {
      {0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul28) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975160
  s21_decimal decimal_check = {{0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul29) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -3.9614081257132168796771975160
  s21_decimal decimal_check = {
      {0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul30) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 3.9614081257132168796771975160
  s21_decimal decimal_check = {{0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul31) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // -0.3961408125713216879677197516
  s21_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCCCCCCC, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul32) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // 0.3961408125713216879677197516
  s21_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCCCCCCC, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul33) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // -396140812571321.68796771975160
  s21_decimal decimal_check = {
      {0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0x800E0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul34) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // 396140812571321.68796771975160
  s21_decimal decimal_check = {{0xFFFFFFF8, 0xFFFFFFFF, 0x7FFFFFFF, 0xE0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul35) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // -0.0000000000000012500000000000
  s21_decimal decimal_check = {{0x620F4800, 0xB5E, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul36) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // 0.0000000000000012500000000000
  s21_decimal decimal_check = {{0x620F4800, 0xB5E, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul37) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // -0.0000000000000002500000000000
  s21_decimal decimal_check = {{0x139CA800, 0x246, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul38) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // 0.0000000000000002500000000000
  s21_decimal decimal_check = {{0x139CA800, 0x246, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul39) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul40) {
  // -0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul41) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 55901.969927234268947708082476
  s21_decimal decimal_check = {{0x2DC7792C, 0x10FB6E4E, 0xB4A10696, 0x180000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul42) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -55901.969927234268947708082476
  s21_decimal decimal_check = {
      {0x2DC7792C, 0x10FB6E4E, 0xB4A10696, 0x80180000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul43) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};
  // 5590.1969927234268947708082480
  s21_decimal decimal_check = {{0x2DC77930, 0x10FB6E4E, 0xB4A10696, 0x190000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul44) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};
  // -5590.1969927234268947708082480
  s21_decimal decimal_check = {
      {0x2DC77930, 0x10FB6E4E, 0xB4A10696, 0x80190000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul45) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 5590196992723426894.7708082476
  s21_decimal decimal_check = {{0x2DC7792C, 0x10FB6E4E, 0xB4A10696, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul46) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -5590196992723426894.7708082476
  s21_decimal decimal_check = {
      {0x2DC7792C, 0x10FB6E4E, 0xB4A10696, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul47) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x100000}};
  // 0.0000000000176395514401743219
  s21_decimal decimal_check = {{0x27E36173, 0x272AEC9, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul48) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000025
  s21_decimal decimal2 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -0.0000000000176395514401743219
  s21_decimal decimal_check = {{0x27E36173, 0x272AEC9, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul49) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x100000}};
  // 0.0000000000035279102880348644
  s21_decimal decimal_check = {{0x3B2D79E4, 0x7D5628, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul50) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // -0.0000000000035279102880348644
  s21_decimal decimal_check = {{0x3B2D79E4, 0x7D5628, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul51) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul52) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul53) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul54) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul55) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000007056
  s21_decimal decimal_check = {{0x1B90, 0x0, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul56) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000007056
  s21_decimal decimal_check = {{0x1B90, 0x0, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul57) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000070558
  s21_decimal decimal_check = {{0x1139E, 0x0, 0x0, 0x1C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul58) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000070558
  s21_decimal decimal_check = {{0x1139E, 0x0, 0x0, 0x801C0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul59) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // 400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0xE0000}};
  // 2825399045699384434.0452935949
  s21_decimal decimal_check = {{0x109AC90D, 0xBE2CD8E0, 0x5B4B2733, 0xA0000}};

  test_mul(decimal1, decimal2, decimal_check);
}

START_TEST(test_mul60) {
  // 7055.820576069728775806815669
  s21_decimal decimal1 = {{0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000}};
  // -400435217312910.10886274103770
  s21_decimal decimal2 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  // -2825399045699384434.0452935949
  s21_decimal decimal_check = {
      {0x109AC90D, 0xBE2CD8E0, 0x5B4B2733, 0x800A0000}};

  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

Suite *s21_test_mul(void) {
  Suite *s = suite_create("\033[43m-=s21_mul=-\033[0m");
  TCase *tc = tcase_create("mul_rc");

  // TODO: Тесты на некорректные данные
  tcase_add_test(tc, test_mul_fail_manual1);
  tcase_add_test(tc, test_mul_fail_manual2);
  tcase_add_test(tc, test_mul_fail_manual3);
  tcase_add_test(tc, test_mul_fail_manual4);
  tcase_add_test(tc, test_mul_fail_manual5);
  tcase_add_test(tc, test_mul_fail_manual6);
  tcase_add_test(tc, test_mul_fail_manual7);
  tcase_add_test(tc, test_mul_fail_manual8);
  tcase_add_test(tc, test_mul_fail_manual9);
  tcase_add_test(tc, test_mul_fail_manual10);
  tcase_add_test(tc, test_mul_fail_manual11);
  tcase_add_test(tc, test_mul_fail_manual12);
  tcase_add_test(tc, test_mul_fail_manual13);
  tcase_add_test(tc, test_mul_fail_manual14);
  tcase_add_test(tc, test_mul_fail_manual15);
  tcase_add_test(tc, test_mul_fail_manual16);
  tcase_add_test(tc, test_mul_fail_manual17);

  // TODO: Тесты на все типы данных

  //   tcase_add_test(tc, test_mul_manual1);
  //   tcase_add_test(tc, test_mul_manual2);
  //   tcase_add_test(tc, test_mul_manual3);
  //   tcase_add_test(tc, test_mul_manual4);
  //   tcase_add_test(tc, test_mul_manual5);
  //   tcase_add_test(tc, test_mul_manual6);
  //   tcase_add_test(tc, test_mul_manual7);
  //   tcase_add_test(tc, test_mul_manual8);
  //   tcase_add_test(tc, test_mul_manual9);
  //   tcase_add_test(tc, test_mul_manual10);
  //   tcase_add_test(tc, test_mul_manual11);
  //   tcase_add_test(tc, test_mul_manual12);
  //   tcase_add_test(tc, test_mul_manual13);
  //   tcase_add_test(tc, test_mul_manual14);
  //   tcase_add_test(tc, test_mul_manual15);
  //   tcase_add_test(tc, test_mul_manual16);
  //   tcase_add_test(tc, test_mul_manual17);
  //   tcase_add_test(tc, test_mul_manual18);
  tcase_add_test(tc, test_mul_manual19);
  tcase_add_test(tc, test_mul_manual20);

  // TODO: case

  tcase_add_test(tc, test_mul1);
  tcase_add_test(tc, test_mul2);
  tcase_add_test(tc, test_mul3);
  tcase_add_test(tc, test_mul4);
  tcase_add_test(tc, test_mul5);
  tcase_add_test(tc, test_mul6);
  tcase_add_test(tc, test_mul7);
  tcase_add_test(tc, test_mul8);
  tcase_add_test(tc, test_mul9);
  tcase_add_test(tc, test_mul10);
  tcase_add_test(tc, test_mul11);
  tcase_add_test(tc, test_mul12);
  tcase_add_test(tc, test_mul13);
  tcase_add_test(tc, test_mul14);
  tcase_add_test(tc, test_mul15);
  tcase_add_test(tc, test_mul16);
  //   tcase_add_test(tc, test_mul17);
  //   tcase_add_test(tc, test_mul18);
  tcase_add_test(tc, test_mul19);
  tcase_add_test(tc, test_mul20);
  //   tcase_add_test(tc, test_mul21);
  //   tcase_add_test(tc, test_mul22);
  tcase_add_test(tc, test_mul23);
  tcase_add_test(tc, test_mul24);
  //   tcase_add_test(tc, test_mul25);
  //   tcase_add_test(tc, test_mul26);
  //   tcase_add_test(tc, test_mul27);
  //   tcase_add_test(tc, test_mul28);
  //   tcase_add_test(tc, test_mul29);
  //   tcase_add_test(tc, test_mul30);
  //   tcase_add_test(tc, test_mul31);
  //   tcase_add_test(tc, test_mul32);
  //   tcase_add_test(tc, test_mul33);
  //   tcase_add_test(tc, test_mul34);
  //   tcase_add_test(tc, test_mul35);
  //   tcase_add_test(tc, test_mul36);
  //   tcase_add_test(tc, test_mul37);
  //   tcase_add_test(tc, test_mul38);
  tcase_add_test(tc, test_mul39);
  tcase_add_test(tc, test_mul40);
  //   tcase_add_test(tc, test_mul41);
  //   tcase_add_test(tc, test_mul42);
  //   tcase_add_test(tc, test_mul43);
  //   tcase_add_test(tc, test_mul44);
  //   tcase_add_test(tc, test_mul45);
  //   tcase_add_test(tc, test_mul46);
  //   tcase_add_test(tc, test_mul47);
  //   tcase_add_test(tc, test_mul48);
  //   tcase_add_test(tc, test_mul49);
  //   tcase_add_test(tc, test_mul50);
  tcase_add_test(tc, test_mul51);
  tcase_add_test(tc, test_mul52);
  //   tcase_add_test(tc, test_mul53);
  //   tcase_add_test(tc, test_mul54);
  //   tcase_add_test(tc, test_mul55);
  //   tcase_add_test(tc, test_mul56);
  //   tcase_add_test(tc, test_mul57);
  //   tcase_add_test(tc, test_mul58);
  //   tcase_add_test(tc, test_mul59);
  //   tcase_add_test(tc, test_mul60);

  suite_add_tcase(s, tc);
  return s;
}

void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_mul_fail1(s21_decimal decimal1, s21_decimal decimal2,
                    int code_check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, code_check);
}

void test_mul_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check) {
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, code_check);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}