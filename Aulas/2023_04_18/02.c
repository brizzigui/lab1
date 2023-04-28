#include <stdio.h>

int main(){
    float num, maior;

    for (int i = 0; i < 20; i++){
        scanf("%f", &num);
        if (i == 0){
            maior = num;
        }
        if (num > maior){
            maior = num;
        }
    }

    printf("O maior equivale a: %f", maior);
}
