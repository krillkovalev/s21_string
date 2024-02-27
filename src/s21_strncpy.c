#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t length;
  for (length = 0; length < n && src[length] != '\0'; length++) {
    dest[length] = src[length];
  }
  for (; length < n; length++) {
    dest[length] = '\0';
  }
  return dest;
}