#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char re[80];
    printf("digite seu nome: \t");
    gets(re);
    printf("Oi %s, como você esta?\n", re);
    scanf("%s", &re);
        if (strcmp(re,"bem")==0){
        printf("Que bom, tenha um otimo dia\n", re);
    }
        else {
            printf("nao se desanime, seu dia ainda vai ficar muito bom ! \t");
        }

    return 0;
}
