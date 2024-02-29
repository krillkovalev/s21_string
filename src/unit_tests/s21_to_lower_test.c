#include "s21_main_test.h"

START_TEST(s21_to_lower1_func) {
  const char str[] = "Hello, World MY 99rf!";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello, world my 99rf!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower2_func) {
  const char str[] = "";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_lower3_func) {
  const char str[] = "hello_23";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello_23");
  free(result);
}
END_TEST

START_TEST(s21_to_lower4_func) {
  const char str[] = ",!";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, ",!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower5_func) {
  const char *str = S21_NULL;
  void *result = s21_to_lower(str);
  ck_assert_ptr_eq(result, S21_NULL);
  free(result);
}
END_TEST

Suite *suite_s21_lower(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_to_lower = tcase_create("to_lower_func");
  suite_add_tcase(suite, tc_to_lower);
  tcase_add_test(tc_to_lower, s21_to_lower1_func);
  tcase_add_test(tc_to_lower, s21_to_lower2_func);
  tcase_add_test(tc_to_lower, s21_to_lower3_func);
  tcase_add_test(tc_to_lower, s21_to_lower4_func);
  tcase_add_test(tc_to_lower, s21_to_lower5_func);

  return suite;
}