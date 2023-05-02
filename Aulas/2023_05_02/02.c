#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num = 0;
    int menor_valor = 1000;
    float qnt_intervalo = 0, soma_intervalo = 0, media_intervalo;
    int soma_total = 0;


    while(1){
        scanf("%d", &num);
        if (num == -1){
            break;
        }
        
        if (num > 100 && num < 1000){
            qnt_intervalo++;
            soma_intervalo += num;

            if (num < menor_valor){
                menor_valor = num;

            }

        }

        soma_total += num;
    }
    
    media_intervalo = soma_intervalo / qnt_intervalo;
    printf("Menor valor do intervalo: %d\n", menor_valor);
    printf("Media dos valores do intervalo: %f\n", media_intervalo);
    printf("Soma dos valores do intervalo: %g\n", soma_intervalo);
    printf("Soma total: %d\n", soma_total);
}
