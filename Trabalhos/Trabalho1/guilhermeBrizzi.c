#include <stdio.h>

int main(){
    float tarifaLitoral = 216.72;
    float tarifaCapital = 157.36;
    float tarifaSerra = 182.19;
    float tarifaFronteira = 259.41;
    float tarifaInterEst = 368.92;

    printf("- Sistema de Compra de Passagens -\n");

    printf("\nTablela de tarifas:\n");
    printf("Codigo - Destino - Tarifa\n");
    printf("1 -> Litoral - %.2f\n", tarifaLitoral);
    printf("2 -> Capital - %.2f\n", tarifaCapital);
    printf("3 -> Serra - %.2f\n", tarifaSerra);
    printf("4 -> Fronteira - %.2f\n", tarifaFronteira);
    printf("5 -> Interestadual - %.2f\n\n", tarifaInterEst);

    printf("Digite um codigo para continuar sua compra: ");
    int codigo;
    scanf("%d", &codigo);

    float valorBaseUnitario;

    switch(codigo){
        case 1:
            printf("\nDestino selecionado: Litoral\n");
            valorBaseUnitario = tarifaLitoral;
            break;

        case 2:
            printf("\nDestino selecionado: Capital\n");
            valorBaseUnitario = tarifaCapital;
            break;

        case 3:
            printf("\nDestino selecionado: Serra\n");
            valorBaseUnitario = tarifaSerra;
            break;

        case 4:
            printf("\nDestino selecionado: Fronteira\n");
            valorBaseUnitario = tarifaFronteira;
            break;

        case 5:
            printf("\nDestino selecionado: Interestadual\n");
            valorBaseUnitario = tarifaInterEst;
            break;

        default:
            printf("Parece que um destino inexistente foi pedido. Tente novamente.\n");
            return 0;
    }

    int numeroDePassagens;
    char temIdaEVolta, temSeguro;

    printf("\nQuantas passagens voce gostaria de comprar? ");
    scanf("%d", &numeroDePassagens);
    if (numeroDePassagens < 1){
        printf("Quantia invalida. Tente novamente.\n");
        return 0;
    }

    printf("\nVoce deseja comprar ida e volta para essa viagem?\nDigite 's' para sim e 'n' para nao: ");
    scanf(" %c", &temIdaEVolta);

    printf("\nVoce deseja adicionar um seguro-viagem a sua compra?\nDigite 's' para sim e 'n' para nao: ");
    scanf(" %c", &temSeguro);

    float valorTotalDasPassagens, valorTotal, valorFinal;
    float valorDesconto = 0, valorSeguro = 0;

    float taxasVoltas = 0;

    if (temIdaEVolta == 's' || temIdaEVolta == 'S'){
        taxasVoltas = numeroDePassagens * 1.5;
        numeroDePassagens = numeroDePassagens*2;
    }

    switch(numeroDePassagens){
        case 1:
            valorTotalDasPassagens = valorBaseUnitario;
            break;
        case 2:
            valorDesconto = valorBaseUnitario*0.09;
            valorTotalDasPassagens = valorBaseUnitario*numeroDePassagens - valorDesconto;
            break;
        case 3:
            valorDesconto = valorBaseUnitario*0.11 + valorBaseUnitario*0.13;
            valorTotalDasPassagens = valorBaseUnitario*numeroDePassagens - valorDesconto;
            break;
        case 4:
            valorDesconto = 3*valorBaseUnitario*0.15;
            valorTotalDasPassagens = valorBaseUnitario*numeroDePassagens - valorDesconto;
            break;

        default:
            valorDesconto = numeroDePassagens*valorBaseUnitario*0.16;
            valorTotalDasPassagens = valorBaseUnitario*numeroDePassagens - valorDesconto;
            break;

    }

    if (temSeguro == 's' || temSeguro == 'S'){
        valorSeguro = 0.0216 * valorBaseUnitario * numeroDePassagens;
        valorTotal = valorTotalDasPassagens + valorSeguro;
    }

    else{
        valorTotal = valorTotalDasPassagens;
    }

    valorFinal = valorTotal + taxasVoltas;

    printf("\n\n-------  Resumo da Compra  -------\n\n");
    if (temIdaEVolta == 's' || temIdaEVolta == 'S'){
        printf("Valor base da compra: R$%.2f ", valorBaseUnitario*numeroDePassagens);
        printf(" - (%d passagens x 2, valor unitario: %.2f)\n",numeroDePassagens/2, valorBaseUnitario);
    }

    else{
        printf("Valor base da compra: R$%.2f ", valorBaseUnitario*numeroDePassagens);
        printf(" - (%d passagens, valor unitario: %.2f)\n",numeroDePassagens, valorBaseUnitario);
    }

    if (valorDesconto != 0)
        printf("Valor do desconto: R$%.2f\n", valorDesconto);

    printf("Valor da compra: R$%.2f \n", valorTotalDasPassagens);

    if (valorSeguro != 0)
        printf("Valor do seguro: R$%.2f\n", valorSeguro);

    printf("\n----------------------------------\n");
    printf("Subtotal: R$%.2f", valorTotal);
    printf("\n----------------------------------\n");


    printf("\n----------------------------------\n");

    float percentualDiferenca;
    if (temIdaEVolta == 's' || temIdaEVolta == 'S'){
        printf("Valor Final: R$%.2f -> ida e volta -> (R$%.2f + taxas)", valorFinal, valorTotal);
        percentualDiferenca = valorFinal / (valorBaseUnitario*numeroDePassagens);
    }

    else{
        printf("Valor Final: R$%.2f", valorFinal);
        percentualDiferenca = valorFinal / (valorBaseUnitario*numeroDePassagens);
    }

    printf("\n----------------------------------\n\n\n");

    if (percentualDiferenca > 1){
        printf("O valor final foi %.2f%% maior que o preco inicial", (percentualDiferenca-1)*100);
        printf("\n(para a quantia de trechos e passagens compradas)\n");
    }

    else if (percentualDiferenca < 1){
        printf("O valor final foi %.2f%% menor que o preco inicial", (1-percentualDiferenca)*100);
        printf("\n(para a quantia de trechos e passagens compradas)\n");
    }

    else{
        printf("O valor final foi igual ao preco inicial");
        printf("\n(para a quantia de trechos e passagens compradas)\n");
    }


    printf("\n------------- Pontos -------------\n");

    int pontos;
    pontos = valorFinal / 120;
    printf("\nEssa compra gerou %d pontos :)\n", pontos);
    printf("Voce pode usa-los para resgatar barrinhas de cereal ou garrafas d'agua!\n");

    if (pontos >= 2){
        char resgataOuNao;
        printf("\nGostaria de resgatar seus brindes? \nDigite 's' para sim e 'n' para nao: ");
        scanf(" %c", &resgataOuNao);

        if (resgataOuNao == 's' || resgataOuNao == 'S'){
            int aguas = 0, barrinhas = 0, pedido;

            if (pontos >= 5){
                printf("\nVoce tem credito suficiente para ate %d barrinhas e ate %d aguas\n", pontos/2, pontos/5);
                printf("Quantas garrafas d'agua voce quer resgatar? ");
                scanf("%d", &pedido);

                if (pedido > pontos/5 || pedido < 0){
                    printf("Resgate falhou! :( Tente novamente!\n");
                    return 0;
                }

                else{
                    printf("Resgate com sucesso!\n");
                    aguas += pedido;
                    pontos = pontos - pedido*5;
                }
            }

            if (pontos >= 2){
                printf("\nAgora, voce tem credito suficiente para ate %d barrinhas\n", pontos/2);
                printf("Quantas barrinhas voce quer resgatar? ");
                scanf("%d", &pedido);

                if (pedido > pontos/2 || pedido < 0){
                    printf("Resgate falhou! :( Tente novamente!\n");
                    return 0;
                }

                else{
                    printf("Resgate com sucesso!\n");
                    barrinhas += pedido;
                    pontos = pontos - pedido*2;
                }
            }

            printf("\n----------------------------------\n\n");
            printf("\nVoce ganhou um total de %d barrinhas e %d garrafas d'agua.\n", barrinhas, aguas);
        }

    }


    else{
        printf("Voce ainda nao acumulou pontos suficientes para realizar resgates.\n");
    }

    printf("\n\n----------------------------------\n\n");
    printf("Obrigado pela preferencia! :)");
    printf("\n\n----------------------------------\n\n\n\n");

}
