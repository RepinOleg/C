#include "../s21_3DViewer/OBJLoader/OBJLoader_Util.h"
#include "Test.h"
START_TEST(OBJLoader_1) {
  OBJData_t *data = OBJLoader_Load("Tests/Test_Models/Test1.obj_model");

  if (!OBJLoader_IsValid(data)) {
    return;
  }

  ck_assert_int_eq(data->verticesData->amount, 4);
  ck_assert_int_eq(data->facesData->amount, 3);
  ck_assert_int_eq(data->invalidData->amount, 0);

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_2) {
  OBJData_t *data = OBJLoader_Load("Tests/Test_Models/Test2.obj_model");

  if (!OBJLoader_IsValid(data)) {
    return;
  }

  ck_assert_int_eq(data->verticesData->amount, 4);
  ck_assert_int_eq(data->facesData->amount, 2);
  ck_assert_int_eq(data->invalidData->amount, 0);

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_3) {
  OBJData_t *data = OBJLoader_Load("Tests/Test_Models/Test3.obj_model");

  if (!OBJLoader_IsValid(data)) {
    return;
  }

  ck_assert_int_eq(data->verticesData->amount, 3);
  ck_assert_int_eq(data->facesData->amount, 1);
  ck_assert_int_eq(data->invalidData->amount, 10);

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_4) {
  OBJData_t *data = NULL;

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_5) {
  OBJData_t *data = OBJLoader_Load("Tests/Test_Models/Test1.obj_model");

  if (!OBJLoader_IsValid(data)) {
    return;
  }

  free(data->fileName);
  data->fileName = NULL;

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_6) {
  OBJData_t *data = (OBJData_t *)malloc(sizeof(OBJData_t));

  data->facesData = NULL;
  data->invalidData = NULL;
  data->verticesData = NULL;
  data->fileName = NULL;

  OBJLoader_Dump(data);
}
END_TEST

START_TEST(OBJLoader_7) {
  OBJData_t *data = NULL;
  int64_t amount = 0;
  OBJLoader_Status_t res = OBJLoader_InvalidData(data, "", amount);

  ck_assert_int_eq(res, 3);
}
END_TEST

Suite *Test_OBJLoader(void) {
  Suite *s = suite_create(color_text("OBJLoader"));
  TCase *tc = tcase_create("OBJLoader_tc");

  tcase_add_test(tc, OBJLoader_1);
  tcase_add_test(tc, OBJLoader_2);
  tcase_add_test(tc, OBJLoader_3);
  tcase_add_test(tc, OBJLoader_4);
  tcase_add_test(tc, OBJLoader_5);
  tcase_add_test(tc, OBJLoader_6);
  tcase_add_test(tc, OBJLoader_7);
  suite_add_tcase(s, tc);
  return s;
}
