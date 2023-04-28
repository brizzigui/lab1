#include <stdio.h>

int main(){

    int soma = 0;

    for (int i = 100; i <= 200; i++){
        if (i%13 != 0){
            soma = soma + i;
        }
    }

    printf("%d", soma);
}
