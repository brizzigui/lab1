#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main(){
    int vet[TAM];
    int pares[TAM], impares[TAM];

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vet[i]);
    }

    int idx_par = 0, idx_impar = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (vet[i]%2 ==0)
        {
            pares[idx_par] = vet[i];
            idx_par++;
        }

        else
        {
            impares[idx_impar] = vet[i];
            idx_impar++;
        }
        
    }


    printf("\nVetor par:\n");
    for (int i = 0; i < idx_par; i++)
    {
        printf("%3d", pares[i]);
    }

    printf("\nVetor impar:\n");
    for (int i = 0; i < idx_impar; i++)
    {
        printf("%3d", impares[i]);
    }
    
    
}
