#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario, vendas;
    float comissao = 0;

    printf("\n digite seu salario:\t");
    scanf("%f", &salario);
    printf("\n digite o valor de vendas: \t");
    scanf("%f", &vendas);

    if (vendas <= 1500) {
        comissao = vendas * 0.03;
    } else {
    comissao + 1500 * 0.03;
    comissao = comissao + (vendas-1500) * 0.05;
    }
    printf ("valor do salario total = %.2f\n", (salario=comissao));

    return 0;
}
