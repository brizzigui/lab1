#include <stdio.h>

int main(){
    float velms, velkmh;
    printf("Insira um valor em m/s para converter para km/h: ");
    scanf("%f", &velms);
    velkmh = velms * 3.6;
    printf("Velocidade igual a %.2f km/h.", velkmh);
}
