#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int checa_triangular(float num){
    float i = 1;
    while (num > i){
        if (num/(i * (i+1) * (i+2)) == 1){
            return 1;
        }
        i++;
    }
    return 0;
}

int main(){
    float num;
    scanf("%f", &num);
    int triangular = checa_triangular(num);

    if (triangular == 0){
        printf("Numero nao triangular.\n");
    }

    else{
        printf("Numero triangular.\n");
    }
}
