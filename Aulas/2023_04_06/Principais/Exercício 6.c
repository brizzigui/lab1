#include <stdio.h>

int main(){
    char homemOuMulher;
    float altura, pesoIdeal;

    printf("Digite H para o calculo masculino e M para o calculo feminino: ");
    scanf(" %c", &homemOuMulher);

    if (homemOuMulher != 'H' && homemOuMulher != 'M'){
        printf("Tente novamente!\n");
        main();
    }
    printf("Digite a sua altura em centimetros: ");
    scanf("%f", &altura);

    if (homemOuMulher == 'H'){
        pesoIdeal = (72.7 * 0.01 * altura - 58);
    }

    if (homemOuMulher == 'M'){
        pesoIdeal = (62.1 * 0.01 * altura - 44.7);
    }

    printf("De acordo com essa formula, seu peso ideal seria %f", pesoIdeal);

}
