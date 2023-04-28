#include <stdio.h>

int numeros(){
    int num;
    float soma_pares = 0, soma_impares = 0, media_pares, qnt_pares = 0, qnt_impares = 0;;
    for (int i = 0; i < 10; i++){

        scanf("%d", &num);
        if (num % 2 == 0){
            qnt_pares++;
            soma_pares = soma_pares + num;
        }

        else{
            qnt_impares++;
            soma_impares = soma_impares + num;
        }
    }

    media_pares = soma_pares / qnt_pares;

    printf("Havia %.0f numeros pares e %.0f numers impares.\n", qnt_pares, qnt_impares);
    printf("A media dos numeros pares foi %f.\n", media_pares);
    printf("O somatorio dos impares foi %f.\n", soma_impares);
}

int main(){
    numeros();

}
