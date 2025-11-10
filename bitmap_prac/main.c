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
    unsigned char test[] = {0xff, 0x00, 0x00, 0x00};
     unsigned char f = 0x1 << 8;
    bitmap_print_bitmap(test, 4);
    bitmap_set_bit(test, 4, 15);
    int t = bitmap_bit_is_set(test, 4, 1);
    printf("%d\n", t);
    bitmap_print_bitmap(test, 4);
    return 0;
}