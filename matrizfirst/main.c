#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[3][3];
    int l, c, lu;

    for (l=0; l<3; l++) {
      for(c=0; c<3; c++) {
        printf("digite o valor da posicao (%d,%d) \t", l, c);
        scanf("%d", &m[l][c]);
      }
    }
    printf("digite a linha a ser exibida:");
    scanf("%d", &lu);

    for (c=0; c<3; c++) {
        printf("%d \t", m[lu][c]);
    }
    printf("\n");

    return 0;
}
