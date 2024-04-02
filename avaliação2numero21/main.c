#include <stdio.h>
#include <stdlib.h>



int inverter(int valor){
    int numero, cifra;

    printf("digite um numero: \t");
    scanf("%d", &numero);

    if (numero >= 0){

    do {
        cifra = numero % 10;
        printf("%d", cifra);
        numero/=10;
    }while(numero != 0);
    printf("\n");
    }
    else {
        printf("digite apenas numeros positivos.");
    }
    return inverter;
}


int main()
{
    int numero;

    printf("digite um numero: \t");
    scanf("%d", &numero);

    printf("o numero invertido sera: %i", inverter);

    return 0;
}
