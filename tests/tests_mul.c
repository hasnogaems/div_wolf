#include "../test_includes/s21_tests.h"

START_TEST(mul_int_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_int_2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(mul_int_3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(mul_int_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_float_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 327680);
}
END_TEST

START_TEST(mul_float_2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147811328);
}
END_TEST

START_TEST(mul_float_3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147811328);
}
END_TEST

START_TEST(mul_float_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 2);
  set_exp(&value_2, 3);
  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 327680);
}
END_TEST

START_TEST(mul_inf) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(mul_neg_inf) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(mul_bank_round_1) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{342, 0, 0, 0}};
  set_exp(&value_2, 5);
  set_exp(&value_1, 25);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 534);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 1835008);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_bank_round_2) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{342, 0, 0, 0}};
  set_exp(&value_2, 5);
  set_exp(&value_1, 24);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 5335);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 1835008);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_bank_round_3) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{342, 0, 0, 0}};
  set_exp(&value_2, 5);
  set_exp(&value_1, 24);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 5335);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 1835008);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_bank_round_4) {
  s21_decimal value_1 = {{155, 0, 0, 0}};
  s21_decimal value_2 = {{355, 0, 0, 0}};
  set_exp(&value_2, 5);
  set_exp(&value_1, 24);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 5502);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2149318656);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(mul_one) {
  s21_decimal value_1 = {{155, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 155);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *suite_s21_mul(void) {
  Suite *s = suite_create("\033[1;31m--MUL--\033[m");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul_int_1);
  tcase_add_test(tc, mul_int_2);
  tcase_add_test(tc, mul_int_3);
  tcase_add_test(tc, mul_int_4);
  tcase_add_test(tc, mul_float_1);
  tcase_add_test(tc, mul_float_2);
  tcase_add_test(tc, mul_float_3);
  tcase_add_test(tc, mul_float_4);
  tcase_add_test(tc, mul_inf);
  tcase_add_test(tc, mul_neg_inf);
  tcase_add_test(tc, mul_bank_round_1);
  tcase_add_test(tc, mul_bank_round_2);
  tcase_add_test(tc, mul_bank_round_3);
  tcase_add_test(tc, mul_bank_round_4);
  tcase_add_test(tc, mul_one);
  suite_add_tcase(s, tc);

  return s;
}
