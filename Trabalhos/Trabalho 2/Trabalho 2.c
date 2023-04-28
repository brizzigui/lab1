#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void perguntaJogadorPronto(){
    char jogadorPronto;
    printf("\nVoce esta pronto? (digite 's' para sim, 'n' para nao): ");
    scanf(" %c", &jogadorPronto);

    if (jogadorPronto == 's' || jogadorPronto == 'S'){
        system("clear || cls");
        printf("\nA sorte esta lancada! Que comecem os jogos...\n\n");
    }

    else{
        printf("Entendo... Volte quando a sorte estiver do seu lado.\n\n");
        perguntaJogadorPronto();
    }

}

void instrucoes(){
    dados(3);
    printf("DADOS & PONTOS\n");
    printf("Pronto para testar sua sorte?\n");
    printf("Neste jogo, voce devera contar com a sorte nos dados para ganhar.\n");
    printf("Mas isso sem deixar de lado a estrategia nas suas escolhas.\n");
    dados(5);
    printf("\nClique ENTER para continuar\n");
    scanf("%c");
    system("clear || cls");

    printf("\n-------------------------\n");

    printf("\nINSTRUCOES:\n\n");
    printf("-> O jogo utiliza 2 dados, que permitem ao jogador pontuar, dependendo da combinacao obtida.\n");
    printf("   A seguinte tabela de categorias guia a pontuacao:\n\n");
    printf("   FREE: 2 dados diferentes -> marca-se a soma dos dados\n");
    printf("   RANK: 2 dados diferentes em sequencia -> 20 pontos\n");
    printf("   DOUBLE: 2 dados iguais, porem diferentes de 6 -> 30 pontos\n");
    printf("   MAX: 2 dados iguais a 6 -> 50 pontos.\n\n");
    printf("-> O jogador joga seus 2 dados. A seguir, o jogador tem 3 opcoes: \n");
    printf("   - marcar uma posicao na tabela ja no primeiro lancamento\n");
    printf("   - repetir o lance de apenas um dado\n");
    printf("   - repetir o lance dos 2 dados\n\n");
    printf("-> O jogador deve marcar em uma posicao da tabela que for possivel pelas regras e que seja estrategica.\n");
    printf("-> Exceto para a categoria FREE, se o jogador conseguir, no primeiro lance, os dados para cumprir uma regra, acrescenta 5 pontos a sua pontuacao.\n");
    printf("-> Cada partida tem 4 rodadas, e o vencedor sera quem, apos o decorrer de 3 partidas tiver a maior pontuacao.\n");

    printf("\n-------------------------\n");

    perguntaJogadorPronto();

}

int numAleatorio(){
    int numeroAleatorio = rand()%6 + 1;
    return numeroAleatorio;
}

int ocupadaFREE = 0;
int ocupadaRANK = 0;
int ocupadaDOUBLE = 0;
int ocupadaMAX = 0;

int escolhaPontuacao(int dadoA, int dadoB, int rodada, char primeiroLance){
    int pontuacao = 0;
    char categoria;

    printf("Voce tem as seguintes jogadas disponiveis:\n");

    if (ocupadaMAX == 0){
        if (dadoA == 6 && dadoB == 6){
            if (primeiroLance == 'M' || primeiroLance == 'm'){
                printf("-> pontuar em MAX (55 pts, digite 'M')\n");
            }

            else{
                printf("-> pontuar em MAX (50 pts, digite 'M')\n");
            }

        }

        printf("-> riscar MAX (anula categoria, digite 'X')\n\n");

    }

    if (ocupadaDOUBLE == 0){
        if (dadoA == dadoB) {
            if (primeiroLance == 'M' || primeiroLance == 'm'){
                printf("-> pontuar em DOUBLE (35 pts, digite 'D')\n");
            }

            else{
                printf("-> pontuar em DOUBLE (30 pts, digite 'D')\n");
            }

        }

        printf("-> riscar DOUBLE (anula categoria, digite 'X')\n\n");

    }

    if (ocupadaRANK == 0){
        if ((dadoA == dadoB+1) || (dadoA == dadoB-1)){
            if (primeiroLance == 'M' || primeiroLance == 'm'){
                printf("-> pontuar em RANK (25 pts, digite 'R')\n");
            }

            else{
                printf("-> pontuar em RANK (20 pts, digite 'R')\n");
            }

        }

        printf("-> riscar RANK (anula categoria, digite 'X')\n\n");
    }

    if (ocupadaFREE == 0){
        printf("-> pontuar em FREE (%d pts, digite 'F')\n", dadoA+dadoB);
        printf("-> riscar FREE (anula categoria, digite 'X')\n\n");
    }



    printf("Sua escolha: ");
    scanf(" %c", &categoria);

    switch(categoria){
        case 'F': case 'f':
            printf("Pontuado em FREE.\n");
            pontuacao = dadoA + dadoB;
            ocupadaFREE = 1;
            break;
        case 'R': case 'r':
            printf("Pontuado em RANK.\n");
            pontuacao = 20;
            ocupadaRANK = 1;
            break;
        case 'D': case 'd':
            printf("Pontuado em DOUBLE.\n");
            pontuacao = 30;
            ocupadaDOUBLE = 1;
            break;
        case 'M': case 'm':
            printf("Pontuado em MAX.\n");
            pontuacao = 50;
            ocupadaMAX = 1;
            break;
        case 'X': case 'x':
            printf("Qual categoria voce quer riscar? Digite a inicial: ");
            char categoriaRiscar;
            scanf(" %c", &categoriaRiscar);

            switch(categoriaRiscar){
                case 'F': case 'f':
                    printf("FREE riscada.\n");
                    ocupadaFREE = 1;
                    break;
                case 'R': case 'r':
                    printf("RANK riscada.\n");
                    ocupadaRANK = 1;
                    break;
                case 'D': case 'd':
                    printf("DOUBLE riscada.\n");
                    ocupadaDOUBLE = 1;
                    break;
                case 'M': case 'm':
                    printf("MAX riscada.\n");
                    ocupadaMAX = 1;
                    break;
            }

            break;
    }

    if (primeiroLance == 'M' || primeiroLance == 'm' && pontuacao >= 20)
        pontuacao = pontuacao + 5;

    if (rodada == 4){
        ocupadaFREE = 0;
        ocupadaRANK = 0;
        ocupadaDOUBLE = 0;
        ocupadaMAX = 0;
    }

    return pontuacao;


}

int turnoDoJogador(int rodada){
    int dadoA = numAleatorio();
    int dadoB = numAleatorio();
    printf("Os numeros sorteados foram: %d, %d\n", dadoA, dadoB);
    dados(dadoA);
    dados(dadoB);

    printf("Voce deseja manter esses numeros, lancar 1 dado novamente ou lancar os 2 dados novamente?\n");
    printf("Digite 'M' para manter, '1' para relancar 1 dado e '2' para relancar os 2 dados: ");
    char mantemOuRelanca;
    scanf(" %c", &mantemOuRelanca);

    if (mantemOuRelanca == 'M' || mantemOuRelanca == 'm'){
        printf("\nSeus dados foram mantidos.\n");
    }

    else{
        if (mantemOuRelanca == '1'){
            if (dadoA == dadoB){
                system("clear || cls");
                dadoA = numAleatorio();
                printf("\nO novo dado sorteado foi %d.\n", dadoA);
            }

            else{
                printf("\nQual dado voce deseja relancar? Digite o valor do dado: ");
                int qualRelanca;
                scanf("%d", &qualRelanca);
                system("clear || cls");

                if (qualRelanca == dadoA){
                    dadoA = numAleatorio();
                    printf("O novo dado sorteado foi %d.\n", dadoA);
                }
                else if (qualRelanca == dadoB){
                    dadoB = numAleatorio();
                    printf("O novo dado sorteado foi %d.\n", dadoB);
                }
            }

        }
        else if (mantemOuRelanca == '2'){
            system("clear || cls");
            printf("Relancando ambos dados!\n");
            dadoA = numAleatorio();
            dadoB = numAleatorio();
        }

        printf("Seus dados atuais sao %d, %d.\n", dadoA, dadoB);
        dados(dadoA);
        dados(dadoB);
    }

    int pontuacaoRodada;
    pontuacaoRodada = escolhaPontuacao(dadoA, dadoB, rodada, mantemOuRelanca);

    return pontuacaoRodada;
}


int botOcupadaFREE = 0;
int botOcupadaRANK = 0;
int botOcupadaDOUBLE = 0;
int botOcupadaMAX = 0;

int turnoDoOponente(int rodada){
    int dadoA = numAleatorio();
    int dadoB = numAleatorio();
    int pontuacao = 0;

    printf("O oponente sorteou os dados %d e %d\n", dadoA, dadoB);
    dados(dadoA);
    dados(dadoB);


    if (dadoA == 6 && dadoB == 6 && botOcupadaMAX == 0){
        printf("O oponente escolheu manter os dados.\n");
        printf("O oponente escolheu pontuar na categoria MAX.\n");
        pontuacao = 55;
        botOcupadaMAX = 1;

    }

    else if (botOcupadaDOUBLE == 0 && dadoA == dadoB){
        printf("O oponente escolheu manter os dados.\n");
        printf("O oponente escolheu pontuar na categoria DOUBLE.\n");
        pontuacao = 35;
        botOcupadaDOUBLE = 1;
    }


    else if (botOcupadaRANK == 0 && (dadoA == dadoB-1 || dadoA == dadoB+1)){
        printf("O oponente escolheu manter os dados.\n");
        printf("O oponente escolheu pontuar na categoria RANK.\n");
        pontuacao = 25;
        botOcupadaRANK = 1;
    }

    else if(dadoA + dadoB >= 10 && botOcupadaFREE == 0){
        printf("O oponente escolheu manter os dados.\n");
        printf("O oponente escolheu pontuar na categoria FREE.\n");
        pontuacao = dadoA + dadoB;
        botOcupadaFREE = 1;
    }

    else{
        if(botOcupadaMAX == 1 && botOcupadaDOUBLE == 1 && botOcupadaRANK == 1){
            if (dadoA > 4 && dadoB < 4){
                printf("O oponente escolheu relancar um dos dados.\n");
                dadoB = numAleatorio();
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);
            }

            else if (dadoB >= 4 && dadoA <= 4){
                printf("O oponente escolheu relancar um dos dados.\n");
                dadoA = numAleatorio();
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);
            }

            else{
                dadoA = numAleatorio();
                dadoB = numAleatorio();
                printf("O oponente escolheu relancar ambos dados.\n");
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);
            }

            printf("O oponente escolheu pontuar na categoria FREE.\n");
            pontuacao = dadoA + dadoB;
            botOcupadaFREE = 1;

        }

        else{
            if(dadoA == 6 && botOcupadaMAX == 0){
                printf("O oponente escolheu relancar um dos dados.\n");
                dadoB = numAleatorio();
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);

                if (dadoA == dadoB){
                    printf("O oponente escolheu pontuar na categoria MAX.\n");
                    pontuacao = 50;
                    botOcupadaMAX = 1;
                }

                else{
                    printf("O oponente escolheu riscar a categoria MAX.\n");
                    botOcupadaMAX = 1;
                }
            }

            else if(dadoB == 6 && botOcupadaMAX == 0){
                printf("O oponente escolheu relancar um dos dados.\n");
                dadoA = numAleatorio();
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);

                if (dadoA == dadoB){
                    printf("O oponente escolheu pontuar na categoria MAX.\n");
                    pontuacao = 50;
                    botOcupadaMAX = 1;
                }

                else{
                    printf("O oponente escolheu riscar a categoria MAX.\n");
                    botOcupadaMAX = 1;
                }
            }

            else{
                dadoA = numAleatorio();
                dadoB = numAleatorio();
                printf("O oponente escolheu relancar ambos dados.\n");
                printf("Agora, os dados do oponente sao: %d e %d.\n", dadoA, dadoB);
                dados(dadoA);
                dados(dadoB);

                if(botOcupadaMAX == 0 && dadoA == 6 && dadoB == 6){
                    printf("O oponente escolheu pontuar na categoria MAX.\n");
                    pontuacao = 50;
                    botOcupadaMAX = 1;

                }

                else if (botOcupadaDOUBLE == 0 && dadoA == dadoB){
                    printf("O oponente escolheu pontuar na categoria DOUBLE.\n");
                    pontuacao = 30;
                    botOcupadaDOUBLE = 1;
                }

                else if (botOcupadaRANK == 0 && (dadoA == dadoB-1 || dadoA == dadoB+1)){
                    printf("O oponente escolheu pontuar na categoria RANK.\n");
                    pontuacao = 20;
                    botOcupadaRANK = 1;
                }

                else if (botOcupadaFREE == 0){
                    printf("O oponente escolheu pontuar na categoria FREE.\n");
                    pontuacao = dadoA + dadoB;
                    botOcupadaFREE = 1;
                }

                else if(botOcupadaMAX == 0){
                    printf("O oponente escolheu riscar a categoria MAX.\n");
                    botOcupadaMAX = 1;
                }

                else if(botOcupadaDOUBLE == 0){
                    printf("O oponente escolheu riscar a categoria DOUBLE.\n");
                    botOcupadaDOUBLE = 1;
                }

                else if(botOcupadaRANK == 0){
                    printf("O oponente escolheu riscar a categoria RANK.\n");
                    botOcupadaRANK = 1;
                }

                else if(botOcupadaFREE == 0){
                    printf("O oponente escolheu riscar a categoria FREE.\n");
                    botOcupadaFREE = 1;
                }

            }
        }

    }

    if (rodada == 4){
        botOcupadaFREE = 0;
        botOcupadaRANK = 0;
        botOcupadaDOUBLE = 0;
        botOcupadaMAX = 0;
    }

    return pontuacao;
}

int main(){
    srand(time(NULL));

    instrucoes();

    printf("Insira o nome do Jogador 1: ");
    char nomeJogador[30];
    scanf("%s", nomeJogador);
    system("clear || cls");
    printf("Boa sorte, %s.\n\n", nomeJogador);

    int pontJogadorPartida = 0, pontJogadorTotal = 0, pontOponentePartida = 0, pontOponenteTotal = 0;

    for(int jogo = 1; jogo <= 3; jogo++){
        for (int rodada = 1; rodada <= 4; rodada++){
            printf("Partida n.%d\n", jogo);
            printf("Rodada n.%d\n", rodada);

            printf("\nSua vez, %s...\n", nomeJogador);
            int pontJogadorRodada = turnoDoJogador(rodada);

            printf("Sua pontuacao nessa rodada foi de %d pts.", pontJogadorRodada);
            pontJogadorPartida = pontJogadorPartida + pontJogadorRodada;

            printf("\n-------------------------\n");
            printf("\nDigite T para passar para o turno do oponente.\n");
            scanf(" %c");
            system("clear || cls");

            printf("Partida n.%d\n", jogo);
            printf("Rodada n.%d\n", rodada);
            printf("Vez do oponente...\n");
            int pontOponenteRodada = turnoDoOponente(rodada);

            printf("A pontuacao do oponente nessa rodada foi de %d pts.", pontOponenteRodada);
            pontOponentePartida = pontOponentePartida + pontOponenteRodada;

            printf("\n-------------------------\n");
            printf("\nDigite P para ir para a proxima rodada.\n");
            scanf(" %c");
            pontJogadorRodada = 0;
            pontOponenteRodada = 0;
            system("clear || cls");
        }
        printf("Sua pontuacao nessa partida foi de %d pts.\n", pontJogadorPartida);
        printf("Essa foi a partida n.%d\n", jogo);
        pontJogadorTotal = pontJogadorTotal + pontJogadorPartida;

        printf("A pontuacao do oponente foi de %d pts.\n", pontOponentePartida);
        pontOponenteTotal = pontOponenteTotal + pontOponentePartida;

        printf("\n-------------------------\n");
        printf("Placar geral:\n");
        printf("%s - %d x %d - PC", nomeJogador, pontJogadorTotal, pontOponenteTotal);
        printf("\n-------------------------\n");
        printf("\nDigite P para ir para a proxima partida.\n");
        scanf(" %c");
        system("clear || cls");
        pontJogadorPartida = 0;
        pontOponentePartida = 0;

    }

    dados(6);
    printf("Fim do jogo!\n\n");
    if (pontJogadorTotal > pontOponenteTotal){
        printf("Voce, %s, foi o vencedor! A sorte esteve convosco :)\n", nomeJogador);
        printf("Parabens! Sua pontuacao foi de %d pts e a do oponente foi %d pts.\n", pontJogadorTotal, pontOponenteTotal);
    }

    else if (pontJogadorTotal == pontOponenteTotal){
        printf("O impossivel aconteceu: Empate!\n");
        printf("Tanto voce quanto o oponente obtiveram %d pts.\n", pontJogadorTotal);
    }

    else if (pontJogadorTotal < pontOponenteTotal){
        printf("Sinto muito, %s, voce perdeu! Mais sorte na proxima vez!\n", nomeJogador);
        printf("O oponente fez %d pts e voce fez apenas %d pts... :(\n", pontOponenteTotal, pontJogadorTotal);
    }

    printf("\n\n\n");
    dados(5);
    printf("Obrigado por jogar! :)\n");
    printf("Por Guilherme Brizzi\n");
    dados(3);
    printf("\n\n\n");
}
