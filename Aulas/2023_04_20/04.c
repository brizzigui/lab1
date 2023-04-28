#include <stdio.h>

float converte(float temp){
    temp = temp * 1.8 + 32;
    return temp;
}

int main(){
    float min, max;
    printf("Escreva o minimo e o maximo em celsius para converter para farenheit:\n");
    scanf("%f %f", &min, &max);

    for (float i = min; i <= max; i = i + 2){
        float temp = converte(i);
        printf("%.2f C  =  %.2f F\n", i, temp);
    }
}
