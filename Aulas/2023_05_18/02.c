#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main(){
    int vetor[TAM];

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = TAM-1; i >= 0; i--)
    {
        printf("%d ", vetor[i]);
    }
    
    
}
