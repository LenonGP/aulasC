#include <stdio.h>
#include <math.h>

int main()
{
    float num;

    printf("\n digite um numero (numero maior que zero): \t");
    scanf("%f", &num);

    printf("a) %.2f\n", pow(num,2));
    printf("b) %.2f\n", pow(num,3));
    printf("c) %.2f\n", sqrt(num));
    printf("d) %.2f\n", cbrt(num));


    return 0;
}
