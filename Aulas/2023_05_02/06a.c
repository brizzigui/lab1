#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num;
    float soma = 0, qnt = 0, media;

    scanf("%d", &num);
    while (num != 0){
        if (num % 2 == 0){
            soma += num;
            qnt++;
        }

        scanf("%d", &num);
        
    }

media = soma / qnt;
printf("Media: %g\n", media);
        
}
