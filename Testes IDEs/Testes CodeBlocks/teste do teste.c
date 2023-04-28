#include <stdio.h>

int main(){
    printf("Na sua vez, digite f quando por um número múltiplo de 3, b, quando múltiplo de 5 e z, quando múltiplo de ambos\n");
    int num = 0;

    while (1){
        num = num + 1;

        if ((num%2) != 0){
            //vez do npc
            if (num%3 == 0 && num%5 == 0){
                printf("FizzBuzz\n");
            }
            else{
                if (num%3 != 0 && num%5 != 0){
                    printf("%d\n", num);
                }
                else{
                    if (num%3 == 0){
                        printf("Fizz\n");
                    }
                    if (num%5 == 0){
                        printf("Buzz\n");
                    }
                }
            }
        }
        else {
            //vez do jogador
            char resposta_do_jogador;
            char resposta_correta;
            scanf(" %c", &resposta_do_jogador);
            if (num%3 == 0 && num%5 == 0){
                resposta_correta = 'z';
            }
            else{
                if (num%3 != 0 && num%5 != 0){
                    resposta_correta = num;
                    printf("%d", resposta_correta);
                }
                else{
                    if (num%3 == 0){
                        resposta_correta = 'f';
                    }
                    if (num%5 == 0){
                        resposta_correta = 'b';
                    }
                }
            }
            //checa resposta do jogador
            printf("%c",resposta_do_jogador);
            printf("%c",resposta_correta);

            if (resposta_do_jogador == resposta_correta){
                continue;
            }
            else{
                printf("Errou! A resposta correta era: %c, mas tu respondeu %c", resposta_correta, resposta_do_jogador);
                break;
            }
        }
    }
    return 0;
}
