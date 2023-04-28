#include <stdio.h>

int main(){
    int valorMax, numA, numB;
    char simbolo;

    printf("Insira o valor maximo que esse computador consegue representar: ");
    scanf("%d", &valorMax);

    printf("Digite um numero, um simbolo (+ ou *), e mais um numero:\n");
    scanf("%d %c %d", &numA, &simbolo, &numB);

    if (simbolo == '+'){
        if ((numA + numB) > valorMax)
            printf("Overflow!\n");
        else
            printf("Ok!\n");
    }

    else{
        if ((numA * numB) > valorMax)
            printf("Overflow!\n");
        else
            printf("Ok!\n");
    }
}
