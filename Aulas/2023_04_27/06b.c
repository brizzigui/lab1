#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num;
    float qnt_pares = 0, soma_pares = 0, media_pares;
    printf("Insira numeros para achar a media dos pares: \n");

    do{
        scanf("%d", &num);
        if (num%2 == 0 && num != 0){
            qnt_pares++;
            soma_pares += num;
        }
    } while(num != 0);

    
    
    media_pares = soma_pares / qnt_pares;

    printf("%.2f", media_pares);
}
