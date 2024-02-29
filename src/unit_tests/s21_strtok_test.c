#include "s21_main_test.h"

START_TEST(s21_strtok1_func) {
  char str1[100] = "Hi, Divide this string ,/ please / ok";
  char str2[100] = "";
  char str3[100] = "He\0llo,23";
  char str4[100] = ", Divide me";
  char str5[100] = "Divide me, ";
  const char delim1[100] = ",";
  const char delim2[100] = "";
  const char delim3[100] = ",/i";
  const char delim4[100] = "ie\0,";

  ck_assert_str_eq(strtok(str1, delim1), s21_strtok(str1, delim1));
  ck_assert_str_eq(strtok(str1, delim3), s21_strtok(str1, delim3));
  ck_assert_str_eq(strtok(str1, delim2), s21_strtok(str1, delim2));
  ck_assert_ptr_eq(strtok(str2, delim1), s21_strtok(str2, delim1));
  ck_assert_str_eq(strtok(str3, delim1), s21_strtok(str3, delim1));
  ck_assert_str_eq(strtok(str1, delim4), s21_strtok(str1, delim4));
  ck_assert_str_eq(strtok(str4, delim1), s21_strtok(str4, delim1));
  ck_assert_ptr_eq(strtok(str5, delim1), s21_strtok(str5, delim1));
}
END_TEST

START_TEST(s21_strtok2_func) {
  char str[100] = "No delimiters here";
  ck_assert_ptr_eq(s21_strtok(str, ""), strtok(str, ""));
}
END_TEST

START_TEST(s21_strtok3_func) {
  char str[100] = "token1,token2";
  char delim[10] = ",";
  s21_strtok(str, delim);
  s21_strtok(S21_NULL, delim);
}
END_TEST

START_TEST(s21_strtok4_func) {
  char *token = s21_strtok(S21_NULL, ",");
  ck_assert_ptr_null(token);
}
END_TEST

Suite *suite_s21_strtok(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_strtok = tcase_create("strtok_func");
  suite_add_tcase(suite, tc_strtok);
  tcase_add_test(tc_strtok, s21_strtok1_func);
  tcase_add_test(tc_strtok, s21_strtok2_func);
  tcase_add_test(tc_strtok, s21_strtok3_func);
  tcase_add_test(tc_strtok, s21_strtok4_func);

  return suite;
}