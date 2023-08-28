#include "../s21_3DViewer/Headers/AffineTransform.h"
#include "Test.h"

START_TEST(test_s21_3D_Viewer_1_1) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");

  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;
  double value = 1;
  int flag = 1;
  MoveXYZ(data, value, flag);

  ck_assert_double_eq(vertices[1].x, 1.0);
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_1_2) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");
  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;
  double value = 2;
  int flag = 2;
  MoveXYZ(data, value, flag);

  ck_assert_double_eq(vertices[1].y, 2.0);
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_1_3) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");
  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;
  double value = 0.5;
  int flag = 3;
  MoveXYZ(data, value, flag);

  ck_assert_double_eq(vertices[1].z, 0.5);
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_2_1) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");

  ScaleReset(data);

  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;

  ck_assert_double_eq(vertices[1].x, 0.0);
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_3_1) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");
  double value = 2.0;
  RotateX(data, value);

  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;

  ck_assert_msg(fabs(vertices[7].y) - 0.999391 <= 0.000001, "test 3_1 failed");
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_3_2) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");
  double value = 2.0;
  RotateY(data, value);

  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;

  ck_assert_msg(fabs(vertices[7].x) - 0.999391 <= 0.000001, "test 3_2 failed");
  OBJLoader_Dump(data);
}
END_TEST

START_TEST(test_s21_3D_Viewer_3_3) {
  OBJData_t *data = NULL;
  data = OBJLoader_Load("Tests/Test_Models/Cube.obj_model");
  double value = 2.0;
  RotateZ(data, value);

  Vertex_t *vertices = (Vertex_t *)data->verticesData->vertices->data;
  ck_assert_msg(fabs(vertices[7].y) - 1.034273 <= 0.000001, "test 3_3 failed");
  OBJLoader_Dump(data);
}
END_TEST

void test_s21_3D_Viewer(SRunner *runner) {
  Suite *tests = suite_create(color_text("AffineTransform"));

  tests = add_test(tests, test_s21_3D_Viewer_1_1);
  tests = add_test(tests, test_s21_3D_Viewer_1_2);
  tests = add_test(tests, test_s21_3D_Viewer_1_3);
  tests = add_test(tests, test_s21_3D_Viewer_2_1);
  tests = add_test(tests, test_s21_3D_Viewer_3_1);
  tests = add_test(tests, test_s21_3D_Viewer_3_2);
  tests = add_test(tests, test_s21_3D_Viewer_3_3);
  srunner_add_suite(runner, tests);
}
