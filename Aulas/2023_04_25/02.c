#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int soma_dos_n_inteiros(int m, int n){
    int soma = 0, cont = 0;
    while (cont < n){
        soma = soma + m;
        m++;
        cont++;
    }
    return soma;
}

int main(){
    int m, n;
    while (1){
        printf("Insira o valor de m (numero inicial) e de n (quantos a partir de m voce quer): ");
        scanf("%d %d", &m, &n);

        int soma = soma_dos_n_inteiros(m, n);
        printf("A soma foi: %d\n", soma);
    }
}
