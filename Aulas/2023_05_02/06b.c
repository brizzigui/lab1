#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num;
    float soma = 0, qnt = 0, media;

    do{
        scanf("%d", &num);

        if (num % 2 == 0 && num != 0){
            soma += num;
            qnt++;
        }

        
        
    } while (num != 0);

media = soma / qnt;
printf("Media: %g\n", media);
        
}
