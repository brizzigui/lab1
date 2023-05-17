#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[5][5];
    int par[5][5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%4d", matriz[i][j]);

            if ((i+j) % 2 == 0){
                par[i][j] = matriz[i][j];
            }

            else{
                par[i][j] = -1;
            }
        }

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (par[i][j] != -1)
                printf("%4d", par[i][j]);
        }

        printf("\n");
    }
}
