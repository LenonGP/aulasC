#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, t;

    printf("\n digite o valor de a: \t");
    scanf("%d", &a);

    printf("\n digite o valor de b: \t");
    scanf("%d", &b);

    printf("a = %d, b = %d \n", a,b);

    t = a;
    a = b;
    b = t;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}
