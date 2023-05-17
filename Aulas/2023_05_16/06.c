#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetorMultiplicador[3];
    int matriz[3][3];

    printf("Insira os numeros do vetor multiplicador:\n");

    for (int i = 0; i < 3; i++){
        scanf("%d", &vetorMultiplicador[i]);
    }

    printf("Insira os numeros da matriz:\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
        
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j] = matriz[i][j] * vetorMultiplicador[i];
        }
        
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

}
