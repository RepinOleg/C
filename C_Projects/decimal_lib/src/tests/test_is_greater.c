#include "test.h"

// TODO: Тесты на некорректные данные //

START_TEST(test_is_greater_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok21) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok23) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok24) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok25) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok26) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok27) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok28) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok29) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok30) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok31) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok32) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok33) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok34) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok35) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok36) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok37) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok38) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok39) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok40) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok41) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok42) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok43) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok44) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok45) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok46) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok47) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok48) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok49) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok50) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok51) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok52) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok53) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok54) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok55) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok56) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok57) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok58) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok59) {
  // 19290120297533996546.12653034
  s21_decimal decimal1 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TRUE;

  test_is_greater(decimal1, decimal2, check);
}

START_TEST(test_is_greater_ok60) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 19290120297533996546.12653034
  s21_decimal decimal2 = {{0x11EAD3EA, 0xABA39F31, 0x63BA42F, 0x80000}};
  int check = FALSE;

  test_is_greater(decimal1, decimal2, check);
}

Suite *s21_test_is_greater(void) {
  Suite *s = suite_create("\033[43m-=s21_is_greater=-\033[0m");
  TCase *tc = tcase_create("is_greater_rc");

  // TODO: Тесты на некорректные данные //
  tcase_add_test(tc, test_is_greater_ok1);
  tcase_add_test(tc, test_is_greater_ok2);
  tcase_add_test(tc, test_is_greater_ok3);
  tcase_add_test(tc, test_is_greater_ok4);
  tcase_add_test(tc, test_is_greater_ok5);
  tcase_add_test(tc, test_is_greater_ok6);
  tcase_add_test(tc, test_is_greater_ok7);
  tcase_add_test(tc, test_is_greater_ok8);
  tcase_add_test(tc, test_is_greater_ok9);
  tcase_add_test(tc, test_is_greater_ok10);
  tcase_add_test(tc, test_is_greater_ok11);
  tcase_add_test(tc, test_is_greater_ok12);
  tcase_add_test(tc, test_is_greater_ok13);
  tcase_add_test(tc, test_is_greater_ok14);
  tcase_add_test(tc, test_is_greater_ok15);
  tcase_add_test(tc, test_is_greater_ok16);
  tcase_add_test(tc, test_is_greater_ok17);
  tcase_add_test(tc, test_is_greater_ok18);
  tcase_add_test(tc, test_is_greater_ok19);
  tcase_add_test(tc, test_is_greater_ok20);
  tcase_add_test(tc, test_is_greater_ok21);
  tcase_add_test(tc, test_is_greater_ok22);
  tcase_add_test(tc, test_is_greater_ok23);
  tcase_add_test(tc, test_is_greater_ok24);
  tcase_add_test(tc, test_is_greater_ok25);
  tcase_add_test(tc, test_is_greater_ok26);
  tcase_add_test(tc, test_is_greater_ok27);
  tcase_add_test(tc, test_is_greater_ok28);
  tcase_add_test(tc, test_is_greater_ok29);
  tcase_add_test(tc, test_is_greater_ok30);
  tcase_add_test(tc, test_is_greater_ok31);
  tcase_add_test(tc, test_is_greater_ok32);
  tcase_add_test(tc, test_is_greater_ok33);
  tcase_add_test(tc, test_is_greater_ok34);
  tcase_add_test(tc, test_is_greater_ok35);
  tcase_add_test(tc, test_is_greater_ok36);
  tcase_add_test(tc, test_is_greater_ok37);
  tcase_add_test(tc, test_is_greater_ok38);
  tcase_add_test(tc, test_is_greater_ok39);
  tcase_add_test(tc, test_is_greater_ok40);
  tcase_add_test(tc, test_is_greater_ok41);
  tcase_add_test(tc, test_is_greater_ok42);
  tcase_add_test(tc, test_is_greater_ok43);
  tcase_add_test(tc, test_is_greater_ok44);
  tcase_add_test(tc, test_is_greater_ok45);
  tcase_add_test(tc, test_is_greater_ok46);
  tcase_add_test(tc, test_is_greater_ok47);
  tcase_add_test(tc, test_is_greater_ok48);
  tcase_add_test(tc, test_is_greater_ok49);
  tcase_add_test(tc, test_is_greater_ok50);
  tcase_add_test(tc, test_is_greater_ok51);
  tcase_add_test(tc, test_is_greater_ok52);
  tcase_add_test(tc, test_is_greater_ok53);
  tcase_add_test(tc, test_is_greater_ok54);
  tcase_add_test(tc, test_is_greater_ok55);
  tcase_add_test(tc, test_is_greater_ok56);
  tcase_add_test(tc, test_is_greater_ok57);
  tcase_add_test(tc, test_is_greater_ok58);
  tcase_add_test(tc, test_is_greater_ok59);
  tcase_add_test(tc, test_is_greater_ok60);

  suite_add_tcase(s, tc);
  return s;
}

void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check) {
  int code = s21_is_greater(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}