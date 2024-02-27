#include "s21_main_test.h"


START_TEST(s21_strstr_func) {
  const char str1_1[100] = "He2llo,23";
  const char str1_2[100] = "";
  const char str1_3[100] = "He\0llo,23";
  const char str1_4[100] = "Hello,";
  const char str2_1[100] = "lo";
  const char str2_2[100] = "";
  const char str2_3[100] = "He";
  const char str2_4[100] = "23";

  ck_assert_ptr_eq(strstr(str1_1, str2_1), s21_strstr(str1_1, str2_1));
  ck_assert_ptr_eq(strstr(str1_1, str2_4), s21_strstr(str1_1, str2_4));
  ck_assert_ptr_eq(strstr(str1_2, str2_1), s21_strstr(str1_2, str2_1));
  ck_assert_ptr_eq(strstr(str1_1, str2_2), s21_strstr(str1_1, str2_2));
  ck_assert_ptr_eq(strstr(str1_2, str2_2), s21_strstr(str1_2, str2_2));
  ck_assert_ptr_eq(strstr(str1_3, str2_1), s21_strstr(str1_3, str2_1));
  ck_assert_ptr_eq(strstr(str1_3, str2_3), s21_strstr(str1_3, str2_3));
  ck_assert_ptr_eq(strstr(str1_4, str2_4), s21_strstr(str1_4, str2_4));
}
END_TEST



Suite *suite_s21_strstr(void) {
  Suite *suite;
  suite = suite_create("Functions checking");


  TCase *tc_strstr = tcase_create("Strstr func");
  suite_add_tcase(suite, tc_strstr);
  tcase_add_test(tc_strstr, s21_strstr_func);


  return suite;
}