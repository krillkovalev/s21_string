#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL || src != S21_NULL) {
    s21_size_t length_dest = 0;
    while (dest[length_dest] != '\0') {
      length_dest++;
    }
    s21_size_t length_src = 0;
    while (length_src < n && src[length_src] != '\0') {
      dest[length_dest + length_src] = src[length_src];
      length_src++;
    }
    dest[length_dest + length_src] = '\0';
  }
  return dest;
}
