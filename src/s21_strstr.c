#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    while (*haystack != '\0') {
      const char *h1 = haystack;
      const char *n1 = needle;
      while (*n1 != '\0' && *h1 == *n1) {
        h1++;
        n1++;
      }
      if (*n1 == '\0') {
        result = (char *)haystack;
        break;
      }
      haystack++;
    }
  }
  return result;
}
