#include "Test.h"

static void test_run(Suite *s, int *failed) {
  SRunner *sr = srunner_create(s);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  *failed += srunner_ntests_failed(sr);
  srunner_free(sr);
}

Suite *add_test(Suite *suite, const TTest *test) {
  TCase *test_case;
  test_case = tcase_create(test->name);
  tcase_add_test(test_case, test);
  suite_add_tcase(suite, test_case);
  return suite;
}

int main(void) {
  int failed = 0;
  Suite *tests[] = {Test_DynamicBuffer(), Test_OBJLoader(), NULL};

  printf("\n" color_text("====== TESTING ======") "\n\n");

  for (Suite **s = tests; *s != NULL; ++s) {
    test_run(*s, &failed);
  }
  SRunner *runner = srunner_create(suite_create(""));

  test_s21_3D_Viewer(runner);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\n" color_text("====== FAILED: %d ======") "\n",
         failed + number_failed);

  return 0;
}
