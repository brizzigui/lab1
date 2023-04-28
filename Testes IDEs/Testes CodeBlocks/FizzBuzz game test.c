#include <stdio.h>
#include <string.h>
//essa segunda biblioteca deixa usar strcpy e outros

int main(){

    printf("Nesse jogo, voce devera reconhecer se os numeros sao multiplos de 3 ou 5\n");
    printf("Caso eles sejam multiplos de 3, voce devera escrever Fizz no lugar do numero\n");
    printf("Se for multiplo de 5, porem, voce devera escrever Buzz\n");
    printf("E se for multiplo de 3 e 5 simultaneamente, escreva FizzBuzz\n");
    printf("Voce alternara turnos com o PC enquanto joga, devendo apenas responder aos numeros da sua vez\n");
    printf("\n");
    printf("Boa sorte!\n");
    printf("\n");


    int num = 0;
    char respostaCorreta[16];
    char respostaDoJogador[16];

    while (1){
        num = num + 1;
        if (num%2 != 0){
            //vez do npc
            if (num%3 == 0 && num%5 == 0){
                strcpy(respostaCorreta, "FizzBuzz");

            }

            else {
                if (num%3 == 0){
                    strcpy(respostaCorreta, "Fizz");
                }
                if (num%5 == 0){
                    strcpy(respostaCorreta, "Buzz");
                }
                if (num%3 && num%5 != 0){
                    sprintf(respostaCorreta, "%d", num);
                    //sprintf converte int em string, pegando valor de num e colocando em respostaCorreta
                }

            }
            printf("%s",respostaCorreta);


        }

        else{
            //vez do jogador
            printf("\n");
            if (num%3 == 0 && num%5 == 0){
                strcpy(respostaCorreta, "FizzBuzz");

            }

            else {
                if (num%3 == 0){
                    strcpy(respostaCorreta, "Fizz");
                }
                if (num%5 == 0){
                    strcpy(respostaCorreta, "Buzz");
                }
                if (num%3 && num%5 != 0){
                    sprintf(respostaCorreta, "%d", num);
                }

            }

            scanf("%s", respostaDoJogador);
            int value = 0;
            value = strcmp(respostaCorreta,respostaDoJogador);
            //compara as strings retornando um valor 0 se iguais
            //não é possível fazer a comparação direta como se faria em python

            if (value == 0){
                continue;
            }

            else{
                printf("\n");
                printf("A resposta correta era %s\n", respostaCorreta);
                printf("Mas a sua resposta foi %s\n", respostaDoJogador);
                printf("Errou!\n");
                break;
                return 0;
            }
        }

    }

}
