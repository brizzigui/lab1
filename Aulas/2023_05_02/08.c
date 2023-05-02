#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int divisores(int num){
    int soma = 0;
    for (int i = 1; i <= num; i++){
        if (num%i == 0){
            soma += i;
        }
    }

    return soma;
}

int main(){
    int somaI, somaJ;
    for(int i = 2; i < 10000; i++){
        somaI = divisores(i);
        for (int j = 2; j++ < 10000; j++){
            somaJ = divisores(j);
            if (somaI == somaJ){
                printf("%d e %d sao amigos\n", i, j);
            }
        }
    }   
}
