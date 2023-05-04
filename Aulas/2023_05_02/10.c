#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int primoOuNao(int num){
    for (int j = 2; j <= num; j++){
         if (j == num){
            return 1;
        }

        else if (num % j == 0){
            return 0;
        }
    }
}

int main(){
    int num;
    scanf("%d", &num);

    printf("Decomposicao: ");
    for (int i = 2; i <= num; i++) 
    if(primoOuNao(i)){
        while (num%i == 0){
            num /= i;
            printf("%d ", i);
        }   
    }
}
