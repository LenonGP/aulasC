#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ENTRADA Preço do produto
    //PROCESSAMENTO Calcular o novo preço do produto
    //SAIDA Mostrar o novo preço do produto

    float preco_produto;

        printf("digite o preço do produto:\t");
        scanf("%f",&preco_produto);

        preco_produto=preco_produto*0.9;

        printf("preço do produto com desconto = %f\n",preco_produto);






    return 0;
}
