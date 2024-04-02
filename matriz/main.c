#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz [3][3] = {{1, 2, 3},
                        {4, 5, 678},
                        {8, 9, 0}};
    int casas = 5;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%*d",casas, matriz[i][j]);
        }
        printf("\n");
    }



    return 0;
}
