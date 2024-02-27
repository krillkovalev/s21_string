#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;
  while (n-- > 0) {
    *d++ = *s++;
  }
  return dest;
}