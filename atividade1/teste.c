#include <stdio.h>
#include <stdlib.h>

// faça uma fução que receba um vetor de inteiros por parâmetro, receba também um numero adicional
// a função deve mover os elementos posições a frente 


int main()
{
    int vet[5]= {1,2,3,4,5};
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&vet[i]);

    }   
    for(i=0;i<5;i++)
    {
        printf("%d",&vet[i]);

    }
    return 0;
}
