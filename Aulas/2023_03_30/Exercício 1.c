#include <stdio.h>

int main(){
    float nota1, nota2;
    int peso1, peso2;
    float notafinal;

    printf("Insira as notas:\n");
    scanf("%f %f", &nota1, &nota2);

    printf("Insira os pesos\n");
    scanf("%d %d", &peso1, &peso2);

    notafinal = (nota1*peso1 + nota2*peso2)/(peso1+peso2);
    printf("A nota final foi %f", notafinal);

}
