#include <stdio.h>

int main(){
    float base, altura, area;

    printf("Insira a base: ");
    scanf("%f", &base);

    printf("Insira a altura: ");
    scanf("%f", &altura);

    area = base*altura/2;
    printf("Area igual a %.2f", area);

}
