#include <stdio.h>

void gastoDiesel(){
    printf("Insira a quilometragem: ");
    float quilometragem, gasto;
    scanf("%f", &quilometragem);

    if (quilometragem < 0 || quilometragem > 900){
        printf("Quilometragem invalida. Tente novamente!");
        gastoDiesel();
    }

    gasto = (quilometragem/10) * 2.5;

    if (quilometragem/10 > 45){
        gasto = gasto + (quilometragem/10 - 45) * 2.3;
    }

    printf("\nO gasto com diesel foi de R$%.2f para rodar %.2f km\n", gasto, quilometragem);
}

int main(){

    gastoDiesel();
}
