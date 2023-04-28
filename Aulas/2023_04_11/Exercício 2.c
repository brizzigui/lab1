#include <stdio.h>

int main(){
    char simbolo;
    float total, valorA, valorB;
    printf("Insira dois valores: \n");
    scanf("%f %f", &valorA, &valorB);

    printf("Insira um simbolo: ");
    scanf(" %c", &simbolo);

    switch(simbolo){
        case '+':
            total = valorA + valorB;
            break;
        case '-':
            total = valorA - valorB;
            break;
        case '*':
            total = valorA * valorB;
            break;
        case '/':
            total = valorA / valorB;
            break;

        default: printf("Tente novamente!");
    }

    printf("Resultado: %f", total);
}
