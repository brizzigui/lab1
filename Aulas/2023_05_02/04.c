#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void divisores(int num){
    for (int i = 1; i <= num; i++){
        if (num%i == 0){
            printf("%d \n", i);
        }
    }
}

int main(){
    int num;
    char resposta;

    do{
        printf("Insira um numero para ver seus divisores: ");
        scanf("%d", &num);
        divisores(num);

        printf("Voce deseja continuar? 's' para sim, 'n' para nao");
        scanf(" %c", &resposta);
        
    }while(resposta == 's' || resposta == 'S');
}
