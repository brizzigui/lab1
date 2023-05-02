#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num, posicao = 1;
    scanf("%d", &num);

    while(num != 0){
        printf("Posicao: %d - Numero: %d - ", posicao, num);
        if (num % posicao == 0){
            printf("Multiplo: %d", num);
        }
        posicao++;

        printf("\n");
        scanf("%d", &num);
    }
}
