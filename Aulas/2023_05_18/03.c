#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

int main(){
    int vetor[TAM];
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 1; i < TAM; i++)
    {
        if (vetor[i] > maior){
            maior = vetor[i];
        }

        else if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    printf("%d e %d", maior, menor);
    
    
}
