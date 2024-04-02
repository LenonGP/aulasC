#include <stdio.h>
#include <stdlib.h>

int pot(int base, int expoente){
    int resultado=1;
    while (expoente>0){
        resultado=resultado*base;
        expoente--;
    }
    return resultado;
}

int digitos (int numero){
    int cont = 0;
    while (numero>=1){
        numero=numero/10;
        cont++;
    }
    return cont;
}

int inverter(int valor){
    int invertido=0, contador=digitos(valor);
    while (valor>=1){
        invertido=invertido+(valor%10)*pot(10,contador-1);
        valor=valor/10;
        contador--;
    }
    return (invertido);
}


int main()
{
    int numero;

    printf("digite um numero: \t");
    scanf("%d", &numero);

    printf("\n O numero invertido e: %d", inverter (numero));
    printf("\n\n");

    return 0;
}
