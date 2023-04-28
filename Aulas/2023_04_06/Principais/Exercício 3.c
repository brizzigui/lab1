#include <stdio.h>
#include <math.h>

int main(){
    float numero;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    if (numero > 0){
        numero = 1/numero;
    }

    else{
        numero = fabs(numero);
    }

    printf("%f", numero);
}
