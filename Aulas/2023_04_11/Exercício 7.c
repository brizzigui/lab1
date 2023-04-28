#include <stdio.h>

int main(){
    char MouF;
    float peso, altura;

    printf("Insira M para o calculo masculino e F para o calculo feminino: ");
    scanf("%c", &MouF);

    printf("\nInsira sua altura: ");
    scanf("%f", &altura);

    switch(MouF){
        case 'M': case 'm':
            peso = (altura - 100) * 0.9;
            break;
        case 'F': case 'f':
            peso = (altura - 100) * 0.85;
            break;
    }

    printf("O peso ideal equivale a %f", peso);

}
