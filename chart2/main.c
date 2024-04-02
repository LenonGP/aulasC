#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char re[80];
    printf("digite uma palavra \t");
    scanf("%s", &re);
    int size=strlen(re);
    printf("essa palavra tem %d caracteres. \n", size);


    return 0;
}
