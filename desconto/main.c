#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ENTRADA Pre�o do produto
    //PROCESSAMENTO Calcular o novo pre�o do produto
    //SAIDA Mostrar o novo pre�o do produto

    float preco_produto;

        printf("digite o pre�o do produto:\t");
        scanf("%f",&preco_produto);

        preco_produto=preco_produto*0.9;

        printf("pre�o do produto com desconto = %f\n",preco_produto);






    return 0;
}
