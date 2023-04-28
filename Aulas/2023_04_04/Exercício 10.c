#include <stdio.h>

int main(){
    int carros;
    float diaria, faturamento, multas;

    printf("Total de carros: ");
    scanf("%d", &carros);
    printf("Valor da diaria: ");
    scanf("%f", &diaria);

    faturamento = (carros * diaria * 12 / 3);
    printf("O faturamento anual foi de %.2f\n", faturamento);

    multas = (0.1 * carros * 0.1 * diaria / 3);
    printf("O valor de multas equivale a %.2f\n", multas);

    carros = carros - 0.05 * carros + 1/8 * carros;
    printf("O numero de carros no fim do ano sera %d\n", carros);



}
