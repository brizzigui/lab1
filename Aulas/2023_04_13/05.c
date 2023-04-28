#include <stdio.h>

float quadrado(){
    float lado, area;
    printf("Insira o valor do lado do quadrado: ");
    scanf("%f", &lado);
    area = lado*lado;
    printf("A area equivale a %.2f\n\n\n", area);

    menu();
}

float retangulo(){
    float largura, comprimento, area;
    printf("Insira o valor da largura e do comprimento do retangulo: ");
    scanf("%f %f", &largura, &comprimento);
    area = largura*comprimento;
    printf("A area equivale a %.2f\n\n\n", area);

    menu();
}

float triangulo(){
    float base, altura, area;
    printf("Insira o valor da base e da altura do triangulo: ");
    scanf("%f %f", &base, &altura);
    area = base*altura*0.5;
    printf("A area equivale a %.2f\n\n\n", area);

    menu();
}

float trapezio(){
    float baseMenor, baseMaior, altura, area;
    printf("Insira o valor da base menor, da base maior e da altura do trapezio: ");
    scanf("%f %f %f", &baseMenor, &baseMaior, &altura);
    area = (baseMaior + baseMenor) * 0.5  * altura;
    printf("A area equivale a %.2f\n\n\n", area);

    menu();
}


void menu(){
    char figura;
    printf("De qual figura voce deseja calcular a area?\n");
    printf("Digite 'q' para o quadrado, 'r' para o retangulo, 't' para o triangulo e 'p' para o trapezio.\n");
    printf("Sua opcao: ");
    scanf(" %c", &figura);

    switch(figura){
        case 'q':
            quadrado();
            break;
        case 'r':
            retangulo();
            break;
        case 't':
            triangulo();
            break;
        case 'p':
            trapezio();
            break;
    }
}

int main(){
    menu();
}
