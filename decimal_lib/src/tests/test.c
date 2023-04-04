#include "test.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {s21_test_add(),
                              s21_test_mul(),
                              s21_test_floor(),
                              s21_test_negate(),
                              s21_test_round(),
                              s21_test_truncate(),
                              s21_test_sub(),
                              s21_test_fun(),
                              s21_test_is_equal(),
                              s21_test_is_greater_or_equal(),
                              s21_test_is_greater(),
                              s21_test_is_less(),
                              s21_test_is_less_or_equal(),
                              s21_test_is_not_equal(),
                              s21_test_from_decimal_to_float(),
                              s21_test_from_decimal_to_int(),
                              s21_test_mod(),
                              s21_test_from_float_to_decimal(),
                              s21_test_from_int_to_decimal(),
                              s21_test_div(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
