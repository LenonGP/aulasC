#include <stdio.h>
#include <stdlib.h>

void mover(int *vet, int t, int p){
    int newvet[5] = {0};
    int aux;
    for(int i=0; i<t; i++){
        aux = i+p;
        if(aux>=t)aux -= t;
        newvet[aux] = vet[i];
    }
    for(int i=0;i<t;i++){
        vet[i] = newvet[i];
    }
}
void imp(int *vet, int t){
    for(int i=0;i<t;i++){
        printf("%d", vet[i]);
    }
    printf("\n");
}
int main()
{
    int vet[] = {1,2,3,4,5};
    imp(vet, 5);
    mover(vet, 5, 2);
    imp(vet, 5);
    return 0;
}
