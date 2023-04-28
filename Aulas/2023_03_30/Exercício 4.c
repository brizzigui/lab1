#include <stdio.h>

int main(){
    float precobase, precoaumentado, precodiminuido;

    printf("Insira o preco base do produto: ");
    scanf("%f", &precobase);
    precodiminuido = 0.9 * precobase;
    printf("O preco base era %.2f\n", precobase);
    printf("O preco com desconto foi de: %.2f\n", precodiminuido);

    precoaumentado = 1.2 * precobase;
    printf("\n");
    printf("O preco base era %.2f\n", precobase);
    printf("Com aumento, o preco ficou: %.2f\n", precoaumentado);

}
