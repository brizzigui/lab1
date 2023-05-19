#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 7


void estado_atual(char matriz[TAM][TAM]){
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%3c", matriz[i][j]);
        }

        printf("\n");
    }
    
    printf("\n");
}

char escolha_do_usuario(){

    char escolha;
    printf("Qual orbita da matriz voce quer rotacionar?\n");
    printf("Digite 'E' para externa, 'M' para media e 'I' para interna: ");
    scanf(" %c", &escolha);

    return escolha;

}

void rotaciona_externa(char matriz[TAM][TAM]){
    char temp, aux;

    aux = matriz[0][TAM-1];

    for (int j = TAM-1; j > 0; j--)
    {   
        temp = matriz[0][j-1];
        matriz[0][j-1] = aux;
        aux = temp;
    }

    for (int i = 1; i < TAM; i++)
    {   
        temp = matriz[i][0];
        matriz[i][0] = aux;
        aux = temp;
    }

    for (int j = 1; j < TAM; j++)
    {   
        temp = matriz[6][j];
        matriz[6][j] = aux;
        aux = temp;
    }

    for (int i = TAM-1; i > 0; i--)
    {   
        temp = matriz[i-1][6];
        matriz[i-1][6] = aux;
        aux = temp;
    }
    
}

void rotaciona_media(char matriz[TAM][TAM]){

}

void rotaciona_interna(char matriz[TAM][TAM]){
    char temp, aux;

    aux = matriz[2][TAM-2-1];

    for (int j = TAM-2-1; j > 2; j--)
    {   
        temp = matriz[2][j-1];
        matriz[2][j-1] = aux;
        aux = temp;
    }

    for (int i = 3; i < TAM-2; i++)
    {   
        temp = matriz[i][2];
        matriz[i][2] = aux;
        aux = temp;
    }

    for (int j = 3; j < TAM-2; j++)
    {   
        temp = matriz[4][j];
        matriz[4][j] = aux;
        aux = temp;
    }

    for (int i = TAM-2-1; i > 2; i--)
    {   
        temp = matriz[i-1][4];
        matriz[i-1][4] = aux;
        aux = temp;
    }
}

void movimentar(char matriz[TAM][TAM]){
    
    char escolha = escolha_do_usuario();

    switch (escolha)
    {
        case 'e': case 'E':
            rotaciona_externa(matriz);
            break;
        case 'm': case 'M':
            rotaciona_media(matriz);
            break;
        case 'i': case 'I':
            rotaciona_interna(matriz);
            break;
    
    }


}

void inicializa_matriz(char matriz[TAM][TAM]){
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            matriz[i][j] = '.';
        }

        matriz[0][0] = 'O';
        matriz[1][1] = 'X';
        matriz[0][6] = 'X';
        matriz[1][5] = 'O';
        matriz[2][3] = 'O';
        matriz[3][2] = 'X';
        matriz[3][4] = 'X';
        matriz[4][3] = 'O';
        matriz[5][1] = 'O';
        matriz[5][5] = 'X';
        matriz[6][0] = 'X';
        matriz[6][6] = 'O';

        
    }
    
}


int main(){
    char matriz[TAM][TAM];
    inicializa_matriz(matriz);
    estado_atual(matriz);
    while(1){
        movimentar(matriz);
        estado_atual(matriz);
    }
    
}
