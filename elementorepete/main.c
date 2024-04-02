#include <stdio.h>


void elemento_mais_repetido(int vetor[], int tamanho, int *elemento, int *quantidade) {
    *elemento = vetor[0];
    *quantidade = 1;

    for (int i = 0; i < tamanho; i++) {
        int frequencia = 1;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] == vetor[j])
                frequencia++;
        }
        if (frequencia > *quantidade) {
            *elemento = vetor[i];
            *quantidade = frequencia;
        }
    }
}

int main() {
    int vetor[] = {4,4,7,1,3,7,7,3,2,3,4,6,3,9,4,2,3,8,3,5,6,1,0,8,1,5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int elemento_repetido, repeticoes;
    elemento_mais_repetido(vetor, tamanho, &elemento_repetido, &repeticoes);

    printf("numero mais repetido: %d\n", elemento_repetido);
    printf("quantidade de repeticoes: %d vezes\n",repeticoes);


    return 0;
}
