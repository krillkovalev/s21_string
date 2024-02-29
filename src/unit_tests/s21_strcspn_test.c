#include "s21_main_test.h"

START_TEST(s21_strcspn_func) {
  const char str1_1[100] = "He2llo,23";
  const char str1_2[100] = "";
  const char str1_3[100] = "K\0ha";
  const char str1_4[100] = "Hello\0,";
  const char str2_1[100] = "Allo";
  const char str2_2[100] = "";
  const char str2_3[100] = "S\0ha";
  const char str2_4[100] = "Wrd!";
  const char str2_5[100] = "123";

  ck_assert_int_eq(strcspn(str1_1, str2_1), s21_strcspn(str1_1, str2_1));
  ck_assert_int_eq(strcspn(str1_1, str2_2), s21_strcspn(str1_1, str2_2));
  ck_assert_int_eq(strcspn(str1_2, str2_1), s21_strcspn(str1_2, str2_1));
  ck_assert_int_eq(strcspn(str1_1, str2_5), s21_strcspn(str1_1, str2_5));
  ck_assert_int_eq(strcspn(str1_2, str2_2), s21_strcspn(str1_2, str2_2));
  ck_assert_int_eq(strcspn(str1_1, str2_4), s21_strcspn(str1_1, str2_4));
  ck_assert_int_eq(strcspn(str1_3, str2_1), s21_strcspn(str1_3, str2_1));
  ck_assert_int_eq(strcspn(str1_4, str2_3), s21_strcspn(str1_4, str2_3));
}
END_TEST

Suite *suite_s21_strcspn(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strcspn = tcase_create("Strcspn func");
  suite_add_tcase(suite, tc_strcspn);
  tcase_add_test(tc_strcspn, s21_strcspn_func);

  return suite;
}