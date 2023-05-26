#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int ler_e_comparar(){

    int qnt_palavras;
    int cumpre = 1;
    printf("Quantas palavras compoem a sequencia? ");
    scanf("%d", &qnt_palavras);

    char palavra[10];
    char auxiliar[10];

    printf("Digite as %d palavras da sequencia:\n", qnt_palavras);
    scanf("%s", auxiliar);
    int tamanho_auxiliar = strlen(auxiliar);

    for (int cont_palavras = 0; cont_palavras < qnt_palavras-1; cont_palavras++)
    {

        scanf("%s", palavra);
        int tamanho_palavra = strlen(palavra);

        if (tamanho_auxiliar != tamanho_palavra)
        {
            cumpre = 0;
        }
        
        int diferencas = 0;

        for (int letra = 0; letra < tamanho_auxiliar; letra++)
        {

            if (auxiliar[letra] != palavra[letra])
            {
                diferencas++;
            }

            if (diferencas >= 2)
            {
                cumpre = 0;
            }
                
        }

        strcpy(auxiliar, palavra);

    }

    return cumpre;
  
}

int main(){

    int cumpre_condicao = ler_e_comparar();

    if (cumpre_condicao)
    {
        printf("A sequencia informada cumpre a condicao.");
    }

    else
    {
        printf("A sequencia informada nao cumpre a condicao.");
    }
    
    
}
