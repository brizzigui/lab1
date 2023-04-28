#include <stdio.h>

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero == 0){
        printf("%d: nulo", numero);
    }

    else{
        if (numero > 0){
            printf("%d: positivo", numero);
        }

        else{
            printf("%d: negativo", numero);
        }
    }
}
