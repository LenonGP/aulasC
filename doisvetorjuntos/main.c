#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Desenvolver uma função que receba dois vetores, o primeiro com 5
//elementos e o segundo com 8. Construir um terceiro vetor que armazene a
//junção dos dois primeiros vetores. O terceiro vetor deve ter 13 posições.


int main()
{
    int i, vet1[5], vet2[8], vet3[13];

    srand(time(NULL));

    for(i=0; i<8; i++){
        vet1[i] = rand() %100;
        vet2[i] = rand() %100;
    }
    for(i=0; i<13; i++){
        vet3[i] = vet1[i] + vet2[i];
    }

    printf("\n vetor 1 :");
    for(i=0; i<5; i++){
        printf("%d,", vet1[i]);
    }
    printf("\n vetor 2 :");
    for(i=0; i<8; i++){
        printf("%d,", vet2[i]);
    }
    printf("\n vetor 3 :");
    for(i=0; i<13; i++){
        printf("%d,", vet3[i]);
    }

    return 0;
}
