#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_entry = S21_NULL;
  while (*str) {
    if (*str == c) {
      last_entry = str;
    }
    str++;
  }
  if (c == '\0') {
    last_entry = str;
  }
  return (char *)last_entry;
}