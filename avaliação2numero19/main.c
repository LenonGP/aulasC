#include <stdio.h>
#include <stdlib.h>

int teste(int valor){

        int soma=0, divisor;

    for (divisor=1; divisor <= valor/2; divisor++)
        if(valor % divisor==0)
            soma=soma+divisor;

    return soma;
}

int perfeito(int valor)
{

    if(teste(valor)==(valor))
        return 1;
    else
        return 0;
}


int main()
{
    int valor;

    printf("\n digite um numero para ver se ele e perfeito: \t");
    scanf("%d", &valor);

    if (perfeito(valor))
        printf("\n Esse numero e perfeito!");
    else
        printf("\n Esse numero NAO e perfeito!");

    printf("\n\n");
    return 0;
}
