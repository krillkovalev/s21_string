#include "s21_main_test.h"


START_TEST(s21_strpbrk_func) {
  const char str1_1[100] = "He2llo,23";
  const char str1_2[100] = "";
  const char str1_3[100] = "K\0Wa";
  const char str1_4[100] = "Hello,";
  const char str2_1[100] = "Allo";
  const char str2_2[100] = "";
  const char str2_3[100] = "S\0Ha";
  const char str2_4[100] = "WrdH!";
  const char str2_5[100] = "123";

  ck_assert_ptr_eq(strpbrk(str1_1, str2_1), s21_strpbrk(str1_1, str2_1));
  ck_assert_ptr_eq(strpbrk(str1_1, str2_4), s21_strpbrk(str1_1, str2_4));
  ck_assert_ptr_eq(strpbrk(str1_2, str2_1), s21_strpbrk(str1_2, str2_1));
  ck_assert_ptr_eq(strpbrk(str1_1, str2_2), s21_strpbrk(str1_1, str2_2));
  ck_assert_ptr_eq(strpbrk(str1_2, str2_2), s21_strpbrk(str1_2, str2_2));
  ck_assert_ptr_eq(strpbrk(str1_4, str2_5), s21_strpbrk(str1_4, str2_5));
  ck_assert_ptr_eq(strpbrk(str1_3, str2_4), s21_strpbrk(str1_3, str2_4));
  ck_assert_ptr_eq(strpbrk(str1_1, str2_3), s21_strpbrk(str1_1, str2_3));
}
END_TEST



Suite *suite_s21_strpbrk(void) {
  Suite *suite;
  suite = suite_create("Functions checking");


  TCase *tc_strpbrk = tcase_create("Strpbrk func");
  suite_add_tcase(suite, tc_strpbrk);
  tcase_add_test(tc_strpbrk, s21_strpbrk_func);


  return suite;
}