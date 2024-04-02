#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabuada = 0;

    printf("\n digite a tabuada que voce deseja: \n");
    scanf("%d", &tabuada);

    for(int x; x <= 10; x++){

            printf("\t %d x %d =  %d \n", tabuada, x, x*tabuada);


    }



    printf("Hello world!");
    return 0;
}
