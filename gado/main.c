#include <stdio.h>
#include <stdlib.h>
#define CG 2

    struct data{
    int mes;
    int ano;
    };

    struct gado {
    int codigo;
    int leite;
    int alimento;
    struct data nasc;
    char abate;
    };

int main(){
   struct gado cg [CG];
   int i;

   for (i = 0; i < CG; i++) {
    printf("codigo\t");
    scanf("%d", &cg[i].codigo);
    printf("leite \t");
    scanf("%d", &cg[i].leite);
    printf("alimento \t");
    scanf("%d", &cg[i].alimento);
    printf("nascimento (mes) \t");
    scanf("%d", &cg[i].nasc.mes);
    printf("nascimento (ano) \t");
    scanf("%d", &cg[i].nasc.ano);
    printf("abate ? \t");
    scanf(" %c", &cg[i].abate);
   }
   for (i = 0; i < CG; i++) {
    printf("\n codigo: \t %d", cg[i].codigo);
    printf("\n leite \t %d", cg[i].leite);
    printf("\n alimento \t %d", cg[i].alimento);
    printf("\n nascimento \t %d/%d \n", cg[i].nasc.mes, cg[i].nasc.ano);
    printf("\n abate ? \t %c \n\n", cg[i].abate);
   }
    return 0;
}
