#include <stdio.h>
#include <stdlib.h>


int main()
{
    char str[200] = ("aula de estrutura de dados e programacao");
    char sub[20] = ("strut");

    for(int i = 0; str[i] != '\0'; i++){
        printf("%c \n", str[i]);
    }

    return 0;
}
