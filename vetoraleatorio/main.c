#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetorAleatorio(int *v, int t, int max) {
    srand(time(NULL));
    int i;
    int *vet = (int *) malloc(t * sizeof(int));
    for(i=0;i<t;i++)
     vet[i]=(rand()%max)+1;
    return vet;
}
int main() {
    int *v;
    int i, t = 10000;
    v = vetorAleatorio(v, t, 500);
    for(i=0;i<t;i++) {
        printf("%d, ", v[i]);
    }
    return 0;
}
