#include "../test_includes/s21_tests.h"

START_TEST(is_greater_or_equal_case_1) {
  // float num1 = 5.355;
  // float num2 = 5.35;
  s21_decimal dec1 = {{0x000014EB, 0x0, 0x0, 0x00030000}};
  s21_decimal dec2 = {{0x00000217, 0x0, 0x0, 0x00020000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_2) {
  // float num1 = 5.345678344;
  // float num2 = 5.35;
  s21_decimal dec1 = {{0x3EA09408, 0x00000001, 0x0, 0x00090000}};
  s21_decimal dec2 = {{0x00000217, 0x0, 0x0, 0x00020000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_greater_or_equal_case_3) {
  // float num1 = 5.35;
  // float num2 = 5.35;
  s21_decimal dec1 = {{0x00000217, 0x0, 0x0, 0x00020000}};
  s21_decimal dec2 = {{0x00000217, 0x0, 0x0, 0x00020000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_4) {
  // float num1 = 5.35;
  // float num2 = -5.35;
  s21_decimal dec1 = {{0x00000217, 0x0, 0x0, 0x00020000}};
  s21_decimal dec2 = {{0x00000217, 0x0, 0x0, 0x80020000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_5) {
  // int num1 = 0;
  // int num2 = 0;
  s21_decimal dec1 = {0}, dec2 = {0};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_6) {
  // int num1 = 3;
  // int num2 = 55;
  s21_decimal dec1 = {{0x00000003, 0x0, 0x0, 0x0}};
  s21_decimal dec2 = {{0x00000037, 0x0, 0x0, 0x0}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(is_greater_or_equal_case_7) {
  // int num1 = -55;
  // int num2 = -55;
  s21_decimal dec1 = {{0x00000037, 0x0, 0x0, 0x80000000}};
  s21_decimal dec2 = {{0x00000037, 0x0, 0x0, 0x80000000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_8) {
  // float num1 = -5.35456754356;
  // float num2 = -55.35345673456;
  s21_decimal dec1 = {{0x77922674, 0x0000000C, 0x0, 0x800A0000}};
  s21_decimal dec2 = {{0xCC5004F0, 0x00000508, 0x0, 0x800B0000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_9) {
  s21_decimal dec1 = {{0x00003039, 0x0, 0x0, 0x80040000}};  // -1.2345
  s21_decimal dec2 = {{0x0000000C, 0x0, 0x0, 0x80010000}};  //  -1.2;
  ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 1);
}
END_TEST

START_TEST(is_greater_or_equal_case_10) {
  // float num1 = -535456.754356;
  // float num2 = -535456754.356;
  s21_decimal dec1 = {{0xABB5AAB4, 0x0000007C, 0x0, 0x80060000}};  // -1.2345
  s21_decimal dec2 = {{0xABB5AAB4, 0x0000007C, 0x0, 0x80030000}};
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *suite_is_greater_or_equal(void) {
  Suite *s = suite_create("\033[1;31m--is greater or equal--\033[m");
  TCase *tc = tcase_create("is greater or equal");

  tcase_add_test(tc, is_greater_or_equal_case_1);
  tcase_add_test(tc, is_greater_or_equal_case_2);
  tcase_add_test(tc, is_greater_or_equal_case_3);
  tcase_add_test(tc, is_greater_or_equal_case_4);
  tcase_add_test(tc, is_greater_or_equal_case_5);
  tcase_add_test(tc, is_greater_or_equal_case_6);
  tcase_add_test(tc, is_greater_or_equal_case_7);
  tcase_add_test(tc, is_greater_or_equal_case_8);
  tcase_add_test(tc, is_greater_or_equal_case_9);
  tcase_add_test(tc, is_greater_or_equal_case_10);

  suite_add_tcase(s, tc);

  return s;
}
