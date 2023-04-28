#include <stdio.h>

void ipva(){
    int mesAtual, placa, digito;
    printf("Insira os ultimos 4 digitos da sua placa: ");
    scanf("%d", &placa);
    printf("Insira o mes atual: ");
    scanf("%d", &mesAtual);

    digito = placa%10;

    printf("Seu ipva vence em ");
    switch(digito){
        case 1:
            printf("janeiro.\n");
            break;
        case 2:
            printf("fevereiro.\n");
            break;
        case 3:
            printf("marco.\n");
            break;
        case 4:
            printf("abril.\n");
            break;
        case 5:
            printf("maio.\n");
            break;
        case 6:
            printf("junho.\n");
            break;
        case 7:
            printf("julho.\n");
            break;
        case 8:
            printf("agosto.\n");
            break;
        case 9:
            printf("setembro.\n");
            break;
        case 10:
            printf("outubro.\n");
            break;
    }

    if ((digito - mesAtual) >= 1)
        printf("Ou seja, vence em %d meses.\n", (digito-mesAtual));

    else
        printf("O ipva vence neste mes.\n");
}

int main(){
    ipva();
}
