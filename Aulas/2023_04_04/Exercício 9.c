#include <stdio.h>

int main(){
    int cent1, cent5, cent10, cent25, cent50, real1;
    float total;
    printf("Insira, respectivamente, a quantidade de moedas de 1 centavo, 5 centavos, 10 centavos, 25 centavos, 50 centavos e 1 real\n");
    scanf("%d %d %d %d %d %d", &cent1, &cent5, &cent10, &cent25, &cent50, &real1);

    total = cent1*0.01 + cent5*0.05 + cent10*0.1 + cent25*0.25 + cent50*0.5 + real1;

    printf("O total foi de %f", total);

}
