#include "s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && str1[i] == str2[i]) {
    i++;
  }
  if (i < n) {
    return str1[i] - str2[i];

  } else {
    return 0;
  }
}