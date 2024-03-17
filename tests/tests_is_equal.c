#include "../test_includes/s21_tests.h"

START_TEST(is_equal_case_1) {
  s21_decimal dec1 = {{123456u, 654u, 0x00, 80000000}};
  s21_decimal dec2 = {{123456u, 654u, 0x00, 80000000}};
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_equal_case_2) {
  s21_decimal dec1 = {{123456u, 654u, 0x00, 80000000}};
  s21_decimal dec2 = {{123456u, 654u, 0x00, 80000000}};
  set_sign(&dec1, 1);
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_equal_case_3) {
  s21_decimal dec1 = {{123457u, 654u, 0x00, 80000000}};
  s21_decimal dec2 = {{123456u, 654u, 0x00, 80000000}};
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_equal_case_4) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};

  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_equal_case_6) {
  s21_decimal dec1 = {{0xAF000000, 0x94D13D54, 0x004158E6, 0x0}};
  s21_decimal dec2 = {{0x000000FF, 0x0, 0x0, 0x00020000}};
  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *suite_is_equal(void) {
  Suite *s = suite_create("\033[1;31m--is equal--\033[m");
  TCase *tc = tcase_create("is equal");

  tcase_add_test(tc, is_equal_case_1);
  tcase_add_test(tc, is_equal_case_2);
  tcase_add_test(tc, is_equal_case_3);
  tcase_add_test(tc, is_equal_case_4);
  tcase_add_test(tc, is_equal_case_6);

  suite_add_tcase(s, tc);

  return s;
}
