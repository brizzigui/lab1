#include <stdio.h>

int main(){
    float temperaturaC, temperaturaF;
    printf("Insira a temperatura em Celsius: ");
    scanf("%f", &temperaturaC);

    temperaturaF = temperaturaC * 1.8 + 32;

    printf("%.2f", temperaturaF);

}
