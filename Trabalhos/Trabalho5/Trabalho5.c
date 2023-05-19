#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 7


void estado_atual(char matriz[TAM][TAM]){

    printf("\n");

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

    do
    {
        printf("Digite 'E' para externa, 'M' para media e 'I' para interna: ");
        scanf(" %c", &escolha);

        if (escolha != 'e' && escolha != 'E' && escolha != 'm' && escolha != 'M' && escolha != 'i' && escolha != 'I' && escolha != '0')
        {
            printf("Opcao invalida. Tente novamente.");
        }
        

    }while(escolha != 'e' && escolha != 'E' && escolha != 'm' && escolha != 'M' && escolha != 'i' && escolha != 'I' && escolha != '0');
    

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
    char temp, aux;

    aux = matriz[1][1];
    for (int j = 1; j < TAM-2; j++)
    {
        temp = matriz[1][j+1];
        matriz[1][j+1] = aux;
        aux = temp;
    }

    for (int i = 1; i < TAM-2; i++)
    {
        temp = matriz[i+1][5];
        matriz[i+1][5] = aux;
        aux = temp;
    }
    
    for (int j = TAM-2; j > 1; j--)
    {
        temp = matriz[5][j-1];
        matriz[5][j-1] = aux;
        aux = temp;
    }

    for (int i = TAM-2; i > 1; i--)
    {
        temp = matriz[i-1][1];
        matriz[i-1][1] = aux;
        aux = temp;
    }
    
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

int movimentar(char matriz[TAM][TAM]){
    
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
        case '0':
            return 0;
    
    }

    return 1;

}

void inicializa_matriz(char matriz[TAM][TAM]){
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            
            if(i == j)
            {
                matriz[i][j] = 'O';
            }

            else if(i+j == TAM-1)
            {
                matriz[i][j] = 'X';
            }

            else
            {
                matriz[i][j] = '.';
            }
            
        }

    }

    matriz[3][3] = '.';

    for (int i = 0; i < 4; i++)
    {
        rotaciona_media(matriz);
    }

    for (int i = 0; i < 3; i++)
    {
        rotaciona_interna(matriz);
    }
    

    
}

char checa_figura(char matriz[TAM][TAM]){
    
    //cruz
    for (int j = 0; j < TAM && matriz[3][j] == 'X'; j++)
    {
        if(j == 2)
        {
            j++;
        }

        else if(j == TAM-1){
            return 'c';
        }   
            
    }

    //cruz
    for (int j = 0; j < TAM && matriz[3][j] == 'O'; j++)
    {
        if(j == 2)
        {
            j++;
        }

        else if(j == TAM-1){
            return 'c';
        }   
            
    }

    //x
    for (int i= 0, j = 0; i < TAM && matriz[i][j] == 'X'; i++, j++)
    {
        if(i == 2)
        {
            i++;
            j++;
        }

        else if(j == TAM-1){
            return 'x';
        }   
            
    }

    //x
    for (int i= 0, j = 0; i < TAM && matriz[i][j] == 'O'; i++, j++)
    {
        if(i == 2)
        {
            i++;
            j++;
        }

        else if(j == TAM-1){
            return 'x';
        }   
            
    }

    return '0';




}

int main(){
    char matriz[TAM][TAM];
    inicializa_matriz(matriz);
    
    char figura;
    int continuar;


    do
    {
        estado_atual(matriz);
        figura = checa_figura(matriz);
        
        
        if (figura == 'c')
        {
            printf("CRUZ FORMADA NA TELA!\n\n");
        }

        else if(figura == 'x')
        {
            printf("X FORMADO NA TELA!\n\n");
        }

        continuar = movimentar(matriz);
        system("cls || clear");

    }while(continuar != 0);

    printf("Obrigado por jogar!\n");
    printf("Por Guilherme Brizzi\n");

}
