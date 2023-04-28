#include <stdio.h>

int main(){
    int termoPreAnterior = 0, termoAnterior = 1, termoAtual, n;
    scanf("%d", &n);

    if (n >= 1)
    printf("%d ", termoPreAnterior);

    if (n >= 2)
        printf("%d ", termoAnterior);

    for (int cont = 0; cont < n; cont++){

        termoAtual = termoPreAnterior + termoAnterior;
        printf("%d ", termoAtual);
        termoPreAnterior = termoAnterior;
        termoAnterior = termoAtual;




    }
}
