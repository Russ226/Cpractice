#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//   unsigned char t = (test[0] << 0 * 1);
    
//     int pos = 0;
//     printf("\n");
//     while(pos < 8){
        
//         int cur_bit = ((test[0] << pos) & mask_2) > 0;
//         printf("%d", cur_bit);
//         pos++;
//     }


int main(){
     printf("\n");
    unsigned char mask_1 = 0xFF;
    unsigned char mask_2 = 0x80;
    unsigned char test[] = {0x00, 0xfF};
    
    //unsigned char m[] = {0x1 << 4};  
    bitmap_print_bitmap(test, 1);
    //*(test + 3/BIT_PER_BYTE) = *(test + 3/BIT_PER_BYTE) ^ 0x01 << 3;
    *(test + 3/BIT_PER_BYTE) = *(test + 3/BIT_PER_BYTE) | 0x01 << 3;
    bitmap_print_bitmap(test, 1);
    //int current_byte = *(test + 2/BIT_PER_BYTE);
    //int v = ((0x80 >> 7 % BIT_PER_BYTE) & 0x01);
    //printf("%d", v);
    return 0;
}