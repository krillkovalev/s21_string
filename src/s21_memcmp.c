#include "s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  const unsigned char* p1 = str1;
  const unsigned char* p2 = str2;
  int diff = 0;

  while (n-- > 0) {
    if ((*p1) != (*p2)) {
      diff = *p1 - *p2;
      break;
    }
    p1++;
    p2++;
  }

  return diff;
}