#include <stdio.h>
 struct my{
 	int i;
 };
int main() {
	struct my i1;
    i1.i = 0;
    
    struct my i2;
    i2.i = 1;
    
    struct my i3;
    i3.i = 2;
    
    struct my i4;
    i4.i = 3;
    
  struct my myNumbers[4] = {
  	i1,
    i2,
    i3,
    i4
  };
  struct my *ptr = myNumbers;
  int i;
  printf("\n\n");
  for (i = 0; i < 4; i++) {
    printf("%d\n", ptr[i].i);
  }
  return 0;
}