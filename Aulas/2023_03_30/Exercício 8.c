#include <stdio.h>

int main(){
    float primeiro, razao, resultado;

    printf("Insira o primeiro termo da PA: ");
    scanf("%f", &primeiro);

    printf("Insira a razao da PA: ");
    scanf("%f", &razao);

    resultado = primeiro + razao*9;

    printf("%.2f", resultado);


}
