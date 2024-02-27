#include "s21_main_test.h"


START_TEST(strchr_1) {
  char src[5] = "12340";
  int n = '1';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_2) {
  char src[5] = "12340";
  int n = 'k';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_3) {
  char src[5] = "12341";
  int n = 4;
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST

START_TEST(strchr_4) {
  char src[] = "";
  int n = 'k';
  ck_assert_pstr_eq(s21_strchr(src, n), strchr(src, n));
}
END_TEST


Suite *suite_s21_strchr(void) {
  Suite *suite;
  suite = suite_create("Functions checking");


 TCase *tc_strchr = tcase_create("strchr_test");
  suite_add_tcase(suite, tc_strchr);
  tcase_add_test(tc_strchr, strchr_1);
  tcase_add_test(tc_strchr, strchr_2);
  tcase_add_test(tc_strchr, strchr_3);
  tcase_add_test(tc_strchr, strchr_4);


  return suite;
}