#include <stdio.h>
#include <stdlib.h>

int main()
{
   float joao, pedro;
   int a;

   joao = 1.5;
   pedro = 1.1;
   a = 0;

   while (joao >= pedro){
    joao += 0.02;
    pedro += 0.03;
    a++;
    printf("Joao: %.2f \t Pedro: %.2f \t Ano: %d \n", joao, pedro, a);
   }
   printf("\n Apos %d anos, Pedro ficara maior que Joao!\n", a);

    return 0;
}
