#include <stdio.h>

int main(){
    float pesoA, pesoB, pesoC, pesoD;
    printf("Insira os valores dos pesos: \n");
    scanf("%f %f %f %f", &pesoA, &pesoB, &pesoC, &pesoD);

    if ((pesoA == (pesoB + pesoC + pesoD)) && ((pesoB + pesoC) == pesoD) && (pesoB == pesoC)){
        printf("Esta equilibrado!\n");
    }

    else printf("Nao esta equilibrado!\n");
}
