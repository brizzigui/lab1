#include <stdio.h>

int main(){
    float numerador, denominador;
    float resultado = 0;

    for (numerador = 1, denominador = 1; numerador <= 99 && denominador <= 50; numerador = numerador + 2, denominador++){
        resultado = resultado + (numerador / denominador);
    }

    printf("%f", resultado);

}
