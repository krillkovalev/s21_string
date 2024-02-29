#include "s21_main_test.h"

START_TEST(strncmp_1) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  int n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello!";
  int n = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  const char *str1 = "Hello!";
  const char *str2 = "Hello World!";
  int n = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  const char *str1 = "Hi";
  const char *str2 = "Bay";
  int n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  const char *str1 = "Bay";
  const char *str2 = "Hi";
  int n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  int n = 26;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  const char *str1 = " Hello World!";
  const char *str2 = "Hello World!";
  int n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  const char *str1 = "Hello World! ";
  const char *str2 = "Hello World!";
  int n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World! ";
  int n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *suite_s21_strncmp(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strncmp = tcase_create("strncmp_test");
  suite_add_tcase(suite, tc_strncmp);
  tcase_add_test(tc_strncmp, strncmp_1);
  tcase_add_test(tc_strncmp, strncmp_2);
  tcase_add_test(tc_strncmp, strncmp_3);
  tcase_add_test(tc_strncmp, strncmp_4);
  tcase_add_test(tc_strncmp, strncmp_5);
  tcase_add_test(tc_strncmp, strncmp_6);
  tcase_add_test(tc_strncmp, strncmp_7);
  tcase_add_test(tc_strncmp, strncmp_8);
  tcase_add_test(tc_strncmp, strncmp_9);

  return suite;
}