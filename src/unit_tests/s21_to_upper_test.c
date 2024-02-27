#include "s21_main_test.h"

START_TEST(s21_to_upper1_func) {
  const char str[] = "Hello, World MY 99rf!";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD MY 99RF!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper2_func) {
  const char str[] = "";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_upper3_func) {
  const char str[] = "HELLO_23";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO_23");
  free(result);
}
END_TEST

START_TEST(s21_to_upper4_func) {
  const char str[] = ",!";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, ",!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper5_func) {
  const char *str = S21_NULL;
  void *result = s21_to_upper(str);
  ck_assert_ptr_eq(result, S21_NULL);
  free(result);
}
END_TEST



Suite *suite_s21_upper(void) {
  Suite *suite;
  suite = suite_create("Functions checking");


  TCase *tc_to_upper = tcase_create("to_upper_func");
  suite_add_tcase(suite, tc_to_upper);
  tcase_add_test(tc_to_upper, s21_to_upper1_func);
  tcase_add_test(tc_to_upper, s21_to_upper2_func);
  tcase_add_test(tc_to_upper, s21_to_upper3_func);
  tcase_add_test(tc_to_upper, s21_to_upper4_func);
  tcase_add_test(tc_to_upper, s21_to_upper5_func);


  return suite;
}