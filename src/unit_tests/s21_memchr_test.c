#include "s21_main_test.h"

START_TEST(memchr_1) {
  char str[] = "pampampam";
  int c = 'm';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "pam";
  int c = 'm';
  s21_size_t n = sizeof(str) - sizeof(char);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "pam";
  int c = 'a';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "mpam";
  int c = 'm';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "pam";
  int c = 'a';
  s21_size_t n = sizeof(str) - 2 * sizeof(char);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "";
  int c = 'a';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "abs";
  int c = 'a';
  s21_size_t n = 0;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "asd";
  int c = ' ';
  s21_size_t n = sizeof(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "GNOiee";
  int c = 'i';
  s21_size_t n = sizeof(str) - 4;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str[13] = "GNOiee";
  int c = '\0';
  s21_size_t n = 10;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST



Suite *suite_s21_memchr(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_memchr = tcase_create("memchr_test");
  suite_add_tcase(suite, tc_memchr);
  tcase_add_test(tc_memchr, memchr_1);
  tcase_add_test(tc_memchr, memchr_2);
  tcase_add_test(tc_memchr, memchr_3);
  tcase_add_test(tc_memchr, memchr_4);
  tcase_add_test(tc_memchr, memchr_5);
  tcase_add_test(tc_memchr, memchr_6);
  tcase_add_test(tc_memchr, memchr_7);
  tcase_add_test(tc_memchr, memchr_8);
  tcase_add_test(tc_memchr, memchr_9);
  tcase_add_test(tc_memchr, memchr_10);


  return suite;
}