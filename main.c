
#include "s21_decimal.h"

int main(void) {
 
  int a = 0b00000010001;
  int bitN = 33;
  // int result=get_bit_from_int(a, bitN);
  // printf("bit %d of %d is %d\n", bitN, a, get_bit_from_int(a, bitN));
  s21_decimal bits = {0b000000000, 0b0000000, 0b000101, 0b00000000000000000000001100000000};
  // printf("decimal bit %d is %d", bitN, get_bit_value(bits, bitN));
 // set_bit_value(&bits, 32, 1); // howw toprintf in binary?????
  s21_decimal bits2 = {0b00001111, 0b000, 0b000, 0b00000000000000000000000000000};
  s21_decimal bits3 = {0b00000011, 0b0000110, 0b000101, 0b00000000000000000000011100000000};
  s21_decimal two = {0b0000010, 0b00000, 0b000, 0b00000000000000000000000000000};
  s21_decimal result;
  nullify(&result);
 
  //div_by_ten(&bits2);
   printb(bits2);
  s21_div(bits2, two, &result);
  //set_to_zero(&bits);
  //printb(bits);
  return 0;
}

