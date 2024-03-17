#include "s21_decimal.h"
int s21_div(s21_decimal divident_src, s21_decimal divisor, s21_decimal *result) {
    int result_num = 1;
    s21_decimal divident;
    s21_decimal one={0b00000001, 0b0000, 0b000, 0b0000000000000000000000000000};
    nullify(&divident);
    nullify(result);
    int position=0;
    
   
   // int divident=0;
    //int divisor=0;
    int i=95;
    while(!get_bit(divident_src, i)){
        i--;}//режем нули
   
       
        {
            

            
                
                while(s21_is_less(divident, divisor)){
                    
                    grow_divident(&divident, divident_src, i);
                    i--;

                }//now divident can be actually substracted from
                
while(s21_is_greater_or_equal(divident, divisor)){
    s21_sub(divident, divisor, &divident);
    s21_add(*result, one, result);
    printb(*result);
    
    grow_divident(&divident, divident_src, i);
    while(s21_is_less(divident, divisor)){
                    
                    grow_divident(&divident, divident_src, i);
                    i--;

                }

}
// и теперь мы заведем цикл на собственно деление, но если divisor биты будут занимать больше одного инта, то просто делением я не смогу это сделать, надо ведь через вычитание?

            
        }
        
        printb(*result);
    return result_num;
}
    void grow_divident(s21_decimal* divident, s21_decimal divident_src,int i){
shift_left(divident); 
set_bit(divident, 0, get_bit(divident_src, i));
    }