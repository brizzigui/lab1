#include <stdio.h>

int main(){
    float precoEtanol, precoGasolina, kmLEtanol, kmLGasolina, economia;

    printf("Insira, respectivamente, o preco do etanol e da gasolina:\n");
    scanf("%f %f", &precoEtanol, &precoGasolina);

    printf("Insira, respectivamente, os km/l realizados com etanol e gasolina:\n");
    scanf("%f %f", &kmLEtanol, &kmLGasolina);

    if (precoGasolina * (1/kmLGasolina) <= precoEtanol * (1/kmLEtanol)){
        printf("Combustivel recomendado: gasolina\n");

        economia = precoEtanol * (1/kmLEtanol) - precoGasolina * (1/kmLGasolina);
        printf("Usando gasolina, voce vai economizar %f por km\n", economia);

    }

    else{
        printf("Combustivel recomendado: etanol\n");

        economia = precoGasolina * (1/kmLGasolina) - precoEtanol * (1/kmLEtanol);
        printf("Usando etanol, voce vai economizar %.2f por km\n", economia);
    }
}
