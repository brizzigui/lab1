#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int x = 3, y = 3;
    int matriz[y][x];

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            if (i + j != x - 1)
            printf("%3d", matriz[i][j]);
            else
                printf("   ");
            
        }
        printf("\n");
    }
}
