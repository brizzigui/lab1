#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void casaParOuImpar(int num){
    int alg_centena = num/100;
    if (alg_centena % 2 == 0){
        printf("Algarismo par\n");
    }
    else{
        printf("Algarismo impar\n");
    }
}


int main(){
    int num;
    scanf("%d", &num);
    while(num >= 100 && num <= 999){
        
        casaParOuImpar(num);
        scanf("%d", &num);

    }
    


}
