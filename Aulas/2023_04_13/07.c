#include <stdio.h>

float precoEntrada(){
    float precoOriginal, precoParcial, precoFinal;
    char dia, temAoVivo;

    printf("Insira o preco base da entrada da danceteria: ");
    scanf("%f", &precoOriginal);

    printf("Insira o dia da semana (D, 2, 3, 4, 5, S): ");
    scanf(" %c", &dia);

    printf("Havera musica ao vivo? Digite s para sim e n para nao: ");
    scanf(" %c", &temAoVivo);

    if (temAoVivo == 's' || temAoVivo == 'S'){
        precoParcial = precoOriginal * 1.15;
    }

    else{
        precoParcial = precoOriginal;
    }


    switch(dia){
        case 'D': case '2': case '3':
            precoFinal = precoParcial * 0.75;
            break;

        default: precoFinal = precoParcial;
    }


    return precoFinal;


}

int main(){
    printf("O preco da entrada sera de %.2f nesse dia", precoEntrada());
}
