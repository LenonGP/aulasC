#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario, novo_salario;
    int percentual;


    printf("\n digite o salario mensal: \t");
    scanf("%f", &salario);

    printf("\n digite o percentual do reajuste: \t");
    scanf("%d", &percentual);

    novo_salario = salario + ((salario) * (percentual/100.0));

    printf("\n o antigo salario era de %.2f. \t", salario);
    printf("\n o percentual de reajuste e de %d %%. \t", percentual);

    printf("\n novo salario %.2f\t antigo salario %.2f.", novo_salario, salario);


    return 0;
}
