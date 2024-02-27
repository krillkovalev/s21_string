#ifndef __S21_STRING__
#define __S21_STRING__

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL (void *)0
#define s21_size_t unsigned long long

#define UNKNOWN "Unknown error: "

#define is_flag(ch) \
  ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '#' || (ch) == '0')

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

#define is_length(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define is_specifier(ch)                                                      \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'f' || (ch) == 'g' || (ch) == 'G' || (ch) == 'o' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'x' || (ch) == 'X' || (ch) == 'p' || (ch) == 'n' || \
   (ch) == '%')

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);

/*----------------------------SSCANF------------------------------*/

typedef struct {
  int width;
  int star;
  int length;
  int spec;
  int cnt;
} options;

#define BUFF_SIZE 1024
#define is_specifier_sscanf(ch)                                               \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'f' || (ch) == 'g' || (ch) == 'G' || (ch) == 'o' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'x' || (ch) == 'X' || (ch) == 'p' || (ch) == 'n')

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')
#define is_digit_o(ch) ((ch) >= '0' && (ch) <= '7')
#define is_star(ch) (ch == '*')

int s21_sscanf(const char *str, const char *format, ...);
int struct_init(char **s, char **f, options *opts, int *step, int *recorded,
                va_list args);
int start_processing(char *s, char *f, va_list args, int *step, int *recorded);
int spec_handling(char **s, char **f, options *opts, int *step, int *recorded,
                  va_list args);
int spec_s(char **s, options *opts, int *step, va_list args);
int spec_c(char **s, options *opts, int *step, va_list args);
void str_plus_char(char *ch, char *buffer);
int spec_d_i(char **s, options *opts, int *step, va_list args);
void convert_to_int(char *buffer, int *result, options *opts);
int spec_f_e_E_g_G(char **s, options *opts, int *step, va_list args);
void is_space_or_percent(char **s, int *step);
int spec_u(char **s, options *opts, int *step, va_list args);
int spec_x_X(char **s, options *opts, int *step, va_list args);
int spec_p(char **s, options *opts, int *step, va_list args);
int spec_o(char **s, options *opts, int *step, va_list args);
int spec_n(char **s, int *step, va_list args);
int spec_percent(char **f, int *step);
long long s21_strtol(const char *nptr, char **endptr, register int base);
long double s21_atold(const char *str);

/*----------------------------SPRINTF------------------------------*/

typedef struct format_part {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_sharp;
  int flag_zero;
  int width;
  int precision;
  char length;
  char specifier;
  int sign;
  int point;
} format_part;

int s21_sprintf(char *str, const char *format, ...);

void sprintf_check_flag(format_part *parameters, const char *format);

void sprintf_default_precision(format_part *parameters);
char *sprintf_check_specifier(char *str, s21_size_t *str_len, va_list *args,
                              format_part *parameters);
void sprintf_move_string(char *string_from_cs);
void sprintf_reverse_str(char *string_from_cs);
void sprintf_make_str_precision(format_part *parameters, char *string_from_cs);

char *sprintf_str_int(int *number, const char *format, va_list *args);
void sprintf_int_str(format_part *parameters, char *string_from_cs,
                     long double number);
void sprintf_eE_str(char *string_from_cs, long double number,
                    format_part *parameters);
void sprintf_float_str(char *string_from_cs, long double number,
                       format_part *parameters);
void sprintf_gG_str(char *string_from_cs, long double number,
                    format_part *parameters);
void sprintf_ol_str(char *string_from_cs, unsigned long long number,
                    int prefix);
void sprintf_ul_str(char *string_from_cs, unsigned long long number,
                    format_part *parameters);
void sprintf_hl_str(char *string_from_cs, unsigned long long number,
                    format_part *parameters);

void sprintf_make_str_flags(format_part *parameters, char *string_from_cs);
void sprintf_make_str_width(format_part *parameters, char *string_from_cs);

void sprintf_spec_di(char *string_from_cs, va_list *args,
                     format_part *parameters);
void sprintf_spec_eE(char *string_from_cs, va_list *args,
                     format_part *parameters);
void sprintf_spec_f(char *string_from_cs, va_list *args,
                    format_part *parameters);
void sprintf_spec_gG(char *string_from_cs, va_list *args,
                     format_part *parameters);
void sprintf_spec_o(char *string_from_cs, va_list *args,
                    format_part *parameters);
void sprintf_spec_p(char *string_from_cs, va_list *args,
                    format_part *parameters);
void sprintf_spec_s(char *string_from_cs, va_list *args,
                    format_part *parameters);
void sprintf_spec_u(char *string_from_cs, va_list *args,
                    format_part *parameters);
void sprintf_spec_xX(char *string_from_cs, va_list *args,
                     format_part *parameters);

void sprintf_sharp_flag(format_part *parameters, char *string_from_cs);
void sprintf_delete_zero(format_part *parameters, char *string_from_cs);
void sprintf_mantissa(format_part *parameters, char *mantice, int notation);

int sprintf_make_expo(long double number);
void sprintf_make_sign(double number, format_part *parameters);

#endif
