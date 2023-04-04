#include "test.h"

// TODO: Тесты на некорректные данные //
START_TEST(test_is_less_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok21) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok22) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok23) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok24) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok25) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok26) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok27) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok28) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok29) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok30) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok31) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok32) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok33) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok34) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok35) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok36) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok37) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok38) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok39) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok40) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok41) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok42) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok43) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok44) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok45) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok46) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok47) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok48) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok49) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok50) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok51) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok52) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok53) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok54) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok55) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok56) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok57) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok58) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok59) {
  // 58391.31040040850204230282817
  s21_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok60) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 58391.31040040850204230282817
  s21_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TRUE;

  test_is_less(decimal1, decimal2, check);
}

Suite *s21_test_is_less(void) {
  Suite *s = suite_create("\033[43m-=s21_is_less=-\033[0m");
  TCase *tc = tcase_create("is_less_rc");

  // TODO: Тесты на некорректные данные //
  tcase_add_test(tc, test_is_less_ok1);
  tcase_add_test(tc, test_is_less_ok2);
  tcase_add_test(tc, test_is_less_ok3);
  tcase_add_test(tc, test_is_less_ok4);
  tcase_add_test(tc, test_is_less_ok5);
  tcase_add_test(tc, test_is_less_ok6);
  tcase_add_test(tc, test_is_less_ok7);
  tcase_add_test(tc, test_is_less_ok8);
  tcase_add_test(tc, test_is_less_ok9);
  tcase_add_test(tc, test_is_less_ok10);
  tcase_add_test(tc, test_is_less_ok11);
  tcase_add_test(tc, test_is_less_ok12);
  tcase_add_test(tc, test_is_less_ok13);
  tcase_add_test(tc, test_is_less_ok14);
  tcase_add_test(tc, test_is_less_ok15);
  tcase_add_test(tc, test_is_less_ok16);
  tcase_add_test(tc, test_is_less_ok17);
  tcase_add_test(tc, test_is_less_ok18);
  tcase_add_test(tc, test_is_less_ok19);
  tcase_add_test(tc, test_is_less_ok20);
  tcase_add_test(tc, test_is_less_ok21);
  tcase_add_test(tc, test_is_less_ok22);
  tcase_add_test(tc, test_is_less_ok23);
  tcase_add_test(tc, test_is_less_ok24);
  tcase_add_test(tc, test_is_less_ok25);
  tcase_add_test(tc, test_is_less_ok26);
  tcase_add_test(tc, test_is_less_ok27);
  tcase_add_test(tc, test_is_less_ok28);
  tcase_add_test(tc, test_is_less_ok29);
  tcase_add_test(tc, test_is_less_ok30);
  tcase_add_test(tc, test_is_less_ok31);
  tcase_add_test(tc, test_is_less_ok32);
  tcase_add_test(tc, test_is_less_ok33);
  tcase_add_test(tc, test_is_less_ok34);
  tcase_add_test(tc, test_is_less_ok35);
  tcase_add_test(tc, test_is_less_ok36);
  tcase_add_test(tc, test_is_less_ok37);
  tcase_add_test(tc, test_is_less_ok38);
  tcase_add_test(tc, test_is_less_ok39);
  tcase_add_test(tc, test_is_less_ok40);
  tcase_add_test(tc, test_is_less_ok41);
  tcase_add_test(tc, test_is_less_ok42);
  tcase_add_test(tc, test_is_less_ok43);
  tcase_add_test(tc, test_is_less_ok44);
  tcase_add_test(tc, test_is_less_ok45);
  tcase_add_test(tc, test_is_less_ok46);
  tcase_add_test(tc, test_is_less_ok47);
  tcase_add_test(tc, test_is_less_ok48);
  tcase_add_test(tc, test_is_less_ok49);
  tcase_add_test(tc, test_is_less_ok50);
  tcase_add_test(tc, test_is_less_ok51);
  tcase_add_test(tc, test_is_less_ok52);
  tcase_add_test(tc, test_is_less_ok53);
  tcase_add_test(tc, test_is_less_ok54);
  tcase_add_test(tc, test_is_less_ok55);
  tcase_add_test(tc, test_is_less_ok56);
  tcase_add_test(tc, test_is_less_ok57);
  tcase_add_test(tc, test_is_less_ok58);
  tcase_add_test(tc, test_is_less_ok59);
  tcase_add_test(tc, test_is_less_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_is_less(s21_decimal decimal1, s21_decimal decimal2, int check) {
  int code = s21_is_less(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}