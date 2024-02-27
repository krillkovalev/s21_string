#include "s21_main_test.h"

START_TEST(memcmp_1) {
  char src[5] = "12340";
  char srd[5] = "1234 ";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}
END_TEST

START_TEST(memcmp_2) {
  char src[5] = "12340";
  char srd[5] = "1234-";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}
END_TEST

START_TEST(memcmp_3) {
  char src[5] = "12341";
  char srd[5] = "1234-";
  int n = 4;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}
END_TEST

START_TEST(memcmp_4) {
  char src[0] = "";
  char srd[0] = "";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(src, srd, n), memcmp(src, srd, n));
}
END_TEST



Suite *suite_s21_memcmp(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_memcmp = tcase_create("memcmp_test");
  suite_add_tcase(suite, tc_memcmp);
  tcase_add_test(tc_memcmp, memcmp_1);
  tcase_add_test(tc_memcmp, memcmp_2);
  tcase_add_test(tc_memcmp, memcmp_3);
  tcase_add_test(tc_memcmp, memcmp_4);


  return suite;
}