#include <stdio.h>
#include <stdlib.h>


//Desenvolver uma fun��o que receba um vetor de 15 n�meros e mostre
//quantos deles s�o maiores que 5.


int main()
{
    int vet[15] = {6, 37, 39, 2, 10, 30, 48, 19, 12, 6, 5, 1, 36, 14, 14}, i;
    for(i=0; i<15; i++){
        if(vet[i]>5)
            printf("%d\n",vet[i]);
        else;
    }
    return 0;
}
