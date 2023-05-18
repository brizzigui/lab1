#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int idx_menor = vetor[0];

    for (int i = 1; i < 5; i++)
    {
        if (vetor[i] < vetor[idx_menor])
        {
            idx_menor = i;
        }
        
    }

    printf("O menor valor equivale a %d, no indice %d", vetor[idx_menor], idx_menor);
    
    
}
