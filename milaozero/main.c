#include <stdio.h>
#include <unistd.h>

int main() {
    int cont = 1000;

    while (cont >= 0) {
        printf("%d\n", cont);
        cont--;
        sleep(1); // Atraso de 1 segundo
    }

    return 0;
}
