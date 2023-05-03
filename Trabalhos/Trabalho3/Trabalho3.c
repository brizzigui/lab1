#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char temp;

void dados(int numeroDado){
    switch(numeroDado){
        case 1:
            printf(" -------\n");
            printf("|       |\n");
            printf("|   O   |\n");
            printf("|       |\n");
            printf(" -------\n");
            break;

        case 2:
            printf(" -------\n");
            printf("|     O |\n");
            printf("|       |\n");
            printf("| O     |\n");
            printf(" -------\n");
            break;

        case 3:
            printf(" -------\n");
            printf("|     O |\n");
            printf("|   O   |\n");
            printf("| O     |\n");
            printf(" -------\n");
            break;

        case 4:
            printf(" -------\n");
            printf("| O   O |\n");
            printf("|       |\n");
            printf("| O   O |\n");
            printf(" -------\n");
            break;

        case 5:
            printf(" -------\n");
            printf("| O   O |\n");
            printf("|   O   |\n");
            printf("| O   O |\n");
            printf(" -------\n");
            break;

        case 6:
            printf(" -------\n");
            printf("| O   O |\n");
            printf("| O   O |\n");
            printf("| O   O |\n");
            printf(" -------\n");
            break;
    }
}

char instrucoes(){
    dados(6);
    printf("VERMELHO E BRANCO\n");
    printf("Pronto para testar a sorte?\n");
    dados(6);

    printf("\nDigite C para continuar.\n");
    scanf(" %c", &temp);

    system("clear || cls");

    printf("\nInstrucoes do jogo:\n\n");
    printf("-> Os jogadores possuem a sua disposição 2 dados: um branco e um vermelho.\n");
    printf("-> A cada jogada, o jogador tem a opção de rolar os dados ou passar a vez.\n");
    printf("-> Se optar por rolar os dados, devera:");
    printf("   - Iniciar rolando o dado BRANCO, cujo valor soma-se a pontuacao do jogador.\n");
    printf("   - Em seguida, o jogador devera rolar o dado VERMELHO.\n");
    printf("   - Se o valor do dado VERMELHO for 6, o dobro desse valor sera adicionado a pontuacao do jogador.\n");
    printf("   - Sendo outro valor, simplesmente o adicionara a pontuacao do jogodador.\n");
    printf("-> Cada partida compoe-se por 3 jogadas, em que o jogador alterna turnos com outro jogador, ou com o Computador.\n");
    printf("-> Ganha a partida o jogador que, tendo feito menos de 21 pontos, estiver mais perto de 21.\n");
    printf("   - Se ambos estiverem a mesma distancia de 21, a partida empata.\n");
    printf("-> Caso ambos jogadores tenham feito mais de 21 pontos, a partida empata.\n");


    char entendeuInstrucoes;

    do{
        printf("\nVoce entendeu as instrucoes? (Digite 's' para sim e 'n' para nao): ");
        scanf(" %c", &entendeuInstrucoes);
        if (entendeuInstrucoes != 's' && entendeuInstrucoes != 'S'){
            printf("Entendo... Volte quando a sorte estiver convosco!\n\n\n");
            printf("---------------------");
        }
    }while(entendeuInstrucoes != 's' && entendeuInstrucoes != 'S');

    system("clear || cls");


    char modoDeJogo;

    printf("Voce pode selecionar o modo de jogo:\n");
    printf("Digite a letra correspondente.\n\n\n");
    printf("P - Player x Player (2 jogadores)\n");
    printf("C - Player x Computer (1 jogador, contra a maquina)\n");

    do{
        printf("\n\nSua escolha: ");
        scanf(" %c", &modoDeJogo);
        if (modoDeJogo != 'p' && modoDeJogo != 'P' && modoDeJogo != 'c' && modoDeJogo != 'C'){
            printf("Parece que voce nao inseriu um modo de jogo valido. Tente novamente!\n");
        }
    }while(modoDeJogo != 'p' && modoDeJogo != 'P' && modoDeJogo != 'c' && modoDeJogo != 'C');
    
    return modoDeJogo;
    

}

int numAleatorio(){
    int numeroAleatorio = rand()%6 + 1;
    return numeroAleatorio;
}

int turnoDoJogador(int pontTotal){
    char passarOuNao;
    int dadoBRANCO, dadoVERMELHO, pontRodada = 0, pontAtual;

    printf("\nDigite 'R' rolar os dados ou 'P' para passar a vez ao oponente: ");
    scanf(" %c", &passarOuNao);

    if (passarOuNao == 'P' || passarOuNao == 'p'){
        printf("Turno passado ao oponente!\n");
        return 0;
    }

    else{
        printf("Rolando dado BRANCO!\n");
        dadoBRANCO = numAleatorio();
        printf("O numero sorteado no dado BRANCO foi %d.\n", dadoBRANCO);
        pontRodada += dadoBRANCO;
        pontAtual = pontTotal + pontRodada;
        dados(dadoBRANCO);
        
        printf("A sua pontuacao agora equivale a %d (%d + %d).\n", pontAtual, pontTotal, dadoBRANCO);

        printf("Digite P para lancar o proximo dado: ");
        scanf(" %c", &temp);


        printf("Rolando dado VERMELHO!\n");
        dadoVERMELHO = numAleatorio();
        printf("O numero sorteado no dado VERMELHO foi %d.\n", dadoVERMELHO);
        if (dadoVERMELHO == 6){
            dadoVERMELHO *= 2;
            pontRodada += dadoVERMELHO;
        }
        else{
            pontRodada += dadoVERMELHO;
        }

        pontAtual = pontTotal + pontRodada;
        dados(dadoVERMELHO);
        
        printf("A sua pontuacao agora equivale a %d (%d + %d).\n", pontAtual, pontTotal+dadoBRANCO, dadoVERMELHO);

        printf("Digite F para finalizar sua jogada: ");
        scanf(" %c", &temp);

        return pontRodada;
        
    }
}

int turnoDoNPC(){

}

int modoPlayerPlayer(){
    
    char continuarJogando;
    int pontJogador1 = 0, pontJogador2 = 0;
    char nomeJogador1[32], nomeJogador2[32];

    printf("Insira o nome do Jogador 1: ");
    scanf("%s", &nomeJogador1);
    printf("Insira o nome do Jogador 2: ");
    scanf("%s", &nomeJogador2);

    system("clear || cls");

    printf("Boa sorte, %s e %s...\n", nomeJogador1, nomeJogador2);

    do{
        
        for (int rodada = 1; rodada <=3; rodada++){
            printf("Rodada n.%d\n", rodada);
            printf("Vez de %s.\n", nomeJogador1);
            printf("---------------------\n");
            printf("Sua pontuacao ate agora: %d\n", pontJogador1);
            pontJogador1 += turnoDoJogador(pontJogador1);

            system("clear || cls");

            printf("Rodada n.%d\n", rodada);
            printf("Vez de %s.\n", nomeJogador2);
            printf("---------------------\n");
            printf("Sua pontuacao ate agora: %d\n", pontJogador2);
            pontJogador2 += turnoDoJogador(pontJogador2);

            system("clear || cls");
            
        }

        if (pontJogador1 > 21 && pontJogador2 > 21){
            printf("Empate! Apos 3 jogadas, %s somou %d pontos e %s somou %d pontos.\n", nomeJogador1, pontJogador1, nomeJogador2, pontJogador2);
            printf("Como ambas essas pontuacoes surpassam 21 pontos, a partida terminou em empate.\n");
        }

        else if (pontJogador1 <= 21 && pontJogador2 <= 21){
            if(fabs(21-pontJogador1) < fabs(21-pontJogador2)){
                printf("Parabens, %s. Voce foi o Vencedor dessa partida com %d pontos!\n", nomeJogador1, pontJogador1);
                printf("Mais sorte na proxima, %s... Voce fez %d pontos.\n", nomeJogador2, pontJogador2);
            }
            else if(fabs(21-pontJogador1) > fabs(21-pontJogador2)){
                printf("Parabens, %s. Voce foi o Vencedor dessa partida com %d pontos!\n", nomeJogador2, pontJogador2);
                printf("Mais sorte na proxima, %s... Voce fez %d pontos.\n", nomeJogador1, pontJogador1);
            }

            else{
                printf("Empate! Apos 3 jogadas, %s somou %d pontos e %s somou %d pontos.\n", nomeJogador1, pontJogador1, nomeJogador2, pontJogador2);
                printf("Como essas pontuacoes sao iguais, a partida terminou em empate.\n");
            }
        }
        


        scanf(" %c", &continuarJogando);

    }while(continuarJogando == 's' || continuarJogando == 'S');
}

int modoPlayerNPC(){

}

int main(){
    srand(time(NULL));
    char modoDeJogo = instrucoes();
    if (modoDeJogo != 'p' || modoDeJogo != 'P'){
        modoPlayerPlayer();
    }

    else{
        modoPlayerNPC();
    }
}
