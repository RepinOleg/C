#ifndef __TEST_H__
#define __TEST_H__

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_3DViewer/Headers/AffineTransform.h"
#include "../s21_3DViewer/Headers/DynamicBuffer.h"
#include "../s21_3DViewer/Headers/OBJLoader.h"

#define color_text(test_name) "\033[33;41m" #test_name "\033[0m"

extern Suite *Test_DynamicBuffer(void);
extern Suite *Test_OBJLoader(void);
Suite *add_test(Suite *suite, const TTest *test);

void test_s21_3D_Viewer(SRunner *runner);

#endif  // __TEST_H__
