#include "test.h"

// TODO: Тесты на некорректные данные //
START_TEST(test_is_less_or_equal_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok21) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 30667538544853.855676101018067
  s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok22) {
  // 30667538544853.855676101018067
  s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0xF0000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok23) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -30667538544853.855676101018067
  s21_decimal decimal2 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok24) {
  // -30667538544853.855676101018067
  s21_decimal decimal1 = {{0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok25) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok27) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok28) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok29) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok30) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok31) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok32) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok33) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok34) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok35) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok36) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok37) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok38) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok39) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok40) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok41) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok43) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok44) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok45) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok46) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok47) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok48) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok49) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok50) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok51) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok52) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok53) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok54) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok55) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok56) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok57) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok58) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok59) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = FALSE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

START_TEST(test_is_less_or_equal_ok60) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_less_or_equal(decimal1, decimal2, check);
}

Suite *s21_test_is_less_or_equal(void) {
  Suite *s = suite_create("\033[43m-=s21_is_less_or_equal=-\033[0m");
  TCase *tc = tcase_create("is_less_or_equal_rc");

  // TODO: Тесты на некорректные данные //
  tcase_add_test(tc, test_is_less_or_equal_ok1);
  tcase_add_test(tc, test_is_less_or_equal_ok2);
  tcase_add_test(tc, test_is_less_or_equal_ok3);
  tcase_add_test(tc, test_is_less_or_equal_ok4);
  tcase_add_test(tc, test_is_less_or_equal_ok5);
  tcase_add_test(tc, test_is_less_or_equal_ok6);
  tcase_add_test(tc, test_is_less_or_equal_ok7);
  tcase_add_test(tc, test_is_less_or_equal_ok8);
  tcase_add_test(tc, test_is_less_or_equal_ok9);
  tcase_add_test(tc, test_is_less_or_equal_ok10);
  tcase_add_test(tc, test_is_less_or_equal_ok11);
  tcase_add_test(tc, test_is_less_or_equal_ok12);
  tcase_add_test(tc, test_is_less_or_equal_ok13);
  tcase_add_test(tc, test_is_less_or_equal_ok14);
  tcase_add_test(tc, test_is_less_or_equal_ok15);
  tcase_add_test(tc, test_is_less_or_equal_ok16);
  tcase_add_test(tc, test_is_less_or_equal_ok17);
  tcase_add_test(tc, test_is_less_or_equal_ok18);
  tcase_add_test(tc, test_is_less_or_equal_ok19);
  tcase_add_test(tc, test_is_less_or_equal_ok20);
  tcase_add_test(tc, test_is_less_or_equal_ok21);
  tcase_add_test(tc, test_is_less_or_equal_ok22);
  tcase_add_test(tc, test_is_less_or_equal_ok23);
  tcase_add_test(tc, test_is_less_or_equal_ok24);
  tcase_add_test(tc, test_is_less_or_equal_ok25);
  tcase_add_test(tc, test_is_less_or_equal_ok26);
  tcase_add_test(tc, test_is_less_or_equal_ok27);
  tcase_add_test(tc, test_is_less_or_equal_ok28);
  tcase_add_test(tc, test_is_less_or_equal_ok29);
  tcase_add_test(tc, test_is_less_or_equal_ok30);
  tcase_add_test(tc, test_is_less_or_equal_ok31);
  tcase_add_test(tc, test_is_less_or_equal_ok32);
  tcase_add_test(tc, test_is_less_or_equal_ok33);
  tcase_add_test(tc, test_is_less_or_equal_ok34);
  tcase_add_test(tc, test_is_less_or_equal_ok35);
  tcase_add_test(tc, test_is_less_or_equal_ok36);
  tcase_add_test(tc, test_is_less_or_equal_ok37);
  tcase_add_test(tc, test_is_less_or_equal_ok38);
  tcase_add_test(tc, test_is_less_or_equal_ok39);
  tcase_add_test(tc, test_is_less_or_equal_ok40);
  tcase_add_test(tc, test_is_less_or_equal_ok41);
  tcase_add_test(tc, test_is_less_or_equal_ok42);
  tcase_add_test(tc, test_is_less_or_equal_ok43);
  tcase_add_test(tc, test_is_less_or_equal_ok44);
  tcase_add_test(tc, test_is_less_or_equal_ok45);
  tcase_add_test(tc, test_is_less_or_equal_ok46);
  tcase_add_test(tc, test_is_less_or_equal_ok47);
  tcase_add_test(tc, test_is_less_or_equal_ok48);
  tcase_add_test(tc, test_is_less_or_equal_ok49);
  tcase_add_test(tc, test_is_less_or_equal_ok50);
  tcase_add_test(tc, test_is_less_or_equal_ok51);
  tcase_add_test(tc, test_is_less_or_equal_ok52);
  tcase_add_test(tc, test_is_less_or_equal_ok53);
  tcase_add_test(tc, test_is_less_or_equal_ok54);
  tcase_add_test(tc, test_is_less_or_equal_ok55);
  tcase_add_test(tc, test_is_less_or_equal_ok56);
  tcase_add_test(tc, test_is_less_or_equal_ok57);
  tcase_add_test(tc, test_is_less_or_equal_ok58);
  tcase_add_test(tc, test_is_less_or_equal_ok59);
  tcase_add_test(tc, test_is_less_or_equal_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                           int check) {
  int code = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}