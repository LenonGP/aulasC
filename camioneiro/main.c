#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cod_estado, cod_carga;
    float carga_caminhao;

    float carga_caminhao_kg, preco_carga_caminhao, vi, vt;

    printf("digite o codigo do estado: \t");
    scanf("%d", &cod_estado);
    printf("digite o codigo da carga: \t");
    scanf("%d",&cod_carga);
    printf("digite o peso do caminhao: \t");
    scanf("%f", &carga_caminhao);

    carga_caminhao_kg = carga_caminhao * 1000;

    if ((cod_carga >= 10) && (cod_carga <= 20)){
        preco_carga_caminhao = carga_caminhao_kg * 100;
    }else if ((cod_carga >= 21) && (cod_carga <= 30)){
        preco_carga_caminhao = carga_caminhao_kg * 250;
    }else {
        preco_carga_caminhao = carga_caminhao_kg * 340;
    }


    switch (cod_estado) {
      case 1:
        vi = preco_carga_caminhao * 0.35;
        break;
      case 2:
        vi = preco_carga_caminhao * 0.25;
        break;
      case 3:
        vi = preco_carga_caminhao * 0.15;
        break;
      case 4:
        vi = preco_carga_caminhao * 0.05;
        break;
      default:
        vi = 0;
        break;
    }

    vt = preco_carga_caminhao + vi;


    printf("peso do caminhao em kg: %.2f \n", carga_caminhao_kg);
    printf("preco da carga do caminhao: %.2f \n", preco_carga_caminhao);
    printf("valor do imposto: %.2f \n", vi);
    printf("valor total transportado %.2f \n", vt);

    return 0;
}
