#include <stdio.h>
#include <stdlib.h>

typedef struct carro {
    char marca [200];
    char modelo [200];
    int ano;
    char cor [100];
    float preco;
} Carro;

int main()
{
    Carro c;

    printf("marca:\t");
    gets(c.marca);
    printf("\n modelo:\t");
    gets(c.modelo);
    printf("\n ano:\t");
    scanf("%d", &c.ano);
    printf("\n cor:\t");
    getchar ();
    gets(c.cor);
    printf("\n preco:\t");
    scanf("%f", &c.preco);

    printf("\n\n");

    printf("\n %s", c.marca);
    printf("\n %s", c.modelo);
    printf("\n %s", c.cor);
    printf("\n Ano %d, preco %.2f", c.ano, c.preco);

    return 0;
}
