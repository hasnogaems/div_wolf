#include "../test_includes/s21_tests.h"

START_TEST(from_float_to_decimal0) {
#line 4
  float src = 56.986;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "56986 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal1) {
#line 14
  float src = 1.0 / 0.0;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal2) {
#line 24
  float src = -1.596;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596 0 0 2147680256";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal3) {
#line 34
  float src = 1 / 0.0;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal4) {
#line 44
  double src = 0.0;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal5) {
#line 54
  long double src = 0.;
  s21_decimal z = {{0u, 0u, 0u, 0u}};
  int n1 = s21_from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal6) {
#line 64
  s21_decimal temp;
  init_decimal(&temp);
  float a = 0.0f;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 0);
  ck_assert_int_eq(get_sign(temp), 0);

  init_decimal(&temp);
  a = 20.0;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(get_sign(temp), 0);
  ck_assert_int_eq(get_exp(temp), 0);

  init_decimal(&temp);
  a = -20.0;
  s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(temp.bits[0], 20);
  ck_assert_int_eq(get_sign(temp), 1);
  ck_assert_int_eq(get_exp(temp), 0);

  init_decimal(&temp);
  a = 0.0 / 0.0;
  int res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  init_decimal(&temp);
  a = 1.0 / 0.0;
  res = 0;
  res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);

  init_decimal(&temp);
  a = -1.0 / 0.0;
  res = 0;
  res = s21_from_float_to_decimal(a, &temp);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal7) {
#line 103
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 1.0 / 0.0;
  ck_assert_uint_eq(dec.bits[0], 0);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 0);
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal8) {
#line 113
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = -1.0 / 0.0;
  ck_assert_uint_eq(dec.bits[0], 0);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 0);
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal9) {
#line 123
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = NAN;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0], 0);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal10) {
#line 133
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 248e-30;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0], 2);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 1835008);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal11) {
#line 144
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 248e30;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0], 0);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 0);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal12) {
#line 155
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = -248e30;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0], 0);
  ck_assert_uint_eq(dec.bits[1], 0);
  ck_assert_uint_eq(dec.bits[2], 0);
  ck_assert_uint_eq(dec.bits[3], 0);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(from_float_to_decimal13) {
#line 165
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 248e26;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0],
                    3758096384);  // 11100000000000000000000000000000
  ck_assert_uint_eq(dec.bits[1],
                    3788270668);  // 11100001110011000110110001001100

  ck_assert_uint_eq(dec.bits[2],
                    1344410693);  // 1010000001000100001010001000101
  // 10100000010001000010100010001011110000111001100011011000100110011100000000000000000000000000000
  // конвертируется в 24800000000000000000000000000
  ck_assert_uint_eq(dec.bits[3], 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal14_1) {
#line 181
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 7.922815e28;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal14) {
#line 187
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = 7.922816e28;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal15) {
#line 193
  s21_decimal dec = {{0u, 0u, 0u, 0u}};
  float a = -248e26;
  int res = s21_from_float_to_decimal(a, &dec);
  ck_assert_uint_eq(dec.bits[0], 3758096384);
  ck_assert_uint_eq(dec.bits[1], 3788270668);

  ck_assert_uint_eq(dec.bits[2], 1344410693);
  ck_assert_uint_eq(get_sign(dec), 1);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(from_float_to_decimal16) {
#line 205
  float inp = -1.078071E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x82949470, 0x00000002, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal17) {
#line 213
  float inp = -5.447201E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal18) {
#line 221
  float inp = 0.00000000000000000000000858598287381972;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(D2F_0) {
#line 227
  s21_decimal x = {{15008, 0, 0, 0}};
  set_exp(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = 15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(D2F_1) {
#line 236
  s21_decimal x = {{15008, 0, 0, 0}};
  set_sign(&x, 1);
  set_exp(&x, 3);
  float res1;
  int n1 = s21_from_decimal_to_float(x, &res1);
  float res2 = -15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(D2F_2) {
#line 246
  s21_decimal x = {{15008, 0, 0, 0}};
  set_sign(&x, 1);
  set_exp(&x, 3);
  float res1 = 0;
  int n1 = s21_from_decimal_to_float(x, NULL);
  float res2 = 0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(D2F_3) {
#line 256
  s21_decimal value = {{9, 0, 0, 0}};
  set_exp(&value, 1);
  set_sign(&value, 1);
  float a = -0.9, b;
  int res = s21_from_decimal_to_float(value, &b);
  ck_assert_float_eq(a, b);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(D2F_4) {
#line 265
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{9, 0, 0, 0}};
  set_exp(&value_2, 1);
  set_sign(&value_2, 1);
  float a = -0.9;
  int res = s21_from_float_to_decimal(a, &value);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(D2F_5) {
#line 274
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_float(decimal, NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(D2F_6) {
#line 279
  s21_decimal a = {{5, 0, 0, 2147483648}};
  float dec_to_float_a = 0;
  s21_from_decimal_to_float(a, &dec_to_float_a);
  ck_assert_float_eq(dec_to_float_a, -5.0);
}
END_TEST

START_TEST(D2F_7) {
#line 285
  s21_decimal a = {{13, 0, 0, 0}};
  float dec_to_float_a = 0;
  s21_from_decimal_to_float(a, &dec_to_float_a);
  ck_assert_float_eq(dec_to_float_a, 13.0);
}
END_TEST

START_TEST(D2F_8) {
#line 291
  s21_decimal temp;
  init_decimal(&temp);
  float a = 0;
  temp.bits[0] = 45;
  set_exp(&temp, 1);
  s21_from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, 4.5);

  init_decimal(&temp);
  a = 0;
  temp.bits[0] = 45;
  set_exp(&temp, 1);
  set_sign(&temp, 1);
  s21_from_decimal_to_float(temp, &a);
  ck_assert_float_eq(a, -4.5);
}
END_TEST

START_TEST(D2F_9) {
#line 308
  s21_decimal a = {{2, 0, 0, 0x80000000}};
  s21_decimal b = {{228322, 4, 0, 0b000000000000001010000000000000000}};
  s21_decimal c = {{0, 0, 0, 0x80000000}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal i = {
      {0b11101011000111110000101011010010, 0b10101011010101001010100110001100,
       0, 0b000000000000101000000000000000000}};  //  0.1234567890123...
  s21_decimal k = {
      {0b01101010110111001011101011000000, 0b10011000001000100111111010101010,
       0b00000000000010100011011001001100, 0b10000000000101110000000000000000}};

  float e = 0.0;
  float f = 0.0;
  float g = 0.0;
  float h = 0.0;
  float j = 0.0;
  float l = 0.0;

  ck_assert_int_eq(s21_from_decimal_to_float(a, &e), 0);
  ck_assert_float_eq_tol(e, -2.0, 1e-9);
  ck_assert_int_eq(s21_from_decimal_to_float(b, &f), 0);
  ck_assert_float_eq_tol(f, 171800.97506, 1e-9);
  ck_assert_int_eq(s21_from_decimal_to_float(c, &g), 0);
  ck_assert_float_eq(g, -0.0);
  ck_assert_int_eq(s21_from_decimal_to_float(c, NULL), 1);
  ck_assert_int_eq(
      s21_from_decimal_to_float((s21_decimal){{0, 0, 0, 0xffffffff}}, &e), 1);

  ck_assert_int_eq(s21_from_decimal_to_float(d, &h), 0);
  ck_assert_float_eq(h, -0.0);
  ck_assert_int_eq(s21_from_decimal_to_float(i, &j), 0);
  ck_assert_float_eq_tol(j, 0.123457, 1e-6);
  ck_assert_int_eq(s21_from_decimal_to_float(k, &l), 0);
  ck_assert_float_eq_tol(l, -123.457, 1e-3);
}
END_TEST

START_TEST(I2D_0) {
#line 346
  int src = 2147483647;
  s21_decimal result;
  init_decimal(&result);
  s21_from_int_to_decimal(src, &result);
  s21_decimal check = {{2147483647u, 0u, 0u, 0u}};
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(I2D_1) {
#line 356
  int src = -2147483648;
  s21_decimal check = {{2147483648u, 0u, 0u, 0u}};
  set_sign(&check, 1);
  s21_decimal result;
  s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(I2D_2) {
#line 366
  int src = -49135648;
  s21_decimal check = {{49135648u, 0u, 0u, 0u}};
  set_sign(&check, 1);
  s21_decimal result;
  s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(I2D_3) {
#line 376
  int a = 123123;
  s21_decimal result = {0};
  s21_from_int_to_decimal(a, &result);
  ck_assert_uint_eq(result.bits[0], a);
  ck_assert_int_eq(get_sign(result), 0);
  ck_assert_int_eq(get_exp(result), 0);
}
END_TEST

START_TEST(I2D_4) {
#line 384
  int number = -2147483648;
  int result = s21_from_int_to_decimal(number, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(I2D_5) {
#line 389
  int number = -2147483648;
  s21_decimal result;
  int rez = s21_from_int_to_decimal(number, &result);
  // Converted the Int32 value -2147483648 to the Decimal value -2147483648.
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(rez, 0);
}
END_TEST

START_TEST(I2D) {
#line 398

  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal c = {{0, 0, 0, 0}};
  s21_decimal d = {{0, 0, 0, 0}};
  s21_decimal i = {{0, 0, 0, 0}};
  s21_decimal k = {{0, 0, 0, 0}};

  int e = 228;
  int f = 322;
  int g = -1337;
  int h = 0;
  int j = 2147483647;
  int l = -2147483647;

  ck_assert_int_eq(s21_from_int_to_decimal(e, &a), 0);
  ck_assert_int_eq(e, a.bits[0]);

  ck_assert_int_eq(s21_from_int_to_decimal(f, &b), 0);
  ck_assert_int_eq(f, b.bits[0]);

  ck_assert_int_eq(s21_from_int_to_decimal(g, &c), 0);
  ck_assert_int_eq(-g, c.bits[0]);
  ck_assert_int_eq(0x80000000, c.bits[3]);

  ck_assert_int_eq(s21_from_int_to_decimal(h, &d), 0);
  ck_assert_int_eq(h, d.bits[0]);

  ck_assert_int_eq(s21_from_int_to_decimal(j, &i), 0);
  ck_assert_int_eq(j, i.bits[0]);

  ck_assert_int_eq(s21_from_int_to_decimal(l, &k), 0);
  ck_assert_int_eq(-l, k.bits[0]);
  ck_assert_int_eq(0x80000000, k.bits[3]);

  ck_assert_int_eq(s21_from_int_to_decimal(l, NULL), 1);
}
END_TEST

START_TEST(D2I_0) {
#line 526
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_sign(&value, 1);
  set_exp(&value, 1);
  int dst;
  int check = -4913564;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(dst, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(D2I_1) {
#line 536
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_exp(&value, 1);
  int dst;
  int check = 4913564;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(dst, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(D2I_2) {
#line 545
  s21_decimal a = {{123, 0, 0, 0}};
  set_exp(&a, 1);
  int int_a;

  s21_from_decimal_to_int(a, &int_a);
  ck_assert_int_eq(int_a, 12);
}
END_TEST

START_TEST(D2I_3) {
#line 553
  int a = 0;
  s21_decimal temp;
  init_decimal(&temp);
  temp.bits[0] = 1U;
  set_sign(&temp, 1);
  s21_from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, -1);

  a = 0;
  init_decimal(&temp);
  temp.bits[0] = 1U;
  temp.bits[3] = 0;
  s21_from_decimal_to_int(temp, &a);
  ck_assert_int_eq(a, 1);

  a = 0;
  init_decimal(&temp);
  temp.bits[0] = 123;
  temp.bits[1] = 123;
  int res = 0;
  res = s21_from_decimal_to_int(temp, &a);
  ck_assert_uint_eq(res, 1);
}
END_TEST

START_TEST(D2I_4) {
#line 577

  s21_decimal a = {{2, 0, 0, 0x80000000}};
  s21_decimal b = {{228322, 0, 0, 0}};
  s21_decimal c = {{1234, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal d = {{123445, 132123, 0, 0}};
  s21_decimal i = {{123445, 0, 0, 0b11111111111111111111111111111111}};
  int e = 0;
  int f = 0;
  int g = 0;
  int h = 0;

  ck_assert_int_eq(s21_from_decimal_to_int(a, &e), 0);
  ck_assert_int_eq(e, -2);

  ck_assert_int_eq(s21_from_decimal_to_int(b, &f), 0);
  ck_assert_int_eq(f, 228322);

  ck_assert_int_eq(s21_from_decimal_to_int(c, &g), 0);
  ck_assert_int_eq(g, 123);

  ck_assert_int_eq(s21_from_decimal_to_int(d, &h), 1);
  ck_assert_int_eq(s21_from_decimal_to_int(b, NULL), 1);
  ck_assert_int_eq(s21_from_decimal_to_int(b, NULL), 1);
  ck_assert_int_eq(s21_from_decimal_to_int(i, &h), 1);
}
END_TEST

Suite *suite_s21_conventors(void) {
  Suite *s = suite_create("\033[1;31m--CONVENTORS--\033[m");
  TCase *tc1_1 = tcase_create("conventors_tc");

  tcase_add_test(tc1_1, from_float_to_decimal0);
  tcase_add_test(tc1_1, from_float_to_decimal1);
  tcase_add_test(tc1_1, from_float_to_decimal2);
  tcase_add_test(tc1_1, from_float_to_decimal3);
  tcase_add_test(tc1_1, from_float_to_decimal4);
  tcase_add_test(tc1_1, from_float_to_decimal5);
  tcase_add_test(tc1_1, from_float_to_decimal6);
  tcase_add_test(tc1_1, from_float_to_decimal7);
  tcase_add_test(tc1_1, from_float_to_decimal8);
  tcase_add_test(tc1_1, from_float_to_decimal9);
  tcase_add_test(tc1_1, from_float_to_decimal10);
  tcase_add_test(tc1_1, from_float_to_decimal11);
  tcase_add_test(tc1_1, from_float_to_decimal12);
  tcase_add_test(tc1_1, from_float_to_decimal13);
  tcase_add_test(tc1_1, from_float_to_decimal14_1);
  tcase_add_test(tc1_1, from_float_to_decimal14);
  tcase_add_test(tc1_1, from_float_to_decimal15);
  tcase_add_test(tc1_1, from_float_to_decimal16);
  tcase_add_test(tc1_1, from_float_to_decimal17);
  tcase_add_test(tc1_1, from_float_to_decimal18);
  tcase_add_test(tc1_1, D2F_0);
  tcase_add_test(tc1_1, D2F_1);
  tcase_add_test(tc1_1, D2F_2);
  tcase_add_test(tc1_1, D2F_3);
  tcase_add_test(tc1_1, D2F_4);
  tcase_add_test(tc1_1, D2F_5);
  tcase_add_test(tc1_1, D2F_6);
  tcase_add_test(tc1_1, D2F_7);
  tcase_add_test(tc1_1, D2F_8);
  tcase_add_test(tc1_1, D2F_9);
  tcase_add_test(tc1_1, I2D_0);
  tcase_add_test(tc1_1, I2D_1);
  tcase_add_test(tc1_1, I2D_2);
  tcase_add_test(tc1_1, I2D_3);
  tcase_add_test(tc1_1, I2D_4);
  tcase_add_test(tc1_1, I2D_5);
  tcase_add_test(tc1_1, I2D);
  tcase_add_test(tc1_1, D2I_0);
  tcase_add_test(tc1_1, D2I_1);
  tcase_add_test(tc1_1, D2I_2);
  tcase_add_test(tc1_1, D2I_3);
  tcase_add_test(tc1_1, D2I_4);

  suite_add_tcase(s, tc1_1);

  return s;
}
