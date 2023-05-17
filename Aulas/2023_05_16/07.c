#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4

int main(){
    int matrizA[TAM][TAM];
    int matrizB[TAM][TAM];

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }


    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (matrizB[i][j] > matrizA[i][j]){
                matrizA[i][j] = matrizB[i][j];
            }
        }
    }

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%4d", matrizA[i][j]);

        }

        printf("\n");
    }


}
