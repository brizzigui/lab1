#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int ler_e_comparar(){

    int qnt_palavras;
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
            return 0;
        }
        
        int diferencas = 0;

        for (int letra_auxiliar = 0; letra_auxiliar < tamanho_auxiliar; letra_auxiliar++)
        {
            for (int letra_palavra = 0; letra_palavra < tamanho_palavra; letra_palavra++)
            {   

                if (auxiliar[letra_auxiliar] != palavra[letra_palavra])
                {
                    diferencas++;
                }

                if (diferencas >= 2)
                {
                    return 0;
                }
                
                
            } 
        }

        strcpy(auxiliar, palavra);

    }

    return 1;
  
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
