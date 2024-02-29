#include "s21_string.h"

int s21_sscanf(const char* str, const char* format, ...) {
  int step = 0;
  int recorded_variables = 0;
  if (str == S21_NULL || format == S21_NULL) return -1;
  char* f = S21_NULL;
  char* s = S21_NULL;
  f = (char*)format;
  s = (char*)str;
  va_list args;
  va_start(args, format);
  start_processing(s, f, args, &step, &recorded_variables);
  va_end(args);
  return recorded_variables;
}

int struct_init(char** s, char** f, options* opts, int* step, int* recorded,
                va_list args) {
  char* buffer = S21_NULL;
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  while (**f != '\0') {
    if (is_digit(**f)) {
      while (is_digit(**f)) {
        str_plus_char(*f, buffer);
        *f += 1;
      }
      opts->width = (int)s21_strtol(buffer, S21_NULL, 8);
      *buffer = '\0';
    } else if (**f == 'h') {
      opts->length = 1;
      *f += 1;
    } else if (**f == 'l') {
      opts->length = 2;
      *f += 1;
    } else if (**f == 'L') {
      opts->length = 3;
      *f += 1;
    } else if (is_specifier_sscanf(**f)) {
      opts->spec = 1;
      spec_handling(s, f, opts, step, recorded, args);
      s21_memset(opts, 0, sizeof(options));
      *f += 1;
    } else if (**f == '*') {
      opts->star = 1;
      *f += 1;
    } else if (**f == '%') {
      *f += 1;
      if (**f == '%') spec_handling(s, f, opts, step, recorded, args);
    } else {
      *f += 1;
    }
  }
  free(buffer);
  return *step;
}

int start_processing(char* s, char* f, va_list args, int* step, int* recorded) {
  while (*f != '\0' && step) {
    if (*f == '%') {
      f++;
      options opts = {0};
      struct_init(&s, &f, &opts, step, recorded, args);
    } else
      f++;
  }
  return *step;
}

int spec_handling(char** s, char** f, options* opts, int* step, int* recorded,
                  va_list args) {
  switch (**f) {
    case 's':
      spec_s(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'c':
      spec_c(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'd':
    case 'i':
      spec_d_i(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      spec_f_e_E_g_G(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'u':
      spec_u(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'x':
    case 'X':
      spec_x_X(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'p':
      spec_p(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'o':
      spec_o(s, opts, step, args);
      if (!opts->star) *recorded += 1;
      break;
    case 'n':
      spec_n(s, step, args);
      break;
    case '%':
      spec_percent(f, step);
      break;
    default:
      break;
  }
  return *step;
}

void str_plus_char(char* ch, char* buffer) {
  char tmp[2];
  tmp[0] = *ch;
  tmp[1] = '\0';
  s21_strcat(buffer, tmp);
}

int spec_s(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  if (!opts->star) {
    buffer = (char*)va_arg(args, char*);
    s21_memset(buffer, 0, s21_strlen(buffer) + 1);
  }
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (**s != ' ' && **s != '\0') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
  }
  return *step;
}

int spec_c(char** s, options* opts, int* step, va_list args) {
  is_space_or_percent(s, step);
  char* buffer = S21_NULL;
  if (!opts->star) {
    buffer = va_arg(args, char*);
    s21_memset(buffer, 0, s21_strlen(buffer) + 1);
    *buffer = **s;
    *step += 1;
  }
  *s += 1;
  return *step;
}

int spec_d_i(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  int* result = NULL;
  if (!opts->star) result = va_arg(args, int*);
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s) || **s == 'x' || **s == 'X' ||
           (**s > 64 && **s < 71) || **s == '-') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
    if (!opts->star) {
      convert_to_int(buffer, result, opts);
    }
  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
  }
  if (!opts->star) {
    convert_to_int(buffer, result, opts);
  }
  free(buffer);
  return *step;
}

void convert_to_int(char* buffer, int* result, options* opts) {
  if (buffer[0] == '0' && (buffer[1] == 'x' || buffer[1] == 'X'))
    if (opts->length == 1)
      *result = (unsigned short int)s21_strtol(buffer, S21_NULL, 16);
    else if (opts->length == 2)
      *result = (unsigned long int)s21_strtol(buffer, S21_NULL, 16);
    else
      *result = s21_strtol(buffer, S21_NULL, 16);
  else if (buffer[0] == '0' && is_digit_o(buffer[1]))
    if (opts->length == 1)
      *result = (unsigned short int)s21_strtol(buffer, S21_NULL, 8);
    else if (opts->length == 2)
      *result = (unsigned long int)s21_strtol(buffer, S21_NULL, 8);
    else
      *result = s21_strtol(buffer, S21_NULL, 8);
  else
    *result = (int)s21_strtol(buffer, S21_NULL, 10);
}

int spec_f_e_E_g_G(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s) || **s == '.' || **s == '-' || **s == '+' ||
           **s == 'e' || **s == 'E') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
    if (!opts->star) {
      if (opts->length == 3)
        *(long double*)va_arg(args, long double*) =
            (long double)s21_atold(buffer);
      else if (opts->length == 2)
        *(double*)va_arg(args, double*) = s21_atold(buffer);
      else {
        *(float*)va_arg(args, float*) = (float)s21_atold(buffer);
      }
    }
  } else {
    while (**s != ' ' && **s != '\0') {
      while (opts->width > 0) {
        if (!opts->star) {
          str_plus_char(*s, buffer);
          *step += 1;
        }
        *s += 1;
        opts->width--;
      }
      *s += 1;
    }
    if (!opts->star) {
      if (opts->length == 3)
        *(long double*)va_arg(args, long double*) =
            (long double)s21_atold(buffer);
      else
        *(float*)va_arg(args, float*) = s21_atold(buffer);
    }
  }
  free(buffer);
  return *step;
}

int spec_u(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s) || (**s > 64 && **s < 71)) {
      if (!opts->star) str_plus_char(*s, buffer);
      *s += 1;
      *step += 1;
    }
    if (opts->length == 1)
      *(unsigned short*)va_arg(args, unsigned short*) =
          (unsigned short)s21_strtol(buffer, S21_NULL, 10);
    else if (opts->length == 2)
      *(unsigned long*)va_arg(args, unsigned long*) =
          (unsigned long)s21_strtol(buffer, S21_NULL, 10);
    else
      *(unsigned*)va_arg(args, unsigned*) =
          (unsigned)s21_strtol(buffer, S21_NULL, 10);
  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
    if (!opts->star) {
      *(unsigned*)va_arg(args, unsigned*) =
          (unsigned)s21_strtol(buffer, S21_NULL, 10);
    }
  }
  free(buffer);
  return *step;
}

int spec_x_X(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s) || **s == 'x' || **s == 'X' ||
           (**s > 64 && **s < 71) || (**s > 96 && **s < 103)) {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
    if (opts->length == 1)
      *(unsigned short int*)va_arg(args, unsigned short int*) =
          (unsigned short int)s21_strtol(buffer, S21_NULL, 16);
    else if (opts->length == 2)
      *(unsigned long*)va_arg(args, unsigned long*) =
          (unsigned long)s21_strtol(buffer, S21_NULL, 16);
    else
      *(unsigned*)va_arg(args, unsigned*) =
          (unsigned)s21_strtol(buffer, S21_NULL, 16);

  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
    if (!opts->star) {
      if (opts->length == 1)
        *(unsigned short int*)va_arg(args, unsigned short int*) =
            (unsigned short int)s21_strtol(buffer, S21_NULL, 16);
      else if (opts->length == 2)
        *(unsigned long*)va_arg(args, unsigned long*) =
            (unsigned long)s21_strtol(buffer, S21_NULL, 16);
      else
        *(unsigned*)va_arg(args, unsigned*) =
            (unsigned)s21_strtol(buffer, S21_NULL, 16);
    }
  }
  free(buffer);
  return *step;
}

int spec_o(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  unsigned* result;
  if (!opts->star) result = va_arg(args, unsigned*);
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s)) {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
    if (opts->length == 1)
      *result = (unsigned short int)s21_strtol(buffer, S21_NULL, 8);
    else if (opts->length == 2)
      *result = (unsigned long int)s21_strtol(buffer, S21_NULL, 8);
    else
      *result = s21_strtol(buffer, S21_NULL, 8);
  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
    if (!opts->star) {
      if (opts->length == 1)
        *result = (unsigned short int)s21_strtol(buffer, S21_NULL, 8);
      else if (opts->length == 2)
        *result = (unsigned long int)s21_strtol(buffer, S21_NULL, 8);
      else
        *result = s21_strtol(buffer, S21_NULL, 8);
    }
  }
  free(buffer);
  return *step;
}

int spec_p(char** s, options* opts, int* step, va_list args) {
  char* buffer = S21_NULL;
  void** result = S21_NULL;
  if (!opts->star) result = va_arg(args, void**);
  buffer = calloc((s21_strlen(*s) + 10), sizeof(char));
  is_space_or_percent(s, step);
  if (opts->width == 0) {
    while (is_digit(**s) || **s == 'x' || (**s > 64 && **s < 71) ||
           (**s > 96 && **s < 103)) {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
    }
    *result = (void*)s21_strtol(buffer, S21_NULL, 16);
  } else {
    while (opts->width > 0 && **s != ' ') {
      if (!opts->star) {
        str_plus_char(*s, buffer);
        *step += 1;
      }
      *s += 1;
      opts->width--;
    }
    if (!opts->star) {
      *result = (void*)s21_strtol(buffer, S21_NULL, 16);
    }
  }
  free(buffer);
  return *step;
}

int spec_n(char** s, int* step, va_list args) {
  is_space_or_percent(s, step);
  int* result;
  result = va_arg(args, int*);
  *result = *step;
  return *step;
}

int spec_percent(char** f, int* step) {
  *f += 1;
  return *step;
}

void is_space_or_percent(char** s, int* step) {
  while ((**s >= 9 && **s <= 13) || (**s == 32) || **s == '%') {
    *s += 1;
    *step += 1;
  }
}

long long s21_strtol(const char* nptr, char** endptr, int base) {
  const char* st;
  unsigned long acc = 0;
  char c = 0;
  unsigned long cutoff = 0;
  int neg = 0, any = 0, cutlim = 0;
  st = nptr;
  do {
    c = *st++;
  } while (c == ' ');
  if ((base == 0 || base == 16) && c == '0' && (*st == 'x' || *st == 'X')) {
    c = st[1];
    st += 2;
    base = 16;
  }
  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  for (acc = 0, any = 0;; c = *st++) {
    if (c >= '0' && c <= '9')
      c -= '0';
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      c -= (c >= 'A' && c <= 'Z') ? 'A' - 10 : 'a' - 10;
    else
      break;
    if (c >= base) break;
    if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
  }
  if (endptr != 0) *endptr = (char*)(any ? st - 1 : nptr);
  return (acc);
}

long double s21_atold(const char* str) {
  long double a = 0.0;
  int e = 0;
  int c = 0;
  long double sign = 1.0;
  int cnt = 0;

  if (*str == '+') ++str;
  if (*str == '-') {
    sign = -1.0;
    str++;
  }

  while ((c = *str++) != '\0' && (c >= '0' && c <= '9')) {
    a = a * (long double)10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *str++) != '\0' && (c >= '0' && c <= '9')) {
      a = a * (long double)10.0 + (c - '0');
      e = e - 1;
    }
  }
  if (c == 'e' || c == 'E') {
    long double i = 0;
    long double e_sign = 1.;
    c = *str++;
    if (c == '+')
      c = *str++;
    else if (c == '-') {
      c = *str++;
      e_sign = -1.;
    }
    while ((c >= '0' && c <= '9')) {
      i = i * (long double)10 + (c - '0');
      c = *str++;
    }
    e += i * e_sign;
  }
  while (e > 0) {
    a *= (long double)10.0;
    e--;
  }
  while (e < 0) {
    a *= (long double)0.1;
    e++;
    cnt++;
  }
  a = floorl(a * (long double)pow(10, cnt)) / (long double)pow(10, cnt);
  a *= sign;
  return a;
}
