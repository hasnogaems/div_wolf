#include "../test_includes/s21_tests.h"

START_TEST(sub_int_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 21);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_int_2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 25);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_int_3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 25);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(sub_int_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 21);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(sub_float_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147680256);
}
END_TEST

START_TEST(sub_float_2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 43);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147680256);
}
END_TEST

START_TEST(sub_float_3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 43);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 196608);
}
END_TEST

START_TEST(sub_float_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 196608);
}
END_TEST

START_TEST(sub_inf) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  set_sign(&value_2, 1);
  int code;
  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(sub_neg_inf) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *s = suite_create("\033[1;31m--SUB--\033[m");
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, sub_int_1);
  tcase_add_test(tc, sub_int_2);
  tcase_add_test(tc, sub_int_3);
  tcase_add_test(tc, sub_int_4);
  tcase_add_test(tc, sub_float_1);
  tcase_add_test(tc, sub_float_2);
  tcase_add_test(tc, sub_float_3);
  tcase_add_test(tc, sub_float_4);
  tcase_add_test(tc, sub_inf);
  tcase_add_test(tc, sub_neg_inf);
  suite_add_tcase(s, tc);

  return s;
}
