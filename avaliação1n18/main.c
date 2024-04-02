#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_imaginado, num_chute, chutes;

    printf("\n imagine um numero inteiro de 1 a 10 e escreva: \t");
    scanf("%d", &num_imaginado);
    system("cls");
    printf("\n tente adivinhar o numero de 1 a 10: \t");

    do
    {
        chutes++;
      scanf("%d", &num_chute);
      if (num_chute==num_imaginado)
            printf("\t PARABENS VOCE ACERTOU!! foram %d tentativas",chutes);
      else{
        if (num_chute<num_imaginado)
            printf("esse numero e baixo, tente novamente: \n");
        else
            printf("esse numero e alto, tente novamente: \n");
      }
    }
    while (num_chute!= num_imaginado);
    return 0;
}
