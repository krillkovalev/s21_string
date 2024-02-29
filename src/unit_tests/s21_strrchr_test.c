#include "s21_main_test.h"

START_TEST(s21_strrchr_func) {
  const char str1_1[100] = "He2llo,23";
  const char str1_2[100] = "";
  const char str1_3[100] = "o\0Wa";
  int c1 = 'o';
  int c2 = '2';
  int c3 = 'a';
  int c4 = '\0';

  ck_assert_ptr_eq(strrchr(str1_1, c1), s21_strrchr(str1_1, c1));
  ck_assert_ptr_eq(strrchr(str1_1, c2), s21_strrchr(str1_1, c2));
  ck_assert_ptr_eq(strrchr(str1_1, c3), s21_strrchr(str1_1, c3));
  ck_assert_ptr_eq(strrchr(str1_2, c1), s21_strrchr(str1_2, c1));
  ck_assert_ptr_eq(strrchr(str1_3, c3), s21_strrchr(str1_3, c3));
  ck_assert_ptr_eq(strrchr(str1_3, c1), s21_strrchr(str1_3, c1));
  ck_assert_ptr_eq(strrchr(str1_1, c4), s21_strrchr(str1_1, c4));
}
END_TEST

Suite *suite_s21_strrchr(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strrchr = tcase_create("Strrchr func");
  suite_add_tcase(suite, tc_strrchr);
  tcase_add_test(tc_strrchr, s21_strrchr_func);

  return suite;
}