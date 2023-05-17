#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[5][5];
    int linha2e5[5][5];
    int coluna3e5[5][5];
    int diagonais[5][5];
    int aux;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
            linha2e5[i][j] = matriz[i][j];
            coluna3e5[i][j] = matriz[i][j];
            diagonais[i][j] = matriz[i][j];
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int j = 0; j < 5; j++){
        linha2e5[1][j] = matriz[4][j];
        linha2e5[4][j] = matriz[1][j];
    }


    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%4d", linha2e5[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++){
        coluna3e5[i][2] = matriz[i][4];
        coluna3e5[i][4] = matriz[i][2];
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%4d", coluna3e5[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == j){
                diagonais[i][4-(j)] = matriz[i][j];
                diagonais[i][j] = matriz[i][4-(j)];
            }
                
            
        }
        
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%4d", diagonais[i][j]);
        }
        printf("\n");
    }
}
