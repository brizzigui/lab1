#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void menor_e_maior_primos(int N, int *p1, int *p2){

    int divisores = 0;
    int maior_primo, menor_primo = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i%j == 0)
            {
                divisores++;
            }
            
        }

        if (divisores == 2){
            maior_primo = i;
        }

    divisores = 0;

    }

    for (int i = N; menor_primo == 0; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i%j == 0)
            {
                divisores++;
            }
            
        }

        if (divisores == 2){
            menor_primo = i;
        }
    
    divisores = 0;
    }

    *p1 = maior_primo;
    *p2 = menor_primo;
    
}

int main(){
    int N, p1, p2;

    scanf("%d", &N);
    menor_e_maior_primos(N, &p1, &p2);

    printf("Maior antes de N: %d\n", p1);
    printf("Menor depois de N: %d\n", p2);
}
