#include "s21_decimal.h"
int s21_div(s21_decimal divident_src, s21_decimal divisor,
            s21_decimal *result) {
  int result_num = 1;
  s21_decimal divident;
  s21_decimal ostatok;nullify(&ostatok);
  s21_decimal one = {0b00000001, 0b0000, 0b000, 0b0000000000000000000000000000};
  nullify(&divident);
  nullify(result);
  int position = 0;

  // int divident=0;
  // int divisor=0;
  int i = 95;
  while (!get_bit(divident_src, i)) {
    i--;
  }  // режем нули

  while (s21_is_less(divident, divisor)) {
    divident_init(&divident, divident_src, i);
    i--;
    
  }  // now divident can be actually substracted from
  
  ostatok=divident;
  int x = s21_sub(ostatok, divisor, &ostatok);
      put_in_result(result, 1, divident_src);
  ostatok_into_divident(&ostatok, divident_src, &i);
  while (i >= 0) {
    if (s21_is_greater_or_equal(ostatok, divisor)) {
      int x = s21_sub(ostatok, divisor, &ostatok);
      put_in_result(result, 1, divident_src);

       printb(*result);
   
    ostatok_into_divident(&ostatok, divident_src, &i);
        if (s21_is_greater_or_equal(ostatok, divisor)) {
      int x = s21_sub(ostatok, divisor, &ostatok);
      put_in_result(result, 1, divident_src);
ostatok_into_divident(&ostatok, divident_src, &i);
       printb(*result);
    }
    }
    if(s21_is_less(ostatok, divisor)) {
        put_in_result(result, 0, divident_src);
      ostatok_into_divident(&ostatok, divident_src, &i);
if (s21_is_greater_or_equal(ostatok, divisor)) {
      int x = s21_sub(ostatok, divisor, &ostatok);
      put_in_result(result, 1, divident_src);
ostatok_into_divident(&ostatok, divident_src, &i);
       printb(*result);
    }
      //printb(ostatok);
    }
    }

    // и теперь мы заведем цикл на собственно деление, но если divisor биты
    // будут занимать больше одного инта, то просто делением я не смогу это
    // сделать, надо ведь через вычитание?

    printb(*result);
    return result_num;
  }
  void divident_init(s21_decimal * divident, s21_decimal divident_src, int i) {
    shift_left(divident);
    set_bit(divident, 0, get_bit(divident_src, i));
  }

  int ostatok_into_divident(s21_decimal * ostatok, s21_decimal divident_src,
                            int* i) {
    shift_left(ostatok);
    int zero_or_one = 0;
    zero_or_one = get_bit(divident_src, *i);
    set_bit(ostatok, 0, zero_or_one);
    //printb(*ostatok);
    
    return zero_or_one;
  }

  void put_in_result(s21_decimal * result, int i, s21_decimal divident_src) {
    shift_left(result);
    set_bit(result, 0, i);
    printf("result\n");
    
   // printb(*result);
  }
