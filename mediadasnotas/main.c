#include <stdio.h>
#include <stdlib.h>

int main()
{
    float M1, M2, M3, X;


    printf("\n escreva suas tres notas trimestrais e descubra sua media \t");
    scanf("%f", &M1);
    scanf("%f", &M2);
    scanf("%f", &M3);

    X=(M1+M2+M3)/3;
    printf(" sua media final é: %f\n", X);



    return 0;
}
