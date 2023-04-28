#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num, qnt_divisores = 0, qnt_primos = 0;
    scanf("%d", &num);
    while (num > 0){
        for (int i = 1; i <= num; i++){
            if (num%i == 0){
                qnt_divisores++;
            }
            
        }

        if(qnt_divisores == 2){
            qnt_primos++;
        }

        qnt_divisores = 0;
        scanf("%d", &num);
    }

    printf("A quantidade de primos foi de: %d", qnt_primos);
}
