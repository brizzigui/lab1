#include <stdio.h>

int somaQuadrados(){
    double num, quadrado, soma = 0;
    for (int i = 0; i < 20; i++){
        scanf("%lf", &num);
        quadrado = num*num;

        if (quadrado < 225){
            soma = soma + num;
        }
    }

    printf("A soma dos numeros cujo quadrado eh menor que 225 equivale a %.0lf", soma);
}

int main(){
    somaQuadrados();

}
