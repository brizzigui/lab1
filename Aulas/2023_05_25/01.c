#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void divisores(int *num){
    int cont = 0;

    for (int i = 1; i < *num; i++)
    {
        if (*num % i == 0)
        {
            cont++;
        }
       
    }

    *num = cont;
    
}


int main(){
    int N;
    printf("Quantos valores voce quer ler? ");
    scanf("%d", &N);

    int numero;
    for (int i = 0; i < N; i++)
    {
        printf("Insira um valor: ");
        scanf("%d", &numero);
        divisores(&numero);
        printf("%d divisores\n\n", numero);
    }
    
}
