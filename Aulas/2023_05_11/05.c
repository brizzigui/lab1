#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[10];
    int aux;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[(9-i)];
        vetor[(9-i)] = aux;

    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", vetor[i]);
    }
}
