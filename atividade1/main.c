#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, X, X1, Y, Y1;
    X= 1;
    X1= 1;

    printf("\n digite qualquer numero inteiro: \t");
    scanf("%d", &A);

    Y= A+X;
    Y1= A-X1;

    printf("%d \n" , Y1);
    printf("%d \n" , A);
    printf("%d \n" , Y);

    return 0;
}
