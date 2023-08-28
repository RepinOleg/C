#include "Test.h"

START_TEST(DBuffer_1) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 0);
  ck_assert_int_eq(buf->capacity, 10);
  ck_assert_int_eq(buf->dataSize, sizeof(int));

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_2) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  free(buf->data);
  buf->data = NULL;

  ck_assert_int_eq(buf->capacity, 1);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_3) {
  DBuffer_t *buf = NULL;

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_4) {
  DBuffer_t *buf = DBuffer_Create(-1, 0);

  ck_assert_ptr_null(buf);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_5) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Reserve(buf, 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->capacity, 10);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_6) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Status_t ret = DBuffer_Reserve(buf, -1);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_7) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 1);

  DBuffer_Status_t ret = DBuffer_Reserve(buf, 10);

  ck_assert_int_eq(ret, DBUFFER_OK);
  ck_assert_int_eq(buf->capacity, 10);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_8) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 2);

  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 10);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_9) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 1);

  DBuffer_Status_t ret = DBuffer_Insert(buf, &(int){1}, -1, 0);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_10) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);

  DBuffer_Erase(buf, 1, 0);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 2);

  DBuffer_Status_t ret = DBuffer_Erase(buf, 5, 0);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_11) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Status_t ret = DBuffer_Erase(buf, -1, 0);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_12) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);

  DBuffer_Clear(buf);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 0);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_13) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  buf->dataSize = -1;

  DBuffer_Status_t ret = DBuffer_Clear(buf);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_14) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);

  int *p = DBuffer_GetData(buf, 0);

  ck_assert_ptr_nonnull(p);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_15) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);
  DBuffer_Insert(buf, &(int){1}, 1, 0);

  int *p = DBuffer_GetData(buf, -1);

  ck_assert_ptr_null(p);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_16) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushBack(buf, &(int){1}, 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 1);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_17) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Status_t ret = DBuffer_PushBack(buf, &(int){1}, -1);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_18) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushFront(buf, &(int){1}, 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 1);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_19) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_Status_t ret = DBuffer_PushFront(buf, &(int){1}, -1);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_20) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushFront(buf, &(int){1}, 1);
  DBuffer_PopBack(buf, 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 0);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_21) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushFront(buf, &(int){1}, 1);
  DBuffer_Status_t ret = DBuffer_PopBack(buf, -1);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_22) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushFront(buf, &(int){1}, 1);
  DBuffer_PopFront(buf, 1);

  if (!DBuffer_IsValid(buf)) {
    return;
  }

  ck_assert_int_eq(buf->length, 0);

  DBuffer_Destroy(buf);
}
END_TEST

START_TEST(DBuffer_23) {
  DBuffer_t *buf = DBuffer_Create(sizeof(int), 0);

  DBuffer_PushFront(buf, &(int){1}, 1);
  DBuffer_Status_t ret = DBuffer_PopFront(buf, -1);

  ck_assert_int_ne(ret, DBUFFER_OK);

  DBuffer_Destroy(buf);
}
END_TEST

Suite *Test_DynamicBuffer(void) {
  Suite *s = suite_create(color_text("DynamicBuffer"));
  TCase *tc = tcase_create("DynamicBuffer_tc");

  tcase_add_test(tc, DBuffer_1);
  tcase_add_test(tc, DBuffer_2);
  tcase_add_test(tc, DBuffer_3);
  tcase_add_test(tc, DBuffer_4);
  tcase_add_test(tc, DBuffer_5);
  tcase_add_test(tc, DBuffer_6);
  tcase_add_test(tc, DBuffer_7);
  tcase_add_test(tc, DBuffer_8);
  tcase_add_test(tc, DBuffer_9);
  tcase_add_test(tc, DBuffer_10);
  tcase_add_test(tc, DBuffer_11);
  tcase_add_test(tc, DBuffer_12);
  tcase_add_test(tc, DBuffer_13);
  tcase_add_test(tc, DBuffer_14);
  tcase_add_test(tc, DBuffer_15);
  tcase_add_test(tc, DBuffer_16);
  tcase_add_test(tc, DBuffer_17);
  tcase_add_test(tc, DBuffer_18);
  tcase_add_test(tc, DBuffer_19);
  tcase_add_test(tc, DBuffer_20);
  tcase_add_test(tc, DBuffer_21);
  tcase_add_test(tc, DBuffer_22);
  tcase_add_test(tc, DBuffer_23);

  suite_add_tcase(s, tc);
  return s;
}
