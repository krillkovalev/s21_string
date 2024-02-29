#include "s21_main_test.h"

START_TEST(s21_strlen_func) {
  const char str1[100] = "He2llo,23";
  const char str2[100] = "";
  const char str3[100] = "K\0ha";
  const char str4[100] = "Hello\\\0";

  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
  ck_assert_int_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

Suite *suite_s21_strlen(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strlen = tcase_create("Strlen func");
  suite_add_tcase(suite, tc_strlen);
  tcase_add_test(tc_strlen, s21_strlen_func);

  return suite;
}
