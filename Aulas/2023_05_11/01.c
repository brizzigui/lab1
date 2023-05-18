#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[10];
    int valor, cont = 0;

    printf("Digite 10 numeros para o vetor:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Insira o valor cuja ocorrencia voce quer verificar: ");
    scanf("%d", &valor);

    for (int i = 0; i < 10; i++){
        if (vetor[i] == valor){
            
            cont++;
        }
    }

    printf("Ocorrencia: %d vezes", cont);
    
    
}
