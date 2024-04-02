#include<stdio.h>
#include<stdlib.h>

int main(){

int num1, num2, soma, sub, div, mult;

printf("calculadora de lenon 1.0 ela ainda vai melhorar muito rlx \n");
printf("digite os numero que deseja calcular: \t\n");
scanf("%i%i", &num1, &num2);

soma = num1 + num2;
sub = num1 - num2; 
div = num1 / num2;
mult = num1 * num2;

printf("sua soma: %i \n", soma);
printf("sua subtracao: %i \n", sub);
printf("sua divisao: %i \n", div);
printf("sua multiplicacao: %i \n", mult);

    return 0; 
}