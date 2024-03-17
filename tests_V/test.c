#include <stdbool.h>

#include "../s21_decimal.h"
#include "../test_includes/s21_tests.h"

#define OK 0

START_TEST(part1_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 97;
  test.bits[0] = 97;
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part2_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 976546;
  test.bits[0] = 976;
  set_exp(&value_1, 3);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  test.bits[0] = 977;
  set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part3_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 9765;
  test.bits[0] = 976;
  set_exp(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  test.bits[0] = 977;
  set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part4_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part5_floor) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 30);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 30);
  s21_floor(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  set_sign(&value_1, 1);
  s21_decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(part1_round) {
  s21_decimal value_1 = {{97, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal test = {{97, 0, 0, 0}};
  int return_value = s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(part2_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 976546;
  set_exp(&value_1, 3);
  test.bits[0] = 977;
  s21_round(value_1, &result);

  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  test.bits[0] = 977;
  set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part3_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 9765;
  test.bits[0] = 977;
  set_exp(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part4_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_round(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part5_round) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 30);
  int result_value = s21_round(value_1, &result);
  ck_assert_int_eq(result_value, 1);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  set_exp(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_exp(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_exp(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

//============round=========

START_TEST(test_round_max) {
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 0U, 28U, __UINT32_MAX__, __UINT32_MAX__,
                          __UINT32_MAX__);

  int status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 0U, 0, 0, 0, 8U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_NULL) {
  s21_decimal dec;
  create_decimal_from_arr(&dec, 0U, 28U, __UINT32_MAX__, __UINT32_MAX__,
                          __UINT32_MAX__);
  int status = s21_round(dec, NULL);
  ck_assert(status == 1);
}
END_TEST

START_TEST(test_round_zero_scale) {
  s21_decimal dec, res;
  create_decimal_from_arr(&dec, 0U, 0U, __UINT32_MAX__, __UINT32_MAX__, 0U);
  int status = s21_round(dec, &res);
  ck_assert_int_eq(s21_is_equal(res, dec), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_num_ten) {
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 1U, 3U, 0, 0, 1000U);
  int status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 1U, 0U, 0, 0, 1U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_distant) {
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 1U, 12U, 0U, 2328306U, 1874919425U);
  int status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 1U, 0U, 0, 0, 10000U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_num_rem_5_long_1) {
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 1U, 23U, 13552U, 2264118075U, 1749024769U);
  int status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 1U, 0U, 0, 0, 3U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_num_bank_5_up) {
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 1U, 23U, 8131U, 2217464304U, 1908408320U);
  int status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 1U, 0U, 0, 0, 2U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_num_bank_5_down) {
  int status;  // вместо int - bool
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 1U, 23U, 13552U, 2264118075U, 1749024768U);
  status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 1U, 0U, 0, 0, 3U);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_round_2) {
  int status;
  s21_decimal dec, res, ans;
  create_decimal_from_arr(&dec, 0U, 1U, 0U, 9U, 4294967291U);
  status = s21_round(dec, &res);
  create_decimal_from_arr(&ans, 0U, 0U, 0, 1U, 0);
  ck_assert_int_eq(s21_is_equal(res, ans), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal check = {{3, 0, 0, 0}};
  set_exp(&value_1, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(value_1, &res);

  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_uint_eq(res.bits[0], 3);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_int_eq(get_sign(res), 0);
  ck_assert_int_eq(get_exp(res), 0);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  set_exp(&value_1, 3);
  set_sign(&value_1, 1);
  s21_decimal check = {{123, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(value_1, &res);

  ck_assert_int_eq(s21_is_equal(res, check), 1);
  ck_assert_int_eq(get_sign(res), 1);
  ck_assert_int_eq(get_exp(res), 0);
}
END_TEST

START_TEST(part1_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  value_1.bits[0] = 97;
  test.bits[0] = 97;
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part2_truncate) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 976546;
  set_exp(&value_1, 3);

  s21_decimal test = {0};
  test.bits[0] = 976;

  s21_decimal result = {0};
  s21_truncate(value_1, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part3_truncate) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 9765;
  set_exp(&value_1, 1);

  s21_decimal test = {0};
  test.bits[0] = 976;

  s21_decimal result = {0};
  s21_truncate(value_1, &result);

  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 1);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part4_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(part5_truncate) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal test = {0};
  test.bits[0] = 0;
  set_exp(&value_1, 30);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);

  set_sign(&value_1, 1);
  s21_truncate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s = suite_create("\033[1;31m--EXTRA FUNCTIONS--\033[m");

  TCase *tc_floor_parts;
  tc_floor_parts = tcase_create("floor_parts");
  suite_add_tcase(s, tc_floor_parts);
  tcase_add_test(tc_floor_parts, part1_floor);
  tcase_add_test(tc_floor_parts, part2_floor);
  tcase_add_test(tc_floor_parts, part3_floor);
  tcase_add_test(tc_floor_parts, part4_floor);
  tcase_add_test(tc_floor_parts, part5_floor);

  TCase *tc_round_parts;
  tc_round_parts = tcase_create("round_parts");
  suite_add_tcase(s, tc_round_parts);
  tcase_add_test(tc_round_parts, part1_round);
  tcase_add_test(tc_round_parts, part2_round);
  tcase_add_test(tc_round_parts, part3_round);
  tcase_add_test(tc_round_parts, part4_round);
  tcase_add_test(tc_round_parts, part5_round);

  TCase *tc_floor_1;
  tc_floor_1 = tcase_create("s21_floor_1");
  suite_add_tcase(s, tc_floor_1);
  tcase_add_test(tc_floor_1, s21_floor_1);

  TCase *tc_floor_2;
  tc_floor_2 = tcase_create("s21_floor_2");
  suite_add_tcase(s, tc_floor_2);
  tcase_add_test(tc_floor_2, s21_floor_2);

  TCase *tc_negate_1;
  tc_negate_1 = tcase_create("s21_negate_1");
  suite_add_tcase(s, tc_negate_1);
  tcase_add_test(tc_negate_1, s21_negate_1);

  TCase *tc_negate_2;
  tc_negate_2 = tcase_create("s21_negate_2");
  suite_add_tcase(s, tc_negate_2);
  tcase_add_test(tc_negate_2, s21_negate_2);

  TCase *tc_round_1;
  tc_round_1 = tcase_create("s21_round_1");
  suite_add_tcase(s, tc_round_1);
  tcase_add_test(tc_round_1, s21_round_1);

  TCase *tc_round_2;
  tc_round_2 = tcase_create("s21_round_2");
  suite_add_tcase(s, tc_round_2);
  tcase_add_test(tc_round_2, s21_round_2);

  TCase *tc_round_3;
  tc_round_3 = tcase_create("s21_round_3");
  suite_add_tcase(s, tc_round_3);
  tcase_add_test(tc_round_3, s21_round_3);

  TCase *tc_round_4;
  tc_round_4 = tcase_create("s21_round_4");
  suite_add_tcase(s, tc_round_4);
  tcase_add_test(tc_round_4, s21_round_4);

  TCase *tc_truncate_1;
  tc_truncate_1 = tcase_create("s21_truncate_1");
  suite_add_tcase(s, tc_truncate_1);
  tcase_add_test(tc_truncate_1, s21_truncate_1);

  TCase *tc_truncate_2;
  tc_truncate_2 = tcase_create("s21_truncate_2");
  suite_add_tcase(s, tc_truncate_2);
  tcase_add_test(tc_truncate_2, s21_truncate_2);

  TCase *tc_truncate = tcase_create("tc_truncate");
  suite_add_tcase(s, tc_truncate);
  tcase_add_test(tc_truncate, part1_truncate);
  tcase_add_test(tc_truncate, part2_truncate);
  tcase_add_test(tc_truncate, part3_truncate);
  tcase_add_test(tc_truncate, part4_truncate);
  tcase_add_test(tc_truncate, part5_truncate);

  TCase *tc_roundROFL = tcase_create("tc_roundROFL");
  suite_add_tcase(s, tc_roundROFL);
  tcase_add_test(tc_roundROFL, test_round_max);
  tcase_add_test(tc_roundROFL, test_round_NULL);
  tcase_add_test(tc_roundROFL, test_round_zero_scale);
  tcase_add_test(tc_roundROFL, test_round_num_ten);
  tcase_add_test(tc_roundROFL, test_round_distant);
  tcase_add_test(tc_roundROFL, test_round_num_rem_5_long_1);
  tcase_add_test(tc_roundROFL, test_round_num_bank_5_up);
  tcase_add_test(tc_roundROFL, test_round_num_bank_5_down);
  tcase_add_test(tc_roundROFL, test_round_2);

  return s;
}
