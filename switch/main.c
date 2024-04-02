#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    scanf("%d", &numero);
    switch(numero){
        case 0:
        printf("igual a zero!");
        break;
        case 1:
        printf("igual a 1!");
        break;
        default:
        printf("diferente de zero e 1!");
    }
    return 0;
}
