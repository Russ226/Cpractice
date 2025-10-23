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
    unsigned char mask_1 = 0xFF;
    unsigned char mask_2 = 0x80;
    unsigned char test[] = {0x77, 0x2F};
    bitmap_print_bitmap(test, 2);

    return 0;
}