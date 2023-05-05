#include <stdio.h>
#include <math.h>
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

void interrompeParaLer(){
    char temp;
    scanf(" %c", &temp);
    
}


void instrucoes(){
    dados(6);
    printf("DADO DE SANGUE\n");
    printf("Pronto para testar a sorte?\n");
    dados(6);

    printf("\nDigite C para continuar.\n");
    interrompeParaLer();

    system("clear || cls");

    printf("\nInstrucoes do jogo:\n\n");
    printf("-> Os jogadores possuem a sua disposicao 2 dados: um branco e um vermelho.\n");
    printf("-> A cada jogada, o jogador tem a opcao de rolar os dados ou passar a vez.\n");
    printf("-> Se optar por rolar os dados, devera:\n");
    printf("   - Iniciar rolando o dado BRANCO, cujo valor soma-se a pontuacao do jogador.\n");
    printf("   - Em seguida, o jogador devera rolar o dado VERMELHO.\n");
    printf("   - Se o valor do dado VERMELHO for 6, o dobro desse valor sera adicionado a pontuacao do jogador.\n");
    printf("   - Sendo outro valor, simplesmente o adicionara a pontuacao do jogador.\n");
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

}

int numAleatorio(){
    int numeroAleatorio = rand()%6 + 1;
    return numeroAleatorio;
}

int turnoDoJogador(int pontTotal){
    char passarOuNao;
    int dadoBRANCO, dadoVERMELHO, pontRodada = 0, pontAtual;

    do{
        printf("\nDigite 'R' rolar os dados ou 'P' para passar a vez ao oponente: ");
        scanf(" %c", &passarOuNao);

        if (passarOuNao != 'R' && passarOuNao != 'r' && passarOuNao != 'P' && passarOuNao != 'p'){
            printf("Parece que voce inseriu uma opcao inexistente. Tente novamente.\n");
        }
        
    }while(passarOuNao != 'R' && passarOuNao != 'r' && passarOuNao != 'P' && passarOuNao != 'p');
    

    if (passarOuNao == 'P' || passarOuNao == 'p'){
        return 0;
    }

    else{
        printf("\nRolando dado BRANCO!\n");
        dadoBRANCO = numAleatorio();
        printf("O numero sorteado no dado BRANCO foi %d.\n", dadoBRANCO);
        pontRodada += dadoBRANCO;
        pontAtual = pontTotal + pontRodada;
        dados(dadoBRANCO);
        
        printf("A sua pontuacao agora equivale a %d (%d + %d).\n", pontAtual, pontTotal, dadoBRANCO);

        printf("Digite P para lancar o proximo dado: ");
        interrompeParaLer();


        printf("\nRolando dado VERMELHO!\n");
        dadoVERMELHO = numAleatorio();
        printf("O numero sorteado no dado VERMELHO foi %d.\n", dadoVERMELHO);
        dados(dadoVERMELHO);

        if (dadoVERMELHO == 6){
            dadoVERMELHO *= 2;
            pontRodada += dadoVERMELHO;
            pontAtual = pontTotal + pontRodada;
            printf("A sua pontuacao agora equivale a %d (%d + 6x2).\n", pontAtual, pontTotal+dadoBRANCO);
        }
        else{
            pontRodada += dadoVERMELHO;
            pontAtual = pontTotal + pontRodada;
            printf("A sua pontuacao agora equivale a %d (%d + %d).\n", pontAtual, pontTotal+dadoBRANCO, dadoVERMELHO);
        }
       
        printf("Digite F para finalizar sua jogada: ");
        interrompeParaLer();

        return pontRodada;
        
    }
}

int turnoDoNPC(int pontTotal, int pontOponente){
    int pontRodada = 0, dadoBRANCO, dadoVERMELHO, pontAtual;
    if (pontTotal > 15 && pontOponente < pontTotal || pontOponente > 21){
        printf("O computador escolheu passar a vez.\n");
        return pontRodada;
        //se a pontuacao esta proxima de passar 21, nao arrisca jogar novamente
        //exceto se o outro jogador ja esta melhor.
        //ademais, nao joga se a partida ja esta ganha/empatada
    }

    else{
        //se ainda esta longe do limite, continua tentando se aproximar de 21
        printf("O computador escolheu lancar os dados.\n");

        printf("\nRolando dado BRANCO!\n");
        dadoBRANCO = numAleatorio();
        printf("O numero sorteado no dado BRANCO do computador foi %d.\n", dadoBRANCO);
        dados(dadoBRANCO);
        pontRodada += dadoBRANCO;
        pontAtual = pontTotal + pontRodada;
        
        printf("A pontuacao do computador agora equivale a %d (%d + %d).\n", pontAtual, pontTotal, dadoBRANCO);

        dadoVERMELHO = numAleatorio();
        printf("\nRolando dado VERMELHO!\n");
        printf("O numero sorteado no dado VERMELHO do computador foi %d.\n", dadoVERMELHO);
        dados(dadoVERMELHO);

        if (dadoVERMELHO == 6){
            dadoVERMELHO *= 2;
            pontRodada += dadoVERMELHO;
            pontAtual = pontTotal + pontRodada;
            printf("A pontuacao do computador agora equivale a %d (%d + 6x2).\n", pontAtual, pontTotal+dadoBRANCO);
        }
        else{
            pontRodada += dadoVERMELHO;
            pontAtual = pontTotal + pontRodada;
            printf("A pontuacao do computador agora equivale a %d (%d + %d).\n", pontAtual, pontTotal+dadoBRANCO, dadoVERMELHO);
        }

    }

    printf("Digite F para finalizar o turno do computador: ");
    interrompeParaLer();

    return pontRodada;

}

void modoPlayerPlayer(){
    
    int pontJogador1 = 0, pontJogador2 = 0;
    char nomeJogador1[16], nomeJogador2[16];

    printf("Insira o nome do Jogador 1: ");
    scanf("%s", &nomeJogador1);
    printf("Insira o nome do Jogador 2: ");
    scanf("%s", &nomeJogador2);

    system("clear || cls");

    printf("Boa sorte, %s e %s...\n", nomeJogador1, nomeJogador2);
        
    for (int rodada = 1; rodada <=3; rodada++){
        printf("\n ------------------------- \n");
        printf("| Rodada n.%d              |\n", rodada);
        printf("| Vez de %-16s |\n", nomeJogador1);
        printf(" ------------------------- \n");
        printf("Sua pontuacao ate agora: %d\n", pontJogador1);
        pontJogador1 += turnoDoJogador(pontJogador1);

        system("clear || cls");

        printf("\n ------------------------- \n");
        printf("| Rodada n.%d              |\n", rodada);
        printf("| Vez de %-16s |\n", nomeJogador2);
        printf(" ------------------------- \n");
        printf("Sua pontuacao ate agora: %d\n", pontJogador2);
        pontJogador2 += turnoDoJogador(pontJogador2);

        system("clear || cls");
        
    }

    if (pontJogador1 > 21 && pontJogador2 > 21){
        printf("Empate!\n Apos 3 jogadas, %s somou %d pontos e %s somou %d pontos.\n", nomeJogador1, pontJogador1, nomeJogador2, pontJogador2);
        printf("Como ambas essas pontuacoes surpassam 21 pontos, a partida terminou em empate.\n");
    }

    else if (pontJogador1 <= 21 && pontJogador2 <= 21){
        if(21-pontJogador1 < 21-pontJogador2){
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos, ficando mais perto de 21!\n", nomeJogador1, pontJogador1);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos.\n", nomeJogador2, pontJogador2);
        }
        else if(21-pontJogador1 > 21-pontJogador2){
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos, ficando mais perto de 21!\n", nomeJogador2, pontJogador2);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos.\n", nomeJogador1, pontJogador1);
        }
        else{
            printf("Empate!\nApos 3 jogadas, %s somou %d pontos e %s somou %d pontos.\n", nomeJogador1, pontJogador1, nomeJogador2, pontJogador2);
            printf("Sendo ambas as pontuacoes iguais, a partida terminou em empate.\n");
        }
    }

    else{
        if(pontJogador2 > 21){
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos!\n", nomeJogador1, pontJogador1);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos e passou de 21.\n", nomeJogador2, pontJogador2);
        }

        else{
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos!\n", nomeJogador2, pontJogador2);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos e passou de 21.\n", nomeJogador1, pontJogador1);
        }
    }
    
}

void modoPlayerNPC(){
    int pontJogador1 = 0, pontNPC = 0;
    char nomeJogador1[16];

    printf("Insira o nome do Jogador 1: ");
    scanf("%s", &nomeJogador1);

    system("clear || cls");

    printf("Boa sorte, %s...\n", nomeJogador1);

    for (int rodada = 1; rodada <=3; rodada++){
        printf("\n ------------------------- \n");
        printf("| Rodada n.%d              |\n", rodada);
        printf("| Vez de %-16s |\n", nomeJogador1);
        printf(" ------------------------- \n");
        printf("Sua pontuacao ate agora: %d\n", pontJogador1);
        pontJogador1 += turnoDoJogador(pontJogador1);

        system("clear || cls");

        printf("\n --------------------\n");
        printf("| Rodada n.%d         |\n", rodada);
        printf("| Vez do Computador. |\n");
        printf(" --------------------\n");
        printf("Pontuacao do Computador ate agora: %d\n", pontNPC);
        pontNPC += turnoDoNPC(pontNPC, pontJogador1);

        system("clear || cls");
        
    }

    if (pontJogador1 > 21 && pontNPC > 21){
        printf("Empate!\nApos 3 jogadas, %s somou %d pontos e o computador somou %d pontos.\n", nomeJogador1, pontJogador1, pontNPC);
        printf("Como ambas essas pontuacoes surpassam 21 pontos, a partida terminou em empate.\n");
    }

    else if (pontJogador1 <= 21 && pontNPC <= 21){
        if(21-pontJogador1 < 21-pontNPC){
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos, ficando mais perto de 21!\n", nomeJogador1, pontJogador1);
            printf("O computador fez %d pontos.\n", pontNPC);
        }
        else if(21-pontJogador1 > 21-pontNPC){
            printf("Perdeu! :(\n");
            printf("O computador foi o Vencedor dessa partida com %d pontos, ficando mais perto de 21!\n", pontNPC);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos.\n", nomeJogador1, pontJogador1);
        }

        else{
            printf("Empate!\nApos 3 jogadas, %s somou %d pontos e o computador somou %d pontos.\n", nomeJogador1, pontJogador1, pontNPC);
            printf("Como essas pontuacoes sao iguais, a partida terminou em empate.\n");
        }
    }

    else{
        if(pontNPC > 21){
            printf("Parabens, %s!\nVoce foi o Vencedor dessa partida com %d pontos!\n", nomeJogador1, pontJogador1);
            printf("O computador fez %d pontos e passou de 21.\n", pontNPC);
        }

        else{
            printf("Perdeu! :(\n");
            printf("O computador foi o Vencedor dessa partida com %d pontos!\n", pontNPC);
            printf("Mais sorte na proxima, %s... Voce fez %d pontos e passou de 21.\n", nomeJogador1, pontJogador1);
        }
    }
    
        
}

void modoDeJogo(){
    char modo;
    char continuarJogando;

    do{
        printf("Voce pode selecionar o modo de jogo:\n");
        printf("Digite a letra correspondente.\n\n\n");
        printf("P - Player x Player (2 jogadores)\n");
        printf("C - Player x Computer (1 jogador, contra a maquina)\n");

        do{
            printf("\n\nSua escolha: ");
            scanf(" %c", &modo);
            if (modo != 'p' && modo != 'P' && modo != 'c' && modo != 'C'){
                printf("Parece que voce nao inseriu um modo de jogo valido. Tente novamente!\n");
            }

        }while(modo != 'p' && modo != 'P' && modo != 'c' && modo != 'C');
        
        if (modo == 'p' || modo == 'P'){
            modoPlayerPlayer();
        }

        else{
            modoPlayerNPC();
        }

        printf("\n\nVoce quer jogar novamente? Digite 's' para sim e 'n' para nao: ");
        scanf(" %c", &continuarJogando);
        system("clear || cls");

    }while(continuarJogando == 's' || continuarJogando == 'S');
    
}

int main(){
    srand(time(NULL));
    instrucoes();
    modoDeJogo();

    dados(6);
    printf("Obrigado por jogar!\n");
    printf("Volte quando quiser testar sua sorte!\n");
    
    printf("\n\n\n");
    printf("Por Guilherme Brizzi");

    interrompeParaLer();
}
