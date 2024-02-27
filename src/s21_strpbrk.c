#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  while (*str1 != '\0' && result == S21_NULL) {
    const char *temp = str2;
    while (*temp != '\0' && result == S21_NULL) {
      if (*temp == *str1) {
        result = (char *)str1;
      }
      temp++;
    }
    str1++;
  }
  return result;
}