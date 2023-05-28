#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int tamanhos[10], cont = 0;
    char palavras[10][64];

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", palavras[i]);

        for (int j = 0; palavras[i][j] != '\0'; j++)
        {
            cont++;
        }

        tamanhos[i] = cont;
        cont = 0;

    }

    printf("Os tamanhos foram: ");
    int maior = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", tamanhos[i]);

        if (tamanhos[i] > tamanhos[maior]){
            maior = i;
        }
    }

    printf("\nA maior palavra foi %s, com %d caracteres", palavras[maior], tamanhos[maior]);
    
    
    
    
}
