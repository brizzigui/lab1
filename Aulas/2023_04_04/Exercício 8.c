#include <stdio.h>

int main(){
    float preco_gas, odometro_i, odometro_f, km_rodado, gasto_comb, faturamento, lucro, consumo_medio;
    preco_gas = 6.99;

    printf("Insira a marcacao inicial do odometro e a marcacao final, respectivamente: ");
    scanf("%f %f", &odometro_i, &odometro_f);
    printf("Quanto combustivel foi gasto? (em litros) ");
    scanf("%f", &gasto_comb);
    printf("Qual foi o valor total recebido dos passageiros? ");
    scanf("%f", &faturamento);

    km_rodado = odometro_f - odometro_i;
    consumo_medio = km_rodado/gasto_comb;
    lucro = faturamento - gasto_comb*preco_gas;

    printf("O consumo medio foi de %.2f km/l e o lucro foi de %.2f reais", consumo_medio, lucro);




}
