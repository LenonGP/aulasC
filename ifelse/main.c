#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    scanf("%d, &numero");
    if (numero==0){
        printf("igual a zero!");
    }else if (numero>0){
        printf("maior que zero!");
    }else{
        printf("numero menor que zero!");
    }
    return 0;
}
