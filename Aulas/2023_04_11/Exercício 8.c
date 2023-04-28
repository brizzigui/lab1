#include <stdio.h>

int main(){
    char plano;
    float salario;

    printf("Insira o plano de salario: ");
    scanf("%c", &plano);
    printf("Insira o salario atual: ");
    scanf("%f", &salario);

    switch(plano){
        case 'A':
            salario = salario * 1.09;
            break;
        case 'B':
            salario = salario * 1.13;
            break;
        case 'C':
            salario = salario * 1.17;
            break;

    }

    printf("O salario com aumento equivale a %f", salario);
}
