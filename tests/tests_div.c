#include "../test_includes/s21_tests.h"

START_TEST(div_int_1) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div_int_2) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(div_int_3) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(div_int_4) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div_float_1) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 7);
  set_exp(&value_2, 3);
  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 262144);
}
END_TEST

START_TEST(div_float_2) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 3);
  set_exp(&value_2, 7);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 50000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(div_float_3) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  set_exp(&value_1, 33);
  set_exp(&value_2, 3);
  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 1835008);
}
END_TEST

START_TEST(div_float_4) {
  s21_decimal value_1 = {{3, 0, 0, 0}};
  s21_decimal value_2 = {{15, 0, 0, 0}};
  set_sign(&value_2, 1);
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;
  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 65536);
}
END_TEST

START_TEST(div_inf_1) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{6, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 2192222891);
  ck_assert_int_eq(result.bits[1], 173768805);
  ck_assert_int_eq(result.bits[2], 90350181);
  ck_assert_int_eq(result.bits[3], 1835008);
}
END_TEST

START_TEST(div_inf_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 89478485);
  ck_assert_int_eq(result.bits[1], 347537611);
  ck_assert_int_eq(result.bits[2], 180700362);
  ck_assert_int_eq(result.bits[3], 2149318656);
}
END_TEST

START_TEST(div_inf_3) {
  s21_decimal value_1 = {{54, 0, 0, 0}};
  s21_decimal value_2 = {{14, 0, 0, 0}};
  s21_decimal result = {0};
  set_exp(&value_1, 3);
  int code;

  code = s21_div(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 1720863012);
  ck_assert_int_eq(result.bits[1], 1428723515);
  ck_assert_int_eq(result.bits[2], 2090961);
  ck_assert_int_eq(result.bits[3], 1835008);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_exp(&value_2, 5);
  set_exp(&value_1, 25);
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(code, 3);
}
END_TEST

START_TEST(div_one) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 156);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div_one_1) {
  s21_decimal value_1 = {{156, 0, 0, 0}};
  s21_decimal value_2 = {{156, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *suite_s21_div(void) {
  Suite *s = suite_create("\033[1;31m--DIV--\033[m");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, div_int_1);
  tcase_add_test(tc, div_int_2);
  tcase_add_test(tc, div_int_3);
  tcase_add_test(tc, div_int_4);
  tcase_add_test(tc, div_float_1);
  tcase_add_test(tc, div_float_2);
  tcase_add_test(tc, div_float_3);
  tcase_add_test(tc, div_float_4);
  tcase_add_test(tc, div_inf_1);
  tcase_add_test(tc, div_inf_2);
  tcase_add_test(tc, div_inf_3);
  tcase_add_test(tc, div_zero);
  tcase_add_test(tc, div_one);
  tcase_add_test(tc, div_one_1);
  suite_add_tcase(s, tc);

  return s;
}
