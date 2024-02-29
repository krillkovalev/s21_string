#include "s21_main_test.h"

START_TEST(memcpy_1) {
  char str1[] = "Привет, мир!";
  char str2[50];

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "";
  char str2[50] = "Hello World";

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_3) {
  char str1[1000];
  for (int i = 0; i < 999; i++) {
    str1[i] = 'a';
  }
  str1[999] = '\0';
  char str2[1000];

  ck_assert_ptr_eq(s21_memcpy(str2, str1, strlen(str1) + 1),
                   memcpy(str2, str1, strlen(str1) + 1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "Hello World";
  char str2[50] = "";
  s21_size_t n = 5;
  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "Hello World";
  char str2[50] = "";
  s21_size_t n = 0;
  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_6) {
  char str1[] = "Hello World";
  char str2[50] = "";
  s21_size_t n = strlen(str1) + 1;

  ck_assert_ptr_eq(s21_memcpy(str2, str1, n), memcpy(str2, str1, n));
  ck_assert_mem_eq(str1, str2, n);
}
END_TEST

START_TEST(memcpy_7) {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {0};
  s21_size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

START_TEST(memcpy_8) {
  int arr1[5] = {0};
  int arr2[5] = {1, 2, 3, 4, 5};
  s21_size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

START_TEST(memcpy_9) {
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {0};
  s21_size_t n = sizeof(arr1);
  ck_assert_ptr_eq(s21_memcpy(arr2, arr1, n), memcpy(arr2, arr1, n));
  ck_assert_mem_eq(arr1, arr2, n);
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_memcpy = tcase_create("memcpy_test");
  suite_add_tcase(suite, tc_memcpy);
  tcase_add_test(tc_memcpy, memcpy_1);
  tcase_add_test(tc_memcpy, memcpy_2);
  tcase_add_test(tc_memcpy, memcpy_3);
  tcase_add_test(tc_memcpy, memcpy_4);
  tcase_add_test(tc_memcpy, memcpy_5);
  tcase_add_test(tc_memcpy, memcpy_6);
  tcase_add_test(tc_memcpy, memcpy_7);
  tcase_add_test(tc_memcpy, memcpy_8);
  tcase_add_test(tc_memcpy, memcpy_9);

  return suite;
}
