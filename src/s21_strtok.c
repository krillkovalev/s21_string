#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *token_buffer;
  if (str != S21_NULL) token_buffer = str;
  if (token_buffer == S21_NULL) return S21_NULL;
  while (*token_buffer && s21_strchr(delim, *token_buffer)) {
    ++token_buffer;
  }
  if (*token_buffer == '\0') {
    return S21_NULL;
  }
  char *start = token_buffer;
  while (*token_buffer && !s21_strchr(delim, *token_buffer)) {
    token_buffer++;
  }
  if (*token_buffer) {
    *token_buffer = '\0';
    token_buffer++;
  }
  return start;
}
