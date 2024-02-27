#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t len = s21_strlen(str);
  void *result = calloc(len + 1, sizeof(char));
  if (result != S21_NULL) {
    char *lower_str = (char *)result;
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        lower_str[i] = str[i] + ('a' - 'A');
      } else {
        lower_str[i] = str[i];
      }
    }
  }
  return result;
}