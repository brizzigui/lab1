#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numero_usuario, num_quadrado_maior=1;
    printf("Insira um numero para achar outro numero cujo quadrado eh menor que o numero inserido: ");
    scanf("%d", &numero_usuario);

    do{
        num_quadrado_maior++;
    } while(num_quadrado_maior*num_quadrado_maior < numero_usuario);

    printf("Esse numero sera: %d", num_quadrado_maior);
}
