#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int num = 0, soma = 0;

    do{
        soma = soma + num;

        printf("Insira um numero positivo (para parar, insira um valor negativo): ");
        scanf("%d", &num);

        
    
    } while(num >= 0);

    printf("Soma: %d", soma);
}
