#include <stdio.h>

int main(){
    char opcao;
    float resposta, valor1, valor2;

    printf("Opcoes: 'A' para calcular a media aritmetica, 'P' para calcular a media ponderada");
    printf("e 'R' para o resto inteiro da divisao: ");
    scanf("%c", &opcao);

    printf("Insira os dois valores\n");
    scanf("%f %f", &valor1, &valor2);

    switch(opcao){
        case 'A':
            resposta = (valor1 + valor2)/2;
            break;

        case 'P':
            resposta = 0.4*valor1 + 0.6*valor2;
            break;

        case 'R':
            resposta = (int)valor1%(int)valor2;
            break;
    }

    printf("%f", resposta);
}
