#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (s21_size_t i = 0; str[i]; i++) {
    if (str[i] == (char)c) {
      return (char *)&str[i];
    }
  }
  return S21_NULL;
}
