#include "test.h"

// TODO: Тесты на некорректные данные //

START_TEST(test_add_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_add(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual5) {
  //! степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual6) {
  //! степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual7) {
  //! степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual8) {
  //! степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual13) {
  //! степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual14) {
  //! степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual15) {
  //! степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual16) {
  //! степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

// TODO: Тесты на типы данных

START_TEST(test_add_manual1) {
  //! 7.922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 11.884224377139650639031592551
  s21_decimal check = {{0x66666667, 0x66666666, 0x26666666, 0x1B0000}};

  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  s21_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add21) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 26409387504754779198497227447
  s21_decimal check = {{0x7C0802B7, 0x55555555, 0x55555555, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add22) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add23) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add24) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966889
  s21_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add25) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add26) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -18486571253328345438493588412
  s21_decimal check = {{0xBBBBBBBC, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add27) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -34332203756181212957202378478
  s21_decimal check = {{0xEEEEEEEE, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add30) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -18486571253328345438493588411
  s21_decimal check = {{0xBBBBBBBB, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add31) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -34332203756181212957202378479
  s21_decimal check = {{0xEEEEEEEF, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add32) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -18486571253328345438493588410
  s21_decimal check = {{0xBBBBBBBA, 0xBBBBBBBB, 0x3BBBBBBB, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add33) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7922816251426433759354395035
  s21_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -34332203756181212957202378480
  s21_decimal check = {{0xEEEEEEF0, 0xEEEEEEEE, 0x6EEEEEEE, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add34) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -26409387504754779197847983444
  s21_decimal check = {{0x55555554, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add35) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -26409387504754779197847983446
  s21_decimal check = {{0x55555556, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add36) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -26409387504754779197847983444
  s21_decimal check = {{0x55555554, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add37) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -26409387504754779197847983446
  s21_decimal check = {{0x55555556, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add38) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add39) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -26409387504754779197847983445
  s21_decimal check = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add40) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -26409387504754779197847983444
  s21_decimal check = {{0x55555554, 0x55555555, 0x55555555, 0x80000000}};

  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add41) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 649244010.13123142325191963437
  s21_decimal check = {{0x2A95F32D, 0x4993B047, 0xD1C834AF, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add42) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 649243994.28559892039905211567
  s21_decimal check = {{0xF9AE74AF, 0x63582784, 0xD1C83459, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add43) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 649244010.20841517182548587502
  s21_decimal check = {{0x2AA233EE, 0xB4B0DD51, 0xD1C834AF, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add44) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 649243994.20841517182548587502
  s21_decimal check = {{0xF9A233EE, 0xF83AFA7A, 0xD1C83458, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add45) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 649244005.84208120014563947502
  s21_decimal check = {{0xC4DBB3EE, 0x92F6BF9, 0xD1C83498, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add46) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -3.6336660283201536
  s21_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 649243998.57474914350533227502
  s21_decimal check = {{0x5F68B3EE, 0xA3BC6BD2, 0xD1C83470, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add47) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add48) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add49) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add50) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add51) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add52) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add53) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add54) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 649244002.20841517182548587502
  s21_decimal check = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add55) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -56124981125208672332921.802216
  s21_decimal check = {{0x29358DE8, 0x553CC7C5, 0xB5597F0B, 0x80060000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add56) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 56124981125209321576924.010631
  s21_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // 56124981125209970820926.219046
  s21_decimal check = {{0xF5752326, 0x554164BC, 0xB5597F0B, 0x60000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add57) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // -49054757420.183255710099686956
  s21_decimal check = {{0x3CBDC62C, 0x491D6CBB, 0x9E8124F0, 0x80120000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add58) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // 49704001422.391670881925172831
  s21_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // 50353245424.600086053750658706
  s21_decimal check = {{0xC2395692, 0xD677691, 0xA2B33A78, 0x120000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add59) {
  // 649244002.20841517182548587502
  s21_decimal decimal1 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -649244002.20841517182548587502
  s21_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 0.00000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x140000}};

  test_add(decimal1, decimal2, check);
}

Suite *s21_test_add(void) {
  Suite *s = suite_create("\033[43m-=s21_add=-\033[0m");
  TCase *tc = tcase_create("add_rc");

  // TODO: Тесты на некорректные данные //

  tcase_add_test(tc, test_add_fail_manual1);
  tcase_add_test(tc, test_add_fail_manual2);
  tcase_add_test(tc, test_add_fail_manual3);
  tcase_add_test(tc, test_add_fail_manual4);
  tcase_add_test(tc, test_add_fail_manual5);
  tcase_add_test(tc, test_add_fail_manual6);
  tcase_add_test(tc, test_add_fail_manual7);
  tcase_add_test(tc, test_add_fail_manual8);
  tcase_add_test(tc, test_add_fail_manual9);
  tcase_add_test(tc, test_add_fail_manual10);
  tcase_add_test(tc, test_add_fail_manual11);
  tcase_add_test(tc, test_add_fail_manual12);
  tcase_add_test(tc, test_add_fail_manual13);
  tcase_add_test(tc, test_add_fail_manual14);
  tcase_add_test(tc, test_add_fail_manual15);
  tcase_add_test(tc, test_add_fail_manual16);
  tcase_add_test(tc, test_add_fail_manual17);

  // TODO: Тесты на типы данных //
  tcase_add_test(tc, test_add_manual1);
  tcase_add_test(tc, test_add1);
  tcase_add_test(tc, test_add2);
  tcase_add_test(tc, test_add3);
  tcase_add_test(tc, test_add4);
  tcase_add_test(tc, test_add5);
  tcase_add_test(tc, test_add6);
  tcase_add_test(tc, test_add7);
  tcase_add_test(tc, test_add9);
  tcase_add_test(tc, test_add10);
  tcase_add_test(tc, test_add11);
  tcase_add_test(tc, test_add12);
  tcase_add_test(tc, test_add13);
  tcase_add_test(tc, test_add14);
  tcase_add_test(tc, test_add15);
  tcase_add_test(tc, test_add16);
  tcase_add_test(tc, test_add17);
  tcase_add_test(tc, test_add18);
  tcase_add_test(tc, test_add19);
  tcase_add_test(tc, test_add20);
  tcase_add_test(tc, test_add21);
  tcase_add_test(tc, test_add22);
  tcase_add_test(tc, test_add23);
  tcase_add_test(tc, test_add24);
  tcase_add_test(tc, test_add25);
  tcase_add_test(tc, test_add26);
  tcase_add_test(tc, test_add27);
  tcase_add_test(tc, test_add30);
  tcase_add_test(tc, test_add31);
  tcase_add_test(tc, test_add32);
  tcase_add_test(tc, test_add33);
  tcase_add_test(tc, test_add34);
  tcase_add_test(tc, test_add35);
  tcase_add_test(tc, test_add36);
  tcase_add_test(tc, test_add37);
  tcase_add_test(tc, test_add38);
  tcase_add_test(tc, test_add39);
  tcase_add_test(tc, test_add40);
  tcase_add_test(tc, test_add41);
  tcase_add_test(tc, test_add42);
  tcase_add_test(tc, test_add43);
  tcase_add_test(tc, test_add44);
  tcase_add_test(tc, test_add45);
  tcase_add_test(tc, test_add46);
  tcase_add_test(tc, test_add47);
  tcase_add_test(tc, test_add48);
  tcase_add_test(tc, test_add49);
  tcase_add_test(tc, test_add50);
  tcase_add_test(tc, test_add51);
  tcase_add_test(tc, test_add52);
  tcase_add_test(tc, test_add53);
  tcase_add_test(tc, test_add54);
  tcase_add_test(tc, test_add55);
  tcase_add_test(tc, test_add56);
  tcase_add_test(tc, test_add57);
  tcase_add_test(tc, test_add58);
  tcase_add_test(tc, test_add59);

  suite_add_tcase(s, tc);
  return s;
}

void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  int code = s21_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, check);
}