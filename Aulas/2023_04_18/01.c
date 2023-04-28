#include <stdio.h>

int main(){
    int menor, maior, soma;
    scanf("%d %d", &menor, &maior);

    for (int num = menor; num <= maior; num++){

        if (num%2 != 0){
            printf("%d ", num);
            soma = soma + num;

        }
    }

    printf("\nA soma foi de %d", soma);

}
