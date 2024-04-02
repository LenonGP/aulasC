#include <stdio.h>
#include <stdlib.h>

struct carro {
    int velocidade;
    int radio_on;
    int RPM;
};



int main(){
    struct carro ferrari;
    ferrari.velocidade = 180;
    ferrari.radio_on = 0;
    ferrari.RPM = 7;
    printf("Ferrari:\n velocidade = %d MPH \n RPM x1000 = %d", ferrari.velocidade, ferrari.RPM);

    if (ferrari.radio_on){
        printf("\n com radio ligado!");
    }else {
            printf("\n com radio desligado!");
            }


    return 0;
}
