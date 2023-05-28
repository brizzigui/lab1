#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main(){
    int vetorA[TAM];
    int vetorB[TAM];
    int cont = 0;

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetorA[i]);
    }
    

    for (int i = 0; i < TAM; i++)
    {
        if (vetorA[i] > 0)
        {
            vetorB[cont] = vetorA[i];
            cont++;
        }
        
    }

    for (int i = 0; i < cont; i++)
    {
        printf("%d ", vetorB[i]);
    }
    
    
}
