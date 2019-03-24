#include<stdio.h>

void swap(int *x, int *y){
int temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */

   return;
}


int main () {


   int a = 10;
   int b = 20;

   swap(&a, &b);

   printf("A is : %d\n", a );
   printf("B is : %d\n", b );

   return 0;
}
