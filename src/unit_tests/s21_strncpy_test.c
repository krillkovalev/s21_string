#include "s21_main_test.h"

START_TEST(s21_strncpy_func) {
  char dest_1[100] = "Hello, ";
  char dest_2[100] = "";
  char dest_3[100] = "Hello,\nMy";
  char dest_4[100] = "Hello\0,";
  const char src_1[100] = "World!";
  const char src_2[100] = "";
  const char src_3[100] = "World!\nis Mine";
  const char src_4[100] = "World\0!";
  s21_size_t n_1 = 6;
  s21_size_t n_2 = 3;
  s21_size_t n_3 = 0;

  ck_assert_str_eq(strncpy(dest_1, src_1, n_1),
                   s21_strncpy(dest_1, src_1, n_1));
  ck_assert_str_eq(strncpy(dest_1, src_2, n_1),
                   s21_strncpy(dest_1, src_2, n_1));
  ck_assert_str_eq(strncpy(dest_1, src_1, n_2),
                   s21_strncpy(dest_1, src_1, n_2));
  ck_assert_str_eq(strncpy(dest_1, src_1, n_3),
                   s21_strncpy(dest_1, src_1, n_3));
  ck_assert_str_eq(strncpy(dest_2, src_1, n_1),
                   s21_strncpy(dest_2, src_1, n_1));
  ck_assert_str_eq(strncpy(dest_3, src_1, n_1),
                   s21_strncpy(dest_3, src_1, n_1));
  ck_assert_str_eq(strncpy(dest_1, src_3, n_1),
                   s21_strncpy(dest_1, src_3, n_1));
  ck_assert_str_eq(strncpy(dest_2, src_2, n_1),
                   s21_strncpy(dest_2, src_2, n_1));
  ck_assert_str_eq(strncpy(dest_4, src_1, n_1),
                   s21_strncpy(dest_4, src_1, n_1));
  ck_assert_str_eq(strncpy(dest_1, src_4, n_1),
                   s21_strncpy(dest_1, src_4, n_1));
}
END_TEST

Suite *suite_s21_strncpy(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strncpy = tcase_create("Strncpy func");
  suite_add_tcase(suite, tc_strncpy);
  tcase_add_test(tc_strncpy, s21_strncpy_func);

  return suite;
}