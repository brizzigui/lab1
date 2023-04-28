#include <stdio.h>

int main(){
    float consumo, valorConta = 0;
    printf("Insira o seu consumo de agua, em m3: ");
    scanf("%f", &consumo);

    if (consumo <= 10){
        valorConta = 7;
    }

    else if (consumo <= 30){
        valorConta = 7 + (consumo - 10)*1;
        //desconta o que já está incluso na aliquota anterior e multiplica pela taxa.
    }

    else if (consumo <= 100){
        valorConta = 7 + 20 + (consumo - 30)*2;

    }

    else{
        valorConta = 7 + 20 + 140 +(consumo - 100)*5;
    }

    printf("\nA sua conta equivale a %.2f\n", valorConta);
}
