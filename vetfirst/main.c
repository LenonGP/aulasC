#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont, alunos=0;
    float n[5], media=0;

    for (cont=0; cont<5; cont++) {
        printf("digite a nota %d:", cont);
        scanf("%f", &n[cont]);
        media=media+n[cont];
    }
    media=media/(float)cont;
    for (cont=0; cont<5; cont++){
        if (n[cont]>media){
            alunos++;
        }
    }
    printf("alunos acima da media = %d", alunos);

    return 0;
}
