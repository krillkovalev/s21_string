#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  while (n-- > 0) {
    if (*p == (unsigned char)c) {
      return (void *)p;
    }
    p++;
  }

  return S21_NULL;
}