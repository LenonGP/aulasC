#include <stdio.h>
#include <stdlib.h>

int main()
{
    float indice;

    printf("digite o indice de poluicao:\t");
    scanf("%f", &indice);

    if ((indice >= 0.05) && (indice <= 0.5)) {
        if ((indice >= 0.05) && (indice <= 0.25)){
           printf("indice aceitavel! \n");
        }else if (indice <= 0.3) {
        printf ("primeiro grupo deve suspender as atividades! \n");
        }else if (indice <= 0.4) {
        printf ("segundo grupo deve suspender as atividades! \n");
        }else if (indice <= 0.5) {
        printf ("todos os grupos devem suspender as atividades! \n");
        }
    }else{
    printf("valor não é valido! \n");
    }


    return 0;
}
