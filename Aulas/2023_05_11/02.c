#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    double vetor[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &vetor[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%lf\n", vetor[i]);
    }
    

    printf("\n");

    
    for (int i = 0; i < 5; i++)
    {
        if (vetor[i] == 0)
        {
            vetor[i] = -99;
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%lf\n", vetor[i]);
    }
    
}
