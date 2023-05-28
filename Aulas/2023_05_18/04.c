#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[10];
    int pares = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            pares++;
        }
        
    }

    printf("%d", pares);
    
    
}
