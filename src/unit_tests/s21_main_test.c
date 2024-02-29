#include "s21_main_test.h"

void run_tests(void) {
  Suite *list_cases[] = {suite_s21_insert(),  suite_s21_memchr(),
                         suite_s21_memcmp(),  suite_s21_memcpy(),
                         suite_s21_memset(),  suite_s21_sprintf(),
                         suite_s21_sscanf(),  suite_s21_strchr(),
                         suite_s21_strcspn(), suite_s21_strerror(),
                         suite_s21_strlen(),  suite_s21_strncat(),
                         suite_s21_strncmp(), suite_s21_strncpy(),
                         suite_s21_strpbrk(), suite_s21_strrchr(),
                         suite_s21_strstr(),  suite_s21_strtok(),
                         suite_s21_lower(),   suite_s21_upper(),
                         suite_s21_trim(),    NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 0) putchar('\n');
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

int main(void) {
  run_tests();
  return 0;
}