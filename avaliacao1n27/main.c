#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, resultado=0;


    printf("\n digite um numero: \t");
    scanf("%d", &num);

    for (i = 2; i<= num/2; i++){
        if (num %i == 0){
            resultado++;
            break;
        }
    }

    if (resultado==0)
        printf("\n %d e um numero primo!", num);
    else
        printf("\n %d nao e um numero primo!", num);


    return 0;
}
