#include <stdio.h>

int main(){
    float peso;
    int codigo;

    printf("Insira um peso (em N) na Terra: ");
    scanf("%f", &peso);

    printf("Insira um numero de um planeta: ");
    scanf("%d", &codigo);

    switch(codigo){

        case 1:
            peso = (peso) * 0.37;
            break;
        case 2:
            peso = (peso) * 0.88;
            break;
        case 3:
            peso = (peso) * 0.38;
            break;
        case 4:
            peso = (peso) * 2.64;
            break;
        case 5:
            peso = (peso) * 1.15;
            break;
        case 6:
            peso = (peso) * 1.17;
            break;
    }

    printf("%f", peso);
}
