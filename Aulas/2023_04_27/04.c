#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("Jogo de numero aleatorio\n");
    int tentativas = 0, chute_do_jogador;
    int resposta = rand()%10;
    

    do{

        printf("Chute um numero de 0 a 9: ");
        scanf("%d", &chute_do_jogador);
        tentativas++;
        if (chute_do_jogador != resposta){
            printf("Errado\n\n");
        }

    }while(chute_do_jogador != resposta);

    printf("Acertou! Foram necessarias %d tentativas\n", tentativas);
    
}
