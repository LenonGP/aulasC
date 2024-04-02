#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2;
    printf("\n escreva dois numeros para descobrir qual eh o maior: \t");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    if (numero1 > numero2){
        printf("numero1 eh maior. %d", numero1);
    }else{
        printf("numero2 eh maior. %d", numero2);
    }
    return 0;
}
