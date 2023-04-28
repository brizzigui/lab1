#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num, produto = 1;

    do{
        printf("Insira um numero positivo: ");
        scanf("%d", &num);
        if (num > 0){
            produto = produto * num;
        } 
        
    
    } while(num >= 0);

    printf("Produto: %d", produto);
}
