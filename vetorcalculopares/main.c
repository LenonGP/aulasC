#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10], cont, soma=0;
    cont=0;

    do{
        scanf("%d", &vet[cont]);
        if ((vet[cont]%2)==0){
            soma = soma+vet[cont];
        }
        cont++;
    }while(cont<10);
    printf("a soma de pares e = %d", soma);


    return 0;
}
