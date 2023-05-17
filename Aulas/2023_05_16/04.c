#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[2][2];
    int diagPrim = 1, diagSec = 1;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if (i == j){
                diagPrim *= matriz[i][j];
            }

            else if(i + j == (2 - 1)){
                diagSec *= matriz[i][j];
            }
        }
    }

    int resultado = diagPrim - diagSec;
    printf("Resultado: %d", resultado);
}
