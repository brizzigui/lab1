#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[2][3];
    int transposta[3][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            transposta[j][i] = matriz[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("%4d", transposta[i][j]);
        }

        printf("\n");
    }

}
