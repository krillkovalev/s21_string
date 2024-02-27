#include "s21_main_test.h"

START_TEST(test_sscanf_1) {
  char a = '\0', b = '\0', c = '\0', d = '\0';
  int result = 0, result_origin = 0;
  result = s21_sscanf("H e", "%c %c", &a, &b);
  result_origin = sscanf("H e", "%c %c", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

}
END_TEST

START_TEST (test_sscanf_2) {
  char b = '\0', d = '\0';
  int result = 0, result_origin = 0;
  result = s21_sscanf("H e", "%*c %c", &b);
  result_origin = sscanf("H e", "%*c %c", &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST (test_sscanf_3) {
  char str1[512] = {0};
  char str2[512] = {0};

  char str3[512] = {0};
  char str4[512] = {0};

  int result = 0, result_origin = 0;
  result = s21_sscanf("Hello % world ", "%s %% %s", str1, str2);
  result_origin = sscanf("Hello % world ", "%s %% %s", str3, str4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(str1, str3);
  ck_assert_str_eq(str2, str4);
}
END_TEST

START_TEST (test_sscanf_4) {

  int result = 0, result_origin = 0;
  char str1[512] = {0};
  char str2[512] = {0};
  char str3[512] = {0};
  char str4[512] = {0};
  result = s21_sscanf("Today is tuesday", "%3s %*s %5s", str1, str2);
  result_origin =
      sscanf("Today is tuesday", "%3s %*s %5s", str3, str4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(str1, str3);
  ck_assert_str_eq(str2, str4);

}
END_TEST

START_TEST (test_sscanf_5) {
  char str1[512] = {0};
  char str3[512] = {0};
  int result = 0, result_origin = 0;
  result = s21_sscanf("Hello world ", "%s %*s", str1);
  result_origin = sscanf("Hello world ", "%s %*s", str3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(str1, str3);

}
END_TEST

START_TEST (test_sscanf_6) {

  int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;


  int result = 0, result_origin = 0;
  result = s21_sscanf("123 -123 0x1F 077", "%d %*d %i %i", &num1, &num3, &num5);
  result_origin =
      sscanf("123 -123 0x1F 077", "%d %*d %i %i", &num2, &num4, &num6);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(num3, num4);
  ck_assert_int_eq(num5, num6);
}
END_TEST

START_TEST (test_sscanf_7) {
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
  int num5 = 0, num6 = 0, num7 = 0, num8 = 0;
  int result = 0, result_origin = 0;
  result = s21_sscanf("10678 539 0x1FABS 07297", "%2d %1d %5i %4i", &num1,
                      &num2, &num3, &num4);
  result_origin = sscanf("10678 539 0x1FABS 07297", "%2d %1d %5i %4i", &num5,
                         &num6, &num7, &num8);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(num1, num5);
  ck_assert_int_eq(num2, num6);
  ck_assert_int_eq(num3, num7);
  ck_assert_int_eq(num4, num8);

}
END_TEST

START_TEST (test_sscanf_8) {
  int result = 0, result_origin = 0;
  short sh_num_1 = 0, sh_num_2 = 0, sh_num_3 = 0, sh_num_4 = 0, sh_num_5 = 0, sh_num_6 = 0;
  result =
      s21_sscanf("7 0xfff 045", "%hd %hd %hd", &sh_num_1, &sh_num_2, &sh_num_3);
  result_origin =
      s21_sscanf("7 0xfff 045", "%hd %hd %hd", &sh_num_4, &sh_num_5, &sh_num_6);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(sh_num_1, sh_num_4);
  ck_assert_int_eq(sh_num_2, sh_num_5);
  ck_assert_int_eq(sh_num_3, sh_num_6);
}
END_TEST

START_TEST (test_sscanf_9) {
  int result = 0, result_origin = 0;
  long int l_num1 = 0, l_num2 = 0, l_num3 = 0, l_num4 = 0;
  result = s21_sscanf("234567890987654356789 0xDEF", "%ld %li", &l_num1, &l_num2);
  result_origin = s21_sscanf("234567890987654356789 0xDEF", "%ld %li", &l_num3, &l_num4);

  float num_1 = 0., num_2 = 0., num_3 = 0., num_4 = 0., num_5 = 0., num_6 = 0., num_7 = 0.;
  float num_8 = 0., num_9 = 0., num_10 = 0., num_11 = 0., num_12 = 0., num_13 = 0., num_14 = 0.;

  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(l_num1, l_num3);
  ck_assert_int_eq(l_num2, l_num4);

  result = 0, result_origin = 0;
  result = s21_sscanf("3.14567 1.2e4 7.8900e-3 6.00410E2 1.2E-4 0.125 25.123",
                      "%f %e %e %E %E %g %G", &num_1, &num_2, &num_3, &num_4,
                      &num_5, &num_6, &num_7);
  result_origin =
      sscanf("3.14567 1.2e4 7.8900e-3 6.00410E2 1.2E-4 0.125 25.123",
             "%f %e %e %E %E %g %G", &num_8, &num_9, &num_10, &num_11, &num_12,
             &num_13, &num_14);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(num_1, num_8);
  ck_assert_float_eq(num_2, num_9);
  ck_assert_float_eq(num_3, num_10);
  ck_assert_float_eq(num_4, num_11);
  ck_assert_float_eq(num_5, num_12);
  ck_assert_float_eq(num_6, num_13);
  ck_assert_float_eq(num_7, num_14);

}
END_TEST

START_TEST (test_sscanf_10) {
  float num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0;
  int result = 0, result_origin = 0;
  result = s21_sscanf(".1234 -123.123456789", "%e %6e", &num_1, &num_2);
  result_origin = sscanf(".1234 -123.123456789", "%e %6e", &num_3, &num_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(num_1, num_3);
  ck_assert_float_eq(num_2, num_4);

}
END_TEST

START_TEST (test_sscanf_11) {

  float num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0;
  int result = 0, result_origin = 0;
  result = s21_sscanf(".1234 -123.123456789", "%g %g", &num_1, &num_2);
  result_origin = sscanf(".1234 -123.123456789", "%g %g", &num_3, &num_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(num_1, num_3);
  ck_assert_float_eq(num_2, num_4);

}
END_TEST

START_TEST (test_sscanf_12) {

  int result = 0, result_origin = 0;
  unsigned t_1 = 0, t_2 = 0, t_3 = 0, t_4 = 0;
  result = s21_sscanf("1750 0456", "%o %o", &t_1, &t_2);
  result_origin = sscanf("1750 0456", "%o %o", &t_3, &t_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(t_1, t_3);
  ck_assert_int_eq(t_2, t_4);

}
END_TEST

START_TEST (test_sscanf_13) {

  int result = 0, result_origin = 0;
  short int h, g, f, j, y, p;
  result = s21_sscanf("05 016 0890", "%ho %ho %ho", &h, &g, &f);
  result_origin = s21_sscanf("05 016 0890", "%ho %ho %ho", &j, &y, &p);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(h, j);
  ck_assert_int_eq(g, y);
  ck_assert_int_eq(f, p);

}
END_TEST

START_TEST (test_sscanf_14) {

  int result = 0, result_origin = 0;
  long int lng_oct_1 = 0, lng_oct_2 = 0, lng_oct_3 = 0, lng_oct_4 = 0;
  result = s21_sscanf("100 0501", "%lo %lo", &lng_oct_1, &lng_oct_2);
  result_origin = sscanf("100 0501", "%lo %lo", &lng_oct_3, &lng_oct_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_msg(lng_oct_1 == lng_oct_3,
                "lng_oct_1 and lng_oct_3 should be equal");
  ck_assert_msg(lng_oct_2 == lng_oct_4,
                "lng_oct_2 and lng_oct_4 should be equal");

}
END_TEST

START_TEST (test_sscanf_15) {

  int result = 0, result_origin = 0;
  long int lng_oct_1 = 0, lng_oct_2 = 0, lng_oct_3 = 0, lng_oct_4 = 0;
  result = s21_sscanf("100 0501", "%1lo %2lo", &lng_oct_1, &lng_oct_2);
  result_origin = sscanf("100 0501", "%1lo %2lo", &lng_oct_3, &lng_oct_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_msg(lng_oct_1 == lng_oct_3,
                "lng_oct_1 and lng_oct_3 should be equal");
  ck_assert_msg(lng_oct_2 == lng_oct_4,
                "lng_oct_2 and lng_oct_4 should be equal");

}
END_TEST

START_TEST (test_sscanf_16) {

  int result = 0, result_origin = 0;
  unsigned dec_1 = 0, dec_2 = 0, dec_3 = 0, dec_4 = 0;
  result = s21_sscanf("125 0", "%u %u", &dec_1, &dec_2);
  result_origin = sscanf("125 0", "%u %u", &dec_3, &dec_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(dec_1, dec_3);
  ck_assert_int_eq(dec_2, dec_4);

}
END_TEST

START_TEST (test_sscanf_17) {

  int result = 0, result_origin = 0;
  unsigned short dec_5, dec_6;
  result = s21_sscanf("386", "%hu", &dec_5);
  result_origin = sscanf("386", "%hu", &dec_6);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(dec_5, dec_6);

}
END_TEST

START_TEST (test_sscanf_18) {

  int result = 0, result_origin = 0;
  unsigned long lng_u_1 = 0, lng_u_2 = 0;
  result = s21_sscanf("123456789", "%lu", &lng_u_1);
  result_origin = sscanf("123456789", "%lu", &lng_u_2);
  ck_assert_int_eq(result, result_origin);
  ck_assert_msg(lng_u_1 == lng_u_2, "lng_u_1 and lng_u_2 should be equal");

}
END_TEST

START_TEST (test_sscanf_19) {

  int result = 0, result_origin = 0;
  unsigned dec_1 = 0, dec_2 = 0, dec_3 = 0, dec_4 = 0;
  result = s21_sscanf("125678 498", "%4u %2u", &dec_1, &dec_2);
  result_origin = sscanf("125678 498", "%4u %2u", &dec_3, &dec_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(dec_1, dec_3);
  ck_assert_int_eq(dec_2, dec_4);

}
END_TEST

START_TEST (test_sscanf_20) {

  int result = 0, result_origin = 0;
  unsigned hex_1, hex_2, hex_3, hex_4;
  result = s21_sscanf("0x5A3 0Xfffff", "%x %X", &hex_1, &hex_2);
  result_origin = sscanf("0x5A3 0Xfffff", "%x %X", &hex_3, &hex_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(hex_1, hex_3);
  ck_assert_int_eq(hex_2, hex_4);

}
END_TEST


START_TEST (test_sscanf_21) {

  int result = 0, result_origin = 0;
  unsigned hex_1 = 0, hex_2 = 0, hex_3 = 0, hex_4 = 0;
  result = s21_sscanf("5A3D fe4a", "%2x %3X", &hex_1, &hex_2);
  result_origin = sscanf("5A3D fe4a", "%2x %3X", &hex_3, &hex_4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(hex_1, hex_3);
  ck_assert_int_eq(hex_2, hex_4);

}
END_TEST

START_TEST (test_sscanf_22) {

  int result = 0, result_origin = 0;
  short unsigned hex_5, hex_6, hex_7, hex_8;
  result = s21_sscanf("0x4C5 0XFF", "%hx %hX", &hex_5, &hex_6);
  result_origin = sscanf("0x4C5 0XFF", "%hx %hX", &hex_7, &hex_8);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(hex_5, hex_7);
  ck_assert_int_eq(hex_6, hex_8);

}
END_TEST

START_TEST (test_sscanf_23) {

  int result = 0, result_origin = 0;
  short unsigned hex_5 = 0, hex_6 = 0, hex_7 = 0, hex_8 = 0;
  result = s21_sscanf("0x4C5 0XFFAB", "%4hx %4hX", &hex_5, &hex_6);
  result_origin = sscanf("0x4C5 0XFFAB", "%4hx %4hX", &hex_7, &hex_8);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(hex_5, hex_7);
  ck_assert_int_eq(hex_6, hex_8);

}
END_TEST


START_TEST (test_sscanf_24) {

  int result = 0, result_origin = 0;
  long unsigned hex_9 = 0, hex_10 = 0, hex_11 = 0, hex_12 = 0;
  result = s21_sscanf("0x1A45F0DA 0X141F", "%lx %lX", &hex_9, &hex_10);
  result_origin = sscanf("0x1A45F0DA 0X141F", "%lx %lX", &hex_11, &hex_12);
  ck_assert_int_eq(result, result_origin);
  ck_assert_msg(hex_9 == hex_11, "hex_9 and hex_11 should be equal");
  ck_assert_msg(hex_10 == hex_12, "hex_10 and hex_12 should be equal");

}
END_TEST


START_TEST (test_sscanf_25) {

  int result = 0, result_origin = 0;
  long unsigned hex_9 = 0, hex_10 = 0, hex_11 = 0, hex_12 = 0;
  result = s21_sscanf("0x1A45F0DA 0X141F", "%6lx %3lX", &hex_9, &hex_10);
  result_origin = sscanf("0x1A45F0DA 0X141F", "%6lx %3lX", &hex_11, &hex_12);
  ck_assert_int_eq(result, result_origin);
  ck_assert_msg(hex_9 == hex_11, "hex_9 and hex_11 should be equal");
  ck_assert_msg(hex_10 == hex_12, "hex_10 and hex_12 should be equal");

}
END_TEST

START_TEST (test_sscanf_26) {

  int result = 0, result_origin = 0;
  char *str = "0xAAAA 0xFFFF 0xBC431";
  char *format = "%p %p %p";
  void *a1 = S21_NULL, *a2 = S21_NULL, *b1 = S21_NULL, *b2 = S21_NULL,
       *c1 = S21_NULL, *c2 = S21_NULL;

  result = s21_sscanf(str, format, &a1, &b1, &c1);
  result_origin = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_int_eq(result, result_origin);

}
END_TEST

START_TEST (test_sscanf_27) {
  char *str = "0xAAAA 0xFFFF 0xBC431";
  int result = 0, result_origin = 0;
  void *a1 = S21_NULL, *a2 = S21_NULL, *b1 = S21_NULL, *b2 = S21_NULL, *c1 = S21_NULL, *c2 = S21_NULL;
  char *format = "%4p %4p %5p";
  result = s21_sscanf(str, format, &a1, &b1, &c1);
  result_origin = sscanf(str, format, &a2, &b2, &c2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_int_eq(result, result_origin);

}
END_TEST

START_TEST (test_sscanf_28) {

  char str_n[1024] = {0}, str_n_orig[1024] = {0};
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
  char a = '\0', b = '\0';
  int result = s21_sscanf("aboba % 1567 @", "%s  %% %d %c %n", str_n, &num1, &a, &num2);
  int result_origin = sscanf("aboba % 1567 @", "%s %% %d %c %n", str_n_orig, &num3, &b, &num4);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(str_n, str_n_orig);
  ck_assert_int_eq(num1, num3);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(num2, num4);
}
END_TEST



Suite *suite_s21_sscanf(void) {
  Suite *suite;
  suite = suite_create("Sscanf_test");

  TCase *tc_sscanf = tcase_create("Sscanf func");
  suite_add_tcase(suite, tc_sscanf);

  tcase_add_test(tc_sscanf, test_sscanf_1);
  tcase_add_test(tc_sscanf, test_sscanf_2);
  tcase_add_test(tc_sscanf, test_sscanf_3);
  tcase_add_test(tc_sscanf, test_sscanf_4);
  tcase_add_test(tc_sscanf, test_sscanf_5);
  tcase_add_test(tc_sscanf, test_sscanf_6);
  tcase_add_test(tc_sscanf, test_sscanf_7);
  tcase_add_test(tc_sscanf, test_sscanf_8);
  tcase_add_test(tc_sscanf, test_sscanf_9);
  tcase_add_test(tc_sscanf, test_sscanf_10);
  tcase_add_test(tc_sscanf, test_sscanf_11);
  tcase_add_test(tc_sscanf, test_sscanf_12);
  tcase_add_test(tc_sscanf, test_sscanf_13);
  tcase_add_test(tc_sscanf, test_sscanf_14);
  tcase_add_test(tc_sscanf, test_sscanf_15);
  tcase_add_test(tc_sscanf, test_sscanf_16);
  tcase_add_test(tc_sscanf, test_sscanf_17);
  tcase_add_test(tc_sscanf, test_sscanf_18);
  tcase_add_test(tc_sscanf, test_sscanf_19);
  tcase_add_test(tc_sscanf, test_sscanf_20);
  tcase_add_test(tc_sscanf, test_sscanf_21);
  tcase_add_test(tc_sscanf, test_sscanf_22);
  tcase_add_test(tc_sscanf, test_sscanf_23);
  tcase_add_test(tc_sscanf, test_sscanf_24);
  tcase_add_test(tc_sscanf, test_sscanf_25);
  tcase_add_test(tc_sscanf, test_sscanf_26);
  tcase_add_test(tc_sscanf, test_sscanf_27);
  tcase_add_test(tc_sscanf, test_sscanf_28);

  return suite;
}