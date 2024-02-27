#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t countlength = 0;
  int matchfound = 0;
  if (str1 && str2) {
    while (str1[countlength] != '\0' && !matchfound) {
      const char *scansymbol = str2;
      while (*scansymbol != '\0' && !matchfound) {
        if (str1[countlength] == *scansymbol) {
          matchfound = 1;
        } else {
          scansymbol++;
        }
      }
      if (!matchfound) {
        countlength++;
      }
    }
  }
  return countlength;
}
