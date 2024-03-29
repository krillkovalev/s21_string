#include "s21_main_test.h"

START_TEST(memset_test1) {
  char origin_src1[] = "12340";
  char s21_src1[] = "12340";
  char ch1 = 75;
  int n1 = 5;
  ck_assert_mem_eq(s21_memset(s21_src1, ch1, n1), memset(origin_src1, ch1, n1),
                   n1);
}
END_TEST

START_TEST(memset_test2) {
  char origin_src2[] = "\00012340";
  char s21_src2[] = "\00012340";
  char ch2 = 75;
  int n2 = 2;
  ck_assert_mem_eq(s21_memset(s21_src2, ch2, n2), memset(origin_src2, ch2, n2),
                   n2);
}
END_TEST

START_TEST(memset_test3) {
  char origin_src3[] = "qwer12340";
  char s21_src3[] = "qwer12340";
  char ch3 = 5;
  int n3 = 3;
  ck_assert_mem_eq(s21_memset(s21_src3, ch3, n3), memset(origin_src3, ch3, n3),
                   n3);
}
END_TEST

START_TEST(memset_test4) {
  char origin_src4[] = "qwer12340";
  char s21_src4[] = "qwer12340";
  char ch4 = 67;
  int n4 = 0;
  ck_assert_mem_eq(s21_memset(s21_src4, ch4, n4), memset(origin_src4, ch4, n4),
                   n4);
}
END_TEST

START_TEST(memset_test5) {
  char origin_src5[] = "12340";
  char s21_src5[] = "12340";
  char ch5 = 67;
  int n5 = 3;
  ck_assert_mem_eq(s21_memset(s21_src5, ch5, n5), memset(origin_src5, ch5, n5),
                   n5);
}
END_TEST

Suite *suite_s21_memset(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_memset = tcase_create("memset_test");
  suite_add_tcase(suite, tc_memset);
  tcase_add_test(tc_memset, memset_test1);
  tcase_add_test(tc_memset, memset_test2);
  tcase_add_test(tc_memset, memset_test3);
  tcase_add_test(tc_memset, memset_test4);
  tcase_add_test(tc_memset, memset_test5);

  return suite;
}