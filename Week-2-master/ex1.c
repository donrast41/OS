#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;


    printf("Size is = %d\n",sizeof(a));
    printf("The maximum value of INT = %d\n", a);

    printf("Size is = %ld\n",sizeof(b));
    printf("The maximum value of FLOAT = %f\n", b);

    printf("Size is = %ld\n",sizeof(c));
    printf("The maximum value of DOUBLE = %f\n", c);

    return 0;

}


